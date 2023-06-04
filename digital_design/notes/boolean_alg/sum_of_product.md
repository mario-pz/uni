# Sum of Product (SOP)

In Boolean algebra, the sum of products (SOP) is a standard form used to represent logical expressions. It involves expressing a Boolean function as the logical OR (sum) of multiple logical AND (product) terms.

In SOP you may realize that AND gates are being used more than OR gates.

Sum of Product has two forms. 

## Canonical/Standard SOP form
Each minterm is having all the variables in normal or complimented form.

### Example
F = A'B + AB + A'B'

## Minimal SOP form
Each minterm does not have all the variables in normal or complimented form.

### Example
F = A + B'C

## Representation of SOP

To represent a Boolean function in the sum of products form, you follow these steps:
* Identify all the combinations of inputs that produce a True output for the function.
* Write each combination as a logical AND term, where each input variable appears either in its original form or complemented.
* Combine all the logical AND terms using the logical OR operator.

Here's an example with 3 variables (2^3=8 combinations) to illustrate the process:
Suppose we have a Boolean function with three variables, A, B, and C, and its truth table is as follows:

|m|A  |	B	|C	|F |
|---|---|---|---|---|
|m1|0| 0 |0|	1|
|m2|0	|0|	1	|0|
|m3|0	|1|	0	|1|
|m4|0	|1	|1|	1|
|m5|1	|0	|0|	0|
|m6|1	|0	|1	|1|
|m7|1	|1	|0|	0|
|m8 |1|	1|	1|	0|

### Quick Note

```
1 -> A
0 -> A'

if you see Σm you pick those with F=1,
if you see ΣM you pick those with F=0.
m = minimum, M = maximum.

```

_(click [here](./product_of_sum) to see about the Maximum I am talking about)_

To express this function in the sum of products form, we identify the combinations that result in True (1) output:
```
F = A'B'C + A'BC' + AB'C + AB'C'
```

So, the sum of products representation of the given function is,
```
F = A'B'C + A'BC' + AB'C + AB'C'.
```

Note that the terms in the sum of products form are written as the logical AND of the inputs or their complements, and they are combined using the logical OR operator.

Another note most of the time you will be given a function instead of the truth table instead,
for example. 
```
F (A,B,C) = m1 + m3 + m4 + m6
```

Or you can write it as:
```
F (A,B,C) = Σm(1,3,4,6)
```

To find the smallest form of the Boolean function F(A, B, C) given the sum of products expression:
```
F(A, B, C) = A'B'C + A'BC + AB'C' + AB'C
```

we can utilize simplification techniques such as Boolean algebra laws or Karnaugh maps to reduce the number of terms and simplify the expression further.

Let's simplify the expression using Boolean algebra laws:
```
F(A, B, C) = A'B'C + A'BC + AB'C' + AB'C
```

Apply the distributive law to factor out B:
```
F(A, B, C) = B(A'B'C + A'C) + B'(A'BC + AB'C)
```

Using the absorption law, we can simplify further:
```
F(A, B, C) = B(A'C) + B'(A'C)
```

Apply the distributive law again to factor out A'C:
```
F(A, B, C) = (B + B')(A'C)
```

Using the complement law, we have B + B' = 1:
```
F(A, B, C) = 1(A'C)
```

Finally, multiplying by 1 is redundant, so we are left with:
```
F(A, B, C) = A'C
```

Therefore, the smallest form of the Boolean function F(A, B, C) is 
```
F(A, B, C) = A'C.
```

## References
Put the video speed no lower than 1.5x.

![](https://www.youtube.com/watch?v=xnLBbOYYnHM&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=13)

![](https://www.youtube.com/watch?v=NGgNoa0_zns&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=13)