; SAMPLE ASM PROGRAM
.686
.model flat, C

.stack 1000h

.data
; <<DATA HERE >>
A DD 6
B DD 9
sum DD ?

.code
main proc
; << CODE HERE >>
mov EAX, [A]
add EAX, [B]
mov [sum], EAX

main endp
end main
.end