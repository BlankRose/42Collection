extern _fopen
extern _fprintf
extern _fclose

section .data
Colleen db "extern _fopen%2$cextern _fprintf%2$cextern _fclose%2$c%2$csection .data%2$cColleen db %3$c%1$s%3$c, 0%2$cFileName db %3$cGrace_kid.s%3$c, 0%2$cFileMode db %3$cw%3$c, 0%2$c%2$csection .text%2$c%%macro GRACE 0%2$cglobal _main%2$c_main:%2$c%2$c	; This program will print its own source when run.%2$c	push	r8%2$c	mov		rdi, FileName%2$c	mov		rsi, FileMode%2$c	call	_fopen%2$c%2$c	mov		rdi, rax%2$c	lea		rsi, [rel Colleen]%2$c	mov		rdx, rsi%2$c	mov		rcx, 10%2$c	mov		r8, 34%2$c	call	_fprintf%2$c%2$c	call	_fclose%2$c	pop		r8%2$c	ret%2$c%%endmacro%2$cGRACE", 0
FileName db "Grace_kid.s", 0
FileMode db "w", 0

section .text
%macro GRACE 0
global _main
_main:

	; This program will print its own source when run.
	push	r8
	mov		rdi, FileName
	mov		rsi, FileMode
	call	_fopen

	mov		rdi, rax
	lea		rsi, [rel Colleen]
	mov		rdx, rsi
	mov		rcx, 10
	mov		r8, 34
	call	_fprintf

	call	_fclose
	pop		r8
	ret
%endmacro
GRACE