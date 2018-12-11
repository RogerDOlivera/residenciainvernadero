//valores de memebresia para temperatura/temperatura{muy bajo, bajo, normal, alto, muy alto}
double membresiasTemperatura[5] = {0,0,0,0,0};
double membresiasHumedad[5] = {0,0,0,0,0};

// etiquetas linguisticas para variables de entrada, donde:
// B: MuyBajo, b: bajo, n:  normal, a: alto, A: muyAlto  
char etiquetasLinguisticas[5] = {'B', 'b', 'n', 'a', 'A'};

char etiquetasActivasTemperatura[2];
char etiquetasActivasHumedad[2];

double valorEtiquetasTemperatura[2];
double valorEtiquetasHumedad[2];

//variables de control activas en base a las variables de entrada
char variablesControlActivas[4];
//valores que van a tomar las variables de control del sistema
double valorVariablesControl[4] = {0,0,0,0};

double valoresPoligonoX[4];
double valoresPoligonoY[4];

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
		
		double pertenencia = funcionTriangular(temperaturaBaja, x);
		membresiasTemperatura[1] = pertenencia;
		printf("El valor %f Se encuentra en el rango: BAJA\nCon pertenencia de: %f\n",x,pertenencia);
		
	}
	if(x>=temperaturaNormal[0] & x<=temperaturaNormal[2]){
		//cuando x caiga en el rango de NORMAL
		
		double pertenencia = funcionTriangular(temperaturaNormal, x);
		membresiasTemperatura[2] = pertenencia;
		printf("El valor %f Se encuentra en el rango: NORMAL\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=temperaturaAlta[0] & x<=temperaturaAlta[2]){
		//cuando x caiga en el rango de ALTA
		
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
	
	//double mayor = obtenerMayor(membresiasTemperatura, 5);
	//int pos = obtenerPosMayor(membresiasTemperatura, 5);
	
	//printf("El valor: %f , corresponde al conjunto: %c , con una membresia de %f : \n",x, etiquetasLinguisticas[pos], mayor);
	
	//return pos;
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
		
		double pertenencia = funcionTriangular(humedadBaja, x);
		membresiasHumedad[1] = pertenencia;
		printf("El valor %f Se encuentra en el rango: BAJA\nCon pertenencia de: %f\n",x,pertenencia);
		
	}
	if(x>=humedadNormal[0] & x<=humedadNormal[2]){
		//cuando x caiga en el rango de NORMAL
		
		double pertenencia = funcionTriangular(humedadNormal, x);
		membresiasHumedad[2] = pertenencia;
		printf("El valor %f Se encuentra en el rango: NORMAL\nCon pertenencia de: %f\n",x,pertenencia);
	}
	if(x>=humedadAlta[0] & x<= humedadAlta[2]){
		//cuando x caiga en el rango de ALTA
		
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
	
	printf("El valor: %f , corresponde al conjunto: %c , con una membresia de %f : \n",x, etiquetasLinguisticas[pos], mayor);
	
	

}

void obtenerEtiquetasActivas(){
	int contT = 0;
	for(int i = 0; i<5; i++){
		if(membresiasTemperatura[i] != 0){
			etiquetasActivasTemperatura[contT] = etiquetasLinguisticas[i];
			contT++;
		}
	}
	
	int contH = 0;
	for(int i = 0; i<5; i++){
		if(membresiasHumedad[i] != 0){
			etiquetasActivasHumedad[contH] = etiquetasLinguisticas[i];
			contH++;
		}
	}
}

char obtenerVariableControl(char etiquetaTemperatura, char etiquetaHumedad){
	char valorVariable;
	
	int posicionTemperatura = buscarElemento(etiquetasLinguisticas, 5, etiquetaTemperatura);
	int posicionHumedad = buscarElemento(etiquetasLinguisticas, 5, etiquetaHumedad);
	
	valorVariable = FAM[posicionTemperatura][posicionHumedad];
	
	//printf("Valor: %c", valorVariable);
	
	return valorVariable;
	
}

void asignarValorEtiquetas(){
	int contT = 0;
	
	for(int i = 0; i<5; i++){
		if(membresiasTemperatura[i] != 0){
			valorEtiquetasTemperatura[contT] =  membresiasTemperatura[i];
			contT++;
		}
	}
	
	int contH = 0;
	for(int i = 0; i<5; i++){
		if(membresiasHumedad[i] != 0){
			valorEtiquetasHumedad[contH] =  membresiasHumedad[i];
			contH++;
		}
	}
}

void inferencia(){
	int aux = 0;
	for(int i = 0; i<2 ; i++){
		//variablesControlActivas[i] = obtenerVariableControl(etiquetasActivasTemperatura[i], etiquetasActivasHumedad[i]);
		//valorVariablesControl[i] = FuzzyAND(valorEtiquetasTemperatura[i], valorEtiquetasHumedad[i]);
		for(int j = 0; j<2; j++){
			variablesControlActivas[aux] = obtenerVariableControl(etiquetasActivasTemperatura[i], etiquetasActivasHumedad[j]);
			valorVariablesControl[aux] = FuzzyAND(valorEtiquetasTemperatura[i], valorEtiquetasHumedad[j]);
			aux++;
		}
		//aux++;
		
	}
}

bool isEqual(double d1, double d2){
	double epsilon = 0.00000000001;
    return fabs(d1 - d2) < epsilon;
}
	
	
double centroide(double valoresX[], double valoresY[], int tam){
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

double maximoCentral(double valoresX[], double valoresY[], int tam){
	double y0;
	
	return y0;
}

double bisectriz(double valoresX[], double valoresY[], int tam){
	double y0;
	
	return y0;
}




void generarPoligono(double valores[], int tam, double valorMaximo){
	//double valores [3] = {-7.5, -2.5, 0};
	int cont= 0;
	valoresPoligonoX[0] = valores[0];
	
	valoresPoligonoY[0]=0;
	valoresPoligonoY[1] =valorMaximo;
	valoresPoligonoY[2] =valorMaximo;
	valoresPoligonoY[3]=0;
	
	for(double i = valores[0]; i<valores[tam-1]; i+=.05){
		double y = funcionTriangular(valores , i);
		
		if(isEqual(y,valorMaximo)){
			//printf("<<<<<");
			cont++;
			valoresPoligonoX[cont] = i;
		}
		//printf("x: %f , y: %f\n", i, y);
	}
	valoresPoligonoX[3] = valores[tam-1]; 
}


void defuzzificacion(){
	int posMax = obtenerPosMayor(valorVariablesControl, 4);
	double valorMayor = valorVariablesControl[posMax];
	char variableControlActiva = variablesControlActivas[posMax];
	
	printf("\n<<<<<<<<VARIABLE MAYOR: %c , CON VALOR: %f >>>>>>>>>>", variableControlActiva, valorMayor);
	
	//B: BajadaGrande, b: BajadaNormal, v: BajadaPequeña, m: mantener, z: SubidaPequeña, s: SubidaNormal, S: SubidaGrande
	if(variableControlActiva == 'B'){
		generarPoligono(bajadaGrande,3, valorMayor);
	}
	if(variableControlActiva == 'b'){
		generarPoligono(bajadaNormal,3, valorMayor);
	}
	if(variableControlActiva == 'v'){
		generarPoligono(bajadaPequena,3, valorMayor);
	}
	if(variableControlActiva == 'm'){
		generarPoligono(mantener,3, valorMayor);
	}
	if(variableControlActiva == 'z'){
		generarPoligono(subidaPequena,3, valorMayor);
	}
	if(variableControlActiva == 's'){
		generarPoligono(subidaNormal,3, valorMayor);
	}
	if(variableControlActiva == 'S'){
		generarPoligono(subidaGrande,3, valorMayor);
	}
	
	
	
	double centro = centroide(valoresPoligonoX,valoresPoligonoY, 4);
	
	printf("\nCAMBIAR TEMPERATURA: \n");
	printf("centroide:%f ", centro);
}


double metodoDifuso(double temperatura, double humedad){
	obtenerValorMembresiaTemperatura(temperatura);
	obtenerValorMembresiaHumedad(humedad);
	obtenerEtiquetasActivas();
	asignarValorEtiquetas();
	inferencia();
	defuzzificacion();
}

