//O(n) time and O(1) space solution can be done using simple maths , (sum of squares of first n numbers) and (sum of first n numbers)

//This solution requires either O(n) extra space or ability to change the original array values
vector<int> Solution::repeatedNumber(const vector<int> &B) {


    vector<int> solReturn ;
    vector<int> A(B.size());
    for (int i =0;i<A.size();i++) A[i]=B[i];
    for (int i =0;i<A.size();i++){
        if(A[abs(A[i])-1]<0){
            solReturn.push_back(abs(A[i]));
            continue;
        }
        A[abs(A[i])-1]=(-1*A[abs(A[i])-1]);
        
        
    }
    int missingIndex;
    // for (int i=0;i<A.size();i++)cout<<A[i]<<" ";
    
    for (int i=0;i<A.size();i++){
        if(A[i]>0){
            missingIndex=i+1;
            break;
        }
    }
    solReturn.push_back(missingIndex);
    return solReturn;
}
//This can be also be done using Floyd's cycle detection algorithm and then using maths to find the missing digit