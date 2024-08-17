// getCurIp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
_declspec(naked) int f() {
    _asm {
        call $ + 5          // 生成 `e8 00 00 00 00`
        pop eax           // 将下一条指令的地址弹入 EAX
        ret
    }
}
int main()
{
    std::cout << std::hex << "curIp " << f() << std::endl;
    return 0;
}
