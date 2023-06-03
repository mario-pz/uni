.data 
gramma : .asciiz "a"
eyxh: .ascii "Hello \n mphres"


.text 
.globl main
main: 

# Άσκηση 1

li $v0, 4 # Print 
# A system-call that does something based on v0 and a0; in this case, 
# “4” meant print, and it looks for what to print using the memory address stored in a0
la $a0, gramma # 0x43 αλλιώς 
syscall 
# αλλιώς
# li $v0, 'C'

# Άσκηση 2 
la $a0, eyxh 
syscall

# Άσκηση 3 
li $v0, 8 
la $a0, eyxh 
li $a1, 6
syscall

# The last system call uses the number “10”, which means to exit the program
li $v0, 10
syscall 