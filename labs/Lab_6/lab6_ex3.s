			.data
newline:	.asciiz		"\n"

			.text
			.globl		main

main:		li			$s0, 0
			li			$s1, 5
			li			$s2, 10

loop:		bge		$s0, $s2, Done
			add 	$s1, $s1, $s0
			addi 	$s0, $s0, 1

			move 	$a0, $s1
			li		$v0, 1
			syscall
			la	$a0, newline
			li		$v0, 4
			syscall
			j loop

Done:		li	$v0, 10
			syscall