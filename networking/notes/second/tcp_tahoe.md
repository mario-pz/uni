# TCP Tahoe

TCP Tahoe is a congestion control algorithm used in TCP 
to manage network congestion and ensure reliable data transmission. 

# Understand the Basics:
Familiarize yourself with the fundamentals of TCP, including the three-way handshake, reliable data transfer, and congestion control.
TCP Tahoe primarily uses two mechanisms: Slow Start and Congestion Avoidance.

## Slow Start:
At the beginning of a connection or after a timeout, TCP Tahoe enters the slow start phase.
During slow start, the congestion window (cwnd) is initially set to a small value, typically one or a few segments.
For every acknowledgment received, cwnd is doubled, leading to exponential growth in the sending rate.
Slow start continues until the congestion window reaches a congestion threshold (ssthresh) or a congestion event occurs (e.g., timeout).

## Congestion Avoidance:
After reaching the ssthresh or experiencing congestion, TCP Tahoe enters the congestion avoidance phase.
In this phase, cwnd is increased linearly rather than exponentially.
For every acknowledgment received, cwnd is incremented by 1/cwnd.
This prevents aggressive growth and aims to avoid congestion collapse.

## Congestion Event and Timeout:
If a timeout occurs before receiving an acknowledgment, it indicates that congestion has likely happened.
In such cases, TCP Tahoe assumes the network is congested and halves the congestion window (cwnd = 1).
Additionally, ssthresh is updated to half of the previous congestion window size.
TCP Tahoe then re-enters the slow start phase.

# Exercise Approach:
TCP Tahoe exercises often involve simulating the behavior of the algorithm over multiple rounds or scenarios.
You might be given information about the initial cwnd, ssthresh, round-trip time (RTT), segment size, or other relevant parameters.

## Follow these steps to solve the exercises:
* Start with the initial values provided.
* Simulate the slow start phase by doubling the cwnd for every acknowledgment received.
* Track the cwnd, ssthresh, and the number of acknowledgments.
* If a congestion event occurs (e.g., timeout), halve the cwnd and update ssthresh.
* Enter the congestion avoidance phase and increment cwnd linearly for every acknowledgment.
* Continue simulating until you reach a specific condition mentioned in the exercise (e.g., a certain number of rounds or reaching a maximum cwnd value).
* Keep track of the changes in cwnd, ssthresh, and other variables at each step.
* Analyze the results and answer the questions based on the exercise requirements.