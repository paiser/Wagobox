# Wago

Device server for Wago 750 series Programable Fieldbus Controllers 
and Fieldbus Couplers. The class supports reading and writing to a node
consisting of a number of Wago modules. It communicates with device over
Modbus TCP or RTU protocol by means of Modbus Tango class.

## Cloning

Any instructions or special flags required to clone the project. For example, if the project has submodules in git, then specify this and give the command to check them out correctly, example:

```
git clone --recurse-submodules git@gitlab.esrf.fr:accelerators/Instruments/wago.git
```

## Documentation

Pogo generated documentation in **doc_html** folder

## Building and Installation

### Dependencies

The project has the following dependencies.

#### Project Dependencies

* Tango Controls 9 or higher.
* omniORB release 4 or higher.
* libzmq - libzmq3-dev or libzmq5-dev.
* Modbus Serial Tango Classes.

#### Toolchain Dependencies

* C++11 compliant compiler.

### Build

Instructions on building the project.

Make example:

```bash
make
```

You can also make WagoInterlock:

```bash
cd WagoInterlock
make
```

