# This MAL program will find the maximum value in an
# integer array of size 12

            .data
arr:        .word     1, 2048, 4, 512, 16, 64, 32, 128, 8, 512, 1024, 2
outstr:     .asciiz   "The maximum value in the array is "
newline:    .asciiz   "\n"

            .text
            .globl main
main:       # TODO: Initialize constants, etc.
		move	$5,	$0	# i=0
		li	$6,	11	# size = 12
		la	$10,	arr
		move	$7,	$0	# starting value of 0
		j	loop

loop:       # TODO: Find the maximum value in the array
		bge	$5,	$6,	print		# check if i<=size
		lw	$9,	($10)
		slt	$s0,	$7,	$9		# check if value is higher than current max
		beq	$s0,	1,	swap
		addi	$5,	$5,	1		# increment i
		addi	$10,	$10,	4		# advance array pointer
		j 	loop

swap:		move	$7,	$9	# store new max value
		j loop
            
print:      # TODO: Print out the max value	
            la    $a0, outstr
            li    $v0, 4
            syscall
            li    $v0, 1
            move  $a0, $7
            syscall
            la    $a0, newline
            li    $v0, 4         # print newline
            syscall
            li      $v0, 10      # Exit: to the bat mobile...
            syscall
