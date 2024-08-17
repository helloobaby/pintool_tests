1674;section: [.text]
1dba;kernel32.IsProcessorFeaturePresent
1dd7;CPUID:0
1e12;CPUID:1
1e89;CPUID:7
1a9b;ntdll.RtlInitializeSListHead
1c72;kernel32.SetUnhandledExceptionFilter
1c78;[ANTIDEBUG] --> ^ SetUnhandledExceptionFilter;https://anti-debug.checkpoint.com/techniques/exceptions.html#unhandledexceptionfilter
10a7;ntdll.RtlAddVectoredExceptionHandler
10c0;[ANTIDEBUG] --> Trap Flag set;https://anti-debug.checkpoint.com/techniques/assembly.html#popf_and_trap_flag
10c1;ntdll.KiUserExceptionDispatcher
1092;ntdll.[RtlGetGroupSecurityDescriptor+17c]*
10c2;ntdll.RtlRemoveVectoredExceptionHandler
1c2c;kernel32.GetModuleHandleW
