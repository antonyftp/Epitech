BITS 64

section .text
global strlen

strlen:
    XOR     RCX, RCX

loop:
    CMP BYTE [RDI + RCX], 0
    JE end
    inc RCX
    JMP loop

end:
    MOV     RAX, RCX
    RET