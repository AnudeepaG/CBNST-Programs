#include<stdio.h>
#include<math.h>
#define f(x) 1/(1+x*x)
int main(){
    float a, b, h,n,x, sum=0,integral;
    printf("Equation is:1/(1+x*x)\n");
    printf("Enter Lower Limit : ");
    scanf("%f", &a);
    printf("Enter Upper Limit : ");
    scanf("%f", &b);
    printf("Enter no of steps : ");              //no of sub intervals
    scanf("%f", &n);
    // calculating step size
    h = fabs(b-a)/ n;
    for(int i=1;i<n;i++){
        x=a+i*h;                                  //x=0,0.1,0.2
        sum += f(x);
    }
    integral=(h/2)*(f(a)+f(b)+2*sum);
    printf("Integral value of given function is  %.3f", integral);
}

#include <stdio.h>
#include <math.h>
#define f(x) x * exp(x)
//f(x) sqrt(x)  LL:4,UL:9  Ans=38/3,12.664
//f(x) (x*x*x-5*x*x)/x LL:2,UL:3  Ans=-37/6,-6.160
//f(x) (x*x)*((x*x*x+5)*(x*x*x+5)) LL:0,UL:1  Ans=91/9,10.294
//f(x) (4 * x * exp(pow(x, 2)))  LL:1,UL:2  Ans=2e^4 - 2e,105.364

int main(){
    float a, b, h, n, x, sum = 0, integral;
    printf("Equation is: x * exp(x);\n");
    printf("Enter Lower Limit : ");
    scanf("%f", &a);
    printf("Enter Upper Limit : ");
    scanf("%f", &b);
    printf("Enter no of steps : "); // no of sub intervals
    scanf("%f", &n);
    // calculating step size
    h = fabs(b - a) / n;

    printf("\nStep\t|\t x \t|\t Sum \t|\t Integral\n");
    printf("------------------------------------------------------\n");
    for (int i = 1; i < n; i++) {
        x = a + i * h; // x = 0, 0.1, 0.2
        sum += f(x);
        integral = (h / 2) * (f(a) + f(b) + 2 * sum);
        printf("%d\t|\t%.3f\t|\t%.3f\t|\t%.3f\n", i, x, sum, integral);
    }
    printf("----------------------------------------------------------\n");
    printf("Integral value of given function is %.3f\n", integral);
    return 0;
}
