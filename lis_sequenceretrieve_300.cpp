// reference cp-algorithms.com 
// O(n^2)
// retrieve the longest increasing subsequence 
#include <bits/stdc++.h>
using namespace std;

vector <int> lis(vector <int> const & a ){
    int n = a.size();
    vector <int> d(n,1),p(n,-1);
    for (int i =0;i<n;i++){
        for (int j = 0;j<i;j++){
            if (a[j]<a[i] && d[i]<=d[j]){
                d[i]= d[j]+1;
                p[i]=j;

        }
        }
    }

    int ans =d[0], pos=0;
    for (int i =1;i<n;i++){
        if (d[i]>ans){
            ans= d[i];
            pos = i;

        }
    }

    //pos is the index of the last number in the longest increaing subseq
    //iterating through all the position in the lis until we hit the end (-1)`git 
    vector<int> subseq ;
    while (pos!=-1){
        subseq.push_back(a[pos]);
        pos= p[pos];
    }
    reverse(subseq.begin(),subseq.end());
    return subseq;
}


int main(){
}