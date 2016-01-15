Demonstration project of a simple DNP3 device based on [opendnp3](https://www.automatak.com/opendnp3) and the raspberry Pi + Piface.

Why put dnp3 on the RPi? Because it's fun and a cheap demo of it running on a non-x86 architecture with real I/O.

By default, the RTU listens on port 20000. Master address is 1, outstation address is 1024. You can change these in the source
or setup some command line arguments. Pull requests happily accepted =).

ControlRelayOutputBlock (CROB) requests can be sent to indices 0 to 7 with LATCH_ON or LATCH_OFF to toggle the state of the output. PULSE_ON and PULSE_OFF can be used in combination with the count and timing parameters to execute step functions. The current resolution is limited to 100ms, but could be updated in the code. 

| Index         | Function        |
| ------------- |:---------------:|
| 0             | Relay 1 + LED1  |
| 1             | Relay 2 + LED2  |
| 2             | LED3            |
| 3             | LED4            |
| 4             | LED5            |
| 5             | LED6            |
| 6             | LED7            |
| 7             | LED8            |


Switches 1-4 are mapped to BinaryInput indices 0-3

| Index         | Function        |
| ------------- |:---------------:|
| 0             | Switch1         |
| 1             | Switch2         |
| 2             | Switch3         |
| 3             | Switch4         |


Enjoy!

Building
==========================

Piface RTU expects the various opendnp3 libraries to be installed.

Use opendnp3 2.0.x on the RPi or via cross compiler *using the cmake build system*. Make sure that you've defined ASIO_HOME environment variable.

```
   * cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr
   * make
   * sudo make install
```

Piface RTU expects [libpiface-1.0](https://github.com/thomasmacpherson/piface) to be installed.

```
   * cd c
   * ./autogen.sh
   * ./configure --prefix=/usr
   * make
   * make install
```

With both depenencies installed 

Build piface rtu:
```
   * cmake .
   * make
```
