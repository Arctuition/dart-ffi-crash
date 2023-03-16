# dart_ffi_crash

The program only use to verify that carshes which is made by ffi can not be captured.

There are two ways to verify. Same program call ffi interface and c++ plugin. Crash in Ffi module( c++ code be called) can not be captured. Crash in c++ plugins can be captured.

In addation, crash in main function can be captured.

## Getting Started

* install flutter  -- you can follow this to install https://docs.flutter.dev/get-started/install/windows
* run the command -- flutter run -d windows
* click the buttoms,  ./.sentry-native folder will be generated in the root directoy of the project. If click the buttoms about ffi, dump file can not be generated. If click the buttom about plugins, dump file can be generated.
* you can open the windows/runner/main.cpp, make some crashes , they can be captured, too. The code of sentry to initialize is in it.  It is the program entry.
