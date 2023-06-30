# Three processes are competing for 3 resources A,B,C.  Given the below table

* What resources have already been allocated  in every process
	*  Process P1 has allocated resources A=2, B=1, C=3.
	- Process P2 has allocated resources A=2, B=3, C=2.
	- Process P3 has allocated resources A=0, B=2, C=1.

* What are the max resources each kind of process can request
	- Process P1 can request a maximum of resources A=3, B=6, C=8.
	- Process P2 can request a maximum of resources A=2, B=9, C=8.
	- Process P3 can request a maximum of resources A=3, B=2, C=3.

* What resources are left from each kind
	Available resources are A=3, B=3, C=X (unknown value).
	
## Allocation

|Process |A|B|C|
|---|---|---|---|
|P1|2|1|3|
|P2|2|3|2|
|P3|0|2|1|
|Total|4|6|6|

## Max Need (Μέγ. Απαιτήσεις)

|Process |A|B|C|
|---|---|---|---|
|P1|3|6|8|
	|P2|2|9|8|
|P3|3|2|3|

## Available (Διαθ. Πόροι)

|A|B|C|
|---|---|---|
|3|3|X|


## Remaining Need (Εναπ. Απαιτήσεις)

|Process |A|B|C|
|---|---|---|---|
|P1|1|5|5|
|P2|0|6|6|
|P3|3|0|2|

## Banker's Algorithm (need <= work)

### Note

```
We check need <= work, update the above tables accordingly, and continue iteratively until all processes are exhausted, while keeping at each step what constraint on the value of Y is required.
```

----

For X = 1
```
1,5,5  <= (3,3,1) False
0,6,6  <= (3,3,1) False
3,0,1  <= (3,3,1) True
```

Only P3 manages, so we do `(0,2,1) + (3, 3, Y) = (3,5, Y + 1)` and put it on available.

----

For X = 2
```
1,5,5  <= (3,3,3) False
0,6,6  <= (3,3,3) True
```

P2 manages
```
2,3,2 + (3,3, 1) = (5,6,3)
```

----

For X = 3
```
1,5,5  <= (5,6,6) True
```

Finally P1 manages to complete, therefore the minimum value we search for is 3
```
(0,2,1) + (5,6,6) = (5, 8, 7)
```

# Given the below processes in a real time system, make the according Gantt Chart.

|Process|Period|Execution Time|
|---|---|---|
|P1|60|48|
|P2|15|3|

### Answer

- At time 0ms, P2 has the highest priority since it has the shortest period. P2 executes for 3ms.
- At time 3ms, P2 completes its execution, and P1, which has a longer period, starts its execution.
- At time 15ms, P1 has completed 12ms of its execution, and P2's next release time has not yet arrived.
- At time 27ms, P1 completes its execution (48ms total execution time).
- At time 30ms, P2 starts its second execution since its period is 15ms.
- At time 33ms, P2 completes its second execution, and P1's next release time has not yet arrived.
- This pattern repeats until the end of the 120ms hyperperiod.

| Time | 0ms | 3ms | 15ms| 27ms  | 30ms  | 33ms |
|-------|------|------|------|------|-------|-------|
| P1/P2    | P2   | P1 | P1 | P1  | P2  | P2   |

# Let there be seven periodic processes in a real-time system, each of which has a period of 50ms and a Duration of 7.5ms.

* What is the total utilization for the above set of processes

```
Utilization = Σ(Duration / Period)

7,5ms / 50ms = 0,15

7 * 0,15 = 1,05 -> 105%
```

* It is possible to schedule them with the EDF algorithm

It is only possible if the total utilization is less than or equal to 100%. In our case, the total utilization is 105%, so scheduling with the EDF algorithm is not feasible.


# Let 6 processes A,B,C,D,E,Z that are arriving at time 0 in a multiprocessing system with shared memory having 12 CPUS (c1,..,c12).

* A, B,C have 8 threads that each lasts 30ms (A1 .. A8, B1 .. B8, C1 .. C8)
* D, E, Z have 4 threads that each lasts 45ms (D1 .. D4, E1 .. E4, Z1 .. Z4)

## Show how the threads will execute using space sharing with FCFS logic

|ms|C1|C2|C3|C4|C5|C6|C7|C8|C9|C10|C11|C12|
|---|---|---|---|---|---|---|---|---|---|---|---|----|
|0-30|A1|A2|A3|A4|A5|A6|A7|A8|B1|B2|B3|B4|
|60-90|B5 |B6|B7|B8|C1|C2|C3|C4|C5|C6|C7|C8|
|90-135|D1 |D2|D3|D4|E1|E2|E3|E4|Z1|Z2|Z3|Z4|

## Show how the threads will execute using gang scheduling with quantum 15ms

| ms  | C1  | C2  | C3  | C4  | C5  | C6  | C7  | C8  | C9  | C10 | C11 | C12 |
|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| 0-15   | A1  | A2  | A3  | A4  | A5  | A6  | A7  | A8  |     |     |     |     |
| 15-30  | B1  | B2  | B3  | B4  | B5  | B6  | B7  | B8  |     |     |     |     |
| 30-45  | C1  | C2  | C3  | C4  | C5  | C6  | C7  | C8  |     |     |     |     |
| 45-60  | D1  | D2  | D3  | D4  | E1  | E2  | E3  | E4  | Z1  | Z2  | Z3  | Z4  |
| 60-75   | A1  | A2  | A3  | A4  | A5  | A6  | A7  | A8  |     |     |     |     |
| 75-90  | B1  | B2  | B3  | B4  | B5  | B6  | B7  | B8  |     |     |     |     |
| 90-105  | C1  | C2  | C3  | C4  | C5  | C6  | C7  | C8  |     |     |     |     |
| 105-120 | D1  | D2  | D3  | D4  | E1  | E2  | E3  | E4  | Z1  | Z2  | Z3  | Z4  |
| 120-135  | D1  | D2  | D3  | D4  | E1  | E2  | E3  | E4  | Z1  | Z2  | Z3  | Z4  |

# Is it enough to use a simple TSL mechanism (the one implemented in single cpu systems) to achieve mutual blocking in a multiprocessor shared memory system? How is this handled in modern systems?

In modern multiprocessor systems, a simple TSL (Test-and-Set-Lock) mechanism used in single-CPU systems is not enough to achieve mutual blocking. More advanced synchronization mechanisms like spin locks, mutexes, semaphores, and read-write locks are employed to provide mutual exclusion and synchronization between multiple processors or cores. These mechanisms, along with sophisticated scheduling algorithms, ensure correct and efficient execution of concurrent processes or threads in multiprocessor shared memory systems.

# What is a spin lock

A spin lock is a type of lock used in computer programming to protect shared resources. It uses busy-waiting, where a thread continuously checks for the availability of the lock until it can acquire it. Spin locks are suitable for short critical sections where the expected wait time is brief.

#  What is a smart time scheduler and its use cases compared to a classic implementation of time sharing

A smart time scheduler is an advanced scheduling algorithm that efficiently manages system resources. It offers improved resource utilization, system responsiveness, and overall performance compared to classic time sharing.