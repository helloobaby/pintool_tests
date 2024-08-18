// WriteFile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>

int main()
{
	CreateFileA("Hello.exe", GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	getchar(); // for attach debugger to view memory
	return 0;
}

/*
pin跟踪时候的调用栈 (Procmon)
0	FLTMGR.SYS	FltGetStreamContext + 0x20cb	0xfffff80657bc963b	C:\Windows\System32\drivers\FLTMGR.SYS
1	FLTMGR.SYS	FltGetStreamContext + 0x1b51	0xfffff80657bc90c1	C:\Windows\System32\drivers\FLTMGR.SYS
2	FLTMGR.SYS	FltRequestFileInfoOnCreateCompletion + 0x4ef	0xfffff80657c01fef	C:\Windows\System32\drivers\FLTMGR.SYS
3	ntoskrnl.exe	IofCallDriver + 0x55	0xfffff80658712655	C:\Windows\system32\ntoskrnl.exe
4	ntoskrnl.exe	SeQuerySecurityDescriptorInfo + 0xa743	0xfffff80658bb7ff3	C:\Windows\system32\ntoskrnl.exe
5	ntoskrnl.exe	PsLookupProcessThreadByCid + 0x157	0xfffff80658b6a537	C:\Windows\system32\ntoskrnl.exe
6	ntoskrnl.exe	ObOpenObjectByNameEx + 0x1844	0xfffff80658ae9824	C:\Windows\system32\ntoskrnl.exe
7	ntoskrnl.exe	ObOpenObjectByNameEx + 0x1f2	0xfffff80658ae81d2	C:\Windows\system32\ntoskrnl.exe
8	ntoskrnl.exe	NtCreateFile + 0xba7	0xfffff80658bcf0c7	C:\Windows\system32\ntoskrnl.exe
9	ntoskrnl.exe	NtCreateFile + 0x79	0xfffff80658bce599	C:\Windows\system32\ntoskrnl.exe
10	ntoskrnl.exe	setjmpex + 0x9115	0xfffff8065882b305	C:\Windows\system32\ntoskrnl.exe
11	<unknown>	0x299c3970833	0x299c3970833   ->  Intel pin Jitted Code Cache


正常运行时候的调用栈
0	FLTMGR.SYS	FltGetStreamContext + 0x20cb	0xfffff80657bc963b	C:\Windows\System32\drivers\FLTMGR.SYS
1	FLTMGR.SYS	FltGetStreamContext + 0x1b51	0xfffff80657bc90c1	C:\Windows\System32\drivers\FLTMGR.SYS
2	FLTMGR.SYS	FltRequestFileInfoOnCreateCompletion + 0x4ef	0xfffff80657c01fef	C:\Windows\System32\drivers\FLTMGR.SYS
3	ntoskrnl.exe	IofCallDriver + 0x55	0xfffff80658712655	C:\Windows\system32\ntoskrnl.exe
4	ntoskrnl.exe	SeQuerySecurityDescriptorInfo + 0xa743	0xfffff80658bb7ff3	C:\Windows\system32\ntoskrnl.exe
5	ntoskrnl.exe	PsLookupProcessThreadByCid + 0x157	0xfffff80658b6a537	C:\Windows\system32\ntoskrnl.exe
6	ntoskrnl.exe	ObOpenObjectByNameEx + 0x1844	0xfffff80658ae9824	C:\Windows\system32\ntoskrnl.exe
7	ntoskrnl.exe	ObOpenObjectByNameEx + 0x1f2	0xfffff80658ae81d2	C:\Windows\system32\ntoskrnl.exe
8	ntoskrnl.exe	NtCreateFile + 0xba7	0xfffff80658bcf0c7	C:\Windows\system32\ntoskrnl.exe
9	ntoskrnl.exe	NtCreateFile + 0x79	0xfffff80658bce599	C:\Windows\system32\ntoskrnl.exe
10	ntoskrnl.exe	setjmpex + 0x9115	0xfffff8065882b305	C:\Windows\system32\ntoskrnl.exe
11	ntdll.dll	NtCreateFile + 0x14	0x7ff8766f0a44	C:\Windows\System32\ntdll.dll
12	KernelBase.dll	CreateFileW + 0x710	0x7ff873d6a330	C:\Windows\System32\KernelBase.dll
13	KernelBase.dll	CreateFileA + 0xe8	0x7ff873d69ba8	C:\Windows\System32\KernelBase.dll
14	WriteFile.exe	main + 0x35, C:\Users\admin\Desktop\pintool_tests\WriteFile\WriteFile.cpp(9)	0x7ff7b0c11035	C:\Users\admin\Desktop\pintool_tests\x64\Release\WriteFile.exe
15	WriteFile.exe	__scrt_common_main_seh + 0x10c, D:\a\_work\1\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl(281)	0x7ff7b0c11270	C:\Users\admin\Desktop\pintool_tests\x64\Release\WriteFile.exe
16	kernel32.dll	BaseThreadInitThunk + 0x1d	0x7ff875ef257d	C:\Windows\System32\kernel32.dll
17	ntdll.dll	RtlUserThreadStart + 0x28	0x7ff8766aaf28	C:\Windows\System32\ntdll.dll





*/