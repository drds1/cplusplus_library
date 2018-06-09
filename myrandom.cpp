// normal_distribution
#include <iostream>
#include <string>
#include <random>

using namespace std;


// HOW to comile? 'g++-7 myrandom.cpp -o mr.exe'

// function to draw from gaussian distribution with mean ave and std sig
template <class T>
T rang(T ave,T sig){
T sum;
sum = 0.0;

random_device generator;
normal_distribution<float> distribution(ave,sig);
float dice_roll = distribution(generator);  // generates number in the range 1..6 

cout << dice_roll << " normal dis" << endl;	

return(dice_roll);

}







int main()
{
  const int nrolls=10000;  // number of experiments
  const int nstars=100;    // maximum number of stars to distribute
  float gr;
  //std::default_random_engine generator;
  std::random_device generator;
  std::normal_distribution<double> distribution(5.0,2.0);

  int p[10]={};

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>=0.0)&&(number<10.0)) ++p[int(number)];
  }

  std::cout << " normal_distribution (5.0,2.0):" << std::endl;

  for (int i=0; i<10; ++i) {
    std::cout << i << "-" << (i+1) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }
  
  gr = rang(0,1);
  return 0;
}