// EnumSelfModules.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <Windows.h>
#include <winternl.h>
#include <iostream>
#include <string>
typedef struct
{
LIST_ENTRY InLoadOrderLinks;
LIST_ENTRY InMemoryOrderLinks;
LIST_ENTRY InInitializationOrderLinks;
PVOID DllBase;
PVOID EntryPoint;
ULONG SizeOfImage;
UNICODE_STRING FullDllName;
UNICODE_STRING BaseDllName;
// more stuff underneath . . .
} LDR_DATA_TABLE_ENTRY2, * PLDR_DATA_TABLE_ENTRY2;
using PLDR_ENUM_CALLBACK = VOID(NTAPI*)(PLDR_DATA_TABLE_ENTRY2 entry, PVOID context, PBOOLEAN stop);
EXTERN_C NTSTATUS LdrEnumerateLoadedModules(ULONG flags, PLDR_ENUM_CALLBACK enumProc, PVOID context);
#pragma comment(lib,"ntdll.lib")

using namespace std;

int main()
{
	// 尝试找pinvm.dll 实际上枚举不到
	auto hr = LdrEnumerateLoadedModules(0, [](PLDR_DATA_TABLE_ENTRY2 entry, PVOID context, PBOOLEAN stop)
		{
			std::wcout << entry->FullDllName.Buffer << std::endl;
		}, NULL);
    return 0;
}