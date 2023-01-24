		.data

		.align 	2
temp:		.space 	100

map:		.ascii 	"I.IIIIIIIIIIIIIIIIIIII....I....I.......I.IIII.IIIII.I.I.III.I.II.I.....I..I..I.....II.I.III.II...II.I.IIII...I...III.I...I...IIIIII.IIIII.III.III.II.............I.I...IIIIIIIIIIIIIIII.I.III@...............I..IIIIIIIIIIIIIIIIIIIIIII"

str1:		.asciiz	"Welcome to the Labyrinth.\n"
str2:		.asciiz	"\nMove by pressing W, A, S, D or press E for the optimal solution.\nPlease type a command key: "

str3:		.asciiz	"\n\nYou cannot walk through walls.\n"
str4:		.asciiz	"\n# marks the most optimal path.\n"
str5:		.asciiz	"\n\nType between your options.\n"
str9:		.asciiz	"\n\nLeaving so soon?\n"

str6:		.asciiz	"\nWinner Winner Chicken Dinner!\n"

str7:		.asciiz "\nLabyrinth:\n\n"
str8:		.asciiz "\n"

cdata:		.word	0
cflag:		.word	0

startX:		.word 	1
w:		.word	21
h:		.word	11
totalElements:	.word	231

		.text

main:		addi	$sp,	$sp,	-32
		sw	$s0,	0($sp)
		sw	$s1,	4($sp)
		sw	$s2,	8($sp)
		sw	$s3,	12($sp)
		sw	$s4,	16($sp)
		sw	$s5,	20($sp)
		sw	$s6,	24($sp)
		sw	$s7,	28($sp)

		lw 	$s0, 	startX
		lw 	$s4, 	w
		
		li 	$v0, 	4
		la 	$a0, 	str1
		syscall
		
		move	$s1, 	$s0

		jal	printLabyrinth

		whileLabel1:	la	$s7,	map
				add	$s6,	$s7,	$s1
				lb	$s2,	0($s6)			

				li	$t0,	64
				beq 	$s2, 	$t0, 	afterWhile1
				li	$t0,	35
				beq 	$s2, 	$t0, 	afterWhile1

				li 	$v0, 	4
				la 	$a0, 	str2
				syscall

				keyWait:	lw      $t0, 	0xffff0000
                				andi    $t0, 	$t0, 	1
                				beq     $t0, 	$zero, 	keyWait
				
				lbu     $a0, 	0xffff0004
				move 	$s3,	$a0

				li	$t0,	87
				beq 	$s3, 	$t0, 	case87
				li	$t0,	65
				beq 	$s3, 	$t0, 	case65
				li	$t0,	83
				beq 	$s3, 	$t0, 	case83
				li	$t0,	68
				beq 	$s3, 	$t0, 	case68
				li	$t0,	69
				beq 	$s3, 	$t0, 	case69

				li 	$v0, 	4
				la 	$a0, 	str5
				syscall
	
				j	whileLabel1

				case87:		bne	$s1,	$s0,	elseLabel
						
						li 	$v0, 	4
						la 	$a0, 	str9
						syscall
						
						j 	whileLabel1

						elseLabel:	sub	$s3,	$s1,	$s4
	
								la	$s7,	map
								add	$s6,	$s7,	$s3
								lb	$s2,	0($s6)	

								li	$t0,	73

								bne	$s2,	$t0,	elseLabel1

								li 	$v0, 	4
								la 	$a0, 	str3
								syscall

								j	whileLabel1

								elseLabel1:	sub	$s1,	$s1,	$s4

										jal	printLabyrinth
										j	whileLabel1

				case65:		addi	$s3,	$s1,	-1
	
						la	$s7,	map
						add	$s6,	$s7,	$s3
						lb	$s2,	0($s6)	

						li	$t0,	73

						bne	$s2,	$t0,	elseLabel2

						li 	$v0, 	4
						la 	$a0, 	str3
						syscall

						j	whileLabel1

						elseLabel2:	addi	$s1,	$s1,	-1

								jal	printLabyrinth
								j	whileLabel1

				case83:		add	$s3,	$s1,	$s4
	
						la	$s7,	map
						add	$s6,	$s7,	$s3
						lb	$s2,	0($s6)	

						li	$t0,	73

						bne	$s2,	$t0,	elseLabel3

						li 	$v0, 	4
						la 	$a0, 	str3
						syscall

						j	whileLabel1

						elseLabel3:	add	$s1,	$s1,	$s4

								jal	printLabyrinth
								j	whileLabel1

				case68:		addi	$s3,	$s1,	1
	
						la	$s7,	map
						add	$s6,	$s7,	$s3
						lb	$s2,	0($s6)	
	
						li	$t0,	73
	
						bne	$s2,	$t0,	elseLabel4

						li 	$v0, 	4
						la 	$a0, 	str3
						syscall

						j	whileLabel1

						elseLabel4:	addi	$s1,	$s1,	1

								jal	printLabyrinth
								j	whileLabel1

				case69:		move	$a0,	$s0
					
						jal	makeMove

						jal	printLabyrinth

						li 	$v1, 	4
						la 	$a0, 	str4
						syscall

						j	whileLabel1

		afterWhile1:	la	$s7,	map
				add	$s6,	$s7,	$s1
				lb	$s2,	0($s6)

				li	$t0,	64
				beq	$s2,	$t0,	next

				afterNext:	lw	$s0,	0($sp)
						lw	$s1,	4($sp)
						lw	$s2,	8($sp)
						lw	$s3,	12($sp)
						lw	$s4,	16($sp)
						lw	$s5,	20($sp)
						lw	$s6,	24($sp)
						lw	$s7,	28($sp)
						addi	$sp,	$sp,	32

						li 	$v0, 	10
						syscall

				next:	li 	$v0, 	4
					la 	$a0, 	str6
					syscall

					j	afterNext
printLabyrinth:	lw	$t4,	w
		lw	$t5,	h
		move 	$t9,	$s1
		
		la	$t7,	temp
		
		move	$t0,	$zero						
		li	$t1,	100000						
										
		uSleep:	bge	$t0,	$t1,	afterFunction								
				addi	$t0,	$t0,	1									
				j	uSleep
										
		afterFunction:	move	$t0,	$zero
				move	$t2,	$zero						
		
		li 	$v0, 	4
		la 	$a0, 	str7		
		syscall

		forLoop1:	bge	$t0,	$t5,	afterLoop1
		
				move	$t1,	$zero

				forLoop2:	bge	$t1,	$t4,	afterLoop2
						bne	$t2,	$t9,	elseLabel5

						li	$t3,	80

						la	$t7, 	temp
						add	$t6,	$t7,	$t1
						sb	$t3,	0($t6)

						j	afterCondition1

						elseLabel5:		la	$t8, 	map
									add	$t6,	$t8,	$t2
									lb	$t3,	0($t6)

									la	$t7, 	temp
									add	$t6,	$t7,	$t1
									sb	$t3,	0($t6)

									j	afterCondition1

						afterCondition1:	addi	$t2,	$t2,	1
				
									addi	$t1,	$t1,	1

									j	forLoop2

				afterLoop2:	addi	$t1,	$t1,	1

						add	$t6,	$t7,	$t1
						sb	$zero,	0($t6)

						li 	$v0, 	4
						la 	$a0, 	temp		
						syscall

						li 	$v0, 	4
						la 	$a0, 	str8			
						syscall

						addi 	$t0,	$t0,	1

						j	forLoop1

		afterLoop1:	jr	$ra

makeMove:	addi	$sp,	$sp,	-8
		sw	$s0,	0($sp)
		sw	$ra,	4($sp)

		lw	$t4,	totalElements
		move 	$s0,	$a0

		bge 	$s0,	$zero,	afterCondition2

		move	$v1,	$zero

		afterCondition2:	blt	$s0,	$t4,	afterCondition3

					move	$v1,	$zero

		afterCondition3:	la	$t1,	map
					add	$t3,	$t1,	$s0
					lb	$t5,	0($t3)

					li	$t0,	46
					bne	$t5,	$t0,	elseLabel6

					li	$t6,	42

					j	afterCondition4
	
					elseLabel6:		li 	$t0,	80
								bne	$t5,	$t0,	elseLabel7

								li 	$t6,	80

					afterCondition4:	la	$t1,	map
								add	$t3,	$t1,	$s0
								sb	$t6,	0($t3)

								jal	printLabyrinth

					addi	$a0,	$s0,	1

					jal	makeMove
					lw	$ra,	4($sp)

					move	$t7,	$v1
					li	$t0,	1
					beq	$t7,	$t0,	afterCondition5

					move	$t0,	$s4
					add	$a0,	$s0,	$t0

					jal	makeMove
					lw	$ra,	4($sp)

					move	$t7,	$v1
					li	$t0,	1
					beq	$t7,	$t0,	afterCondition5

					addi	$a0,	$s0,	-1

					jal	makeMove
					lw	$ra,	4($sp)

					move	$t7,	$v1
					li	$t0,	1
					beq	$t7,	$t0,	afterCondition5

					move	$t0,	$s4
					sub	$a0,	$s0,	$t0

					jal	makeMove
					lw	$ra,	4($sp)

					move	$t7,	$v1
					li	$t0,	1
					beq	$t7,	$t0,	afterCondition5

					elseLabel7:		la	$t1,	map
								add	$t3,	$t1,	$s0
								lb	$t5,	0($t3)

								li	$t0,	64
								bne	$t5,	$t0,	afterCondition6

								li	$t9,	37

								#add	$t3,	$t1,	$s0
								sb	$t9,	0($t3)

								jal	printLabyrinth

								li	$v1,	1

								lw	$s0,	0($sp)
								addi	$sp,	$sp,	8

								lw	$ra,	4($sp)

								jr	$ra

					afterCondition5:	li	$t8,	35

								la	$t1,	map
								add	$t3,	$t1,	$s0
								sb	$t8,	0($t3)
		
								li	$v1,	1

								lw	$s0,	0($sp)
								addi	$sp,	$sp,	8

								jr	$ra

					afterCondition6:	move	$v1,	$zero

								lw	$s0,	0($sp)
								addi	$sp,	$sp,	8

								jr	$ra

