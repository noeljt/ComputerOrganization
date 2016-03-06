/* CSCI-2500 Lab #8 - Digital Logic Emulation */
/* Include standard I/O lib */
#include <stdio.h>

#define FALSE 0
#define TRUE 1

/* Redefine short int as BIT */ 
typedef short int BIT;

/* Function Declarations (basic gates) */
BIT not_gate(BIT);
BIT or_gate(BIT, BIT);
BIT and_gate(BIT, BIT);
BIT xor_gate(BIT, BIT);

/* Function Declarations (combinational circuits) */
BIT multiplexer(BIT, BIT, BIT, BIT, BIT, BIT);
void decoder(BIT, BIT, BIT*, BIT*, BIT*, BIT*);
BIT half_adder(BIT, BIT, BIT*);
BIT adder(BIT, BIT, BIT, BIT*);

/* Function Declarations (sequential circuits) */
BIT sr_latch(BIT, BIT, BIT);

/* main function */
int main(int argc, char *argv[])
{

   BIT X, Y, Cin, Cout;
   BIT I0, I1, I2, I3;
   BIT O0, O1, O2, O3;
   BIT S0, S1;
   BIT S, R, Q;

   // Unit test for NOT gate - produce truth table
   // X   NOT(X)
   // 0     1
   // 1     0
   printf("===== Unit test for not_gate =====\n");
   printf("not_gate(X) | RESULT \n");
   printf("not_gate(0) | %d \n", not_gate(0) );
   printf("not_gate(1) | %d \n", not_gate(1) );
  
   
   // Unit test for OR gate
   // X Y (X OR Y)
   // 0 0   0
   // 0 1   1
   // 1 0   1
   // 1 1   1
   printf("===== Unit test for or_gate =====\n");
   printf("or_gate(X,Y) | RESULT\n");

   for( X = 0; X < 2; X++)
      for( Y = 0; Y < 2; Y++)
         printf("or_gate(%d,%d) | %d\n",X,Y,or_gate(X,Y));

   
   // Unit test for AND gate
   // X Y (X AND Y)
   // 0 0   0
   // 0 1   0
   // 1 0   0
   // 1 1   1
   printf("===== Unit test for and_gate =====\n");
   printf("and_gate(X,Y) | RESULT\n");
   for( X = 0; X < 2; X++)
      for( Y = 0; Y < 2; Y++)
         printf("and_gate(%d,%d) | %d\n",X,Y,and_gate(X,Y));

   
   // Unit test for XOR gate
   // X Y (X AND Y)
   // 0 0   0
   // 0 1   1
   // 1 0   1
   // 1 1   0
   printf("===== Unit test for and_gate =====\n");
   for( X = 0; X < 2; X++)
      for( Y = 0; Y < 2; Y++)
         printf("xor_gate(%d,%d) | %d\n",X,Y,xor_gate(X,Y));

   

   // Unit test for Multiplexer
   // (S0,S1) | (I0,I1,I2,I3) = RESULT (I0|I1|I2|I3)
   printf("===== Unit test for 4-input multiplexer =====\n");
   printf("multiplexer(S0,S1) | (I0,I1,I2,I3) | RESULT (I0|I1|I2|I3) \n");
   for( S0 = 0; S0 < 2; S0++) // Selector bit 1
   for( S1 = 0; S1 < 2; S1++) // Selector bit 2
   {

      for( I0 = 0; I0 < 2; I0++)
         for( I1 = 0; I1 < 2; I1++)
            for( I2 = 0; I2 < 2; I2++)
               for( I3 = 0; I3 < 2; I3++)
               {
                  printf("multiplexer(%2d,%2d) | (%2d,%2d,%2d,%2d) | %2d \n",S0,S1,I0,I1,I2,I3,
                         multiplexer(I0,I1,I2,I3,S0,S1) );
               }
   }

   // Unit test for Decoder
   // I0 I1 O0 O1 O2 O3
   // 0  0   1  0  0  0
   // 0  1   0  1  0  0
   // 1  0   0  0  1  0
   // 1  1   0  0  0  1
   printf("===== Unit test for 2-input decoder =====\n");
   printf("decoder(I0,I1) | (O0,O1,O2,O3)\n");
   for( I0 = 0; I0 < 2; I0++)
      for( I1 = 0; I1 < 2; I1++)
      {
         decoder(I0,I1,&O0,&O1,&O2,&O3);
         printf("decoder(%2d,%2d) | (%2d,%2d,%2d,%2d)\n",I0,I1,O0,O1,O2,O3);
      }
   
   // Unit test for S-R Latch
   // S R | Q | Q(t+1)
   // 0 0 | 0 | 0
   // 0 0 | 1 | 1
   // 0 1 | 0 | 0
   // 0 1 | 1 | 0
   // 1 0 | 0 | 1
   // 1 0 | 1 | 1
   // 1 1 | 0 | -1
   // 1 1 | 1 | -1
   printf("===== Unit test for sr_latch =====\n");
   printf("sr_latch( S, R ) | Q | Q(t+1)\n");
   for (S = 0; S < 2; S++)
   {
      for (R = 0; R < 2; R++)
      {
         for (Q = 0; Q < 2; Q++)
            printf("sr_latch( %d, %d ) | %d | %d \n", S, R, Q, sr_latch(S,R,Q) );
      }
   }

   // Unit test for half-adder
   // X Y | Sum | Cout
   // 0 0 |  0  |  0
   // 0 1 |  1  |  0
   // 1 0 |  1  |  0
   // 1 1 |  0  |  1
   printf("===== Unit test for half_adder =====\n");
   printf("half_adder( A, B ) | Sum | Cout\n");
   // TODO: Implement Unit Test
   for (X = 0; X < 2; X++)
   {
      for (Y = 0; Y < 2; Y++)
      {
         Cout=0;
         BIT SUM = half_adder(X,Y,&Cout);
         printf("half_adder( %d, %d ) |  %d  | %d \n", X, Y, SUM, Cout);
      }
   }

   // Unit test for adder
   // X Y | Sum | Cin | Cout
   // 0 0 |  0  |  0  |  0
   // 0 1 |  1  |  0  |  0
   // 1 0 |  1  |  0  |  0
   // 1 1 |  0  |  0  |  1
   // 0 0 |  1  |  1  |  0
   // 0 1 |  0  |  1  |  1
   // 1 0 |  0  |  1  |  1
   // 1 1 |  1  |  1  |  1
   printf("===== Unit test for adder =====\n");
   printf("adder( A, B ) | Sum | Cin | Cout\n");
   // TODO: Implement Unit Test
   for (Cin = 0; Cin < 2; Cin++)
   {
      for (X = 0; X < 2; X++)
      {
         for (Y = 0; Y < 2; Y++) {
            Cout=0;
            BIT SUM = adder(X,Y,Cin,&Cout);
            printf("adder( %d, %d ) |  %d  |  %d  | %d\n", X, Y, SUM, Cin, Cout);
         }
      }
   }   
   return 0;
}

BIT not_gate(BIT X)
{
   
    if (X==FALSE) {
        return TRUE;
    } else {
        return FALSE;
    }
   
}

BIT or_gate(BIT X, BIT Y)
{
   
    if (X==FALSE && Y==FALSE) {
        return FALSE;
    } else {
        return TRUE;
    }
   
}

BIT and_gate(BIT X, BIT Y)
{

   if (X==TRUE && Y==TRUE) {
      return TRUE;
   } else {
      return FALSE;
   }
   
}

BIT xor_gate(BIT X, BIT Y)
{
   
   if (X != Y) {
      return TRUE;
   } else {
      return FALSE;
   }

}

BIT multiplexer(BIT I0, BIT I1, BIT I2, BIT I3, BIT S0, BIT S1)
{
   
   // Leverage sum of products notation
   return ( ( I0 && !S0 && !S1 ) ||
            ( I1 && !S0 && S1  ) ||
            ( I2 &&  S0 && !S1 ) ||
            ( I3 &&  S0 && S1  ) );
   
}

void decoder(BIT I0, BIT I1, BIT *O0, BIT *O1, BIT *O2, BIT *O3)
{

   // Initialize all outputs to 0
   *O0 = *O1 = *O2 = *O3 = FALSE;
   
   *O0 = (!I0 && !I1 );
   *O1 = (!I0 &&  I1 );
   *O2 = ( I0 && !I1 );
   *O3 = ( I0 && I1  );
   
}

/* Returns the next state of the S-R Latch */
BIT sr_latch(BIT S, BIT R, BIT Q)
{
   
   // if both bits are zero then behavior of S-R latch
   // is undefined so we will have the simulation return -1 or UNDEF
   if( S==TRUE && R==TRUE) return -1;
   
   if (S==TRUE) {
      Q = TRUE; // Set
   } else if (R==TRUE) {
      Q = FALSE; // Reset
   } else {
      Q = Q; // Unchanged
   }
   
   return Q;
}

/* Returns the sum of the half adder and carry out bit to calling method */
BIT half_adder (BIT A, BIT B, BIT *CarryOut)
{
   if (xor_gate(A,B)==TRUE) {
      return TRUE;
   } else if (and_gate(A,B)) {
      *CarryOut=TRUE;
      return FALSE;
   } else {
      return FALSE;
   }
   
}

/* Returns the sum of the full-adder and carry out bit to calling method */
BIT adder (BIT A, BIT B, BIT CarryIn, BIT *CarryOut)
{
   BIT TEMP = FALSE;
   BIT SUM_1 = half_adder(A,B, &TEMP);
   BIT SUM_2 = half_adder(SUM_1,CarryIn,CarryOut); 
   *CarryOut = or_gate(TEMP,*CarryOut);
   return SUM_2; 
}

