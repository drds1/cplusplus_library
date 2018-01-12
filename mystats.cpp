//how do i compile I forgot. Find out when have internet and stick the line up here
#include <iostream>
#include <stdlib.h>
#include <math.h>                           /* math functions */

using namespace std;


/* example of how to use templates to create a function that can have int, float , double inputs etc
template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}
*/








// function to calculate the average of input array
template <class T>
T avg(T x[],int nx){
T sum;
sum = 0.0;
for( int i = 0; i < nx; i = i + 1 ) {
sum = sum + x[i];
}
return((sum)/nx);

}








/* how to define without template
float sort(float a[],int size)
{
*/

// function to sort arrays
template <class T>
T sort(T a[],int size)
{
    int i,j;
    T temp;
  cout<<"\nStored Data Before Sorting In Array :: \n\n";
 
  for(i=0;i<size;i++)
  {
  cout<<" "<<a[i]<<" ";
  }
 
 for(i=0;i<size;i++)
 {
     for(j=0;j<size-i-1;j++)
     {
         if(a[j]>a[j+1])
         {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
         }
     }
 }
 
 cout<<"\n\nStored Data After Sorting In Array :: \n\n";
 
 for(i=0;i<size;i++)
  {
  cout<<" "<<a[i]<<" ";
  }
 
  cout<<"\n";
 
  return 0;
 
 }
 
 
 
 




// now write function to calculate median 
template <class T>
T median(T a[],int size)
{
T b[size],c;
int i;

// make a copy of array
for(i=0;i<size;i++)
 {
 b[i] = a[i];
 }
 
 
//sort array b 
c = sort(b,size);


//select half way element if size odd else pick half way between
if (remainder(size,2) != 0) {
cout<<"median function" << size << size/2 << endl;
return(b[size/2]);
}
else {
cout<<"median function" << size << size/2 - 1 << size/2 << endl;
return((b[size/2-1] +b[size/2])/2);
}



}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
// now write function to calculate a damped random walk light curve
void drw(double t[],double y[],int n,double freq[], int nf, double taudrw){

double sknow, cknow, p0=1.0,a=-2,b=-2,pi=3.141592653589793238462643383279;
double twopi = 2*pi,wnow,tnow,sum=0.0,freqnow,f0;

//time loop
for(int it=0;it<n;it = it + 1) {
tnow = t[it];

sum = 0.0;
//frequency loop
f0 = 1./taudrw;
for(int iw=0;iw<nf;iw = iw + 1) {
freqnow = freq[iw];
wnow = twopi*freqnow;
a   = sqrt( p0*pow(freqnow/f0,a) / (1 + pow(freqnow/f0,(a-b));
cknow = ((double) rand() / (RAND_MAX))*a;
sknow = ((double) rand() / (RAND_MAX))*a;
sum = sum + sknow*sin(wnow*tnow) + cknow*cos(wnow*tnow);
} //end frequency loop
y[it] = sum

} // end time loop

//sk  = mr.normdis(nf,0,1)*a
//ck  = mr.normdis(nf,0,1)*a


}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


























int main ()
{
float *x,*y,*sig,ay,e;
int np,b;
long m,c;
double taudrw,f0drw,*freq,flodrw,fhidrw,df,*xdrw,*ydrw;
int nfdwr;
void drwfunc;



// specify parameters of test (number of points intercept, gradient etc)
np = 6;
c = 2.0;
m = 1.0;



/* the above allows you to declare arrays and allocate them later in 
the program (dynamic allocation)
*/
x = new float [np];
y = new float [np];
sig = new float [np];
xdrw = new double [np];
ydrw = new double [np];

// just test out how to print numbers and assign values to arrays
for( int i = 0; i < np; i = i + 1 ) {
x[i] = 1.0*float(i);
xdrw[i] = 1.0*double(i);
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


// try sorting y array
ay = avg(y, np);
cout << "average y = "<< ay << endl;



y[0] = 10.2;
for( int i = 0; i < np; i = i + 1 ) {
cout << "y value pre sorty "<< y[i] << endl;
}

b = sort(y,np);
for( int i = 0; i < np; i = i + 1 ) {
cout << "y value post sort y "<< y[i]<< endl;
}


e = median(y,np);
cout << "Median = "<< e << endl;




/*
test the drw function
specify drw parameters to test drw routine 
*/
flodrw = 0.1;
fhidrw = 10.0;
nfdrw  = 100;

df = (fhidrw - flodrw)/(nfdrw-1.0);
taudrw = 1./(0.5*(fhidrw-flodrw));
freq = new double [nfdrw];
for (int i=0;i<nfdrw;i=i+1){
freq[i] = flo + i*df;
}
drwfunc = drw(xdrw,ydrw,np,freq,nfdrw,taudrw);

for (int i=0;i<np;i=i+1){
cout << "xdrw="<<xdrw[i]<<"  ydrw="<<ydrw[i]<<"  taudrw="<<taudrw<<" "<< endl;
}



}
// end of main body of code now define all functions below including the
// average of an array and least squares
















