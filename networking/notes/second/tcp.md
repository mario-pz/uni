# TCP

TCP (Transmission Control Protocol) is a reliable, connection-oriented protocol used for data transmission over IP networks. It ensures data integrity and order by establishing a connection, segmenting data into packets, and adding headers for control and error detection. TCP uses acknowledgments and retransmissions for reliability and implements flow control and congestion control mechanisms. It's widely used for applications that require error-free and orderly data transmission.

| Source Port | Destination Port | Sequence Number |
|-------------|-----------------|-----------------|
|     16      |       16        |       32        |

* **Source Port (16 bits): Indicates the port number of the sender.

* **Destination Port (16 bits)**: Specifies the port number of the intended recipient.

* **Sequence Number (32 bits)**: Represents the sequence number of the first data byte in the TCP segment.

| Acknowledgment Number | Data Offset | Reserved | Flags |
|-----------------------|-------------|----------|-------|
|          32           |     4       |    6     |   6   |

* **Acknowledgment Number (32 bits): Contains the acknowledgment number that the sender expects to receive next.

* **Data Offset (4 bits)**: Indicates the size of the TCP header in 32-bit words (i.e., the number of 32-bit words that make up the header). This field is used to determine the start of the TCP data.

*  **Reserved (6 bits)**: Reserved for future use and must be set to zero.

* **Flags (6 bits)**: Various control flags that are used for different purposes, such as indicating the status of a TCP connection. The flags include URG (Urgent), ACK (Acknowledgment), PSH (Push), RST (Reset), SYN (Synchronize), and FIN (Finish).

| Window Size | Checksum | Urgent Pointer |
|-------------|----------|----------------|
|     16      |    16    |       16       |

* **Window Size (16 bits)**: Specifies the size of the receive window, which is the amount of data, in bytes, that the receiver can accept.

* **Checksum (16 bits)**: Used for error detection and verification of the TCP header and data.

* **Urgent Pointer (16 bits)**: If the URG flag is set, this field points to the sequence number of the last urgent data byte.

|       Options       |     Padding     |
|---------------------|-----------------|
| Variable (0-320)    | Variable (0-24) |

*  **Options (variable size)**: An optional field that can be used to include additional information or modify the default TCP behavior. This field can be of variable size, and its length is indicated by the Data Offset field.

* **Padding (variable size)**: If the Options field is used and its length is not a multiple of 4 bytes, padding is added to ensure that the TCP header aligns on a 32-bit boundary.