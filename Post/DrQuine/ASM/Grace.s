section .data
	Colleen db "section .data%2$c	Colleen db %3$c%1$s%3$c, 0%2$c	FileName db %3$cGrace_kid.s%3$c, 0%2$c	FileMode db %3$cw%3$c, 0%2$c%2$csection .text%2$c	extern fopen%2$c	extern fprintf%2$c	extern fclose%2$c	extern exit%2$c%2$c%%macro GRACE 0%2$cglobal _start%2$c_start:%2$c%2$c	; This program will print its own source when run.%2$c	mov		rdi, FileName%2$c	mov		rsi, FileMode%2$c	call	fopen%2$c%2$c	test	rax, rax%2$c	jz		end%2$c%2$c	mov		rdi, rax%2$c	mov		r12, rax%2$c%2$c	lea		rsi, [rel Colleen]%2$c	mov		rdx, rsi%2$c	mov		rcx, 10%2$c	mov		r8, 34%2$c	call	fprintf%2$c%2$c	mov		rdi, r12%2$c	call	fclose%2$c%2$cend:%2$c	xor		rdi, rdi%2$c	call	exit%2$c%%endmacro%2$cGRACE%2$c", 0
	FileName db "Grace_kid.s", 0
	FileMode db "w", 0

section .text
	extern fopen
	extern fprintf
	extern fclose
	extern exit

%macro GRACE 0
global _start
_start:

	; This program will print its own source when run.
	mov		rdi, FileName
	mov		rsi, FileMode
	call	fopen

	test	rax, rax
	jz		end

	mov		rdi, rax
	mov		r12, rax

	lea		rsi, [rel Colleen]
	mov		rdx, rsi
	mov		rcx, 10
	mov		r8, 34
	call	fprintf

	mov		rdi, r12
	call	fclose

end:
	xor		rdi, rdi
	call	exit
%endmacro
GRACE
