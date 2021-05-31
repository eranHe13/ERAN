/* ERAN HELVITZ - 313206542*/
/* ITAMAR DROR - 315820134*/




#include "ValuesChecker.h"


int isLetter(char letter) {
    /* check if the given char is a letter */
    if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122)) {
        return 1;
    } else return 0;
}

int isDigit(char isNum) {
    /* check if the given char is a number */
    if (isNum > 47 && isNum <= 57) return 1;
    else return 0;
}
int valid_char_check(char *str) {
    int i;
    if (strlen(str) == 0)return 0;
    for (i = 0; i < strlen(str); i++) {
        if (isLetter(str[i]) == 0) return 0;
    }
    return 1;
}

int valid_digit_check(char *str) {
    int i;
    if (strlen(str) == 0)return 0;
    for (i = 0; i < strlen(str); i++) {
        if (isDigit(str[i]) == 0) return 0;
    }
    return 1;
}

int date_valid(int year, int month, int day) {
    int month_with_30[4] = {4, 6, 9, 11};

    if (year < 1930 || year > 2022) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    if (day > 30) {
        int i;
        for (i = 0; i < 4; i++) {
            if (month == month_with_30[i]) {
                return 0;
            }
        }
    }
    if (month == 2 && day > 28) {
        return 0;
    }
    return 1;
}

void smaller_than_ten(int num) {
    if (num < 10 && num >= 0) {
        printf("0");
    }
}

int time_valid(int hour, int minute) {
    if (hour < 0 || hour > 23) {
        return 0;
    }
    if (minute < 0 || minute > 60) {
        return 0;
    }
    return 1;
}
int check_value_size(char* str,int size){
    if (strlen(str)==0)return 0;
    if (strlen(str)>size)return 0;
    else return 1;
}

int valid_int(int num,int min,int max){
    if (num<min || num>max){
        printf("%d is not valid!\n",num);
        return 0;
    } else return 1;
}