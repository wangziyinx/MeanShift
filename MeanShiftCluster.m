function Cnew=MeanShiftCluster(D, bd, numKernel) 

% D: dataset, N x d. Namely each row is a vector.
%bd: bandwidth, namely the size of the kenel.
%numKernel: the number of Kernels

C=MSClust(D', bd, numKernel, 100);
% plot(C(:,1),C(:,2),'ro')
Cnew=[];
nMatch=[];
for i=1:size(C,1)
    if size(Cnew,1)==0
        Cnew(end+1,:)=C(i,:);
        nMatch=1;
        continue;
    end
    flag_match=0;
    for j=1:size(Cnew,1)
        if norm (Cnew(j,:)-C(i,:))<0.5*bd
            flag_match=1;
            Cnew(j,:)=(Cnew(j,:)*nMatch(j)+C(i,:));
            nMatch(j)=nMatch(j)+1;
            Cnew(j,:)=Cnew(j,:)/nMatch(j);
        end
    end
    
    if flag_match==0 && i>1
        Cnew(end+1,:)=C(i,:);
        nMatch(end+1)=1;
    end
end

