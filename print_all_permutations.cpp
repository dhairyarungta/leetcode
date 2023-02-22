#include <bits/stdc++.h>
using namespace std;
void helperf(string input, string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
        
    }
    for(int i =0;i<input.size();i++){
        string temp = input;
        swap(temp[0],temp[i]);
        string outputTemp = output+temp[0];
        helperf(temp.substr(1),outputTemp);
    }

}

void printPermutations(string s){
    string out = "";
    helperf(s,out); 
}

int main(){
    string s = "abcd";
    printPermutations(s);
    return 0;
}