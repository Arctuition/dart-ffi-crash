#include "make_crash_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

#include <iostream>
// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

#include "../../../app/crash.h"

namespace make_crash {

// static
void MakeCrashPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "make_crash",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<MakeCrashPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

MakeCrashPlugin::MakeCrashPlugin() {}

MakeCrashPlugin::~MakeCrashPlugin() {}

void MakeCrashPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare("makeCrash") == 0) {
    const auto type = std::get_if<int>(method_call.arguments());
    int crashType = *type;
    Crash::Trigger(crashType);
    //result->Success(flutter::EncodableValue(true));
  } else {
    result->NotImplemented();
  }
}

}  // namespace make_crash
