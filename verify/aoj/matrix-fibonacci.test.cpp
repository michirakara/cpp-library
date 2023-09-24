#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A"

#include "../../math/matrix.hpp"

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    Matrix<long long> to_power(2,2,0),beg(2,1);
    to_power[0][0]=1,to_power[0][1]=1,to_power[1][0]=1;
    beg[0][0]=1,beg[1][0]=0;
    cout<<(to_power.pow(n)*beg)[0][0]<<endl;
}