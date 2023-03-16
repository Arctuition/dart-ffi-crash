#include "scene.h"
#include <iostream>

void Scene::TriggerCrash(int crashType)
{
    switch (crashType)
    {
    case 0:
    {
        std::cout << "The divisor is zero" << std::endl;
        int a = 2;
        int b = 0;
        int c = a / b;
    }
    break;

    case 1:
    {
        std::cout << "memory error" << std::endl;
        int *iPtr = nullptr;
        *iPtr = 3;
    }
    break;

    case 2:
    {
        std::cout << "throw exception" << std::endl;
        throw 1;
    }
    break;
    
    default:
    {
        std::cout << "memory error" << std::endl;
        static void *invalid_mem = (void *)1;
        memset((char *)invalid_mem, 1, 100);
    }
    break;
    }
}
