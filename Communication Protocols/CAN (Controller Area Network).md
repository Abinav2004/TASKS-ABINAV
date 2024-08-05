The Controller Area Network protocol (CAN or CAN Bus) is a two-wire (twisted-pair), bidirectional serial bus communication method that allows electronic subsystems to be linked together and interact in a network. It is a message based protocol rather than an address based one which makes it so special. The feature that makes the CAN protocol unique among other communication protocols is the broadcast type of bus. Here, broadcast means that the information is transmitted to all the nodes.

It is a half duplex communication, only one device could use the bus and send data at a time. once the transfer is complete, the other device could respond and send its data. 

The CAN Bus protocol can be summarized in the following manner:

- The physical layer uses differential transmission on a twisted pair wire
- A non-destructive bit-wise arbitration is used to control access to the bus
- The messages are small (at most eight data bytes) and are protected by a checksum
- There is no explicit address in the messages; instead, each message carries a numeric value which controls its priority on the bus and may also serve as an identification of the contents of the message
- An elaborate error handling scheme that results in retransmitted messages when they are not properly received
- There are effective means for isolating faults and removing faulty nodes from the bus

CAN Bus has a multi-master capability meaning any node on the bus can initiate communication to any other node in a network.

All nodes on the CAN network must operate at the same nominal bit rate otherwise errors will occur on receiving side. CAN communication is asynchronous so it depends on the baud rate, so all devices must agree on the baud rate 

CAN specifications are international standards. Two versions are now in use: _==CAN 2.0A==, the low-speed version, sometimes known as Basic or Standard CAN_, is defined by the ISO11519 standard; _==CAN 2.0B==, the high-speed version, also known as Full CAN or extended-frame CAN, is defined by the ISO11898 standard_

### CAN LAYERED ARCHITECTURE ###
the [[OSI model]]partitions the communication system into 7 different layers. But the CAN layered architecture consists of two layers, i.e., data-link layer and physical layer.
![[Pasted image 20240626120013.png|500]]
- **Data-link layer**: This layer is responsible for node to node data transfer. It allows you to establish and terminate the connection. It is also responsible for detecting and correcting the errors that may occur at the physical layer. Data-link layer is subdivided into two sub-layers:
    1. **MAC:** MAC stands for Media Access Control. It defines how devices in a network gain access to the medium. It provides Encapsulation(adding additional data during transmission) and Decapsulation of data(removing additional data after transmission) , Error detection, and signaling.
    2. **LLC:** LLC stands for Logical link control. It is responsible for frame acceptance filtering, overload notification, and recovery management.
- **Physical layer**: The physical layer is responsible for the transmission of raw data. It defines the specifications for the parameters such as voltage level, timing, data rates, and connector.

### CAN FRAMING ###
![[Pasted image 20240626121316.png]]
- **SOF:** SOF stands for the start of frame, which indicates that the new frame is entered in a network. It is of 1 bit.
- **Identifier:** A standard data format defined under the CAN 2.0 A specification uses an 11-bit message identifier for arbitration. Basically, this message identifier sets the priority of the data frame. lower the message identifier higher the priority.
- **RTR:** RTR stands for Remote Transmission Request, which defines the frame type, whether it is a data frame or a remote frame. It is of 1-bit.
- **RTR = 0:** This value indicates that the frame is a data frame. The Data Field will contain the actual data payload (up to 8 bytes).
- **RTR = 1:** This value indicates that the frame is a remote frame. The Data Field is empty because it is a request for data.
- **Control field:** It has user-defined functions.
    1. **IDE:** An IDE bit in a control field stands for identifier extension. A dominant(logic 0) IDE bit defines the 11-bit standard identifier, whereas recessive(logic 1) IDE bit defines the 29-bit extended identifier.
    2. **DLC:** DLC stands for Data Length Code, which defines the data length in a data field. It is of 4 bits . Indicates the number of bytes in the Data Field (0-8) or Indicates the number of bytes expected in the response data frame(RTR=1)
    3. **Data field:** The data field can contain up to 8 bytes.
- **CRC field:** The data frame also contains a cyclic redundancy check field of 15 bit, which is used to detect the corruption if it occurs during the transmission time. The sender will compute the CRC(value based on the contents of the CAN frame) before sending the data frame, and the receiver also computes the CRC and then compares the computed CRC with the CRC received from the sender. If the CRC does not match, then the receiver will generate the error.
- **ACK field:** This is the receiver's acknowledgment. In other protocols, a separate packet for an acknowledgment is sent after receiving all the packets, but in case of CAN protocol, no separate packet is sent for an acknowledgment.
- **EOF:** EOF stands for end of frame. It contains 7 consecutive recessive bits(logic 1) known End of frame.

 here is the exact range of the CAN data frame lengths:
- **Standard Frame (CAN 2.0A):** 44 to 108 bits
- **Extended Frame (CAN 2.0B):** 64 to 128 bits
### CAN TRANSMISSION ###

![[Pasted image 20240626124758.png|500]]
- Host  
    A host is a microcontroller or microprocessor which is running some application to do a specific job. A host decides what the received message means and what message it should send next.
- CAN Controller  
    CAN controller deals with the communication functions described by the CAN protocol. It also triggers the transmission, or the reception of the CAN messages.
- CAN Transceiver  
    CAN transceiver is responsible for the transmission or the reception of the data on the CAN bus. It converts the data signal into the stream of data collected from the CAN bus that the CAN controller can understand.
CAN bus consists of two lines, i.e., CAN low line and CAN high line, which are also known as CANH and CANL, respectively. The transmission occurs due to the differential voltage applied to these lines. The CAN uses twisted pair cable and differential voltage because of its environment.
Differential voltage is the voltage difference between two points, often labeled as V+ (positive voltage) and V- (negative voltage).
- Involves transmitting signals over two wires, where one wire carries the signal and the other carries its inverse.
- The receiver interprets the signal by measuring the voltage difference between the two wires.
- Differential signaling helps to cancel out ==electromagnetic interference (EMI) and noise==, as any noise that affects both wires equally is eliminated when taking the difference.
- Differential systems reject common-mode signals (noise that is present on both wires), enhancing the reliability of the signal transmission.
![[Pasted image 20240626125640.png|500]]

 In CAN terminology, logic 1 is said to be recessive while logic 0 is dominant. When CAN high line and CAN low line are applied with 2.5 volts, then the actual differential voltage would be zero volt. ==A zero volt on CAN bus is read by the CAN transceiver as a recessive or logic 1==. A zero volt on CAN bus is an ideal state of the bus. When CAN high line is pulled up to 3.5 volt(3.75 more precise) and the CAN low line is pulled down to 1.5(1.75 more precise) volt, then the bus's actual differential voltage would be 2 volts. It is treated as a dominant bit or logic 0 by the CAN transceiver. ==If the bus state is reached to dominant or logic 0 then it would become impossible to move to the recessive state by any other node.==
 If the CANH-CANL voltage is greater than 1.5 V, a CAN receiver identifies that bit as Logic 0. Whereas, if the CANH-CANL voltage is less than 200 mV, a CAN receiver identifies that bit as Logic
 
 ### Example
Consider three nodes, A, B, and C, trying to transmit messages with identifiers 0x100, 0x101, and 0x102, respectively:
1. **All nodes start transmitting:**
    - Node A sends a bit 0 (dominant) as the first bit of its identifier.
    - Node B and Node C also send their first bits, which are 0 (dominant).
2. **Bus remains in dominant state:**
    - As all nodes sent a dominant bit, the bus state is dominant.
3. **Next bits:**
    - Node A sends the next bit, which might be 0 (dominant) or 1 (recessive).
    - Node B and C continue sending their bits.
4. **Arbitration:**
    - If Node A sends a recessive bit and Node B or C sends a dominant bit, Node A will lose arbitration and stop transmitting.
5. **Final outcome:**
    - The node with the lowest identifier (highest priority) will continue transmitting, and other nodes will wait for the bus to be free.

 the dominant state (logic 0) in CAN ensures that the highest priority message wins arbitration and prevents lower priority messages from disrupting the transmission, thereby maintaining reliable and orderly communication on the CAN bus.
![[Pasted image 20240626130307.png|500]]

**NOTE:**
![[Pasted image 20240626131034.png]]

Version 1.0 and 1.2 defined CAN with an 11-bit message identification giving a possible 2048 message identifiers. Version 2.0 has allowed an 18-bit message ID extension allowing for an effective 29-bit message ID.
## CAN 2.0 ##
The latest is CAN 2.0, published in 1991. This specification has two parts. Part A is for the standard format with an 11-bit identifier, and part B is for the extended format with a 29-bit identifier. A ==CAN device that uses 11-bit identifiers is commonly called CAN 2.0A, and a CAN device that uses 29-bit identifiers is commonly called CAN 2.0-B==

When a CAN device transmits data onto the network, an identifier that is unique throughout the network precedes the data. The identifier defines not only the content of the data, but also the priority.
When a device transmits a message onto the CAN network, all other devices on the network receive that message. Each receiving device performs an acceptance test on the identifier to determine if the message is relevant to it. If the received identifier is not relevant to the device (such as RPM received by an air conditioning controller), the device ignores the message.
When more than one CAN device transmits a message simultaneously, the identifier is used as a priority to determine which device gains access to the network. The lower the numerical value of the identifier, the higher its priority.

_**NOTE**_: CAN arbitration happens Electrically in the sense once it is dominant it wins the arbitration and rest all lose, in the bus
The arbitration process in a CAN network primarily takes place on the bus, with the cooperation of the transceivers and CAN controllers in each node.
Every node on the network reads the identifier of a message, and each node independently determines if the message is to be ignored or processed. Since the identifier is specific to the contents of the message rather than the identity of the originating node, new nodes may be added to the network, even while the network is functioning, without modifying the program of any existing node on the network.

## CAN Transceivers ##
For a CAN transceiver, it's not required to provide exact voltages for the CANH (CAN High) and CANL (CAN Low) pins. The transceiver is designed to work with a range of voltages that represent the CAN bus differential signaling.

Here are the typical voltage levels for the MCP2551:

- **Dominant State (Logical 0):**
  - CANH: Typically around 3.5V to 4.5V
  - CANL: Typically around 0.5V to 1.5V
- **Recessive State (Logical 1):**
  - CANH: Typically around 2.0V to 2.5V
  - CANL: Typically around 2.0V to 2.5V

The differential voltage between CANH and CANL determines the state of the CAN bus:

- **Dominant State:** CANH - CANL > 0.9V
- **Recessive State:** CANH - CANL ≈ 0V

The MCP2551 transceiver interprets these voltage levels to communicate data over the CAN bus. Therefore, as long as the voltage levels fall within the acceptable range for dominant and recessive states, the exact voltages are not critical. The transceiver ensures proper communication by converting the differential signals to logic levels that the microcontroller can process.

The role of the transceiver is simply to drive and detect data to and from the bus. It converts the single-ended logic used by the controller to the differential signal transmitted over the bus. It also determines the bus logic state from the differential voltage, rejects the common-mode noise, and outputs a single-ended logic signal to the controller

The CAN controller handles the data link layer of CAN communication, whereas the CAN transceiver handles the physical layer.

VREF pin in 2551 IC-VREF helps in stabilizing these variations, ensuring that the differential signal is accurately interpreted by the CAN transceiver and the microcontroller.
By connecting a capacitor between VREF and ground, high-frequency noise can be filtered out. This ensures a cleaner and more stable reference voltage, which in turn helps in reducing the noise on the CAN bus.
## CAN Controller Components:##

### Receive Buffers: ###
  - The CAN controller has two receive buffers to temporarily hold incoming messages.
  - These buffers help manage the flow of messages and ensure that high-priority messages are handled first.
  - **Prioritized Message Storage:**
    - Messages are stored based on priority. In CAN, messages with lower identifier values have higher priority.
### Filters ##
- Filters are used to determine which messages are accepted by the CAN controller based on their identifiers.
- Filters match the message identifiers against predefined patterns to decide if a message should be accepted or ignored.
- Each message on the CAN bus has an identifier (11-bit for standard frames, 29-bit for extended frames).
- Filters compare these identifiers to predefined values set in the filters.
- The CAN controller mentioned has six 29-bit filters, meaning it can filter based on six different identifier patterns.
## Masks: ##
- When a message is received, the CAN controller extracts the message identifier.
- A mask is applied to both the incoming message identifier and the filter identifier.
- The masked incoming identifier is compared to the masked filter identifier.
- If they match, the message is accepted.
- If they do not match, the message is ignored.
- Suppose a filter is set to match identifier `0x12345678` with a mask of `0x1FFFFFFF`.
- The mask `0x1FFFFFFF` means all bits are considered for comparison.

### Purpose of Termination Resistors:(120 ohm)###

1. **Prevent Signal Reflections:**
    - In a CAN bus, electrical signals are transmitted along the communication lines. If the signals encounter an impedance mismatch or an open circuit at the ends of the bus, they can reflect back into the cable. These reflections can interfere with the original signals, leading to noise and potential data errors.
2. **Match Impedance:**
    - The termination resistors are used to match the impedance of the cable to the characteristic impedance of the bus (typically 120 ohms for CAN networks). By matching the impedance, the resistors help to absorb the signals at the end of the bus, preventing them from reflecting back.
The characteristic impedance of a transmission line is a measure of the impedance that the line presents to a signal traveling along it. It is determined by the physical properties of the cable, such as its inductance and capacitance per unit length.

To ensure minimal signal reflection and maximum power transfer, the termination impedance should match the characteristic impedance of the bus. For a CAN bus with a characteristic impedance of 120 ohms, the termination resistors are therefore chosen to be 120 ohms each.