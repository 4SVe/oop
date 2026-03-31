#include "Tank.h"
#include <iostream>

static int tankIdCounter = 0;

Tank::Tank() : name("Unnamed Tank"), armor(100), speed(50), ammo(0), fuel(100.0f) {
    tankIdCounter++;
}

Tank::Tank(const std::string& name, int armor, int speed)
    : name(name), armor(armor), speed(speed), ammo(50), fuel(100.0f) {
    tankIdCounter++;
}

Tank::Tank(const std::string& name, int armor, int speed, int ammo, float fuel)
    : name(name), armor(armor), speed(speed), ammo(ammo), fuel(fuel) {
    tankIdCounter++;
}

Tank::~Tank() {
    std::cout << "Tank destroyed: " << name << std::endl;
}

std::string Tank::getName() const {
    return name;
}

void Tank::setName(const std::string& name) {
    this->name = name;
}

int Tank::getArmor() const {
    return armor;
}

void Tank::setArmor(int armor) {
    this->armor = armor;
}

int Tank::getSpeed() const {
    return speed;
}

void Tank::setSpeed(int speed) {
    this->speed = speed;
}

int Tank::getAmmo() const {
    return ammo;
}

void Tank::setAmmo(int ammo) {
    this->ammo = ammo;
}

float Tank::getFuel() const {
    return fuel;
}

void Tank::setFuel(float fuel) {
    this->fuel = fuel;
}

void Tank::refuel(float amount) {
    fuel += amount;
    if (fuel > 100.0f) fuel = 100.0f;
    std::cout << name << " заправлен. Топливо: " << fuel << "%" << std::endl;
}

void Tank::reload(int shells) {
    ammo += shells;
    std::cout << name << " перезаряжен. Боеприпасы: " << ammo << std::endl;
}

int Tank::getPower() const {
    return armor + speed + ammo;
}
