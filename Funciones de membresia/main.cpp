//funcion de membrecia tipo trapecio///

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <graphics.h> 
#include "funciones.h"

HANDLE screen;

char etiquetasLinguisticasTemperatura[5] = {'B', 'b', 'n', 'a', 'A'};

char etiquetasLinguisticasHumedad[5]     = {'B', 'b', 'n', 'a', 'A'};


//valores para las etiquetas linguisticas de temperatura    

double temperaturaMuyBaja[2] = {5,15};//funcion L   {maximo, minimo}
                                    
double temperaturaBaja [3]  =  {10, 15, 20};//funcion triangular  {inicio, media, fin}
double temperaturaNormal[3] =  {18, 20, 22};
double temperaturaAlta[3]   =  {20, 25, 30};

double temperaturaMuyAlta[2] = {25, 30};//funcion gamma {minimo, maximo}

//valores para las etiquetas linguisticas de humedad

double humedadMuyBaja[2] = {10, 20};

double humedadBaja[3] = {10,25,40};
double humedadNormal[3] = {30, 40, 50};
double humedadAlta[3] = {40, 55, 70};

double humedadMuyAlta[2] = {60, 70};

//valores de memebresia para temperatura{muy bajo, bajo, normal, alto, muy alto}
double membresiasTemperatura[5] = {0,0,0,0,0};

//valores de membresia para humedad{muy bajo, bajo, normal, alto, muy alto}
	
double membresiasHumedad[5] = {0,0,0,0,0};

//etiquetas 
char etiquetasLinguisticasVariacion[7] = {'B', 'b', 'v', 'm', 'z', 's', 'S'};


/*double funcionTriangular(double a, double m, double b, double x){
	double y = 0;
	
	if(x < a){
		y = 0;
	}
	if(a<x & x<= m){
		y = (x-a)/(m-a);
	}
	if(m<x & x<=b){
		y = (b-x)/(b-m);
	}
	if(x>b){
		y = 0;
	}
	return y;
}

double funcionTrapecio(double a, double b, double c, double d, double x){
	double y = 0;
	
	if(x<=a){
		y = 0;
	}
	if(a<=x & x<=b){
		y = (x-a)/(b-a);
	}
	if(b<x & x<=c){
		y = 1;
	}
	if(c<=x & x<=d){
		y = (d-x)/(d-c);
	}
	if(x>d){
		y = 0;
	}
	
	return y;
}

double funcionGauss(double m, double x){
	double k = 2;
	
	double var1 = pow( (x-m), 2 );
	double var2 = 2 * ( pow (k,2) );
	
	return exp(-1*(var1/var2));
	
	
	
}

double funcionGamma(double a, double m, double x){
	double y = 0;
	
	if(x <= a){
		y = 0;
	}
	if(x>a & x<m){
		y = (x-a)/(m-a);
	}
	if(x>= m){
		y = 1;
	}
	return y;
}

double funcionL(double a, double m, double x){
	return 1 - funcionGamma(a, m, x);
}
*/


double obtenerMayor(double arreglo[], int tam){
	double mayor = 0;
	for (int i = 0; i < 5; i++){
		if (mayor < arreglo[i]){
	 		mayor = arreglo[i];
	 		//pos = i;
		}
	}
	
	return mayor;
}

int obtenerPosMayor(double arreglo[], int tam){
	int pos = 0;
	
	double mayor = obtenerMayor(arreglo, tam);
	
	int cont = 0;
	while(mayor != arreglo[cont]){
		cont ++;
	}
	return cont;
}

void obtenerValorMembresiaTemperatura(double x){
	printf("\n::: TEMPERATURA :::\n");
	
	if(x<=temperaturaMuyBaja[1]){
		//cuando x caiga en el rango de MUYBAJA
		double pertenencia = funcionL(temperaturaMuyBaja,x);
		membresiasTemperatura[0] = pertenencia;
		printf("El valor %f Se encuentra en el rango: MUY BAJA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=temperaturaBaja[0] & x<=temperaturaBaja[2]){
		//cuando x caiga en el rango de BAJA
		//double pertenencia = funcionTriangular(temperaturaBaja[0], temperaturaBaja[1], temperaturaBaja[2], x);
		double pertenencia = funcionTriangular(temperaturaBaja, x);
		membresiasTemperatura[1] = pertenencia;
		printf("El valor %f Se encuentra en el rango: BAJA\nCon pertenencia de: %f\n",x,pertenencia);
		
	}
	if(x>=temperaturaNormal[0] & x<=temperaturaNormal[2]){
		//cuando x caiga en el rango de NORMAL
		//double pertenencia = funcionTriangular(temperaturaNormal[0], temperaturaNormal[1], temperaturaNormal[2], x);
		double pertenencia = funcionTriangular(temperaturaNormal, x);
		membresiasTemperatura[2] = pertenencia;
		printf("El valor %f Se encuentra en el rango: NORMAL\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=temperaturaAlta[0] & x<=temperaturaAlta[2]){
		//cuando x caiga en el rango de ALTA
		//double pertenencia = funcionTriangular(temperaturaAlta[0], temperaturaAlta[1], temperaturaAlta[2], x);
		double pertenencia = funcionTriangular(temperaturaAlta, x);
		membresiasTemperatura[3] = pertenencia;
		printf("El valor %f Se encuentra en el rango: ALTA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>temperaturaMuyAlta[0]){
		//cuando x caiga en el rango de MUYALTA
		double pertenencia = funcionGamma(temperaturaMuyAlta,x);
		membresiasTemperatura[4] = pertenencia;
		printf("El valor %f Se encuentra en el rango: MUY ALTA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	
	double mayor = obtenerMayor(membresiasTemperatura, 5);
	int pos = obtenerPosMayor(membresiasTemperatura, 5);
	
	printf("El valor: %f , corresponde al conjunto: %c , con una membresia de %f : \n",x, etiquetasLinguisticasTemperatura[pos], mayor);
	
}

void obtenerValorMembresiaHumedad(double x){
	printf("\n::: HUMEDAD :::\n");
	
	if(x<humedadMuyBaja[1]){
		//cuando x caiga en el rango de MUYBAJA
		double pertenencia = funcionL(humedadMuyBaja,x);
		membresiasHumedad[0] = pertenencia;
		printf("El valor %f Se encuentra en el rango: MUY BAJA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=humedadBaja[0] & x<=humedadBaja[2]){
		//cuando x caiga en el rango de BAJA
		//double pertenencia = funcionTriangular(humedadBaja[0], humedadBaja[1], humedadBaja[2], x);
		double pertenencia = funcionTriangular(humedadBaja, x);
		membresiasHumedad[1] = pertenencia;
		printf("El valor %f Se encuentra en el rango: BAJA\nCon pertenencia de: %f\n",x,pertenencia);
		
	}
	if(x>=humedadNormal[0] & x<=humedadNormal[2]){
		//cuando x caiga en el rango de NORMAL
		//double pertenencia = funcionTriangular(humedadNormal[0], humedadNormal[1], humedadNormal[2], x);
		double pertenencia = funcionTriangular(humedadNormal, x);
		membresiasHumedad[2] = pertenencia;
		printf("El valor %f Se encuentra en el rango: NORMAL\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=humedadAlta[0] & x<= humedadAlta[2]){
		//cuando x caiga en el rango de ALTA
		//double pertenencia = funcionTriangular(humedadAlta[0], humedadAlta[1], humedadAlta[2], x);
		double pertenencia = funcionTriangular(humedadAlta, x);
		membresiasHumedad[3] = pertenencia;
		printf("El valor %f Se encuentra en el rango: ALTA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>humedadMuyAlta[0]){
		//cuando x caiga en el rango de MUYALTA
		double pertenencia = funcionGamma(humedadMuyAlta,x);
		membresiasHumedad[4] = pertenencia;
		printf("El valor %f Se encuentra en el rango: MUY ALTA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	
	double mayor = obtenerMayor(membresiasHumedad, 5);
	int pos = obtenerPosMayor(membresiasHumedad, 5);
	
	printf("El valor: %f , corresponde al conjunto: %c , con una membresia de %f : \n",x, etiquetasLinguisticasHumedad[pos], mayor);
}

main(){
	screen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(screen,10);
	
	double x = 5;
	double x1 = 3;
	double x11 = 2;
	
	
	obtenerValorMembresiaTemperatura(14);
	printf("\n");
	obtenerValorMembresiaHumedad(32);
	
	
	getch();
	return 0;
}
