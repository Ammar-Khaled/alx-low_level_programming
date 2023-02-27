/*******************************************************************************
*
* Program: Random Password Generator
* 
* Description: Generates random passwords of a user-specified length using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=laIQbFLznRo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
  int length, i;
  char *password;
  char *digits;
  char *lowers;
  char *uppers;
  char *symbols;
  int digits_length, lowers_length, uppers_length, symbols_length;
  
  printf("Length: ");
  


  scanf("%d", &length);
  


  if (length <= 0)
  {

    printf("Password length must be >= 1!");


    return 1;
  }
  
  password = malloc(length + 1);


  digits = "0123456789";
   digits_length = strlen(digits);
  
  lowers = "abcdefghijklmnopqrstuwxyz";
   lowers_length = strlen(lowers);
  
  uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   uppers_length = strlen(uppers);
  
  symbols = "!@#$%^&*()";
   symbols_length = strlen(symbols);
    

  srand(time(NULL) * getpid());
  
  for (i = 0; i < length; i++)
  {
    int char_type = rand() % 4;
    
    if (char_type == 0)
      password[i] = digits[rand() % digits_length];
    else if (char_type == 1)
      password[i] = lowers[rand() % lowers_length];
    else if (char_type == 2)
      password[i] = uppers[rand() % uppers_length];
    else
      password[i] = symbols[rand() % symbols_length];
    
  }

   password[length] = '\0';
  
  printf("Password: %s\n", password);
  free(password);


  return 0;
}
