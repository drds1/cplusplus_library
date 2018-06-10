import numpy as np
#code to prepare a training data set for the neural net cplu plus program


#come up with a simple algorithm and then write out the answer for a number of training data sets
ntest = 100
ndim = 3



dat = np.zeros((ntest,ndim+1))
for i in range(ntest):
 dat[i,0] = np.random.randint(2)
 dat[i,1] = np.random.randint(2)
 dat[i,2] = np.random.randint(2)

#the rule is simply that the the answer is 1 if the 1st and 3rd dimensions agree
#or zero otherwise 
 if (dat[i,0] == dat[i,2]):
  test = 1
 else:
  test = 0
 
 dat[i,3] = test
 

np.savetxt('neural_net_train.txt',dat)





