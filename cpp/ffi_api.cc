#include "ffi_api.h"
#include "crash.h"
#include <iostream>

API void makeCrash(int type) {
    std::cout << "hello, cpp!"<< std::endl;
    Crash::Trigger(type);
}