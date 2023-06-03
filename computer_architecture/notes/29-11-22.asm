.data 
here: .space 11
wpa: .byte 0xAA 

.text 
.globl main 
main: 

li $v0, 8
la $a0, here
li $a1, 10
syscall


la $t0, here # temp variable
li $v0, 11 
lb $a0, 0($t0)
syscall 


lb $a0, 2($t0)
syscall


# Alliws 
# li $v0, 11
# lb $a0, here($t0) offset + address
# syscall
