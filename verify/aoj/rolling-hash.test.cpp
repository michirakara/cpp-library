#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/rolling-hash.hpp"

int main(){
    string T,P;cin>>T>>P;
    int base=27+rand()%50;
    RollingHash t(T,base),p(P,base);

    for(int i=0;i<=T.size()-P.size();i++){
        if(t.hash(i,i+P.size())==p.hash(0,P.size()))cout<<i<<endl;
    }
}