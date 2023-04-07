#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

#include "../../tree/heavy-light-decomposition.hpp"

using S=long long;
S op(S a,S b){return a+b;}
S e(){return 0;}
int main(){
    int n,q;cin>>n>>q;
    UnweightedGraph T(n);
    for(int i=1;i<n;i++){
        int tmp;cin>>tmp;
        T[tmp].push_back(i);
        T[i].push_back(tmp);
    }
    HeavyLightDecomposition<S,op,e> HLD(T);
    while(q--){
        int u,v;cin>>u>>v;
        cout<<HLD.lcu(u,v)<<endl;
    }
}