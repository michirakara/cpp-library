#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/dijkstra.hpp"

int main(){
    int V,E,r;
    cin>>V>>E>>r;
    WeightedGraph<int> g=input_wgraph<int>(V,E,true,false);
    vector<int> ans=dijkstra<int>(g,r);

    for(int i=0;i<V;i++){
        if(ans[i]==-1){
            cout<<"INF"<<endl;
        }else{
            cout<<ans[i]<<endl;
        }
    }
}