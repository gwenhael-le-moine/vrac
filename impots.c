#include <stdio.h>
#include <stdlib.h>

float tax( int low, int high, float rate, float income )
{
   float taxable = ( income > high ) ? high : income;
   taxable = taxable - low;
   taxable = ( taxable < 0 ) ? 0 : taxable;

   return rate * taxable;
}

int main( int argc, char* argv[] )
{
   float income;
   float lunch;
   float child;
   float taxable;
   float impots = 0.0;
   float taxed = 0.0;

   if ( argc != 4 ) {
      exit -1;
   }

   income = atof( argv[ 1 ] );
   lunch  = atof( argv[ 2 ] );
   child  = atof( argv[ 3 ] );

   taxable = income - ( lunch + child );

   impots += tax( 0,         5000000,  0.05,  taxable );
   impots += tax( 5000000,  10000000,  0.1,   taxable );
   impots += tax( 10000000, 18000000,  0.15,  taxable );
   impots += tax( 18000000, 32000000,  0.2,   taxable );
   impots += tax( 32000000, 52000000,  0.25,  taxable );
   impots += tax( 52000000, 80000000,  0.3,   taxable );
   impots += tax( 80000000, 999000000, 0.35,  taxable );

   printf( "| %.f | %.f | %.f |\n", income, impots, income - impots );
}
