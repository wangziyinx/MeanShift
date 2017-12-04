//
//  MeanShift.cpp
//  Mean_shift
//
//  Created by Wang Ziyin on 12/3/16.
//  Copyright © 2016 Wang Ziyin. All rights reserved.
//

#include "MeanShift.hpp"

double dis(double *x, double *y, int dim){
    
        double s=0;
        for (int i=0; i<dim; i++) {
            s+=(x[i]-y[i])*(x[i]-y[i]);
        }
        return sqrt(s);
}



double kernel(double d, double h){
    return exp(-0.5*d*d/(h*h));
}


//void MeanShit::update_once(vector <double *> &Data){
//    
//    vector<double * > centers2;
//    for (int i=0; i<NumKernel; i++) {
//        centers2.push_back(new double [dim]());
//    }
//    double w[NumKernel]; //sum of weight
//    for (int i=0; i<Data.size(); i++) {
//        for (int j=0; j<NumKernel; j++) {
//            double d= dis (centers[j], Data[i], dim);
//            if (d<kernel_bandwidth) {
//                w[j]+=kernel(d, kernel_bandwidth);
//                for (int l=0; l<dim; l++)
//                    centers2[j][l]+=kernel(d, kernel_bandwidth)*Data[i][l];
//            }
//        }
//    }
//    for (int i=0; i<NumKernel; i++) {
//        for (int l=0; l<dim ; l++) {
//            centers2[i][l]=centers2[i][l]/w[i];
//        }
//    }
//    
//    
//}




void MeanShit::update_once(vector <double *> &Data){
    
    for (int i=0; i<NumKernel; i++) {
        if (stop_flag[i]==1) {
            
            continue;
        }
        
        vector<double *> Data_this;
        vector<double  > weight;
        double s=0;
        for (int j = 0; j<Data.size(); j++) {
            double d=dis(centers[i],Data[j],dim);
            if (d<kernel_bandwidth) {
                Data_this.push_back(Data[j]);
                weight.push_back(kernel(d,kernel_bandwidth));
                s+=weight.back();
            }
        }
        
        double *c =new double [dim]();
        for (int j=0; j<Data_this.size(); j++){
            for (int l=0; l<dim; l++){
                c[l]+=weight[j]*Data_this[j][l];
            }
        }

        if (s==0) {
            cout<<"error"<<endl;
        }
        
        for (int l=0; l<dim; l++)
            c[l]=c[l]/s;
        
        
        if (dis(c, centers[i], dim)<0.001*kernel_bandwidth) {
            stop_flag[i]=1;
            continue;
        }
        for (int l =0 ; l< dim; l++) {
            centers[i][l]=c[l];
        }
        
    }
}

void MeanShit::initialization(vector <double *> &Data){
    for (int i=0; i<NumKernel; i++) {
        double * c = new double [dim]();
        
        int t=rand() % Data.size();
        for (int j=0; j<dim; j++) {
            c[j]=Data[t][j];
        }
        centers.push_back(c);
    }
}

void array_coppy(double * x, double * y, int dim){
    for ( int i=0; i<dim; i++) x[i]=y[i];
    
}







void MeanShit::clustering(vector<double *> &Data){
    initialization(Data);
    for (int i=0; i<maxIter; i++){
        update_once(Data);
        int s=0;
        for (int j=0; j<NumKernel; j++) {
            s+=stop_flag[j];
        }
        if (s==NumKernel) {
            break;
        }
    }

}






















