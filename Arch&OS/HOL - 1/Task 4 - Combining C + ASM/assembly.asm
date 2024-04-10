.686
.model flat, C

; Inform the assembler these vars will be used in an extern C module
EXTERNDEF C vector:DWORD

.data
vector DD 13, 6, 25, 9, 3, 12, 55, 67, 23, 32, 6, 41, 5, 0

.code
asmAVG proc

start:
	mov EAX, [vector]	; this line might be unnecessary as EAX is initialized again in a few lines, but it's included for better code readability
	mov EBX, 0
	mov ECX, 0
	jmp comp

whileloop:
	add ECX, 4
	add EBX, EAX

comp:
	mov EAX, [vector + ECX]
	cmp EAX, 0
	jne whileloop

result:
	shr ECX, 2
	inc ECX		; This is for including the zero (0) as length of the array, we can delete it if we do not consider it part of it's length (therefore the average values changes)
	mov EAX, EBX
	idiv ECX
	ret

asmAVG endp

END