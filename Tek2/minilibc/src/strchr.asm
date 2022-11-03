BITS 64

section .text
global strchr

strchr:
	XOR	    RCX, RCX
	CMP	    RDI, 0
	JE	    non_find_end

loop:
	CMP	    [RDI + RCX], SIL
	JE	    find_end
	CMP	    BYTE [RDI + RCX], 0
	JE	    non_find_end
	INC	    RCX
	JMP	    loop

find_end:
	ADD	    RDI, RCX
	MOV	    RAX, RDI
	RET

non_find_end:
	MOV	    RAX, 0
	RET