# MeanShift
Implemented Mean Shift algorithm in C++ and wrapped by Matlab.

To compile with Matlab mex, run makefile.m

To call the function in Matlab:
C=MeanShiftCluster(D, bd, numKernel);

parameters
D: dataset, N x d. Namely each row is a vector.
bd: bandwidth, namely the size of the kenel.
numKernel: the number of Kernels
C: centers returned from the algorithm.

More about the algorithm:
Initialization: random.
Kernel Type: hard assignment.
The algorithm merge kernels if their final position is close to each other.

Mex file for mac has been pre-built.
Please feel free to download and use. If there is any issue please let me know.
I am also happy to provide advanced functionalities if you need. So, let me know.

