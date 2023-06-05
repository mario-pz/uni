
# Karnaugh Map
A [Karnaugh map](https://en.wikipedia.org/wiki/Karnaugh_map), also known as a K-map, is a graphical method used in digital circuit design to simplify Boolean algebra expressions. It provides a visual representation of truth tables and helps in minimizing logic functions.

## Use Case
Its useful for simplifying logic functions and reducing the number of gates required in a circuit. They can help in optimizing the design, reducing complexity, and improving efficiency.

## How to use it
1. Write down the truth table for the logic function.
2. Group the 1's in the truth table into squares or rectangles of size 1, 2, 4, 8, etc., depending on the number of variables. (must be power of 2 groups)
3. Fill in the corresponding cells in the Karnaugh map with the corresponding binary values.
4. Identify adjacent cells in the Karnaugh map that form groups of 1's. These groups represent simplified terms in the logic function.
5. Write down the simplified logic function using the identified groups.

![[karnaugh_map.png]]

## References

1. [Karnaugh map - Wikipedia](https://en.wikipedia.org/wiki/Karnaugh_map)