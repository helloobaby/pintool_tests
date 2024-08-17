// InterruptTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
BOOL IsDebuggerPresent_Int2d()
{
    //__try
    //{
    //    __asm int 0x2d
    //}
    //__except (1)
    //{
    //    return FALSE;
    //}

    //return TRUE;
    return false;
}

extern "C" void __int2d();
extern "C" void* __syscall();

static BOOL SwallowedException = TRUE;

static LONG CALLBACK VectoredHandler(
    _In_ PEXCEPTION_POINTERS ExceptionInfo
)
{
    std::cout << "enter my veh\n";
    SwallowedException = FALSE;
    if (ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT)
    {
        //The Int 2D instruction already increased EIP/RIP so we don't do that (although it wouldnt hurt).
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

//#define NOCATCH
BOOL Interrupt_0x2d()
{
#ifndef NOCATCH
    PVOID Handle = AddVectoredExceptionHandler(1, VectoredHandler);
#endif // !NOCATCH

    SwallowedException = TRUE;
    std::cout << "执行 int2d \n";
    __int2d();
#ifndef NOCATCH
    RemoveVectoredExceptionHandler(Handle);
#endif // !NOCATCH

    return SwallowedException;
}
int main()
{
    if (IsDebuggerPresent_Int2d())
        std::cout << "Debugger present\n";
    else {
        std::cout << "OK\n";
    }
    
    if (Interrupt_0x2d()) {
        std::cout << "Debugger present2\n";
    }
    else {
        std::cout << "OK2\n";
    }

    std::cout << std::hex << __syscall();
    
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
