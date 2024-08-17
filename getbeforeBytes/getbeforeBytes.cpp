// getbeforeBytes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>

static LONG CALLBACK VectoredHandler(
	_In_ PEXCEPTION_POINTERS ExceptionInfo
)
{
	std::cout << std::hex << "Exception Address " << ExceptionInfo->ContextRecord->Eip << std::endl;

	if (ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT) {
		DWORD* CheckPtr = (DWORD*)ExceptionInfo->ContextRecord->Eip - 1;
		// 正常运行和Pintool插桩运行都是输出0x90909090
		std::cout << *CheckPtr << std::endl;
		ExceptionInfo->ContextRecord->Eip++;
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	return EXCEPTION_CONTINUE_SEARCH;
}
_declspec(naked) bool f() {
    _asm {
		nop // 0x90
		nop // 0x90
		nop // 0x90
        nop // 0x90
        int 3
        ret
    }
}

int main()
{
	PVOID Handle = AddVectoredExceptionHandler(1, VectoredHandler);
	f();
	RemoveVectoredExceptionHandler(Handle);
    return 0;
}
