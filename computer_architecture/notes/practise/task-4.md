
### 1

#### Πρόγραμμα που να διαβάζει ένα ακέραιο και να εμφανίζει το μήνυμα
«Zero» ή το μήνυμα «Non Zero». Χρησιμοποιήστε ως αφετηρία τον
ακόλουθο κώδικα C:
scanf(‚%d‛, &n);
if (n==0) goto 1;
printf(‚Non Zero‛);
goto 2:
1: printf(‚Zero‛);
2: <<<..
```
.data 
msg: .asciiz "Dose akeraio:"
iszero: .asciiz "Mhden\n"
nonzero: .asciiz "Oxi mhden\n" 

.text 
.globl main 

main:
la $a0, msg
li $v0, 4
syscall

li $v0, 5
syscall

move $t1, $v0
 
beqz $t1, zero
# Else
la $a0, nonzero
j exit

zero:
  la $a0, iszero
  j exit  
  
exit:
li $v0, 4
syscall

li $v0, 10
syscall


```


####  Πρόγραμμα που να διαβάζει ένα ακέραιο και να εμφανίζει το μήνυμα
«Positive» ή το μήνυμα «Non Positive». Χρησιμοποιήστε ως αφετηρία
τον ακόλουθο κώδικα C:
scanf(‚%d‛, &n);
if (n>=0) goto 1;
printf(‚Non Positive‛);
goto 2:
1: printf(‚Positive‛);
2: <<<

```
li $v0, 5 # system call code for reading an integer 
syscall 
move $t0, $v0 # move input to $t0 slt $t1, $t0, 0 # set $t1 to 1 if $t0 < 0, 0 otherwise 
beq $t1, 1, non_positive # branch to non_positive label if $t1 = 1 la $a0, positive # load address of "Positive" string 

li $v0, 4 # system call code for printing a string syscall j end non_positive: 
la $a0, non_positive # load address of "Non Positive" string
li $v0, 4 # system call code for printing a string syscall

end:
```


#### Πρόγραμμα που να εμφανίζει 5 φορές το χαρακτήρα *

```
.text 
.globl main
main: li $a0, 42 # ascii value of '*' 
li $t0, 5 # number of times to print loop:
li $v0, 11 # system call code for printing a character 
syscall 
addi $t0, $t0, -1 # decrement t0 by 1 bne $t0, 0, loop # if t0 is not zero, jump to loop li $v0, 10 # system call code for exiting the program syscall
```

#### Πρόγραμμα που να διαβάζει ένα ακέραιο x και να εμφανίζει x φορές το χαρακτήρα *.

```
.text
.globl main

main:
    li $v0, 5   # system call code for reading an integer
    syscall
    move $t0, $v0 # move the input to $t0
    li $a0, 42  # ascii value of '*'

loop:
    li $v0, 11  # system call code for printing a character
    syscall
    addi $t0, $t0, -1  # decrement t0 by 1
    bne $t0, 0, loop  # if t0 is not zero, jump to loop

li $v0, 10   # system call code for exiting the program
syscall

```
 

#### Πρόγραμμα που να εμφανίζει 5 γραμμές, κάθε μία από τις οποίες να έχει 4 φορές το χαρακτήρα *.

```
.text
.globl main

main:
    li $t0, 4    # number of times to print '*'
    li $t1, 5    # number of lines to print
    li $a0, 42   # ascii value of '*'

line_loop:
    li $t2, 4    # number of times to print '*'
    li $v0, 11   # system call code for printing a character

star_loop:
    syscall
    addi $t2, $t2, -1  # decrement t2 by 1
    bne $t2, 0, star_loop  # if t2 is not zero, jump to star_loop

    li $a0, 10   # ascii value of '\n' (newline)
    syscall
    addi $t1, $t1, -1  # decrement t1 by 1
    bne $t1, 0, line_loop  # if t1 is not zero, jump to line_loop

li $v0, 10   # system call code for exiting the program
syscall

```


#### Πρόγραμμα που να διαβάζει δύο ακεραίους x, y και να εμφανίζει x γραμμές, κάθε μία από τις οποίες θα έχει y φορές το χαρακτήρα *. 

```
.text
.globl main

main:
    li $v0, 5    # system call code for reading an integer
    syscall
    move $t0, $v0 # move input to $t0 (x)
    li $v0, 5    # system call code for reading an integer
    syscall
    move $t1, $v0 # move input to $t1 (y)
    li $a0, 42   # ascii value of '*'

line_loop:
    li $t2, $t1  # number of times to print '*'
    li $v0, 11   # system call code for printing a character

star_loop:
    syscall
    addi $t2, $t2, -1  # decrement t2 by 1
    bne $t2, 0, star_loop  # if t2 is not zero, jump to star_loop

    li $a0, 10   # ascii value of '\n' (newline)
    syscall
    addi $t0, $t0, -1  # decrement t0 by 1
    bne $t0, 0, line_loop  # if t0 is not zero, jump to line_loop

li $v0, 10   # system call code for exiting the program
syscall

```


### 2

#### Πρόγραμμα που να διαβάζει ένα string μήκους το πολύ 15 χαρακτήρων και να εμφανίζει το πλήθος των χαρακτήρων που διαβάστηκαν (Yπόδειξη: πρέπει να σαρώσετε το string μέχρι να βρείτε το χαρακτήρα με ascii κωδικό 0). 
```
.data
str: .space 15  # reserve space for the string

.text
.globl main

main:
    la $a0, str    # load address of the string
    li $a1, 15     # maximum number of characters
    li $v0, 8      # system call code for reading a string
    syscall

    li $t0, 0      # initialize a counter to 0

count_loop:
    lb $t1, 0($a0) # load the current character
    addi $a0, $a0, 1  # increment the address
    beq $t1, 0, end_loop  # if the current character is 0, exit the loop
    addi $t0, $t0, 1  # increment the counter
    j count_loop

end_loop:
    li $v0, 1      # system call code for printing an integer
    move $a0, $t0   # move the counter to $a0
    syscall
    li $v0, 10     # system call code for exiting the program
    syscall

```
#### Πρόγραμμα που να διαβάζει ένα string μήκους το πολύ 15 χαρακτήρων και να το εμφανίζει αντίστροφα. (πρώτα ο τελευταίος χαρακτήρας,μετά ο προτελευταίος κλπ. Προφανής υπόδειξη: Χρησιμοποιήστε την προηγούμενη άσκηση). 

```
.data
str: .space 15  # reserve space for the string

.text
.globl main

main:
    la $a0, str    # load address of the string
    li $a1, 15     # maximum number of characters
    li $v0, 8      # system call code for reading a string
    syscall

    la $t0, str    # load address of the string
    addi $t1, $t0, 15  # set the end pointer to the last character

print_loop:
    lb $t2, 0($t1) # load the current character
    beqz $t2, end_loop # if the current character is 0, exit the loop
    li $v0, 4      # system call code for printing a character
    move $a0, $t2   # move the current character to $a0
    syscall
    addi $t1, $t1, -1  # decrement the end pointer
    j print_loop

end_loop:
    li $v0, 10     # system call code for exiting the program
    syscall

```


#### Πρόγραμμα που να υλοποιεί τον εξής κώδικα της C:
```
main() { 
	int i, size = 10, sum; 
	int arr[10] = {1, 15, 0, -3, 99, 48, -17, -9, 20, 15}; sum = 0;
	for (i = 0; i<size; i++){
		sum += arr[i];
	}
	return 0;
}
```


```
.data
arr: .word 1, 15, 0, -3, 99, 48, -17, -9, 20, 15  # initialize array
size: .word 10  # size of array

.text
.globl main

main:
    la $t0, arr    # load address of array
    lw $t1, size   # load size of array
    li $t2, 0      # initialize sum to 0

loop:
    lw $t3, 0($t0) # load current element of array
    add $t2, $t2, $t3   # add current element to sum
    addi $t0, $t0, 4    # increment array pointer
    addi $t1, $t1, -1   # decrement size
    bne $t1, 0, loop   # if size is not zero, jump to loop

li $v0, 10     # system call code for exiting the program
syscall

```


#### Πρόγραμμα που να αποθηκεύει τη τιμή 0xabcd στις θέσεις μνήμης first,second,third,fourth, με τη χρήση βρόχου.
```
.data
first: .word 0
second: .word 0
third: .word 0
fourth: .word 0

.text
.globl main

main:
    li $t0, 4    # number of times to store the value
    li $t1, 0xabcd  # value to store
    la $t2, first    # load address of first location

loop:
    sw $t1, 0($t2)    # store the value at the current location
    addi $t2, $t2, 4  # increment the address
    addi $t0, $t0, -1  # decrement the counter
    bne $t0, 0, loop  # if the counter is not zero, jump to loop

li $v0, 10   # system call code for exiting the program
syscall
```

#### Πρόγραμμα που να διαβάζει με τη λειτουργία 12 άγνωστο πλήθος χαρακτήρων που αντιστοιχούν σε ψηφία και να εμφανίζει τον ακέραιο που αντιστοιχεί σε αυτά (π.χ. αν διαβάσει ‘3’, ‘4’, ‘7’, να εμφανίσει 347). Ο τερματισμός των ψηφίων γίνεται με το enter.

```
.data
str: .space 10  # reserve space for the string

.text
.globl main

main:
    la $a0, str    # load address of the string
    li $v0, 12     # system call code for reading a character

read_loop:
    syscall
    move $t0, $v0  # move current character to $t0
    beq $t0, 10, end_loop  # if the current character is '\n', exit the loop
    sub $t0, $t0, 48    # convert character to integer
    mul $t1, $t1, 10    # shift existing result by 10
    add $t1, $t1, $t0   # add current digit to result
    j read_loop

end_loop:
    li $v0, 1      # system call code for printing an integer
    move $a0, $t1   # move the result to $a0
    syscall
    li $v0, 10     # system call code for exiting the program
    syscall

```