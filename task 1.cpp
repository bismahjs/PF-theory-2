#include <stdio.h>

int addBook(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int isbn;
    int i, j;
    char ch;

    printf("Enter ISBN: ");
    scanf("%d", &isbn);

    for (i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            printf("Book with this ISBN already exists.\n");
            return count;
        }
    }

    isbns[count] = isbn;

    printf("Enter title: ");
    getchar();
    j = 0;
    while ((ch = getchar()) != '\n' && j < 49) {
        titles[count][j] = ch;
        j++;
    }
    titles[count][j] = '\0';

    printf("Enter price: ");
    scanf("%f", &prices[count]);

    printf("Enter quantity: ");
    scanf("%d", &quantities[count]);

    printf("Book added successfully.\n");
    return count + 1;
}

int processSale(int isbns[], int quantities[], int count) {
    int isbn, copies;
    int i, found = 0;

    printf("Enter ISBN to sell: ");
    scanf("%d", &isbn);

    for (i = 0; i < count; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &copies);
            if (copies > quantities[i]) {
                printf("Not enough stock.\n");
            } else {
                quantities[i] -= copies;
                printf("Sale processed successfully.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
    return 0;
}

int lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int i, j, any = 0;

    printf("\nLow Stock Report (Quantity < 5)\n");
    printf("--------------------------------\n");
    for (i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            any = 1;
            printf("ISBN: %d\n", isbns[i]);
            printf("Title: ");
            j = 0;
            while (titles[i][j] != '\0') {
                printf("%c", titles[i][j]);
                j++;
            }
            printf("\nPrice: %.2f\n", prices[i]);
            printf("Quantity: %d\n\n", quantities[i]);
        }
    }

    if (!any) {
        printf("No low-stock books.\n");
    }

    return 0;
}

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            count = addBook(isbns, titles, prices, quantities, count);
        } 
        else if (choice == 2) {
            processSale(isbns, quantities, count);
        } 
        else if (choice == 3) {
            lowStockReport(isbns, titles, prices, quantities, count);
        } 
        else if (choice == 4) {
            printf("Program ended.\n");
            break;
        } 
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

