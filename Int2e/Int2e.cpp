// Int2e.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>

_declspec(naked) int f() {
    __asm {
        xor eax, eax;
        xor edx, edx;
        int 0x2e;
    }
}
int main()
{
    __try {
        std::cout << f();
    }
    __except (1) {
        std::cout << "exception \n";
    }
    std::cout << "exit\n";
    return 0;
}

