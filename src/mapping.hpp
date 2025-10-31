#pragma once

#include <unordered_map>
#include <string>
#include <array>

namespace mapping
{
    // Necessary structs for data;
    struct Champion
    {
        std::string name;
        std::string role;
    };

    struct Perks
    {
        int Primary;
        int Secondary;
        std::array<int, 5> selections;
    };

    struct Participant
    {
        int assists;
        int champExperience;
        int champLevel;
        int championId;
        std::string championName;
        int deaths;
        int goldEarned;
        int item0, item1, item2, item3, item4, item5, item6;
        int kills;
        Perks perks;
        std::string riotIdGameName;
        std::string riotIdTagline;
        int summoner1Id;
        int summoner2Id;
        std::string summonerName;
        int totalMinionsKilled;
        int neutralMinionsKilled;
        int totalAllyJungleMinionsKilled;
        int totalEnemyJungleMinionsKilled;
        int totalDamageDealtToChampions;
        bool win;
        int teamId;
        int visionScore;
    };

    struct MatchInfo
    {
        long long gameCreation;
        int gameDuration;
        long long gameEndTimestamp;
        long long gameStartTimestamp;
        std::string gameVersion;
        long long gameId;
        int queueId;
        std::array<Participant, 10> participants;
    };

    struct MatchMetadata
    {
        std::string matchId;
        std::array<std::string, 10> participantPuuids;
    };

    struct Match
    {
        MatchMetadata metadata;
        MatchInfo info;
    };

    // Query names by ID inside structs;
    extern const std::unordered_map<int, std::string> KEYSTONES;
    extern const std::unordered_map<int, std::string> SECONDARY_RUNES;
    extern const std::unordered_map<int, std::string> SUMMONERS;
    extern const std::unordered_map<int, std::string> BOOTS;
    extern const std::unordered_map<int, std::string> CONSUMABLES;
    extern const std::unordered_map<int, std::string> JUNGLE_ITEMS;
    extern const std::unordered_map<int, std::string> STARTER_ITEMS;
    extern const std::unordered_map<int, std::string> COMPONENTS;
    extern const std::unordered_map<int, std::string> ASSASSIN_ITEMS;
    extern const std::unordered_map<int, std::string> MARKSMAN_ITEMS;
    extern const std::unordered_map<int, std::string> MAGE_ITEMS;
    extern const std::unordered_map<int, std::string> BRUISER_ITEMS;
    extern const std::unordered_map<int, std::string> TANK_ITEMS;
    extern const std::unordered_map<int, std::string> SUPPORT_ITEMS;
    extern const std::unordered_map<int, std::string> SUPPORT_EVO;
    extern const std::unordered_map<int, Champion> CHAMPIONS;
    
}
