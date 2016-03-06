#include <stdio.h>
#include <stdlib.h>

int main(void) 
{

   char *charPointer; 
   int *intPointer; 
   float *floatPointer; 
   double *doublePointer; 

   charPointer = calloc(4,sizeof(char));
   intPointer = calloc(4,sizeof(int));
   floatPointer = calloc(4,sizeof(float));
   doublePointer = calloc(4,sizeof(double));

   printf("charPointer:     %p\ncharPointer+1:   %p\n",charPointer,(charPointer+1));
   printf("intPointer:      %p\nintPointer+1:    %p\n",intPointer,(intPointer+1));
   printf("floatPointer:    %p\nfloatPointer+1:  %p\n",floatPointer,(floatPointer+1));
   printf("doublePointer:   %p\ndoublePointer+1: %p\n",doublePointer,(doublePointer+1));
   return 0;

}
