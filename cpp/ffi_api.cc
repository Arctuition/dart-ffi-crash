#include "ffi_api.h"
#include "scene.h"
#include <iostream>

API void StartCPP() {
    std::cout << "hello, cpp!"<< std::endl;
    Scene::GetScene()->TriggerCrash(1);
}