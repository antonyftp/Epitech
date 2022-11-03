BITS 64

section .text
global memcpy

memcpy:
    XOR     RCX, RCX

loop:
    CMP     RDX, RCX
    JZ      end
    MOV     R8B, [RSI + RCX]
    MOV     [RDI + RCX], R8B
    INC     RCX
    JMP     loop

end:
    MOV     RAX, RDI
    RET