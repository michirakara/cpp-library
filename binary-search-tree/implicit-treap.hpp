//参考 https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
//Treap<T,op,e,F,mapping,composition,id> hoge;で初期化
template<class T,T(*op)(T,T),T(*e)(),class F,T(*mapping)(F f,T x),F(*composition)(F f,F g),F(*id)()>
class ImplicitTreap{
    struct Node{
        T val;
        int priority;
        int cnt=1;
        T acc;
        F lazy=id();
        bool rev=false;
        Node *l, *r;
        Node(T val,int priority):val(val),priority(priority),acc(val),l(nullptr),r(nullptr){};
    }
    *root=nullptr;
    using Tree=Node *;

    int cnt(Tree t) {
        return t ? t->cnt : 0;
    }

    T acc(Tree t){
        return t ? t->acc : e();
    }

    void update(Tree t){
        if(t){
            t->cnt=1+cnt(t->l)+cnt(t->r);
            t->acc=op(t->val,op(acc(t->l),acc(t->r)));
        }
    }

    void pushdown(Tree t){
        if(t && t->rev){
            t->rev=false;
            swap(t->l,t->r);
            if(t->l)t->l->rev^=1;
            if(t->r)t->r->rev^=1;
        }
        if(t && t->lazy!=id()){
            if(t->l){
                t->l->lazy=composition(t->l->lazy,t->lazy);
                t->l->acc=mapping(t->lazy,t->l->acc);
            }
            if(t->r){
                t->r->lazy=composition(t->r->lazy,t->lazy);
                t->r->acc=mapping(t->lazy,t->r->acc);
            }
            t->val=mapping(t->lazy,t->val);
            t->lazy=0;
        }
        update(t);
    }

    void split(Tree t, T key, Tree& l,Tree& r){
        if(!t){
            l=r=nullptr;
            return;
        }
        pushdown(t);
        int implicit_key=cnt(t->l)+1;
        if(key<implicit_key){
            split(t->l,key,l,t->l),r=t;
        }else{
            split(t->r,key-implicit_key,t->r,r),l=t;
        }
        update(t);
    }

    void merge(Tree& t, Tree l, Tree r){
        pushdown(l);
        pushdown(r);
        if(!l || !r){
            t=l?l:r;
        }else if(l->priority>r->priority){
            merge(l->r,l->r,r),t=l;
        }else{
            merge(r->l,l,r->l),t=r;
        }
        update(t);
    }

    void insert(Tree& t,int key,Tree item){
        Tree t1,t2;
        split(t,key,t1,t2);
        merge(t1,t1,item);
        merge(t,t1,t2);
    }

    void erase(Tree& t,int key){
        Tree t1,t2,t3;
        split(t,key+1,t1,t2);
        split(t1,key,t1,t3);
        merge(t,t1,t2);
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

    T prod(Tree t,int l,int r){
        Tree t1,t2,t3;
        split(t,l,t1,t2);
        split(t2,r-l,t2,t3);
        T ret=t2->acc;
        merge(t2,t2,t3);
        merge(t,t1,t2);
        return ret;
    }

    void apply(Tree t,int l,int r,F x){
        Tree t1,t2,t3;
        split(t,l,t1,t2);
        split(t2,r-l,t2,t3);
        t2->lazy=composition(t2->lazy,x);
        t2->acc=mapping(x,t2->acc);
        merge(t2,t2,t3);
        merge(t,t1,t2);
    }

    void reverse(Tree t,int l,int r){
        if(l>r)return;
        Tree t1,t2,t3;
        split(t,l,t1,t2);
        split(t2,r-l,t2,t3);
        t2->rev^=1;
        merge(t2,t2,t3);
        merge(t,t1,t2);
    }

    void rotate(Tree t,int l,int m,int r){
        reverse(t,l,r);
        reverse(t,l,l+r-m);
        reverse(t,l+r-m,r);
    }

public:
    void insert(int pos,T val){
        //valをposの場所に追加する O(log N)
        insert(root,pos,new Node(val,rand()));
    }

    void erase(T pos){
        //posにある要素を消す O(log N)
        erase(root,pos);
    }

    int size(){
        return cnt(root);
    }

    T operator[](int ind){
        //indexでランダムアクセス O(log N)
        return prod(root,ind,ind+1);
    }

    T prod(int l, int r){
        //[l,r)の区間 O(log N)
        return prod(root,l,r);
    }

    void apply(int l,int r,F x){
        apply(root,l,r,x);
    }

    void reverse(int l,int r){
        reverse(root,l,r);
    }

    void rotate(int l,int m,int r){
        rotate(root,l,m,r);
    }
};