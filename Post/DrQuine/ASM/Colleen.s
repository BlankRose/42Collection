; This program will print its own source when run.
extern _printf

section .data
Colleen db "; This program will print its own source when run.%2$cextern _printf%2$c%2$csection .data%2$cColleen db %3$c%1$s%3$c, 0%2$c%2$csection .text%2$cglobal _main%2$c_main:%2$c%2$c	; This program will print its own source when run.%2$c	push	r8%2$c	lea		rdi, [rel Colleen]%2$c	mov		rsi, rdi%2$c	mov		rdx, 10%2$c	mov		rcx, 34%2$c	call	_printf%2$c	pop		r8%2$c	ret", 0

section .text
global _main
_main:

	; This program will print its own source when run.
	push	r8
	lea		rdi, [rel Colleen]
	mov		rsi, rdi
	mov		rdx, 10
	mov		rcx, 34
	call	_printf
	pop		r8
	ret