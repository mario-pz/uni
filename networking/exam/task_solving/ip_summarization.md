# Assume that an ABR in OSPF has its perimeter on networks 10.0.8.0/24 to 10.0.19.0/24. Mention a way to do summarization of these networks

* Determine the range of networks to be summarized. In this case, the range is from 10.0.8.0/24 to 10.0.19.0/24.

* Calculate the most concise summary address that encompasses the entire range of networks. To do this, find the common bits in the network addresses.

* Convert the network addresses to binary form:
```
10.0.8.0/24 : 00001010.00000000.000|01000.00000000
10.0.19.0/24: 00001010.00000000.000|10011.00000000
```

* Identify the common bits from the left in the binary representation:
```
Common bits: 00001010.00000000.000
```

* Determine the subnet mask based on the number of common bits:
```
Subnet mask: 11111111.11111111.111000.00000000 (or /20 in CIDR notation)
```

* Convert the subnet mask back to decimal form:
```
Subnet mask: 255.255.240.0
```

* The summarized address is the network address combined with the subnet mask:
```
Summary address: 10.0.8.0/20
```

# Assume that an ABR in OSPF has its perimeter on networks 172.16.32.0/24 to 172.16.67.0/24. Mention a way to do summarization of these networks

* Determine the range of networks to be summarized. In this case, the range is from 172.16.32.0/24 to 172.16.67.0/24.

* Calculate the most concise summary address that encompasses the entire range of networks. To do this, find the common bits in the network addresses.

* Convert the network addresses to binary form: (not necessarily in a prefix).

```
172.16.32.0/24: 10101100.00010000.0|0100000.00000000
172.16.67.0/24: 10101100.00010000.0|1000011.00000000
```

* Identify the common bits from the left in the binary representation:

```
Common bits: 10101100.00010000.0
```

* Determine the subnet mask based on the number of common bits:

```
Subnet mask: 11111111.11111111.10000000.00000000 (or /17 in CIDR notation)
```

* Convert the subnet mask back to decimal form:

```
Subnet mask: 255.255.128.0
```

* The summarized address is the network address combined with the subnet mask:

```
Summary address: 172.16.0.0/17
```


# Different way without specific prefix

```
10.0.8.0/24 
10.0.19.0/24 

19 - 8 + 1 = 12 = 2^3 + 2 ^ 2
```

remove 3 from first mask and 2 from second mask

```
10.0.8.0/21
10.0.16.0/22
```

# References

* *![](https://www.youtube.com/watch?v=QqEcCzhlWis)