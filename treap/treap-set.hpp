//参考 https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
//Treap<TYPE> hoge;で初期化
template<class T>
class Treap{
    struct Node{
        T val;
        int priority;
        int cnt=1;
        long long acc;
        Node *l, *r;
        Node(T val,int priority):val(val),priority(priority),acc(val),l(nullptr),r(nullptr){};
    }
    *root=nullptr;
    using Tree=Node *;

    int cnt(Tree t) {
        return t ? t->cnt : 0;
    }

    long long acc(Tree t){
        return t ? t->acc : 0;
    }

    void update(Tree t){
        if(t){
            t->cnt=1+cnt(t->l)+cnt(t->r);
            t->acc=t->val+acc(t->l)+acc(t->r);
        }
    }

    void split(Tree t, T val, Tree& l,Tree& r){
        if(!t){
            l=r=nullptr;
        }else if(val<t->val){
            split(t->l,val,l,t->l),r=t;
        }else{
            split(t->r,val,t->r,r),l=t;
        }
        update(t);
    }

    void merge(Tree& t, Tree l, Tree r){
        if(!l || !r){
            t=l?l:r;
        }else if(l->priority>r->priority){
            merge(l->r,l->r,r),t=l;
        }else{
            merge(r->l,l,r->l),t=r;
        }
        update(t);
    }

    void insert(Tree& t,Tree item){
        if(!t){
            t=item;
        }else if(item->priority>t->priority){
            split(t,item->val,item->l,item->r),t=item;
            update(t);
        }else{
            insert(item->val<t->val?t->l:t->r,item);
            update(t);
        }
    }

    void erase(Tree& t,T val){
        if(t->val==val){
            merge(t,t->l,t->r);
            update(t);
        }else{
            erase(val<t->val?t->l:t->r,val);
            update(t);
        }
    }

    bool find(Tree& t, T val){
        if(!t){
            return false;
        }else if(t->val==val){
            return true;
        }else{
            return find(val<t->val?t->l:t->r,val);
        }
    }

    int index(Tree& t, T val, int ni){
        if(!t){
            return -1;
        }else if(t->val==val){
            return ni;
        }else if(val<t->val){
            return index(t->l,val,ni-1-cnt(t->l->r));
        }else{
            return index(t->r,val,ni+1+cnt(t->r->l));
        }
    }

    T at(Tree& t, int ind, int ni){
        if(!t)return -1;
        if(ni==ind){
            return t->val;
        }else if(ind<ni){
            return at(t->l,ind,ni-1-cnt(t->l->r));
        }else{
            return at(t->r,ind,ni+1+cnt(t->r->l));
        }
    }

    long long query(Tree& t, int l, int r,int ni, int nl,int nr){
        if(!t)return 0;
        if(nr<=l || r<=nl)return 0;
        if(l<=nl && nr<=r){
            return t->acc;
        }else{
            long long ret=(l<=ni && ni<r)?t->val:0;
            if(t->l){
                ret+=query(t->l,l,r,ni-1-cnt(t->l->r),nl,nl+cnt(t->l));
            }
            if(t->r){
                ret+=query(t->r,l,r,ni+1+cnt(t->r->l),nr-cnt(t->r),nr);
            }
            return ret;
        }
    }

public:
    void insert(T val){
        //valを追加する O(log N)
        insert(root,new Node(val,rand()));
    }

    void erase(T val){
        //valを消す O(log N)
        erase(root,val);
    }

    bool find(T val){
        //valが存在するか調べる O(log N)
        return find(root,val);
    }

    int index(T val){
        //valのindexを調べる 存在しない場合は-1を返す O(log N)
        return index(root,val,cnt(root->l));
    }

    T operator[](int ind){
        //indexでランダムアクセス O(log N)
        return at(root,ind,cnt(root->l));
    }

    long long query(int l, int r){
        //[l,r)の区間和 O(log N)
        return query(root,l,r,cnt(root->l),0,root->cnt);
    }
};