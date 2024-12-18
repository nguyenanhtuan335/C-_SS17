#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Khai bao cac ham chuc nang
void nhapChuoi(char **str);
void inChuoi(char *str);
void demChuCai(char *str);
void demChuSo(char *str);
void demKyTuDacBiet(char *str);

int main() {
    char *str = NULL; // Con tro chuoi
    int choice;

    while (1) {
        // Hien thi menu
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();  // Loai bo ky tu '\n' con lai trong bo dem

        // Xu ly lua chon
        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                demChuCai(str);
                break;
            case 4:
                demChuSo(str);
                break;
            case 5:
                demKyTuDacBiet(str);
                break;
            case 6:
                free(str);  // Giai phong bo nho
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}

// Ham nhap chuoi
void nhapChuoi(char **str) {
    char buffer[1000];
    printf("Nhap chuoi: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Loai bo ky tu '\n' o cuoi chuoi

    *str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong du bo nho de cap phat.\n");
        exit(1);
    }
    strcpy(*str, buffer);
}

// Ham in chuoi
void inChuoi(char *str) {
    if (str == NULL) {
        printf("Chua nhap chuoi.\n");
        return;
    }
    printf("Chuoi da nhap: %s\n", str);
}

// Ham dem chu cai
void demChuCai(char *str) {
    if (str == NULL) {
        printf("Chua nhap chuoi.\n");
        return;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            count++;
        }
    }
    printf("So luong chu cai: %d\n", count);
}

// Ham dem chu so
void demChuSo(char *str) {
    if (str == NULL) {
        printf("Chua nhap chuoi.\n");
        return;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    printf("So luong chu so: %d\n", count);
}

// Ham dem ky tu dac biet
void demKyTuDacBiet(char *str) {
    if (str == NULL) {
        printf("Chua nhap chuoi.\n");
        return;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && !isspace(str[i])) {
            count++;
        }
    }
    printf("So luong ky tu dac biet: %d\n", count);
}

