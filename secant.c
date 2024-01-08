#include <stdio.h>
#include <math.h>
#define f(x) ((x*x)*exp(-x/2))-1
//#define f(x) x*x*x - 2*x - 5
int main() {
    printf("Name       :\tAnudeepa Giri\n");
    printf("Univ.Rollno:\t2018696\n");
    printf("Sec        :\t F(14)\n");
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1,N;
    printf("\nEquation is: ((x*x)*exp(-x/2))-1\n");
    printf("Enter initial guesses: ");
    scanf("%f %f", &x0, &x1);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
    printf("\nStep\t\t x0\t\t x1\t\t x2\t\t f(x2)\n");
    do {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1) {
            printf("Mathematical error\n");       
        }
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);
        printf("%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\n", step, x0, x1, x2, f2);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        step = step + 1;
        if(step > N){
			   printf("Not Convergent.");
		}
    } while (fabs(f2) > e);
    printf("\nRoot is: %.4f\n", x2);
    return 0; // Return 0 to indicate successful execution
}
