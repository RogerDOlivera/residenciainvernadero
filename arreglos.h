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

int buscarElemento(char arreglo[], int tam, char elemento){
	int pos  = -1;
	
	for(int i =0; i<tam; i++){
		if(arreglo[i] == elemento){
			pos = i;
			return pos;
		}
		
	}
	return pos;
}


void imprimirArregloDouble(double arreglo[], int tam){
	printf("\n");
	for(int i =0 ; i<tam; i++){
		printf("%f, ", arreglo[i]);
	}
	printf("\n");
}

void imprimirArregloChar(char arreglo[], int tam){
	printf("\n");
	for(int i=0; i< tam; i++){
		printf("%c, ", arreglo[i]);
	}
	printf("\n");
}
