
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

# What is Reno
TCP Reno is a conges##
tion control algorithm and is a widely used transport protocol for reliable data transmission over IP networks.
It is named after the city of Reno, Nevada, where it was first implemented.

TCP Reno operates by utilizing a combination of two main techniques: slow start and congestion avoidance.

* **Slow Start**
    Initially, when a TCP connection is established or re-established, TCP Reno starts in the slow start phase.
    During slow start, the sender gradually increases the congestion window (cwnd) by doubling it for every acknowledgment received.
    This allows the sender to probe the network for available bandwidth and maximize its transmission rate.

* **Congestion Avoidance**
    Once the cwnd exceeds a certain threshold, TCP Reno switches from the slow start phase to the congestion avoidance phase.
    In this phase, the sender increases the congestion window more conservatively, typically by adding one segment for every acknowledgment received.
    The goal is to maintain a balance between network utilization and avoiding congestion by not overwhelming the network with excessive traffic.

* **Fast Recovery**
    If a TCP Reno sender receives a packet loss indication, it assumes congestion has occurred and enters a state called fast recovery.
    During fast recovery, the sender reduces the congestion window by half and re-transmits the lost packet(s).
    It then enters a congestion avoidance phase again to continue probing the network for available bandwidth.

# What is Taho?

Its an earlier congestion control algorithm that predates TCP Reno. It was named after Lake Tahoe, California, and was one of the first TCP congestion control algorithms developed. Tahoe operates with a simpler congestion control mechanism compared to TCP Reno. It uses three main techniques:

* **Slow Start**
    Similar to Reno, Tahoe starts in the slow start phase, gradually increasing the congestion window.

* **Congestion Avoidance**
    Once the cwnd exceeds a certain threshold, TCP Tahoe switches to the congestion avoidance phase. In this phase, the sender increases the congestion window more conservatively, typically by adding one segment for every round-trip time.

* **Fast Recovery**
    When TCP Tahoe detects a packet loss, it assumes congestion has occurred and enters a state called fast recovery.
    During fast recovery, TCP Tahoe reduces the congestion window to one segment and retransmits the lost packet(s).
    It then re-enters the slow start phase, gradually increasing the congestion window again.

# Differences between Reno and Tahoe
The main difference between Reno and Tahoe lies in their fast recovery mechanisms:

* **TCP Reno** uses a more aggressive approach during fast recovery. It reduces the congestion window by half and then enters congestion avoidance, allowing it to more quickly recover from packet losses and probe for available bandwidth.

* **TCP Tahoe**, on the other hand, reduces the congestion window to one segment and re-enters the slow start phase after a packet loss. It takes a more conservative approach, gradually increasing the congestion window again.

Overall, TCP Reno is considered an improvement over TCP Tahoe because of its more responsive and efficient handling of packet losses, allowing for better network utilization and faster recovery from congestion situations. TCP Reno has largely replaced TCP Tahoe in modern TCP implementations.




# References

* https://en.wikipedia.org/wiki/TCP_congestion_control