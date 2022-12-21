//find lis of the given vector (a) 
#include <bits/stdc++.h>
using namespace std;


int lis (const vector<int> &a){
    vector<int> d (a.size()+1, INT_MAX);
    int n = a.size();
    //d has indexes from d[0] to d[n]
    d[0]= INT_MIN;
    for (int i =0;i<n;i++){
        //i is used to process the a vector 
        for (int j =1 ;j<=n;j++){
            if (d[j-1]<a[i] && a[i]<d[j]){
                d[j]= a[i];
            }
    }
    }
    int len = 0;
    for (int i =0;i<=n;i++){
        if (d[i]!=INT_MAX && i>len){
            len =i;
        }
    }
    return len;

}