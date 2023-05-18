<div>
	<!-- Title -->
	<h1 align = 'center'>
		📚 <b>LibASM</b> ⚙️
		<br><i style = 'font-size:120%;'>Back to root with Assembly</i>
	</h1>
	<!-- Description -->
	<p>
		This project aims at learning Assembly language (or ASM for short) by making a miniature basic library.
		Alike the Libft but instead of C, its ASM, as simple at that!
		Be aware ASM compiled code might not be a cross-plateform as other languages.<br>
		I've left a short documentation below in case anyone is interrested to learn ASM, and wants a headstart.
		<br><br>
		Here's the full specifications at the time the project was given:
		<ul>
			<li> Compiler: nasm </li>
			<li> OS System: MacOS </li>
  			<li> Architecture: x64 </li>
			<li> Syntax: Intel </li>
		</ul>
	</p>
	<!-- References -->
	<p>
		A few useful links I ve stored which can proves useful while learning ASM:
		<ul>
			<li><a href = 'https://p403n1x87.github.io/getting-started-with-x86-64-assembly-on-linux.html'>Getting started with simple explanations</a></li>
			<li><a href = 'https://www.tutorialspoint.com/assembly_programming/index.htm'>Tutorial Point Website - NASM</a></li>
			<li><a href = 'https://faculty.nps.edu/cseagle/assembly/sys_call.html'>Table of system calls</a></li>
			<li><a href = 'https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/x64-architecture'>Microsoft's list of x64 registry</a>
			<li><a href = 'https://www.thegeekstuff.com/2010/10/linux-error-codes/'>List of all standard ErrNo</a></li>
			<li><a href = 'https://www.cs.uaf.edu/courses/cs301/2014-fall/notes/methods/index.html'>Function Pointers C and ASM</a></li>
			<li><a href = 'https://www.ccoderun.ca/programming/2017-03-10_sizeof/'>Size of Data Types across OS</a></li>
			<li><a href = 'http://nickdesaulniers.github.io/blog/2016/01/20/debugging-x86-64-assembly-with-lldb-and-dtrace/'>Debugging ASM using LLDB</a></li>
			<li><a href = 'https://ncona.com/2019/12/debugging-assembly-with-gdb/'>Debugging ASM using GDB</a></li>
			<li><a href = 'https://lldb.llvm.org/use/map.html'>GDB and LLDB command map</a></li>
		</ul>
		And some extra links to StackOverflow posts which explains some useful optimizations and details concerning flags:
		<ul>
			<li><a href = 'https://stackoverflow.com/questions/1395591/what-is-exactly-the-base-pointer-and-stack-pointer-to-what-do-they-point'>Purpose of the ESP and EBP registers</a>
				(Another shorter post <a href = 'https://stackoverflow.com/questions/41912684/what-is-the-purpose-of-the-rbp-register-in-x86-64-assembler'>here</a>)</li>
			<li><a href = 'https://stackoverflow.com/questions/1396527/what-is-the-purpose-of-xoring-a-register-with-itself'>Purpose of using "xor reg, reg" instead of "mov reg, 0"</a>
				(Complex details <a href = 'https://stackoverflow.com/questions/33666617/what-is-the-best-way-to-set-a-register-to-zero-in-x86-assembly-xor-mov-or-and'>here</a>)</li>
			<li><a href = 'https://stackoverflow.com/questions/39556649/in-x86-whats-difference-between-test-eax-eax-and-cmp-eax-0'>Difference between "test reg, reg" and "cmp reg, 0"</a></li>
			<li><a href = 'https://stackoverflow.com/questions/19301498/carry-flag-auxiliary-flag-and-overflow-flag-in-assembly'>Carry Flag, Auxiliary Flag and Overflow Flag in Assembly</a></li>
		</ul>
		If you want to experiment, converting C code into Assembly, you can either using <a href = 'https://godbolt.org'>Gobolt's Code Explorer</a> or use the command <code>gcc -S -masm=intel [file]</code> to get an overview and test some ideas. On the other hand, you might find their outputs to be more over complicated in comparaison to the actual code, especially the GCC's one, mostly due to how architectures and compilers behaves.
		<br><br>
		Also, feel free to do a pull request if anything here is wrong.
		<br>Thanks :)
	</p>
</div>

<div>
	<h1 align = 'center'>
		<b>Documentation</b>
		<br><i style = 'font-size:80%;'>Basic things you may need to know</i>
	</h1>
	<!-- First Section -->
	<h2 style = 'font-size:120%;'>
		<b>--= BASIC INSTRUCTIONS =--</b>
	</h2>
	<p>
		Here's some basic instructions that can is used often:
<pre>
mov {dst}, {src}                       ; Copy src into dst
inc / dec {value}                      ; Increment or decrement value
add / sub / mul / div {src}, {other}   ; Apply arithmetic operation between src and other, and stores into src
imul / idiv {src}, {other}             ; Alike the one above, except it works on signed operation
and / or / xor / not {src}, {other}    ; Apply logical operation between src and other and stores into src
shl / shr / sal / sar {src}, {x}       ; Shift src by x bits left or right (variant `a`/`c`: keeps sign untouched)
rol / ror / rcl / rcr {src}, {x}       ; Alike the one above, except the last bit is set in first instead of erasing
test {src}, {other}                    ; Act like `and` but instead it doesnt stores (used alike `cmp`)
cmp {src}, {other}                     ; Look section about CONDITIONAL for more details
lea {dst}, {registry}                  ; Calculates the given registry's address and stores into dst
systemcall / call                      ; Look section about SYSTEM CALLS for more details
jmp {target}                           ; Goto target block
ret                                    ; Simply returns
</pre>
	</p>
	<!-- Second Section -->
	<h2 style = 'font-size:120%;'>
		<b>--= SYNTAX =--</b>
	</h2>
	<p>
		Here's some useful, yet important, syntaxes to understand:
<pre>
; ...      ; Commentary
...:       ; New function block
[...]      ; Get address of ...
</pre>
	</p>
	<!-- Third Section -->
	<h2 style = 'font-size:120%;'>
		<b>--= SYSTEM CALLS =--</b>
	</h2>
	<p>
		When it comes to calling external functions or even kernel's implemented basic systems functions / calls, their variables must first be stored
		within the base variables, up to 6. When more variables are requiered for an function, they must be pushed onto the stack. Then its returns
		value will be stored within `rax` (which is the same registry as the one to define which system call will be called for system calls).
<pre>
rax                          ; Target system calls
rdi, rsi, rdx, rcx, r8, r9   ; Variables (in order)
rax                          ; Return value
<br>
syscall                      ; Calls the system (kernel) using the stored variable
call [target]                ; Calls non system functions (no need to define `rax`)
</pre>
	</p>
	<!-- Fourth Section -->
	<h2 style = 'font-size:120%;'>
		<b>--= CONDITIONAL =--</b>
	</h2>
	<p>
		While conditions and loops aren't explicit in ASM unlike most basic languages,
		they can be achieved using jmp / j[condition] (jump) and cmp (compare) statements
		which are equivalent to goto statements in C (not commonly used although)
<pre>
cmp {src}, {cmp}   ; Compare src with cmp value
j[...] {target}    ; Goes to another block is condition is filled
loop {target}      ; Assumes count is stored in ecx / rcx and decrements it until 0
<br>; Here's a list of all primary conditions you can use and combine:
; - Any -
    n              ; Not
    e / z          ; Equal / Zero
; - Arithmetic -
    g              ; Greater
    l              ; Lower
; - Logical -
    a              ; Above
    b              ; Lower
; - Other -
    xcz            ; CX is Zero
    c              ; Carry
    o              ; Overflow
    p / pe         ; Parity / Parity Even
        po         ; (Not)  / Parity Odd
    s              ; Sign (negative) (Not = positive)
</pre>
	</p>
	<!-- Fifth Section -->
	<h2 style = 'font-size:120%;'>
		<b>--= ADDITIONAL TIPS =--</b>
	</h2>
	<p>
		There's some informations which might be quite useful to know:
		<ul>
			<li>Using `xor` on registry on itself is more optimal and takes up less space than mov 0 when it comes to initializing an registry to 0 since `xor` uses logical operations rather than arithmetic, also without taking additional space in the binary for that additional 0:
<pre>
xor     {registry}, {registry}
mov     {registry}, 0
</pre></li>
			<li>The same way as the previous point, `test` is also more optimal than `cmp`:
<pre>
test    {registry}, {registry}
cmp     {registry}, 0
</pre></li>
			<li>While rdi, rsi, rdx and any variables may requierd be set back to its origin state upon leaving the function, there's some other registries which doesn't, such as: rax and rcx</li>
			<li>Sometimes you might comes across some issues such as error with stack aligment, it can be fixed using rbp and rsp:
<pre>
push    rbp        ; Stores initial state of RBP
mov     rbp, rsp   ; Ensures stack alignement
  ...              ; Some code in between...
pop     rbp        ; Restores initial state of RBP
</pre>
		</ul>
		</pre>
	</p>
</div>
