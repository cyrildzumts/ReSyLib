# ReSyLib

Library for Reactive Systems in C++11 for easy GPIO access - tested on Beaglebone Black Rev C

The library in this repository is the result of a lecture class by Prof. Stephan Pareigis held at Hamburg University of Applied Sciences Department Computer Science.
The goal is, to have a  C++11 library according to newest programming standards. It is intended to provide tools for embedded reactive systems. In particular, it is written for BBB and gives easy access to GPIO.

Here are some ideas:
- hardware abstraction layer
- finit state machine
- proxy
- factory for message objects
- dispatcher and observer
- message queue
- protocol state machine


How  to compile this library :

Requirements to compile this library :
# ARM-GCC  gnueabihf toolchains linux( GCC 4.8++ is required)
# make
# cmake
Homepage: http://deeplyembedded.github.io/ReSyLib/
