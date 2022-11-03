BITS 64

section .text
global strcmp

strcmp:
    CMP     RDI, 0
    JE      null_end
    CMP     RSI, 0
    JE      null_end
    XOR     RCX, RCX

loop:
    MOV     R8B, BYTE [RDI + RCX]
    MOV     R9B, BYTE [RSI + RCX]
    CMP     BYTE R8B, 0
    JE      end
    CMP     BYTE R9B, 0
    JE      end
    CMP     R8B, R9B
    JNE     end
    INC     RCX
    JMP     loop

null_end:
    MOV     RAX, 0
    RET

end:
	SUB     R8B, R9B
	MOVZX   RAX, R8B
    RET