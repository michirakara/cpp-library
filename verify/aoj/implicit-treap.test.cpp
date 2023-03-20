#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <bits/stdc++.h>
using namespace std;

#include "../../binary-search-tree/implicit-treap.hpp"

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int n,q;
    cin>>n>>q;
    
    ImplicitTreap<S,op,e,F,mapping,composition,id> set;
    for(int i=0;i<n;i++){
        int x;cin>>x;set.insert(set.size(),x);
    }

    for(int i=0;i<q;i++){
        int x,y,z;
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