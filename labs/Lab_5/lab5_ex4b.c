#include <stdio.h>
double x;

void myfunc()
{
	printf("x:%x\n",&x);
  x = -0.0;
}
