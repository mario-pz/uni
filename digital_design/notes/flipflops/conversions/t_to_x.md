# T flip flop to D Flip Flop

## Step 1: Identify Available and Required Flip-Flops
In this example, we have a T flip-flop and
we want to convert it to a D flip-flop.

## Step 2: Make Characteristic Table for Required Flip-Flop

|Qn|D|Qn+1| T|
|---|---|---|---|
|0|0|0|0|
|0|1|1|1|
|1|0|0|1|
|1|1| 1|0|

## Step 3: Make Excitation Table for Available Flip-Flop

|Qn|D|Qn+1| T|
|---|---|---|---|
|0|0|0|0|
|0|1|1|<span style="background:#d4b106">1</span>|
|1|0|0|<span style="background:#d4b106">1</span>|
|1|1| 1|0|

There is no need to make a karnaugh map on this cause its very simple, as you can see T is high only when Qn and D are having odd number of ones. It is simply the XOR combination of Qn and D.

## Step 4: Write Boolean Expression for Available Flip-Flop
T = Qn ⊕ D

## Step 5: Draw the circuit

![[tff_to_dff.png]]

# T to SR Flip-Flop Conversion

## Step 1: Identify Available and Required Flip-Flops
In this example, we have a T flip-flop, and we want to convert it to an SR flip-flop.

## Step 2: Make Characteristic Table for Required Flip-Flop

| Qn | Qn+1 | S | R |
|----|------|---|---|
|  0 |   0  | 0 |  X |
|  0 |   1  | 1 |  X |
|  1 |   0  | X |  1 |
|  1 |   1  | X |  0 |

## Step 3: Make Excitation Table for Available Flip-Flop

| Qn | Qn+1 | T | S | R |
|----|------|---|---|---|
|  0 |   0  | 0 | 0 | 1 |
|  0 |   1  | 1 | 1 | 0 |
|  1 |   0  | 0 | X | 1 |
|  1 |   1  | 1 | X | 0 |

## Step 4: Write Boolean Expression for Available Flip-Flop
The boolean expressions for an SR flip-flop are:

S = T
R = T'

## Step 5: Draw the Circuit

A link to the circuit being used

# T to JK Flip-Flop Conversion

## Step 1: Identify Available and Required Flip-Flops
In this example, we have a T flip-flop, and we want to convert it to a JK flip-flop.

## Step 2: Make Characteristic Table for Required Flip-Flop

| Qn | Qn+1 | J | K |
|----|------|---|---|
|  0 |   0  | 0 |  X |
|  0 |   1  | X |  1 |
|  1 |   0  | 1 |  X |
|  1 |   1  | X |  0 |

## Step 3: Make Excitation Table for Available Flip-Flop

| Qn | Qn+1 | T | J | K |
|----|------|---|---|---|
|  0 |   0  | 0 | 0 | X |
|  0 |   1  | 1 | X | 1 |
|  1 |   0  | 0 | 1 | X |
|  1 |   1  | 1 | X | 0 |

## Step 4: Write Boolean Expression for Available Flip-Flop
The boolean expressions for a JK flip-flop are:

J = T
K = T'

## Step 5: Draw the Circuit

A link to the circuit being used
