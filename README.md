Demonstration project of a simple DNP3 device based on [opendnp3](https://www.automatak.com/opendnp3) and the raspberry Pi + Piface.

Why put dnp3 on the RPi? Because it's fun and a cheap demo of it running on a non-x86 architecture.

1. Build and install opendnp3 2.0.1 on the RPi or via cross compiler using cmake
2. Build and install libpiface-1.0 (https://github.com/thomasmacpherson/piface)
3. Build piface rtu:

```
$ autoreconf -i -f
$ ./configure CXXFLAGS=-O2
$ make
$ ./pifacertu
```

By default, the RTU listens on port 20000. Master address is 1, outstation address is 1024. You can change these in the source
or setup some command line arguments. Pull requests happily accepted =).

ControlRelayOutputBlock requests can be sent to indices 0 to 7 with LATCH_ON or LATCH_OFF.

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
