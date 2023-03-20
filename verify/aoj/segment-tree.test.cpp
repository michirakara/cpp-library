#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <bits/stdc++.h>
using namespace std;

#include "../../segment-tree/segment-tree.hpp"

using T = long long;
T op(T a,T b){
    return min(a,b);
};
T e(){return (1ll<<31)-1;}

int main(){
    int n,q;cin>>n>>q;
    SegmentTree<T,op,e> sg(n);

    while(q--){
        int com,x,y;cin>>com>>x>>y;
        if(com==0){
            sg.set(x-1,y);
        }else{
            cout<<sg.prod(x-1,y)<<endl;
        }
    }
}