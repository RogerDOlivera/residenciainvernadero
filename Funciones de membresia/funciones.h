
//[a,m,b]
double funcionTriangular(double valores[], double x){
	double y = 0;
	double a = valores[0];
	double m = valores[1];
	double b = valores[2];
	
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

//[a,m]
double funcionGamma(double valores[], double x){
	double y = 0;
	double a = valores[0];
	double m = valores[1];
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


double funcionL(double valores[], double x){
	
	
	return 1 - funcionGamma(valores, x);
}



