#include <stdio.h>
#include <limits.h>
#include <float.h>

int	main()
{
	printf("Значение INT_MAX равно %i\n", INT_MAX);
	printf("Значение INT_MIN равно %i\n", INT_MIN);
	printf("int занимает %li байт\n", sizeof(int));

	printf("Значение FLT_MAX равно %f\n", FLT_MAX);
	printf("Значение FLT_MIN равно %.50f\n", FLT_MIN);
	printf("float занимает %li байт\n", sizeof(float));

	printf("Значение CHAR_MAX равно %d\n", CHAR_MAX);
	printf("Значение CHAE_MIN равно %d\n", CHAR_MIN);
	printf("char занимает %li байт\n", sizeof(char));

	printf("Значение DBL_MAX равно %lf\n", DBL_MAX);
        printf("Значение DBL_MIN равно %lf\n", DBL_MIN);
        printf("double занимает %li байт\n", sizeof(double));

	printf("Значение SHRT_MAX равно %hi\n", SHRT_MAX);
        printf("Значение SHRT_MIN равно %hi\n", SHRT_MIN);
        printf("short занимает %li байт\n", sizeof(short));

	printf("Значение LONG_MAX равно %li\n", LONG_MAX);
        printf("Значение LONG_MIN равно %li\n", LONG_MIN);
        printf("long занимает %li байт\n", sizeof(long));

	return 0;
}
