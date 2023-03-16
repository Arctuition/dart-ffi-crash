import 'dart:ffi';
import 'dart:io';

import 'generated_bindings.dart';

FFIApi? _api;

FFIApi getFFIApi() {
  if (_api == null) {
    late DynamicLibrary lib;
    if (Platform.isWindows) {
      lib = DynamicLibrary.open('app.dll');
    } else if (Platform.isMacOS || Platform.isIOS) {
      lib = DynamicLibrary.process();
    } else {
      lib = DynamicLibrary.open('app.so');
    }
    _api = FFIApi(lib);
  }
  return _api!;
}
