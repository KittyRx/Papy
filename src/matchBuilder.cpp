#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>

#include "matchBuilder.hpp"
#include "myRandom.hpp"
#include "mapping.hpp"

using mapping::Match;

mapping::Match matchBuilder::randomMatch()
{
    mapping::Match matchTemplate;

    // Taking the time stamp of today in ms;
    long long timestamp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    // And passing it as data for game start and creation ( for realism since server won't receive post requests for yesterday's or tomorrow's matches );
    matchTemplate.info.gameCreation = timestamp_ms;
    matchTemplate.info.gameStartTimestamp = timestamp_ms;
    matchTemplate.info.gameDuration = (600, 3000); // seconds
    matchTemplate.info.gameEndTimestamp = timestamp_ms + matchTemplate.info.gameDuration * 1000;

    matchTemplate.metadata.matchId = "TEST1_" + myRandom::generateRandomNumberString(10);

    // Randomly determine win/loss for the different teams
    bool firstSetWin = myRandom::getRandomBool();
    bool secondSetWin = !firstSetWin;

    // Used in assigning the first user to bsawatestuser#test
    bool isFirstIteration = true;

    // Create a team state so as TeamADeaths = TeamBKills and viceversa;
    int totalDeathsA = myRandom::generateRandomInt(5, 30);
    int totalDeathsB = myRandom::generateRandomInt(5, 30);

    // Then assign total kills;
    int totalKillsA = totalDeathsB;
    int totalKillsB = totalDeathsA;

    // Limit number of camps per 45 mins at perfect clear.
    int totalJungleCamps = 120;

    int participantIndex = 0;
    for (auto &participant : matchTemplate.info.participants)
    {
        // Distribute stats randomly per team matching global state, for non 0 values;
        if (participantIndex <= 4)
        {
            participant.assists = myRandom::generateRandomInt(0, totalKillsA);
            participant.deaths = totalDeathsA - myRandom::generateRandomInt(0, totalDeathsA);
            participant.kills = totalKillsA - myRandom::generateRandomInt(0, totalKillsA);
        }
        else
        {
            participant.assists = myRandom::generateRandomInt(0, totalKillsB);
            participant.deaths = totalDeathsB - myRandom::generateRandomInt(0, totalDeathsB);
            participant.kills = totalKillsB - myRandom::generateRandomInt(0, totalKillsB);
        };

        participant.championName = mapping::CHAMPIONS.at(participant.championId);

        // Create a role type for champions;
        std::string role = mapping::CHAMPIONS.at(participant.championId).role;

        // Copy values to work with; Not counting shutdowns or devalues just base.
        int goldKills = participant.kills;

        int goldAssist = participant.assists;
        // 3 Gold per sec gen since 1:40.
        const int duration = matchTemplate.info.gameDuration;
        int goldTime = (duration - 100) * 3;

        participant.totalDamageDealtToChampions = myRandom::generateRandomInt(0, 60000);
        // Perfect farm is 11/min, technically 12 only from minions;
        participant.totalMinionsKilled = myRandom::generateRandomInt(0, duration * 11);
        // Farm of 10cs/min only achievable when invading;
        participant.totalAllyJungleMinionsKilled = (totalJungleCamps * duration) - myRandom::generateRandomInt(0, duration * 6);
        participant.totalEnemyJungleMinionsKilled = totalJungleCamps - myRandom::generateRandomInt(0, duration * 6);

         // Items as IDs; Cassio doesn't wear boots;
        if (participant.championId == 69)
        {   
            int randomMageItem = std::next(mapping::MAGE_ITEMS.begin(), (0, mapping::MAGE_ITEMS.size()))->first;
            participant.item0 = 
            participant.item0 = participant.item0 + 1 ;
            participant.item1 = ;
            participant.item2 = ;
            participant.item3 = ;
            participant.item4 = ;
            participant.item5 = ;
            participant.item6 = ;
        }
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
        } else if ()
       
            participant.goldEarned = goldKills * 300 + goldAssist * 50 + duration;
        1020 participant.champExperience = ;
        participant.champLevel = ;
        participant.championId = ;

        // Use components and starter items for shorter matches;
        if (matchTemplate.info.gameEndTimestamp < 1200)
        {
            participant.item0 = std::next(mapping::BOOTS.begin(), (0, mapping::BOOTS.size()))->first;
            participant.item1 = ;
            participant.item2 = ;
            participant.item3 = ;
            participant.item4 = ;
            participant.item5 = ;
            participant.item6 = ;
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
            participant.riotIdGameName = ;
            participant.riotIdTagline = ;
            participant.summonerName = ;
        }

        // metadata participant puuid placeholder
        matchTemplate.metadata.participantPuuids[participantIndex] = ;

        ++participantIndex;
    }

    return matchTemplate;
}
