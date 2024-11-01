#include<stdio.h>
#include<math.h>
int main () {
    
    float x[20], y[20][20];
    float h, u1, u, fx, fy, fact;
    int i, j, n, ch = 30;
    printf ("Enter no of terms : ");
    scanf ("%d", &n);
    printf ("Enter data:\n");
    for (i = 0; i < n; i++){
        printf ("x[%d]=", i);
        scanf ("%f", &x[i]);
        printf ("y[%d]=", i);
        scanf ("%f", &y[i][0]);
    }
    for (i = 1; i < n; i++){
        for (j = 0; j < n - i; j++){
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
    printf ("\nFORWARD DIFFERENCE TABLE\n\n");
    printf ("X         Y");
    for (i = 0; i < n - 1; i++)	
        printf ("\t%c^%dY", ch, i + 1);
    printf ("\n");
    for (i = 0; i < n; i++){
        printf ("%0.2f", x[i]);
        for (j = 0; j < n - i; j++){
        printf ("\t%0.2f", y[i][j]);
        }
    printf ("\n");
    }
    printf ("\nEnter value of x to find Y : ");
    scanf ("%f", &fx);
    h = x[1] - x[0];
    u = (fx - x[0]) / h;	
    fy = y[0][0];
    u1 = u;
    printf ("Step size is :%.2f\n", h);
    printf ("No of steps(of size 'h'):%.2f\n", u1);
    fact = 1;
    for (i = 1; i < n; i++){  
        fy = fy + (u1 * y[0][i]) / fact;
        u1 = u1 * (u1 - i);
        fact = fact * (i + 1);
    }
    printf ("\n Y(%.2f)=%.4f", fx, fy);
    return 0;
}



