.data

.align 2
array: 			.space 20
.align 2
multipliedArray:	.space 20
.align 2
string:			.space 100
.align 2
changedCaseString:	.space 100

greet:		.asciiz "Welcome\n\n"

printMenu: 	.asciiz "Menu\n\n"

option1:	.asciiz "(1) Create a triangle.\n"
option2:	.asciiz "(2) Check if an integer is even or odd.\n"
option3: 	.asciiz "(3) Multiply five integers by four.\n"
option4: 	.asciiz "(4) Enter the case of a string of characters.\n"
option5: 	.asciiz "(5) Exit program.\n\n"
enterChoice: 	.asciiz "Please enter your choice (1 - 5): "

error: 		.asciiz "\nChoose between 1 to 5.\n\n\n"

case1print1: 	.asciiz "\n\nPlease enter integer N (number of lines): "
case1print2: 	.asciiz "\nNumber of elements is: "
case1print3: 	.asciiz "\n\n\n"

case2print1: 	.asciiz "\nPlease enter integer N to be checked: "
case2print2: 	.asciiz "\nThis integer is an odd number.\n\n\n"
case2print3: 	.asciiz "\nThis integer is an even number.\n\n\n"

case3print1:    .asciiz "\nPlease enter the five integers.\n\n"
case3print2:    .asciiz "Integer "
case3print3:    .asciiz ": "
case3print4:    .asciiz " multiplied by 4 equals: "
case3print5:    .asciiz "\n\n"

case4print1:    .asciiz "\nPlease enter the string you want to change the case of.\n\nString: "
case4print2:    .asciiz "\nChanged case string: "
case4print3:    .asciiz "\n\n\n"

case5print:	.asciiz "\nProgram terminating.\n\n"

nextLine:	.asciiz "\n"


.text

main:		li 	$t0, 	1

		li 	$v0, 	4
		la 	$a0, 	greet
		syscall

		whileLabel1:	beq 	$t0, 	$zero, 	afterWhile1

				li 	$v0, 	4
				la 	$a0, 	printMenu
				syscall
				li 	$v0, 	4
				la 	$a0, 	option1
				syscall
				li 	$v0, 	4
				la 	$a0, 	option2
				syscall
				li 	$v0, 	4
				la 	$a0, 	option3
				syscall
				li 	$v0, 	4
				la 	$a0, 	option4 
				syscall
				li 	$v0, 	4
				la 	$a0, 	option5 
				syscall
				li 	$v0, 	4
				la 	$a0, 	enterChoice
				syscall
	
				li 	$v0, 	5
				syscall
				move 	$t1, 	$v0

				li 	$t2, 	1
				beq 	$t1, 	$t2, 	case1
				addi 	$t2, 	$t2, 	1
				beq 	$t1, 	$t2, 	case2
				addi 	$t2, 	$t2, 	1
				beq 	$t1, 	$t2, 	case3
				addi	$t2, 	$t2, 	1
				beq 	$t1, 	$t2, 	case4
				addi	$t2, 	$t2, 	1
				beq 	$t1, 	$t2, 	case5

				li 	$v0, 	4
				la 	$a0, 	error
				syscall

				j 	whileLabel1

				case1:		li	$v0, 	4
						la 	$a0, 	case1print1
						syscall	

						li 	$v0, 	5
						syscall
						move 	$a0, 	$v0

						jal	getTriangle

						move	$t3,	$v0
		
						li	$v0, 	4
						la 	$a0, 	case1print2
						syscall	

						li 	$v0, 	1
						move 	$a0, 	$t3
						syscall

						li	$v0, 	4
						la 	$a0, 	case1print3
						syscall			

						j 	whileLabel1
	
				case2:		li 	$v0, 	4
						la 	$a0, 	case2print1
						syscall

						li 	$v0, 	5
						syscall
						move 	$a1, 	$v0

						jal	checkEvenOrOdd

						move 	$t3, 	$v0

						sltu	$t4, 	$zero,	$t3
						beq	$t4, 	$zero, 	elseLabel1
		
						li 	$v0, 	4
						la 	$a0, 	case2print2
						syscall

						j 	whileLabel1
		
						elseLabel1:	li 	$v0, 	4
								la 	$a0, 	case2print3
								syscall

								j 	whileLabel1	

				case3:		li 	$v0, 	4
						la 	$a0, 	case3print1
						syscall	
		
						move 	$t3, 	$zero
						li	$t4, 	1

						forLoop1:	slti	$t7, 	$t3, 	20
								beq	$t7,	$zero,	afterLoop1
				
								li 	$v0, 	4
								la 	$a0, 	case3print2
								syscall	
	
								li 	$v0, 	1
								move 	$a0, 	$t4
								syscall
								
								li 	$v0, 	4
								la 	$a0, 	case3print3
								syscall	

								li 	$v0,	5
    								syscall
								move 	$t5, 	$v0
    								
								sw    	$t5, 	array($t3)

								addi	$t4, 	$t4, 	1

								addi 	$t3,	$t3, 	4

								j	forLoop1
		
						afterLoop1:	li 	$v0, 	4
								la 	$a0, 	nextLine
								syscall	
						
								move	$t3, 	$zero
								li	$t4, 	1
						
								jal 	multiplyByFour

						forLoop2:	slti	$t7, 	$t3, 	20
								beq	$t7,	$zero,	afterLoop2

								lw	$t6,	multipliedArray($t3)

								li 	$v0, 	4
								la 	$a0, 	case3print2
								syscall

								li 	$v0, 	1
								move 	$a0, 	$t4
								syscall

								li 	$v0, 	4
								la 	$a0, 	case3print4
								syscall	

								li 	$v0, 	1
								move	$a0, 	$t6
								syscall	

								li 	$v0, 	4
								la 	$a0, 	nextLine
								syscall

								addi	$t4, 	$t4, 	1
								
								addi 	$t3,	$t3, 	4
						
								j 	forLoop2

						afterLoop2:	li 	$v0, 	4
								la 	$a0, 	case3print5
								syscall				

								j 	whileLabel1
	
				case4:		li 	$v0, 	4
						la 	$a0, 	case4print1
						syscall

						li 	$v0, 	8
						la	$a0, 	string
						syscall

						la	$a0,	string
						la	$a1,	changedCaseString

						jal 	changeCase

						li 	$v0, 	4
						la 	$a0, 	case4print2
						syscall

						li 	$v0, 	4
						la 	$a0, 	changedCaseString
						syscall

						li 	$v0, 	4
						la 	$a0, 	case4print3
						syscall

						j	whileLabel1

				case5:		li 	$v0, 	4
						la 	$a0, 	case5print
						syscall	

						addi 	$t0, 	$t0, 	-1

						j 	whileLabel1

		afterWhile1:	li 	$v0, 	10
				syscall

getTriangle:	move	$s0, 	$a0
		li 	$s1, 	0
		li	$s4,	0

		forLoop3:	slt	$s5, 	$s0, 	$s1
				bne 	$s5, 	$zero, 	afterLoop3

				li	$s2, 	0

		forLoop4:	slt	$s6, 	$s2, 	$s1
				beq	$s6, 	$zero, 	afterLoop4
		
				addi 	$s3, 	$s2, 	1

				li 	$v0, 	1
				move 	$a0, 	$s3
				syscall

				addi 	$s4, 	$s4, 	1
				addi 	$s2, 	$s2, 	1

				j 	forLoop4

		afterLoop4:	li 	$v0, 	4
				la 	$a0, 	nextLine
				syscall

				addi	$s1, 	$s1, 	1

				j	forLoop3

		afterLoop3:	move 	$v0, 	$s4 
				li	$s4,	0

				jr	$ra


checkEvenOrOdd:	move	$s0, 	$a1
		
		whileLabel2:	slti	$s2, 	$s0, 	2
				bne	$s2, 	$zero, 	afterWhile2
		
				addi	$s0, 	$s0, 	-2
				
				j 	whileLabel2
		
		afterWhile2:	move	$v0, 	$s0

				jr	$ra

multiplyByFour:	move	$s0, 	$zero

		forLoop5:	slti	$s4, 	$s0, 	20
				beq	$s4,	$zero,	afterLoop5

				sw 	$zero,	multipliedArray($s0)
		
				move	$s1, 	$zero

		forLoop6:	slti	$s5, 	$s1, 	16		
				beq	$s5,	$zero,	afterLoop6

				lw	$s2,	array($s0)
				lw	$s3,	multipliedArray($s0)

				add 	$s3,	$s3,	$s2

				sw 	$s3,	multipliedArray($s0)

				addi	$s1, 	$s1, 	4

				j 	forLoop6

		afterLoop6:	addi	$s0, 	$s0, 	4
				
				j	forLoop5

		afterLoop5:	jr	$ra

changeCase:	move	$s6,	$a0
		move	$s7,	$a1
		move	$s0,	$zero

		forLoop7:	slt 	$s3,	$s0,	100
				beq	$s3, 	$zero,	afterLoop7
		
				add	$s4,	$s6,	$s0
				lb	$s2, 	0($s4)

				beq	$s2,	$zero,	afterLoop7
		
				addi	$s0,	$s0,	1		

				j 	forLoop7

		afterLoop7:	li	$s1,	0
				addi	$s0,	$s0, 	-1

		forLoop8:	slt	$t3,	$s1,	$s0	
				beq	$t3,	$zero,	afterLoop8
				
				add	$s4, 	$s6,	$s1
				lb	$s2,	0($s4)

				slti	$s3,	$s2,	65
				bne	$s3,	$zero,	elseLabel2
				
				slt	$s3,	$s2,	91
				beq	$s3,	$zero,	elseLabel2

				addi	$s5, 	$s2,	32
				
				add	$s4, 	$s7,	$s1
				sb	$s5, 	0($s4)

				j	endIf

				elseLabel2:	addi	$s5, 	$s2,	-32
				
						add	$s4, 	$s7,	$s1
						sb	$s5, 	0($s4)

						j	endIf

				endIf:		addi	$s1,	$s1,	1
					
						j	forLoop8

		afterLoop8:	jr	$ra

