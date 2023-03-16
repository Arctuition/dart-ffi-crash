#include "include/test_crash/test_crash_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "test_crash_plugin.h"

void TestCrashPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  test_crash::TestCrashPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
