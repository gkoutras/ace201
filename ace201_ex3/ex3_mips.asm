.data

greet:		.asciiz "Welcome\n\n"
printMenu: 	.asciiz "Menu\n\n"
option1:	.asciiz "(1) Create a triangle.\n"
option2:	.asciiz "(2) Check if an integer is even or odd.\n"
option3: 	.asciiz "(3) Enter five integers and check their value multiplied by five.\n"
option4: 	.asciiz "(4) Exit program.\n\n"
enterChoice: 	.asciiz "Please enter your choice (1 - 4): "

error: 		.asciiz "Choose between 1 to 4.\n\n\n"

case1print: 	.asciiz "\nYou Chose to create a triangle.\n\n\n"
case2print: 	.asciiz "\nYou Chose to check if an integer is even or odd.\n\n\n"
case3print: 	.asciiz "\nYou Chose to check the value of five integers multiplied by five.\n\n\n"
case4print: 	.asciiz "\nProgram terminating.\n"

.text

main:		li 	$t0, 1

		li 	$v0, 4
		la 	$a0, greet
		syscall

whileLabel:	beq 	$t0, $zero, afterWhile
		li 	$v0, 4
		la 	$a0, printMenu
		syscall
		li 	$v0, 4
		la 	$a0, option1
		syscall
		li 	$v0, 4
		la 	$a0, option2
		syscall
		li 	$v0, 4
		la 	$a0, option3
		syscall
		li 	$v0, 4
		la 	$a0, option4 
		syscall
		li 	$v0, 4
		la 	$a0, enterChoice
		syscall
	
		li 	$v0, 5
		syscall
		move 	$t1, $v0

		li 	$t2, 1
		beq 	$t1, $t2, case1
		addi 	$t2, $t2, 1
		beq 	$t1, $t2, case2
		addi 	$t2, $t2, 1
		beq 	$t1, $t2, case3
		addi	$t2, $t2, 1
		beq 	$t1, $t2, case4

		li 	$v0, 4
		la 	$a0, error
		syscall
		j 	whileLabel

case1:		li	$v0, 4
		la 	$a0, case1print
		syscall	
		j 	whileLabel
	
case2:		li 	$v0, 4
		la 	$a0, case2print
		syscall
		j 	whileLabel	

case3:		li 	$v0, 4
		la 	$a0, case3print
		syscall	
		j 	whileLabel

case4:		li 	$v0, 4
		la 	$a0, case4print
		syscall	

		addi 	$t0, $t0, -1
		j 	whileLabel

afterWhile:	li 	$v0, 10
		syscall
