BITS 64

section .text
global memset

memset:
    XOR     RCX, RCX

loop:
    CMP     RCX, RDX
    JE      end
    MOV     BYTE [RDI + RCX], SIL
    INC     RCX
    JMP     loop

end:
    MOV     RAX, RDI
    RET