.code 

__int2d proc
    mov rax, 0
    int 2dh
    nop
    ret
__int2d endp

__syscall proc
    mov eax,0
    mov ecx,0
    syscall
    mov rax,rcx
    ret
__syscall endp

end

