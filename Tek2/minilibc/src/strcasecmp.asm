BITS 64

section .text
global strcasecmp

strcasecmp:
    XOR     RAX, RAX
    XOR     RCX, RCX
    JMP     loop

increment:
    CMP     R8B, 0
    JE      end
    INC     RCX

loop:
    MOV     R8B, BYTE [RDI + RCX]
    MOV     R9B, BYTE [RSI + RCX]
    CMP     R8B, 'A'
    JL      check_upper_r9b
    CMP     R8B, 'Z'
    JG      check_upper_r9b
    ADD     R8B, 32

check_upper_r9b:
    CMP     R9B, 'A'
    JL      check_same
    CMP     R9B, 'Z'
    JG      check_same
    ADD     R9B, 32

check_same:
    CMP     R8B, R9B
    JE      increment

end:
    MOVZX   RAX, R8B
    MOVZX   RBX, R9B
    SUB     RAX, RBX
    RET