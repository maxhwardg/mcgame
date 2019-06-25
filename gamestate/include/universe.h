//
// Created by maxward on 6/25/19.
//

#ifndef MCGAME_UNIVERSE_H
#define MCGAME_UNIVERSE_H

#include <vector>

enum class PlanetType {
    GAS_GIANT,
    BARREN,
    OCEAN,
    TUNDRA,
    SWAMP,
    TERRAN,
    GAIA,
};

class Colony {
public:
    int owning_player_number;
    int pop_industry;
    int pop_science;
    int pop_farming;
};

class Planet {
public:
    int current_population;
    int size;
    PlanetType type;
};

enum class ShipType {
    COLONY,
    FIGHTER,
    FREIGHTER,
    TRADER,
};

class Ship {
public:
    int combat_strength;
    int defence;
    int speed;
};

class System {
public:
    std::vector<Planet> planets;
    std::vector<Ship> ships;
};

/// A universe is like the game board. Contains data defining a game universe and methods for using this data.
class Universe {
private:
public:
};

#endif //MCGAME_UNIVERSE_H
