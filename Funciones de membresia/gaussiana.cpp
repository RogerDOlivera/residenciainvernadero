#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

HANDLE screen;


int main (){
	int q=0;
 while(q!=27){
 screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(screen,10);
 double x,y;
 y=0; x=0;
 printf("Introduce el valor x: \n");
 scanf("%lf", &x);
 printf("La entrada es: %lf  \n",x);

 double a,b,c,d,e,f,g,h,i;

 

 printf("La salida es : %f\n",y); 
 q = getch();
 }
 return 0;
}
