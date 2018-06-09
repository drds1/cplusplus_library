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
a   = sqrt( p0*pow(freqnow/f0,a) / (1 + pow(freqnow/f0,(a-b))));
cknow = ((double) rand() / (RAND_MAX))*a;
sknow = ((double) rand() / (RAND_MAX))*a;
sum = sum + sknow*sin(wnow*tnow) + cknow*cos(wnow*tnow);
} //end frequency loop
y[it] = sum;

} // end time loop

//sk  = mr.normdis(nf,0,1)*a
//ck  = mr.normdis(nf,0,1)*a


}
 
 

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
double = sum;

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

// compute the weighted sum of inputs to this neuron from the upper level
ws = weight_sum(w_upper, op_upper, n_upper);

// compute the activation function and its derivative for this level
af = act_fun(ws);
diff_af = diff_act_fun(af);

// compute the delta for this level
delta_now = delta_j_in(w_lower, delta_lower,n_lower, diff_af );

for (iw=0;<n_upper;iw=iw+1){
w_upper_new[iw] = -eta*delta_now*op_upper[iw];
}

}






// now need to build propper network using these routines above. 
// start simple. How to decide number of layers and neurons in each layer?










