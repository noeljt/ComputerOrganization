# This MAL program to fill the values of a 2D array
#   using row-major access

         .data
x:       .word  0:10			# space for 2D array x
header:  .asciiz "Row Column Offset Value\n"
space:   .asciiz " "
newln:   .asciiz "\n"
         .text
         .globl main

main:    # Print header to the user
         la      $a0, header     # Output string
         li      $v0, 4
         syscall

         move	$s1, $0        # i = 0
         li	$t3, 3            # $t3 has max # of rows in x
         li	$t4, 4            # $t4 has max # of columns in x
         li	$t5, 4            # $t5 holds # bytes per element (4)
		
iloop:	bge 	$s1, $t3, end_i		 	
         move 	$s2, $0        # j = 0

jloop: 	bge 	$s2, $t4, end_j

         # Now calculate address of x[i][j] in $t0
         la 	$t0, x 			   # $t0 has the base addr. of x
         move 	$t1, $t4
         mul 	$t1, $t1, $t5 		# $t1 has 4 * # columns
         mul 	$t1, $t1, $s1 		# $t1 has 4 * # columns * i
         mul 	$t2, $s2, $t5 		# $t2 has 4 * j
         add 	$t1, $t1, $t2 		# $t1 has the offset for x[i][j]
         add 	$t0, $t0, $t1 		# $t0 has the addr. of x[i][j]

         # Compute i * (j + 1)
         addi	$t2, $s2, 1       # $t2 has j + 1
         mul	$t2, $t2, $s1		# $t2 has i * (j + 1)
         sw	$t2, 0($t0)          # store $t2 in x[i][j]

         # Print information to the user
         move    $a0, $s1
         li      $v0, 1          # Command: print_int i
         syscall
         la      $a0, space      # Output space
         li      $v0, 4
         syscall
         move    $a0, $s2
         li      $v0, 1          # Command: print_int j
         syscall
         la      $a0, space      # Output space
         li      $v0, 4
         syscall
         move    $a0, $t1
         li      $v0, 1          # Command: print_int - address
         syscall
         la      $a0, space      # Output space
         li      $v0, 4
         syscall
         move    $a0, $t2        #
         li      $v0, 1          # Command: print_int i * (j + 1)
         syscall
         la      $a0, newln      # Output newline
         li      $v0, 4
         syscall

         # Update loop indices
         addi	$s2, $s2, 1		# j++
         b	jloop

end_j:   addi 	$s1, $s1, 1		# i++
         b 	iloop

end_i:   li      $v0, 10         # To the bat mobile
         syscall
