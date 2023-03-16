import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'make_crash_method_channel.dart';

abstract class MakeCrashPlatform extends PlatformInterface {
  /// Constructs a MakeCrashPlatform.
  MakeCrashPlatform() : super(token: _token);

  static final Object _token = Object();

  static MakeCrashPlatform _instance = MethodChannelMakeCrash();

  /// The default instance of [MakeCrashPlatform] to use.
  ///
  /// Defaults to [MethodChannelMakeCrash].
  static MakeCrashPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [MakeCrashPlatform] when
  /// they register themselves.
  static set instance(MakeCrashPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<bool?> makeCrash(int type) {
    throw UnimplementedError('makeCrash() has not been implemented.');
  }
}
