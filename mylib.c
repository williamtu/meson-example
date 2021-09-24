
#include <stdio.h>

#define RTE_PRIORITY_LOG 101
#define RTE_PRIORITY_BUS 110
#define RTE_PRIORITY_CLASS 120
#define RTE_PRIORITY_LAST 65535

#define RTE_PRIO(prio) \
	        RTE_PRIORITY_ ## prio

#ifndef RTE_INIT_PRIO 
#define RTE_INIT_PRIO(func, prio) \
	static void __attribute__((constructor(RTE_PRIO(prio)), used)) func(void)
#endif

int mylib_func1(int x) {
	printf("mylib func1: %d\n", x);
	return 0;
}
int mylib_func2(int x) {
	printf("mylib func2: %d\n", x);
	return 0;
}

RTE_INIT_PRIO(myinit1, BUS) {
	printf("constructor1\n");
}
RTE_INIT_PRIO(myinit2, LAST) { 
	printf("constructor2\n");
}



