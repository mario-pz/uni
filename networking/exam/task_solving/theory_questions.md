# Why each host should estimate RTT round trip propagation time in TCP. How is it valued by hosts?

Each host in TCP estimates the RTT to achieve efficient and reliable data transmission.
RTT estimation is crucial for setting appropriate timeouts, detecting network congestion, and triggering retransmissions.

Hosts value RTT estimation as it enables them to optimize their timeout values, adapt congestion control mechanisms, and ensure reliable delivery of data.

# Describe how flow control is achieved in TCP, explaining what happens in the event of a recipient overflow and how it differs from congestion control

In TCP, flow control is achieved through a sliding window mechanism. The recipient specifies its receive window size, and if it becomes full, a smaller window size is advertised to the sender, indicating to slow down transmission. Flow control regulates the rate of data based on the recipient's buffer capacity, while congestion control manages the sending rate based on network congestion to prevent congestion and maintain efficient performance.

# Describe the three way handshake and draw the timing diagram

The three-way handshake is the initial TCP connection establishment process. The client sends a SYN packet to the server, which responds with a SYN-ACK packet. The client then sends an ACK packet, and the connection is established. The timing diagram shows the sequence of these steps.

```
Client                          Server
  |                                |
  |--------- SYN (Seq=X) --------->|
  |                                |
  |<--- SYN-ACK (Seq=Y, Ack=X+1)---|
  |                                |
  |---ACK (Seq=X+1, Ack=Y+1)------>|
  |                                |
  |     Connection Established     |

```

# TCP vs UDP

TCP is a connection-oriented protocol that ensures reliable and ordered delivery of data. 
It incorporates sequencing, acknowledgment, flow control, and congestion control mechanisms. It is well-suited for applications that require data integrity, such as web browsing and file transfers.

UDP is a connectionless protocol that offers unreliable and unordered delivery of data. It lacks sequencing, acknowledgment, flow control, and congestion control mechanisms. UDP is commonly used for real-time applications with low overhead, like streaming media and online gaming.

# When and how a TCP connection is terminated, draw the corresponding timing diagram

A TCP connection can be terminated gracefully or forcefully. In a graceful termination, the initiating party sends a FIN packet, and both parties exchange ACK and FIN packets before closing the connection.

```
Client                          Server
  |                                |
  |--------- FIN (Seq=X)---------> |
  |                                |
  |<-------- ACK (Ack=X+1)---------|
  |                                |
  |<-------- FIN (Seq=Y) ----------|
  |                                |
  |-------- ACK (Ack=Y+1)--------> |
  |                                |
  |       Connection Closed        |
```

In a forceful termination, one party sends an RST packet to abruptly close the connection without further acknowledgment.

```
Client                          Server
  |                                |
  |--------- RST (Seq=X)---------> |
  |                                |
  |                                |
  |       Connection Closed        |

```

# Suppose an application produces chunks of 40 bytes every 20 msec and each chunk is encapsulated in a TCP segment and then in an IP datagram. Find the overhead percentage of each datagram and application level data percentage

|IP Header | TCP Header| Application Data |
|---|---|---|
|20 bytes|20 bytes|40 bytes|

* Calculate the total size of each datagram:

```
Size of TCP segment = Size of TCP header + Size of application data chunk
= 20 bytes + 40 bytes = 60 bytes
Size of IP datagram = Size of IPv4 header + Size of TCP segment
= 20 bytes + 60 bytes = 80 bytes
```

* Calculate the overhead percentage:

```
Overhead = (Size of TCP header + Size of IPv4 header) / Size of IP datagram * 100
= (20 bytes + 20 bytes) / 80 bytes * 100
= 40%
```

* Calculate the application-level data percentage:

```
Application Data Percentage = (Size of application data chunk / Size of IP datagram) * 100 = (40 bytes / 80 bytes) * 100 = 50%
```

# Differences between Go-back-N and Selective Repeat

In Go-Back-N, the sender continues sending a stream of frames without waiting for individual acknowledgments, and if an error or timeout occurs, it re-transmits the entire window of unacknowledged frames. This approach is simple but can lead to unnecessary re-transmissions. 

On the other hand, Selective Repeat allows the receiver to individually acknowledge correctly received frames, allowing the sender to re-transmit only the specific frames that are corrupted or lost. This targeted retransmission minimizes unnecessary retransmissions and improves efficiency. 

TCP one of the core protocols of the Internet, establishes a sliding window protocol that utilizes Selective Repeat for reliable data delivery.

# State the main reasons for adopting IPv6 and describe the content of the datagram

IPv6 is adopted for its larger address space, improved scalability, built-in security, auto-configuration, mobility support, IoT facilitation, and future-proofing. A typical IPv6 datagram consists of the version, traffic class, flow label, payload length, next header, hop limit, source address, destination address, options, and payload.

# Explain what is the utility of Autonomous Systems on the internet.
 
Autonomous Systems are collections of networks, managed independently by a single organization. They provide routing, connectivity, autonomy, scalability, redundancy, and foster competition. Their interconnections and independent management contribute to the internet's functionality, resilience, and growth.

# Describe the "count to infinity" problem using an example network consisting of three routers

In a network with three routers (A, B, and C), the "count to infinity" problem occurs when there is a link failure. Let's assume initially all routers have routes to each other with a metric of 1. When the link between B and C fails, B and C update their routing tables by setting the metric to infinity. However, A and C still believe they can reach each other through themselves with a metric of 2 (1 + 1). This incorrect information leads to routing loops and network instability.

# State the differences between distance vector and link state routing algorithms and examples of modern routing algorithms by category.

* **Information Exchange**: Distance vector algorithms share routing information with directly connected neighbors, while link state algoedo thelo enanrithms share complete network topology information with all routers in the network.

* **Routing Table Updates**: Distance vector algorithms periodically send updates containing their entire routing table to neighbors, while link state algorithms flood network topology changes to ensure all routers have consistent information.

* **Scalability**: Distance vector algorithms scale poorly in large networks due to frequent updates and limited information, while link state algorithms handle large networks better with their accurate and up-to-date view of the network.

## Examples of modern routing algorithms by category:

* **Distance Vector**: (**RIP** , **IGRP**, **EIGRP**)

* **Link State**: (**OSPF**, **IS-IS**)

* **Hybrid**: BGP which combines aspects of both distance vector and link state algorithms.

* **Path Vector**: BGP used for interdomain routing in the Internet.


# What is the BGP protocol

The BGP enables routers in different AS to exchange routing information and make informed decisions, playing a crucial role in interconnecting diverse networks worldwide.

BGP is primarily used in large-scale networks to establish and maintain efficient and reliable connectivity between autonomous systems, considering factors like network policies, path attributes, and path cost.

# Develop the main features of the OSPF routing algorithm and explain the need for areas

The OSPF routing algorithm incorporates key features such as a Link-State Database for maintaining network state, the SPF Algorithm for calculating shortest paths, Neighbor Discovery for establishing connections, and Dynamic Updates for exchanging routing information. 

Areas are essential in OSPF as they enable scalability, simplify administration, improve convergence, and enhance network security by dividing large networks into smaller units.

# State which transport protocol the HTTP,DNS,SMTP,FTP, skype for voice, youtube, DHCP applications use and explain why

HTTP primarily uses TCP for reliable communication, DNS relies on UDP for faster communication, SMTP utilizes TCP for reliable message delivery, FTP primarily uses TCP for reliable data transfer, Skype for Voice relies on UDP for low-latency real-time communication, YouTube uses TCP for reliable video streaming, and DHCP uses UDP for quick IP address assignment.

# Consider a reliable transmission protocol that uses only NACs. How would such a protocol affect performance relative to a protocol that sends positive ACKs?

In scenarios with low-frequency data transmission, the impact of using a protocol with negative acknowledgments (NACs) would be minimal. However, in scenarios with high-frequency data transmission and low losses, using NACs would introduce additional latency, overhead, and inefficiencies.

## Hint: consider two scenarios

### a) Transmitter sending data with a low frequency:

In this scenario, the impact of using a protocol with NACs would be minimal. Since the data transmission frequency is low, the occurrence of lost or corrupted packets would be relatively rare. Therefore, the need for explicit re transmission requests through NACs would have a minimal effect on performance.

### b) Transmitter sends the data with high frequency and with low losses. It is also considered that the receiver sends an ACK when it receives the next packet than expected.

In this scenario, using a protocol with NACs would have a more noticeable impact on performance. With NACs, the receiver would need to individually request retransmissions for missing packets, introducing additional latency and overhead. The lack of positive acknowledgments means that the transmitter may not be aware of successful deliveries until a NAC is received, leading to inefficiencies in the transmission process.

# How does IPv6 communicate with IPv4?
IPv6 and IPv4 communicate through a process called IPv6 transition mechanisms. These mechanisms enable communication between IPv6-only and IPv4-only networks by encapsulating IPv6 packets within IPv4 packets or by using various translation techniques to convert IPv6 packets into IPv4-compatible formats, allowing interoperability between the two protocols.

# if two different values for cwnd arise from the flow and congestion control mechanisms, how does tcp decide what do we answer?

TCP can choose the smaller value if the cwnd value from the flow control mechanism is smaller, and the larger value if the cwnd value from the congestion control mechanism is larger.