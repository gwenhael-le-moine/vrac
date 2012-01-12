#include <stdio.h>

int main( void )
{
    int i, result = 0;
    for( i = 1000 ; --i; ) {
        if ( ( i % 3 == 0) || ( i % 5 == 0 ) ) {
            result += i;
        }
    }
    printf( "%i\n", result );
}
