import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'test_crash_platform_interface.dart';

/// An implementation of [TestCrashPlatform] that uses method channels.
class MethodChannelTestCrash extends TestCrashPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('test_crash');

  @override
  void makeCrash(int type) async {
    methodChannel.invokeMethod('makeCrash', type);
  }
}
