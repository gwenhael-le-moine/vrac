#include <stdlib.h>
#include <stdio.h>

#include <math.h>

#define sq(x) ((x)*(x))

int main( int argc, char* argv[] ) {
   float diag;
   int resx, resy;

   if ( argc != 4 ) {
      exit( -1 );
   }
   else {
      diag = atof( argv[ 1 ] );
      resx = atoi( argv[ 2 ] );
      resy = atoi( argv[ 3 ] );
      if ( resx < resy ) {
        int tmp = resx;
        resx = resy;
        resy = tmp;
      }
      // computing screen dimensions
      float ratio = (float)resy / resx;
      float screenx = sqrtf( sq( diag ) / ( 1 + sq (ratio ) ) );
      float screeny = screenx * ratio;
      float dpi = sqrtf( ( resx * resy ) / ( screenx * screeny ) );

      printf( "ratio: %.2f, %.2f\"×%.2f\" (%.2fcm×%.2fcm)\n", ratio, screenx, screeny, screenx*2.54, screeny*2.54 );
      printf( "dpi: %.2f\n", dpi );
   }
}
