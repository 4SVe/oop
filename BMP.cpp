#include "BMP.h"
#include <iostream>

BMP::BMP() : Tank(), troopCapacity(8), troopsOnBoard(0), smokeGeneratorActive(false) {}

BMP::BMP(const std::string& name, int armor, int speed)
    : Tank(name, armor, speed), troopCapacity(8), troopsOnBoard(0), smokeGeneratorActive(false) {}

BMP::BMP(const std::string& name, int armor, int speed, int ammo, float fuel, int capacity)
    : Tank(name, armor, speed, ammo, fuel), troopCapacity(capacity), troopsOnBoard(0), smokeGeneratorActive(false) {}

void BMP::info() const {
    std::cout << "=== БМП (Боевая Машина Пехоты) ===" << std::endl;
    std::cout << "Название: " << getName() << std::endl;
    std::cout << "Броня: " << getArmor() << " мм" << std::endl;
    std::cout << "Скорость: " << getSpeed() << " км/ч" << std::endl;
    std::cout << "Боеприпасы: " << getAmmo() << " снарядов" << std::endl;
    std::cout << "Топливо: " << getFuel() << "%" << std::endl;
    std::cout << "Десант на борту: " << troopsOnBoard << "/" << troopCapacity << " солдат" << std::endl;
    std::cout << "Дымовая завеса: " << (smokeGeneratorActive ? "АКТИВНА" : "выключена") << std::endl;
    std::cout << "================================" << std::endl;
}

void BMP::attack() const {
    std::cout << getName() << " ведет огонь из автоматической пушки!" << std::endl;
    std::cout << "Десант " << troopsOnBoard << " солдат готов к бою!" << std::endl;
}

void BMP::embarkDemolition(int soldiers) {
    if (troopsOnBoard + soldiers <= troopCapacity) {
        troopsOnBoard += soldiers;
        std::cout << "Десант (" << soldiers << " солдат) погружен на борт " << getName() << std::endl;
        std::cout << "Всего на борту: " << troopsOnBoard << " солдат" << std::endl;
    } else {
        std::cout << "Недостаточно места! Свободно: " << (troopCapacity - troopsOnBoard) << " мест" << std::endl;
    }
}

void BMP::disembarkDemolition() {
    if (troopsOnBoard > 0) {
        std::cout << "Десант (" << troopsOnBoard << " солдат) высаживается из " << getName() << std::endl;
        troopsOnBoard = 0;
    } else {
        std::cout << "Десанта на борту нет!" << std::endl;
    }
}

void BMP::setSmokeScreen() {
    smokeGeneratorActive = true;
    std::cout << getName() << " ставит дымовую завесу!" << std::endl;
    std::cout << "Видимость на поле боя снижена." << std::endl;
    smokeGeneratorActive = false;
}

int BMP::getTroopCapacity() const {
    return troopCapacity;
}

void BMP::setTroopCapacity(int capacity) {
    troopCapacity = capacity;
}

int BMP::getTroopsOnBoard() const {
    return troopsOnBoard;
}

void BMP::setTroopsOnBoard(int troops) {
    troopsOnBoard = troops;
}

bool BMP::isSmokeGeneratorActive() const {
    return smokeGeneratorActive;
}

void BMP::setSmokeGeneratorActive(bool active) {
    smokeGeneratorActive = active;
}

void BMP::repair(int amount) {
    setArmor(getArmor() + amount);
    std::cout << getName() << " отремонтирован. Броня увеличена на " << amount << " мм" << std::endl;
}
