//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";gcc --std=c99 -o "$x" "$0")&&"$x" $*;exit
// ^^ this up there makes the file executable ^^

#include <stdio.h> 

#define N 40

long fib_memoized[ N+1 ];

long fib( unsigned int n )
{
    if ( fib_memoized[ n ] == 0 ) {
        if ( n < 3 ) {
            fib_memoized[ n ] = n;
        } else {
            fib_memoized[ n ] = fib( n - 1 ) + fib( n - 2 );
        }
    }

    return fib_memoized[ n ];
}

int main( void )
{
    int n = 0;
    int sum = 0;
    
    /* initialize fib_memoized */
    for ( int i = 0 ; i<N+1 ; i++ ) { fib_memoized[ i ] = 0; }

    while( fib( n ) < 4000001 ) {
        if ( fib( n ) % 2 == 0 ) {
            sum += fib( n );
        }

        n++;
    };
    printf( "\n%d\n", sum );

    return 0;
}
