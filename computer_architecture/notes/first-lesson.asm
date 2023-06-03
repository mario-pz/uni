.data # τμήμα δεδομένων
str: .asciiz "Hello World\n"

paparoupas: .byte 55

.text # τμήμα κώδικα

.globl main

main: #label
li $v0,4 # κωδικός 4 για να εμφανιστεί η σειρά χαρακτήρων του str
la $a0,str # φόρτωσε τη διεύθυνση του str στον $a0
syscall # κλήση συστήματος
li $v0,10 # κωδικός 10 για τερματισμό του πργρ.
syscall # κλήση συστήματος

# npi!