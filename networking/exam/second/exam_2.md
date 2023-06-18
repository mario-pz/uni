# 1: What are the differences between TCP and UDP

TCP is a connection-oriented protocol that ensures reliable and ordered delivery of data. 
It incorporates sequencing, acknowledgment, flow control, and congestion control mechanisms. It is well-suited for applications that require data integrity, such as web browsing and file transfers.

UDP is a connectionless protocol that offers unreliable and unordered delivery of data. It lacks sequencing, acknowledgment, flow control, and congestion control mechanisms. UDP is commonly used for real-time applications with low overhead, like streaming media and online gaming.

# 2: Host A and B are communicating over a TCP connection and Host B has already received from A all bytes up to byte 164. Assume that Host A then sends two segments to Host B one after the other . The first and second segments contain 90 and 80 bytes of data respectively. In the first segment, the sequence number is 165. Host B sends an ack whenever it receives a segment from Host A.

## What is the sequence number in the second segment sent by Host A to B.

```
Sequence number of the second segment = Sequence number of the first segment + Number of bytes in the first segment

Sequence number of the second segment = 165 + 90 = 255
```

## If the first segment arrives before the second, what will be the acknowledgment number that B will send

```
Acknowledgment number = Next expected sequence number

Acknowledgment number = 165 + 90 = 255
```

## If the second segment arrives before the first, what will be the acknowledgment number that B will send in this case

If the second segment arrives before the first, the acknowledgment number that Host B will send in this case would be 165.

## Assume that the two segments sent from A arrive in sequence at B. The first ack is lost and the second arrives after the timeout, draw a timing diagram showing the sending of segments and acks. For each segment have the seq number and the number of bytes sent, for each ack have the ack number

```
Host A:    |------------------|------------------|
           |     Segment 1    |     Segment 2    |
           | Seq: 165, 90B    | Seq: 255, 80B    |


Host B:     |------------------|------------------|
            |   ACK: 255 (1)   |   ACK: 335 (2)   |
```


# 3: When and how a TCP connection is terminated, draw the corresponding timing diagram

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

# 4: Assume that an application produces chunks of 40 bytes every 20msec and each chunk is encapsulated in a TCP segment and then an IP datagram. What percentage of each datagram will be overhead and what will be application layer data?

* Chunk size: 40 bytes
* Chunk generation interval: 20 msec
* TCP header size: 20 bytes
* IP header size: 20 bytes

Total overhead per chunk:

```
TCP overhead + IP overhead = 20 bytes + 20 bytes = 40 bytes
```

Total datagram size:


```
Chunk size + Total overhead per chunk = 40 bytes + 40 bytes = 80 bytes
```

Percentage of overhead:


```
Overhead size / Total datagram size * 100 = (40 bytes / 80 bytes) * 100 = 50%
```

Percentage of application layer data:

```
Application layer data size / Total datagram size * 100 = (40 bytes / 80 bytes) * 100 = 50%
```

This means that in each datagram, 50% of the total size will be overhead (TCP and IP headers) and the remaining 50% will be the actual application layer data.

# 5: State the main features of distance vector routing algorithms and name one instance of such an algorithm

* Distributed Operation: Distance vector algorithms operate in a decentralized manner, where each router exchanges routing information with its neighboring routers.

* Distance Metric: The algorithm uses a distance metric, usually based on the number of hops or the cost associated with a route, to determine the best path to a destination.

* Routing Table Updates: Routers periodically exchange their routing tables with their neighboring routers, sharing information about the available routes and their associated costs.

* Iterative Calculation: The algorithm iteratively updates the routing tables based on the information received from neighboring routers, aiming to converge on the optimal routes.

* Hop-by-Hop Routing: Distance vector algorithms make routing decisions hop-by-hop, where each router only has knowledge of its immediate neighbors and the cost to reach them.

One instance of a distance vector routing algorithm is the Routing Information Protocol (RIP). RIP uses hop count as the distance metric and employs the Bellman-Ford algorithm for route calculation.

# 6: Assume that an ABR in OSFP has networks 172.16.32.0/24 through 172.16.67.0/24 in its perimeter. Mention a way to summarize (summarization) these networks (not necessarily in a prefix).


```
172.16.32.0/24
172.16.67.0/24 
```

```
67-32 + 1= 35, 2^5 + 2 ^ 2
```

remove 5 bits from the mask and then 2

```
172.16.32.0/19
172.16.32+2^5.0/22 = 172.16.32.64/22
```

# 7: Explain what the BGP protocol is for

The BGP protocol is used for exchanging routing information between autonomous systems 
in large-scale networks like the Internet. It enables the selection of optimal routes and facilitates inter-domain routing.