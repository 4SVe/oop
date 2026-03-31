#include <iostream>
#include <vector>
#include "Tank.h"
#include "BMP.h"
#include "ZRK.h"

int main() {
    BMP bmp;
    bmp.setName("БМП-2");
    bmp.setArmor(150);
    bmp.setSpeed(65);
    bmp.setAmmo(300);
    bmp.setFuel(85.5f);
    bmp.setTroopCapacity(7);
    
    bmp.getName();
    bmp.getArmor();
    bmp.getSpeed();

    ZRK zrk("Стрела-10", 100, 60);
    zrk.info();
    zrk.refuel(50);
    zrk.reload(100);

    std::vector<Tank*> army;
    army.push_back(new BMP("БМП-3", 180, 70));
    army.push_back(new ZRK("Тор-М2", 120, 50));
    army.push_back(new BMP("БМП-1", 130, 62));
    army.push_back(new ZRK("Бук-М2", 150, 55));

    for (size_t i = 0; i < army.size(); i++) {
        army[i]->info();
    }

    for (size_t i = 0; i < army.size(); i++) {
        army[i]->attack();
    }

    for (size_t i = 0; i < army.size(); i++) {
        army[i]->getName();
        army[i]->getPower();
    }

    BMP* bmpPtr = static_cast<BMP*>(army[0]);
    bmpPtr->embarkDemolition(6);
    bmpPtr->setSmokeScreen();
    
    ZRK* zrkPtr = static_cast<ZRK*>(army[1]);
    zrkPtr->enableRadar();
    zrkPtr->trackTarget("Су-27");
    zrkPtr->attack();
    
    for (size_t i = 0; i < army.size(); i++) {
        delete army[i];
    }

    return 0;
}
