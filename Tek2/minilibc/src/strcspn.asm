BITS 64

section .text
global strcspn

strcspn:
    CMP     RDI, 0
    JE      null_end
    CMP     RSI, 0
    JE      null_end
    XOR     RCX, RCX
    XOR     R11, R11

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

null_end:
    MOV     RAX, 0
    RET

end:
    MOV     RAX, RCX
    RET