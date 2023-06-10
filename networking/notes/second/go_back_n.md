# Go Back N
Go-Back-N is a flow control protocol used in computer networks to ensure reliable and sequential delivery of data packets. It is a sliding window protocol that allows the sender to transmit multiple packets without waiting for an acknowledgment for each individual packet. The receiver acknowledges the successful receipt of a series of packets, rather than acknowledging each packet individually.

* The sender divides the data stream into fixed-size packets and assigns a sequence number to each packet.

* The sender starts transmitting the packets, one after the other, continuously.

* The receiver receives the packets and sends cumulative acknowledgments.

* If the receiver detects an error in a packet, it discards that packet and all subsequent packets until the next expected packet.

* Upon receiving a NAK or not receiving an acknowledgment within a specified timeout, the sender re-transmits all the packets starting from the last acknowledged packet.

## Advantages of Go-Back-N:

* It allows for efficient use of network bandwidth by sending multiple packets before receiving acknowledgments.

* It simplifies the receiver's operation by acknowledging a range of packets at once.

## Disadvantages of Go-Back-N:

* It may lead to unnecessary retransmissions when only a single packet is lost or corrupted.

* It introduces additional delays if a packet is lost and the sender has to wait for the timeout before retransmitting.


# To the point difference between Selective Repeat and Go Back N

**Go-Back-N re-transmits again the whole thing(window of packets) upon receiving a negative acknowledgment, while Selective Repeat re-transmits only the lost or damaged packets.**
