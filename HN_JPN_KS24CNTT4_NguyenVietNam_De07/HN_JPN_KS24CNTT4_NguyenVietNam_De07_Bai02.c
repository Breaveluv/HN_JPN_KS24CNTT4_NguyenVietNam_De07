#include <stdio.h>
#include <stdlib.h>
int main() {
    int choice;
    do {
        printf("-----Web History------\n");
        printf("1.Visit url\n");
        printf("2.BackWard\n");
        printf("3.Forward\n");
        printf("4.Current \n");
        printf("5.Thoat\n");
        printf("Moi ban nhap lua chon \n ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Nhap lai di \n");

        }
    }while (choice != 5);
}