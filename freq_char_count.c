



#include <stdio.h>
#include <string.h>
 
int main()
{
   char string[100]="Hi this is livin sunny";
   int c = 0, count[26] = {0};
 
   //printf("Enter a string\n");
   //gets(string);
 
   while ( string[c] != '\0' )
   {
      /* Considering characters from 'a' to 'z' only */
 
      if ( string[c] >= 'a' && string[c] <= 'z' ) 
         printf("%d",count[string[c]-'a']++);
 
      c++;
   }
 
   for ( c = 0 ; c < 26 ; c++ )
   {
      if( count[c] != 0 )
         
         printf("%c occurs %d times in the entered string.\n",c+'a',count[c]);
   }
 
   return 0;
}