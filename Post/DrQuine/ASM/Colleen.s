; This program will print its own source when run.

section .data
	Colleen db "; This program will print its own source when run.%2$c%2$csection .data%2$c	Colleen db %3$c%1$s%3$c, 0%2$c%2$csection .text%2$c	global _start%2$c	extern printf%2$c	extern exit%2$c%2$c_exit:%2$c	mov		rdi, 0%2$c	call	exit%2$c%2$c_start:%2$c%2$c	; This program will print its own source when run.%2$c	lea		rdi, [rel Colleen]%2$c	mov		rsi, rdi%2$c	mov		rdx, 10%2$c	mov		rcx, 34%2$c	call	printf%2$c	call	_exit%2$c", 0

section .text
	global _start
	extern printf
	extern exit

_exit:
	mov		rdi, 0
	call	exit

_start:

	; This program will print its own source when run.
	lea		rdi, [rel Colleen]
	mov		rsi, rdi
	mov		rdx, 10
	mov		rcx, 34
	call	printf
	call	_exit
