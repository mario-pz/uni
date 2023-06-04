
## Exercise 1

### Consider the following Boolean expression:
```
F = (A + B) * C'
```

### Simplify the expression using Boolean algebra laws and theorems.
#### Solution
```
F = AC' + BC'
```

### Create a truth table for the simplified expression.
#### Solution

| A | B | C | F   |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 0 |

## Exercise 2:

### Given the following truth table:

| A | B | C | F |
|---|---|---|---|
| 0 | 0 | 0 | 1 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 1 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 |

### Write the Boolean expression based on the truth table.
#### Solution
```vbnet
 F = A'BC' + AB'C + A'B'C + ABC
```

### Simplify the Boolean expression using Boolean algebra.
#### Solution
```vbnet
F = B ⊕ C
```

## Exercise 3:
### Implement the following Boolean expression using logic gates:
```
F = (A + B') * (C + D')
```

### Write the truth table for the given expression.
#### Solution

| A | B | C | D | F |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 1 | 0 | 1 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 |
| 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 | 1 |

### Simplify the expression using Boolean algebra.
#### Solution

```
F = A + B'C + CD'
```

## Exercise 4:

### Given the Boolean expression:
```
F = A * B + C * (A + B)
```

### Simplify the expression using Boolean algebra laws and theorems.
#### Solution

```
F = A + B
```

## Exercise 5:
### Create a truth table for the following Boolean expression:
```
F = (A + B) * (C + D) * E'
```

### Simplify the expression using Boolean algebra.
#### Solution

```
F = AC + AD + BC + BD
```