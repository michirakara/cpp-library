#include<iostream>
#include<vector>

struct RollingHash{

    long long MOD=(long long)1<<61-1;
    int base;
    std::vector<long long> li={0},p={1};

    RollingHash(std::string s,int base){
        RollingHash::base=base;
        for(int i=1;i<=s.size();i++){
            p.push_back(((__int128)p[i-1]*base)%MOD);
            li.push_back((((__int128)li[i-1]*base)%MOD+((int)s[i-1]-96))%MOD);
        }
    }

    long long hash(int l,int r){
        //[l,r)
        return ((__int128)li[r]-(__int128)li[l]*p[r-l])%MOD;
    }
};