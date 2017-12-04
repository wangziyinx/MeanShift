D=importdata('s1.txt');
plot(D(:,1),D(:,2),'k.');hold on;

bd=5e4;
numKernel=100;
C=MeanShiftCluster(D, bd, numKernel);
plot(C(:,1),C(:,2),'ro')