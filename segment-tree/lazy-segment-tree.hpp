#include<vector>
#include<functional>
#include<cassert>
template <class T,class K>
struct LazySegmentTree{
    int n;
    std::vector<T> tree;
    std::vector<K> lazy;
    T id_func;
    K id_g;
    std::function<T(T,T)> func;
    std::function<T(T,K,int)> mapping;
    std::function<K(K,K)> composition;
    
    LazySegmentTree(std::function<T(T,T)> f,std::function<T(T,K,int)> mapping,std::function<K(K,K)> composition,T id_f,K id_g,int n,std::vector<T> l={}):func(f),mapping(mapping),composition(composition),id_func(id_f),id_g(id_g){
        //SegmentTree(f,g,id_f,id_g,n,l={})
        //区間取得の関数fと単位元id_f、区間更新の関数mapping,compositionとcompositionの単位元id_gで長さnの遅延セグ木を構築します(nが2のべき乗である必要はない)
        //lを与えると初期化してくれます O(N)
        //mapping(a,b,c)は長さcの区間aにlazyに入っている要素bを作用させるときの関数です
        //composition(a,b)は元からlazyにaがあったときにbと合体させるときの関数
        LazySegmentTree::n=(bits_msb(n))<<1;
        tree.resize(2*LazySegmentTree::n,id_func);
        lazy.resize(LazySegmentTree::n,id_g);
        for(int i=0;i<l.size();i++)tree[LazySegmentTree::n+i]=l[i];
        for(int i=LazySegmentTree::n-1;i>0;i--)tree[i]=func(tree[i<<1],tree[(i<<1)+1]);
    }

    /*T at(int ind){
        //O(1)でランダムアクセス
        return tree[n+ind];
    }*/

    void eval(int ind,int l,int r){
        int tmp=ind;
        std::vector<int> inds;
        tmp>>=1;
        while(tmp!=0){inds.push_back(tmp);tmp>>=1;}
        for(int i=inds.size()-1;i>=0;i--){
            if(lazy[inds[i]]!=id_g){
                if(n>(inds[i]<<1)){
                    lazy[inds[i]<<1]=composition(lazy[inds[i]<<1],lazy[inds[i]]);
                    lazy[(inds[i]<<1)+1]=composition(lazy[(inds[i]<<1)+1],lazy[inds[i]]);
                }
                tree[inds[i]<<1]=mapping(tree[inds[i]<<1],lazy[inds[i]],(n/bits_msb(inds[i]))/2);
                tree[(inds[i]<<1)+1]=mapping(tree[(inds[i]<<1)+1],lazy[inds[i]],(n/bits_msb(inds[i]))/2);
                lazy[inds[i]]=id_g;
            }
        }
    }

    void update(int l, int r,K x,int ind=1,int nl=0,int nr=-1){
        //O(log N)でt[l,r)をそれぞれmapping(t[i],x,1)にする
        if(nr==-1)nr=n;
        
        if(nr<=l || r<=nl)return;

        if(l<=nl && nr<=r){
            eval(ind,l,r);
            tree[ind]=mapping(tree[ind],x,nr-nl);
            if(n>ind)lazy[ind]=composition(lazy[ind],x);
            ind>>=1;
            while(ind!=0){tree[ind]=func(tree[ind<<1],tree[(ind<<1)+1]);ind>>=1;}
        }else{
            update(l,r,x,ind<<1,nl,nl+(nr-nl)/2);
            update(l,r,x,(ind<<1)+1,nr-(nr-nl)/2,nr);
        }
        return;
    }

    T query(int l, int r,int ind=1,int nl=0,int nr=-1){
        //O(log N)でt[l:r)のクエリ
        if(nr==-1)nr=n;

        if(nr<=l || r<=nl)return id_func;

        if(l<=nl && nr<=r){
            eval(ind,nl,nr);
            return tree[ind];
        }else{
            return func(query(l,r,ind<<1,nl,nl+(nr-nl)/2),query(l,r,(ind<<1)+1,nr-(nr-nl)/2,nr));
        }
    }

private:
    unsigned int bits_msb( unsigned int v ){
    v = v | (v >>  1);
    v = v | (v >>  2);
    v = v | (v >>  4);
    v = v | (v >>  8);
    v = v | (v >> 16);
    return v ^ (v >> 1);
    }
};