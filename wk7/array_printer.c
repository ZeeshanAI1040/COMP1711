#include <stdio.h>

void printArray(int a[][3]) {
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void populateArray(int rows, int cols) {
    int a[rows][cols];
    int count = 1;

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            a[i][j] = count++;
        }
    }

    printArray(a);
}

int main() {
    int rows, cols;

    printf("Number of Rows: ");
    scanf("%d", &rows);
    printf("Number of Columns: ");
    scanf("%d", &cols);

    populateArray(rows, cols);

    return 0;
}
