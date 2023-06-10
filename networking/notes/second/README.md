
# TCP

# CWND (Congestion Window)
Its fundamental variable used in congestion control algorithms like TCP.
It plays a crucial role in managing the flow of data between a sender and a receiver to ensure reliable and efficient communication.

cwnd represents the number of unacknowledged packets that a sender can transmit into the network without overwhelming it with excessive traffic, thereby causing congestion. It acts as a flow control mechanism, allowing the sender to adapt its transmission rate based on the network conditions.

The value of cwnd dynamically adjusts throughout the communication process, considering factors like round-trip time, packet loss indications, and congestion signals. Initially, during the slow start phase, cwnd starts with a small value and gradually increases as acknowledgments are received.

As the sender continues to receive acknowledgments, cwnd grows, allowing for more packets to be sent concurrently. This increases the transmission rate and improves network utilization. However, if congestion is detected, typically through packet loss or other congestion indications, the sender reduces the value of cwnd to alleviate the congestion.

The congestion control algorithm employed, such as TCP Reno or TCP Tahoe, determines how cwnd is updated in response to network conditions. For example, TCP Reno uses an aggressive approach by halving cwnd upon detecting congestion, while TCP Tahoe reduces cwnd to one segment and re-enters a slow start phase.

By managing cwnd, congestion control algorithms aim to strike a balance between utilizing available network capacity and avoiding congestion. This allows for efficient data transmission and helps maintain the stability and performance of the network connection.

In summary, cwnd is a variable that represents the number of unacknowledged packets a sender can transmit without causing congestion. It dynamically adjusts based on network conditions, enabling efficient data transmission while preventing network overload.


# Differences between Reno and Tahoe
The main difference between Reno and Tahoe lies in their fast recovery mechanisms:

* **TCP Reno** uses a more aggressive approach during fast recovery. It reduces the congestion window by half and then enters congestion avoidance, allowing it to more quickly recover from packet losses and probe for available bandwidth.

* **TCP Tahoe**, on the other hand, reduces the congestion window to one segment and re-enters the slow start phase after a packet loss. It takes a more conservative approach, gradually increasing the congestion window again.

Overall, TCP Reno is considered an improvement over TCP Tahoe because of its more responsive and efficient handling of packet losses, allowing for better network utilization and faster recovery from congestion situations. TCP Reno has largely replaced TCP Tahoe in modern TCP implementations.

# References

* https://en.wikipedia.org/wiki/TCP_congestion_control