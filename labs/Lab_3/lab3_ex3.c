#include <stdio.h>

/* function main begins program execution */
int main(void)
{

   double x,y;
   int n;
  
   x = 1.0E-3;

   for(n=0;n<2000000000;n++)
   {
      y = 1.0 + x;
      if( y <= 1 )
      {
         printf("Machine Epsilon = %.20f \n",x);
         printf("Number of Iterations = %d \n",n);
         break;
      }
      x = x * 0.999999;
   }

} /* end of main */

