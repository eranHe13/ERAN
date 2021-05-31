/*  ERAN HELVITZ - 313206542*/
/*    ITAMAR DROR - 315820134*/
#include "Commom.h"

int clientNumberWithGivenCarYear() {
    List* list
    int car_manu;
    int num_of_car_same_year = 0;
    printf("Enter year of car manufacture: \n");
    scanf("%d",&car_manu);

    for (i = 0; i < N; i++) {
        if (carsList[i].year_manufacture == car_manu) {
            for (j = 0; j < M; j++) {
                if (strcmp(carsList[i].license_number, clientsList[j].license_number) == 0) num_of_car_same_year++;
            }
        }
    }
    return num_of_car_same_year;
}

/* returns the number of clients using the cars from the given year */
