#include <iostream>
#include <vector>
#include "Tank.h"
#include "BMP.h"
#include "ZRK.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "========================================" << std::endl;
    std::cout << "    ЛАБОРАТОРНАЯ РАБОТА №1 ПО ООП" << std::endl;
    std::cout << "    Тема: Инкапсуляция, Наследование," << std::endl;
    std::cout << "           Полиморфизм" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    std::cout << "=== ИНКАПСУЛЯЦИЯ ===" << std::endl;
    std::cout << "Доступ к закрытым полям через геттеры/сеттеры:" << std::endl;
    
    BMP bmp;
    bmp.setName("БМП-2");
    bmp.setArmor(150);
    bmp.setSpeed(65);
    bmp.setAmmo(300);
    bmp.setFuel(85.5f);
    bmp.setTroopCapacity(7);
    
    std::cout << "  Имя (геттер): " << bmp.getName() << std::endl;
    std::cout << "  Броня (геттер): " << bmp.getArmor() << std::endl;
    std::cout << "  Скорость (геттер): " << bmp.getSpeed() << " км/ч" << std::endl;
    std::cout << std::endl;

    std::cout << "=== НАСЛЕДОВАНИЕ ===" << std::endl;
    std::cout << "Класс ЗРК наследует от Танк:" << std::endl;
    
    ZRK zrk("Стрела-10", 100, 60);
    zrk.info();
    
    std::cout << "Вызов унаследованных методов (refuel, reload):" << std::endl;
    zrk.refuel(50);
    zrk.reload(100);
    std::cout << std::endl;

    std::cout << "=== ПОЛИМОРФИЗМ ===" << std::endl;
    std::cout << "Работа с объектами через указатели на базовый класс Tank*:" << std::endl;
    std::cout << std::endl;

    std::vector<Tank*> army;
    army.push_back(new BMP("БМП-3", 180, 70));
    army.push_back(new ZRK("Тор-М2", 120, 50));
    army.push_back(new BMP("БМП-1", 130, 62));
    army.push_back(new ZRK("Бук-М2", 150, 55));

    std::cout << "--- Вызов виртуального метода info() ---" << std::endl;
    for (size_t i = 0; i < army.size(); i++) {
        army[i]->info();
    }

    std::cout << "--- Вызов виртуального метода attack() ---" << std::endl;
    for (size_t i = 0; i < army.size(); i++) {
        army[i]->attack();
        std::cout << std::endl;
    }

    std::cout << "--- Вызов унаследованного метода getPower() ---" << std::endl;
    for (size_t i = 0; i < army.size(); i++) {
        std::cout << army[i]->getName() << " - Боевая мощь: " 
                  << army[i]->getPower() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "--- Вызов собственных методов через static_cast ---" << std::endl;
    
    BMP* bmpPtr = static_cast<BMP*>(army[0]);
    bmpPtr->embarkDemolition(6);
    bmpPtr->setSmokeScreen();
    
    ZRK* zrkPtr = static_cast<ZRK*>(army[1]);
    zrkPtr->enableRadar();
    zrkPtr->trackTarget("Су-27");
    zrkPtr->attack();
    
    std::cout << std::endl;

    std::cout << "--- Освобождение памяти ---" << std::endl;
    for (size_t i = 0; i < army.size(); i++) {
        delete army[i];
    }
    army.clear();

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "          РАБОТА ЗАВЕРШЕНА" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
