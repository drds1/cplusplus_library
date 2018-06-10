#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include <math.h>                           /* math functions */
#include "misc_functions.cpp"

using namespace std;

// g++-7 neural_net_func.cpp

/* compute the activation function for neuron input h = sum_nprevious (w_k O_k)
weighted sum of inputs from previous layer
*/

double act_fun(double h){

return(1./(1. + exp(h)));

}



/* compute the derivative of the activation function 
(appropriate for the sgn function above)
*/
//af = activation function need to calculate by calling function above
double diff_act_fun(double af){
return(af*(1. - af));
}



/* compute the weighted sum of inputs to this neuron from the 
op[1:n] outputs from the n neurons of the previous layer
*/

double weight_sum(double w[], double op[], int n){
double sum=0;

for(int iw=0;iw<n;iw = iw + 1) {
sum = sum + w[iw]*op[iw];
}
return(sum);
}








/* compute the delta term in the weight-update rule for neuron j (Dw = -eta delta op) */
/* first function for outer layer neuron */

double delta_j_out(double op_j, double true_j){
return((op_j - true_j)*op_j*(1.-op_j));
}     





/* now for an arbitrary inner neuron
inputs are the weights w_jl[1:nl]
and deltas delta_l[1:nl] 
of the nl neurons that receive input 
from this jth neuron 
also need the derivative of the activation function for this jth neuron
diff_af_j */
double delta_j_in(double w_jl[], double delta_l[],int nl, double diff_af_j ){
int iw;
double sum=0;

for(iw=0;iw<nl;iw=iw+1){
sum = sum + w_jl[iw]*delta_l[iw];
}

return(sum);
}




/* now need function to update the weights of neuron j in an arbitrary level of
the neuron network.
The upper level will have outputs op_upper[1:n_upper] of which op_upper[i] indicates
the weight in question weight_ij (i corresponds to upper level neuron of current neuron j
such that the weight between them is weight_ij)
 */
 
/* updates the weighs between current neuron j and all i n_upper neurons in the layer above 
the current jth layer e.g n_upper weights will be updated corrsponding to the weights between
this neuron and all neurons in upper layer (i indicates upper layer index, j indicates
current neuron)  
*/
// eta is input update rate
// new upper weights_jl are give by w_upper_new

/* outputs are the w_upper_new[n_upper] new weights between 
this level and the upper level. Note that I think the new weights should
just be saved and not used for until the weights for the whole network have been updated
using the back propagation 
*/

void update_weight_ij(double eta, double op_upper[],double w_upper[],double w_lower[],\
double delta_lower[], int n_lower, int n_upper,double w_upper_new[]){
double delta_now,ws,af,diff_af;
int iw;

// compute the weighted sum of inputs to this neuron from the upper level
ws = weight_sum(w_upper, op_upper, n_upper);

// compute the activation function and its derivative for this level
af = act_fun(ws);
diff_af = diff_act_fun(af);

// compute the delta for this level
delta_now = delta_j_in(w_lower, delta_lower,n_lower, diff_af );

for (iw=0;iw<n_upper;iw=iw+1){
w_upper_new[iw] = -eta*delta_now*op_upper[iw];
}

}






// now need to build propper network using these routines above. 
// start simple. How to decide number of layers and neurons in each layer?
// the internet says you never need more than 2 hidden layers in a NN
// and that the number of neurons / layer should be ave(Ninputs, Nouputs) = (Nin + nout)/2

// double *x is like declaring allocatable array in fortran. You allocate it to an
// arbitrary number of dimensions further down.
int main(){
double*test;
double**xin,**whid; 
int nits,ndim,ntest,n_level,n_per,nin,nout,i,i2;
float **datin;
// specify number of dimensions and number of tests of your neural net problem
// when I get better at c++ I will automate this so the code can
// get this information just from the input data file
ndim = 3;
ntest= 100;
nin = ndim;
nout = 1;

// number of hidden layers and number of neurons / hidden layer
n_level = 2;
n_per   = ndim/2;




/* load the test data and assign it to the proper array structure
2d arrays are a pain in tha arse to assign you have to allocate an
array of arrays. Define at top with ** then lose * when you allocate
the 1st dimension and the lose all the stars when you allocate the 2nd dimension
(dynamically allocated 2d arrays in c++ are like lists of lists in python)
*/
if( !(datin = read_file("lines.txt",ntest,ndim+1) ) ){return 0;}
xin = new double*[ntest];
for (i=0;i<ntest;i=i+1){
xin[i]=new double [ndim];
}

test = new double [ntest];
for(i=0;i<ntest;i=i+1){
test[i] = datin[ndim][i];
for(int i2=0;i2<ndim;i2=i2+1){
xin[i][i2]=datin[i2][i];
}
}



/* set the starting weights */




/* run the network for n_iterations 
http://deeplearning.stanford.edu/tutorial/

This one specific to this type of example
http://ufldl.stanford.edu/tutorial/supervised/MultiLayerNeuralNetworks/
See also wikipedia article on backpropagation
https://en.wikipedia.org/wiki/Backpropagation
for it = 1,n_iterations --> 
	
	for itrain = 1, ntrain
	 update all neuron weights
	 using back propagation
	 i.e update all weights based on first training example, then the next one and so on
 now do that for n_iterations
 
 
can have one algorithm for the inner layer neurons but will probably need 
a seprate algorithm for the input layer and the output layer as these will 
have a differentn number of neurons in each layer than the hidden layers
hidden layer will be aregular 2d grid of nlayers <= 2 X nper layer ([ninputs + noutputs]/2)
*/




}












