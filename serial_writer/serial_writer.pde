/*
A simple Processing script for enabling/disabling the LED on an Arduino using a web interface
*/

import processing.serial.*;

Serial port;

void setup() {
  port = new Serial(this, Serial.list()[1]);
}

void draw() {
  String onoroff[] = loadStrings("http://www.welikelazorguns.us/LEDstate.txt");
  print(onoroff[0]);
  
  if (onoroff[0].equals("1")) {
    println(" - Telling Arduino to turn LED on");
    port.write('H');
  }
  
  if (onoroff[0].equals("0")) {
    println(" - Telling Arduino to turn LED off");
    port.write('L');
  }
  
  delay(1000);
}
