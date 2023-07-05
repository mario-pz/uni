The goal of disk scheduling is to optimize the access and retrieval of data from a computer's disk storage system. It involves determining the order in which pending input/output (I/O) requests should be serviced by the disk controller to minimize the overall access time and maximize disk utilization.

* Seek Time: The time required for the read/write heads to move to the desired track on the disk.

* Rotational Latency: The time it takes for the desired sector of the disk to rotate under the read/write heads.

* Transfer Time: The time required to transfer the requested data to or from the disk.

* Request Arrival Time: The time at which an I/O request is made to the disk.

* Current Head Position: The current location of the read/write heads on the disk.

* Queue Length: The number of pending I/O requests in the disk queue.

# Algorithms used

## First-Served (FCFS):
I/O requests are serviced in the order they arrive, resulting in a first-in, first-out (FIFO) approach.

### Example
A disk contains 200 threads (0-199), Current position of r/w is 50. 

```
0,16,24,43,50,82,140,170,190
```

![](fcfs_disk.png)

Conclude the number of track movements by r/w.

```
	(82-50)        Easier version ->   (170-50)
+   (170-82)                         + (170-43)
+   (170-43)                         + (140-43)
+   (140-43)                         + (140-16)
+   (140-24)                         + (190-16)
+   (24-16)                          -----------------                     
+   (190-16)                           642
-----------------
642
```

## Shortest Seek Time First (SSTF):
The request with the shortest seek time from the current head position is serviced next, minimizing head movement.

### Example
A disk contains 200 threads (0-199), Current position of r/w is 50. 

```
0,16,24,43,50,82,140,170,190
```

![](sstf_disk.png)

Conclude the number of track movements by r/w.

```
    (50-16)
+   (190-16)
-----------------
208
```

If r/w head takes 1ns to move from one track to another then what is the total time taken?

```
208 * 1 = 208ns
```

## SCAN:

The disk arm scans in a particular direction (e.g., from the outermost track to the innermost track or vice versa), servicing requests along the way, until it reaches the end of the disk, and then changes direction. (like a elevator)

### Example
A disk contains 200 threads (0-199), Current position of r/w is 50. 

```
0,16,24,43,50,82,140,170,190
```

![](scan_disk.png)

Conclude the number of track movements by r/w.

```
    (199-50)
+   (199-16)
-----------------
332
```

If r/w head takes 1ns to move from one track to another then what is the total time taken?

```
332 * 1 = 332ns
```

## C-SCAN:
Similar to SCAN, but the disk arm scans only in one direction, servicing requests along the way until it reaches the end, at which point it quickly moves back to the beginning of the disk to start the next scan.

### Example
A disk contains 200 threads (0-199), Current position of r/w is 50. 

```
0,16,24,43,50,82,140,170,190
```

![](cscan_disk.png)

Conclude the number of track movements by r/w.

```
    (199-50)
    (199-0) (DONT SKIP THIS)
+   (43-0)
-----------------
391
```

## LOOK:
The disk arm scans in a particular direction, servicing requests along the way, but changes direction once it reaches the last requested track, without going to the end of the disk.

### Example
A disk contains 200 threads (0-199), Current position of r/w is 50. 

```
0,16,24,43,50,82,140,170,190
```

![](look_disk.png)

Conclude the number of track movements by r/w.

```
    (190-50)
+   (190-16)
-----------------
314
```

If r/w head takes 1ns to move from one track to another then what is the total time taken?

```
314 * 1 = 314ns
```

## C-LOOK:
Similar to LOOK, but the disk arm scans only in one direction, servicing requests along the way until it reaches the last requested track, and then quickly moves back to the beginning of the requested track range.

### Example
A disk contains 200 threads (0-199), Current position of r/w is 50. 

```
0,16,24,43,50,82,140,170,190
```

![](clook_disk.png)

Conclude the number of track movements by r/w.

```
    (190-50)
    (190-16) (Its important to value this as well)
+   (43-16)
-----------------
341
```

## EDF (Earliest Deadline First)

* Similar to SSTF 
Both machine a specific priority criterion the
which bypasses the download order criterion or else the
criterion of fairness – FCFS

* To EDF as a criterion for what will be the next application which
will be served is taken instead of the shorter time
movement/search, the earliest deadline (served
i.e. the process that expires the fastest)

* However, it presents the same problems as FCFS (leads
to random head movements without taking into account
its current location)

### Example

A disk contains 200 threads (0-199), Current position of r/w is 75. 

| MS | CYLINDER |
| --- | ---| 
| 35 |98 |
| 72 |105|
| 48 |183|

Suppose the head is on cylinder 75 and must applications for cylinders 98, 105, 183 with
deadlines respectively 35ms, 72ms, 48ms…? Move from 75 to 98 and then 183 (no
in between to serve 105) and then to 105.

![](edf_disk.png)

## SCAN-EDF (Combination of SCAN and EDF)

* Start with EDF
* Requests with the same deadlines are executed with SCAN
* Any Requests bundles that are grouped will also be executed with SCAN (with deadlines relatively close to each other) 

### Notes
* Requirement: The re arrangement of a bundle using SCAN must not block a request to finish its deadline
* If the deadlines are evenly distributed -> organize in groups (bundles) of fixed size (eg 10 requests per bundle)
* Most common: grouping in bundles the requests that the
their deadlines fall within a certain same period
interval (eg every 100 ms)
* Variant optimization: the principle of the above
'specific period of time' to be determined each time
from the next earliest deadline in the series.

### Example

A disk contains 185 threads (0-399), Current position of r/w is 50. 
For every 100ms we make a new bundle

|Request|Deadline|Track|
|---|---|---|
|A|150ms|25|
|B|201ms|112|
|C|399ms|95|
|D|94ms|31|
|E|295ms|185|
|F|78ms|85|
|G|165ms|150|
|H|125ms|101|
|I|300ms|85|
|J|210ms|90|

* 0-100: F, D
* 100-200: H,A,G
* 200-300: B,J,E
* 300-400: I,C

#### How it would be solved using SCAN

```
F(85),
I(85),
J(90),
C(95),
H(101),
B(112),
G(150),
E(185),
D(31),
A(35)
```

#### How it would be solved using EDF
Just copy paste the bundles you made above

```
F(85),
D(31),
H(101),
A(35)
G(150),
B(112),
J(90),
E(185),
C(95),
I(85), 
```

#### How it would be solved using SCAN-EDF

```
F(85), (EDF)
D(31), (EDF)
A(35) (SCAN)
H(101), (SCAN)
G(150), (SCAN)
E(185), (SCAN) (End of the line)
B(112), 
J(90),
I(85),  
C(95),
```
