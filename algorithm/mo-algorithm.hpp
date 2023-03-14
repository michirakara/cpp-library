#include<vector>
#include<utility>
#include<numeric>
#include<algorithm>
struct Mo{
    int n;
    std::vector<std::pair<int,int>> lr;
    explicit Mo(int n):n(n){}

    void add(int l,int r){/*[l,r)*/
        lr.emplace_back(l,r);
    }

    template<typename AL,typename AR,typename EL,typename ER,typename O>
    void build(const AL &add_left,const AR &add_right,const EL &erase_left,const ER &erase_right,const O &out){
        int q=lr.size();
        int width=n/min<int>(n,sqrt(q));
        std::vector<int> order(q);
        std::iota(order.begin(),order.end(),0);
        std::sort(order.begin(),order.end(),[&](int a,int b){
            int a_block=lr[a].first/width,b_block=lr[b].first/width;
            if(a_block!=b_block)return a_block<b_block;
            return a_block%2==0 ? lr[a].second<lr[b].second : lr[a].second>lr[b].second;
        });

        int l=0,r=0;
        for(auto i:order){
            while(l>lr[i].first)add_left(--l);
            while(r<lr[i].second)add_right(r++);
            while(l<lr[i].first)erase_left(l++);
            while(r>lr[i].second)erase_right(--r);
            out(i);
        }
    }
    template<typename A,typename E,typename O>
    void build(const A &add,const E & erase,const O &out){
        build(add,add,erase,erase,out);
    }
};