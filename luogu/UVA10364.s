	.file	"UVA10364.cpp"
	.text
	.globl	los
	.bss
	.align 4
los:
	.space 4
	.globl	flag
	.align 32
flag:
	.space 84
	.globl	sum
	.align 4
sum:
	.space 4
	.globl	m
	.align 4
m:
	.space 4
	.globl	max
	.align 4
max:
	.space 4
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
.LC1:
	.ascii "no\0"
.LC2:
	.ascii "yes\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB28:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$144, %rsp
	.seh_stackalloc	144
	.seh_endprologue
	call	__main
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	scanf
.L14:
	movl	-16(%rbp), %eax
	testl	%eax, %eax
	je	.L2
	movl	$-2147483648, -4(%rbp)
	leaq	m(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	call	scanf
	movl	$0, los(%rip)
	movl	$0, -8(%rbp)
.L6:
	movl	m(%rip), %eax
	cmpl	%eax, -8(%rbp)
	jge	.L3
	leaq	-112(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	scanf
	movl	-8(%rbp), %eax
	cltq
	movl	-112(%rbp,%rax,4), %eax
	cmpl	%eax, -4(%rbp)
	jg	.L4
	movl	-8(%rbp), %eax
	cltq
	movl	-112(%rbp,%rax,4), %eax
	jmp	.L5
.L4:
	movl	-4(%rbp), %eax
.L5:
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %eax
	cltq
	movl	-112(%rbp,%rax,4), %edx
	movl	los(%rip), %eax
	addl	%edx, %eax
	movl	%eax, los(%rip)
	addl	$1, -8(%rbp)
	jmp	.L6
.L3:
	movl	los(%rip), %eax
	andl	$3, %eax
	testl	%eax, %eax
	jne	.L7
	movl	los(%rip), %eax
	leal	3(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$2, %eax
	cmpl	%eax, -4(%rbp)
	jle	.L8
.L7:
	leaq	.LC1(%rip), %rcx
	call	printf
	jmp	.L14
.L8:
	movl	$0, -12(%rbp)
.L11:
	cmpl	$20, -12(%rbp)
	jg	.L10
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	flag(%rip), %rax
	movl	$0, (%rdx,%rax)
	addl	$1, -12(%rbp)
	jmp	.L11
.L10:
	movl	los(%rip), %eax
	leal	3(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$2, %eax
	movl	%eax, %edx
	leaq	-112(%rbp), %rax
	movl	$0, %r9d
	movl	%edx, %r8d
	movl	$1, %edx
	movq	%rax, %rcx
	call	_Z3dfsPiiii
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L12
	leaq	.LC2(%rip), %rcx
	call	printf
	jmp	.L13
.L12:
	leaq	.LC1(%rip), %rcx
	call	printf
.L13:
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	.L14
.L2:
	movl	$0, %eax
	addq	$144, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3dfsPiiii
	.def	_Z3dfsPiiii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3dfsPiiii
_Z3dfsPiiii:
.LFB29:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	%r9d, 40(%rbp)
	cmpl	$4, 24(%rbp)
	jne	.L17
	movl	$1, %eax
	jmp	.L18
.L17:
	movl	40(%rbp), %eax
	movl	%eax, -4(%rbp)
.L23:
	movl	m(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jge	.L19
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	flag(%rip), %rax
	movl	(%rdx,%rax), %eax
	testl	%eax, %eax
	jne	.L20
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	flag(%rip), %rax
	movl	$1, (%rdx,%rax)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, 32(%rbp)
	jne	.L21
	movl	-4(%rbp), %eax
	leal	1(%rax), %ecx
	movl	los(%rip), %eax
	leal	3(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$2, %eax
	movl	%eax, %edx
	movl	24(%rbp), %eax
	addl	$1, %eax
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_Z3dfsPiiii
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L22
	movl	$1, %eax
	jmp	.L18
.L21:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, 32(%rbp)
	jle	.L22
	movl	-4(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	32(%rbp), %edx
	subl	%eax, %edx
	movl	24(%rbp), %eax
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_Z3dfsPiiii
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L22
	movl	$1, %eax
	jmp	.L18
.L22:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	flag(%rip), %rax
	movl	$0, (%rdx,%rax)
.L20:
	addl	$1, -4(%rbp)
	jmp	.L23
.L19:
	movl	$0, %eax
.L18:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
