class Solution {
public:
    int candy(vector<int>& students) {
            int n  =students.size();
    vector<int> ans(n,1);

    for (int i =1;i<n;i++){
        if(students[i]>students[i-1]){
            ans[i]+=ans[i-1];
        }
    }
    for (int i =n-2;i>=0;i--){
        if( ans[i]<ans[i+1]+1 && students[i]>students[i+1]){
            ans[i]=ans[i+1]+1;
        }
    }

    int sum=0;
    for (auto i :ans)sum+=i;
    return sum;

    }
};

// #include <bits/stdc++.h>
// using namespace std;

// pair<int, int> longestDec(const vector<int> &students) {
//   int st = 0, en = 0;
//   int ansstart = 0, ansend = 0;
//   int n = students.size();
//   while (en < n - 1) {
//     if (students[en + 1] < students[en]) {
//       if (ansend - ansstart < en + 1 - st) {
//         ansend = en + 1;
//         ansstart = st;
//       }
//     } else {
//       st = en + 1;
//     }
//     en++;
//   }
//   return pair<int, int>(ansstart, ansend);
// }

// int countDistinct(int st, int en , const vector<int> & students){
//     set<int> s;

//     for (int i = st ; i<=en;i++){
//         set.insert(students[i]);
//     }
//     return s.size();
// }

// int requiredCandies(vector<int> &students) {
//   // Write your code here.
//   int n = students.size();
//   if (n == 1) return 1; 
//   pair<int, int> subseq = longestDec(students);

//   int minbuy = 0;
//   int curval = 1;
//   int longestDecLen = subseq.second-subseq.first+1;
//  int prev = INT_MIN;

// int maxval= countDistinct(susbseq.first, subseq.second , students);
 
//   for (int i = 0;i<n-1;i++){
//       if(i==subseq.first){
//           curval = maxval+1;
//           minibuy+=curval;
//       }
//       else if(students[i]==students[i+1]){
//         minibuy+=curval;
//       }
//       else if(student[i]<student[i+1]){
//           curval
//       }
//   }  

// }