#include <stdio.h>
#define f(x, y) (x * x + y * y)
//#define f(x, y) (3 * exp(x) + 2 * y)  //3e^x + 2y

int main() {
    float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
    int i, n;
    printf("Equation is:(x * x + y * y)\n");
    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);
    h = (xn - x0) / n;  //step size
    printf("\nStep size (h) = %0.4f\n", h);
    // Runge Kutta Method 
    printf("\nStep\tx\t\t\t y\t\t\t yn\n");
    printf("-------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        k1 = h * (f(x0, y0));
        k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
        k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
        k4 = h * (f((x0 + h), (y0 + k3)));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        printf("%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\n", i + 1, x0, y0, yn);
        x0 = x0 + h;
        y0 = yn;
    }
    printf("-------------------------------------------------\n");
    printf("\nValue of y at x = %0.2f is %0.3f\n", xn, yn);
    return 0;
}






#include<stdio.h>
#include<math.h>
#define f(x,y) x+(y*y)

int main(){
 float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
 int i, n;
 printf("Equation is:x+(y*y)\n");
 printf("Enter Initial Condition\n");
 printf("x0 = ");
 scanf("%f", &x0);
 printf("y0 = ");
 scanf("%f", &y0);
 printf("Enter calculation point xn = ");
 scanf("%f", &xn);
 printf("Enter h = ");
 scanf("%f", &h);
 h = (xn-x0)/n;
 printf("h=%0.2f",h);
 //n=(xn-x0)/h;
 printf("\nx0\ty0\tyn\n");
 for(i=0; i < n; i++)
 {
  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;
  //printf("%0.4f\t%0.4f\t%0.4f\t%0.4f\n",k1,k2,k3,k4);
  //printf("Final Value of k is :%0.4f\n",k);
  
  printf("%0.4f\t%0.4f\t%0.4f\n",x0,y0,yn);
  x0 = x0+h;
  y0 = yn;
 }
 printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
 return 0;
}

