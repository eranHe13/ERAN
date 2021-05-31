/* ERAN HELVITZ - 313206542*/
/* ITAMAR DROR - 315820134*/



#ifndef CAR_RENTAL_PROJECT_VALUESCHECKER_H
#define CAR_RENTAL_PROJECT_VALUESCHECKER_H
#include <string.h>
#include <stdio.h>

int isLetter(char letter);
int isDigit(char isNum);
int valid_char_check(char *str);
int valid_digit_check(char *str);
int date_valid(int year, int month, int day);
void smaller_than_ten(int num);
int time_valid(int hour, int minute);
int check_value_size(char* str,int size);
int valid_int(int num,int min,int max);
#endif
