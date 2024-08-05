The most popular and oldest LAN technology is Ethernet Protocol, so it is more frequently used in LAN environments which is used in almost all networks like offices, homes, public places, enterprises, and universities. Ethernet has gained huge popularity because of its maximum rates over longer distances using optical media.

The Ethernet protocol uses a star topology or linear bus. The main reason to use Ethernet widely is, simple to understand, maintain, implement, provides flexibility, and permits less cost network implementation.

### Ethernet Protocol Architecture ###
 Ethernet protocol operates at the first two layers like the Physical & the Data Link layers but, Ethernet separates the Data Link layer into two different layers called the Logical Link Control layer & the Medium Access Control layer.
 The physical layer in the network mainly focuses on the elements of hardware like repeaters, cables For instance, an Ethernet network like 100BaseTX or 10BaseT indicates the cables type that can be used, the length of cables, and the optimal topology.

![[Pasted image 20240628091628.png]]

The data link layer in the network system mainly addresses the way that data packets are transmitted from one type of node to another. Ethernet uses an access method called CSMA/CD (Carrier Sense Multiple Access/Collision Detection). This is a system where every computer listens to the cable before transmitting anything throughout the network.

_The most popular set of protocols used for both the Physical & Data Link layers is known as Ethernet_

The Ethernet protocol’s actual transmission speed can be measured in Mbps (millions of bits for each second), The speed versions of Ethernet are available in three different types 10 Mbps, called Standard Ethernet; 100 Mbps called Fast Ethernet & 1,000 Mbps, called as Gigabit Ethernet. The output of the Ethernet network rarely achieves this highest speed.

The various versions of ethernet protocol  can mix & match on a similar network with the help of different network devices bridges to connect the segments of the network that utilize different types of media.

The sub-layers of Data Link give significantly to technological compatibility & computer communications. The ==MAC sublayer== is concerned through the physical components that will be utilized to converse the information & arrange the data for communication over the media. The ==Logical Link Control sublayer== will stay independent of the physical equipment that will be utilized for the process of communication.

the LLC acts as an intermediary, managing the flow of data between the higher layers (network protocols) and the lower layers (hardware and physical media). It ensures that data is properly formatted, transmitted, and received, coordinating with the MAC sublayer and the physical network medium. The NIC driver software facilitates this communication by directly interfacing with the NIC hardware, enabling the LLC to perform its functions effectively.the logical link control can be considered the driver software of the NIC.

#### **MAC ADDRESS:**
A MAC address (media access control address) is a 12-digit hexadecimal number assigned to each device connected to the network. Primarily specified as a unique identifier during device manufacturing, the MAC address is often found on a device's network interface card (NIC). A MAC address is required when trying to locate a device or when performing diagnostics on a network device
_**The MAC address designates the physical location of a device within a local network, whereas the IP address signifies the device's global or internet-accessible identity**. The manufacturer of the NIC card provides the MAC Address, whereas the Internet Service Provider supplies the IP Address_
### Ethernet Protocol Frame Structure ###
![[Pasted image 20240628093753.png|500]]

**Preamble:**
Preamble specifies the receiver that frame is coming & lets the receiver lock on the data stream before the genuine frame starts.

**Start of Frame Delimiter:**
The start of the frame delimiter is mainly designed to split the pattern of the bit to the preamble & signal the beginning of the frame.
Sometimes, the start of frame delimiter is considered as the main part of the preamble, so this is the main reason that Preamble is expressed as 8 Bytes in several places. The SFD gives a warning to stations that this is the final opportunity for synchronization.

**Destination Address:**
The Destination Address Field is a 6-bytes field in the above Ethernet frame. The address within the frame & the device MAC address is compared. If both the addresses are matched, then the device simply allows the frame. This MAC address is a uni-cast, multi-cast, or broadcast.
- **Unicast**: One-to-one communication (unique MAC address).
- **Multicast**: One-to-many communication (multicast MAC address within a specific range).
- **Broadcast**: One-to-all communication (special broadcast MAC address).

**Source Address:**
The source address is a 6-Byte field, including the source machine’s MAC address. Once the address of source is an individual address or Unicast always

**Length:**
This field size is 2-byte long that specifies the entire Ethernet frame length. The length value held by the 16-bit field ranges from 0 to 65534, however, the length cannot be higher than 1500 due to some own Ethernet limitations.

**Data Field:**
Data field is the location where actual data can be added and it is also called Payload. Here, both the data & IP header will be inserted if IP is used over Ethernet. So, the highest data available may be 1500 Bytes. If the data length is below the minimum length of 46 bytes, then padding zeros can be included to reach the minimum achievable length.

**CRC:**
The CRC in the frame is the last pattern with 4 Bytes. This field includes 32-bits of data hash code, which is produced over the Source Address, Destination Address, Length, and Ethernet Protocol’s Data field. If the checksum is calculated through a destination that is not similar to the sent checksum value, then received data can be corrupted.

![[Pasted image 20240628095005.png|600]]

#### Ethernet Protocol Analyzer ####
This protocol analyzer is a software tool mainly used for capturing & analyzing the traffic of data within a network. These analyzers can also build the graphic map of the network and generates alarms once the number of packets increases at a specified level otherwise once it detects particular types of packets within the network.

Ethernet protocols are widely used in embedded systems due to their robustness and scalability. However, like any technology, they have their advantages and disadvantages. Here’s a detailed look at both:

### Advantages of Ethernet Protocols in Embedded Systems

1. **Standardization and Interoperability**:
   - Ethernet is a well-established standard, ensuring compatibility across a wide range of devices and systems from different manufacturers.
2. **High Data Rates**:
   - Ethernet supports high data transfer rates (10 Mbps, 100 Mbps, 1 Gbps, and higher), which can be beneficial for applications requiring fast data communication.
3. **Scalability**:
   - Ethernet networks can easily scale from small local networks to large industrial systems with thousands of nodes.
4. **Reliability and Robustness**:
   - Ethernet protocols include error detection and correction mechanisms, providing reliable communication in noisy environments.
5. **Widespread Availability**:
   - Ethernet hardware, such as NICs, switches, and cables, is widely available and relatively inexpensive.
6. **Ease of Integration**:
   - Many microcontrollers and microprocessors used in embedded systems have built-in Ethernet controllers, simplifying hardware integration.
7. **Versatile Application**:
   - Suitable for a wide range of applications, including industrial automation, home automation, medical devices, and more.

### Disadvantages of Ethernet Protocols in Embedded Systems

1. **Power Consumption**:
   - Ethernet controllers and transceivers can consume significant power, which might be a concern in low-power embedded applications.
2. **Complexity**:
   - Implementing Ethernet protocols can be complex, requiring a significant amount of software and hardware resources. This can increase development time and costs.
3. **Real-Time Performance**:
   - Standard Ethernet is not deterministic, meaning there can be variability in message delivery times. This can be a disadvantage for real-time embedded systems that require precise timing.
4. **Size and Cost**:
   - Ethernet hardware can be bulkier and more expensive compared to simpler communication interfaces like SPI or I2C, which might not be ideal for cost-sensitive or space-constrained applications.
5. **Network Configuration**:
   - Setting up and managing an Ethernet network can be more complex compared to simpler point-to-point communication interfaces.
6. **Security Concerns**:
   - Ethernet networks are susceptible to various security threats (e.g., unauthorized access, data interception). Implementing robust security measures can add to the complexity and cost.

### Use Cases
- **Suitable Applications**:
  - Applications requiring high data rates and bandwidth.
  - Systems needing standardization and interoperability with other network devices.
  - Industrial automation systems where Ethernet-based protocols like EtherCAT or Profinet are used.

- **Less Suitable Applications**:
  - Low-power, battery-operated devices where power consumption is a critical factor.
  - Simple, cost-sensitive applications where a simpler communication interface would suffice.
  - Real-time systems requiring deterministic behavior without additional protocols like Time-Sensitive Networking (TSN).

## EXAMPLE ##

## USING ETHERNET ##
### Components Needed:

- **Temperature Sensor with Ethernet Capability** (e.g., a sensor module with a built-in Ethernet interface)
- **Microcontroller with Ethernet Support** (e.g., ESP32, Raspberry Pi, or any microcontroller with an Ethernet shield/module)
- **Ethernet Switch**
- **Ethernet Cables**
- **MQTT Broker** (e.g., Mosquitto, hosted locally or on a cloud service)

### Setup and Configuration:

#### 1. **Physical Connections:**

- **Connect the Temperature Sensor to the Ethernet Switch:**
    - Use an Ethernet cable to connect the temperature sensor to one of the ports on the Ethernet switch.
- **Connect the Microcontroller to the Ethernet Switch:**
    - Use another Ethernet cable to connect the microcontroller to another port on the Ethernet switch.

#### 2. **IP Address Assignment:**
- **Static IP Addresses:**
    - Assign a static IP address to the temperature sensor (e.g., 192.168.1.100).
    - Assign a static IP address to the microcontroller (e.g., 192.168.1.101).
- **DHCP (Optional):**
    - Alternatively, you can use DHCP to dynamically assign IP addresses if your network has a DHCP server.
#### 3. **MQTT Setup:**

- **Install MQTT Broker:**
    - If using Mosquitto, install and configure it on a local server or use a cloud-based MQTT broker service.
    - Ensure the MQTT broker is reachable from both the temperature sensor and the microcontroller.
- **MQTT Broker Configuration:**
    - Configure the broker to allow connections from the sensor and the microcontroller.
    - Note the broker’s IP address and port (typically 1883 for non-secure connections).
#### 4. **Temperature Sensor Configuration:**

- **Sensor Network Settings:**
    - Configure the sensor with the static IP address or set it to obtain an IP address via DHCP.
    - Set the MQTT broker details (IP address, port) in the sensor’s configuration.
- **MQTT Topic:**
    - Configure the sensor to publish temperature data to a specific MQTT topic (e.g., `sensors/temperature`).

#### 5. **Microcontroller Configuration:**
- **Microcontroller Network Settings:**
    - Configure the microcontroller with its static IP address or set it to obtain an IP address via DHCP.
    - Install an MQTT client library suitable for your microcontroller (e.g., `PubSubClient` for Arduino or `paho-mqtt` for Python).
- **MQTT Client Setup:**
    - Initialize the MQTT client in the microcontroller’s code.
    - Set the MQTT broker’s IP address and port.
    - Subscribe to the topic published by the sensor (e.g., `sensors/temperature`).


## Using SPI (Serial Peripheral Interface)##

#### Components

- Temperature Sensor with SPI capability
- Central Controller with SPI interface
- SPI Cables
#### Setup and Configuration

1. **Physical Connections**:
    - Connect the temperature sensor to the central controller using SPI cables.
    - Example connections:
        - MISO (Master In Slave Out)
        - MOSI (Master Out Slave In)
        - SCLK (Serial Clock)
        - SS (Slave Select)
2. **SPI Configuration**:
    - Configure the SPI settings on the central controller:
        - Clock speed (e.g., 1 MHz)
        - Clock polarity (CPOL)
        - Clock phase (CPHA)
3. **Data Communication**:
    - Implement a communication protocol where the central controller periodically sends a read command to the temperature sensor and receives the temperature data.
    - Example: The controller sends a command byte to request temperature data, and the sensor responds with the data.
4. **Testing and Troubleshooting**:
    - Test the communication by reading the temperature data on the central controller.
    - Use an oscilloscope to monitor SPI signals for troubleshooting.