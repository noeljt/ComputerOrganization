#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void transpose( int n, int blocksize, int *dst, int *src ) 
{
    int i,j,k_1,k_2;
    /* TODO: add blocking to this basic loop */
    // for( i = 0; i < n; i++ )
    //     for( j = 0; j < n; j++ )
    //         dst[j+i*n] = src[i+j*n];
    for( i = 0; i < n; i+=blocksize ) {
        for( j = 0; j < n; j+=blocksize ) {
            for (k_1=0;k_1<blocksize;k_1++) {
                for (k_2=0;k_2<blocksize;k_2++) {
                    if (i+k_1>n) {continue;}
                    if (j+k_2>n) {continue;}
                    dst[(j+k_2)+(i+k_1)*n] = src[(i+k_1)+(j+k_2)*n];
                }
            }
        }
    }
}

int main( int argc, char **argv ) 
{
    int n = 2000,i,j;
    int blocksize = atoi(argv[1]); /* TODO: experiment with block size */

    /* allocate an n*n block of integers for the matrices */
    int *A = (int*)malloc( n*n*sizeof(int) );
    int *B = (int*)malloc( n*n*sizeof(int) );

    /* initialize A,B to random integers */
    srand48( time( NULL ) ); /* seed random # generator */
    for( i = 0; i < n*n; i++ ) A[i] = lrand48( );
    for( i = 0; i < n*n; i++ ) B[i] = lrand48( );

    /* measure performance */
    struct timeval start, end;

    gettimeofday( &start, NULL );
    transpose( n, blocksize, B, A );
    gettimeofday( &end, NULL );

    double seconds = (end.tv_sec - start.tv_sec) + 1.0e-6 * (end.tv_usec - start.tv_usec);
    printf( "%g milliseconds\n", seconds*1e3 );

    /* check correctness */
    for( i = 0; i < n; i++ )
        for( j = 0; j < n; j++ )
            if( B[j+i*n] != A[i+j*n] ) {
	        printf("Error: Transpose does not result in correct answer!!\n");
	        exit( -1 );
            }
  
    /* release resources */
    free( A );
    free( B );
    return 0;

}
