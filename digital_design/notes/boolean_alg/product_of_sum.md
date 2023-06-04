_Its the same thing as SOP, but you take the 0's instead of 1's in the truth table_
# Product of Sum (POS)

In Boolean algebra, the product of sum (POS) is a standard form used to represent logical expressions. It involves expressing a Boolean function as the logical AND (product) of multiple logical OR (sum) terms.]

In POS you may realize that OR gates are being used more than AND gates.

Product of Sum has two forms.

## Canonical/Standard POS form
Each maxterm is having all the variables in normal or complemented form.

### Example
F = (A + B')(A' + B + C')(A' + B' + C)

## Minimal POS form
Each maxterm does not have all the variables in normal or complemented form.

### Example
F = (A' + B + C)(A + B' + C)

## Representation of POS

To represent a Boolean function in the product of sum form, you follow these steps:
- Identify all the combinations of inputs that produce a False output for the function.
- Write each combination as a logical OR term, where each input variable appears either in its original form or complemented.
- Combine all the logical OR terms using the logical AND operator.

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
1 -> A' 
0 -> A

if you see Σm you pick those with F=0, if you see ΣM you pick those with F=1.
m = minimum, M = maximum.
```

_(click [here](./sum_of_product) to see about the Minimum I am talking about)_

To express this function in the product of sum form, we identify the combinations that result in False (0) output:
```
F = (A + B + C')(A + B' + C)(A' + B + C')(A' + B + C)
```

So, the product of sum representation of the given function is,
```
F = (A + B + C')(A + B' + C)(A' + B + C')(A' + B + C)
```

Note that the terms in the product of sum form are written as the logical OR of the inputs or their complements, and they are combined using the logical AND operator.

Another note is that most of the time you will be given a function instead of the truth table. For example,
```
F(A,B,C) = M2 * M5 * M7 * M8
```

Or you can write it as:
```
F(A,B,C) = ΠM(2,5,7,8)
```

To find the smallest form of the Boolean function F(A, B, C) given the product of sum expression:
```
F(A, B, C) = (A + B + C')(A + B' + C)(A' + B + C')(A' + B + C)
```

we can utilize simplification techniques such as Boolean algebra laws or Karnaugh maps to reduce the number of terms and simplify the expression further.

Let's simplify the expression using Boolean algebra laws:
```
F(A, B, C) = (A + B + C')(A + B' + C)(A' + B + C')(A' + B + C)
```

Apply the distributive law to factor out (A + B + C'):
```
F(A, B, C) = (A + B + C')(A + B' + C)(A' + B + C') = (A + B + C')(A(A' + B + C) + B'(A' + B + C)) = (A + B + C')(AA' + AB + AC + B'A' + B'B + B'C)

```

Using the complement law, we have AA' = 0 and B'B = 0:
```
F(A, B, C) = (A + B + C')(AB + AC + B'A' + B'C)
```

Apply the distributive law again to factor out (A + B + C'):
```
F(A, B, C) = (A + B + C')(AB + AC + B'A' + B'C') = A(AB + AC + B'A' + B'C') + B(AB + AC + B'A' + B'C') + C'(AB + AC + B'A' + B'C')
```

Using the absorption law, we can simplify further:
```
F(A, B, C) = A(AB + AC + B'A') + B(AB + AC + B'A') + C'(AB + AC + B'A') = A(B + AC + B'A') + B(AB + AC + B'A') + C'(AB + AC + B'A')
```


Apply the distributive law one more time to factor out (B + AC + B'A'):
```
F(A, B, C) = (A + B)(B + AC + B'A') + C'(AB + AC + B'A')
```

Using the complement law, we have B + B'A' = 1:
```
F(A, B, C) = (A + B)(1 + AC) + C'(AB + AC + B'A')
```

Simplifying further:
```
F(A, B, C) = (A + B)(1) + C'(AB + AC + B'A') = A + B + C'(AB + AC + B'A')
```

Finally, using the distributive law, we have C'(AB + AC + B'A') = C'AB + C'AC + C'B'A':
```
F(A, B, C) = A + B + C'AB + C'AC + C'B'A'
```

Therefore, the smallest form of the Boolean function F(A, B, C) is
```
F(A, B, C) = A + B + C'AB + C'AC + C'B'A'.
```

## References
Put the video speed no lower than 1.5x.

![Part 1](https://www.youtube.com/watch?v=nXsiLPJfDZ4&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=14)

![Part 2](https://www.youtube.com/watch?v=ihTH1C6qCYI&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=15)