import 'dart:async';
import 'dart:io';
import 'package:flutter/material.dart';

import 'package:flutter_acrylic/flutter_acrylic.dart';
import 'package:bitsdojo_window/bitsdojo_window.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Window.initialize();
  if (Platform.isWindows) {
    await Window.hideWindowControls();
  }
  runApp(MyApp());
  if (Platform.isWindows) {
    doWhenWindowReady(() {
      appWindow
        ..minSize = Size(640, 360)
        ..size = Size(720, 540)
        ..alignment = Alignment.center
        ..show();
    });
  }
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: MyAppBody(),
    );
  }
}

class MyAppBody extends StatefulWidget {
  MyAppBody({Key? key}) : super(key: key);

  @override
  MyAppBodyState createState() => MyAppBodyState();
}

class MyAppBodyState extends State<MyAppBody> {
  @override
  void initState() {
    super.initState();
    Window.makeWindowFullyTransparent();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      color: Color.fromARGB(0, 0, 0, 0),
      child: Center(
          child: Container(
        color: Colors.black,
        child: OutlinedButton(
          child: const Text('Hoge'),
          onPressed: () {
            print('hoge');
          },
        ),
      )),
    );
  }
}
