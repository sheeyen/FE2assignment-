//FE2 ASSIGNMENT STRADDLE 

#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#define PI 3.14159265358979323846

using namespace std; 

double N (double);
double M (double);

void main ()
{
	float time, K, d1, d2, nd1, nd2, n1d1, delta, vega, theta;
	float S, r, q, v;

	K = 100; 
	r = 0.07; 
	q = 0; 
	v = 0.30;

	ofstream output; 
	output.open("Q3straddle.txt", ios :: out);

		output << setw(13) << "Stock Price";
		output << setw(13) << "Delta(1M)" << setw(13) << "Vega(1M)"; 
		output << setw(13) << "Theta(1M)" << setw(13) << "Delta(1Y)";
		output << setw(13) << "Vega(1Y)" << setw(13) << "Theta(1Y)";

		for (S = 60; S <= 140; S += 1)
		{ 
			time = 0.083333333;
			output << "\n" << setw(13) << S ; 
		
			do {
					d1 = (log(S/K) + (r - q + (pow(v,2)/2))*time)/(v*pow(time,0.5)); 
					d2 = d1 - (v*pow(time,0.5));
					nd1 = N(d1); 
					nd2 = N(d2);
					n1d1 = M(d1);
		
					delta = nd1 + nd1 - 1 ;

					vega = S*n1d1*pow(time,0.5) + S*n1d1*pow(time,0.5);;
					 
					theta = - (S*n1d1*v)/(2*pow(time,0.5)) - r*K*exp(-r*time)*nd2 - (S*n1d1*v)/(2*pow(time,0.5)) + r*K*exp(-r*time)*N(-d2); 
				 
					output << setw(13) << delta << setw(13) << vega << setw(13) << theta ;

					time = time*12;
					} while (time <= 1);

		}
			
	output.close();
	
	system("gnuplot -p Q3straddledelta.gnu");
	system("gnuplot -p Q3straddlevega.gnu");
	system("gnuplot -p Q3straddletheta.gnu");	
	cout << "\nCompleted\n" << endl;
	
_getch();
}

// To calculate N(d1) & N(d2)  
double N (double x)
{
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x)/sqrt(2.0);

    // A&S formula 7.1.26
    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return 0.5*(1.0 + sign*y);
} 

// To calculate N'(d1)
double M (double w)
{
		double z; 
		z = pow(w,2)/2;
    return pow(2*PI, -0.5)*exp(-z);
} 
