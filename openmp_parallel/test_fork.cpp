#include <iostream>
#include <stdlib.h>
#include <math.h>                           /* math functions */
#include <omp.h>
#include <cmath>
#include <time.h>

using namespace std;


/* program to test open mp parallelisation in c++
*/

/* specify number of threads
better just to let the code decide?? e.g possible problem if only have one core 
and decide to split between 3 threads??
*/


int main()
{
  const int size = 25600;
  int start,end,time,tn,nthread=3;
  double sinTable[size];
  
  start = clock();
  
  #pragma omp parallel num_threads(nthread)
  {
  #pragma omp parallel for
  for(int n=0; n<size; ++n)
    sinTable[n] = std::sin(2 * M_PI * n / size);
  }
  end = clock();
  time = end - start;
   
  cout << "parallelised " << time << endl; 
  
  
  
  
  
  start = clock();
  for(int n=0; n<size;n=n+1){
  sinTable[n] = std::sin(2 * M_PI * n / size);
  }  
  end   = clock();
  time  - end - start;
  cout << "not parallelised " << time << endl;



// now print out numbers 1..n these may be in a different order depending on when
// each thread gets to it. Other syntax required to make it go in order
 #pragma omp parallel num_threads(nthread)
{
  #pragma omp for
  for(int n=0; n<10; ++n)
  {
    cout<< n<< " ";
  }
 
  tn = omp_get_thread_num();
 }
 cout << endl;
 cout << "number of threads: " << tn << endl<< endl;







  // the table is now initialized
}