#include <stdio.h>

void myfunc(void);

int y = 15212;
int x = 15213;

int main(void)
{
	printf("x:%x y:%x\n",&x,&y);
  myfunc();
  printf("x = 0x%i y = 0x%i \n", x, y);
  return 0;
}
