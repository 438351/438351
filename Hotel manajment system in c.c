//Group Project using C Programing Language
// Project name:Hotel Management System
/*Introduction of team members
1st member:Fatema Khanom ID:09
2nd member:Ashik Akanda ID:16
3rd member:Maliha Anjum Diya ID:19
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 100
// Stucture of Hotel
struct Hotel
{
    int room_number;
    char name[50];
    int age;
    char gender[10];
    char address[100];
};

struct Hotel records[MAX_RECORDS];

int num_records = 0;
// Information insert function
void insert_record()
{
    if (num_records == MAX_RECORDS)
    {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    struct Hotel h;
    printf("Enter room number: ");
    scanf("%d", &h.room_number);

    for (int i = 0; i < num_records; i++)
    {
        if (records[i].room_number == h.room_number)
        {
            printf("Error: Room already booked.\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf("%s", h.name);
    printf("Enter age: ");
    scanf("%d", &h.age);
    printf("Enter gender: ");
    scanf("%s", h.gender);
    printf("Enter address: ");
    scanf("%s", h.address);

    records[num_records++] = h;
    printf("Record added successfully.\n");
}
// Information search function
void search_record()
{
    int room_number;
    printf("Enter room number to search: ");
    scanf("%d", &room_number);

    int found = 0;
    for (int i = 0; i < num_records; i++)
    {
        if (records[i].room_number == room_number)
        {
            printf("Record found:\n");
            printf("Room Number: %d\n", records[i].room_number);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Gender: %s\n", records[i].gender);
            printf("Address: %s\n", records[i].address);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Information delete function
void delete_record()
{
    int room_number;
    printf("Enter room number to delete: ");
    scanf("%d", &room_number);

    int found = 0;
    for (int i = 0; i < num_records; i++)
    {
        if (records[i].room_number == room_number)
        {
            found = 1;
            for (int j = i; j < num_records - 1; j++)
            {
                records[j] = records[j+1];
            }
            num_records--;
            printf("Record deleted successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Information showing function
void show_records()
{
    if (num_records == 0)
    {
        printf("No records found.\n");
        return;
    }

    printf("Room Number\tName\tAge\tGender\tAddress\n");
    for (int i = 0; i < num_records; i++)
    {
        printf("%d\t\t%s\t%d\t%s\t%s\n", records[i].room_number, records[i].name,
               records[i].age, records[i].gender, records[i].address);
    }
}
// Information update function
void update_record()
{
    int room_number;
    printf("Enter room number to update: ");
    scanf("%d", &room_number);

    int found = 0;
    for (int i = 0; i < num_records; i++)
    {
        if (records[i].room_number == room_number)
        {
            printf("Enter new name (or press Enter to keep current): ");
            char new_name[50];
            scanf("%s", new_name);
            if (strlen(new_name) > 0)
            {
                strcpy(records[i].name, new_name);
            }
            printf("Enter new age (or press 0 to keep current): ");
            int new_age;
            scanf("%d", &new_age);
            if (new_age > 0)
            {
                records[i].age = new_age;
            }
            printf("Enter new gender (or press Enter to keep current): ");
            char new_gender[10];
            scanf("%s", new_gender);
            if (strlen(new_gender) > 0)
            {
                strcpy(records[i].gender, new_gender);
            }
            printf("Enter new address (or press Enter to keep current): ");
            char new_address[100];
            scanf("%s", new_address);
            if (strlen(new_address) > 0)
            {
                strcpy(records[i].address, new_address);
            }
            found = 1;
            printf("Record updated successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
//Main function
int main()
{
    int choice;
    do
    {
        printf("\n\n\n\t\t\tHotel Management System\n");
        printf("\n\n\t\t*************************************************\n");
	    printf("\t\t*                                               *\n");
	    printf("\t\t*       -----------------------------           *\n");
	    printf("\t\t*            WELCOME TO HOTEL RELAX             *\n");
	    printf("\t\t*       -----------------------------           *\n");
	    printf("\t\t*                                               *\n");
	    printf("\t\t*************************************************\n\n\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Show Records\n");
        printf("5. Update Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)//Switch Statement
        {
        case 1:
            insert_record();
            break;
        case 2:
            search_record();
            break;
        case 3:
            delete_record();
            break;
        case 4:
            show_records();
            break;
        case 5:
            update_record();
            break;
        case 6:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    while (choice != 6);

    return 0;
}


