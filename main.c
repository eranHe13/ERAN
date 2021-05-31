#include "stdio.h"
#include "ValuesChecker.c"
#include "Supplier.c"
#include "Client.c"
#include "Vehicle.c"
int checkN(char n );
void programClient();
void programVechile();
void programQuestions();
void programSupplier();
int n =8;

int checkN(char n ){
    if (n>10){printf("wrong input"); return 0;}
    return 1;
}

void program() {
    while (n != 0) {
        printf("\n");
        printf("hello user \n"
               "enter your choice :\n"
               "1 - for supplier\n"
               "2 - for client\n"
               "3 - for vehicle\n"
               "4 - for Questions\n"
               "0 - for exit\n"
               " ---->");
        scanf("%d", &n);
        if (checkN(n) == 0 ){program(); }

        if (n == 1) { programSupplier(); }
        if (n == 2) { programClient(); }
        if (n == 3) { programVechile(); }
        if (n == 4) { programQuestions(); }

    }
}

void programQuestions(){
    if (n==4){
        printf("enter your choice :\n"
               "1 - get number of clients with the same car Year of manufacture \n"
               "2 - get num of vehicles with the same capacity\n"
               "3 - get the three big supplier\n"
               "4 - for delete all vehicle\n");}
    scanf("%d" , &n );

}


void programVechile(){
    printf("enter your choice :\n"
           "1 - for crate vehicle list\n"
           "2 - for add vehicle\n"
           "3 - for delete vehicle\n"
           "4 - for delete all vehicle\n");
    scanf("%d" , &n );

    if (n==1){createCarList();}
    if (n==2){addNewCar();}
    if (n==3){deleteCar();}
    if (n==4){deleteAllCars();}
    program();
}


void programClient(){
    printf("enter your choice :\n"

           "1 - for crate client list\n"
           "2 - for add client\n"
           "3 - for delete client\n"
           "4 - for delete all clients\n"
           "5 - return \n");
    scanf("%d" , &n );
    if (n==1){createClientList();}
    if (n==2){addNewClient();}
    if (n==3){deleteClient();}
    if (n==4){deleteAllClients();}
    program();
}


void programSupplier(){
    printf("enter your choice :\n"
           "1 - for crate supplier list\n"
           "2 - for add supplier\n"
           "3 - for delete supplier\n"
           "4 - for delete all suppliers\n"
           "6 - for FOR PRINT \n");
    scanf("%d", &n);
    if (n == 1){createSupplierList();}
    if (n==2){addNewSupplier(); n=7;}
    if (n==3){
        char* name;
        printf("enter supplier name: \n");
        scanf("%s" , name);
        deleteSupplier(name);}
    if (n==4){deleteAllSuppliers();}
    if (n==5){print1();}
    program();
}



int main() {
    program();

    //addNewSupplier();
//    int n;
//    printf("dfdfd");
//    scanf("%d" ,&n);
//    if (n==5){printf("good");}
//    else { printf("bad");}
    return 0;
}
