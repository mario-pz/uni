.data 
Variable: .word 10

.text 
la $t1, Variable  
lw $t2, 0($t1) 
li $v0, 1 
move $a0, $t2 
syscall 
li   $v0, 10 
syscall 