// Solution work for values as big as n = 10e5;


vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long long sum=0;
    
    long long difference =0;
    for (int i =0;i<n;i++){
        difference+= i+1-A[i];
    }
    
    long long sqdiffernce= 0;
    for (int i =0;i<n;i++){
        sqdiffernce += (long long )pow(i+1,2)-(long long)pow(A[i],2);
    }
    
    long long twosum = sqdiffernce/difference;
    
    long long  missing = (difference+twosum)/2;
    long long repeat = twosum-missing;
    
    vector<int> ans(2);
    ans[0]=repeat;
    ans[1]=missing;
    
    return ans;
}

