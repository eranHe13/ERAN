/* ITAMAR DROR - 315820134*/
/* ERAN HELVITZ - 313206542*/

#ifndef CAR_RENTAL_PROJECT_SUPPLIER_H
#define CAR_RENTAL_PROJECT_SUPPLIER_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define AUTH_DEALER_NUM_LEN 10
#define SUPP_NAME_LEN 5
#define SUPP_PHONE_LEN 10
#define K 50


struct Supplier {
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char supplier_name[SUPP_NAME_LEN + 1];
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    int number_of_deals_withSupp;
    long sum_of_general_deals_withSupp;
};


struct Supplier supplierList[K];
void print1();
int createSupplierList();
struct Supplier getSupplierDetails();
void addToList(struct Supplier s);
int addNewSupplier();
int deleteSupplier(char *supplier_name);
int deleteAllSuppliers();
int checkValues(char *authorized_dealer_num, char *supplier_name, char *supplier_phone_num) ;
char **threeGreatestSuppliers();

#endif
