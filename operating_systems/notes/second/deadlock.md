A deadlock is a situation in computer science where two or more processes are unable to proceed because each is waiting for the other to release a resource. It's like a "standoff" where none of the processes can make progress, leading to a halt in the system's operation. Deadlocks can occur when processes compete for exclusive access to resources and certain conditions are met, resulting in a deadlock state where no progress can be made without external intervention.

# Coffman conditions
If all four conditions are present simultaneously, a deadlock can occur. To prevent deadlocks, strategies such as resource allocation and scheduling algorithms, deadlock detection, and recovery mechanisms are employed.

## Mutual Exclusion
At least one resource must be held in a non-sharable mode, meaning that only one process can use the resource at any given time. This condition states that a resource cannot be simultaneously shared by multiple processes.

## Hold and Wait
A process must be holding at least one resource while waiting to acquire additional resources held by other processes. In other words, a process must be able to hold onto resources it has already acquired while requesting new resources.

## No Preemption
Resources cannot be forcibly taken away from a process; they must be released voluntarily by the process holding them. This condition implies that once a process acquires a resource, it cannot be forcibly reclaimed until the process releases it.

## Circular Wait

There must be a circular chain of two or more processes, where each process is waiting for a resource held by the next process in the chain. This condition forms a circular dependency among the processes' resource requests.

# Circle Detection

```py
function isCycleDetected(graph):
    initialize visitedSet as an empty set
    initialize recursionStack as an empty set

    for each node v in graph:
        if isNodeInCycle(v, visitedSet, recursionStack):
            return true

    return false

function isNodeInCycle(v, visitedSet, recursionStack):
    if v is in recursionStack:
        return true

    if v is in visitedSet:
        return false

    add v to visitedSet
    add v to recursionStack

    for each neighbor u of v:
        if isNodeInCycle(u, visitedSet, recursionStack):
            return true

    remove v from recursionStack

    return false
```

# Deadlock Algorithms

Deadlock detection algorithms find existing deadlocks, not prevent them. When a deadlock is detected, actions like terminating processes, preemption of resources, or system restart can be taken to resolve the deadlock. To minimize deadlocks, prevention and avoidance techniques like resource scheduling, allocation strategies, and deadlock avoidance algorithms such as the Banker's algorithm can be used.

## Deadlock Detection Algorithm:
This algorithm periodically checks the system for the presence of a deadlock. It examines the resource allocation graph or resource state to identify if a cycle exists, indicating a potential deadlock. Various algorithms, such as the Banker's algorithm and the Ostrich algorithm, can be used for deadlock detection.

```py
function deadlockDetection():
    initialize workList as an empty list
    initialize visitedSet as an empty set

    for each process p in the system:
        if p is not in visitedSet:
            add p to visitedSet
            add p to workList

            while workList is not empty:
                remove process p from the front of workList
                mark p as visited

                if p is holding any resources:
                    for each resource r held by p:
                        let q be the process waiting for r

                        if q is not in visitedSet:
                            add q to visitedSet
                            add q to workList

    if there are any unvisited processes in the system:
        return Deadlock detected
    else:
        return No deadlock detected
****
```

## Resource Allocation Graph Algorithm
This algorithm represents processes and resources as nodes in a graph and uses edges to indicate resource allocation and request relationships. It performs a cycle detection algorithm on the resource allocation graph to identify if a cycle exists. If a cycle is found, it implies a potential deadlock.

```py
function resourceAllocationGraphAlgorithm():
    initialize resourceAllocationGraph as an empty graph

    for each process p in the system:
        add node p to resourceAllocationGraph

    for each resource r in the system:
        add node r to resourceAllocationGraph

    for each process p in the system:
        for each resource r allocated to p:
            add an edge from node p to node r in resourceAllocationGraph

    for each process p in the system:
        for each resource r requested by p:
            add an edge from node r to node p in resourceAllocationGraph

    if a cycle exists in resourceAllocationGraph:
        return Deadlock detected
    else:
        return No deadlock detected

```

## Wait-for Graph Algorithm
This algorithm builds a wait-for graph, where processes are represented as nodes, and edges indicate when one process is waiting for another to release a resource. By analyzing the wait-for graph, cycles can be detected, indicating the presence of a deadlock.

```py
function waitForGraphAlgorithm():
    initialize waitForGraph as an empty graph

    for each process p in the system:
        add node p to waitForGraph

    for each process p in the system:
        for each resource r requested by p:
            let q be the process currently holding resource r

            if q is not null:
                add an edge from node q to node p in waitForGraph

    if a cycle exists in waitForGraph:
        return Deadlock detected
    else:
        return No deadlock detected

```
