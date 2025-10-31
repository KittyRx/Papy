#include <string>

#include "dependencies/json.hpp"
#include "mapping.hpp"

namespace mapping
{
    const std::unordered_map<int, std::string> KEYSTONES = {
        {8369, "First Strike"},
        {8124, "Predator"},
        {8112, "Electrocute"},
        {8360, "Unsealed Spellbook"},
        {8128, "Dark Harvest"},
        {8214, "Summon Aery"},
        {8008, "Lethal Tempo"},
        {8010, "Conqueror"},
        {8005, "Press the Attack"},
        {8351, "Glacial Augment"},
        {8439, "Aftershock"},
        {8021, "Fleet Footwork"},
        {8230, "Phase Rush"},
        {8465, "Guardian"},
        {8437, "Grasp of the Undying"},
        {9923, "Hail of Blades"},
        {8229, "Arcane Comet"}};

    const std::unordered_map<int, std::string> SECONDARY_RUNES = {
        {8000, "Precision"},
        {8100, "Domination"},
        {8200, "Sorcery"},
        {8300, "Inspiration"},
        {8400, "Resolve"}};

    const std::unordered_map<int, std::string> SUMMMONERS = {
        {1, "Cleanse"},
        {3, "Exhaust"},
        {4, "Flash"},
        {6, "Ghost"},
        {7, "Heal"},
        {11, "Smite"},
        {12, "Teleport"},
        {14, "Ignite"},
        {21, "Barrier"}};

    const std::unordered_map<int, std::string> BOOTS = {
        {3006, "Berserker's Greaves"},
        {3009, "Boots of Swiftness"},
        {3020, "Sorcerer's Shoes"},
        {3047, "Plated Steelcaps"},
        {3111, "Mercury's Treads"},
        {3117, "Mobility Boots"},
        {3158, "Ionian Boots of Lucidity"}};

    const std::unordered_map<int, std::string> CONSUMABLES = {
        {2003, "Health Potion"},
        {2031, "Refillable Potion"},
        {2033, "Corrupting Potion"},
        {2055, "Control Ward"},
        {2138, "Elixir of Iron"},
        {2139, "Elixir of Sorcery"},
        {2140, "Elixir of Wrath"},
        {2010, "Total Biscuit of Everlasting Will"},
        {2419, "Commencing Stopwatch"},
        {2423, "Perfectly Timed Stopwatch"}};

    const std::unordered_map<int, std::string> JUNGLE_ITEMS = {
        {1035, "Emberknife"},
        {1039, "Hailblade"},
        {1101, "Scorchclaw Pup"},
        {1102, "Gustwalker Hatchling"},
        {1103, "Mosstomper Seedling"}};

    const std::unordered_map<int, std::string> STARTER_ITEMS = {
        {1001, "Boots"},
        {3865, "World Atlas"},
        {1054, "Doran's Shield"},
        {1055, "Doran's Blade"},
        {1056, "Doran's Ring"},
        {1082, "Dark Seal"},
        {1083, "Cull"}};

    const std::unordered_map<int, std::string> SUPPORT_EVO = {
        {3866, "Runic Compass"},
        {3867, "Bounty of Worlds"},
        {3869, "Celestial Opposition"},
        {3870, "Dream Maker"},
        {3871, "Zaz'Zak's Realmspike"},
        {3876, "Solstice Sleigh"},
        {3877, "Bloodsong"}};

    const std::unordered_map<int, std::string> COMPONENTS = {
        {1001, "Boots"},
        {1004, "Faerie Charm"},
        {1006, "Rejuvenation Bead"},
        {1011, "Giant's Belt"},
        {1018, "Cloak of Agility"},
        {1026, "Blasting Wand"},
        {1027, "Sapphire Crystal"},
        {1028, "Ruby Crystal"},
        {1029, "Cloth Armor"},
        {1031, "Chain Vest"},
        {1033, "Null-Magic Mantle"},
        {1036, "Long Sword"},
        {1037, "Pickaxe"},
        {1038, "B. F. Sword"},
        {1042, "Dagger"},
        {1043, "Recurve Bow"},
        {1052, "Amplifying Tome"},
        {1053, "Vampiric Scepter"},
        {1057, "Negatron Cloak"},
        {1058, "Needlessly Large Rod"},
        {2015, "Kircheis Shard"},
        {2420, "Seeker's Armguard"},
        {3044, "Phage"},
        {3051, "Hearthbound Axe"},
        {3057, "Sheen"},
        {3067, "Kindlegem"},
        {3070, "Tear of the Goddess"},
        {3076, "Bramble Vest"},
        {3077, "Tiamat"},
        {3082, "Warden's Mail"},
        {3086, "Zeal"},
        {3105, "Aegis of the Legion"},
        {3108, "Fiendish Codex"},
        {3113, "Aether Wisp"},
        {3114, "Forbidden Idol"},
        {3133, "Caulfield's Warhammer"},
        {3134, "Serrated Dirk"},
        {3145, "Hextech Alternator"},
        {3147, "Haunting Guise"},
        {3211, "Spectre's Cowl"},
        {3801, "Crystalline Bracer"},
        {3802, "Lost Chapter"},
        {3803, "Catalyst of Aeons"},
        {3916, "Oblivion Orb"},
        {6029, "Ironspike Whip"},
        {6660, "Bami's Cinder"},
        {6670, "Noonquiver"},
        {6677, "Rageknife"}};

    const std::unordered_map<int, std::string> ASSASSIN_ITEMS = {
        {3142, "Youmuu's Ghostblade"},
        {3814, "Edge of Night"},
        {6691, "Duskblade of Draktharr"},
        {6692, "Eclipse"},
        {6693, "Prowler's Claw"},
        {6694, "Serylda's Grudge"},
        {6695, "Serpent's Fang"},
        {6696, "Axiom Arc"},
        {6697, "Hubris"},
        {3179, "Umbral Glaive"},
        {3134, "Serrated Dirk"},
        {3133, "Caulfield's Warhammer"},
        {4004, "Spectral Cutlass"}};

    const std::unordered_map<int, std::string> MARKSMAN_ITEMS = {
        {3031, "Infinity Edge"},
        {3046, "Phantom Dancer"},
        {3094, "Rapid Firecannon"},
        {3095, "Stormrazor"},
        {3085, "Runaan's Hurricane"},
        {3087, "Statikk Shiv"},
        {3072, "Bloodthirster"},
        {3153, "Blade of The Ruined King"},
        {3033, "Mortal Reminder"},
        {3036, "Lord Dominik's Regards"},
        {3508, "Essence Reaver"},
        {6671, "Galeforce"},
        {6672, "Kraken Slayer"},
        {6673, "Immortal Shieldbow"},
        {6675, "Navori Quickblades"},
        {6676, "The Collector"},
        {6690, "Rectrix"},
        {6670, "Noonquiver"},
        {3086, "Zeal"},
        {1038, "B. F. Sword"},
        {1037, "Pickaxe"},
        {1043, "Recurve Bow"},
        {1042, "Dagger"},
        {1018, "Cloak of Agility"},
        {3035, "Last Whisper"},
        {3124, "Guinsoo's Rageblade"},
        {6677, "Rageknife"}};

    const std::unordered_map<int, std::string> MAGE_ITEMS = {
        {3089, "Rabadon's Deathcap"},
        {3165, "Morellonomicon"},
        {3157, "Zhonya's Hourglass"},
        {3135, "Void Staff"},
        {3137, "Cryptbloom"},
        {3100, "Lich Bane"},
        {3003, "Archangel's Staff"},
        {3040, "Seraph's Embrace"},
        {3041, "Mejai's Soulstealer"},
        {3116, "Rylai's Crystal Scepter"},
        {3115, "Nashor's Tooth"},
        {3118, "Malignance"},
        {4628, "Horizon Focus"},
        {4629, "Cosmic Drive"},
        {4645, "Shadowflame"},
        {4646, "Stormsurge"},
        {3152, "Hextech Rocketbelt"},
        {6653, "Liandry's Torment"},
        {6655, "Luden's Companion"},
        {6656, "Everfrost"},
        {6657, "Rod of Ages"},
        {4633, "Riftmaker"},
        {4636, "Night Harvester"},
        {4637, "Demonic Embrace"},
        {3802, "Lost Chapter"},
        {3803, "Catalyst of Aeons"},
        {1058, "Needlessly Large Rod"},
        {1052, "Amplifying Tome"},
        {1026, "Blasting Wand"},
        {3145, "Hextech Alternator"},
        {3108, "Fiendish Codex"},
        {3916, "Oblivion Orb"},
        {3147, "Haunting Guise"},
        {4635, "Leeching Leer"},
        {3070, "Tear of the Goddess"},
        {3113, "Aether Wisp"},
        {4642, "Bandleglass Mirror"}};

    const std::unordered_map<int, std::string> BRUISER_ITEMS = {
        {3071, "Black Cleaver"},
        {3053, "Sterak's Gage"},
        {3078, "Trinity Force"},
        {3074, "Ravenous Hydra"},
        {3748, "Titanic Hydra"},
        {6333, "Death's Dance"},
        {3161, "Spear of Shojin"},
        {3073, "Experimental Hexplate"},
        {6630, "Goredrinker"},
        {6631, "Stridebreaker"},
        {6632, "Divine Sunderer"},
        {3181, "Hullbreaker"},
        {6610, "Sundered Sky"},
        {3044, "Phage"},
        {3057, "Sheen"},
        {3077, "Tiamat"},
        {6029, "Ironspike Whip"},
        {3133, "Caulfield's Warhammer"},
        {3051, "Hearthbound Axe"},
        {1036, "Long Sword"},
        {1037, "Pickaxe"}};

    const std::unordered_map<int, std::string> TANK_ITEMS = {
        {3068, "Sunfire Aegis"},
        {3075, "Thornmail"},
        {3110, "Frozen Heart"},
        {3065, "Spirit Visage"},
        {3193, "Gargoyle Stoneplate"},
        {3083, "Warmog's Armor"},
        {3084, "Heartsteel"},
        {3143, "Randuin's Omen"},
        {3742, "Dead Man's Plate"},
        {8001, "Anathema's Chains"},
        {8020, "Abyssal Mask"},
        {4401, "Force of Nature"},
        {3026, "Guardian Angel"},
        {6662, "Iceborn Gauntlet"},
        {6664, "Hollow Radiance"},
        {6665, "Jak'Sho, The Protean"},
        {6667, "Radiant Virtue"},
        {3001, "Evenshroud"},
        {2502, "Unending Despair"},
        {2504, "Kaenic Rookern"},
        {3066, "Winged Moonplate"},
        {3067, "Kindlegem"},
        {1011, "Giant's Belt"},
        {1031, "Chain Vest"},
        {1029, "Cloth Armor"},
        {1033, "Null-Magic Mantle"},
        {1057, "Negatron Cloak"},
        {3076, "Bramble Vest"},
        {3082, "Warden's Mail"},
        {3801, "Crystalline Bracer"},
        {3211, "Spectre's Cowl"},
        {6660, "Bami's Cinder"},
        {3024, "Glacial Buckler"}};

    const std::unordered_map<int, std::string> SUPPORT_ITEMS = {
        {3504, "Ardent Censer"},
        {3222, "Mikael's Blessing"},
        {3107, "Redemption"},
        {3190, "Locket of the Iron Solari"},
        {3050, "Zeke's Convergence"},
        {3109, "Knight's Vow"},
        {2065, "Shurelya's Battlesong"},
        {6616, "Staff of Flowing Water"},
        {6617, "Moonstone Renewer"},
        {6620, "Echoes of Helia"},
        {6621, "Dawncore"},
        {3011, "Chemtech Putrifier"},
        {4005, "Imperial Mandate"},
        {3114, "Forbidden Idol"},
        {3012, "Chalice of Blessing"},
        {3850, "Spellthief's Edge"},
        {3851, "Frostfang"},
        {3853, "Shard of True Ice"},
        {3854, "Steel Shoulderguards"},
        {3855, "Runesteel Spaulders"},
        {3857, "Pauldrons of Whiterock"},
        {3858, "Relic Shield"},
        {3859, "Targon's Buckler"},
        {3860, "Bulwark of the Mountain"},
        {3862, "Spectral Sickle"},
        {3863, "Harrowing Crescent"},
        {3864, "Black Mist Scythe"},
    };

    struct Champion
    {
        std::string name;
        std::string role;
    };

    const std::unordered_map<int, Champion> CHAMPIONS = {
        {266, {"Aatrox", "Bruiser"}},
        {103, {"Ahri", "Mage"}},
        {84, {"Akali", "Assassin"}},
        {166, {"Akshan", "Marksman"}},
        {12, {"Alistar", "Tank"}},
        {799, {"Ambessa", "Bruiser"}},
        {32, {"Amumu", "Tank"}},
        {34, {"Anivia", "Mage"}},
        {1, {"Annie", "Mage"}},
        {523, {"Aphelios", "Marksman"}},
        {22, {"Ashe", "Marksman"}},
        {136, {"AurelionSol", "Mage"}},
        {893, {"Aurora", "Mage"}},
        {268, {"Azir", "Mage"}},
        {432, {"Bard", "Support"}},
        {200, {"Belveth", "Fighter"}},
        {53, {"Blitzcrank", "Tank"}},
        {63, {"Brand", "Mage"}},
        {201, {"Braum", "Tank"}},
        {233, {"Briar", "Fighter"}},
        {51, {"Caitlyn", "Marksman"}},
        {164, {"Camille", "Fighter"}},
        {69, {"Cassiopeia", "Mage"}},
        {31, {"Chogath", "Tank"}},
        {42, {"Corki", "Marksman"}},
        {122, {"Darius", "Fighter"}},
        {131, {"Diana", "Assassin"}},
        {119, {"Draven", "Marksman"}},
        {36, {"DrMundo", "Tank"}},
        {245, {"Ekko", "Assassin"}},
        {60, {"Elise", "Mage"}},
        {28, {"Evelynn", "Assassin"}},
        {81, {"Ezreal", "Marksman"}},
        {9, {"Fiddlesticks", "Mage"}},
        {114, {"Fiora", "Fighter"}},
        {105, {"Fizz", "Assassin"}},
        {3, {"Galio", "Tank"}},
        {41, {"Gangplank", "Fighter"}},
        {86, {"Garen", "Fighter"}},
        {150, {"Gnar", "Fighter"}},
        {79, {"Gragas", "Tank"}},
        {104, {"Graves", "Marksman"}},
        {887, {"Gwen", "Fighter"}},
        {120, {"Hecarim", "Fighter"}},
        {74, {"Heimerdinger", "Mage"}},
        {910, {"Hwei", "Mage"}},
        {420, {"Illaoi", "Fighter"}},
        {39, {"Irelia", "Fighter"}},
        {427, {"Ivern", "Support"}},
        {40, {"Janna", "Support"}},
        {59, {"JarvanIV", "Tank"}},
        {24, {"Jax", "Fighter"}},
        {126, {"Jayce", "Fighter"}},
        {202, {"Jhin", "Marksman"}},
        {222, {"Jinx", "Marksman"}},
        {145, {"Kaisa", "Marksman"}},
        {429, {"Kalista", "Marksman"}},
        {43, {"Karma", "Support"}},
        {30, {"Karthus", "Mage"}},
        {38, {"Kassadin", "Assassin"}},
        {55, {"Katarina", "Assassin"}},
        {10, {"Kayle", "Fighter"}},
        {141, {"Kayn", "Assassin"}},
        {85, {"Kennen", "Mage"}},
        {121, {"Khazix", "Assassin"}},
        {203, {"Kindred", "Marksman"}},
        {240, {"Kled", "Fighter"}},
        {96, {"KogMaw", "Marksman"}},
        {897, {"KSante", "Tank"}},
        {7, {"Leblanc", "Assassin"}},
        {64, {"LeeSin", "Fighter"}},
        {89, {"Leona", "Tank"}},
        {876, {"Lillia", "Fighter"}},
        {127, {"Lissandra", "Mage"}},
        {236, {"Lucian", "Marksman"}},
        {117, {"Lulu", "Support"}},
        {99, {"Lux", "Mage"}},
        {54, {"Malphite", "Tank"}},
        {90, {"Malzahar", "Mage"}},
        {57, {"Maokai", "Tank"}},
        {11, {"MasterYi", "Assassin"}},
        {902, {"Milio", "Support"}},
        {21, {"MissFortune", "Marksman"}},
        {62, {"MonkeyKing", "Fighter"}},
        {82, {"Mordekaiser", "Fighter"}},
        {25, {"Morgana", "Support"}},
        {950, {"Naafiri", "Assassin"}},
        {267, {"Nami", "Support"}},
        {75, {"Nasus", "Fighter"}},
        {111, {"Nautilus", "Tank"}},
        {518, {"Neeko", "Mage"}},
        {76, {"Nidalee", "Assassin"}},
        {895, {"Nilah", "Marksman"}},
        {56, {"Nocturne", "Assassin"}},
        {20, {"Nunu", "Tank"}},
        {2, {"Olaf", "Fighter"}},
        {61, {"Orianna", "Mage"}},
        {516, {"Ornn", "Tank"}},
        {80, {"Pantheon", "Fighter"}},
        {78, {"Poppy", "Tank"}},
        {555, {"Pyke", "Assassin"}},
        {246, {"Qiyana", "Assassin"}},
        {133, {"Quinn", "Marksman"}},
        {497, {"Rakan", "Support"}},
        {33, {"Rammus", "Tank"}},
        {421, {"RekSai", "Fighter"}},
        {526, {"Rell", "Tank"}},
        {888, {"Renata", "Support"}},
        {58, {"Renekton", "Fighter"}},
        {107, {"Rengar", "Assassin"}},
        {92, {"Riven", "Fighter"}},
        {68, {"Rumble", "Mage"}},
        {13, {"Ryze", "Mage"}},
        {360, {"Samira", "Marksman"}},
        {113, {"Sejuani", "Tank"}},
        {235, {"Senna", "Support"}},
        {147, {"Seraphine", "Support"}},
        {875, {"Sett", "Fighter"}},
        {35, {"Shaco", "Assassin"}},
        {98, {"Shen", "Tank"}},
        {102, {"Shyvana", "Fighter"}},
        {27, {"Singed", "Tank"}},
        {14, {"Sion", "Tank"}},
        {15, {"Sivir", "Marksman"}},
        {72, {"Skarner", "Tank"}},
        {901, {"Smolder", "Marksman"}},
        {37, {"Sona", "Support"}},
        {16, {"Soraka", "Support"}},
        {50, {"Swain", "Mage"}},
        {517, {"Sylas", "Mage"}},
        {134, {"Syndra", "Mage"}},
        {223, {"TahmKench", "Tank"}},
        {163, {"Taliyah", "Mage"}},
        {91, {"Talon", "Assassin"}},
        {44, {"Taric", "Support"}},
        {17, {"Teemo", "Marksman"}},
        {412, {"Thresh", "Support"}},
        {18, {"Tristana", "Marksman"}},
        {48, {"Trundle", "Fighter"}},
        {23, {"Tryndamere", "Fighter"}},
        {4, {"TwistedFate", "Mage"}},
        {29, {"Twitch", "Marksman"}},
        {77, {"Udyr", "Fighter"}},
        {6, {"Urgot", "Fighter"}},
        {110, {"Varus", "Marksman"}},
        {67, {"Vayne", "Marksman"}},
        {45, {"Veigar", "Mage"}},
        {161, {"Velkoz", "Mage"}},
        {711, {"Vex", "Mage"}},
        {254, {"Vi", "Fighter"}},
        {234, {"Viego", "Assassin"}},
        {112, {"Viktor", "Mage"}},
        {8, {"Vladimir", "Mage"}},
        {106, {"Volibear", "Fighter"}},
        {19, {"Warwick", "Fighter"}},
        {498, {"Xayah", "Marksman"}},
        {101, {"Xerath", "Mage"}},
        {5, {"XinZhao", "Fighter"}},
        {157, {"Yasuo", "Fighter"}},
        {777, {"Yone", "Fighter"}},
        {83, {"Yorick", "Fighter"}},
        {350, {"Yuumi", "Support"}},
        {154, {"Zac", "Tank"}},
        {238, {"Zed", "Assassin"}},
        {221, {"Zeri", "Marksman"}},
        {115, {"Ziggs", "Mage"}},
        {26, {"Zilean", "Support"}},
        {142, {"Zoe", "Mage"}},
        {143, {"Zyra", "Mage"}}};

    struct Perks
    {
        int Primary;
        int Secondary;
        std::array<int, 5> selections;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Perks, Primary, Secondary, selections)

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
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Participant, assists, champExperience, champLevel, championId,
                                       championName, deaths, goldEarned, item0, item1, item2, item3, item4, item5, item6, kills, perks,
                                       riotIdGameName, riotIdTagline, summoner1Id, summoner2Id, summonerName, totalMinionsKilled,
                                       neutralMinionsKilled, totalAllyJungleMinionsKilled, totalEnemyJungleMinionsKilled, totalDamageDealtToChampions,
                                       win, teamId, visionScore)

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
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MatchInfo, gameCreation, gameDuration, gameEndTimestamp, gameStartTimestamp, gameVersion, gameId, queueId, participants)

    struct MatchMetadata
    {
        std::string matchId;
        std::array<std::string, 10> participantPuuids;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MatchMetadata, matchId, participantPuuids)

    struct Match
    {
        MatchMetadata metadata;
        MatchInfo info;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Match, metadata, info)
}
