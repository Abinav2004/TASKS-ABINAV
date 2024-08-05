A common interface that is used to allow communication between different peripheral devices like mice, digital cameras, printers, keyboards, media devices, scanners, flash drives & external hard drives as well as a host controller like a smartphone or PC is known as USB protocol.

A universal serial bus is intended to allow hot swapping & enhance plug-N- play. The plug-and-play allows the OS to configure and discover a new peripheral device spontaneously without starting the computer whereas hot swapping removes and replaces a new peripheral device without rebooting.  
There are different types of USB connectors available in the market where Type A and Type B are the most frequently used ones. At present, older connectors are replaced by Mini-USB, Micro-USB & USB-C cables.

### USB Protocol Architecture ###
The architecture of the USB protocol is shown below. Once various I/O devices are connected through USB to the computer then they all are structured like a tree. In this USB structure, every I/O device will make a point-to-point connection to transmit data through the serial transmission format.

In this architecture, I/O devices are connected to the computer through USB which is called as a hub. The Hub within the architecture is the connecting point between both the I/O devices as well as the computer. The root hub in this architecture is used to connect the whole structure to the hosting computer. The I/O devices in this architecture are a keyboard, mouse, speaker, camera, etc.

![[Pasted image 20240628143758.png|500]]

The USB protocol simply works on the polling principle because, in polling, the processor continuously checks whether the input/output device is prepared for transmitting data or not. Thus, the I/O devices do not have to update the processor regarding their conditions because it is the main responsibility of the processor to check continuously. So this will make the USB low-cost & simple.
Whenever a new device is allied to the hub then it is addressed like ‘0’. During a normal period, the host computer will poll the hubs to obtain their condition which allows the host to know the I/O devices from the system are attached or detached from the system.
Once the host becomes responsive to the new device then it knows the device capacities by reading the available data within the particular memory of the USB interface of the device. So that the host uses a suitable driver to communicate with devices. After that, the host allocates an address to the new device which is written to the device register. With this device, USB provides plug-and-play features.

Another feature of the USB protocol is “hot-pluggable” which means, the I/O device is connected or removed from the host system without doing any shutdown or restart. So your system runs continuously when the I/O device is connected or detached.

USB protocol can also support the isochronous traffic wherever the data is transmitted at a preset interval of time. The transmission of isochronous data is very faster as compared to synchronous & asynchronous data transfer.

_isochronous data : In USB, isochronous data transfer provides guaranteed bandwidth and regular, periodic data transfers for time-sensitive applications such as audio and video streaming. It prioritizes timely delivery over perfect accuracy, meaning errors are not corrected via retransmission. This ensures a steady, continuous data flow necessary for real-time communication. Isochronous data transfer in USB is used for applications like streaming audio from a USB microphone to a computer.
In this scenario, the microphone sends audio data at regular intervals. The USB system guarantees the necessary bandwidth to ensure that audio samples arrive in a steady stream. However, if some data packets are lost or corrupted, they are not retransmitted, as timely delivery is more critical for maintaining audio continuity than perfect accuracy. This ensures real-time audio streaming without interruptions._

### USB Protocol Features

The **features of USB** include the following.
- The maximum speed of USB 2.0 is up to 480 Mbps.
- An individual USB length can reach up to 40 meters including a hub and up to five meters without a hub
- USB is a plug & play device.
- It can draw power from a computer or through its own supply.
- By using a single USB host controller, above 100 peripherals can be connected.
- The power used by a USB device is up to 5 V & delivers up to 500 mA.
- Once a computer changes into power-saving mode then some types of USBs convert automatically into sleep mode.
- A USB includes two wires; one wire is used for power & another is used for carrying the data.
- At 5V, the computer can provide power up to 500mA on the power wires.
- Low-power-based devices can draw their power from the USB directly.
- Two-way communication is possible by using a USB in between the computer & peripheral devices.
Signaling rate (transmission rate)
![[Pasted image 20240723220014.png]]
### USB Standards and Specifications

The **specifications of USB** will change based on USB standards that include the following.

USB supports three types of speed low speed -1.5 Mbps, Full speed -12 Mbps & High speed – 480 Mbps.
#### USB 2.0 Standard

- It is a high-speed USB with 480Mbps of maximum data transfer speed. This USB supports all connectors.
- The maximum length of the cable is 5 meters.
- Its max charging power is up to 15w.
#### USB 3.2 Standard

- USB 3.2 (Generation1) is a super speed USB with 5Gbps of maximum data transfer speed.
- It supports different connectors like USB 3 USB-A, USB 3 USB-B & USB-C.
- The maximum length of cable for this USB is 3 meters.
- Its max charging power is up to 15w.
#### USB 3.2 (Generation2)

- USB 3.2 (Generation2) is also a super speed USB with 10Gbps of maximum data transfer speed.
- The maximum length of cable for this USB is 1meter.
- It also supports different connectors like USB 3 USB-A, USB 3 USB-B & USB-C.
- Its max charging power is up to 100w.
#### USB 3.2 Generation 2×2

- USB 3.2 Generation 2×2 is a super speed USB with 20Gbps of maximum data transfer speed.
- The maximum length of cable for this USB is 1meter.
- It also supports USB Connector.
- Its max charging power is up to 100w.
#### Thunderbolt 3 Standard

- This USB is also called thunderbolt including up to 40Gbps of maximum data transfer speed.
- The maximum length of cable for this USB is 2 meters for active and 0.8meters for passive cables.
- It supports USB Connector.
- Its max charging power is up to 100w.
#### USB 4 Standard

- This USB is also known as Thunderbolt 4 with up to 40Gbps of maximum data transfer speed.
- The maximum length of cable for this USB is 2m for active & 0.8m for passive cables.
- It supports USB Connector.
- Its max charging power is up to 100w.


### USB Data Format ###
In USB protocol, master devices are known as USB hosts which start all the communication that happens above the USB bus.
It is very essential for host devices to communicate effectively with each other. Once the peripheral device is connected to the computer through USB, then the computer will notice what type of device it is & load a driver automatically that permits the device to function.

The small amount of data transmitted between the two devices is called as ‘packets’

![[Pasted image 20240628145529.png|600]]
In USB (Universal Serial Bus) communication, synchronization between the transmitter and receiver is crucial to ensure accurate data transmission. This is achieved using a SYNC field at the beginning of every USB packet. Let's break down the details for different USB speeds:

### SYNC Field in USB Packets

1. **Purpose of the SYNC Field**:
    - The SYNC field is used to synchronize the clock (CLK) of the transmitter and receiver, allowing them to properly align for data transmission.
    - It helps the receiver detect the start of a new packet and prepare for the subsequent data.

2. **Structure of the SYNC Field**:

    **Low-Speed (LS) and Full-Speed (FS) USB**:
    - The SYNC field is 8 bits long.
    - It consists of a sequence of 3 KJ pairs followed by 2 K’s.
        - KJ pairs: A pair of bits where 'K' represents one logical state and 'J' represents the opposite logical state (e.g., '01' or '10' depending on the encoding scheme used).
        - The sequence: 3 KJ pairs (6 bits) + 2 K’s (2 bits) = 8 bits.
    - This sequence allows the receiver to lock onto the incoming signal's timing.

    **Hi-Speed (HS) USB**:
    - The SYNC field is 32 bits long.
    - It consists of a sequence of 15 KJ pairs followed by 2 K’s.
        - The sequence: 15 KJ pairs (30 bits) + 2 K’s (2 bits) = 32 bits.
    - The longer sequence at high speed is necessary due to the increased data rate, requiring more precise synchronization.
### Detailed Example:

**Low-Speed and Full-Speed USB**:
- **SYNC Field (8 bits)**: KJ KJ KJ KK
    - KJ pairs provide the clock synchronization.
    - The 2 K’s at the end mark the transition to the PID field.

**Hi-Speed USB**:
- **SYNC Field (32 bits)**: KJ KJ KJ KJ KJ KJ KJ KJ KJ KJ KJ KJ KJ KJ KJ KK
    - 15 KJ pairs for high precision synchronization.
    - The 2 K’s at the end mark the transition to the PID field.


**Packet Identifier Field or PID**
The packer identifier field within the USB protocol is mainly used to recognize the packet type that is being transmitted and thus the packet data format. The length of this field is 8 bits long where the upper 4- bits recognize the kind of packet & lower 4- bits are the bit-wise complement of the upper 4- bits.

**Address Field**
The address field of the USB protocol indicates which packet device is mainly designated for. The 7-bits length simply allows support of 127 devices. The address zero is invalid because any device which is not yet allocated an address should be reacted to transmitted packets to the zero address.

**Endpoint Field**
In the USB protocol, each device can have multiple "endpoints" for sending or receiving data, and these endpoints are identified by a 4-bit number, allowing for up to 16 different endpoints per device. Endpoint 0 is special and is called the "control endpoint," which every USB device must have. This endpoint is used for setting up the device and configuring it. The other endpoints can handle different types of data transfers: Control for setup commands, Isochronous for continuous data streams like audio, Bulk for large files, and Interrupt for small, urgent data like keyboard inputs. This system allows USB devices to efficiently manage various types of data transfers.

 - **Endpoint 0 (Control Endpoint):** When you first plug in a USB flash drive, the computer uses the control endpoint to identify the device and configure it. This process involves sending setup commands to the flash drive and receiving responses to ensure the device is recognized and ready to use.
- **Bulk Transfer Endpoints:** Once the flash drive is configured, it typically uses bulk transfer endpoints for data transfer. When you copy a file from your computer to the flash drive, the data is sent through a bulk OUT endpoint (from the host to the device). Similarly, when you copy a file from the flash drive to your computer, the data is sent through a bulk IN endpoint (from the device to the host).

**Data Field**
The length of the data field is not fixed, so it ranges from 0 to 8192 bits long & always an integral the number of bytes.

**CRC Field**
The Cyclic Redundancy Checks (CRC) are executed on the data in the packet payload where all the token packets include 5-bit CRC & the data packets include a 16-bit CRC. The CRC-5 is five bits long & used by the token packet as well as the start of the frame packet.

**EOP Field**
Every packet is terminated by an EOP (End of the Packet) field which includes an SE0 or single-ended zero for 2-bit times followed through the J for 1-bit time.

## USB in STM: ##
In the context of STM32 microcontrollers, when referring to the "class" of USB FS IP (Full-Speed USB Integrated Peripheral), it is about the specific category of USB device functionality that the microcontroller can implement. USB classes define standard protocols and functionalities that allow different types of USB devices to communicate with hosts (like PCs, laptops, or other controllers) in a standardized manner.

1. **CDC (Communications Device Class)**:
   - **Use**: Provides serial communication interfaces, commonly used for virtual COM ports (like USB to UART bridges).
   - **Example**: USB serial converters.

2. **HID (Human Interface Device)**:
   - **Use**: For devices that interact with humans directly, like keyboards, mice, and game controllers.
   - **Example**: USB keyboards, mice, gamepads.

3. **MSC (Mass Storage Class)**:
   - **Use**: For devices that act as storage media, allowing file transfer and storage operations.
   - **Example**: USB flash drives, external hard drives.

4. **Audio Class**:
   - **Use**: For audio devices, handling audio streaming and control.
   - **Example**: USB microphones, speakers, audio interfaces.

5. **MIDI (Musical Instrument Digital Interface)**:
   - **Use**: For musical instruments and related equipment.
   - **Example**: MIDI keyboards, synthesizers.

6. **DFU (Device Firmware Upgrade)**:
   - **Use**: For updating the firmware of a device via USB.
   - **Example**: Devices that allow firmware updates over USB.

7. **RNDIS (Remote Network Driver Interface Specification)**:
   - **Use**: For networking over USB, enabling the device to appear as a network interface.
   - **Example**: USB network adapters.

In STM32 microcontrollers, these classes are supported through the USB Device Library provided by STMicroelectronics, which includes middleware and example projects to help developers implement USB functionalities.

### Virtual COM Ports: ###
A virtual COM port (VCP) is a software-based emulation of a physical serial port, often provided through USB. It allows USB devices to appear and function as if they were connected to a traditional COM (serial) port on a computer, enabling serial communication over USB. This is particularly useful for devices that traditionally use RS-232 or other serial communication protocols but now use USB for connectivity.

### How Virtual COM Ports Work

1. **USB to Serial Bridge**: The device uses a USB to serial converter chip (such as FTDI, CP210x, or an embedded microcontroller with USB support like STM32) to emulate a serial port over USB.
2. **Driver Installation**: When the device is connected to a computer, a driver is installed that creates a virtual COM port. This driver allows software applications to communicate with the USB device as if it were a traditional serial device.
3. **Communication**: Data sent from the computer to the virtual COM port is transmitted to the USB device, which interprets it as serial data. Conversely, data sent from the device is received by the virtual COM port driver and made available to the computer as if it were coming from a serial port.

## TTL AND USB: ##
Most laptops and desktops no longer have serial ports, but many development boards require a serial port for debugging, console interface, or even software download. The serial ports on development boards usually provide “logic level” signals rather than RS-232 serial port signals.

This means that there’s no easy way to connect a development board to a laptop. The USB to TTL converter solves this problem by providing a serial port connection between a host computer and a development board, with the correct interfaces and signal levels for each. Details below.

What is a TTL signal in communication?

A TTL Signal is a kind of hardware interface standard based on the electrical properties of TTL (Transistor-Transistor Logic).

For a TTL input this means that anything below 0.8 volts is a “zero” and anything above 2.4 volts is a “one,” and that it presents a load of less than 1.6ma to the driving circuit.

A TTL output can typically drive ten TTL inputs, and still maintain the correct voltage levels for “zero” and “one.”