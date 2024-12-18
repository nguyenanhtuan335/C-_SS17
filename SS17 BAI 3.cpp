#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Khai bao cac ham chuc nang
void nhapChuoi(char **str);
void inDaoNguocChuoi(char *str);
void demSoLuongTu(char *str);
void soSanhChuoi(char *str);
void inHoaChuCai(char *str);
void themChuoi(char **str);

int main() {
    char *str = NULL; // Con tro chuoi
    int choice;

    while (1) {
        // Hien thi menu
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();  // Loai bo ky tu '\n' con lai trong bo dem

        // Xu ly lua chon
        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inDaoNguocChuoi(str);
                break;
            case 3:
                demSoLuongTu(str);
                break;
            case 4:
                soSanhChuoi(str);
                break;
            case 5:
                inHoaChuCai(str);
                break;
            case 6:
                themChuoi(&str);
                break;
            case 7:
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

// Ham in dao nguoc chuoi
void inDaoNguocChuoi(char *str) {
    if (str == NULL) {
        printf("Chua nhap chuoi.\n");
        return;
    }
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Ham dem so luong tu trong chuoi
void demSoLuongTu(char *str) {
    if (str == NULL) {
        printf("Chua nhap chuoi.\n");
        return;
    }
    int count = 0;
    char *token = strtok(strdup(str), " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    printf("So luong tu trong chuoi: %d\n", count);
}

// Ham so sanh chuoi
void soSanhChuoi(char *str) {
    if (str == NULL) {
        printf("Chua nhap chuoi ban dau.\n");
        return;
    }
    char buffer[1000];
    printf("Nhap chuoi khac: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Loai bo ky tu '\n' o cuoi chuoi

    if (strlen(buffer) > strlen(str)) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else if (strlen(buffer) < strlen(str)) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else {
        printf("Chuoi moi co do dai bang chuoi ban dau.\n");
    }
}

// Ham in hoa tat ca chu cai trong chuoi
void inHoaChuCai(char *str) {
    if (str == NULL) {
        printf("Chua nhap chuoi.\n");
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Chuoi in hoa: %s\n", str);
}

// Ham them chuoi vao chuoi ban dau
void themChuoi(char **str) {
    if (*str == NULL) {
        printf("Chua nhap chuoi ban dau.\n");
        return;
    }
    char buffer[1000];
    printf("Nhap chuoi khac: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Loai bo ky tu '\n' o cuoi chuoi

    *str = (char *)realloc(*str, (strlen(*str) + strlen(buffer) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong du bo nho de cap phat.\n");
        exit(1);
    }
    strcat(*str, buffer);
    printf("Chuoi sau khi them: %s\n", *str);
}

