#pragma once
#include "Tank.h"

class ZRK : public Tank {
private:
    int missileCount;
    int radarRange;
    bool radarActive;
    bool targetLocked;

public:
    ZRK();
    ZRK(const std::string& name, int armor, int speed);
    ZRK(const std::string& name, int armor, int speed, int ammo, float fuel, int radarRange);

    void info() const override;
    void attack() const override;

    void enableRadar();
    void disableRadar();
    void trackTarget(const std::string& targetName);
    void unlockTarget();

    int getMissileCount() const;
    void setMissileCount(int count);

    int getRadarRange() const;
    void setRadarRange(int range);

    bool isRadarActive() const;

    bool isTargetLocked() const;
    std::string getLockedTarget() const;

    void reloadMissiles(int count);
};
