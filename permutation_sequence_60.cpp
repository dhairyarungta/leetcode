
//Passes 134/200 testcases on leetcode
// logic correct
// TLE error but still interesting recursive approach
// approach works baesd on the recursvie Lexicographic order printing 
class Solution {
public:
    void helperf(string input, string output, int &num, int target,string &ans){
    if(input.size()==0){
        num++;
        if(num==target){
        ans = output;
        }
    }
    for(int i =0;i<input.size();i++){
        string temp = input;
        swap(temp[0],temp[i]);
        string outputTemp = output+temp[0];
        string temp2 = temp.substr(1);
        sort(temp2.begin(),temp2.end());
        helperf(temp2,outputTemp,num, target,ans);
    }
}
    string getPermutation(int n, int k) {
        string s="";
        for (int i=1;i<=n;i++){
            s = s+to_string(i);
        }
        string temp ="";
        string ans = "";
        int num = 0;
         helperf(s,temp,num,k,ans);
        return ans;
        
    }
};




// class Solution {
// public:
//     int findFactorial(int n){
//         int temp =1;
//         for (int i =1;i<=n;i++)temp*=i;

//         return temp;
//     }

//     int recursiveGetPermutation(int n , int k,stirng &s){
//         int firstNum = k/
//     }

//     string getPermutation(int n, int k) {
//         string s = "";
//         recursiveGetPermutation(n,k,s);
//         return s;
//     }
// };