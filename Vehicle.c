/*  ERAN HELVITZ - 313206542*/
/*    ITAMAR DROR - 315820134*/

#include "Vehicle.h"


int car_counter = 0;
struct Vehicle emptyVechile = { "0","0",
        "0","0", "0" , 0 , 0 ,
        0 , 0  , 0};


/*creating car list - maximum 10000 cars*/
int createCarList() {
    int i;
    for (i = 0; i < N; i++) {
        carsList[i]=emptyVechile;
    }
    return 1;
}

int valid_car(char *license_num, char *chassis_number, char *maker, char *model, char *color, int year_manufacture,
              int year_get_on_road,
              int price_that_paid, int present_car_price, int engine_cap) {
    if ((check_value_size(license_num, LICENSE_NUM_LEN) == 0) || (valid_digit_check(license_num) == 0)) {
        printf("License number is not valid!\n");
        return 0;
    }
    if ((check_value_size(chassis_number, CHASSIS_NUM_LEN) == 0) || (valid_digit_check(chassis_number) == 0)) {
        printf("Chassis number is not valid!\n");
        return 0;
    }
    if ((check_value_size(maker, MAKER_LEN) == 0) || (valid_char_check(maker) == 0)) {
        printf("Maker is not valid!\n");
        return 0;
    }
    if ((check_value_size(model, MODEL_LEN) == 0) || (valid_char_check(model) == 0)) {
        printf("Model is not valid!\n");
        return 0;
    }
    if ((check_value_size(color, COLOR_LEN) == 0) || (valid_char_check(color) == 0)) {
        printf("Color is not valid!\n");
        return 0;
    }
//    if (valid_int(year_manufacture, 1930, 2022) == 0)return 0;
//    if (valid_int(year_get_on_road, 1930, 2022) == 0)return 0;
//    if (valid_int(price_that_paid, 0, 1000000) == 0)return 0;
//    if (valid_int(present_car_price, 0, 1000000) == 0)return 0;
//    if (valid_int(engine_cap, 0, 10000) == 0)return 0;
    return 1;
}

struct Vehicle init_car() {
    struct Vehicle car;
    char license_number[LICENSE_NUM_LEN * 3];
    char chassis_number[CHASSIS_NUM_LEN * 3];
    char maker[MAKER_LEN * 3];
    char model[MODEL_LEN * 3];
    char color[COLOR_LEN * 3];
    int year_manufacture;
    int year_get_on_road;
    int price_that_paid;
    int present_car_price;
    int engine_cap;
    printf("Enter license number : \n");
    scanf("%s", license_number);
    printf("Enter chassis number : \n");
    scanf("%s", chassis_number);
    printf("Enter maker : \n");
    scanf("%s", maker);
    printf("Enter model : \n");
    scanf("%s", model);
    printf("Enter color :\n");
    scanf("%s", color);
    printf("Enter year of manufacture :\n");
    scanf("%d", &year_manufacture);
    printf("Enter price that paid for the car :\n");
    scanf("%d", &price_that_paid);
    printf("Enter year that car get on road :\n");
    scanf("%d", &year_get_on_road);
    printf("Enter present car price :\n");
    scanf("%d", &present_car_price);
    printf("Enter engine capacity :\n");
    scanf("%d", &engine_cap);
    if (valid_car(license_number, chassis_number, maker, model, color, year_manufacture, year_get_on_road,
                  price_that_paid,
                  present_car_price, engine_cap) != 0) {
    strcpy(car.license_number, license_number);
    strcpy(car.chassis_number, chassis_number);
    strcpy(car.model, model);
    strcpy(car.maker, maker);
    strcpy(car.color, color);
    car.year_manufacture = year_manufacture;
    car.year_get_on_road = year_get_on_road;
    car.present_car_price = present_car_price;
    car.price_that_paid = price_that_paid;
    car.engine_cap = engine_cap;
    return car;}
    return emptyVechile;
}

void add_to_array(struct Vehicle car) {
    if (car.model == 0) return;
    carsList[car_counter] = car;
    car_counter++;
    printf("Numbers of cars in the list: %d\n", car_counter);

}

int addNewCar() {
/*add car to the list, return 1 if succeed*/
    struct Vehicle car = init_car();
    add_to_array(car);
    return 1;
}



int carNumberWithGivenCapacity() {
/* return the amount of the cars by the given engine capacity*/
    int i, capacity;
    int cap_counter = 0;
    printf("Enter the capacity of the engine: \n");
    scanf("%d", &capacity);
    for (i = 0; i < car_counter; i++) {
        if (carsList[i].engine_cap == capacity) {
            cap_counter++;
        }
    }
    return cap_counter;
}




int deleteCar() {
/* remove car from the list, return 1 if succeed*/
    int i;
    char license_number[LICENSE_NUM_LEN + 1];
    struct Vehicle swap_car;
    printf("Enter license number: \n");
    scanf("%s", license_number);
    for (i = 0; i < car_counter; i++) {
        if (strcmp(carsList[i].license_number, license_number) == 0) {
            if (car_counter > 1) {
                swap_car = carsList[car_counter - 1];
                carsList[i] = swap_car;
                carsList[car_counter-1] = emptyVechile;
                car_counter--;
                printf("Car has been deleted\n");
                return 1;

            } else {
                swap_car = carsList[car_counter - 1];
                carsList[i] = swap_car;
                carsList[car_counter-1] = emptyVechile;
                car_counter--;
                printf("Car has been deleted\n");
                return 1;
            }
        }
    }
    printf("Car has not found\n");
    return 0;
}



int deleteAllCars() {
/* delete all of the cars in the list, return 1 if succeed*/
    createCarList();
    car_counter = 0;
    return 1;
}


