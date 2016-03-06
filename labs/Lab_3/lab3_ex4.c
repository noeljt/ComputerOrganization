#include <stdio.h>
#include <math.h>

/* function main begins program execution */
int main(void)
{
   int n;
   double xd,yd,x,y,dif;   

   n = 33554431;
   x = 33554431;

   printf("Value of x:  %.2f \n",x);
   printf("Value of n:  %d \n",n);

   /* What is going on here? */
   if( (int)x == n )
   {
      printf("Variables x and n are equal\n");
   }
   else
   {
      printf("Variables x and n are not equal\n");
   }

   /* Why does this comparison work? */
   if( x == n )
   {
      printf("Variables x and n are equal\n");
   }
   else
   {
      printf("Variables x and n are not equal\n");
   }
   

   xd = 10.0;
   yd = sqrt(xd);
 
   yd = yd * yd;

   printf("Value of xd:  %.2f \n",xd);
   printf("Value of yd:  %.2f \n",yd);

   /* How can we make this comparison better? Hint: See exercise 3 */
  
   x = 1.0E-3;

   for(n=0;n<2000000000;n++)
   {
      y = 1.0 + x;
      if( y <= 1 )
      {
         break;
      }
      x = x * 0.999999;
   }
   dif = xd-yd;

   if( dif < x)
   {
      printf("Variables xd and yd are equal\n");
   }
   else
   {
      printf("Variables xd and yd are not equal\n");
   } 

} /* end of main */

