/*************************************************************/ 
/*************************************************************/ 
/******RANGOS DE VALORES PARA LAS ETIQUETAS LINGUISTICAS******/ 
/*************************************************************/ 
/*************************************************************/ 

/********************* TEMPERATURA ***************************/
/*double temperaturaMuyBaja[2] = {5,15};      //aplica funcion L   {maximo, minimo}                               
double temperaturaBaja [3]  =  {10, 15, 20};//aplica funcion triangular  {inicio, media, fin}
double temperaturaNormal[3] =  {18, 20, 22};
double temperaturaAlta[3]   =  {20, 25, 30};
double temperaturaMuyAlta[2] = {25, 30};     //aplica funcion gamma {minimo, maximo}*/

double temperaturaMuyBaja[2] = {10,12};      //aplica funcion L   {maximo, minimo}                               
double temperaturaBaja [3]  =  {10, 14, 17};//aplica funcion triangular  {inicio, media, fin}
double temperaturaNormal[3] =  {16, 19, 22};
double temperaturaAlta[3]   =  {21, 25, 30};
double temperaturaMuyAlta[2] = {28, 30};     //aplica funcion gamma {minimo, maximo}

/********************* HUMEDAD ***************************/

/*double humedadMuyBaja[2] = {10, 20};
double humedadBaja[3] = {10,25,40};
double humedadNormal[3] = {30, 40, 50};
double humedadAlta[3] = {40, 55, 70};
double humedadMuyAlta[2] = {60, 70};*/

double humedadMuyBaja[2] = {65, 68};
double humedadBaja[3] = {67,69,70};
double humedadNormal[3] = {69, 70, 71};
double humedadAlta[3] = {70, 71, 73};
double humedadMuyAlta[2] = {72, 74};


//***************** VARIABLES DE CONTROL  PARA TEMPERATURA///////////////////////////

/*double bajadaGrande[3] = {-15, -10, -7.5};
double bajadaNormal[3] = {-10, -5, -2.5};
double bajadaPequena[3]= {-7.5, -2.5, 0};
double mantener [3] = {-1, 0 ,1};
double subidaPequena[3] = {0, 2.5, 7.5};
double subidaNormal[3] = {2.5, 5, 10};
double subidaGrande[3] = {7.5, 10, 15};*/

double bajadaGrande[3] = {-12, -10, -5};
double bajadaNormal[3] = {-7, -4, -3};
double bajadaPequena[3]= {-3, -2, 0};
double mantener [3] = {-1, 0 ,1};
double subidaPequena[3] = {0, 2, 5};
double subidaNormal[3] = {3, 6, 8};
double subidaGrande[3] = {7, 10, 12};

//***************** VARIABLES DE CONTROL  PARA HUMEDAD///////////////////////////



double bajadaGrandeH[3] = {-8,-6,-4};
double bajadaNormalH[3] = {-5.5,-3.5,-2.5};
double bajadaPequenaH[3]= {-3,-1.5,0};
double mantenerH [3] = {-2, 0 ,2};
double subidaPequenaH[3] = {0,1.5,3};
double subidaNormalH[3] = {2.5,3.5,5.5};
double subidaGrandeH[3] = {4,6,8};


/*  MATRIZ DE REPRESENTACION DE LA VARIACION DE TEMPERATURA, DONDE:
    B: BajadaGrande, b: BajadaNormal, v: BajadaPequeña, m: mantener, z: SubidaPequeña, s: SubidaNormal, S: SubidaGrande
*/ //FUZZY ASOCIATION MATRIX
/*char FAM[5][5] = {               {'z', 'z', 'S', 'S', 'S'},
			                     {'m', 'm', 's', 's', 'z'},
						         {'m', 'm', 'm', 'm', 'v'},
						         {'m', 'm', 'v', 'v', 'v'},
						         {'v', 'b', 'b', 'B', 'B'},
					           };*/


char FAM[5][5] = {               {'s', 'z', 'z', 'S', 'S'},
			                     {'m', 'm', 's', 'z', 'z'},
						         {'m', 'm', 'm', 'm', 'v'},
						         {'v', 'b', 'b', 'b', 'b'},
						         {'B', 'b', 'b', 'B', 'B'},
					           };
					           
					           
	/*  MATRIZ DE REPRESENTACION DE LA VARIACION DE TEMPERATURA, DONDE:
    B: BajadaGrande, b: BajadaNormal, v: BajadaPequeña, m: mantener, z: SubidaPequeña, s: SubidaNormal, S: SubidaGrande
*/ //FUZZY ASOCIATION MATRIX

char FAMH[5][5] = {              {'z', 'z', 'm', 'S', 'S'},
			                     {'s', 's', 'm', 'S', 'S'},
						         {'z', 'm', 'm', 'v', 's'},
						         {'S', 's', 'z', 'b', 'b'},
						         {'S', 'S', 's', 'B', 'B'},
					           };
