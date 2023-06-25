# Notes

```
Allocation + Max = Need

Safety Algorithm -> need <= work

w = w + alloc
```


# Algorithms

## Banker's Algorithm

* if request <= need
* if request <= available
* alloc = alloc + request
* available = available - 


# Exercises
Three processes are competing for 3 resources A,B,C. 
Given the below table

## Allocated Resources

* What resources have already been allocated  in every process

| |A|B|C|
|---|---|---|---|
|P1|2|1|3|
|P2|2|3|2|
|P3|0|2|1|

## Max Demands

* What are the max resources each kind of process can request

| |A|B|C|
|---|---|---|---|
|P1|3|6|8|
	|P2|2|9|8|
|P3|3|2|3|

## Resources available

| |A|B|C|
|---|---|---|---|
|P1|3|3|X|

* what resources are left from each kind

```
A: Available - Allocated = 3 - 2 - 2 - 0 = -1
B: Available - Allocated = 3 - 1 - 3 - 2 = -3
C: Available - Allocated = X - 3 - 2 - 1 = X - 6

(-1, -3, X - 6)
```

### Exercise
Find the minimum value of X that puts the above on a safe state using the Banker's algorithm. Make a valid reason.

#### Answer


```
A: 2 + 2 + 0 = 4
B: 1 + 3 + 2 = 6
C: 3 + 2 + 1 = 6

P1: Max demand - Allocated resources = (3, 6, 8) - (2, 1, 3) = (1, 5, 5)
P2: (2, 9, 8) - (2, 3, 2) = (0, 6, 6)
P3: (3, 2, 3) - (0, 2, 1) = (3, 0, 2)

A: 3 - 4 = -1
B: 3 - 6 = -3
C: X - 6 = X - 6

P1: (1, 5, 5) - (-1, -3, X - 6) = (2, 8, 5 - X)
P2: (0, 6, 6) - (-1, -3, X - 6) = (1, 9, 6 - X)
P3: (3, 0, 2) - (-1, -3, X - 6) = (4, 3, 2 - X)


Lets start by assuming X = 7

(A, B,  C)
(2, 8, 5 - X) <= (-1, -3, X - 6)
(2, 8, 5 - 7) <= (-1, -3, 7 - 6)
(2, 8, -2) <= (-1, -3,  -1)

C resource is not available

For P2: (1, 9, 6 - 7) <= (-1, -3, 1)
This simplifies to (1, 9, -1) <= (-1, -3, 1), which is satisfied.

FFor P3: (4, 3, 2 - 7) <= (-1, -3, 1)
This simplifies to (4, 3, -5) <= (-1, -3, 1), which is not satisfied since we need -5 of resource C, which is not available.

---------- 

Lets start by assuming X = 8

For P1: (2, 8, 5 - 8) <= (-1, -3, 2)
This simplifies to (2, 8, -3) <= (-1, -3, 2), which is satisfied.

For P2: (1, 9, 6 - 8) <= (-1, -3, 2)
This simplifies to (1, 9, -2) <= (-1, -3, 2), which is satisfied.

For P3: (4, 3, 2 - 8) <= (-1, -3, 2)
This simplifies to (4, 3, -6) <= (-1, -3, 2), which is not satisfied since we need -6 of resource C, which is not available.

```

The processes P1 and P2 can proceed but P3 cannot. Therefore the system is in unsafe state and any allocation of resources may potentially lead to a deadlock


# References
* ![](https://youtu.be/2V2FfP_olaA)