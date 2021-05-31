/* ERAN HELVITZ - 313206542*/
/* ITAMAR DROR - 315820134*/



#include "Supplier.h"

struct Supplier emptySupplier ={"0" , "", "0" ,
        0 , 0};


int counterSupplier = 0;
int i;
int j;
char three_great_supp[3][AUTH_DEALER_NUM_LEN + 1];


void print1() {
    for (i = 0; i < counterSupplier ; i++) {
        printf("%d-\n name :  %s \n- authorized_dealer_num :  %s \n- supplier_phone_num:  %s\n"
               "- number deals :%d %d\n- sum deals : %lu\n",i+1, supplierList[i].supplier_name, supplierList[i].authorized_dealer_num,
                       supplierList[i].number_of_deals_withSupp ,supplierList[i].sum_of_general_deals_withSupp);}
}

int checkValues(char *authorized_dealer_num, char *supplier_name, char *supplier_phone_num) {
    /*check if the values input is according the legality*/
    /*LEN CHECK*/
    if ((strlen(authorized_dealer_num) > 10)) {
        printf("authorized_dealer_num too long\n");
        return 0;
    }
    if ((strlen(supplier_name) > 6)) {
        printf("supplier_name too long\n");
        return 0;
    }

    if ((strlen(supplier_phone_num) > 10)) {
        printf("supplier_phone_num too long\n");
        return 0;
    }
    /*DIGIT-CHAR CHEK*/
    for (i = 0; i < strlen(authorized_dealer_num); ++i) {
        if (isDigit(authorized_dealer_num[i]) == 0) {
            printf("authorized_dealer_num not right\n");
            return 0;
        }
        if (isDigit(supplier_phone_num[i]) == 0) {
            printf("supplier_phone_num not right\n");
            return 0;
        }
    }
    /*LETTER CHECK*/
    for (i = 0; i < strlen(supplier_name); ++i) {
        if (isLetter(supplier_name[i]) == 0) {
            printf("supplier name not right\n");
            return 0;
        }
    }

    return 1;
}

int createSupplierList(){
    for (i = 0; i < K; ++i) {
        supplierList[i] = emptySupplier;
    }
    return 1;
}

struct Supplier getSupplierDetails() {
    /*THE FUNC GET AND SET DETAILS OF THE SUPPLIER*/
    char authorized_dealer_num[AUTH_DEALER_NUM_LEN + 1];
    char supplier_name[SUPP_NAME_LEN + 1];
    char supplier_phone_num[SUPP_PHONE_LEN + 1];
    int sum_of_general_deals_withSupp;
    int number_of_deals_withSupp;
    struct Supplier temporarySupp;

    printf("enter authorized_dealer_num : ");
    scanf("%s", authorized_dealer_num);
    printf("enter supplier_name : ");
    scanf("%s", supplier_name);
    printf("enter  supplier_phone_num : ");
    scanf("%s", supplier_phone_num);
    printf("enter  number_of_deals_withSupp : ");
    scanf("%d", &number_of_deals_withSupp);
    printf("enter  sum_of_general_deals_withSupp : ");
    scanf("%d", &sum_of_general_deals_withSupp);

    if (checkValues(authorized_dealer_num, supplier_name, supplier_phone_num) != 0) {

        strcpy(temporarySupp.supplier_phone_num, supplier_phone_num);
        strcpy(temporarySupp.supplier_name, supplier_name);
        strcpy(temporarySupp.authorized_dealer_num, authorized_dealer_num);
        temporarySupp.sum_of_general_deals_withSupp = sum_of_general_deals_withSupp;
        temporarySupp.number_of_deals_withSupp = number_of_deals_withSupp;

    }
    return temporarySupp;
}

void addToList(struct Supplier s) {
    /*ADD THE SUPPLIER TO THE ARRAY*/
    supplierList[counterSupplier] = s;
    printf("\n\n");

    counterSupplier++;
}

int addNewSupplier() {
    /* add new supplier to the list  , return 1 if succeed */
    struct Supplier s = getSupplierDetails();
    addToList(s);
    return 1;
}


int deleteSupplier(char *supplier_name) {
    /*remove supplier from the list by name,  return 1 if succeed*/
    char* S_name_del;
    struct Supplier swapSupplier;
    for (i = 0; i < counterSupplier; ++i) {
        if (strcmp(supplier_name, supplierList[i].supplier_name) == 0)
        {   strcmp(S_name_del , supplierList[i].supplier_name);
            swapSupplier = supplierList[counterSupplier-1];
            supplierList[i] = swapSupplier;
            supplierList[counterSupplier-1] = emptySupplier;
            printf("supplier %s removed\n\n", S_name_del);
            counterSupplier--;
            return 1;
        }
    }
    printf("supplier name doesnt found\n\n");
    return 0;
}


int deleteAllSuppliers() {

    /* remove all suppliers from the list , return 1 if succeed*/
    for (i = 0; i < counterSupplier; ++i) {
        supplierList[i] = emptySupplier;
    }
    counterSupplier = 0;
    return 1;

}

char **threeGreatestSuppliers() {
/*the function return array of three suppliers with the biggest amount of deals*/
    int index;
    int three_index = 0;
    int count_down = 3;
    long big_check = 0;
    while (count_down > 0) {
        for (i = 0; i < counterSupplier; i++) {
            for (j = 0; j < 2; j++) {
                if ((strcmp(supplierList[i].authorized_dealer_num, three_great_supp[0]) != 0) &&
                    (strcmp(supplierList[i].authorized_dealer_num, three_great_supp[1]) != 0) &&
                            (supplierList[i].sum_of_general_deals_withSupp > big_check)) {
                    big_check = supplierList[i].sum_of_general_deals_withSupp;
                    index = i;
                }
            }
        }
        strcpy(three_great_supp[three_index], supplierList[index].authorized_dealer_num);
        big_check = 0;
        three_index++;
        count_down--;
    }

    printf("%s\n", three_great_supp[0]);
    printf("%s\n", three_great_supp[1]);
    printf("%s\n" , three_great_supp[2]);
    return (char **) three_great_supp;
}


