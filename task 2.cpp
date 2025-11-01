#include <stdio.h>

int main() {
    int productIDs[5] = {1, 2, 3, 4, 5};
    float prices[5] = {180, 120, 250, 400, 20};
    int stock[5] = {20, 30, 15, 10, 50};
    int cartQty[5] = {0};

    int customerID;
    long long customerCNIC;

    int choice;
    float total = 0, discount = 0, finalBill = 0;
    int promo;

    printf("=== Welcome to Supermarket Inventory System ===\n");

    // Get customer info
    printf("Enter Customer ID (number): ");
    scanf("%d", &customerID);
    printf("Enter CNIC number: ");
    scanf("%lld", &customerCNIC);

    do {
        printf("\n---------- Main Menu ----------\n");
        printf("1. Display Inventory\n");
        printf("2. Add Item to Cart\n");
        printf("3. Update Inventory\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nProductID\tPrice\tStock\n");
                printf("-----------------------------\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d\t\t%.2f\t%d\n", productIDs[i], prices[i], stock[i]);
                }
                break;
            case 2: {
                int id, qty;
                printf("\nEnter Product ID to buy (1-5): ");
                scanf("%d", &id);

                if (id < 1 || id > 5) {
                    printf("Invalid Product ID!\n");
                    break;
                }

                printf("Enter quantity: ");
                scanf("%d", &qty);

                if (qty > stock[id - 1]) {
                    printf("Sorry, only %d left in stock.\n", stock[id - 1]);
                } else {
                    cartQty[id - 1] += qty;
                    printf("%d item(s) of Product %d added to cart.\n", qty, id);
                }
                break;
            }

            case 3:
                for (int i = 0; i < 5; i++) {
                    stock[i] -= cartQty[i];
                }
                printf("Inventory updated successfully.\n");
                break;

            // 4?? Display Total Bill
            case 4:
                total = 0;
                for (int i = 0; i < 5; i++) {
                    if (cartQty[i] > 0) {
                        total += prices[i] * cartQty[i];
                    }
                }
                printf("\nYour Total Bill (no discount): %.2f\n", total);

                printf("Do you have promo code Eid2025? (1 = Yes, 0 = No): ");
                scanf("%d", &promo);

                if (promo == 1) {
                    discount = total * 0.25;
                    finalBill = total - discount;
                    printf("25%% Discount Applied! Final Bill = %.2f\n", finalBill);
                } else {
                    finalBill = total;
                    printf("No promo applied. Final Bill = %.2f\n", finalBill);
                }
                break;

            case 5:
                total = 0;
                printf("\n----- INVOICE -----\n");
                printf("Customer ID: %d\n", customerID);
                printf("CNIC: %lld\n", customerCNIC);
                printf("-------------------\n");
                printf("ProdID\tQty\tPrice\tTotal\n");
                for (int i = 0; i < 5; i++) {
                    if (cartQty[i] > 0) {
                        float itemTotal = prices[i] * cartQty[i];
                        printf("%d\t%d\t%.2f\t%.2f\n", productIDs[i], cartQty[i], prices[i], itemTotal);
                        total += itemTotal;
                    }
                }
                printf("-------------------\n");
                printf("Total before discount: %.2f\n", total);

                printf("Apply promo Eid2025? (1 = Yes, 0 = No): ");
                scanf("%d", &promo);

                if (promo == 1) {
                    discount = total * 0.25;
                    finalBill = total - discount;
                } else {
                    discount = 0;
                    finalBill = total;
                }

                printf("Discount: %.2f\n", discount);
                printf("Final Bill: %.2f\n", finalBill);
                printf("-------------------\n");
                printf("Thank you for shopping!\n");
                break;

            case 6:
                printf("Exiting the system... Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

