#include "../graph/graph-template.hpp"

#include <stack>
#include <algorithm>
struct SCC{
    std::vector<int> where;

    std::vector<UnweightedGraph> build(UnweightedGraph &G){
        UnweightedGraph rev_graph((int)G.size());
        std::vector<int> order;

        {std::vector<bool> been((int)G.size(),false);
        std::stack<int> st;
        st.push(0);
        while(!st.empty()){
            int now=st.top();st.pop();
            if(now>=0){
                been[now]=true;
                for(int i:G[now]){
                    rev_graph[i].push_back(now);
                    if(been[i])continue;
                    st.push(-i-1);
                    st.push(i);
                }
            }else{
                now=-now-1;
                order.push_back(now);
            }
        }}
        std::reverse(order.begin(),order.end());
        std::vector<UnweightedGraph> ret;
        std::vector<int> index((int)G.size(),-1);
        std::vector<int> been_2((int)G.size(),-1);
        for(int start:order){
            if(been_2[start]!=-1)continue;
            std::stack<int> st={};
            st.push(start);
            index[start]=0;
            ret.push_back({{}});
            while(!st.empty()){
                int now=st.top();st.pop();
                been_2[now]=start;
                for(int i:rev_graph[now]){
                    if(been_2[i]!=start && been_2[i]!=-1)continue;
                    if(index[i]==-1){
                        index[i]=(int)ret.back().size();
                        ret.back().push_back({});
                    }
                    ret.back()[index[i]].push_back(now);
                    if(been_2[i]==-1)st.push(i);
                }
            }
        }
        where=been_2;
        return ret;
    }

    int operator[](int v){
        return where[v];
    }
};