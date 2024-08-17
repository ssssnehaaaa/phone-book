#include <stdio.h>
#include <stdlib.h>

struct node {
    char name[50];
    long long int number;
    struct node *next;
};

struct node *head = NULL;

void addContact();
void displayContacts();
void editContact();
void deleteContact();
void freeList();

int main() {
    int choice;

    while (1) {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                freeList();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addContact() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Unable to allocate memory\n");
        return 0;
    }
    printf("Enter name: ");
    scanf("%s", newNode->name);
    printf("Enter number: ");
    scanf("%lld", &newNode->number);
    newNode->next = head;
    head = newNode;
    printf("Contact added successfully.\n");
}

void displayContacts() {
    if (head == NULL) {
        printf("Phonebook is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("Phonebook Contacts:\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Number: %lld\n", temp->number);
        temp = temp->next;
    }
}

void editContact() {
    char searchName[50];
    printf("Enter name to edit: ");
    scanf("%s", searchName);
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, searchName) == 0) {
            printf("Enter new number for %s: ", temp->name);
            scanf("%lld", &temp->number);
            printf("Number updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char searchName[50];
    printf("Enter name to delete: ");
    scanf("%s", searchName);
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name, searchName) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Contact deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void freeList() {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Memory freed. Exiting program.\n");
}
