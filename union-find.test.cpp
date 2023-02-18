#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include<tree/union-find.hpp>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    UnionFind uf(n);
    for(int i=0;i<q;i++){
        int t,u,v;
        cin>>t>>u>>v;
        if(t){
            if(uf.same(u,v)){cout<<1<<endl;}
            else{cout<<0<<endl;}
        }else{
            uf.unite(u,v);
        }
    }
}
