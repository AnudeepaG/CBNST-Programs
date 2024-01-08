#include <stdio.h>
#include <math.h>
#define f(x) exp(x)/(1+x)

int main() {
    printf("Name       :\tAnudeepa Giri\n");
    printf("Univ.Rollno:\t2018696\n");
    printf("Sec        :\t F(14)\n");
    
    float lower, upper, integration = 0.0, h, k;
    int n; 
    printf("Equation is exp(x)/(1+x) \n");
    printf("Enter lower limit : ");
    scanf("%f", &lower);
    printf("Enter upper limit : ");
    scanf("%f", &upper);
    printf("Enter step size (h): ");
    scanf("%f", &h);

    // Calculate the number of subintervals (n) based on the given h
    n = ceil((upper - lower) / h);

    printf("Number of sub intervals (n): %d\n", n);
    integration = f(lower) + f(upper);

    printf("\nStep |\tk\t|\tIntegration\n");
    printf("---------------------------------------\n");

    for (int i = 1; i <= n-1 ; i++) {
        k = lower + i * h;

        if (i % 3 == 0) {
            integration = integration + 2 * f(k);
        } else {
            integration = integration + 3 * f(k);
        }

        printf("%d    |\t%.3f\t|\t%.3f\n", i, k, integration);
    }

    integration = (integration * h * 3) / 8;
    printf("---------------------------------------\n");
    printf("\nRequired value of integration is: %.3f\n", integration);

    return 0;
}