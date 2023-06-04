## Binary

### Binary to Decimal: To convert a binary number to decimal, multiply each bit by the corresponding power of 2 and sum the results.

#### Convert binary 1010 to decimal.
```
1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 = 8 + 0 + 2 + 0 = 10 (decimal)
```


### Binary to Octal: Convert the binary number to groups of three bits from right to left, then convert each group to its equivalent octal digit.

#### Convert binary 1101011 to octal.
```
Grouping: 1 101 011
Octal digits: 1 5 3
Result: 1101011 (binary) = 153 (octal)
```


### Binary to Hexadecimal: Convert the binary number to groups of four bits from right to left, then convert each group to its equivalent hexadecimal digit.

#### Convert binary 11011010 to hexadecimal.
```
Grouping: 1101 1010
Hexadecimal digits: D A
Result: 11011010 (binary) = DA (hexadecimal)
```


## Octal
### Octal to Decimal: To convert an octal number to decimal, multiply each digit by the corresponding power of 8 and sum the results.

#### Convert octal 347 to decimal.
```
3 * 8^2 + 4 * 8^1 + 7 * 8^0 = 192 + 32 + 7 = 231 (decimal)
```


### Octal to Binary: Convert each octal digit to its three-bit binary equivalent.

#### Convert octal 27 to binary.
```
2 (octal) = 010 (binary)
7 (octal) = 111 (binary)
Result: 27 (octal) = 010111 (binary)
```


### Octal to Hexadecimal: Convert the octal number to binary, then convert the binary number to hexadecimal.

#### Convert octal 346 to hexadecimal.
```
3 (octal) = 011 (binary)
4 (octal) = 100 (binary)
6 (octal) = 110 (binary)
Result: 346 (octal) = 011100 (binary) = 1C (hexadecimal)
```

## Decimal:

### Decimal to Binary: Divide the decimal number by 2 repeatedly, noting the remainder at each step. The binary representation is obtained by arranging the remainders in reverse order.

#### Convert decimal 42 to binary.

```
Divisions: 42 / 2 = 21 (remainder 0)
               21 / 2 = 10 (remainder 1)
               10 / 2 = 5 (remainder 0)
               5 / 2 = 2 (remainder 1)
               2 / 2 = 1 (remainder 0)
               1 / 2 = 0 (remainder 1)
Result: 42 (decimal) = 101010 (binary)
```


### Decimal to Octal: Divide the decimal number by 8 repeatedly, noting the remainder at each step. The octal representation is obtained by arranging the remainders in reverse order.

#### Convert decimal 189 to octal.
```
Divisions: 189 / 8 = 23 (remainder 5)
               23 / 8 = 2 (remainder 7)
               2 / 8 = 0 (remainder 2)
Result: 189 (decimal) = 275 (octal)
```


### Decimal to Hexadecimal: Divide the decimal number by 16 repeatedly, noting the remainder at each step. The hexadecimal representation is obtained by replacing remainders greater than 9 with corresponding letters (A, B, C, D, E, F).

#### Convert decimal 310 to hexadecimal.
```
    Divisions: 310 / 16 = 19 (remainder 6)
               19 / 16 = 1 (remainder 3)
               1 / 16 = 0 (remainder 1)
    Result: 310 (decimal) = 136 (hexadecimal)
```


## Hexadecimal:

### Hexadecimal to Decimal: Multiply each digit by the corresponding power of 16 and sum the results.

#### Convert hexadecimal 1A5 to decimal.
```
    1 * 16^2 + 10 * 16^1 + 5 * 16^0 = 256 + 160 + 5 = 421 (decimal)
```


### Hexadecimal to Binary: Convert each hexadecimal digit to its four-bit binary equivalent.

#### Convert hexadecimal B7 to binary.
```
    B (hexadecimal) = 1011 (binary)
    7 (hexadecimal) = 0111 (binary)
    Result: B7 (hexadecimal) = 10110111 (binary)
```


### Hexadecimal to Octal: Convert the hexadecimal number to binary, then convert the binary number to octal.

#### Convert hexadecimal E9 to octal.
```
    E (hexadecimal) = 1110 (binary)
    9 (hexadecimal) = 1001 (binary)
    Result: E9 (hexadecimal) = 11101001 (binary) = 351 (octal)
```

