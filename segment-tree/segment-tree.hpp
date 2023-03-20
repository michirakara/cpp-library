#include<vector>
#include<functional>
template <class T,T(*op)(T,T),T(*e)()>
struct SegmentTree{
    int n;
    std::vector<T> tree;
    
    SegmentTree(int n,std::vector<T> l={}){
        //SegmentTree<T,op,e>(n,l={})
        SegmentTree::n=(bits_msb(n))<<1;
        tree.resize(SegmentTree::n*2,e());
        for(int i=0;i<(int)l.size();i++)tree[SegmentTree::n+i]=l[i];
        for(int i=SegmentTree::n-1;i>0;i--)tree[i]=op(tree[i<<1],tree[(i<<1)+1]);
    }

    T at(int ind){
        //O(1)でランダムアクセス
        return tree.at(n+ind);
    }

    T operator[](int pos){
        return tree[n+pos];
    }

    void set(int ind,T x){
        //O(log N)でt[ind]をxにする
        ind+=n;
        tree[ind]=x;
        while(ind>1){
            tree[ind>>1]=op(tree[ind],tree[ind^1]);
            ind>>=1;
        }
    }

    T prod(int l, int r){
        //O(log N)でt[l:r)のクエリ
        T ret=e();
        l+=n;
        r+=n;
        while(l<r){
            if(l&1){
                ret=op(ret,tree[l]);l++;
            }
            if(r&1){
                ret=op(ret,tree[r-1]);
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