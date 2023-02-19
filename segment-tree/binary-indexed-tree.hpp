#include<vector>
struct BinaryIndexedTree{
    // 0-indexed
    int size;
    std::vector<long long> tree={0};

    BinaryIndexedTree(int n,std::vector<long long> l={}):size(n){
        if(l.empty()){
            for(int i=0;i<size;i++)tree.push_back(0);
        }else{
            for(long long i:l){
                tree.push_back(i);
            }
            std::vector<long long> c(n+1,0);
            for(int i=0;i<size;i++){
                c[i+1]=l[i]+c[i];
            }
            for(int x=1;x<=size;x++){
                tree[x]=c[x]-c[x-(x&-x)];
            }
        }
    }

    long long _sum(int r){
        //sum(t[0,r))
        if(r==0)return 0;
        long long s=0;
        while(r>0){
            s+=tree[r];
            r-=r&-r;
        }
        return s;
    }

    long long sum(int l,int r){
        //sum(t[l,r))
        return _sum(r)-_sum(l);
    }

    void add(int i,long long x){
        //t[i]+=x
        i++;
        while(i<=size){
            tree[i]+=x;
            i+=i&-i;
        }
    }
};