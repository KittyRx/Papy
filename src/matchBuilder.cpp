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

// Helper function
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
    return 1; // fallback to first champ if index too large
}

mapping::Match matchBuilder::randomMatch()
{
    mapping::Match matchTemplate;

    // Using curent data for realism;
    long long timestamp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    matchTemplate.info.gameCreation = timestamp_ms;
    matchTemplate.info.gameStartTimestamp = timestamp_ms;
    matchTemplate.info.gameDuration = myRandom::generateRandomInt(600, 3000); // seconds
    matchTemplate.info.gameEndTimestamp = timestamp_ms + matchTemplate.info.gameDuration * 1000;

    matchTemplate.metadata.matchId = "MATCH_" + myRandom::generateRandomNumberString(10);

    // Randomly determine win/loss for the different teams
    bool firstSetWin = myRandom::getRandomBool();
    bool secondSetWin = !firstSetWin;

    // Used in assigning the first user to bsawatestuser#test
    bool isFirstIteration = true;

    // Create a team state so as TeamADeaths = TeamBKills and viceversa;
    int totalDeathsA = myRandom::generateRandomInt(5, 30);
    int totalDeathsB = myRandom::generateRandomInt(5, 30);
    int totalKillsA = totalDeathsB;
    int totalKillsB = totalDeathsA;

    // Distribute kills/deaths across team members;
    std::vector<int> deathsDistA = myRandom::distributeTotal(totalDeathsA, 5);
    std::vector<int> killsDistA = myRandom::distributeTotal(totalKillsA, 5);
    std::vector<int> deathsDistB = myRandom::distributeTotal(totalDeathsB, 5);
    std::vector<int> killsDistB = myRandom::distributeTotal(totalKillsB, 5);

    // Limit number of camps per 45 mins at perfect clear;
    int totalJungleCamps = 120;

    int participantIndex = 0;
    for (auto &participant : matchTemplate.info.participants)
    {
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

        participant.championId = getChampionIdByIndex(myRandom::generateRandomInt(0, mapping::CHAMPIONS.size() - 1));
        participant.championName = mapping::CHAMPIONS.at(participant.championId).name;

        // Create a role type for champions;
        std::string role = mapping::CHAMPIONS.at(participant.championId).role;
        // Map each role string to a pointer to its corresponding item set map.
        std::unordered_map<std::string, const std::unordered_map<int, std::string> *> itemSets = {
            {"Mage", &mapping::MAGE_ITEMS},
            {"Bruiser", &mapping::BRUISER_ITEMS},
            {"Assassin", &mapping::ASSASSIN_ITEMS},
            {"Marksman", &mapping::MARKSMAN_ITEMS},
            {"Tank", &mapping::TANK_ITEMS},
            {"Support", &mapping::SUPPORT_ITEMS}};
        // Dereference the pointer to get the item set associated with the role.
        const auto &itemSet = *itemSets[role];

        // Copy values to work with; Not counting shutdowns or devalues just base.
        int goldKills = participant.kills;

        int goldAssist = participant.assists;

        // 3 Gold per sec gen since 1:40;
        const int duration = matchTemplate.info.gameDuration;
        int goldTime = (duration - 100) * 3;

        participant.totalDamageDealtToChampions = myRandom::generateRandomInt(0, 60000);

        // Perfect farm is 11cs/min, technically 12 only from minions;
        participant.totalMinionsKilled = myRandom::generateRandomInt(0, duration * 11);

        // Farm of 10cs/min only achievable when invading;
        participant.totalAllyJungleMinionsKilled = (totalJungleCamps * duration) - myRandom::generateRandomInt(0, duration * 6);
        participant.totalEnemyJungleMinionsKilled = totalJungleCamps - myRandom::generateRandomInt(0, duration * 6);

        // Item completion at 15 else no gold and standard starting item;
        if (role == "Support" && duration < 900)
        {
            participant.goldEarned = goldKills * 300 + goldAssist * 50 + duration;
            participant.item0 = 3865;
        }
        else if (role == "Support" && duration >= 900)
        {
            participant.goldEarned = goldKills * 300 + goldAssist * 50 + duration + 1300;
            participant.item0 = std::next(mapping::SUPPORT_EVO.begin(), (0, mapping::SUPPORT_EVO.size()))->first;
        }
        else
        {
            participant.goldEarned = goldKills * 300 + goldAssist * 50 + duration;
        }

        participant.champExperience = myRandom::generateRandomInt(1, 12576);
        participant.champLevel = myRandom::generateRandomInt(1, 18);

        // Cassio doesn't wear boots;
        if (participant.championId == 69)
        {
            std::vector<int> items = myRandom::getRandomKeysCached(itemSet, 7);
            for (int i = 0; i < 7; ++i)
            {
                *(&participant.item0 + i) = items[i];
            }
        }

        // Use components and starter items for shorter matches;
        if (matchTemplate.info.gameEndTimestamp < 1200)
        {
            participant.item0 = std::next(mapping::BOOTS.begin(), (0, mapping::BOOTS.size()))->first;
        }

        else
        {
            participant.item0 = ;
        };
        if (role == "Bruiser")
        {
        }
        else if (role == "Mage")
        {
        }
        else if (role == "Assassin")
        {
        }
        else if (role == "Marksman")
        {
        }
        else if (role == "Tank")
        {
        }
        else if (role == "Support")
        {
        }

        participant.item1 = ;
        participant.item2 = ;
        participant.item3 = ;
        participant.item4 = ;
        participant.item5 = ;
        participant.item6 = ;

        participant.summoner1Id = ;
        participant.summoner2Id = ;

        participant.perks.Primary = ;
        participant.perks.Secondary = ;
        for (int i = 0; i < (int)participant.perks.selections.size(); ++i)
        {
            participant.perks.selections[i] = ;
        }

        // Win/loss and team;
        participant.win = (participantIndex < 5) ? firstSetWin : secondSetWin;
        participant.teamId = (participantIndex < 5) ? 100 : 200;
        participant.visionScore = (0, 50);

        // Riot IDs and summoner name;
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

    return matchTemplate;
}
