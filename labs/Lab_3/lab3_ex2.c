#include <stdio.h>
#define SIZE 10

/* prototypes for functions */
float getArrayStats(int[], int, int, int);
void  decrement (int[], int);
void  printArray (int[], int);

/* function main begins program execution */
int main(void)
{

   int num = SIZE;  /* sample array and size */
   int values[SIZE] = {10,9,8,7,6,5,4,3,2,1};
   /* parameters for array values */
   int max, min;
   float average;

   /* INSERT CODE HERE TO PRINT ARRAY STATISTICS */
   average = getArrayStats(values, num, min, max);

   /* print the numbers in the array before call to decrement */
   printf("\nBefore the call to function decrement:\n");
   printArray(values, num);
   /* The next call changes #'s in the values array */
   decrement(values, num);
   /* print the numbers in the array after call to decrement */
   printf("\nAfter the call to function decrement:\n");
   printArray(values, num);

   return 0;

} /* end of main */

float getArrayStats(int values[], int num_elements, int min, int max) {
   int i, sum;
   float avg;
   min = values[0];
   max = 0;
   sum = 0;
   for (i=0; i<num_elements; i++) {
      if (values[i]<min) {
         min = values[i];
      }
      if (values[i]>max) {
         max = values[i];
      }
      sum += values[i];
   }
   avg = (sum/(float)num_elements);
   printf("Maximum value = %d\n", max);
   printf("Minimum value = %d\n", min);
   printf("Average = %6.1f\n", avg);
   return avg;
}

void decrement(int values[], int num_elements)
{
   /* Decrements each value stored in the array */
   /* values by 1 parameter num_elements gives  */
   /* the # of elements in the array            */
   int i; /* temp counter */
   for (i = 0; i < num_elements; i++)
      values[i]--;

} /* end of decrement */

void printArray(int values[], int num_elements)
{
   /* Prints each value stored in the array */
   /* parameter num_elements gives the # of */
   /* elements in the array                 */
   int i; /* temp counter */
   for (i = 0; i < num_elements; i++)
      printf("%4d", values[i]);
   printf("\n");

} /* end of printArray */

