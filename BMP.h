#pragma once
#include "Tank.h"

class BMP : public Tank {
private:
    int troopCapacity;
    int troopsOnBoard;
    bool smokeGeneratorActive;

public:
    BMP();
    BMP(const std::string& name, int armor, int speed);
    BMP(const std::string& name, int armor, int speed, int ammo, float fuel, int capacity);

    void info() const override;
    void attack() const override;

    void embarkDemolition(int soldiers);
    void disembarkDemolition();
    void setSmokeScreen();

    int getTroopCapacity() const;
    void setTroopCapacity(int capacity);

    int getTroopsOnBoard() const;
    void setTroopsOnBoard(int troops);

    bool isSmokeGeneratorActive() const;
    void setSmokeGeneratorActive(bool active);

    void repair(int amount);
};
