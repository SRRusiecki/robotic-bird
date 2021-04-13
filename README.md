# robotic-bird
The Arduino program of experimental robotic bird

## Introduction

Starling is a medium-sized passerine bird. The song of a male starling during the breeding season is often accompanied by two distinct types of wing movements. Recent analysis of high-quality AV recordings revealed precise temporal coordination between song and movements in the starling display (article in preparation). The taxidermic robotic starling was used in field experiments held to separately test the function of different types of movements. The movements of robotic bird were combined with acoustic playbacks to observe the receiver’s response to experimental displays.

## Robotic bird

The robotic bird consisted of two high-speed digital servo-motors (KST Digital Standard Brushless Servo MS805) and audio mini sound board (Adafruit 2341). Wings of taxidermic starling were attached to the servo-motors with separate transition shafts. The whole set was controlled by circuit-board based on the Arduino platform (Arduino Micro; http://www.arduino.cc). It enables timing of wing movements and sounds to be programed with millisecond precision. The operation of the robot was controlled by the custom design Arduino remote controller with XBee WiFi module (Digi International, Minnetonka, MN, USA).

The Arduino code in the project includes two separate programs for:
1) robotic bird control module,
2) 4 button XBee WiFi remote controller.
