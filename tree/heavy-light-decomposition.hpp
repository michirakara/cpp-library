#include "../graph/graph-template.hpp"

#include<vector>
#include<utility>
#include<algorithm>
#include<functional>

template<class S>
struct HeavyLightDecomposition{
    UnweightedGraph T;
    int N;
    std::vector<int> parent,siz_t,depth,shallow,hld,rev_hld;
    int dfs(int now,int prev){
        parent[now]=prev;
        depth[now]=prev!=-1?depth[prev]+1:0;
        int siz=1;
        for(int i:T[now]){
            if(i==prev)continue;
            siz+=dfs(i,now);
        }
        siz_t[now]=siz;
        return siz;
    }
    void dfs2(int now,int prev,bool new_path){
        rev_hld[now]=hld.size();
        hld.push_back(now);
        shallow[now]=new_path?now:shallow[prev];

        int ma=0,ma_idx=-1;
        for(int i:T[now]){
            if(i!=prev && siz_t[i]>ma){
                ma=siz_t[i],ma_idx=i;
            }
        }
        if(ma_idx==-1)return;
        dfs2(ma_idx,now,false);

        for(int i:T[now]){
            if(i!=ma_idx && i!=prev)dfs2(i,now,true);
        }
    }
    HeavyLightDecomposition(UnweightedGraph &T):T(T){
        N=HeavyLightDecomposition::T.size();
        parent.resize(N);
        siz_t.resize(N);
        depth.resize(N);
        shallow.resize(N);
        rev_hld.resize(N);
        dfs(0,-1);
        dfs2(0,-1,1);
    }

    std::vector<std::pair<int,int>> q(int u,int v){
        std::vector<std::pair<int,int>> ret;
        while(shallow[u]!=shallow[v]){
            if(depth[shallow[u]]<=depth[shallow[v]]){
                ret.push_back({rev_hld[shallow[v]],rev_hld[v]});
                v=parent[shallow[v]];
            }else{
                ret.push_back({rev_hld[shallow[u]],rev_hld[u]});
                u=parent[shallow[u]];
            }
        }
        ret.push_back({std::min(rev_hld[u],rev_hld[v]),std::max(rev_hld[u],rev_hld[v])});
        return ret;
    }

    void set(int u,int v,S x,std::function<void(int,int)> f){
        if(parent[v]==u){
            f(rev_hld[v],x);
        }else{
            f(rev_hld[u],x);
        }
    }

    S query(int u,int v,S id,std::function<S(int,int)> f,std::function<S(S,S)> op){
        std::vector<std::pair<int,int>> que=q(u,v);
        S ret=id;
        for(int i=0;i<que.size()-1;i++){
            ret=op(ret,f(que[i].first,que[i].second+1));
        }
        if(que.back().first!=N-1 && que.back().first!=que.back().second){
            ret=op(ret,f(que.back().first+1,que.back().second+1));
        }
        return ret;
    }

    int lcu(int u,int v){
        return hld[q(u,v).back().first];
    }
};