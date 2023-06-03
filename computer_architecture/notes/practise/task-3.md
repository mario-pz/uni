#### Γράψτε πρόγραμμα σε συμβολική γλώσσα MIPS: 
	a) που να εμφανίζει στο παράθυρο Run I/O το χαρακτήρα: a
	b) που να εμφανίζει στο παράθυρο Run I/O τους ακόλουθους χαρακτήρες
	     (χρησιμοποιώντας μόνο τον κωδικό κλήσης 11): a d 
	c) που να εμφανίζει στο παράθυρο Run I/O το ακόλουθο string: 
	      Hello   
	d) που να εμφανίζει στο παράθυρο Run I/O την ακόλουθη σειρά από strings: 
	       Hello TEI 
	e) που να εμφανίζει στο παράθυρο Run I/O τον ακέραιο αριθμό 5
	f) που να διαβάζει ένα αριθμό και να τον εμφανίζει, 
	πχ. (ο υπογραμμισμένος χαρακτήρας είναι αυτός που πληκτρολογεί ο χρήστης).
	 5 5 
	 g) που να διαβάζει από το παράθυρο Run I/O το ονοματεπώνυμό σας, 
	 να το αποθηκεύει στη μνήμη και στη συνέχεια να το εμφανίζει στο παράθυρο
	  Run I/O.

```
.data
hello: .asciiz "\nHello\n"
hellotei: .asciiz "\nHello\nTEI\n"

fullname: .space 25

.text
.globl main
main:
# B
li $a0, 'a'
li $v0, 11
syscall

li $a0, ' '
li $v0, 11
syscall

li $a0, 'd'
li $v0, 11
syscall

# C
li $v0, 4
la $a0, hello
syscall

# D
# 4 code already loaded
la $a0, hellotei
syscall

# E
li $v0, 1
la $a0, 5
syscall

# F
li $v0, 5
syscall
move $a0, $v0

li $v0, 1
syscall

# G
li $v0, 8
la $a0, fullname
li $a1, 25
syscall

li $v0, 4
syscall

li $v0,10 
syscall		# Έξοδος
```

#### Γράψτε πρόγραμμα σε συμβολική γλώσσα MIPS (οι υπογραμμισμένοι χαρακτήρες είναι αυτοί που δίνει ο χρήστης):
a) που να ορίζει στο τμήμα δεδομένων το string `hello` και να εμφανίζει διαδοχικά τον πρώτο και το δεύτερο χαρακτήρα του (με ξεχωριστές εντολές). 4/4 
b) που να διαβάζει ένα ακέραιο x και να εμφανίζει τον x-στό χαρακτήρα του string ‚hello‛. 
c) που να διαβάζει ένα string και να εμφανίζει το δεύτερο χαρακτήρα του, π.χ. hello e 
d) που να υλοποιεί τον εξής κώδικα της C: int x, a = 20, b = 30, c = 15; x = (a+b) - (c + 10);

```
.data
hello: .asciiz "hello\n"

.text
.globl main
main:

li $v0, 11

la $t0, hello
lb $a0, 0($t0) 
syscall

lb $a0, 1($t0) 
syscall

# B
loop:
lb $a0, ($t0) 
beqz $a0, end 

syscall

addi $t0, $t0, 1 
j loop 
end:

# C
# ίδιο με το πάνω

# D
# `int x, a = 20, b = 30, c = 15; x = (a+b) - (c + 10);`
li $v0 , 1

li $t0, 0
li $t1, 20
li $t2, 30
li $t3, 15

add $t0, $t1, $t2
add $t3, $t3, 10
sub $t0, $t0, $t3

la $a0, ($t0)

syscall 


li $v0,10 
syscall
```