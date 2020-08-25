#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	printf("max_int = %d , size = %d\n", INT_MAX, sizeof(int));
	printf("max_float = %f , size = %d\n", FLT_MAX, sizeof(float));
	printf("max_double = %f , size = %d\n", DBL_MAX, sizeof(double));
	return 0;
}
