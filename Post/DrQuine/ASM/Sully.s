extern _sprintf
extern _fopen
extern _fprintf
extern _fclose
extern _system

%macro SULLY 1
section .data
	Colleen db "extern _sprintf%2$cextern _fopen%2$cextern _fprintf%2$cextern _fclose%2$cextern _system%2$c%2$c%%macro SULLY 1%2$csection .data%2$c	Colleen db %3$c%1$s%3$c, 0%2$c	FileName db %3$cSully_%%d.s%3$c, 0%2$c	FileExec db %3$cSully_%%d%3$c, 0%2$c	FormCmds db %3$cnasm -f macho64 -o %%1$s.o %%2$s && ld -lSystem -o %%1$s %%1$s.o && ./%%1$s%3$c, 0%2$c	FileMode db %3$cw%3$c, 0%2$c%2$csection .bss%2$c	cmd resb 1000%2$c	new resb 20%2$c	exe resb 20%2$c%2$csection .text%2$cglobal _main%2$c_main:%2$c%2$c	mov		r9, %%1%2$c	cmp		r9, 0%2$c	jle		errHandle%2$c	dec		r9%2$c	push	r9%2$c%2$c	lea		rdi, [rel new]%2$c	mov		rsi, FileName%2$c	mov		rdx, %%1%2$c	call	_sprintf%2$c%2$c	lea		rdi, [rel exe]%2$c	mov		rsi, FileExec%2$c	mov		rdx, %%1%2$c	call	_sprintf%2$c%2$c	lea		rdi, [rel cmd]%2$c	mov		rsi, FormCmds%2$c	mov		rdx, exe%2$c	mov		rcx, new%2$c	call	_sprintf%2$c%2$c	mov		rdi, new%2$c	mov		rsi, FileMode%2$c	call	_fopen%2$c	mov		r12, rax%2$c%2$c	mov		rdi, rax%2$c	mov		rsi, Colleen%2$c	mov		rdx, rsi%2$c	mov		rcx, 10%2$c	mov		r8, 34%2$c	pop		r9%2$c	push	r9%2$c	call	_fprintf%2$c%2$c	mov		rdi, r12%2$c	call	_fclose%2$c%2$c	mov		rdi, cmd%2$c	call	_system%2$c	pop		r9%2$c%2$cerrHandle:%2$c%2$c	ret%2$c%%endmacro%2$c%2$cSULLY %4$d", 0
	FileName db "Sully_%d.s", 0
	FileExec db "Sully_%d", 0
	FormCmds db "nasm -f macho64 -o %1$s.o %2$s && ld -lSystem -o %1$s %1$s.o && ./%1$s", 0
	FileMode db "w", 0

section .bss
	cmd resb 1000
	new resb 20
	exe resb 20

section .text
global _main
_main:

	mov		r9, %1
	cmp		r9, 0
	jle		errHandle
	dec		r9
	push	r9

	lea		rdi, [rel new]
	mov		rsi, FileName
	mov		rdx, %1
	call	_sprintf

	lea		rdi, [rel exe]
	mov		rsi, FileExec
	mov		rdx, %1
	call	_sprintf

	lea		rdi, [rel cmd]
	mov		rsi, FormCmds
	mov		rdx, exe
	mov		rcx, new
	call	_sprintf

	mov		rdi, new
	mov		rsi, FileMode
	call	_fopen
	mov		r12, rax

	mov		rdi, rax
	mov		rsi, Colleen
	mov		rdx, rsi
	mov		rcx, 10
	mov		r8, 34
	pop		r9
	push	r9
	call	_fprintf

	mov		rdi, r12
	call	_fclose

	mov		rdi, cmd
	call	_system
	pop		r9

errHandle:

	ret
%endmacro

SULLY 5