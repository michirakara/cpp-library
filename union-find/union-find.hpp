#include<iostream>
#include<vector>
#include<unordered_map>
struct UnionFind{
    int n;
    std::vector<int> par;
    int group_cnt;
    
    //要素数NのUnionFindを作成
    UnionFind(int n):par(n,-1),group_cnt(n),n(n){}

    //xの親を探す
    int find(int x){
        if(par.at(x)<0){
            return x;
        }else{
            par.at(x)=find(par.at(x));
            return par.at(x);
        }
    }

    //xとyを連結
    void unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return;
        if(par.at(x)>par.at(y))std::swap(x,y);
        par.at(x)+=par.at(y);
        par.at(y)=x;
        group_cnt--;
        return;
    }

    int size(int x){
        return -par.at(find(x));
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }

    std::vector<int> members(int x){
        int root=find(x);
        std::vector<int> ret;
        for(int i=0;i<n;i++){
            if(find(i)==root)ret.push_back(i);
        }
        return ret;
    }

    std::vector<int> roots(){
        std::vector<int> ret;
        for(int i=0;i<n;i++){
            if(par.at(i)<0)ret.push_back(i);
        }
        return ret;
    }

    int grp_cnt(){
        return group_cnt;
    }

    std::unordered_map<int,std::vector<int>> grp_mem(){
        std::unordered_map<int,std::vector<int>> ret;
        for(int i=0;i<n;i++){
            ret[find(i)].push_back(i);
        }
        return ret;
    }
};
