
# How to tell which is being used
## To detect TCP Reno on a graph:
* Look for aggressive fluctuations and significant drops in the cwnd.
* reacts aggressively to congestion by sharply reducing cwnd.

## To detect TCP Tahoe on a graph:
* Look for a slower and more gradual change in the congestion window (cwnd) without extreme drops.
* It exhibits a more conservative response to congestion compared to TCP Reno.

# Notes
## cwnd
* default value = 1
* during slow start cwnd increases by double 
* cwnd increases by 1 if its not in the phase of slow start

## RTT
* default value is 1
* On each dot RTT increases by 1

## MSS
* MSS default value is 1
* MSS value continues on like this:
```
1 MSS
2 + 1 = 3 MSS
4 + 3 = 7 MSS
...
```

# Task

## Calculate the number of bytes sent from transmission round X to Y

Multiply the number of segments sent during that time by the MSS. 
For example, if the graph shows a constant cwnd of 20 segments from round 10 to 16, and the MSS is 200 bytes, the total bytes sent would be 20 segments * 200 bytes = 4000 bytes.

### What if cwnd is not constant?
Then you need to sum up the product of each cwnd value with the MSS to calculate the total bytes send.

For example, let's say the cwnd values for rounds 10 to 16 are as follows: 18, 15, 20, 17, 19, 16, 21. Assuming the MSS is 200 bytes, the calculation would be as follows:

```
Total bytes sent = (cwnd10 * MSS) + (cwnd11 * MSS) + (cwnd12 * MSS) + (cwnd13 * MSS) + (cwnd14 * MSS) + (cwnd15 * MSS) + (cwnd16 * MSS)
```

```
Total bytes sent = (18 * 200) + (15 * 200) + (20 * 200) + (17 * 200) + (19 * 200) + (16 * 200) + (21 * 200)
```

```
Total bytes sent = 3600 + 3000 + 4000 + 3400 + 3800 + 3200 + 4200 = 22,200bytes
```

## Find the value of ssthresh

Look for the point in the graph where the congestion window transitions from the slow start phase to the congestion avoidance phase.
The ssthresh is typically set when TCP Reno encounters a congestion event and reduces cwnd significantly. Look for a sharp drop in cwnd that precedes the slower growth pattern.

## Find the cwnd at transmission round X
Locate the corresponding point on the graph at round X on the X-axis. Then, identify the value of cwnd at that point on the Y-axis.
It represents the cwnd value at transmission round X.