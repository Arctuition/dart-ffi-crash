import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'make_crash_platform_interface.dart';

/// An implementation of [MakeCrashPlatform] that uses method channels.
class MethodChannelMakeCrash extends MakeCrashPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('make_crash');

  @override
  Future<bool?> makeCrash(int type) async {
    final result = await methodChannel.invokeMethod<bool>('makeCrash', type);
    return result;
  }
}
