#include <stdio.h>

int isLittleEndian();

int main(void)
{
   
    int little = isLittleEndian();

    //Print the result of the union
    if (little) {
        printf("This machine is Little Endian\n");
    } else {
        printf("This machine is Big Endian\n");
    }

    return 0;

}

int isLittleEndian() {
   
   /* Create a union */
   union
   {
      int myint;
      /* Create an array of chars that matches */
      /* the size of the integer so we can display the bytes */
      char charArr[sizeof(int)];
   } myunion;
   
   myunion.myint = 1;
   printf("Integer number used in Union: ");
   printf("%i\n", myunion.myint);
   
   /* Show the byte order */
  printf("%X\n",(int)myunion.charArr[0]);
  printf("%X\n",(int)myunion.charArr[1]); 
   /* Perform a test on the data and return 1 for little endian, 0 for big endian */
  if ((int)myunion.charArr[0]==myunion.myint) { return 1;}
  return 0;
   
}
