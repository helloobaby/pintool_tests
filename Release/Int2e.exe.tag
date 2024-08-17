153f;section: [.text]
1c8a;kernel32.IsProcessorFeaturePresent
1ca7;CPUID:0
1ce2;CPUID:1
1d59;CPUID:7
1966;ntdll.RtlInitializeSListHead
1b3d;kernel32.SetUnhandledExceptionFilter
1b43;[ANTIDEBUG] --> ^ SetUnhandledExceptionFilter;https://anti-debug.checkpoint.com/techniques/exceptions.html#unhandledexceptionfilter
1000;INT2e
;
1000;SYSCALL:0x76f140d0
1000;ntdll.KiUserExceptionDispatcher
1c73;ntdll.[RtlInterlockedCompareExchange64+1e2]*
1b80;kernelbase.[UnhandledExceptionFilter+1cb]*
1c73;ntdll.[RtlInterlockedCompareExchange64+1e2]*
