section .data
msg db "Hello, Holberton", 0
fmt db "%s",0xA, 0

section .text
	global main
	extern printf

main:
	mov rdi, fmt  ; load the format string into rdi
    	mov rsi, msg ; load the message into rsi
	mov eax, 0
	call printf
	
	mov eax, 0
	ret

