#include <stdio.h>
#include <math.h>
#define f(x) 1/(1+x*x)
int main() {
   
    float lower, upper, integration = 0.0, h, k;
    int i, n;
    printf("Enter lower limit : ");
    scanf("%f", &lower);
    printf("Enter upper limit : ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals: ");
    scanf("%d", &n);
    h = (upper - lower) / n;
    printf("Step size (h): %.3f\n", h);
    integration = f(lower) + f(upper);
    printf("\nStep |\tk\t|\tIntegration\n");
    printf("---------------------------------------\n");
    for (i = 1; i <= n - 1; i++) {
        k = lower + i * h;
        if (i % 2 == 0) {
            integration = integration + 2 * f(k);
        } 
        else {
            integration = integration + 4 * f(k);
        }
        printf("%d    |\t%.3f\t|\t%.3f\n", i, k, integration);
    }
    integration = integration * h / 3;
    printf("---------------------------------------\n");
    printf("\nRequired value of integration is: %.3f\n", integration);
return 0;
}
