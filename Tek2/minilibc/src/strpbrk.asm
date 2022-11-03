BITS 64

section .text
global strpbrk

strpbrk:
    CMP     RDI, 0
    JE      null_return
    CMP     RSI, 0
    JE      null_return
    XOR     RCX, RCX    ;counter 1
    XOR     R11, R11    ;counter 2

increment:
    INC     RCX
    XOR     R11, R11
    JMP     loop

loop:
    MOV     R8B, BYTE [RDI + RCX]
    JMP     word_loop

word_loop:
    MOV     R9B, BYTE [RSI + R11]
    CMP     R8B, R9B
    JE      end
    CMP     R9B, 0
    JE      increment
    INC     R11
    JMP     word_loop

null_return:
    MOV     RAX, 0
    RET

end:
    MOV     RAX, RDI
    ADD     RAX, RCX
    RET