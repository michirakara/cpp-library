//参考 https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
#include<iostream>
#include<utility>
#include<vector>

//Treap<TYPE> hoge;で初期化
template<class T>
class Treap{
    struct Node{
        T val;
        int priority;
        Node *l, *r;
        Node(T val,int priority):val(val),priority(priority),l(nullptr),r(nullptr){};
    }
    *root=nullptr;
    using Tree=Node *;

    void split(Tree t, T val, Tree& l,Tree& r){
        if(!t){
            l=r=nullptr;
        }else if(val<t->val){
            split(t->l,val,l,t->l),r=t;
        }else{
            split(t->r,val,t->r,r),l=t;
        }
    }

    void merge(Tree& t, Tree l, Tree r){
        if(!l || !r){
            t=l?l:r;
        }else if(l->priority>r->priority){
            merge(l->r,l->r,r),t=l;
        }else{
            merge(r->l,l,r->l),t=r;
        }
    }

    void insert(Tree& t,Tree item){
        if(!t){
            t=item;
        }else if(item->priority>t->priority){
            split(t,item->val,item->l,item->r),t=item;
        }else{
            insert(item->val<t->val?t->l:t->r,item);
        }
    }

    void erase(Tree& t,T val){
        if(t->val==val){
            merge(t,t->l,t->r);
        }else{
            erase(val<t->val?t->l:t->r,val);
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
};