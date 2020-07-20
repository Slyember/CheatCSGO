#include <thread>
#include "Includes.h"


void esp()
{
    DWORD glowObject = rpm<DWORD>(baseAddress + dwGlowObjectManager);

    while (!GetAsyncKeyState(VK_F10)) {

        for (int i = 0; i < 64; i++) {
            DWORD entity = Entity::getEntBase(i);

            if (Entity::isValid(entity)) {
                if (Entity::getEntTeam(entity) != LocalPlayer::getLocalTeam()) {

                    // Glow hack
                    int glowIndex = Entity::getGlowIndex(entity);
                    float defuseColor = Entity::getEntDefusing(entity) ? 0.0f : 1.0f;
                    Entity::glowEsp(glowObject, glowIndex, 1.0f, defuseColor, defuseColor, 0.75f);

                    // Radar hack
                    Entity::setSpotted(entity, true);
                }
            }
        }

        Sleep(1);
    }
}

void menu()
{
    while (!GetAsyncKeyState(VK_F10))
    {
        // Menu
    }
}

int main()
{
    init();

    //std::thread tMenu(menu);
    std::thread tEsp(esp);

    //tMenu.join();
    tEsp.join();

    CloseHandle(hProc);
}
