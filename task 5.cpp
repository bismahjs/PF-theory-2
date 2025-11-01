#include <stdio.h>

void encodeMessage(char message[]) {
    int length = 0;
    while (message[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = message[i];
        message[i] = message[length - i - 1];
        message[length - i - 1] = temp;
    }

    for (int i = 0; i < length; i++) {
        message[i] = message[i] ^ (1 << 1);
        message[i] = message[i] ^ (1 << 4);
    }

    printf("Encoded Message: ");
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}

void decodeMessage(char message[]) {
    int length = 0;
    while (message[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length; i++) {
        message[i] = message[i] ^ (1 << 1);
        message[i] = message[i] ^ (1 << 4);
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = message[i];
        message[i] = message[length - i - 1];
        message[length - i - 1] = temp;
    }

    printf("Decoded Message: ");
    for (int i = 0; i < length; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}

int main() {
    char message[200];
    int choice;

    while (1) {
        printf("\n1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        getchar();

        if (choice == 1) {
            int i = 0;
            printf("Enter message to encode: ");
            while ((message[i] = getchar()) != '\n') {
                i++;
            }
            message[i] = '\0';
            encodeMessage(message);
        } 
        else if (choice == 2) {
            int i = 0;
            printf("Enter message to decode: ");
            while ((message[i] = getchar()) != '\n') {
                i++;
            }
            message[i] = '\0';
            decodeMessage(message);
        } 
        else if (choice == 3) {
            printf("Program ended.\n");
            break;
        } 
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
2
