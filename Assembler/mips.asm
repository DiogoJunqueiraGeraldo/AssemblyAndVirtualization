# "Hello World" in MIPS Assembly

	# All code is placed after the .text assembler directive
	.text

	# Its necessary to declare the entry point
	.globl main

main:
	li	$v0, 4		# Code for syscall (print_string)
	li	$a0, msg	# Load message address to register a0
	syscall
	li	$v0, 10		# Code for syscall (exit)
	syscall

	# All memory structures are placed after the .data assembler directive
	.data

msg: .asciiz "Hello, World!\n"