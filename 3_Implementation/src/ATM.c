#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
  node structure for implementing a queue to store transaction history
*/
typedef struct node {
    char statement[50];
    struct node* link;
} node;

/*
  ATM function prototypes
*/
void pinGeneration(void);
int checkPin(void);
void showBalance(int *);
void depositMoney(node **, int *);
void withdrawMoney(node **, int *);
void saveHistory(node **, char *);
void removeHistory(node **);
void showHistory(node **);

int main(void) {
    int choice1, choice2;
    int pinValid = 0, balance = 0;

    node *head = NULL;

    while (1) {
        printf("\n\nATM System\n======================\n");
        printf("1. Generate PIN\n2. Use ATM\n3. Exit\n");
        printf("\nYour choice: ");
        scanf("%d", &choice1);

        switch (choice1) {
            case 1: pinGeneration();
                    exit(EXIT_SUCCESS);

            case 2: pinValid = checkPin();

                    if (pinValid) {
                        printf("\nValid PIN\n");
                    } else {
                        printf("\nInvalid PIN. Please generate a PIN if you don't have one.\n");
                        exit(EXIT_FAILURE);
                    }

                    /*
					  On valid PIN entry by user, the ATM Menu is presented to the user
					*/
                    while(pinValid) {
                        printf("\nATM System Menu\n===============\n\n");
                        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n4. View transaction history\n5. Quit\n\n");

                        printf("Enter choice: ");
                        scanf("%d", &choice2);

                        switch(choice2) {
                            case 1: showBalance(&balance);
                                    break;
                            case 2: depositMoney(&head, &balance);
                                    break;
                            case 3: withdrawMoney(&head, &balance);
                                    break;
                            case 4: showHistory(&head);
                                    break;
                            case 5: printf("\nThank you for using the ATM\n");
                                    exit(EXIT_SUCCESS);
                            default: printf("\nInvalid option entered!\n");
                                     break;
                        }
                    }

            case 3: exit(EXIT_SUCCESS);

            default: printf("\nInvalid choice...Try again...\n");
                     break;
        }
    }
    return 0;
}
