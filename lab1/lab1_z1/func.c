#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "func.h"

double factorial(double x){
    double sum = 1;
    int i = 1;
    for (i = 1; i <= x; i++){
        sum *= i;
    }
    return sum;
}

double Ssin(double x,double eps){
    double current = 1, sum = 0;
    int i = 0, degree = 0;
    while( abs(current) > eps ){
    	degree = 2*i + 1;
    	current = pow(-1,i) * pow(x, degree) / factorial (degree);
    	sum += current;
    	i++;
	}
    return sum;
}

double Ccos(double x, double eps){
    double current = 1, sum = 0;
    int i = 0, degree = 0;
    while( abs(current) > eps ){
    	degree = 2*i;
    	current = pow(-1,i) * pow(x, degree) / factorial (degree);
    	sum += current;
    	i++;
	}
    return sum;
}
