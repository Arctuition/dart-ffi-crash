import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'test_crash_method_channel.dart';

abstract class TestCrashPlatform extends PlatformInterface {
  /// Constructs a TestCrashPlatform.
  TestCrashPlatform() : super(token: _token);

  static final Object _token = Object();

  static TestCrashPlatform _instance = MethodChannelTestCrash();

  /// The default instance of [TestCrashPlatform] to use.
  ///
  /// Defaults to [MethodChannelTestCrash].
  static TestCrashPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [TestCrashPlatform] when
  /// they register themselves.
  static set instance(TestCrashPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  void makeCrash(int type) {
    throw UnimplementedError('makeCrash() has not been implemented.');
  }
}
