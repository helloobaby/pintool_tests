// TrapFlag.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include <intrin.h>
static BOOL SwallowedException = TRUE;

static LONG CALLBACK VectoredHandler(
	_In_ PEXCEPTION_POINTERS ExceptionInfo
)
{
	std::cout << "Exec VectoredHandler\n";
	std::cout << std::hex << "ExceptionInfo->ContextRecord->Rip" << ExceptionInfo->ContextRecord->Rip << std::endl;

	SwallowedException = FALSE;

	if (ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_SINGLE_STEP)
		return EXCEPTION_CONTINUE_EXECUTION;

	return EXCEPTION_CONTINUE_SEARCH;
}

int main()
{
	PVOID Handle = AddVectoredExceptionHandler(1, VectoredHandler);
	SwallowedException = TRUE;

#ifdef _WIN64
	UINT64 eflags = __readeflags();
#else
	UINT eflags = __readeflags();
#endif

	//  Set the trap flag
	try {
		eflags |= 0x100;
		__writeeflags(eflags);
	}
	catch (...) {
		std::cout << "Enter SEH\n";
	}


	RemoveVectoredExceptionHandler(Handle);

	if (SwallowedException)
		std::cout << "Detect Debugger\n";
	else
		std::cout << "Success\n";
	
	return SwallowedException;
}
