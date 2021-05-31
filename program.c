//
// Created by User on 06/05/2021.
//

#include "program.h"

//
//int n ;
//void program() {
//    while (n != 0) {
//        printf("hello user \n"
//               "enter your choice :\n"
//               "1 - for supplier\n"
//               "2 - for client\n"
//               "3 - for vehicle\n"
//               "4 - for Questions\n"
//               "0 - for exit\n");
//        scanf("%d", &n);
//
//        if (n == 1) { programSupplier(); }
//        if (n == 2) { programClient(); }
//        if (n == 3) { programVechile(); }
//        if (n == 4) { programQuestions(); }
//
//    }
//}
//
//    void programQuestions(){
//        if (n==4){
//            printf("enter your choice :\n"
//                   "1 - get number of clients with the same car Year of manufacture \n"
//                   "2 - get num of vehicles with the same capacity\n"
//                   "3 - get the three big supplier\n"
//                   "4 - for delete all vehicle\n");}
//        scanf("%d" , &n );
//
//    }
//
//
//    void programVechile(){
//        printf("enter your choice :\n"
//               "1 - for crate vehicle list\n"
//               "2 - for add vehicle\n"
//               "3 - for delete vehicle\n"
//               "4 - for delete all vehicle\n");
//        scanf("%d" , &n );
//
//        if (n==1){createCarList();}
//        if (n==2){addNewCar();}
//        if (n==3){deleteCar();}
//        if (n==4){deleteAllCars();}
//    }
//
//
//void programClient(){
//        printf("enter your choice :\n"
//
//               "1 - for crate client list\n"
//               "2 - for add client\n"
//               "3 - for delete client\n"
//               "4 - for delete all clients\n"
//               "5 - return \n");
//        scanf("%d" , &n );
//        if (n==1){createClientList();}
//        if (n==2){addNewClient();}
//        if (n==3){
//            char* id;
//            printf("enter client id : ");
//            scanf("%s" , id);
//            deleteClient(id);}
//        if (n==4){deleteAllClients();}
//        if (n==5){program();}
//    }
//
//
//    void programSupplier(){
//        printf("enter your choice :\n"
//               "1 - for crate supplier list\n"
//               "2 - for add supplier\n"
//               "3 - for delete supplier\n"
//               "4 - for delete all suppliers\n"
//               "5 - for return \n");
//        scanf("%d", &n);
//        if (n == 1){createSupplierList();}
//        if (n==2){addNewSupplier();}
//        if (n==3){
//            char* name;
//            printf("enter supplier name: \n");
//            scanf("%s" , name);
//            deleteSupplier(name);}
//        if (n==4){deleteAllSuppliers();}
//        if (n==5){program();}
//    }