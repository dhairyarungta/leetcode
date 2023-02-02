class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n= arr.size();
        int left = 0;
        for (int i =1;i<n;i++){
            if(arr[i]<arr[i-1]){
                left =i-1;
                break;
            }
        }
        int right = 0;
        for (int i =n-1;i>0;i--){
            if(arr[i]<arr[i-1]){
                right =i;
                break;
            }
        }
        if(right==0){
            return 0;
        }
        int ans = min(n-left-1,right);
        for (int i =0,j=right;i<=left && j<n;i++){
            if(arr[i]<=arr[j]){
                // i++;
            }
            else{
                while( j<n && arr[i]>arr[j] ){
                    j++;
                }
            }
            ans = min(ans,j-i-1);
        }
        return ans;
    }
};




// class Solution {
// public:
//     int findLengthOfShortestSubarray(vector<int>& arr) {
//              int n = arr.size(), j;
// 		//find last non sorted element
//         for (j = n - 1; j > 0; --j)
//             if (arr[j - 1] > arr[j])
//                 break;
				
// 		//already sorted
//         if (j == 0) return 0;
//         int res = j;
//         for (int i = 0; i < n; ++i) {
//             if (i > 0 && arr[i - 1] > arr[i])
//                break;
//             while (j < n && arr[i] > arr[j])
//                 ++j;
//             res = min(res, j - i - 1);
//         }
//         return res;
//     }
    
// }