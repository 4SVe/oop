#include "ZRK.h"
#include <iostream>

ZRK::ZRK() : Tank(), missileCount(8), radarRange(5000), radarActive(false), targetLocked(false) {}

ZRK::ZRK(const std::string& name, int armor, int speed)
    : Tank(name, armor, speed), missileCount(8), radarRange(5000), radarActive(false), targetLocked(false) {}

ZRK::ZRK(const std::string& name, int armor, int speed, int ammo, float fuel, int radarRange)
    : Tank(name, armor, speed, ammo, fuel), missileCount(8), radarRange(radarRange), radarActive(false), targetLocked(false) {}

void ZRK::info() const {
    std::cout << "=== ЗРК (Зенитный Ракетный Комплекс) ===" << std::endl;
    std::cout << "Название: " << getName() << std::endl;
    std::cout << "Броня: " << getArmor() << " мм" << std::endl;
    std::cout << "Скорость: " << getSpeed() << " км/ч" << std::endl;
    std::cout << "Зенитные ракеты: " << missileCount << " шт." << std::endl;
    std::cout << "Дальность радара: " << radarRange << " м" << std::endl;
    std::cout << "Топливо: " << getFuel() << "%" << std::endl;
    std::cout << "Радар: " << (radarActive ? "ВКЛЮЧЕН" : "выключен") << std::endl;
    std::cout << "Цель захвачена: " << (targetLocked ? "ДА" : "нет") << std::endl;
    std::cout << "======================================" << std::endl;
}

void ZRK::attack() const {
    std::cout << getName() << " производит пуск зенитной ракеты!" << std::endl;
    if (targetLocked) {
        std::cout << "Ракета наводится на захваченную цель!" << std::endl;
    } else {
        std::cout << "Внимание: цель не захвачена! Производится пуск вслепую." << std::endl;
    }
}

void ZRK::enableRadar() {
    radarActive = true;
    std::cout << getName() << " включает радар. Дальность: " << radarRange << " м" << std::endl;
    std::cout << "Поиск воздушных целей..." << std::endl;
}

void ZRK::disableRadar() {
    radarActive = false;
    targetLocked = false;
    std::cout << getName() << " выключает радар." << std::endl;
}

void ZRK::trackTarget(const std::string& targetName) {
    if (!radarActive) {
        std::cout << "Ошибка: радар выключен! Включите радар перед захватом цели." << std::endl;
        return;
    }
    targetLocked = true;
    std::cout << getName() << " захватывает цель: " << targetName << std::endl;
    std::cout << "Цель сопровождается. Ожидание команды на пуск." << std::endl;
}

void ZRK::unlockTarget() {
    if (targetLocked) {
        targetLocked = false;
        std::cout << getName() << " отпускает цель." << std::endl;
    } else {
        std::cout << "Цель не захвачена." << std::endl;
    }
}

int ZRK::getMissileCount() const {
    return missileCount;
}

void ZRK::setMissileCount(int count) {
    missileCount = count;
}

int ZRK::getRadarRange() const {
    return radarRange;
}

void ZRK::setRadarRange(int range) {
    radarRange = range;
}

bool ZRK::isRadarActive() const {
    return radarActive;
}

bool ZRK::isTargetLocked() const {
    return targetLocked;
}

std::string ZRK::getLockedTarget() const {
    return targetLocked ? "Захваченная цель" : "Нет цели";
}

void ZRK::reloadMissiles(int count) {
    missileCount += count;
    std::cout << getName() << " перезаряжен. Ракеты: " << missileCount << " шт." << std::endl;
}
