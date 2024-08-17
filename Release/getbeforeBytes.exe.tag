1354;section: [.text]
1a9a;kernel32.IsProcessorFeaturePresent
1ab7;CPUID:0
1af2;CPUID:1
1b69;CPUID:7
177b;ntdll.RtlInitializeSListHead
1952;kernel32.SetUnhandledExceptionFilter
1958;[ANTIDEBUG] --> ^ SetUnhandledExceptionFilter;https://anti-debug.checkpoint.com/techniques/exceptions.html#unhandledexceptionfilter
10b7;ntdll.RtlAddVectoredExceptionHandler
10a4;[ANTIDEBUG] --> INT3;https://anti-debug.checkpoint.com/techniques/assembly.html#int3
10a4;ntdll.KiUserExceptionDispatcher
1093;ntdll.[RtlGetGroupSecurityDescriptor+17c]*
10c3;ntdll.RtlRemoveVectoredExceptionHandler
190c;kernel32.GetModuleHandleW
