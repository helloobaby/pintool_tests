// InterruptTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
BOOL IsDebuggerPresent_Int2d()
{
#ifndef _WIN64
    __try
    {
        __asm int 0x2d
    }
    __except (1)
    {
        return FALSE;
    }

    return TRUE;
#endif
    return false;
}

extern "C" void __int2d();
extern "C" void* __syscall();

static BOOL SwallowedException = TRUE;

static LONG CALLBACK VectoredHandler(
    _In_ PEXCEPTION_POINTERS ExceptionInfo
)
{
    std::cout << "enter my veh\n";  // pin 不抛异常的话不走这里
    SwallowedException = FALSE;
    if (ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT)
    {
        //The Int 2D instruction already increased EIP/RIP so we don't do that (although it wouldnt hurt).
        return EXCEPTION_CONTINUE_EXECUTION;
    }else if (ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT)
    {
        //The Int 2D instruction already increased EIP/RIP so we don't do that (although it wouldnt hurt).
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

BOOL Interrupt_0x2d()
{
    PVOID Handle = AddVectoredExceptionHandler(1, VectoredHandler);

    SwallowedException = TRUE;
    std::cout << "执行 int2d \n";
    __int2d(); // pin 执行int2d不会抛异常
               // 说明pin int2d是模拟执行的,而不是直接执行的
    
    RemoveVectoredExceptionHandler(Handle);

    return SwallowedException;
}
int main()
{   
    std::cout << "Current Thread id" << std::hex << GetCurrentThreadId() << std::endl;
    if (Interrupt_0x2d()) {
        std::cout << "Debugger present2\n";
    }
    else {
        std::cout << "OK2\n";
    }

    // Get Rip 
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
