#include "include/make_crash/make_crash_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "make_crash_plugin.h"

void MakeCrashPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  make_crash::MakeCrashPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
