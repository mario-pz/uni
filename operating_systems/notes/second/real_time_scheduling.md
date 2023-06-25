
# Algorithms

## Rate Monotonic Algorithm (RMA):
RMA is a priority-based scheduling algorithm for periodic tasks, where tasks with shorter periods are assigned higher priorities. It guarantees schedulability under certain conditions.

## Earliest Deadline First (EDF):
It is a dynamic priority scheduling algorithm where tasks are assigned priorities based on their relative deadlines. The task with the closest deadline is given the highest priority. EDF is optimal for scheduling a set of periodic or aperiodic tasks.

## Deadline Monotonic Algorithm (DMA): 
DMA is a priority assignment algorithm similar to RMA but based on relative deadlines rather than periods. Tasks with shorter deadlines are assigned higher priorities.

## Fixed Priority Scheduling (FPS):
In FPS, tasks are assigned fixed priorities based on their criticality. The tasks with higher priorities are executed first, and preemption occurs if a higher-priority task becomes ready.

## Least Laxity First (LLF):
LLF is a dynamic priority scheduling algorithm that assigns priorities based on the task's laxity, which is the difference between the deadline and the remaining execution time. The task with the least laxity is given the highest priority.

# Notes

* Period -> The time it gets executed every time
* Execution -> Time the process will take

# Exercises

Let be the following periodic processes in a real-time system.

|Processes|Period|Execution time|
|---|---|---|
|P1|60ms|48ms|
|P2|15ms|3ms|

Draw how this would be done in a Gantt chart using RMS algorithm, remember to explain each step in detail.

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


