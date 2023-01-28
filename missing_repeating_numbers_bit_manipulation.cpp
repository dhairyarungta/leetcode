// Time Comeplexity O(n);
// Space Compelexity O(1);

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    int arrxor=0;
    int numxor=0;

    for (int i =0;i<n;i++){
        arrxor^=arr[i];
        numxor^= (i+1);
    }

    int findxor = arrxor^numxor;
    int setBit = 0;
    int notSetBit = 0;

    int bitIndex = findxor& ~(findxor-1);
    
    for (int i =0;i<n;i++){
        if(arr[i] & bitIndex){
            setBit^=arr[i];
        }

        else {
            notSetBit^=arr[i];
        }
    }
    
    for (int i =1;i<=n;i++){
        if(i &bitIndex){
            setBit ^=i;
        }

        else {
            notSetBit ^=i;
        }
    }

    int m , r;

    for (int i =0;i<n;i++){
        if(setBit==arr[i]){
            r = setBit;
            m = notSetBit;
        }

        if(notSetBit==arr[i]){
            r =notSetBit;
            m = setBit;
        }
    }    
    pair<int, int> ans = {m,r};

    return ans;


}