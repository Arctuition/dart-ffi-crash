#ifndef FLUTTER_PLUGIN_MAKE_CRASH_PLUGIN_H_
#define FLUTTER_PLUGIN_MAKE_CRASH_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace make_crash {

class MakeCrashPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  MakeCrashPlugin();

  virtual ~MakeCrashPlugin();

  // Disallow copy and assign.
  MakeCrashPlugin(const MakeCrashPlugin&) = delete;
  MakeCrashPlugin& operator=(const MakeCrashPlugin&) = delete;

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace make_crash

#endif  // FLUTTER_PLUGIN_MAKE_CRASH_PLUGIN_H_
