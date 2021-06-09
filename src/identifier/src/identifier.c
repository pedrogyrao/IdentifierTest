

#include <stdio.h>
#include "identifier.h"


int valid_s(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    return 1;
  else
    return 0;
}

int valid_f(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
    return 1;
  else
    return 0;
}

int identifier(char string[]) {
  char achar;
  int  length, valid_id;
  length = 0;

  achar = string[length];
  valid_id = valid_s(achar);
  if(valid_id) {
    length = 1;
  }
  // else {
  //   return 0;
  // }
  achar = string[length];
  while(achar != '\n') {
    if(!(valid_f(achar))) {
      valid_id = 0;
    }
    length++;
    achar = string[length];
  }

  if (valid_id && (length >= 1) && (length < 6)) {
    return 0;
  }
  else {
    return 1;
  }
}
