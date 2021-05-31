/*  ERAN HELVITZ - 313206542*/
/*    ITAMAR DROR - 315820134*/
#include "Client.h"


int client_counter = 0;



struct Date create_date(int year, int month, int day) {
    struct Date today;
    if (date_valid(year, month, day) == 0) {
        today.year = -1;
        today.month = -1;
        today.day = -1;
    } else {
        today.year = year;
        today.month = month;
        today.day = day;
    }
    return today;
}

void print_date(struct Date d) {
    smaller_than_ten(d.day);
    printf("%d/", d.day);
    smaller_than_ten(d.month);
    printf("%d/%d\n", d.month, d.year);
}

struct Time create_time(int hour, int minute) {
    struct Time current_hour;
    if (time_valid(hour, minute) == 0) {
        current_hour.hour = -1;
        current_hour.minute = -1;
    } else {
        current_hour.hour = hour;
        current_hour.minute = minute;
    }
    return current_hour;
}

void print_time(struct Time t) {
    smaller_than_ten(t.hour);
    printf("%d:", t.hour);
    smaller_than_ten(t.minute);
    printf("%d\n", t.minute);
}

int createClientList() {
    int i;
    for (i = 0; i < M; ++i) {
        strcpy(clientsList[i].id, "");
        strcpy(clientsList[i].first_name, "");
        strcpy(clientsList[i].last_name, "");
        clientsList[i].date_of_rent.year = -1;
        clientsList[i].date_of_rent.month = -1;
        clientsList[i].date_of_rent.day = -1;
        clientsList[i].hour_of_rent.hour = -1;
        clientsList[i].hour_of_rent.minute = -1;
        strcpy(clientsList[i].license_number, "");
        clientsList[i].price_per_rent = -1;
    }
    return 1;
}

/*creates clients list - maximum 8000 clients*/


int client_valid(struct Client client) {
    if (valid_char_check(client.first_name) == 0)return 0;
    if (valid_char_check(client.last_name) == 0)return 0;
    if (valid_digit_check(client.id) == 0)return 0;
    if (valid_digit_check(client.license_number) == 0)return 0;
    if (client.date_of_rent.year == -1)return 0;
    if (client.hour_of_rent.hour == -1)return 0;
    if (client.price_per_rent > 999)return 0;
    return 1;
}

struct Client init_client() {
    struct Client client;
    char id[ID_LEN * 3], first_name[FIRST_NAME_LEN * 3], last_name[LAST_NAME_LEN * 3], license_num[LICENSE_LEN * 3];
    struct Date date_of_rent;
    int year, month, day, hour, minute;
    struct Time time_of_rent;
    int price_per_rent;
    printf("Enter ID: \n");
    scanf("%s", id);
    printf("Enter first name: \n");
    scanf("%s", first_name);
    printf("Enter last name: \n");
    scanf("%s", last_name);
    printf("Enter license number: \n");
    scanf("%s", license_num);
    printf("Enter date: year , month , day\n");
    scanf("%d %d %d", &year, &month, &day);
    printf("Enter time: hour , minute\n");
    scanf("%d %d", &hour, &minute);
    printf("Enter price per rent for 24 hours: \n");
    scanf("%d", &price_per_rent);
    if (strlen(id) > ID_LEN)strcpy(client.id, "");
    else strcpy(client.id, id);
    if (strlen(first_name) > FIRST_NAME_LEN)strcpy(client.first_name, "");
    else strcpy(client.first_name, first_name);
    if (strlen(last_name) > LAST_NAME_LEN)strcpy(client.last_name, "");
    else strcpy(client.last_name, last_name);
    if (strlen(license_num) > LICENSE_LEN)strcpy(client.license_number, "");
    else strcpy(client.license_number, license_num);
    client.price_per_rent = price_per_rent;
    date_of_rent = create_date(year, month, day);
    time_of_rent = create_time(hour, minute);
    client.date_of_rent = date_of_rent;
    client.hour_of_rent = time_of_rent;
    return client;

}

void client_to_array(struct Client client) {
    clientsList[client_counter] = client;
    client_counter++;
}

int addNewClient() {
    struct Client check = init_client();
    if (client_valid(check) == 1) {
        client_to_array(check);
    } else return 0;
    printf("number of clients: %d\n", client_counter);
    return 1;

}

/*adds client to the list, return 1 if succeed*/

int deleteClient() {
    int i;
    struct Client swap_client;
    char id[ID_LEN + 1];
    printf("Enter ID: \n");
    scanf("%s", id);
    for (i = 0; i < client_counter; ++i) {
        if (strcmp(id, clientsList[i].id) == 0) {
            if (client_counter > 1) {
                swap_client = clientsList[client_counter - 1];
                strcpy(clientsList[i].id, "");
                strcpy(clientsList[i].first_name, "");
                strcpy(clientsList[i].last_name, "");
                clientsList[i].date_of_rent.year = -1;
                clientsList[i].date_of_rent.month = -1;
                clientsList[i].date_of_rent.day = -1;
                clientsList[i].hour_of_rent.hour = -1;
                clientsList[i].hour_of_rent.minute = -1;
                strcpy(clientsList[i].license_number, "");
                clientsList[i].price_per_rent = -1;
                clientsList[client_counter - 1] = clientsList[i];
                clientsList[i] = swap_client;
                client_counter--;
                printf("number of clients: %d\n", client_counter);
                return 1;
            } else {
                strcpy(clientsList[i].id, "");
                strcpy(clientsList[i].first_name, "");
                strcpy(clientsList[i].last_name, "");
                clientsList[i].date_of_rent.year = -1;
                clientsList[i].date_of_rent.month = -1;
                clientsList[i].date_of_rent.day = -1;
                clientsList[i].hour_of_rent.hour = -1;
                clientsList[i].hour_of_rent.minute = -1;
                strcpy(clientsList[i].license_number, "");
                clientsList[i].price_per_rent = -1;
                client_counter--;
                return 1;
            }
        }
    }
    return 0;
}

/*remove client by id from the list, return 1 if succeed*/

int deleteAllClients() {
    createClientList();
    client_counter = 0;
    return 1;
}
/*remove all clients from the list, return 1 if succeed*/
