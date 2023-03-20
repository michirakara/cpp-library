#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <bits/stdc++.h>
using namespace std;

#include "../../binary-search-tree/implicit-treap.hpp"

using T = long long;
using F = long long;

const T INF = 8e18;
const F ID = 8e18;

T op(T a, T b){ return std::min(a, b); }
T e(){ return INF; }
T mapping(F f, T x){ return (f == ID ? x : f); }
F composition(F f, F g){ return g==ID ? f : g; }
F id(){ return ID; }

int main(){
    int n,q;
    cin>>n>>q;
    
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ImplicitTreap<T,op,e,F,mapping,composition,id> set(a);
    while(q--){
        long long x,y,z;
        cin>>x>>y>>z;
        if(x==0){
            set.rotate(y,z,z+1);
        }else if(x==1){
            cout<<set.prod(y,z+1)<<endl;
        }else{
            set.apply(y,y+1,z);
        }
    }
}