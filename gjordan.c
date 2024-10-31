#include <stdio.h>
#include <math.h>
int main() {
    float a[20][21], x[20], ratio;
    int i, j, k, n;
    printf("Enter number of unknowns: ");
    scanf("%d", &n);
    printf("\nEnter elements of augmented matrix row-wise:\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("A[%d][%d] : ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    printf("\nAugmented matrix:\n"); // Print augmented matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!\n");
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k <= n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
    printf("\nIn diagonal form:\n"); // after Gaussian jordan
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        x[i] = a[i][n] / a[i][i];
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    return 0;
}
