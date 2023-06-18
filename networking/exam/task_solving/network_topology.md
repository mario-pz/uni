# You are given a network "insert picture here"

There are 4 Routers RA,RB,RC,RD and 3 computer H1,H2,H3.

H1 is connected to RA's interface 1,
H2 is connected to RA's interface 2,
RA interface 3 is connected to RB interface 1
RA interface 4 is connected to RC interface 1
RB interface 2 is connected to RD interface 1
RC interface 2 is connected to RD interface 2
RD interface 3 is connected to H3

![](../../assets/simple_network.png)

Assume this is a datagram network. Answer with reason if you can make a forwarding table on Router A so that all traffic from H1 directed to H3 is forwarded from RA's interface 3 and all traffic directed from H2 to H3 is forwarded from RA's interface 4, If your answer is negative then indicate what kind of network can support this function.

## Answer

In the given datagram network topology, it is not possible to create a forwarding table on Router A that directs all traffic from H1 to H3 through interface 3 and all traffic from H2 to H3 through interface 4. This limitation arises because Router A does not have a direct connection to Router D, where H3 is connected, and thus lacks the necessary information to determine the next hop for H3. To achieve the desired forwarding behavior, a network configuration with additional routing information and routing protocols, such as OSPF or BGP, would be required. Such a setup would enable the exchange of routing information between routers and provide Router A with the necessary details to create a forwarding table that includes the appropriate next hop and outgoing interfaces for H3.


# Consider the network shown below.

![](../../assets/network_topology_2.png)

* AS3, and AS2 are running RIP for the internal-AS routing protocol.
* AS1 and AS4 are running OSPF for the internal-AS routing protocol.
* eBGP and iBGP are used for the communication routing protocol between the different autonomous systems. 
* There is no physical link between AS2 and AS4.

## Which routing protocol does router 3a learn about prefix x from: (OSPF, RIP, eBGP, iGBP)

*AS3 is running RIP for the internal-AS routing protocol.*

Prefix x is external to AS3 therefore 3a will learn about prefix x eBGP protocol.

## What routing protocol does router 3b learn about x from?

Router 3b will only learn about prefix x from within AS3, using the RIP protocol.

## What routing protocol does router 4a learn about x from?

Prefix x is internal to AS4, therefore router 4a will learn about prefix x through OSPF.


