// getCurIp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
_declspec(naked) int f() {
    _asm {
        call $ + 5          // Pin应该会修复所有跟地址有关的,比如这里call push到栈上的地址,会修复成原来程序正常运行的
        pop eax           
        ret
    }
}
int main()
{
    std::cout << std::hex << "curIp " << f() << std::endl;
    return 0;
}
