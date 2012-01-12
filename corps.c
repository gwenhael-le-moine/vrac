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

float basal_metabolic_rate( int mass, float height, int age, int sex /* male: 1, female: 0 */ )
{
    float quotients[2][4] = { { 655.0,  9.6, 1.8, 4.7 },
                              {  66.0, 13.7, 5,   6.8 } };

    return( quotients[ sex ][ 0 ]                            \
            + ( quotients[ sex ][ 1 ] * mass)                \
            + ( quotients[ sex ][ 2 ] * ( height * 100 ) )   \
            - ( quotients[ sex ][ 3 ] * age ) );
}

/* float lean_body_mass_men( int mass, float waist ) */
/* { */
/*     return( ( ( mass * 1.082 ) + 94.42 ) - ( ( waist * 100 ) * 4.15 ) ); */
/* } */

/* float body_fat_weight_men( int mass, float waist ) */
/* { */
/*     return( mass - lean_body_mass_men( mass, waist ) ); */
/* } */

/* float body_fat_2_men( int mass, float waist ) */
/* { */
/*     return( ( body_fat_weight_men( mass, waist ) * 100 ) / mass ); */
/* } */

int main( int argc, char* argv[] )
{
    if ( argc != 6 ) { exit -1; }

    int mass = atoi( argv[ 1 ] );
    float height = atof( argv[ 2 ] );
    float waist = atof( argv[ 3 ] );
    int age = atoi( argv[ 4 ] );
    int sex = atoi( argv[ 5 ] );

    printf( "BMI: %.2f\n", body_mass_index( mass, height ) );
    printf( "BFP: %.2f%%\n", body_fat_percentage( body_mass_index( mass, height ), age, sex ) );
    printf( "BMR: %.2f\n", basal_metabolic_rate( mass, height, age, sex ) );

    /* if ( sex == 1 ) { */
    /*     printf( "BFP2: %.2f%%\n", body_fat_2_men( mass, waist ) ); */
    /* } */
    return 0;
}
