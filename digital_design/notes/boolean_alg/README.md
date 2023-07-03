![George Boole](https://upload.wikimedia.org/wikipedia/commons/thumb/c/ce/George_Boole_color.jpg/330px-George_Boole_color.jpg)
_(photo from wikipedia)_

Boolean Algebra is a set of rules used to simplify the given logic expression without changing its functionality bring more optimized and cost efficient hardware.

It is used when number of variables are less.

## Showcase

* OR GATE -> (A + B)
* AND GATE -> (A * B)
* NOT GATE -> A' (not A)
* XOR GATE: A ⊕ B (A XOR B)

![Truth table](https://www.realdigital.org/img/228d4788d26e286b5706f6d644ddee8b.svg)


## Distributive law:

A*(B+C) = AB+AC
A+(BC)= (A+B)(A+C)

A+A'B = A+B
A'+AB = A'+B

## Commutative law:
A + B = B + A 
A * B = B * A

## Associative law

(A * B) C = A(BC)

## Priority
To solve this kind of exercises you need to follow the bellow priority
1. NOT
2. AND
3. OR

## De Morgan's Law

NOT (A+B) = A' * B'
NOT (A * B = A' + B'

## Examples

### Example 1
#### BAC' + B'AC' + BC' 

Y = B<mark style="background: #FFB86CA6;">AC' </mark>+ B'<mark style="background: #FFB86CA6;">AC'</mark> + BC'  (AC' is common between these two literals)
Y = AC'{B + B'} + BC'  (we know from OR operation that True + False = 1 )
Y = <mark style="background: #ABF7F7A6;">AC'</mark> * 1 + BC' (lets put X variable on AC')
Y = X * 1 + BC' (X * 1 = X)
Y  = X + BC' (lets unpack it now)
<mark style="background: #BBFABBA6;">Y = AC' + BC'</mark>

### Example 2
#### AB + AB'

Y = AB + AB' ( We Have 4 possible combinations )
Y = A{B + B'} ( True or False = True )
Y = A * 1 ( True and True = True)
<mark style="background: #BBFABBA6;">Y = A</mark>

##### Truth Table

|A | B | Y = AB +AB' |
|---|---|---|
| 0 | 0 | 0x0 + 0x0 = 0 |
| 0 | 1 | 0x1 + 1x0 = 0 |
| 1 | 0 | 1x0 + 1x1 = 1|
| 1 | 1 | 1x1 + 1x0 = 1 |

As you can see A and Y are the same.

### Example 2
#### Y =  AB + AB'C + AB'C' ( A is common in all three literals )

Y = A {<mark style="background: #FFF3A3A6;">B + B'C</mark> + B'C'} (go to distributive laws, we spot A+A'B = A+B)
Y = A {<mark style="background: #FFF3A3A6;">B</mark> + C + <mark style="background: #FFF3A3A6;">B'C</mark>'} (again, we find the same law.)
Y = A {B + <mark style="background: #FFF3A3A6;">C' + C</mark>} (C' + C = 1)
Y = A { B + 1 }
Y = A * 1
<mark style="background: #BBFABBA6;">Y = A</mark>

### Example 3
#### Y = (A+B+C)(A+B'C)(A+B+C')

Y = (<mark style="background: #ABF7F7A6;">A+B</mark>+C)(A+B'C)(A+B+C'), (X = A+B )
Y = (X+C)(A+B'C)(X+C'), (commutative law)
Y = (X+C)(X+C')(A+B'C), (distributive law, )
Y = (X{C * C'}) (A+B'C)
Y = (X+0)(A+B'+C)
Y  = X(A+B'+C), (time to unpack X) 
Y = (<mark style="background: #FFF3A3A6;">A</mark>+B)(<mark style="background: #FFF3A3A6;">A</mark>+B'+C), (again distributive law)
Y =  A + B * (B' + C), (again distributive law)
Y = A + BB' + BC
Y = A + 0 + BC
<mark style="background: #BBFABBA6;">Y = A+BC</mark>

### Example 4

#### Y = (A+B)(A+B')(A'+B)(A'+B')

Y =<mark style="background: #D2B3FFA6;"> (<mark style="background: #FFF3A3A6;">A</mark>+B)(<mark style="background: #FFF3A3A6;">A</mark>+B')</mark>(<mark style="background: #FFB86CA6;"><mark style="background: #FFF3A3A6;">A'</mark>+B)(<mark style="background: #FFF3A3A6;">A'</mark>+B')</mark>, (distributive law)
Y = (A+BB')(A'+BB')
Y = (A+0)(A'+0)
Y = A * A'
<mark style="background: #BBFABBA6;">Y = 0</mark>

## Redundancy Theorem

The redundancy theorem in Boolean algebra states that in an expression of the form
A + AB or A(A + B), the second term (AB or A + B) is redundant and can be omitted.

(redundant = no longer useful)

### How to detect you can apply Redundancy Theorem
* Three Variables
* Each variable is repeated twice
* One variable is complimented
* Take the complimented variable

### What does complimented mean?
In Boolean algebra, "complemented" means the negation or opposite of a logical value or expression. It involves reversing the truth value from true to false or from false to true.

### Example 1

#### Y = AB+A'C + BC

We got three variables, we have two A's , so for B and C.
A is complimented because we have A and A' while not for B and C.
We shall now take the complimented variable.

<mark style="background: #BBFABBA6;">Y = AB+A'C</mark>
##### Detailed version
Y = AB + A'C + BC * 1
Y = AB+A'C+ BC * ( A + A' )
Y = AB + A'C + ABC + A'BC
Y = <mark style="background: #D2B3FFA6;">AB</mark> + <mark style="background: #FFF3A3A6;">A'C</mark> + <mark style="background: #D2B3FFA6;">AB</mark>C + <mark style="background: #FFF3A3A6;">A'C</mark>B
Y  = AB{1 + C} A'C{1 +B}
Y  = AB{1} A'C{1}
<mark style="background: #BBFABBA6;">Y = AB + A'C</mark>


### Example 2

#### Y = AB+BC' + AC
We got three variables, each variable is repeated twice, C is complimented whereas A and B are not. We now take the complimented variable and omit AB.

<mark style="background: #BBFABBA6;">Y = BC' + AC</mark>

### Example 3 (Trap)
#### Y = AB' + BC + AC
 
We got three variables, each variable is repeated twice , BUT! 

By observing the expression, we can see that BC is repeated. Therefore, we can simplify the expression as:

<mark style="background: #BBFABBA6;">Y = AB' + AC</mark>

### Example 4

#### Y = (A+B)(A'+C)(B+C)

We got three variables, each variable is repeated twice, A is complimented whereas B and C are not. We now take the complimented variable and omit (B+C)

<mark style="background: #BBFABBA6;">Y = (A+B)(A'+C)</mark>

### Example 5

#### Y = (A+B)(B'+C)(A+C)

We got three variables, each variable is repeated twice, B is complimented whereas A and C are not. We now take the complimented variable and omit (A+C)

<mark style="background: #BBFABBA6;">Y = (A+B)(B'+C)</mark>

### Example 6

#### Y = (A'+B')(A+C')(B'+C')

This is slightly different, A is the only one that is not complimented, 
when more than one variable are complimented we have to check the one that's not.
We also omitting (B'+C').

<mark style="background: #BBFABBA6;">Y = (A'+B')(A+C')</mark>

## How to get good on Boolean Algebra

### Understand the Basics
Start by familiarizing yourself with the basic concepts of Boolean algebra, including logic gates, truth tables, Boolean operators (AND, OR, NOT), and Boolean expressions.
Learn the laws and theorems of Boolean algebra, such as the commutative, associative, distributive, and De Morgan's laws.

### Practice Truth Tables
Truth tables are an essential tool for understanding Boolean operations and verifying the correctness of your logic. Practice creating truth tables for different logic gates and expressions. Work on converting truth tables to Boolean expressions and vice versa.

### Simplify Boolean Expressions
Learn techniques to simplify complex Boolean expressions using Boolean algebra laws and theorems.
Practice simplifying expressions using methods like Karnaugh maps and Boolean algebra manipulation rules.

### Master Logic Gates
Understand the different types of logic gates (AND, OR, NOT, XOR, etc.) and their behavior.
Learn how to represent logic gates using Boolean expressions and truth tables.
Practice analyzing and designing combinational circuits using logic gates.

### Design Sequential Circuits
Study sequential circuits, including flip-flops, registers, counters, and state machines.
Learn how to design sequential circuits using Boolean algebra and state diagrams.
Practice building sequential circuits and verifying their functionality.

### Solve Practice Problems
Regularly solve practice problems to reinforce your understanding of Boolean algebra.
Start with simple problems and gradually move on to more complex ones.
Look for resources like textbooks, online tutorials, and problem-solving websites that provide a variety of practice problems.

### Utilize Digital Design Tools:
Make use of digital design software or simulators that allow you to experiment with logic gates, Boolean expressions, and circuit designs.

## References
Put the video speed no lower than 1.5x.

![](https://www.youtube.com/watch?v=WW-NPtIzHwk&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=7)

![](https://www.youtube.com/watch?v=OjWmVCG8PLA&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=8)

![](https://www.youtube.com/watch?v=k04ksfLBuak&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=9)

![](https://www.youtube.com/watch?v=uPBYaCarXDM&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=10)

![](https://www.youtube.com/watch?v=3pbH9IhxwOg&list=PLBlnK6fEyqRjMH3mWf6kwqiTbT798eAOm&index=11)
