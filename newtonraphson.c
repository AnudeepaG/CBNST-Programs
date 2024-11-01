#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) x*x*x-48
#define g(x) 3*x*x
int main(){
    
    float x0, x1, f0, f1, g0, e;
    int step = 1;
    printf("\nEnter initial guesses:\n");
    scanf("%f%f", &x0,&x1);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);
    // Determine which initial guess is closer to root 
    if (fabs(f(x0)) < fabs(f(x1))) {
        printf("\nChoosing initial guess %f as it is closer to root.\n", x0);
    } else {
        printf("\nChoosing initial guess %f as it is closer to root.\n", x1);
        // Swap x0 and x1
        float temp = x0;
        x0 = x1;
        x1 = temp;
    }
    // Implementing Newton Raphson Method
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do{
        g0 = g(x0);
        f0 = f(x0);
        if (g0 == 0.0){
            printf("Mathematical Error.");
        }
        x1 = x0 - f0 / g0;
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, f0, x1, f1);
        x0 = x1;
        step = step + 1;
        f1 = f(x1);
    } while (fabs(f1) > e);
    printf("\nRoot is: %f", x1);
    return 0;
}

