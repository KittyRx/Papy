#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>

#include "matchBuilder.hpp"
#include "myRandom.hpp"
#include "mapping.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>

using mapping::Match;

/**
 * @brief Takes a random integer and maps it to the `ID` in `CHAMPIONS` struct;
 *
 * @param a Integer value representing index;
 * @return Returns `ID` at index value of `int` inside `CHAMPIONS`;
 **/
static int getChampionIdByIndex(int index)
{
    int current = 0;
    for (const auto &pair : mapping::CHAMPIONS)
    {
        if (current == index)
        {
            return pair.first;
        }
        current++;
    }
    return 1;
}

/**
 * @brief `randomMatch` function is called to create templates of `Match`;
 *
 * @return Returns the match as nlohmann::json (converted from native structs)
 **/
nlohmann::json matchBuilder::randomMatch()
{
    mapping::Match matchTemplate;
    long long timestamp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    matchTemplate.info.gameCreation = timestamp_ms;
    matchTemplate.info.gameStartTimestamp = timestamp_ms;
    matchTemplate.info.gameDuration = myRandom::generateRandomInt(600, 3000);                    // seconds
    matchTemplate.info.gameEndTimestamp = timestamp_ms + matchTemplate.info.gameDuration * 1000; // miliseconds;
    matchTemplate.metadata.matchId = "MATCH_" + myRandom::generateRandomNumberString(10);
    const int duration = matchTemplate.info.gameDuration;
    const int goldPerSec = (duration - 100) * 3; // 3 Gold per sec gen since 1:40m ( first 100 secs no gold gen );

    // Randomly determine win/loss for the different teams
    bool firstSetWin = myRandom::getRandomBool();
    bool secondSetWin = !firstSetWin;

    // Used in assigning the first user to bsawatestuser#test
    bool isFirstIteration = true;

    // Create a team state so as TeamADeaths = TeamBKills and viceversa;
    const int totalDeathsA = myRandom::generateRandomInt(5, 30);
    const int totalDeathsB = myRandom::generateRandomInt(5, 30);
    const int totalKillsA = totalDeathsB;
    const int totalKillsB = totalDeathsA;

    // Create vectors with values for deaths and kills which will be used to distribute stats in the `for loop` to each player;
    std::vector<int> deathsDistA = myRandom::distributeTotal(totalDeathsA, 5);
    std::vector<int> killsDistA = myRandom::distributeTotal(totalKillsA, 5);
    std::vector<int> deathsDistB = myRandom::distributeTotal(totalDeathsB, 5);
    std::vector<int> killsDistB = myRandom::distributeTotal(totalKillsB, 5);

    // Map each role string to a pointer corresponding to its item set map;
    std::unordered_map<std::string, const std::unordered_map<int, std::string> *> itemSets = {
        {"Mage", &mapping::MAGE_ITEMS},
        {"Bruiser", &mapping::BRUISER_ITEMS},
        {"Assassin", &mapping::ASSASSIN_ITEMS},
        {"Marksman", &mapping::MARKSMAN_ITEMS},
        {"Tank", &mapping::TANK_ITEMS},
        {"Support", &mapping::SUPPORT_ITEMS}};

    // Helper enum for game phases;
    enum class GamePhase
    {
        EARLY,    // < 15 minutes (900s);
        MID,      // 15-20 minutes (900-1200s);
        LATE,     // 20-33 minutes (1200-2000s);
        VERY_LATE // 33+ minutes (2000s+);
    };

    // Determine game phase based on duration;
    auto getGamePhase = [](int duration) -> GamePhase
    {
        if (duration < 900)
            return GamePhase::EARLY;
        if (duration < 1200)
            return GamePhase::MID;
        if (duration < 2000)
            return GamePhase::LATE;
    };

    int participantIndex = 0;
    for (auto &participant : matchTemplate.info.participants)
    {
        // Distribute stats across teams;
        if (participantIndex <= 4)
        {
            participant.deaths = deathsDistA[participantIndex];
            participant.kills = killsDistA[participantIndex];
            participant.assists = myRandom::generateRandomInt(0, totalKillsA);
        }
        else
        {
            int idx = participantIndex - 5;
            participant.deaths = deathsDistB[idx];
            participant.kills = killsDistB[idx];
            participant.assists = myRandom::generateRandomInt(0, totalKillsB);
        };

        participant.totalDamageDealtToChampions = myRandom::generateRandomInt(0, duration * 750); // DPM between 622 in Pro play to 750 in ranked;
        participant.totalMinionsKilled = myRandom::generateRandomInt(0, duration * 11);           // 11/12 cs/m ceiling on minion waves;
        participant.totalAllyJungleMinionsKilled = myRandom::generateRandomInt(0, duration * 6);
        participant.totalEnemyJungleMinionsKilled = myRandom::generateRandomInt(0, duration * 6);

        const int minions = participant.totalMinionsKilled;
        const int jglCamps = participant.totalAllyJungleMinionsKilled + participant.totalEnemyJungleMinionsKilled;
        const int goldKills = participant.kills * 300;   // Base value, not considering shutdowns and devaluation implemented in later patches;
        const int goldAssist = participant.assists * 50; // Also not counting plates or obectives for now;
        const int totalGold = goldKills + goldAssist + goldPerSec + minions + jglCamps;
        participant.goldEarned = totalGold;

        participant.championId = getChampionIdByIndex(myRandom::generateRandomInt(0, mapping::CHAMPIONS.size() - 1));
        participant.championName = mapping::CHAMPIONS.at(participant.championId).name;
        std::string role = mapping::CHAMPIONS.at(participant.championId).role;
        GamePhase phase = getGamePhase(duration);
        // Dereference the pointer to get the item set associated with the role;
        const auto &itemSet = *itemSets[role];

        // Set the trinket or special;
        participant.item6 = myRandom::getRandomKeyCached(mapping::SPECIAL_ITEMS);
        // Give random consumables pre 20m;
        std::vector<int> items = myRandom::getRandomKeysCached(mapping::CONSUMABLES, 2);
        for (int i = 0; i < 2; ++i)
        {
            *(&participant.item1 + i) = items[i];
        }

        // Giving supp item to support class ( forced by Riot );
        if (role == "Support" && phase == GamePhase::EARLY)
        {
            participant.goldEarned = totalGold - minions - jglCamps;
            participant.item0 = 3865;
        }
        // Item completes at 15m and gives 1.3k gold;
        else if (role == "Support" && phase == GamePhase::MID)
        {
            // Supports don't farm but might take jgl camps;
            participant.goldEarned = totalGold + 1300 - minions - jglCamps % 2;
            participant.item0 = myRandom::getRandomKeyCached(mapping::SUPPORT_MAIN);
        };

        // If not support totalGold unchanged;
        if (role != "Support" && phase == GamePhase::EARLY)
        {
            // Give random starting item;
            participant.item0 = myRandom::getRandomKeyCached(mapping::STARTER_ITEMS);

            // Give random components overide 1 consumable;
            std::vector<int> items = myRandom::getRandomKeysCached(mapping::COMPONENTS, 3);
            for (int i = 0; i < 3; ++i)
            {
                *(&participant.item2 + i) = items[i];
            }
        }
        else if (role != "Support" && phase == GamePhase::MID)
        {
            // Changing the starter item for completed boots;
            participant.item0 = myRandom::getRandomKeyCached(mapping::BOOTS);

            // Give 3 random components overriding all consumables;
            std::vector<int> comp_items = myRandom::getRandomKeysCached(mapping::COMPONENTS, 3);
            for (int i = 0; i < 3; ++i)
            {
                *(&participant.item1 + i) = comp_items[i];
            }
            // Give 2 completed items at min 20;
            std::vector<int> finished_items = myRandom::getRandomKeysCached(itemSet, 2);
            for (int i = 0; i < 2; ++i)
            {
                *(&participant.item4 + i) = finished_items[i];
            }
        }
        else if (role != "Support" && phase == GamePhase::LATE)
        {
            participant.item0 = myRandom::getRandomKeyCached(mapping::BOOTS);

            // Full build;
            std::vector<int> items = myRandom::getRandomKeysCached(itemSet, 5);
            for (int i = 0; i < 5; ++i)
            {
                *(&participant.item1 + i) = items[i];
            }
        }

        const int experienceKills = participant.kills * 590;
        const int experienceAssists = participant.assists * 590;
        int experienceFarm = minions * 60 + jglCamps * 120;
        if (participant.item6 == 3513)
        {
            int experienceFarm = minions * 60 + jglCamps * 120 + 300;
        }

        const int totalExperience = experienceAssists + experienceKills + experienceFarm;
        participant.champExperience = totalExperience;

        constexpr int XP_FOR_LEVEL[19] = {
            0,     // unused index 0;
            0,     // level 1;
            280,   // level 2;
            660,   // level 3;
            1140,  // level 4;
            1720,  // level 5;
            2400,  // level 6;
            3180,  // level 7;
            4060,  // level 8;
            5040,  // level 9;
            6120,  // level 10;
            7300,  // level 11;
            8580,  // level 12;
            9960,  // level 13;
            11440, // level 14;
            12920, // level 15;
            14500, // level 16;
            16180, // level 17;
            17960  // level 18 (min xp at 18);
        };

        int level = 1;
        for (int lvl = 18; lvl >= 1; --lvl)
        {
            if (totalExperience >= XP_FOR_LEVEL[lvl])
            {
                level = lvl;
                break;
            }
        }

        participant.champLevel = level;
        participant.summoner1Id = myRandom::generateRandomInt(6,36);

        participant.perks.Primary = myRandom::getRandomKeyCached(mapping::KEYSTONES);
        participant.perks.Secondary = myRandom::getRandomKeyCached(mapping::SECONDARY_RUNES);

        // Win/loss and team
        participant.win = (participantIndex < 5) ? firstSetWin : secondSetWin;

        // Give participants the same team id;
        const int teamID = myRandom::generateRandomInt(0,200);
        const int secondTeamID = myRandom::generateRandomInt(0,200);
        participant.teamId = (participantIndex < 5) ? teamID : secondTeamID;
        participant.visionScore = (0, 50);

        // Riot IDs and summoner name
        if (isFirstIteration)
        {
            participant.riotIdGameName = "bsawatestuser";
            participant.riotIdTagline = "test";
            participant.summonerName = "bsawatestuser";
            isFirstIteration = false;
        }
        else
        {
            participant.riotIdGameName = myRandom::generateRandomString(8);
            participant.riotIdTagline = myRandom::generateRandomString(3);
            participant.summonerName = myRandom::generateRandomString(8);
        }

        // metadata participant puuid placeholder
        matchTemplate.metadata.participantPuuids[participantIndex] = myRandom::generateRandomString(16);

        ++participantIndex;
    }

    // Convert native struct to JSON using nlohmann (mapping has NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE);
    nlohmann::json j;
    nlohmann::to_json(j, matchTemplate);
    return j;
}
