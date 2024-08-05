
I2C protocol is combination of both UART and SPI communication protocol.
One  can connect multiple slaves and multiple master via I2C communication protocol
It is half-duplex communication so either master can send data or slave can send data at a time.

It has only two wires to transmit:
**SDA (Serial Data)** – The line for the master and slave to send and receive data.
**SCL (Serial Clock)** – The line that carries the clock signal.

**![](https://lh7-us.googleusercontent.com/docsz/AD_4nXcrSqCnCjW_d92VUhaKWJbqPbNqXgs3MWWPXoeW08Ozx4RwOywgqxOiYaSl11vDnpm0RSkcmdmFVkvtn4nf59EqBWZogA2KnaLlJZiU2YjTDu79XBlofxrGI4DgHq6TJ0O1fe3ipZ_fJuOVtXDhTTJJrL2u?key=uJeW2HMPdP7W2LlykD-pHQ)**
**
Like UART data is sent bit by bit through the SDA line. Here also the clock is controlled by the master.
Number of slaves depends on the size of I2C hardware:
For example:
7-bit I2C upto 128 devices.

### I2C data transmission: ###
With I2C, data is transferred in packets. Each packet  is broken up into frames of data. Each message has an address frame that contains the binary address of the slave, and one or more data frames that contain the data being transmitted. The message also includes start and stop conditions, read/write bits, and ACK/NACK bits between each data frame:
**![](https://lh7-us.googleusercontent.com/docsz/AD_4nXetpEtPhrU3d_7ysqzGAQYpgXmOJtLK2zt_dxBh3p2Npp76EgDS5V3SuNpL2J8U1I7c_oZns56bOlSvkuW8eJiDR5ZXvHhscACtSyuQx9kIDCIM4aDjvZJvEB1HXuHrry4TaWAoZN05hw7Q5xVssKc-MCI?key=uJeW2HMPdP7W2LlykD-pHQ)**
**
**Start Condition**: The SDA line switches from a high voltage level to a low voltage level before the SCL line switches from high to low.

**Stop Condition**: The SDA line switches from a low voltage level to a high voltage level after the SCL line switches from low to high.

**Address Frame**: A 7 or 10 bit sequence unique to each slave that identifies the slave when the master wants to talk to it.

**Read/Write Bit**: A single bit specifying whether the master is sending data to the slave (low voltage level) or requesting data from it (high voltage level).

**ACK/NACK Bit**: Each frame in a message is followed by an acknowledge/no-acknowledge bit. If an address frame or data frame was successfully received, an ACK bit is returned to the sender from the receiving device.

**ADDRESSING I2C SLAVES:**
The master sends the address of the slave it wants to communicate with to every slave connected to it. Each slave then compares the address sent from the master to its own address. If the address matches, it sends a low voltage ACK bit back to the master. If the address doesn’t match, the slave does nothing and the SDA line remains high.

**![](https://lh7-us.googleusercontent.com/docsz/AD_4nXflATvCGfQtXztgJzeLzMHcyMFpB-BxgJ2eFWRx491EVuayfmRAXcGnn5S46ajVhQD_c9u5B0LtoqRf3Cwlis0n_l8izf7bt4zHv7QV4prVShnKs5rtO2g4ES_pNSpYEAtU_4SpOrUowESer2U3DTwks6lk?key=uJeW2HMPdP7W2LlykD-pHQ)**

STEPS DURING DATA TRANSMISSION:

1. The master sends the start condition to every connected slave by switching the SDA line from a high voltage level to a low voltage level before switching the SCL line from high to low
2. The master sends each slave the 7 or 10 bit address of the slave it wants to communicate with, along with the read/write bit
3. Each slave compares the address sent from the master to its own address. If the address matches, the slave returns an ACK bit by pulling the SDA line low for one bit. If the address from the master does not match the slave’s own address, the slave leaves the SDA line high
4. The master sends or receives the data frame
5. After each data frame has been transferred, the receiving device returns another ACK bit to the sender to acknowledge successful receipt of the frame
6. To stop the data transmission, the master sends a stop condition to the slave by switching SCL high before switching SDA high.

![[Pasted image 20240626214848.png]]

### CLOCK STRETCHING IN I2C PROTOCOL ###
An I2C master controls the clock speed and provides SCL on the line. It is possible for the slave device to “stretch” or hold the clock and alt the data or commands transmission from the master. Clock stretching is mainly used to hold the master device when the slave device is swamped(**Very busy; having too much to do**.). An I2C slave device can use clock stretching to push the master device into a wait state. When a slave device requires longer time to manage data, such as store received data or prepare to transmit another byte of data, it may execute clock stretching. This usually happens after the slave device has acknowledged receiving a byte of data.

![[Pasted image 20240626215316.png|500]]

The clock stretching pauses the transaction by holding the SCL line LOW. The data transaction cannot be completed until SCL line held HIGH. Clock stretching is optional and in fact, most target devices do not include an SCL driver, so they are unable to stretch the clock.  
  
A device may be able to receive bytes of data quickly at the byte level, but it takes longer to store a received byte or prepare another byte for transmission. After receiving and acknowledging a byte, targets can keep the SCL line LOW to force the controller into a wait state until the target is ready for the next byte transfer, like a handshake operation.

Here are the lengths of I²C frames in various cases (in bits):

1. **7-bit Address, 1 Data Byte**: 20 bits
2. **7-bit Address, n Data Bytes**: \(10 + 9n\) bits

3. **10-bit Address, 1 Data Byte**: 29 bits
4. **10-bit Address, n Data Bytes**: \(19 + 9n\) bits

In I2C Protocol there are 5-speed categories including standard mode, fast mode, fast plus mode, high-speed mode, and ultra speed mode these speed categories range from 100 kHz to 5MHz, where standard mode is 100KHz, Fast mode is 400KHz, Fast mode plus is 1MHz, High-Speed Mode is 3.4MHz and Ultra-fast mode is 5MHz. 100KHz up to 1MHz are very similar, while 3.4 MHz needs some special consideration, and 5MHz being unidirectional requires even more special attention. But the most common speed categories for I2C Protocol are Standard mode, Fast Mode, and Fast mode plus these modes are easy to implement.

- **Arbitration**   
    I2C protocol supports multi-master bus system but more than one bus can not be used simultaneously. The SDA and SCL are monitored by the masters. If the SDA is found high when it was supposed to be low it will be inferred that another master is active and hence it stops the transfer of data.


### **I2C address** ###
In the I2C protocol, addresses are traditionally 7 bits long, but the actual transmitted address on the I2C bus includes an additional read/write bit, making it an 8-bit value. The left shift operation (`i << 1`) in the `HAL_I2C_Master_Transmit` function is used to convert the 7-bit address into an 8-bit address format required by the I2C protocol.

In the I2C protocol, the address `0` (0x00) has a special purpose and is known as the **General Call Address**. Here's a detailed explanation of what it is and how it is used:
### General Call Address (0x00)

- **Purpose**: The General Call Address is used to address all devices on the I2C bus simultaneously. When a master device sends a General Call Address, it is effectively broadcasting a message to all slave devices on the bus.
- **Address**: The General Call Address is `0x00` (binary `0000 0000`).

### I2C Addressing Format

1. **7-bit Addressing**: The standard I2C addressing uses 7 bits to specify the device address. This allows for 128 unique addresses (0 to 127).
2. **8-bit Format for Transmission**: When transmitting the address on the I2C bus, the address is placed in the upper 7 bits of the byte, and the least significant bit (LSB) is used to indicate whether the operation is a read (1) or write (0).
### Left Shift Operation (`i << 1`)

- **Purpose**: The left shift operation (`i << 1`) takes the 7-bit address and shifts it left by one bit. This effectively moves the 7-bit address to the upper 7 bits of the byte and clears the LSB.
- **Result**: After the left shift, the LSB can be used to specify the read/write operation.
### Example

If you have an I2C device with a 7-bit address `i`:

1. **Original 7-bit Address**: `i = 0x50` (for example, 0x50 is 80 in decimal).
2. **Left Shift Operation**: `i << 1` shifts the address left by one bit: `0x50 << 1 = 0xA0`.
3. **8-bit Address for Transmission**: The resulting 8-bit address is `0xA0`. This 8-bit value can be used directly in the I2C communication functions, where the LSB is set to 0 for a write operation or 1 for a read operation.

