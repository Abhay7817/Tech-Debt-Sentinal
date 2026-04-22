#pragma once
#include "Header.h"
//#include<time.h>
int main(void) {
	//clock_t start, end;
	//double cpu_time;
	//start = clock();
	reader();
	//end = clock();
	//cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
	//printf("Time taken: %lf s\n", cpu_time);
	json_generator();
	output_printer();
	return 0;
}