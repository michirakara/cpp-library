#include<iostream>
#include<vector>
using ull=unsigned long long;
struct RollingHash{
    ull MOD=(1ull<<61)-1,MASK31=(1ull<<31)-1,MASK30=(1ull<<30)-1;
    ull base;
    std::vector<ull> li={0},p={1};

    ull _mod(ull x){
        ull xu=x>>61,xd=x&MOD;
        ull res=xu+xd;
        if(res>=MOD)res-=MOD;
        return res;
    }

    ull _mul(ull a,ull b){
        ull au=a>>31,ad=a&MASK31,bu=b>>31,bd=b&MASK31;
        ull mid=ad*bu+au*bd;
        ull midu=mid>>30;
        ull midd=mid&MASK30;
        return _mod(au*bu*2+midu+(midd<<31)+ad*bd);
    }

    RollingHash(std::string s,int base){
        RollingHash::base=base;
        for(int i=1;i<=s.size();i++){
            p.push_back(_mul(p[i-1],base));
            li.push_back((_mul(li[i-1],base)+s[i-1])%MOD);
        }
    }

    ull hash(int l,int r){
        //[l,r)
        return (MOD+li[r]-_mul(li[l],p[r-l]))%MOD;
    }
};