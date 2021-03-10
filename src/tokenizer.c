#include "stdlib.h"
#include "stdio.h"
#include "tokenizer.h"

int main(){
  char array[50];
  int index =0;
  printf("Type the sentence> ");
  fgets( array, 50, stdin);
  char* p = array;
  char** tokens = tokenize(p);
  print_tokens(tokens);
}

int string_length(char* str) {//added helper method to help me find length of array easier
  int length=0;
  for (int i = 0; str[i]; i++) { //iterate through the whole string
    length++; 
  }
  return length;
}

char *word_start(char *str) {
  int index=0;
  while (*str == ' ') {
    if (*str == '\0') {            //checks if the string reaches the null character
      return str;
    }
    index++;
    str++; //moves to the next character in the string
  }
  return str;
}


char *word_end(char *str){
  int index=0;
  while (*str !='\0') {
    if (str[index]=='\t' || str[index]== ' ' ){
      return str;
    }
    str++;
  }
  return str;
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

/*method to count words in string, when a non space character is found function will keep iterating
  until space is found and add 1 to words and so on*/

int count_words(char *str) {
  int counter;
  int words=0;
  while (str[0]) { 

    str = word_start(str);
    str = word_end(str);
    words++;
  }
  return words;

}

char *copy_str(char *inStr, short len) {
  
  char* temp =word_start(inStr);
  int wordLength = (string_length(inStr) - string_length(word_end(inStr))) + 1;//finds length of fi                                                                                           rst word
  char* wordCopy = (char*) malloc((wordLength + 1)*sizeof(char*)); //allocates memory for that word
  for (int i =0; i < wordLength; i++) {//this for loop will copy the first word of the char array
    wordCopy[i] = temp[i];           // to wordCopy
  }
  return wordCopy;
}

void print_tokens( char **tokens) {
  for (int i=0; *tokens; i++) {  //iterates through the whole array
   
  printf("token at [%i] is %s\n",i,*tokens);//prints every element
  tokens++;
 }
}

/* Frees all tokens*/
void free_tokens(char **tokens) {
  int i =0;
  while (*tokens[i]) {
    free(tokens[i]);//frees tokens
    i++;
    tokens++;
  }
  return;
}

/* tokenize allows us to use copy_str to copy first
   word from string and places it into tokens array*/

//Know what malloc does
//Know C format
// Terminate null array correctly

char **tokenize(char* str) {
  int wordTotal = count_words(str);
  char *temp = str;
  char *terminate="0";
  char **tokens = (char**) malloc((wordTotal + 1) * sizeof(char*));//allocates memory for char**
  for (int i =0; i < wordTotal; i++) {
    temp = word_start(temp);//makes sure word does not count spaces
    tokens[i] = copy_str(temp,wordTotal);
    temp = word_end(temp);
  }
  tokens[wordTotal] = terminate;
    // copy_str(terminate,wordTotal);
  return tokens;

}
