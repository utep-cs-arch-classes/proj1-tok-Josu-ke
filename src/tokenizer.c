#include "stdlib.h"
#include "stdio.h"
#include "tokenizer.h"

int main(){
  char array[50]
  printf{"Type the sentence>"};
  fgets(array,50,stdin);  
  printf("%s",&array);


}


int non_space_char(char c) {  //Finds if char does not begin with a space or tab
  if (c=='\t' || c== ' ' ) {
    return 0;
  }
  return 1;

}

int space_char(char c) {     //checks that char is a space or a tab
  if (c == '\t'|| c == ' ') {
    return 1;
  }
  return 0;
}
