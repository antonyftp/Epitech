BITS 64

section .text
global strstr

strstr:
    CMP     RDI, 0
    JE      null_return
    CMP     RSI, 0
    JE      null_return
    MOV     R9B, [RSI]
    XOR     RCX, RCX
    XOR     RDX, RDX
    JMP     main_loop

main_loop:
    MOV     R8B, [RDI + RCX]
    CMP     R8B, 0
    JE      null_return
    CMP     R8B, R9B
    JE      save_ptr
    INC     RCX

save_ptr:
    LEA     RAX, [RDI + RCX]
    JMP     sub_loop

sub_loop:
    CMP     R9B, 0
    JE      not_null_return
    INC     RCX
    INC     RDX
    MOV     R8B, [RDI + RCX]
    MOV     R9B, [RSI + RDX]
    CMP     R8B, R9B
    JE      sub_loop
    MOV     RDX, 0
    JMP     main_loop


not_null_return:
    RET

null_return:
    MOV     RAX, 0
    RET