#include "ffi_api.h"
#include "crash.h"
#include <iostream>

API void StartCPP() {
    std::cout << "hello, cpp!"<< std::endl;
    Crash::Trigger(1);
}