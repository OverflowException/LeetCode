	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Please input number of parenthesis!\0"
LC1:
	.ascii "returnSize = %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	cmpl	$2, 8(%ebp)
	je	L2
	movl	$LC0, (%esp)
	call	_puts
	movl	$0, %eax
	jmp	L6
L2:
	movl	$0, 20(%esp)
	movl	12(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %edx
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_generateParenthesis
	movl	%eax, 24(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, 28(%esp)
	jmp	L4
L5:
	movl	28(%esp), %eax
	leal	0(,%eax,4), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_puts
	addl	$1, 28(%esp)
L4:
	movl	20(%esp), %eax
	cmpl	%eax, 28(%esp)
	jl	L5
	movl	$0, %eax
L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.globl	_generateParenthesis
	.def	_generateParenthesis;	.scl	2;	.type	32;	.endef
_generateParenthesis:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$16, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	movl	$16, (%esp)
	call	_malloc
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	$0, 12(%eax)
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	leal	(%eax,%eax), %edx
	movl	-16(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$0, 12(%esp)
	movl	$1, 8(%esp)
	movl	%edx, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_GenerateYinYangTree
	movl	-16(%ebp), %eax
	movl	12(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	addl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_ExtractResultStr
	movl	-20(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.globl	_GenerateYinYangTree
	.def	_GenerateYinYangTree;	.scl	2;	.type	32;	.endef
_GenerateYinYangTree:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	16(%ebp), %eax
	movb	%al, -12(%ebp)
	movl	8(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movzbl	-12(%ebp), %edx
	movb	%dl, (%eax)
	cmpl	$0, 20(%ebp)
	je	L10
	movl	20(%ebp), %eax
	movzbl	1(%eax), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	addl	%edx, %eax
	jmp	L11
L10:
	movzbl	-12(%ebp), %eax
L11:
	movl	8(%ebp), %edx
	movb	%al, 1(%edx)
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	testb	%al, %al
	jns	L12
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	jmp	L9
L12:
	cmpb	$0, -12(%ebp)
	jle	L14
	movl	$40, %edx
	jmp	L15
L14:
	movl	$41, %edx
L15:
	movl	8(%ebp), %eax
	movb	%dl, 2(%eax)
	subl	$1, 12(%ebp)
	cmpl	$0, 12(%ebp)
	jle	L16
	movl	$16, (%esp)
	call	_malloc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	$16, (%esp)
	call	_malloc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	$-1, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_GenerateYinYangTree
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	$1, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_GenerateYinYangTree
	jmp	L17
L16:
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	movl	8(%ebp), %eax
	movzbl	1(%eax), %eax
	testb	%al, %al
	jne	L17
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	_AppendResult
L17:
	nop
L9:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.globl	_ReleaseYinYangTree
	.def	_ReleaseYinYangTree;	.scl	2;	.type	32;	.endef
_ReleaseYinYangTree:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_AppendResult
	.def	_AppendResult;	.scl	2;	.type	32;	.endef
_AppendResult:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	8(%eax), %ebx
	movl	$16, (%esp)
	call	_malloc
	movl	%eax, 4(%ebx)
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 12(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.globl	_ExtractResultStr
	.def	_ExtractResultStr;	.scl	2;	.type	32;	.endef
_ExtractResultStr:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -28(%ebp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	$0, -20(%ebp)
	jmp	L21
L24:
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movl	16(%ebp), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, (%ebx)
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -24(%ebp)
	jmp	L22
L23:
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movzbl	2(%eax), %eax
	movb	%al, (%edx)
	movl	-12(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -12(%ebp)
	subl	$1, -24(%ebp)
L22:
	cmpl	$0, -24(%ebp)
	jns	L23
	movl	-16(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -16(%ebp)
	addl	$1, -20(%ebp)
L21:
	movl	-20(%ebp), %eax
	cmpl	-28(%ebp), %eax
	jl	L24
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.ident	"GCC: (i686-posix-dwarf-rev1, Built by MinGW-W64 project) 4.9.2"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_atoi;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
