#include <stdio.h>

int main() {
    int rows, cols;
    int r, c;               
    int bit, action;  
    int choice;             
    printf("Enter number of rows in grid: ");
    scanf("%d", &rows);
    printf("Enter number of columns in grid: ");
    scanf("%d", &cols);

    int grid[10][10] = {0}; 

    do {
        printf("\n===== IESCO Power Grid Monitoring System =====\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

      
            case 1: {
                printf("Enter row (0 to %d): ", rows - 1);
                scanf("%d", &r);
                printf("Enter column (0 to %d): ", cols - 1);
                scanf("%d", &c);

                if (r < 0 || r >= rows || c < 0 || c >= cols) {
                    printf("Invalid sector location!\n");
                    break;
                }

                printf("\nChoose which status to change:\n");
                printf("0 = Power, 1 = Overload, 2 = Maintenance\n");
                scanf("%d", &bit);

                printf("Enter 1 to turn ON / 0 to turn OFF: ");
                scanf("%d", &action);

                switch (action) {
                    case 1:
                        grid[r][c] = grid[r][c] | (1 << bit);
                        printf("Status bit %d turned ON at (%d,%d)\n", bit, r, c);
                        break;
                    case 0:
                        grid[r][c] = grid[r][c] & ~(1 << bit);
                        printf("Status bit %d turned OFF at (%d,%d)\n", bit, r, c);
                        break;
                    default:
                        printf("Invalid input! Must be 1 or 0.\n");
                        break;
                }
                break;
            }

            case 2: {
                printf("Enter row to query: ");
                scanf("%d", &r);
                printf("Enter column to query: ");
                scanf("%d", &c);

                if (r < 0 || r >= rows || c < 0 || c >= cols) {
                    printf("Invalid coordinates!\n");
                    break;
                }

                int status = grid[r][c];
                printf("\n--- Sector (%d, %d) Status ---\n", r, c);

                switch ((status & 1)) {     
                    case 1:
                        printf("Power: ON\n");
                        break;
                    default:
                        printf("Power: OFF\n");
                        break;
                }

                switch ((status >> 1) & 1) { 
                    case 1:
                        printf("Overload: YES\n");
                        break;
                    default:
                        printf("Overload: NO\n");
                        break;
                }

                switch ((status >> 2) & 1) { 
                    case 1:
                        printf("Maintenance Required: YES\n");
                        break;
                    default:
                        printf("Maintenance Required: NO\n");
                        break;
                }

                break;
            }

            case 3: {
                int overloaded = 0;
                int maintenance = 0;

                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        switch ((grid[i][j] >> 1) & 1) {
                            case 1:
                                overloaded++;
                                break;
                        }

                        switch ((grid[i][j] >> 2) & 1) {
                            case 1:
                                maintenance++;
                                break;
                        }
                    }
                }

                printf("\n--- System Diagnostic Report ---\n");
                printf("Overloaded sectors: %d\n", overloaded);
                printf("Maintenance required in: %d sectors\n", maintenance);
                break;
            }

            case 4:
                printf("Exiting system... Thank you!\n");
                break;

            default:
                printf("Invalid menu choice!\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

