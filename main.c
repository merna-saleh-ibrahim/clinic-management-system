
#include <stdio.h>
#include <stdlib.h>
#define PASSWORD 1234

int slots[5] = {0};

struct patient{
    char name[50];
    char gender[10];
    int id;
    int age;
   struct patient* next;
};
struct patient* head = NULL;

int isIDexsist(int id){
    struct patient*current=head;
    while(current!=NULL){
        if(current->id==id)
        return 1;
       current=current->next;
    }
    return 0;
}

void addpatient(){
    struct patient* newpatient = (struct patient*)malloc(sizeof(struct patient));
  printf("Enter patient ID\n");
  scanf("%d",&newpatient->id);
  if(isIDexsist(newpatient->id)){
    printf("ID is alreaady exists. ENTRY IS REJECTED!");
    free(newpatient);
    return;
    }
printf("Enter patient name:\n");
    scanf(" %[^\n]", newpatient->name);

    printf("Enter patient age:\n");
    scanf("%d", &newpatient->age);

    printf("Enter patient gender (male/female):\n");
    scanf("%s", newpatient->gender);
newpatient->next=head;
head=newpatient;
printf("Patient Added Successfully\n");
}

void editpatient(){
    int id;
    printf("Please enter ID to edit patient\n");
    scanf("%d",&id);
        struct patient*current=head;
 while(current!=NULL){
        if(current->id==id){
            printf("Patient found. Enter new data:\n");

            printf("Enter new name:\n");
            scanf(" %[^\n]", current->name);

            printf("Enter new age:\n");
            scanf("%d", &current->age);

            printf("Enter new gender:\n");
            scanf("%s", current->gender);

            printf("Patient record updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Incorrect ID. Patient not found.\n");
        }

char* slottimes[5] = {
    "2:00pm to 2:30pm",
    "2:30pm to 3:00pm",
    "3:00pm to 3:30pm",
    "4:00pm to 4:30pm",
    "4:30pm to 5:00pm"
};

void reserveslot() {
    printf("Available slots:\n");
    for(int i=0;i<5;i++){
        if(slots[i]==0)
            printf("slot %d: %s are avalible\n",i+1,slottimes[i]);
        else
            printf("slot %d: %s is reserved\n",i+1,slottimes[i]);
                  
    }
    int patientID;
        printf("Enter patient ID: ");
        scanf("%d", &patientID);
        
        if (!isIDexsist(patientID)) {
        printf("Patient ID not found!\n");
        return;
    }
   int chosenslot;
   printf("please choose a slot number(1-5)");
   scanf("%d",&chosenslot);
   chosenslot--;
   
  if (chosenslot < 0 || chosenslot >= 5) {
    printf("Invalid slot number.\n");
    return;
}
if (slots[chosenslot] == 0) {
        slots[chosenslot] = patientID;
        printf("Slot %d booked successfully.\n", chosenslot + 1);
    } else {
        printf("Slot %d is already booked you cannot reserve it .\n", chosenslot + 1);
    }
    
            }
    
    
    void  cancelreservation(){
        int id;
        printf("Please enter patient id to cancel reservation:\n");
        scanf("%d",&id);
        int found = 0;
    for (int i = 0; i < 5; i++) {
        if (slots[i] == id) {
            slots[i] = 0;
            printf("Reservation for patient ID %d at slot %d has been cancelled.\n", id, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No reservation found for patient ID %d.\n", id);
    }
}



void viewpatientrecord(){
    int id;
     printf("Please enter patient id to view patient record:\n");
        scanf("%d",&id);
        struct patient* current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("Patient Record:\n");
            printf("Name: %s\n", current->name);
            printf("Age: %d\n", current->age);
            printf("Gender: %s\n", current->gender);
            return;
        }
        current = current->next;
    }
        
        printf("Patient ID %d not found.\n", id);
    }
    
    
    
    
    void viewtodayreservations(){
    int id;
     printf("\nToday's Reservations:\n");
        for (int i = 0; i < 5; i++) {
        if (slots[i] == 0) {
            printf("Slot %d (%s): Available\n", i + 1, slottimes[i]);
        } else {
            printf("Slot %d (%s): Reserved - Patient ID: %d\n", i + 1, slottimes[i], slots[i]);
        }
    }
}
    
    
    
int main()
{
    int mode;
    while (1) {
        printf("please enter mode:\n1. Admin Mode\n2. User Mode\n3. Exit Program\n");
        scanf("%d", &mode);

       switch(mode){
        case 1:{
        printf("admin mode \n");
    int pass , trials=0;
    while(trials<3){
    printf("please enter the admin password\n");
    scanf("%d",&pass);
    if(pass==PASSWORD){
    printf("Welcome to the admin mode\n");
    
    int adminChoice;
do {
    printf("\nAdmin Menu:\n");
    printf("1. Add Patient\n");
    printf("2. Edit Patient\n");
    printf("3. Reserve a slot\n");
    printf("4. Cancel Resrevation \n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &adminChoice);

    switch(adminChoice) {
        case 1:addpatient();break;
        case 2:editpatient();break;
        case 3:reserveslot();break;
        case 4:cancelreservation();break;
        case 5:printf("Exiting admin mode.\n");break;
        default:printf("Invalid choice, try again.\n");
    }
} while(adminChoice != 5);

         break;
    }
        else{
        printf("Incorrect Password, PLEASE TRY AGAIN\n");
        trials++;
        }
        }
        if(trials==3){
            printf("Too many trials.System closed.\n");
            return 0;
        }
        break;
    }
        case 2:{
                printf("Welcome to the user mode\n");
        
        
         int userChoice;
         do {
    printf("\nuser Menu:\n");
    printf("1. View Patient Record\n");
    printf("2. view today’s reservations\n");
    printf("3. Exit to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &userChoice);
        
    switch(userChoice) {
        case 1:viewpatientrecord();break;
        case 2:viewtodayreservations();break;
        case 3:printf("Exiting user mode.\n");break;
        default:printf("Invalid choice, try again.\n");
    }
} while(userChoice != 3);

         break;
    }
        case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid mode, please try again.\n");
        }
    }

    return 0;
}


