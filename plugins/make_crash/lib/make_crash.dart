import 'make_crash_platform_interface.dart';

class MakeCrashPlugin {
  static Future<bool?> makeCrash(int type) {
    return MakeCrashPlatform.instance.makeCrash(type);
  }
}
