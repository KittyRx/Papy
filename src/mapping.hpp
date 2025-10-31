#pragma once

#include <unordered_map>
#include <string>
#include <array>

using str = std::string;
using map = std::unordered_map<int, str>;

namespace mapping
{
    // Query names by ID inside structs;
    extern const map KEYSTONES;
    extern const map SECONDARY_RUNES;
    extern const map SUMMONERS;
    extern const map BOOTS;
    extern const map CONSUMABLES;
    extern const map JUNGLE_ITEMS;
    extern const map STARTER_ITEMS;
    extern const map COMPONENTS;
    extern const map ASSASSIN_ITEMS;
    extern const map MARKSMAN_ITEMS;
    extern const map MAGE_ITEMS;
    extern const map BRUISER_ITEMS;
    extern const map TANK_ITEMS;
    extern const map SUPPORT_ITEMS;
    extern const map SUPPORT_EVO;
    extern const std::unordered_map<int, Champion> CHAMPIONS;

    // Necessary structs for data;
    struct Champion
    {
        str name;
        str role;
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
        str championName;
        int deaths;
        int goldEarned;
        int item0, item1, item2, item3, item4, item5, item6;
        int kills;
        Perks perks;
        str riotIdGameName;
        str riotIdTagline;
        int summoner1Id;
        int summoner2Id;
        str summonerName;
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
        str gameVersion;
        long long gameId;
        int queueId;
        std::array<Participant, 10> participants;
    };

    struct MatchMetadata
    {
        str matchId;
        std::array<str, 10> participantPuuids;
    };

    struct Match
    {
        MatchMetadata metadata;
        MatchInfo info;
    };
}
