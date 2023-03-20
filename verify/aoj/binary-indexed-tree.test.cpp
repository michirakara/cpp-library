#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>
using namespace std;

#include "../../segment-tree/binary-indexed-tree.hpp"

int main(){
    int N,Q;cin>>N>>Q;
    BinaryIndexedTree bit(N);

    while(Q--){
        int com,x,y;cin>>com>>x>>y;

        if(com==0)bit.add(x,y);
        else cout<<bit.sum(x,y+1)<<endl;
    }
}