162e;section: [.text]
1d4b;kernel32.IsProcessorFeaturePresent
1d68;CPUID:0
1d68;[ANTIVM] --> CPUID - vendor check;https://unprotect.it/technique/cpuid/
1da3;CPUID:1
1da3;[ANTIVM] --> CPUID - HyperVisor bit check;https://unprotect.it/technique/cpuid/
1e1a;CPUID:7
1a55;ntdll.RtlInitializeSListHead
1c2c;kernel32.SetUnhandledExceptionFilter
1c32;[ANTIDEBUG] --> ^ SetUnhandledExceptionFilter;https://anti-debug.checkpoint.com/techniques/exceptions.html#unhandledexceptionfilter
103a;[ANTIDEBUG] --> INT2D;https://anti-debug.checkpoint.com/techniques/assembly.html#int2d
103f;ntdll.KiUserExceptionDispatcher
1be6;kernel32.GetModuleHandleW
