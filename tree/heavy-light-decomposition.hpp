#include "../graph/graph-template.hpp"
#include "../segment-tree/segment-tree.hpp"

#include<vector>
#include<utility>
#include<algorithm>

template<class S,S(*op)(S,S),S(*e)()>
struct HeavyLightDecomposition{
    UnweightedGraph T;
    SegmentTree<S,op,e> sg;
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
    HeavyLightDecomposition(UnweightedGraph &T):T(T),sg(SegmentTree<S,op,e>(T.size())){
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

    void set(int u,int v,S x){
        if(parent[v]==u){
            sg.set(rev_hld[v],x);
        }else{
            sg.set(rev_hld[u],x);
        }
    }

    S query(int u,int v){
        std::vector<std::pair<int,int>> que=q(u,v);
        S ret=e();
        for(int i=0;i<que.size()-1;i++){
            ret=op(ret,sg.prod(que[i].first,que[i].second+1));
        }
        if(que.back().first!=N-1 && que.back().first!=que.back().second){
            ret=op(ret,sg.prod(que.back().first+1,que.back().second+1));
        }
        return ret;
    }

    int lcu(int u,int v){
        return hld[q(u,v).back().first];
    }
};