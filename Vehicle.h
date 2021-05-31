/*  ERAN HELVITZ - 313206542*/
/*    ITAMAR DROR - 315820134*/

#ifndef CAR_RENTAL_PROJECT_VEHICLE_H
#define CAR_RENTAL_PROJECT_VEHICLE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LICENSE_NUM_LEN 10
#define CHASSIS_NUM_LEN 5
#define MAKER_LEN 5
#define MODEL_LEN 10
#define COLOR_LEN 7
#define N 10000

struct Vehicle {
    char license_number[LICENSE_NUM_LEN + 1];
    char chassis_number[CHASSIS_NUM_LEN + 1];
    char maker[MAKER_LEN + 1];
    char model[MODEL_LEN + 1];
    char color[COLOR_LEN+1];
    int year_manufacture;
    int year_get_on_road;
    int price_that_paid;
    int present_car_price;
    int engine_cap;
};
struct Vehicle carsList[N];
int createCarList();
int addNewCar();
int carNumberWithGivenCapacity();
int deleteCar();
int deleteAllCars();
int valid_car(char *license_num, char *chassis_number, char *maker, char *model, char *color, int year_manufacture,
              int year_get_on_road,
              int price_that_paid, int present_car_price, int engine_cap);
struct Vehicle init_car();
void add_to_array(struct Vehicle car);
#endif
