#include <math.h>
#include <stdio.h>
int main() {
    
    double a, b, c, d, root1, root2, rp, ip;
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Equation is: %.2lfx^2 + %.2lfx + %.2lf\n", a, b, c);
    // Calculate discriminant
    d = b * b - 4 * a * c;
    printf("Discriminant is %.2lf\n", d);
    // Check nature of roots
    if (d > 0) {       // Real and different roots
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("Real and different roots\n");
        printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
    }
    else if (d == 0) {   // Real and equal roots
        root1 = root2 = -b / (2 * a);
        printf("Real and equal roots\n");
        printf("root1 = root2 = %.2lf\n", root1);
    }
    else {    // Complex roots
        rp = -b / (2 * a);
        ip = sqrt(-d) / (2 * a);
        printf("Complex roots\n");
        printf("root1 = %.2lf + %.2lfi and root2 = %.2lf - %.2lfi\n", rp, ip, rp, ip);
    }
    return 0;
}
