#include<stdio.h>

int main() {
    // Printing some information
    printf("Name       :\tAnudeepa Giri\n");
    printf("Univ.Rollno:\t2018696\n");
    printf("Sec        :\t F(14)\n");

    int n;
    printf("Enter no of data: ");
    scanf("%d", &n);

    // Arrays to store x and y values
    float x[n], y[n], xp;

    // Getting input for x and y values
    printf("Enter value of x and fx respectively \n");
    for(int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Getting the point at which interpolation is required
    printf("Enter interpolation point : ");
    scanf("%f", &xp);

    float yp = 0, p;

    // Calculating interpolated value using Lagrange's formula
    for(int i = 0; i < n; i++) {
        p = 1;
        for(int j = 0; j < n; j++) {
            if(i != j) {
                // Lagrange's formula calculation for each term
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        // Accumulating the interpolated value
        yp = yp + p * y[i];
    }

    // Printing the interpolated value at the given point
    printf("Interpolated value at %.2f is %.4f.", xp, yp);
    
    return 0;
}
