#  JK to D Flip Flop

## Step 1: Identify Available and Required Flip-Flops
In this example, we have a JK flip-flop and
we want to convert it to a D flip-flop.

## Step 2: Make Characteristic Table for Required Flip-Flop

|Qn|Qn+1| J | K |
|---|---|---|--------|
|0| 0 | 0 |   X    |
|0| 1| 1 |   X    |
|1| 0| X |   1    |
|1| 1| X |   0    |

## Step 3: Make Excitation Table for Available Flip-Flop

|Qn|D|Qn+1| J | K |
|---|---|---|---|--------|
|0| 0 |0| 0 |   X    |
|0| 1| 1|1 |   X    |
|1| 0| 0|X |   1    |
|1| 1| 1|X |   0    |

## Step 4: Write Boolean Expression for Available Flip-Flop
![[jk_bool_expr.png]]

* J = D
* K = D'

## Step 5: Draw the circuit

![[jk_to_d.png]]
_(pay attention at D *hah gottem*)_


# JK to SR Flip-Flop Conversion

## Step 1: Identify Available and Required Flip-Flops
In this example, we have a JK flip-flop, and we want to convert it to an SR flip-flop.

## Step 2: Make Characteristic Table for Required Flip-Flop

| Qn | Qn+1 | S | R |
|----|------|---|---|
|  0 |   0  | 0 |  X |
|  0 |   1  | 1 |  X |
|  1 |   0  | X |  1 |
|  1 |   1  | X |  0 |

## Step 3: Make Excitation Table for Available Flip-Flop

A sequel of the previous matrix that includes new values

| Qn | Qn+1 | J | K | S | R |
|----|------|---|---|---|---|
|  0 |   0  | 0 | X | 0 | 1 |
|  0 |   1  | 1 | X | 1 | 0 |
|  1 |   0  | X | 1 | 0 | 1 |
|  1 |   1  | X | 0 | 1 | 0 |

## Step 4: Write Boolean Expression for Available Flip-Flop
The boolean expressions for a JK flip-flop are:

S = J
R = K'

## Step 5: Draw the Circuit

![](https://www.electronicshub.org/wp-content/uploads/2015/06/JK-TO-SR.jpg)

# JK to T Flip-Flop Conversion

## Step 1: Identify Available and Required Flip-Flops
In this example, we have a JK flip-flop, and we want to convert it to a T flip-flop.

## Step 2: Make Characteristic Table for Required Flip-Flop

| Qn | Qn+1 | T |
|----|------|---|
|  0 |   0  | 0 |
|  0 |   1  | 1 |
|  1 |   0  | 1 |
|  1 |   1  | 0 |

## Step 3: Make Excitation Table for Available Flip-Flop

| Qn | Qn+1 | J | K | T |
|----|------|---|---|---|
|  0 |   0  | 0 | X | 0 |
|  0 |   1  | 1 | X | 1 |
|  1 |   0  | X | 0 | 1 |
|  1 |   1  | X | 1 | 0 |

## Step 4: Write Boolean Expression for Available Flip-Flop
T = J ⨁ K

## Step 5: Draw the Circuit

![](https://media.geeksforgeeks.org/wp-content/uploads/20200422120839/jktod3-1.png)

# References
* https://www.geeksforgeeks.org/conversion-of-j-k-flip-flop-into-t-flip-flop/