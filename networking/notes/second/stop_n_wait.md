The stop and wait protocol is a simple and basic flow control mechanism used in data communication to ensure reliable transmission between a sender and a receiver.
It is commonly employed in situations where the transmission channel has a low error rate and reliability is crucial.

In the Stop and Wait protocol there is:

* **Sender**: The sender divides the data to be transmitted into fixed-size packets.
After sending each packet, the sender stops and waits for an ACK from the receiver before proceeding with the next packet.

* **Receiver**: The receiver receives the packet and checks for any errors. If the packet is error-free, the receiver sends an ACK back to the sender indicating successful reception. If an error is detected, the receiver discards the packet and requests re-transmission of the lost packet.

* **Timeout**: To handle scenarios where the acknowledgment is lost or delayed, the sender employs a timeout mechanism. If the sender doesn't receive an acknowledgment within a certain time (timeout period), it assumes that the packet was lost and re-transmits it.

* **Flow control**: The sender stops transmitting until it receives an acknowledgment, ensuring that the receiver can handle the incoming packets at its own pace. This prevents the receiver from being overwhelmed by a continuous stream of packets.

## Taking to account

While the stop and wait protocol is simple to implement and guarantees reliable transmission, it suffers from low link utilization. 
The sender must wait for an acknowledgment for each packet, resulting in significant idle time for the transmission channel. 
As a result, the throughput is limited, especially for **high-capacity** links.

Due to its limited efficiency, stop and wait protocols are typically used in scenarios where reliability is critical, error rates are low, and the data transmission requirements are not time-sensitive. In situations where higher throughput and improved link utilization are desired, more advanced protocols like sliding window protocols, such as Go-Back-N or Selective Repeat, are commonly employed.