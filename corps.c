#include <stdlib.h>
#include <stdio.h>

#define sq(x) ((x)*(x))

float body_mass_index( int mass, float height )
{
   return( mass / sq( height ) );
}

float body_fat_percentage( float bmi, int age, int sex /* male: 1, female: 0 */ )
{
   return( ( bmi * 1.2 ) + ( 0.23 * age ) - ( 10.8 * sex ) - 5.4 );
}

int main( int argc, char* argv[] )
{
   if ( argc != 5 ) { exit -1; }

   int mass = atoi( argv[ 1 ] );
   float height = atof( argv[ 2 ] );
   int age = atoi( argv[ 3 ] );
   int sex = atoi( argv[ 4 ] );

   printf( "BMI: %.2f\n", body_mass_index( mass, height ) );
   printf( "BFP: %.2f%%\n", body_fat_percentage( body_mass_index( mass, height ), age, sex ) );

   return 0;
}
