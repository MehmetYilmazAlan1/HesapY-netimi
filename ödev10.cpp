#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

struct User {
    char name[50];
    int accountNumber;
    float balance;
};

struct User users[MAX_USERS];
int numUsers = 0;

void createUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maksimum kullan�c� say�s�na ula��ld�.\n");
        return;
    }

    printf("Ad: ");
    scanf("%s", users[numUsers].name);

    printf("Hesap numaras�: ");
    scanf("%d", &users[numUsers].accountNumber);

    printf("Ba�lang�� bakiye: ");
    scanf("%f", &users[numUsers].balance);

    numUsers++;

    printf("Yeni kullan�c� olu�turuldu.\n");
}

void displayBalance(int accountNumber) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber) {
            printf("Bakiye: %.2f\n", users[i].balance);
            return;
        }
    }

    printf("Hesap bulunamad�.\n");
}

void deposit(int accountNumber, float amount) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber) {
            users[i].balance += amount;
            printf("Para yat�r�ld�.\n");
            return;
        }
    }

    printf("Hesap bulunamad�.\n");
}

void withdraw(int accountNumber, float amount) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber) {
            if (users[i].balance >= amount) {
                users[i].balance -= amount;
                printf("Para �ekildi.\n");
            } else {
                printf("Yetersiz bakiye.\n");
            }
            return;
        }
    }

    printf("Hesap bulunamad�.\n");
}

void menu() {
    printf("\n--- Banka Hesap Y�netimi ---\n");
    printf("1. Kullan�c� olu�tur\n");
    printf("2. Bakiye g�r�nt�le\n");
    printf("3. Para yat�r\n");
    printf("4. Para �ek\n");
    printf("5. ��k��\n");
}

int main() {
    int choice;
    int accountNumber;
    float amount;

    do {
        menu();
        printf("Se�iminizi yap�n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                printf("Hesap numaran�z� girin: ");
                scanf("%d", &accountNumber);
                displayBalance(accountNumber);
                break;
            case 3:
                printf("Hesap numaran�z� girin: ");
                scanf("%d", &accountNumber);
                printf("Yat�r�lacak miktar: ");
                scanf("%f", &amount);
                deposit(accountNumber, amount)
                break;
            case 4:
                printf("Hesap numaran�z� girin: ");
                scanf("%d", &accountNumber);
                printf("�ekilecek miktar: ");
                scanf("%f", &amount);
                withdraw(accountNumber, amount);
                break;
            case 5:
                printf("Program sonland�r�l�yor...\n");
                break;
            default:
                printf("Ge�ersiz se�im!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
