#ifndef FLUTTER_PLUGIN_TEST_CRASH_PLUGIN_H_
#define FLUTTER_PLUGIN_TEST_CRASH_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace test_crash {

class TestCrashPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  TestCrashPlugin();

  virtual ~TestCrashPlugin();

  // Disallow copy and assign.
  TestCrashPlugin(const TestCrashPlugin&) = delete;
  TestCrashPlugin& operator=(const TestCrashPlugin&) = delete;

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace test_crash

#endif  // FLUTTER_PLUGIN_TEST_CRASH_PLUGIN_H_
