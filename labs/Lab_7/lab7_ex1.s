# This MAL program will demonstrate multiple nested function calls

            .data
mainx:      .asciiz   "main x: "
newline:    .asciiz   "\n"

            .text
            .globl main
main:       li    $s0, 1         # $s0 = x = 1
            move  $a0, $s0
            jal   hello          # call hello function
            la    $a0, mainx
            li    $v0, 4
            syscall
            li    $v0, 1
            move  $a0, $s0       # print x
            syscall
            la    $a0, newline
            li    $v0, 4         # print newline
            syscall
            li    $v0, 10        # Exit: To the batmobile
            syscall

            .data
hellox:     .asciiz   "hello x: "
            .text
            # TODO: Manage the Stack and Implement the rest of the procedure
hello:      add   $s1, $s0, 1
            move  $s2, $ra       # save return address to main
            jal   hello2         # call hello2 function
            la    $a0, hellox
            li    $v0, 4
            syscall
            li    $v0, 1
            move  $a0, $s1
            syscall
            la    $a0, newline
            li    $v0, 4         # print newline
            syscall
            move  $ra, $s2
            jr    $ra            #return to main     

            .data
hello2x:    .asciiz   "hello2 x: "
            .text
            # TODO: Manage the Stack and Implement the rest of the procedure
hello2:     add   $s3, $s1, 1
            la    $a0, hello2x
            li    $v0, 4
            syscall
            li    $v0, 1
            move  $a0, $s3
            syscall            
            la    $a0, newline
            li    $v0, 4         # print newline
            syscall
            jr    $ra