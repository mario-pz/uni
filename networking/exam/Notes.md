# Calculating network protocol overhead
It involves analyzing the sizes of headers and payload within the TCP and IP layers to understand the proportion of overhead and application-level data in the network communication.

### Note
 *If you are working with IPv6, the IP header size would be different (40 bytes)*
 
* Calculate the total size of each datagram:

```
Size of TCP segment = Size of TCP header + Size of application data
Size of IP datagram = Size of IPv4 header + Size of TCP segment
```

* Calculate the overhead percentage:

```
Overhead = (Size of TCP header + Size of IPv4 header) / Size of IP datagram * 100
```

* Calculate the application-level data percentage:

```
Application Data Percentage = (Size of application data / Size of IP datagram) * 100
```