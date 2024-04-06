; DIVISION ASM PROGRAM
.686
.model flat, C

.stack 1000h

.data
; << DATA HERE >>
A DD 5
B DD 0
quo DD ?
rem DD ?

.code
main proc
; << CODE HERE >>
; start:
	mov EAX, [A]
	mov EBX, [B]
	mov ECX, 0

; divisor = 0
	cmp EBX, 0
	je case_0
	jmp comp

whileloop:
	sub EAX, EBX
	inc ECX

comp:
	cmp EAX, EBX
	jge whileloop

result:
	mov quo, ECX
	mov rem, EAX
	jmp fi

case_0:
	mov quo, -1
	mov rem, 0

fi:

main endp
end main
.end