DNP3 Remote Terminal Unit (RTU) based on opendnp3 (dnp3.github.com) and the raspberry Pi + Piface.

1. Build and install opendnp3 on the Pi or via cross compiler (dnp3.github.com)
2. Build and install libpiface-1.0 (https://github.com/thomasmacpherson/piface)
3. Build piface rtu:

```
$ autoreconf -i -f
$ ./configure CXXFLAGS=-O2
$ make
$ ./pifacertu
```

By default, the RTU listens on port 20000. Master address is 1, outstation address is 1024.

ControlRelayOutputBlock requests can be sent to indices 0 to 7 with LATCH_ON or LATCH_OFF. Indices 0 an 1 control the relays.
