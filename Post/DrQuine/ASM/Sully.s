section .data
	Colleen db "section .data%2$c	Colleen db %3$c%1$s%3$c, 0%2$c	FileName db %3$cSully_%%d.s%3$c, 0%2$c	FileExec db %3$cSully_%%d%3$c, 0%2$c	FormCmds db %3$cnasm -f elf64 -o %%1$s.o %%2$s && ld -lc -dynamic-linker /usr/lib64/ld-linux-x86-64.so.2 -o %%1$s %%1$s.o && ./%%1$s%3$c, 0%2$c	FileMode db %3$cw%3$c, 0%2$c%2$csection .bss%2$c	cmd resb 1000%2$c	new resb 20%2$c	exe resb 20%2$c%2$csection .text%2$c	extern sprintf%2$c	extern fopen%2$c	extern fprintf%2$c	extern fclose%2$c	extern system%2$c	extern exit%2$c%2$c%%macro SULLY 1%2$cglobal _start%2$c_start:%2$c%2$c	mov		r12, %%1%2$c	cmp		r12, 0%2$c	jle		errHandle%2$c	dec		r12%2$c%2$c	lea		rdi, [rel new]%2$c	mov		rsi, FileName%2$c	mov		rdx, %%1%2$c	call	sprintf%2$c%2$c	lea		rdi, [rel exe]%2$c	mov		rsi, FileExec%2$c	mov		rdx, %%1%2$c	call	sprintf%2$c%2$c	lea		rdi, [rel cmd]%2$c	mov		rsi, FormCmds%2$c	mov		rdx, exe%2$c	mov		rcx, new%2$c	call	sprintf%2$c%2$c	mov		rdi, new%2$c	mov		rsi, FileMode%2$c	call	fopen%2$c	mov		r13, rax%2$c%2$c	mov		rdi, rax%2$c	mov		rsi, Colleen%2$c	mov		rdx, rsi%2$c	mov		rcx, 10%2$c	mov		r8, 34%2$c	mov		r9, r12%2$c	call	fprintf%2$c%2$c	mov		rdi, r13%2$c	call	fclose%2$c%2$c	mov		rdi, cmd%2$c	call	system%2$c%2$cerrHandle:%2$c	xor		rdi, rdi%2$c	call	exit%2$c%%endmacro%2$c%2$cSULLY %4$d%2$c", 0
	FileName db "Sully_%d.s", 0
	FileExec db "Sully_%d", 0
	FormCmds db "nasm -f elf64 -o %1$s.o %2$s && ld -lc -dynamic-linker /usr/lib64/ld-linux-x86-64.so.2 -o %1$s %1$s.o && ./%1$s", 0
	FileMode db "w", 0

section .bss
	cmd resb 1000
	new resb 20
	exe resb 20

section .text
	extern sprintf
	extern fopen
	extern fprintf
	extern fclose
	extern system
	extern exit

%macro SULLY 1
global _start
_start:

	mov		r12, %1
	cmp		r12, 0
	jle		errHandle
	dec		r12

	lea		rdi, [rel new]
	mov		rsi, FileName
	mov		rdx, %1
	call	sprintf

	lea		rdi, [rel exe]
	mov		rsi, FileExec
	mov		rdx, %1
	call	sprintf

	lea		rdi, [rel cmd]
	mov		rsi, FormCmds
	mov		rdx, exe
	mov		rcx, new
	call	sprintf

	mov		rdi, new
	mov		rsi, FileMode
	call	fopen
	mov		r13, rax

	mov		rdi, rax
	mov		rsi, Colleen
	mov		rdx, rsi
	mov		rcx, 10
	mov		r8, 34
	mov		r9, r12
	call	fprintf

	mov		rdi, r13
	call	fclose

	mov		rdi, cmd
	call	system

errHandle:
	xor		rdi, rdi
	call	exit
%endmacro

SULLY 5
