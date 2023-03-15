import 'dart:ffi';
import 'dart:io';
import '../generated_bindings.dart';

AppApi? _api;

AppApi getAppApi() {
  if (_api == null) {
    late DynamicLibrary lib;
    if (Platform.isWindows) {
      lib = DynamicLibrary.open('app.dll');
    } else if (Platform.isMacOS || Platform.isIOS) {
      lib = DynamicLibrary.process();
    } else {
      lib = DynamicLibrary.open('app.so');
    }
    _api = AppApi(lib);
  }
  return _api!;
}
