_(Note: Octal system(Whole) and Hexadecimal(Division, Multiplication) are outside of the study road map, I've noted them down as proof of concept._

# Binary

## Binary Addition

### Instructions
* Start from the rightmost bits of the two binary numbers.
* Add the corresponding bits along with any carry from the previous position.
* If the sum is 0 or 2, write down the sum and carry 0.
* If the sum is 1 or 3, write down the sum and carry 1.
* Move to the next bit position and repeat steps 2-4 until all bits have been added.

#### Example:
```
  1011    (11 in decimal)
+ 0110    (6 in decimal)
-------
  10001    (17 in decimal)

```

## Binary Subtraction

### Instruction
* Start from the rightmost bits of the two binary numbers.
* Subtract the corresponding bits along with any borrow from the previous position.
* If the difference is 0 or positive, write down the difference and borrow 0.
* If the difference is negative, borrow 1 from the next higher bit position and add 2 to the difference.
* Move to the next bit position and repeat steps 2-4 until all bits have been subtracted.

#### Example:
```
  1011    (11 in decimal)
- 0110    (6 in decimal)
-------
    101    (5 in decimal)
```


### Binary Multiplication
* Start from the rightmost bit of the second binary number.
* If the bit is 1, copy the first binary number and align it to the current bit position.
* If the bit is 0, write down a string of zeros equal to the length of the first binary number.
* Add all the numbers obtained in step 2 or 3.
* Repeat steps 2-4 for each bit in the second binary number.
* Add all the numbers obtained in step 4 to get the final result.

#### Example:
```
  1011  (11 in decimal)
x 0110  (6 in decimal)
------- 
  0000  (0 in decimal)
+ 1011  (11 in decimal)
-------
  11010  (26 in decimal)
```


### Binary Division
* Compare the divisor (the number being divided into) with the dividend (the number being divided).
* If the divisor is greater than or equal to the dividend, subtract the divisor from the dividend.
* Write down a 1 to indicate a successful subtraction, and 0 otherwise.
* Repeat steps 2-3 with the remaining bits of the dividend, aligning the divisor to the current bit position.
* Continue the process until all bits have been divided.

#### Example:
```
   11010    (26 in decimal)
÷  0110    (6 in decimal)
-------
     01     (1 in decimal)
    - 0     (0 in decimal)
-------
     11     (3 in decimal)
```

# Octal Number System

## Octal Addition

### Instruction:
To add two octal numbers together, follow these steps:

1. Start from the rightmost digits of the two octal numbers.
2. Add the corresponding digits.
3. If the sum is less than 8, write down the sum.
4. If the sum is 8 or greater, write down the remainder of the sum divided by 8 and carry over the quotient to the next left digit.
5. Move to the next digit position to the left and repeat steps 2-4 until all digits have been added.
6. If there is a remaining carry at the leftmost digit, include it in the final result.

#### Example:
```
35+46=63
```

## Octal Subtraction

### Instruction:
To subtract one octal number from another, follow these steps:

1. Start from the rightmost digits of the two octal numbers.
2. Subtract the corresponding digits.
3. If the difference is positive or zero, write down the difference.
4. If the difference is negative, borrow 1 from the next left digit, which is equivalent to adding 8 to the current digit.
5. Move to the next digit position to the left and repeat steps 2-4 until all digits have been subtracted.

#### Example:
```
 35
-46
---
-11
```

## Octal Multiplication

### Instruction:
To multiply two octal numbers together, follow these steps:

1. Start from the rightmost digit of the second octal number.
2. Multiply the digit with each digit of the first octal number, starting from the rightmost digit.
3. Write down the products obtained in each step, aligning them according to their positions.
4. If there are multiple products, add them together.
5. Repeat steps 2-4 for each digit of the second octal number.
6. Add all the products obtained to get the final result.

#### Example:
```
  35
x 46
-----

210 (140 in decimal)

140 (80 in decimal)

334 (224 in decimal)
```

## Octal Division

### Instruction:
To divide one octal number by another, follow these steps:

1. Compare the divisor (the number being divided into) with the dividend (the number being divided).
2. If the divisor is greater than or equal to the dividend, subtract the dividend from the divisor.
3. Write down a quotient of 1 to indicate a successful subtraction, and 0 otherwise.
4. Repeat steps 2-3 with the remaining digits of the dividend, aligning the divisor to the current digit position.
5. Continue the process until all digits have been divided.

#### Example:
```
  334 (224 in decimal)
÷ 46 (38 in decimal)
------

7 (7 in decimal)

-0 (0 in decimal)

7 (7 in decimal)
```


# Hexadecimal Number System

## Hexadecimal Addition

### Instruction:
To add two hexadecimal numbers together, follow these steps:

1. Start from the rightmost digits of the two hexadecimal numbers.
2. Add the corresponding digits.
3. If the sum is less than 16, write down the sum.
4. If the sum is 16 or greater, write down the remainder of the sum divided by 16 as the digit and carry over the quotient to the next left digit.
5. Move to the next digit position to the left and repeat steps 2-4 until all digits have been added.
6. If there is a remaining carry at the leftmost digit, include it in the final result.

### Example:
```
  3A
+ 25
----
  5F
```

## Hexadecimal Subtraction

### Instruction:
To subtract one hexadecimal number from another, follow these steps:

1. Start from the rightmost digits of the two hexadecimal numbers.
2. Subtract the corresponding digits.
3. If the difference is positive or zero, write down the difference.
4. If the difference is negative, borrow 1 from the next left digit, which is equivalent to adding 16 to the current digit.
5. Move to the next digit position to the left and repeat steps 2-4 until all digits have been subtracted.

### Example:
```
  3A
- 25
----
  15
```

## Hexadecimal Multiplication

### Instruction:
To multiply two hexadecimal numbers together, follow these steps:

1. Start from the rightmost digit of the second hexadecimal number.
2. Multiply the digit with each digit of the first hexadecimal number, starting from the rightmost digit.
3. Write down the products obtained in each step, aligning them according to their positions.
4. If there are multiple products, add them together.
5. Repeat steps 2-4 for each digit of the second hexadecimal number.
6. Add all the products obtained to get the final result.

### Example:

```
  3A
x 25
-----
7F6 (1,966 in decimal)

3A (58 in decimal)

834 (2,024 in decimal)
```


## Hexadecimal Division

### Instruction:
To divide one hexadecimal number by another, follow these steps:

1. Compare the divisor (the number being divided into) with the dividend (the number being divided).
2. If the divisor is greater than or equal to the dividend, subtract the dividend from the divisor.
3. Write down a quotient of 1 to indicate a successful subtraction, and 0 otherwise.
4. Repeat steps 2-3 with the remaining digits of the dividend, aligning the divisor to the current digit position.
5. Continue the process until all digits have been divided.

### Example:
```
  834 (2,024 in decimal)
÷  25 (37 in decimal)
-----
22  (34 in decimal)
-20 (32 in decimal)
2   (2 in decimal)
```
