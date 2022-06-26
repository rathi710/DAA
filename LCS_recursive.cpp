// LCS by recursion

#include<bits/stdc++.h>
using namespace std;

int lcs(int n, int m, string s1, string s2)
{
    if(n==0 || m==0) return 0;

    if(s1[n-1]==s2[m-1]){
        return 1 + lcs(n-1,m-1,s1,s2);
    }
    else{
        return max(lcs(n-1,m,s1,s2), lcs(n,m-1,s1,s2));
    }
}

int main(){
    int len=0;
    string s1 = "madsan";
    string s2 = "mcxanr";

    int n = s1.size();
    int m = s2.size();

    cout<<lcs(n,m,s1,s2);
}