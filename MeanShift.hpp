//
//  MeanShift.hpp
//  Mean_shift
//
//  Created by Wang Ziyin on 12/3/16.
//  Copyright © 2016 Wang Ziyin. All rights reserved.
//

#ifndef MeanShift_hpp
#define MeanShift_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;




class MeanShit{
public:
    double kernel_bandwidth;
    int NumKernel;
    int maxIter;
    int dim;
    int * stop_flag;
    vector<double * > centers;
    
    
    void update_once(vector<double *> & Data);
    void initialization (vector <double *> &Data);
    void clustering(vector<double *> & Data);
    
};

#endif /* MeanShift_hpp */
