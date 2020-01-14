#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 20
#define COLUMNS 40

int main ( int argc, char *argv[] ) {

   char cGrid[ROWS][COLUMNS + 1];
   char fGrid[ROWS][COLUMNS + 1];
   char seedRead;
   char input[2];
   int i = 0;
   int j = 0;
   int k = 0;
   int l = 0;
   int tick = 0;
   int alive = 0;
   int stop = 50;
   

   FILE *f1;

   if ( (f1 = fopen(argv[1], "r")) != NULL ) {
      
      seedRead = fgetc(f1);
      while ( seedRead != EOF ) {
         
         if ( (seedRead > 47) && (seedRead < 58) ) {
            
            if (seedRead == '1') {
               seedRead = 'X';
            }
      
            if (seedRead == '0') {
               seedRead = ' ';
            }
            
            fGrid[i][j] = seedRead;
            j++;

            if ( j == 40 ) {
               i++;
               j = 0;
            }
            
            
         }
         
         seedRead = fgetc(f1);
      }
   } else {
      printf ( "Cannot open %s\n", argv[1] );
      return ( -2 );
   }

   fclose(f1);
   
   int done = 0;

   while ( done == 0 ) {

      system( "clear" );
      
      for ( i = 0; i < 20; i++) {
         for ( j = 0; j < 40; j++ ) {
            cGrid[i][j] = fGrid[i][j];
         }
      }

      printf (" ");
      for (i = 0; i < 42; i++) {
         printf("-");
      }
      printf ("\n");

      for (i = 0; i < 20; i++) {
         printf ("| ");
         for (j = 0; j < 40; j++) {
            printf ("%c", cGrid[i][j]);
         }
         printf (" |\n");
      }

      printf (" ");
      for (i = 0; i < 42; i++) {
         printf("-");
      }
      printf ("%d", tick);
      printf ("\n");

      if (tick == 0) {
         printf("Start? (y or n): \n");
         fgets(input, 10, stdin);

         if (input[0] == 'N' || input[0] == 'n') {
            done = 1;
         }
      }

      if (argc == 3) {
         stop = atoi(argv[2]);
      }

      if (((tick % stop) == 0) && (tick != 0)) {
         printf("Continue? (y or n): \n");
         fgets(input, 10, stdin);

         if (input[0] == 'N' || input[0] == 'n') {
            done = 1;
         }
      }

      tick++;

      for (i = 0; i < 20; i++) {
         for (j = 0; j < 40; j++) {
         
            alive = 0;
            k = i;
            l = j;

            k++;
            
            if ( k >= 0 && k < 40 && l >= 0 && l < 40 && cGrid[k][l] == 'X') {
               alive++;
            }

            l++;

            if ( k >= 0 && k < 40 && l >= 0 && l < 40 && cGrid[k][l] == 'X') {
               alive++;
            }

            k--;

            if ( k >= 0 && k < 40 && l >= 0 && l < 40 && cGrid[k][l] == 'X') {
               alive++;
            }

            k--;
         
            if ( k >= 0 && k < 40 && l >= 0 && l < 40 && cGrid[k][l] == 'X') {
               alive++;
            }

            l--;

            if ( k >= 0 && k < 40 && l >= 0 && l < 40 && cGrid[k][l] == 'X') {
               alive++;
            }

            l--;

            if ( k >= 0 && k < 40 && l >= 0 && l < 40 && cGrid[k][l] == 'X') {
               alive++;
            }

            k++;

            if ( k >= 0 && k < 40 && l >= 0 && l < 40 && cGrid[k][l] == 'X') {
              alive++;
            }

            k++;

            if ( k >= 0 && k < 40 && l >= 0 && l < 40 && cGrid[k][l] == 'X') {
               alive++;
            }

            if (cGrid[i][j] == 'X') {
               if (alive < 2) {
                  fGrid[i][j] = ' ';
               } else if (alive < 4) {
                  fGrid[i][j] = 'X';
               } else if (alive > 3) {
                  fGrid[i][j] = ' ';
               }
            }

            if (cGrid[i][j] == ' ') {
               if (alive == 3) {
                  fGrid[i][j] = 'X';
               }
            }

         }
      }

      int done2 = 0;
      
      while ( done2 == 0 ) {
         
         for ( i = 0; i < 20; i++) {

            cGrid[i][40] = '\0';
            fGrid[i][40] = '\0';

            if (strcmp( cGrid[i], fGrid[i]) != 0) {
               done2 = 1;
            }
         }
         
         if (done2 == 0) {
            done2 = 1;
            done = 1;
         }
      }

      system( "sleep 0.25" );
      
   }


   return 0;
}
