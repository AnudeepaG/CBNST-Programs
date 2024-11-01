#include <stdio.h>
int main() {

    int ch = 30;
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    float x[n];
    float y[n][n];

    printf("Enter data:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }

    // Calculating backward difference table
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    // Displaying backward difference table and step size
    printf("\nBACKWARD DIFFERENCE TABLE\n");
    printf("X\tY\t");
    for (int i = 1; i < n; i++) {
        printf("%c^%dY\t", ch, i);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("%.2f\t", y[i][j]);
        }
        printf("\n");
    }

    float value;   // Value to interpolate at
    printf("\nEnter value to interpolate at: ");
    scanf("%f", &value);

    // Calculating step size 'h'
    float h = x[1] - x[0];
    printf("\nStep size (h): %0.2f\n", h);

    // Calculating number of steps
    int num_steps = (x[n - 1] - x[0]) / h;
    printf("Number of steps of size h: %d\n", num_steps);

    // Initializing sum for interpolation
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / h;

    // Calculation of u mentioned in formula
    for (int i = 1; i < n; i++) {
        float temp = u;
        for (int j = 1; j < i; j++)
            temp = temp * (u + j);

        // Calculating factorial of given i
        int fact = 1;
        for (int k = 2; k <= i; k++)
            fact *= k;

        sum = sum + (temp * y[n - 1][i]) / fact;
    }
    printf("\nInterpolated value at %0.2f is %0.4f\n", value, sum);
    return 0;
}


#include <stdio.h>
int ch = 30;

// Calculation of u mentioned in formula
float u_cal(float u, int n) {
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

// Calculating factorial of given n
int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    printf ("Name       :\tAnudeepa Giri\n");
    printf ("Univ.Rollno:\t2018696\n");
    printf ("Sec        :\t F(14)\n");
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    float x[n];
    float y[n][n];

    printf("Enter data:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }

    // Calculating backward difference table
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    // Displaying backward difference table and step size
    printf("\nBACKWARD DIFFERENCE TABLE\n");
    printf("X\tY\t");
    for (int i = 1; i < n; i++) {
        printf("%c^%dY\t", ch, i);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("%.2f\t", y[i][j]);
        }
        printf("\n");
    }
    float value;   // Value to interpolate at
    printf("\nEnter value to interpolate at: ");
    scanf("%f", &value);

    // Calculating step size 'h'
    float h = x[1] - x[0];
    printf("\nStep size (h): %0.2f\n", h);

    // Calculating number of steps
    int num_steps = (x[n - 1] - x[0]) / h;
    printf("Number of steps of size h: %d\n", num_steps);

    // Initializing sum for interpolation
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / h;

    // Calculating interpolated value using step size and number of steps
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) / fact(i);
    }
    printf("\nInterpolated value at %0.2f is %0.4f\n", value, sum);
    return 0;
}
   
