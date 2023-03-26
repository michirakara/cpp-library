#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include <bits/stdc++.h>
using namespace std;

#include "../../set/treap-multiset.hpp"

int main(){
    int n,q;
    cin>>n>>q;

    vector<int> s(n);
    for(int i=0;i<n;i++)cin>>s[i];

    Treap<> t;
    for(int i=0;i<n;i++)t.insert(s[i]);
    
    for(int i=0;i<q;i++){
        int qi;cin>>qi;
        if(qi==0){
            int x;
            cin>>x;
            t.insert(x);
        }else if(qi==1){
            cout<<t[0]<<endl;
            t.erase(t[0]);
        }else{
            cout<<t[t.size()-1]<<endl;
            t.erase(t[t.size()-1]);
        }
    }
}
