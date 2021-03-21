// Compile > gcc -W pixelToCoordinates.c -o pixelToCoordinates
// Run > ./pixelToCoordinates <pixel.txt >coord.txt
// Ana Rocha 
#include <stdio.h>


int doubles_get(double *a){
    int result = 0;
    double x;
    while(scanf("%lf", &x)!=EOF)
    {
        a[result++]=x;
    }
    return result;
}

double pixelToCoordinateX(double x, int witdh)
{
    return (x/(witdh/2)) -1;
}

double pixelToCoordinateY(double y, int height)
{
    return -((y/(height/2)) -1);

}

int pixelToCoordinates(double *a, int n, double *b)
{
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        if(i%2 == 0)
            b[result++] = pixelToCoordinateX(a[i],600);
        else if(i%2 ==1){
            b[result++] = pixelToCoordinateY(a[i],800);
            b[result++] = 0.0;            
    }
    }
    return result;
}


void doubles_println(double *a, int n)
{
    if(n>0){
        for(int i = 0; i < n; i++)
        {  
            printf("%g\n", a[i]);
        }
        printf("\n");
    }
}



void printCoordinates(double *a, int n)
{
    if(n>0){
        printf("%g,", a[0]);
        for(int i = 1; i < n; i++)
        {
            if(i%3 == 0)
            printf(" %g,", a[i]);
            else if(i%3 ==1){
            printf(" %g,", a[i]);
        }
            else{
            printf(" %g,\n", a[i]);

            }
        }
        printf("\n");
    }
}


void test_reading()
{
    double a[10000];
    int a_size=doubles_get(a);
    
    double b[10000];
    int b_size= pixelToCoordinates(a, a_size,b);
    doubles_println(b,b_size);

}

int main(int argc, char **argv) {
   
    test_reading();
   return 0;
}