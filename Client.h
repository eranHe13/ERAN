/*  ERAN HELVITZ - 313206542*/
/*    ITAMAR DROR - 315820134*/

#ifndef CAR_RENTAL_PROJECT_CLIENT_H
#define CAR_RENTAL_PROJECT_CLIENT_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ValuesChecker.h"
#include <ctype.h>
#define LICENSE_LEN 10
#define FIRST_NAME_LEN 20
#define LAST_NAME_LEN 20
#define ID_LEN 9
#define M 8000
#define TRUE 1
#define FALSE 0

struct Date {
    int year;
    int month;
    int day;
};
struct Date create_date(int year, int month, int day);
void print_date(struct Date d);

struct Time {
    int hour;
    int minute;
};
struct Time create_time(int hour, int minute);
void print_time(struct Time t);


struct Client {
    char first_name[FIRST_NAME_LEN + 1];
    char last_name[LAST_NAME_LEN + 1];
    char id[ID_LEN + 1];
    char license_number[LICENSE_LEN+1];
    struct Date date_of_rent;
    struct Time hour_of_rent;
    int price_per_rent;
};
struct Client clientsList[M];
int createClientList();

int addNewClient();

int deleteClient();

int deleteAllClients();


#endif
