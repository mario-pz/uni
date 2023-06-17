# Selective Repeat
Selective Repeat is another flow control protocol used for reliable data transmission in computer networks. It is also a sliding window protocol but differs from Go-Back-N in that it only re-transmits the packets that are damaged or lost, rather than re-transmitting a whole window of packets. Similar to [Go-Back-N](networking/notes/second/stop_n_wait.md), the sender divides the data stream into fixed-size packets and assigns a sequence number to each packet.

* The sender starts transmitting the packets, one after the other, continuously.
* The receiver receives the packets and sends individual acknowledgments for each successfully received packet.
* If the receiver detects an error in a packet, it discards that packet but keeps track of its sequence number.
* Upon receiving a negative acknowledgment (NAK) for a specific packet or not receiving an acknowledgment within a specified timeout, the sender retransmits only the lost or damaged packet(s), using their sequence numbers.

## Advantages of Selective Repeat:

* It reduces unnecessary retransmissions by selectively retransmitting only the lost or damaged packets.

* It provides better throughput than Go-Back-N when the channel has a low error rate.

## Disadvantages of Selective Repeat:

* It requires additional complexity in the receiver's operation to handle out-of-order packets and buffer management.

* It may lead to increased overhead in terms of memory usage to store out-of-order packets at the receiver.


# To the point difference between Selective Repeat and Go Back N

**Go-Back-N re-transmits again the whole thing(window of packets) upon receiving a negative acknowledgment, while Selective Repeat re-transmits only the lost or damaged packets.**