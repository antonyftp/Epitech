BITS 64

section .text
global rindex

rindex:
    CMP     RDI, 0
    JE      non_find_end
    XOR     RCX, RCX
    JMP     pos_loop

decrement:
    DEC     RCX
    JMP     main_loop

pos_loop:
    MOV     R8B, BYTE [RDI + RCX]
    CMP     R8B, 0
    JE      decrement
    INC     RCX
    JMP     pos_loop

main_loop:
    MOV     R8B, BYTE [RDI + RCX]
    CMP     R8B, SIL
    JE      find_end
    CMP     R8B, 0
    JE      non_find_end
    DEC     RCX
    JMP     main_loop

find_end:
    MOV     RAX, RDI
    ADD     RAX, RCX
    RET

non_find_end:
    MOV     RAX, 0
    RET