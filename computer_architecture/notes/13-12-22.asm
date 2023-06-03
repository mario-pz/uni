.data 
string_data: .space 17

.text 
.globl main 

main: 

li $v0, 8
la $a0, string_data 
li $a1, 17 
syscall 

la $t0, string_data
li $t1, 0

loop:
lb $t2, 0($t0)
bnez $t2, loop
addi $t1, $t1, 1 
addi $t0, $t0, 1

li $v0, 1
sub $t1, $t1 2 # remove null operator and enter
move $a0, $t1 
syscall 

# Reverse show string
loop2:
li $v0, 11 
lb $a0, 0($t0) 
subi $t1, $t1, 1
subi $t0, $t0, 1 
bnez $t1, loop2 
syscall

li $v0, 10 
syscall