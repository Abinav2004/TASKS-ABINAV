- OSI stands for **Open System Interconnection** is a reference model that describes how information from a software in one computer through a physical medium to the software application in another computer.
- OSI consists of seven layers, and each layer performs a particular network function.
- OSI model divides the whole task into seven smaller and manageable tasks. Each layer is assigned a particular task.
- Each layer is self-contained, so that task assigned to each layer can be performed independently.
- ![[Pasted image 20240626104849.png|600]]
![[Pasted image 20240626104951.png]]

#### PHYSICAL LAYER: ####
![[Pasted image 20240626105402.png|500]]
- The main functionality of the physical layer is to transmit the individual bits from one node to another node.
- It establishes, maintains and deactivates the physical connection.
- It defines the way how two or more devices can be connected physically.
- It defines the transmission mode whether it is simplex, half-duplex or full-duplex mode between the two devices on the network.
- It defines the way how network devices are arranged.
- It determines the type of the signal used for transmitting the information.
#### DATA LINK LAYER ####
![[Pasted image 20240626105730.png|500]]
- This layer is responsible for the error-free transfer of data frames.
- It defines the format of the data on the network.
- It is mainly responsible for the unique identification of each device that resides on a local network.
- It contains two sub-layers:
    - **Logical Link Control Layer**
        - It is responsible for transferring the packets to the Network layer of the receiver that is receiving.
        - It identifies the address of the network layer protocol from the header.
        - It also provides flow control.
    - **Media Access Control Layer**
        - A Media access control layer is a link between the Logical Link Control layer and the network's physical layer.
        - It is used for transferring the packets over the network.
- Functions:
	 - **Framing:** The data link layer translates the physical's raw bit stream into packets known as Frames. The Data link layer adds the header and trailer to the frame. The header which is added to the frame contains the hardware destination and source address.
	 
	 - **Physical Addressing:** The Data link layer adds a header to the frame that contains a destination address. The frame is transmitted to the destination address mentioned in the header.
	
	- **Flow Control:** Flow control is the main functionality of the Data-link layer. It is the technique through which the constant data rate is maintained on both the sides so that no data get corrupted. It ensures that the transmitting station such as a server with higher processing speed does not exceed the receiving station, with lower processing speed.
	
	- **Error Control:** Error control is achieved by adding a calculated value CRC (Cyclic Redundancy Check) that is placed to the Data link layer's trailer which is added to the message frame before it is sent to the physical layer. If any error seems to occur, then the receiver sends the acknowledgment for the retransmission of the corrupted frames.
	
	- **Access Control:** When two or more devices are connected to the same communication channel, then the data link layer protocols are used to determine which device has control over the link at a given time.

#### NETWORK LAYER ####
![[Pasted image 20240626111653.png|500]]
- It determines the best path to move data from source to the destination based on the network conditions, the priority of service, and other factors.
- An internetworking is the main responsibility of the network layer. It provides a logical connection between different devices.
- A Network layer adds the source and destination address to the header of the frame. Addressing is used to identify the device on the internet.
- Routing is the major component of the network layer, and it determines the best optimal path out of the multiple paths from source to the destination.
- A Network Layer receives the packets from the upper layer and converts them into packets. This process is known as Packetizing. It is achieved by internet protocol (IP).
#### TRANSPORT LAYER: ####
![[Pasted image 20240626114839.png|500]]
- The Transport layer is a Layer 4 ensures that messages are transmitted in the order in which they are sent and there is no duplication of data.
- The main responsibility of the transport layer is to transfer the data completely.
- It receives the data from the upper layer and converts them into smaller units known as segments.
- This layer can be termed as an end-to-end layer as it provides a point-to-point connection between source and destination to deliver the data reliably.
- Functions:
  - Computers run several programs simultaneously due to this reason, the transmission of data from source to the destination not only from one computer to another computer but also from one process to another process. The transport layer adds the header that contains the address known as a service-point address or port address. The responsibility of the network layer is to transmit the data from one computer to another computer and the responsibility of the transport layer is to transmit the message to the correct process.
  - When the transport layer receives the message from the upper layer, it divides the message into multiple segments, and each segment is assigned with a sequence number that uniquely identifies each segment. When the message has arrived at the destination, then the transport layer reassembles the message based on their sequence numbers.

#### SESSION LAYER ####
![[Pasted image 20240626115308.png|500]]
- The Session layer is used to establish, maintain and synchronizes the interaction between communicating devices.
-  Session layer acts as a dialog controller that creates a dialog between two processes or we can say that it allows the communication between two processes which can be either half-duplex or full-duplex.
-  Session layer adds some checkpoints when transmitting the data in a sequence. If some error occurs in the middle of the transmission of data, then the transmission will take place again from the checkpoint. This process is known as Synchronization and recovery.

#### PRESENTATION LAYER ####
![[Pasted image 20240626115546.png|500]]
- A Presentation layer is mainly concerned with the syntax and semantics of the information exchanged between the two systems.
-  This layer is a part of the operating system that converts the data from one presentation format to another format.
- The processes in two systems exchange the information in the form of character strings, numbers and so on. Different computers use different encoding methods, the presentation layer handles the interoperability between the different encoding methods. It converts the data from sender-dependent format into a common format and changes the common format into receiver-dependent format at the receiving end.
- Encryption is needed to maintain privacy. Encryption is a process of converting the sender-transmitted information into another form and sends the resulting message over the network.
- Data compression is a process of compressing the data, i.e., it reduces the number of bits to be transmitted. Data compression is very important in multimedia such as text, audio, video.
#### Application Layer ####
 ![[Pasted image 20240626115821.png|500]]
  - An application layer allows a user to access the files in a remote computer, to retrieve the files from a computer and to manage the files in a remote computer.
  - An application layer serves as a window for users and application processes to access network service.
  - It handles issues such as network transparency, resource allocation, etc.
  - An application provides the distributed database sources and is used to provide that global information about various objects.
