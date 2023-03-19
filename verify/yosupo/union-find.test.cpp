#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../../union-find/union-find.hpp"

int main(){
    int n,q;
    cin>>n>>q;

    UnionFind uf(n);
    
    for(int _i=0;_i<q;_i++){
        int t,u,v;
        cin>>t>>u>>v;
        if(t==0){
            uf.unite(u,v);
        }else{
            cout<<(uf.same(u,v)?1:0)<<endl;
        }
    }
}