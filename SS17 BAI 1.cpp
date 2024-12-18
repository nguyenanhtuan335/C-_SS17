#include <stdio.h>
#include <stdlib.h>

// Khai bao cac ham chuc nang
void nhapMang(int **arr, int *n);
void hienThiMang(int *arr, int n);
int tinhDoDaiMang(int *arr, int n);
int tinhTongPhanTu(int *arr, int n);
int timPhanTuLonNhat(int *arr, int n);

int main() {
    int *arr = NULL; 
	 // Con tro mang
    int n = 0;       
	 // So phan tu trong mang
    int choice;

    while (1) {
        // Hien thi menu
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        // Xu ly lua chon
        switch (choice) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                printf("Do dai mang: %d\n", tinhDoDaiMang(arr, n));
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", tinhTongPhanTu(arr, n));
                break;
            case 5:
                printf("Phan tu lon nhat: %d\n", timPhanTuLonNhat(arr, n));
                break;
            case 6:
                free(arr);  // Giai phong bo nho
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}

// Ham nhap mang
void nhapMang(int **arr, int *n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);

    *arr = (int *)malloc(*n * sizeof(int));
    if (*arr == NULL) {
        printf("Khong du bo nho de cap phat.\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &((*arr)[i]));
    }
}

// Ham hien thi mang
void hienThiMang(int *arr, int n) {
    if (arr == NULL) {
        printf("Mang chua duoc khoi tao.\n");
        return;
    }

    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham tinh do dai mang
int tinhDoDaiMang(int *arr, int n) {
    return n;
}

// Ham tinh tong cac phan tu trong mang
int tinhTongPhanTu(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Ham tim phan tu lon nhat
int timPhanTuLonNhat(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

