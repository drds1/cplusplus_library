#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include <math.h>                           /* math functions */
#include "misc_functions.cpp"

using namespace std;

//g++-7 test_2darray.cpp

void passFunc(int** a, int ndown, int nalong){
int i1,i2;

 for(i1=0;i1<ndown;i1++)
  {
  
  
  for(i2=0;i2<nalong;i2++)
  { 
  cout<<" "<<a[i1][i2]<<" ";
  }
  cout<<"\n";
  }
 
  
  
  
}



// jsut dont usethem!