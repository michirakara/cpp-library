#include<vector>
#include<functional>
template <class T>
struct SegmentTree{
    int n;
    std::vector<T> tree;
    T id_el;
    std::function<T(T,T)> func;
    
    SegmentTree(std::function<T(T,T)> f,T id_el,int n,std::vector<T> l={}):func(f),id_el(id_el){
        //SegmentTree(f,id_el,n,l={})
        //モノイドの関数fと単位元id_el、で長さnのセグ木を構築します(nが2のべき乗である必要はない)
        //lを与えると初期化してくれます O(N)
        SegmentTree::n=(bits_msb(n))<<1;
        for(int i=0;i<2*SegmentTree::n;i++)tree.push_back(id_el);
        for(int i=0;i<l.size();i++)tree[SegmentTree::n+i]=l[i];
        for(int i=SegmentTree::n-1;i>0;i--)tree[i]=func(tree[i<<1],tree[(i<<1)+1]);
    }

    T at(int ind){
        //O(1)でランダムアクセス
        return tree[n+ind];
    }

    void update(int ind,T x){
        //O(log N)でt[ind]をxにする
        ind+=n;
        tree[ind]=x;
        while(ind>1){
            tree[ind>>1]=func(tree[ind],tree[ind^1]);
            ind>>=1;
        }
    }

    T query(int l, int r){
        //O(log N)でt[l:r)のクエリ
        T ret=id_el;
        l+=n;
        r+=n;
        while(l<r){
            if(l&1){
                ret=func(ret,tree[l]);l++;
            }
            if(r&1){
                ret=func(ret,tree[r-1]);
            }
            r>>=1;
            l>>=1;
        }
        return ret;
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