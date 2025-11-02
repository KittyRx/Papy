#pragma once

#include <unordered_map>
#include <string>
#include <array>
#include "dependencies/json.hpp"

namespace mapping
{
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

    extern const std::unordered_map<int, std::string> STARTER_ITEMS;
    extern const std::unordered_map<int, std::string> SUPPORT_MAIN;
    extern const std::unordered_map<int, std::string> CONSUMABLES;
    extern const std::unordered_map<int, std::string> BOOTS;

    extern const std::unordered_map<int, std::string> JUNGLE_ITEMS;
    extern const std::unordered_map<int, std::string> COMPONENTS;

    extern const std::unordered_map<int, std::string> ASSASSIN_ITEMS;
    extern const std::unordered_map<int, std::string> MARKSMAN_ITEMS;
    extern const std::unordered_map<int, std::string> BRUISER_ITEMS;
    extern const std::unordered_map<int, std::string> MAGE_ITEMS;
    extern const std::unordered_map<int, std::string> TANK_ITEMS;
    extern const std::unordered_map<int, std::string> SUPPORT_ITEMS;

    extern const std::unordered_map<int, std::string> SPECIAL_ITEMS;

    extern const std::unordered_map<int, Champion> CHAMPIONS;

    // JSON (de)serialization helpers for mapping structs;
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Champion, name, role);

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Perks, Primary, Secondary, selections);

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Participant, assists, champExperience, champLevel, championId,
                                       championName, deaths, goldEarned, item0, item1, item2, item3, item4, item5, item6, kills, perks,
                                       riotIdGameName, riotIdTagline, summoner1Id, summoner2Id, summonerName, totalMinionsKilled,
                                       neutralMinionsKilled, totalAllyJungleMinionsKilled, totalEnemyJungleMinionsKilled, totalDamageDealtToChampions,
                                       win, teamId, visionScore);

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MatchInfo, gameCreation, gameDuration, gameEndTimestamp, gameStartTimestamp, gameVersion, gameId, queueId, participants);

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MatchMetadata, matchId, participantPuuids);

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Match, metadata, info);

}
