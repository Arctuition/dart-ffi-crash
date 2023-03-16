import 'package:dart_ffi_crash/app_ffi.dart';
import 'package:flutter/material.dart';
import 'package:test_crash/test_crash.dart';

void main() {
  runApp(const App());
}

class App extends StatelessWidget {
  const App({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Windows Crash Demo',
      home: Home(title: 'Demo Page'),
    );
  }
}

class Home extends StatefulWidget {
  const Home({super.key, required this.title});

  final String title;

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  ffiCrash() {
    getAppApi().StartCPP();
  }

  pluginCrash(int type) {
    TestCrash.makeCrash(type);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: DefaultTextStyle(
        style: const TextStyle(fontSize: 30, color: Colors.black),
        child: Column(
          children: [
            const Padding(
              padding: EdgeInsets.symmetric(vertical: 40),
              child: Text(
                'these buttons will call the ffi crash api, which can\'t be caught by crashpad',
              ),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                TextButton(
                  onPressed: ffiCrash,
                  child: const Text('type1'),
                ),
                TextButton(
                  onPressed: ffiCrash,
                  child: const Text('type2'),
                ),
                TextButton(
                  onPressed: ffiCrash,
                  child: const Text('type3'),
                ),
                TextButton(
                  onPressed: ffiCrash,
                  child: const Text('type4'),
                ),
              ],
            ),
            const Padding(
              padding: EdgeInsets.symmetric(vertical: 40),
              child: Text(
                'these buttons will call the plugin crash api, which can be caught by crashpad',
              ),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                TextButton(
                  onPressed: () => pluginCrash(1),
                  child: const Text('type1'),
                ),
                TextButton(
                  onPressed: () => pluginCrash(2),
                  child: const Text('type2'),
                ),
                TextButton(
                  onPressed: () => pluginCrash(3),
                  child: const Text('type3'),
                ),
                TextButton(
                  onPressed: () => pluginCrash(4),
                  child: const Text('type4'),
                ),
              ],
            ),
            const Padding(
              padding: EdgeInsets.symmetric(vertical: 80),
              child: Text(
                'the ffi crash api and plugin crash api call the same cpp method',
              ),
            ),
          ],
        ),
      ),
    );
  }
}
