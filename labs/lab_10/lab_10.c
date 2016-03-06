#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* include SSE extenstions */
#include <emmintrin.h> 

#define ARR_SIZE 200000

int basic_sum( int , int * );
int unrolled_sum( int , int * );
int vectorized_sum( int , int * );
void time_method( int , int* , int(*)(int,int*), char * );

int main( int argc, char **argv )
{
   
   int i;
   clock_t start, end;
   int array[ARR_SIZE];
   
   /* initialize the array with random data */
   srand48( time( NULL ) ); /* seed with system time */
   for( i = 0; i < ARR_SIZE; i++ ) array[i] = lrand48( );
   
   /* report time of execution on each function */
   time_method( ARR_SIZE, array, basic_sum, "basic sum" );
   time_method( ARR_SIZE, array, unrolled_sum, "unrolled" );
   time_method( ARR_SIZE, array, vectorized_sum, "vectorized" );
 
   return 0;
}

/* Computes the sum of the elements in an array */
int basic_sum( int n, int *array )
{ 
    int i;
    int sum = 0;
    for( i = 0; i < n; i++ )
        sum += array[i];
    printf("Regular Sum: %d\n", sum);
    return sum;
}

/* Computes the sum of the elements in an array */
/*    but with an unrolled loop                 */
int unrolled_sum( int n, int *array )
{
  int i;
  int sum = 0;
  int broke = 0;
   
  /* TODO: Unroll the loop - do multiple operations at a time */
   
  /* HINT: be sure to handle any tail elements */
  /*    should array size not be a mult. of 4  */
  for( i = 0; i < n; i+=4 ) {
    if ((i+3)>=n) {
      broke = 1;
      break;
    }
    sum += array[i];
    sum += array[i+1];
    sum += array[i+2];
    sum += array[i+3];
  }
  if (broke) {
    for (;i<n; i++) {
      sum += array[i];
    }
  }
  printf("Rolled Sum: %d\n", sum);
  return sum;
}

/* Computes the sum of the elements in an array */
/*    using the SSE extensions */
int vectorized_sum( int n, int *array )
{
   
   __m128i sum =_mm_setzero_si128();
   __m128i vect = _mm_setzero_si128();
   int i,j;
   int values[4];
   int result;
   int broke = 0;

   /* TODO: Write vectorized code here */
  for( i = j = 0; i < n; i+=4 ) {
    if ((i+3)>=n) {
      broke = 1;
      break;
    }
    vect = _mm_loadu_si128((__m128i*)(array+i));
    sum = _mm_add_epi32(sum, vect);
  }
  _mm_storeu_si128((__m128i*)values, sum);;
  result += values[0];
  result += values[1];
  result += values[2];
  result += values[3];
  if (broke) {
    for (;i<n;i++) {
      result += values[i];
    }
  }
  printf("vector sum: %d\n", result);
  return result;

}

/* Times the execution of a sum method and prints results to std out */
void time_method( int n, int *a, int (*computeSum)(int,int*), char *name )
{
   
   char *time_units;
   int sum;
   double time_measure;
   clock_t start, end;

   /* warm up CPU */
   sum = computeSum( n, a);
   
   /* measure execution time */
   start = clock();
   sum += computeSum( n, a );
   end = clock();
   time_measure = (double)(end-start);

   if( CLOCKS_PER_SEC == 1E3) time_units = "milliseconds";
   if( CLOCKS_PER_SEC == 1E6) time_units = "microseconds";
   if( CLOCKS_PER_SEC == 1E9) time_units = "nanoseconds";
   
   /* report time of execution */
   printf( "%20s: ", name );
   printf( "%.2f %s\n", time_measure, time_units );

}



