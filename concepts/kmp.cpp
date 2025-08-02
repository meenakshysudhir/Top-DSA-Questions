#include <bits/stdc++.h>
using namespace std;

vector<int> piTable(string pattern){
    int m = pattern.size();
    vector<int> pi(m,0);
    int j = 0;
    for(int i = 1; i < m;i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = pi[j-1];
        }
        if(pattern[i] == pattern[j]) j++;   
        pi[i] = j;
    }
    return pi;

}
int kmp(string text,string pattern){
    vector<int> pitable = piTable(pattern);
    int n = text.size(), m = pattern.size(),j=0;
    for(int i = 0;i<n;i++){
        while(j > 0 && text[i] != pattern[j]) j = pitable[j-1];
        if(text[i] == pattern[j]) j++;
        if(j == m) return i-m+1; 

    }
    return -1;
}
int main(void){
   string pattern="aaaaaab", text="aaaaaaaamaaaaaab";
   int ind = kmp(text,pattern);
   if(ind == -1) cout << "Pattern not matching" << endl;
   else{
    cout << "Pattern found at index : " << ind << endl;
   }   
}