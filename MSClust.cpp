#include "MSClust.hpp"

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
/* variable declarations here */
double pf;      /* input scalar */
double th_large;
double th_small;
double maxl;
double *D;     /* data is store in colunm*/

mwSize dim;  
mwSize N;


/* get input */
D=mxGetPr(prhs[0]);
N=mxGetN(prhs[0]);
dim=mxGetM(prhs[0]);

double kernel_bandwidth=mxGetScalar(prhs[1]);
int NumKernel=mxGetScalar(prhs[2]);
int maxIter=mxGetScalar(prhs[3]);




// /* code here */
//     
//     
    vector<double * > Data;
    matrix2vector(D, N, dim, Data);
    
    MeanShit Cluster;
    Cluster.kernel_bandwidth=kernel_bandwidth;
    Cluster.NumKernel=NumKernel;
    Cluster.maxIter=maxIter;
    Cluster.dim=dim;
    Cluster.stop_flag=new int [Cluster.NumKernel]();
    
    Cluster.clustering(Data);
    
    vector <double *> CC;
    

// /* get output */
    



plhs[0] = mxCreateDoubleMatrix(Cluster.centers.size(), dim, mxREAL);
double * outMatrix = mxGetPr(plhs[0]);
vector2matrix(outMatrix, Cluster.centers.size() ,dim, Cluster.centers);
}



void matrix2vector(double * M,  mwSize N, mwSize dim, vector < double * > & D ){
    mwSize i;
    for (i=0; i<N; i++){
        D.push_back(&M[i*dim]);
    }
}

void vector2matrix(double * M, mwSize N, mwSize dim, vector <double *> &D){
    mwSize i,j;
   
    for (i=0; i<dim; i++)
        for (j=0; j<N; j++)
            M[i*N+j]=D[j][i];
}




