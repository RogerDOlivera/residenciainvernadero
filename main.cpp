#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <graphics.h> 
#include "funciones.h"
#include "variables.h"
#include "arreglos.h"
#include "MetodoDifusoTemperatura.h"
#include "MetodoDifusoHumedad.h"
#include <cstdint>



HANDLE screen;


////////////////////// HUMEDAD //////////////////////////////////////////////////////////////





int main(int argc, char** argv) {
	screen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(screen,10);
	
	/*obtenerValorMembresiaTemperatura(19.5);
	obtenerValorMembresiaHumedad(65);
	
	imprimirArregloDouble(membresiasTemperatura, 5);
	imprimirArregloDouble(membresiasHumedad, 5);
	
	obtenerEtiquetasActivas();
	
	printf("etiquetas activas de temperatura:");
	imprimirArregloChar(etiquetasActivasTemperatura, 2);
	
	printf("etiquetas activas de huemdad:");
	imprimirArregloChar(etiquetasActivasHumedad, 2);*/
	
	//obtenerVariableControl('n', 'A');
	
	/*obtenerValorMembresiaTemperatura(19.5);
	obtenerValorMembresiaHumedad(65);
	obtenerEtiquetasActivas();
	
	
	printf("MEMBRESIAS TEMP");
	
	imprimirArregloDouble(membresiasTemperatura, 5);
	printf("MEMBRESIAS HUMEDAD");
	imprimirArregloDouble(membresiasHumedad, 5);
	
	asignarValorEtiquetas();
	
	printf("MEMBRESIAS TEMP");
	imprimirArregloChar(etiquetasActivasTemperatura, 2);
	imprimirArregloDouble(valorEtiquetasTemperatura, 2);
	printf("MEMBRESIAS HUMEDAD");
	imprimirArregloChar(etiquetasActivasHumedad, 2);
	imprimirArregloDouble(valorEtiquetasHumedad, 2);
	
	inferencia();//
	
	imprimirArregloChar(variablesControlActivas, 4);
	imprimirArregloDouble(valorVariablesControl, 4);
	
	defuzzificacion();
	
	printf("\n");
	
	
	printf("\n----------------------\n");
	generarPoligono(bajadaPequena, 3, 0.5);//
	imprimirArregloDouble(valoresPoligonoX,4);
	imprimirArregloDouble(valoresPoligonoY,4);
	//genera
	
	double centro = centroide(valoresPoligonoX,valoresPoligonoY, 4);
	
	printf("\n----------------------\n");
	printf("centroide:%f ", centro);*/
	
	//19.5,  65
	metodoDifuso(11,66);
	printf("\n----------------------------------------\n");
	metodoDifusoAH(11,66);
	
	getch();
	return 0;
}
