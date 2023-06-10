Network Summarization helps in reducing the routing table size and optimizing OSPF routing updates by advertising a single route instead of multiple individual routes. It also enhances network performance by reducing the processing overhead on routers.

# How to do Summarization

* Determine the range of networks to be summarized. In this case, the range is from 10.0.8.0/24 to 10.0.19.0/24.

* Calculate the most concise summary address that encompasses the entire range of networks. To do this, find the common bits in the network addresses.

* Convert the network addresses to binary form:
```
10.0.8.0/24: 00001010.00000000.00001000.00000000
10.0.19.0/24: 00001010.00000000.00010011.00000000
```

* Convert the network addresses to binary form:

```
10.0.8.0/24: 00001010.00000000.00001000.00000000
10.0.19.0/24: 00001010.00000000.00010011.00000000
```

* Identify the common bits from the left in the binary representation:

```
Common bits: 00001010.00000000
```


* Determine the subnet mask based on the number of common bits:

```
Subnet mask: 11111111.11111111.11100000.00000000 (or /17 in CIDR notation)
```

* Convert the subnet mask back to decimal form:

```
Subnet mask: 255.255.224.0
```


* The summarized address is the network address combined with the subnet mask:

```
Summary address: 10.0.8.0/17
```