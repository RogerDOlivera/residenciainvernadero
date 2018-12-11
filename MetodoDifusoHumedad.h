//valores de memebresia para temperatura/temperatura{muy bajo, bajo, normal, alto, muy alto}
double membresiasTemperaturaAH[5] = {0,0,0,0,0};
double membresiasHumedadAH[5] = {0,0,0,0,0};

// etiquetas linguisticas para variables de entrada, donde:
// B: MuyBajo, b: bajo, n:  normal, a: alto, A: muyAlto  
char etiquetasLinguisticasAH[5] = {'B', 'b', 'n', 'a', 'A'};

char etiquetasActivasTemperaturaAH[2];
char etiquetasActivasHumedadAH[2];

double valorEtiquetasTemperaturaAH[2];
double valorEtiquetasHumedadAH[2];

//variables de control activas en base a las variables de entrada
char variablesControlActivasAH[4];
//valores que van a tomar las variables de control del sistema
double valorVariablesControlAH[4] = {0,0,0,0};

double valoresPoligonoXAH[4];
double valoresPoligonoYAH[4];

void obtenerValorMembresiaTemperaturaAH(double x){
	printf("\n::: TEMPERATURA :::\n");
	
	if(x<=temperaturaMuyBaja[1]){
		//cuando x caiga en el rango de MUYBAJA
		double pertenencia = funcionL(temperaturaMuyBaja,x);
		membresiasTemperaturaAH[0] = pertenencia;
		printf("El valor %f Se encuentra en el rango: MUY BAJA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=temperaturaBaja[0] & x<=temperaturaBaja[2]){
		//cuando x caiga en el rango de BAJA
		
		double pertenencia = funcionTriangular(temperaturaBaja, x);
		membresiasTemperaturaAH[1] = pertenencia;
		printf("El valor %f Se encuentra en el rango: BAJA\nCon pertenencia de: %f\n",x,pertenencia);
		
	}
	if(x>=temperaturaNormal[0] & x<=temperaturaNormal[2]){
		//cuando x caiga en el rango de NORMAL
		
		double pertenencia = funcionTriangular(temperaturaNormal, x);
		membresiasTemperaturaAH[2] = pertenencia;
		printf("El valor %f Se encuentra en el rango: NORMAL\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=temperaturaAlta[0] & x<=temperaturaAlta[2]){
		//cuando x caiga en el rango de ALTA
		
		double pertenencia = funcionTriangular(temperaturaAlta, x);
		membresiasTemperaturaAH[3] = pertenencia;
		printf("El valor %f Se encuentra en el rango: ALTA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>temperaturaMuyAlta[0]){
		//cuando x caiga en el rango de MUYALTA
		double pertenencia = funcionGamma(temperaturaMuyAlta,x);
		membresiasTemperaturaAH[4] = pertenencia;
		printf("El valor %f Se encuentra en el rango: MUY ALTA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	
	//double mayor = obtenerMayor(membresiasTemperaturaAH, 5);
	//int pos = obtenerPosMayor(membresiasTemperaturaAH, 5);
	
	//printf("El valor: %f , corresponde al conjunto: %c , con una membresia de %f : \n",x, etiquetasLinguisticasAH[pos], mayor);
	
	//return pos;
}

void obtenerValorMembresiaHumedadAH(double x){
	printf("\n::: HUMEDAD :::\n");
	
	if(x<humedadMuyBaja[1]){
		//cuando x caiga en el rango de MUYBAJA
		double pertenencia = funcionL(humedadMuyBaja,x);
		membresiasHumedadAH[0] = pertenencia;
		printf("El valor %f Se encuentra en el rango: MUY BAJA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=humedadBaja[0] & x<=humedadBaja[2]){
		//cuando x caiga en el rango de BAJA
		
		double pertenencia = funcionTriangular(humedadBaja, x);
		membresiasHumedadAH[1] = pertenencia;
		printf("El valor %f Se encuentra en el rango: BAJA\nCon pertenencia de: %f\n",x,pertenencia);
		
	}
	if(x>=humedadNormal[0] & x<=humedadNormal[2]){
		//cuando x caiga en el rango de NORMAL
		
		double pertenencia = funcionTriangular(humedadNormal, x);
		membresiasHumedadAH[2] = pertenencia;
		printf("El valor %f Se encuentra en el rango: NORMAL\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=humedadAlta[0] & x<= humedadAlta[2]){
		//cuando x caiga en el rango de ALTA
		
		double pertenencia = funcionTriangular(humedadAlta, x);
		membresiasHumedadAH[3] = pertenencia;
		printf("El valor %f Se encuentra en el rango: ALTA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>humedadMuyAlta[0]){
		//cuando x caiga en el rango de MUYALTA
		double pertenencia = funcionGamma(humedadMuyAlta,x);
		membresiasHumedadAH[4] = pertenencia;
		printf("El valor %f Se encuentra en el rango: MUY ALTA\nCon pertenencia de: %f\n",x,pertenencia);
	}
	
	double mayor = obtenerMayor(membresiasHumedadAH, 5);
	int pos = obtenerPosMayor(membresiasHumedadAH, 5);
	
	printf("El valor: %f , corresponde al conjunto: %c , con una membresia de %f : \n",x, etiquetasLinguisticasAH[pos], mayor);
	
	

}

void obtenerEtiquetasActivasAH(){
	int contT = 0;
	for(int i = 0; i<5; i++){
		if(membresiasTemperaturaAH[i] != 0){
			etiquetasActivasTemperaturaAH[contT] = etiquetasLinguisticasAH[i];
			contT++;
		}
	}
	
	int contH = 0;
	for(int i = 0; i<5; i++){
		if(membresiasHumedadAH[i] != 0){
			etiquetasActivasHumedadAH[contH] = etiquetasLinguisticasAH[i];
			contH++;
		}
	}
}

char obtenerVariableControlAH(char etiquetaTemperatura, char etiquetaHumedad){
	char valorVariable;
	
	int posicionTemperatura = buscarElemento(etiquetasLinguisticasAH, 5, etiquetaTemperatura);
	int posicionHumedad = buscarElemento(etiquetasLinguisticasAH, 5, etiquetaHumedad);
	
	valorVariable = FAMH[posicionTemperatura][posicionHumedad];
	
	//printf("Valor: %c", valorVariable);
	
	return valorVariable;
	
}

void asignarValorEtiquetasAH(){
	int contT = 0;
	
	for(int i = 0; i<5; i++){
		if(membresiasTemperaturaAH[i] != 0){
			valorEtiquetasTemperaturaAH[contT] =  membresiasTemperaturaAH[i];
			contT++;
		}
	}
	
	int contH = 0;
	for(int i = 0; i<5; i++){
		if(membresiasHumedadAH[i] != 0){
			valorEtiquetasHumedadAH[contH] =  membresiasHumedadAH[i];
			contH++;
		}
	}
}

void inferenciaAH(){
	int aux = 0;
	for(int i = 0; i<2 ; i++){
		//variablesControlActivasAH[i] = obtenerVariableControl(etiquetasActivasTemperaturaAH[i], etiquetasActivasHumedadAH[i]);
		//valorVariablesControlAH[i] = FuzzyAND(valorEtiquetasTemperaturaAH[i], valorEtiquetasHumedadAH[i]);
		for(int j = 0; j<2; j++){
			variablesControlActivasAH[aux] = obtenerVariableControlAH(etiquetasActivasTemperaturaAH[i], etiquetasActivasHumedadAH[j]);
			valorVariablesControlAH[aux] = FuzzyAND(valorEtiquetasTemperaturaAH[i], valorEtiquetasHumedadAH[j]);
			aux++;
		}
		//aux++;
		
	}
}

bool isEqualAH(double d1, double d2){
	double epsilon = 0.00000000001;
    return fabs(d1 - d2) < epsilon;
}
	
	
double centroideAH(double valoresX[], double valoresY[], int tam){
	// dividendo/divisor
	double dividendo=0;
	double divisor=0;
	
	for(int i = 0; i<tam; i++){
		double aux  = valoresX[i]*valoresY[i];
		dividendo += aux;
		divisor += valoresY[i];
		
	}
	
	//printf("---------------- %f entre %f -------------------", dividendo, divisor);
	
	return dividendo/divisor;
	
}

double maximoCentralAH(double valoresX[], double valoresY[], int tam){
	double y0;
	
	return y0;
}

double bisectrizAH(double valoresX[], double valoresY[], int tam){
	double y0;
	
	return y0;
}



void generarPoligonoAH(double valores[], int tam, double valorMaximo){
	//double valores [3] = {-7.5, -2.5, 0};
	int cont= 0;
	valoresPoligonoXAH[0] = valores[0];
	
	valoresPoligonoYAH[0]=0;
	valoresPoligonoYAH[1] =valorMaximo;
	valoresPoligonoYAH[2] =valorMaximo;
	valoresPoligonoYAH[3]=0;
	
	for(double i = valores[0]; i<valores[tam-1]; i+=.05){
		double y = funcionTriangular(valores , i);
		
		if(isEqualAH(y,valorMaximo)){
			//printf("<<<<<");
			cont++;
			valoresPoligonoXAH[cont] = i;
		}
		//printf("x: %f , y: %f\n", i, y);
	}
	valoresPoligonoXAH[3] = valores[tam-1]; 
}


void defuzzificacionAH(){
	int posMax = obtenerPosMayor(valorVariablesControlAH, 4);
	double valorMayor = valorVariablesControlAH[posMax];
	char variableControlActiva = variablesControlActivasAH[posMax];
	
	printf("\n<<<<<<<<VARIABLE MAYOR: %c , CON VALOR: %f >>>>>>>>>>", variableControlActiva, valorMayor);
	
	//B: BajadaGrande, b: BajadaNormal, v: BajadaPequeña, m: mantener, z: SubidaPequeña, s: SubidaNormal, S: SubidaGrande
	if(variableControlActiva == 'B'){
		generarPoligonoAH(bajadaGrandeH,3, valorMayor);
	}
	if(variableControlActiva == 'b'){
		generarPoligonoAH(bajadaNormalH,3, valorMayor);
	}
	if(variableControlActiva == 'v'){
		generarPoligonoAH(bajadaPequenaH,3, valorMayor);
	}
	if(variableControlActiva == 'm'){
		generarPoligonoAH(mantenerH,3, valorMayor);
	}
	if(variableControlActiva == 'z'){
		generarPoligonoAH(subidaPequenaH,3, valorMayor);
	}
	if(variableControlActiva == 's'){
		generarPoligonoAH(subidaNormalH,3, valorMayor);
	}
	if(variableControlActiva == 'S'){
		generarPoligonoAH(subidaGrandeH,3, valorMayor);
	}
	
	double centro = centroideAH(valoresPoligonoXAH,valoresPoligonoYAH, 4);
	
	printf("\nCAMBIAR HUMEDAD: \n");
	printf("centroide:%f ", centro);
}


double metodoDifusoAH(double temperatura, double humedad){
	
	obtenerValorMembresiaTemperaturaAH(temperatura);
	obtenerValorMembresiaHumedadAH(humedad);
	obtenerEtiquetasActivasAH();
	asignarValorEtiquetasAH();
	inferenciaAH();
	defuzzificacionAH();
}

