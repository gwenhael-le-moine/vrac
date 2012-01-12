//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";gcc --std=c99 -o "$x" "$0")&&"$x" $*;exit
// ^^ this up there makes the file executable ^^

#include <stdio.h> 

#define M 600851475143
#define MAX_NB_PRIMES 50
int pn;

long primes[ MAX_NB_PRIMES ];

int is_prime( long n )
{
    if ( n % 2 == 0 ) {
        return 0;
    } else {
        for
    }
}

void calc_primes_up_to( long n )
{
    long p = 2;
    
    pn = 0;

    primes[ pn ] = p;
    while( ( p < M ) && ( pn < MAX_NB_PRIMES ) ) {
        p += 2;
    }
}

int main( void )
{

    return 0;
}
