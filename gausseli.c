#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int i, j, k, n;
    float a[20][20], ratio, x[10], sum = 0.0;
    printf("\nEnter no. of unknowns: ");
    scanf("%d", &n);
    printf("\nEnter elements of augmented matrix row-wise:\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("A[%d][%d] : ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    printf("\nAugmented matrix:\n");     // Print augmented matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < n; j++) {          // Gaussian Elimination
		if (a[j][j] == 0.0) {
            printf("Mathematical Error! Division by zero.\n");
        }
        for (i = 0; i < n; i++) {
            if (i > j) {
                ratio = a[i][j] / a[j][j];
                for (k = 0; k <= n; k++) {
                    a[i][k] = a[i][k] - ratio * a[j][k];
                }
            }
        }
    }
    // Backward Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }  
    printf("\nIn upper triangular matrix form:\n");       // after Gaussian elimination
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.3f\n", i + 1, x[i]);
    }
    return (0);
}






