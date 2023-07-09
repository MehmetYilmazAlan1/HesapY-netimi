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
        printf("Maksimum kullanýcý sayýsýna ulaþýldý.\n");
        return;
    }

    printf("Ad: ");
    scanf("%s", users[numUsers].name);

    printf("Hesap numarasý: ");
    scanf("%d", &users[numUsers].accountNumber);

    printf("Baþlangýç bakiye: ");
    scanf("%f", &users[numUsers].balance);

    numUsers++;

    printf("Yeni kullanýcý oluþturuldu.\n");
}

void displayBalance(int accountNumber) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber) {
            printf("Bakiye: %.2f\n", users[i].balance);
            return;
        }
    }

    printf("Hesap bulunamadý.\n");
}

void deposit(int accountNumber, float amount) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber) {
            users[i].balance += amount;
            printf("Para yatýrýldý.\n");
            return;
        }
    }

    printf("Hesap bulunamadý.\n");
}

void withdraw(int accountNumber, float amount) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber) {
            if (users[i].balance >= amount) {
                users[i].balance -= amount;
                printf("Para çekildi.\n");
            } else {
                printf("Yetersiz bakiye.\n");
            }
            return;
        }
    }

    printf("Hesap bulunamadý.\n");
}

void menu() {
    printf("\n--- Banka Hesap Yönetimi ---\n");
    printf("1. Kullanýcý oluþtur\n");
    printf("2. Bakiye görüntüle\n");
    printf("3. Para yatýr\n");
    printf("4. Para çek\n");
    printf("5. Çýkýþ\n");
}

int main() {
    int choice;
    int accountNumber;
    float amount;

    do {
        menu();
        printf("Seçiminizi yapýn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                printf("Hesap numaranýzý girin: ");
                scanf("%d", &accountNumber);
                displayBalance(accountNumber);
                break;
            case 3:
                printf("Hesap numaranýzý girin: ");
                scanf("%d", &accountNumber);
                printf("Yatýrýlacak miktar: ");
                scanf("%f", &amount);
                deposit(accountNumber, amount)
                break;
            case 4:
                printf("Hesap numaranýzý girin: ");
                scanf("%d", &accountNumber);
                printf("Çekilecek miktar: ");
                scanf("%f", &amount);
                withdraw(accountNumber, amount);
                break;
            case 5:
                printf("Program sonlandýrýlýyor...\n");
                break;
            default:
                printf("Geçersiz seçim!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
