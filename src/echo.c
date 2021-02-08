#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
  char input[400];
  
  printf("$");
 
   fgets(input,400,stdin);

printf("%s",&input);
}
