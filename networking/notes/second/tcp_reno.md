
# TCP Reno

Its an enhancement over TCP Tahoe that further improves congestion control.  It introduces the Fast Recovery mechanism to handle packet losses more efficiently.

# Understand the Basics:
TCP Reno builds upon the basic mechanisms of TCP Tahoe,
including slow start and congestion avoidance.
It introduces an additional mechanism called Fast Recovery to handle packet losses.

# Slow Start and Congestion Avoidance:
TCP Reno follows the slow start and congestion avoidance mechanisms described in the TCP Tahoe explanation (steps 1-3).

## Fast Recovery:
When a packet loss is detected (e.g., due to triple duplicate acknowledgments), TCP Reno enters the fast recovery phase.
Instead of going back to the slow start phase, TCP Reno reduces the congestion window (cwnd) to approximately half of the current cwnd.
It then enters the fast recovery phase, where it increases cwnd linearly by 1 segment for each additional acknowledgment received.

## Congestion Event and Timeout:
If a timeout occurs before receiving an acknowledgment, TCP Reno assumes congestion and follows similar steps as TCP Tahoe. It sets the congestion window (cwnd) to 1 segment and updates the congestion threshold (ssthresh) to half of the previous cwnd size. TCP Reno then re-enters the slow start phase.

# Exercise Approach:
This exercise typically involves simulating the behavior of the algorithm and analyzing its performance in different scenarios.

You might be provided with initial values for cwnd, ssthresh, RTT, segment size, or other relevant parameters.

## Here's an approach to solving TCP Reno exercises:

* Start with the initial values provided.

* Simulate the slow start phase by doubling the cwnd for every acknowledgment received.

* Track the cwnd, ssthresh, and the number of acknowledgments.

* If a congestion event occurs (e.g., triple duplicate acknowledgments), enter the fast recovery phase.
	* Reduce cwnd to approximately half of the current cwnd.
	* Increment cwnd by 1 segment for each additional acknowledgment received.

* If a timeout occurs, follow the steps similar to TCP Tahoe: set cwnd to 1 and update ssthresh.

* Enter the congestion avoidance phase and increment cwnd linearly for every acknowledgment.

* Continue simulating until you reach a specific condition mentioned in the exercise (e.g., a certain number of rounds or reaching a maximum cwnd value).

* Keep track of the changes in cwnd, ssthresh, and other variables at each step.

* Analyze the results and answer the questions based on the exercise requirements.