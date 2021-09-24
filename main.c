
#include <stdio.h>
#include <rte_eal.h>
#include "mylib.h"
//
// main is where all program execution starts
//
int main(int argc, char **argv) {
   	printf("Hello there.\n");

	mylib_func1(123);
	rte_eal_init(argc, argv);
	return 0;
}
