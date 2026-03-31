#pragma once
#include <string>

class Tank {
protected:
    std::string name;
    int armor;
    int speed;

private:
    int ammo;
    float fuel;

public:
    Tank();
    Tank(const std::string& name, int armor, int speed);
    Tank(const std::string& name, int armor, int speed, int ammo, float fuel);
    virtual ~Tank();

    std::string getName() const;
    void setName(const std::string& name);

    int getArmor() const;
    void setArmor(int armor);

    int getSpeed() const;
    void setSpeed(int speed);

    int getAmmo() const;
    void setAmmo(int ammo);

    float getFuel() const;
    void setFuel(float fuel);

    virtual void info() const = 0;
    virtual void attack() const = 0;

    void refuel(float amount);
    void reload(int shells);
    int getPower() const;
};
