* Forwarding transfers packets from the router's input to the appropriate router's output
* Routing determines which path the packets will take from the sender to the destination
* Routing algorithms

# Proportion
* routing: journey planning process from dispatch to destination
* forwarding: transit process through simple switching

# Fragmentation
In the layered architecture of a network, each layer communicates with its corresponding peer, using a protocol of the same layer. However, this function is performed indirectly as each layer has the possibility of direct communication only with its neighbors, through their interface.

![Fragmentation](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fb/Encapsulation.png/799px-Encapsulation.png)

An IP address is hard-coded by the system itself or borrowed from a DHCP Server.

# DHCP investigation:
* host broadcasts “DHCP discover” message (optional)
* DHCP server responds with “DHCP offer” message (optional)
* host requests an IP address: “DHCP request” message
* DHCP server sends address: “DHCP ack” message

At the same time, the DHCP server can also return a DNS gateway or host/ip up to a network mask.

# Various Protocols
* ICMP: used by devices to report errors, transferred via IP Datagrams

# IPv4 vs IPv6
![](https://i.ytimg.com/vi/H-J_Dpd2Nc4/maxresdefault.jpg)

- IPv4 : 2^32 Possible network addresses
- IPv6: 2^128 possible network addresses
