#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323
#define g 9.81

#define r 9.31
#define ps 753.0
#define pw 1000

void bisection(double(*f)(double), double a, double b, int n) {
	double fa = f(a);
	double fb = f(b);
	if (fa * fb >= 0) {
		printf("Intervalo invalido.\n");
		return;
	} else {
		for (int i = 0; i < n; i++) {
			double m = 0.5 * (a + b);
			double fm = f(m);
			if (fm == 0) {
				printf("Raiz encontrada. r = %.17lf\n", m);
				return;
			}
			if (i + 1 == n) {
        		printf("%.17lf,", m);
      		}
			if (fa * fm < 0) {
				b = m;
			} else {
				a = m;
				fa = fm;
			}
		}
	}
}

void newton(double (*f) (double), double (*df) (double), double x0, int n) {
	for (int i = 0; i < n; i++) {
		double dfx0 = df(x0);

		if (dfx0 == 0) {
			break;
		}
		double xi = x0 - f(x0) / dfx0;
		if (i + 1 == n) {
     		printf("%.17lf,", xi);
    	}
		x0 = xi;
	}
}

void secant(double (*f)(double), double x0, double x1, int n) {
	for (int i = 0; i < n; i++) {
		double fx0 = f(x0);
		double fx1 = f(x1);
		if (fx0 == fx1) {
			break;
		}
		double x2 = (x0 * fx1 - x1 * fx0) / (fx1 - fx0);
		if (i + 1 == n) {
			printf("%.17lf,", x2);
		}
		x0 = x1;
		x1 = x2;
	}
}

void falsePosition(double (*f)(double), double a, double b, int n) {
	for (int i = 0; i < n; i++) {
		double fa = f(a);
		double fb = f(b);
		if (fa * fb >= 0) {
			return;
		}
		double x = (a * fb - b * fa) / (fb - fa);

		if (i + 1 == n) {
		  printf("%.17lf,", x);
		}

		double fx = f(x);

    if (fx == 0) {
      printf("A raiz procurada e: x = %.17lf, e foi encontrada na %d iteracao",x, i+1);
      return;
    } else {
  		if (fa * fx < 0) {
  			b = x;
  			fb = fx;
  		} else {
  			a = x;
  			fa = fx;
  		}
    }
	}
}

void fixedPoint(double (*f)(double), double x0, int n) {
	for (int i = 0; i < n; i++) {
		x0 = f(x0);
		if (i + 1 == n) {
			printf("%.17lf,", x0);
		}
	}
}

double f(double h) {
	return pw*((pow(r,3) * 4 /3) - (pow(h,2))*r + (pow(h,3))/3) - ps*(4*(pow(r,3))/3);
}

double df(double h) {
	return pw*(-2*h*r + pow(h,2));
}

int main(void) {
	int iterationsBissection[] = {2, 4, 8, 12};
	int iterationsNewton[] = {1, 3, 5};
	int iterationsSecant[] = {1, 2, 5};
	int iterationsFalsePosition[] = {2, 4, 7, 9};

	// Método da Bisseção
	for(int i = 0; i < sizeof(iterationsBissection) / sizeof(iterationsBissection[0]); i++) {
		bisection(f, 0, 18.62, iterationsBissection[i]);
	}
	printf("\n");

	// Método de Newton
	for(int i = 0; i < sizeof(iterationsNewton) / sizeof(iterationsNewton[0]); i++) {
		newton(f, df, 5.84 , iterationsNewton[i]);
	}
	printf("\n");

	// Método da Secante
	for(int i = 0; i < sizeof(iterationsSecant) / sizeof(iterationsSecant[0]); i++) {
		secant(f, 0.83, 18.36, iterationsSecant[i]);
	}
	printf("\n");

	// Método da Posição Falsa
	for(int i = 0; i < sizeof(iterationsFalsePosition) / sizeof(iterationsFalsePosition[0]); i++) {
		falsePosition(f, 0, 18.62, iterationsFalsePosition[i]);
	}
	printf("\n");

	return 0;
}