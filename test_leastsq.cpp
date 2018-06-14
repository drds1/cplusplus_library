#include <iostream>
#include <stdlib.h>
#include <math.h>                           /* math functions */

using namespace std;






// function to calculate the average of input array
double avg(double x[],int nx){
float sum;

sum = 0.0;
for( int i = 0; i < nx; i = i + 1 ) {
sum = sum + x[i];
}
return(sum/nx);

}



// function to calculate the pivot point for linear regression
double xpivot(double x[],double sig[],int nx){
double sum1=0.0,sum2=0.0,a;

for(int i=0;i<nx;i = i + 1) {
a = 1./pow(sig[i],2);
sum1 = sum1 + x[i]*a;
sum2 = sum2 + a;
}

return(sum1/sum2);

}












// least squares fitting function
// x and y values set with scatter about random position, now do least squares fit
void leastsq(double x[],double y[],double sigy[],int n,double xpiv,double cop,double sigcop,double mop,double sigmop){

double b,c,a,grad,siggrad,sigintercept,intercept,sum1=0,sum2=0,sum3=0,sum4=0,siga,sigb;

xpiv = xpivot(x,sigy,n);


for(int i=0;i<n;i = i + 1) {
a = 1./pow(sigy[i],2);
c = x[i]-xpiv;
sum1 = sum1 + y[i]*a;
sum2 = sum2 + a;
sum3 = sum3 + y[i]*c*a;
sum4 = sum4 + c*c*a;
}

intercept = sum1/sum2;
sigintercept = sqrt(1/sum2);

grad = sum3/sum4;
siggrad = sqrt(1/sum4);


mop    = grad;
sigmop = siggrad;
cop    = intercept;
sigcop = sigintercept;

}





/* to do a multiline comment start with the slash
and star then
end the comment with a star and slash
*/

// alternatively just put double
// slash on each commented line



























int main ()
{
float *x,*y,*sig;
int np;
long m,c;


// specify parameters of test (number of points intercept, gradient etc)
np = 5;
c = 2.0;
m = 1.0;



/* the above allows you to declare arrays and allocate them later in 
the program (dynamic allocation)
*/
x = new float [np];
y = new float [np];
sig = new float [np];

// just test out how to print numbers and assign values to arrays
for( int i = 0; i < np; i = i + 1 ) {
x[i] = 1.0*float(i);
sig[i] = 1.0;
//cout << x[i] << endl;
//cout << "value of i: " << i << endl;
}





/* now set y values as randomly distributed about straight line with scatter 
 appropriate for error bars
 */
for( int i = 0; i < np; i = i + 1 ) {
y[i] = m*x[i] + c;
y[i] = ((double) rand() / (RAND_MAX))*sig[i] + y[i];
cout << "x and y (post random) " << x[i] << ' ' << y[i] << endl;
}









}
// end of main body of code now define all functions below including the
// average of an array and least squares




























