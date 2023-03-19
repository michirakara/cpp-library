---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
  bundledCode: "#line 1 \"treap/treap-multiset.hpp\"\n//\u53C2\u8003 https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n\
    //Treap<TYPE> hoge;\u3067\u521D\u671F\u5316\ntemplate<class T>\nclass Treap{\n\
    \    struct Node{\n        T val;\n        int priority;\n        int cnt=1;\n\
    \        long long acc;\n        Node *l, *r;\n        Node(T val,int priority):val(val),priority(priority),acc(val),l(nullptr),r(nullptr){};\n\
    \    }\n    *root=nullptr;\n    using Tree=Node *;\n\n    int cnt(Tree t) {\n\
    \        return t ? t->cnt : 0;\n    }\n\n    long long acc(Tree t){\n       \
    \ return t ? t->acc : 0;\n    }\n\n    void update(Tree t){\n        if(t){\n\
    \            t->cnt=1+cnt(t->l)+cnt(t->r);\n            t->acc=t->val+acc(t->l)+acc(t->r);\n\
    \        }\n    }\n\n    void split(Tree t, T val, Tree& l,Tree& r){\n       \
    \ if(!t){\n            l=r=nullptr;\n        }else if(val<t->val){\n         \
    \   split(t->l,val,l,t->l),r=t;\n        }else{\n            split(t->r,val,t->r,r),l=t;\n\
    \        }\n        update(t);\n    }\n\n    void merge(Tree& t, Tree l, Tree\
    \ r){\n        if(!l || !r){\n            t=l?l:r;\n        }else if(l->priority>r->priority){\n\
    \            merge(l->r,l->r,r),t=l;\n        }else{\n            merge(r->l,l,r->l),t=r;\n\
    \        }\n        update(t);\n    }\n\n    void insert(Tree& t,Tree item){\n\
    \        if(!t){\n            t=item;\n        }else if(item->priority>t->priority){\n\
    \            split(t,item->val,item->l,item->r),t=item;\n            update(t);\n\
    \        }else{\n            insert(item->val<t->val?t->l:t->r,item);\n      \
    \      update(t);\n        }\n    }\n\n    void erase(Tree& t,T val){\n      \
    \  if(t->val==val){\n            merge(t,t->l,t->r);\n            update(t);\n\
    \        }else{\n            erase(val<t->val?t->l:t->r,val);\n            update(t);\n\
    \        }\n    }\n\n    bool find(Tree& t, T val){\n        if(!t){\n       \
    \     return false;\n        }else if(t->val==val){\n            return true;\n\
    \        }else{\n            return find(val<t->val?t->l:t->r,val);\n        }\n\
    \    }\n\n    int ind_l(Tree& t, T val, int ni){\n        if(t->l && t->l->val==val){\n\
    \            return ind_l(t->l,val,ni-1-cnt(t->l->r));\n        }else{\n     \
    \       return ni;\n        }\n    }\n    \n    int ind_r(Tree& t, T val, int\
    \ ni){\n        if(t->r && t->r->val==val){\n            return ind_r(t->r,val,ni+1+cnt(t->r->l));\n\
    \        }else{\n            return ni;\n        }\n    }\n\n    int index(Tree&\
    \ t, T val, int ni){\n        if(!t){\n            return -1;\n        }else if(t->val==val){\n\
    \            return ind_l(t,val,ni);\n        }else if(val<t->val){\n        \
    \    return index(t->l,val,ni-1-cnt(t->l->r));\n        }else{\n            return\
    \ index(t->r,val,ni+1+cnt(t->r->l));\n        }\n    }\n\n    int rindex(Tree&\
    \ t, T val, int ni){\n        if(!t){\n            return -1;\n        }else if(t->val==val){\n\
    \            return ind_r(t,val,ni);\n        }else if(val<t->val){\n        \
    \    return index(t->l,val,ni-1-cnt(t->l->r));\n        }else{\n            return\
    \ index(t->r,val,ni+1+cnt(t->r->l));\n        }\n    }\n\n    T at(Tree& t, int\
    \ ind, int ni){\n        if(!t)return -1;\n        if(ni==ind){\n            return\
    \ t->val;\n        }else if(ind<ni){\n            return at(t->l,ind,ni-1-cnt(t->l->r));\n\
    \        }else{\n            return at(t->r,ind,ni+1+cnt(t->r->l));\n        }\n\
    \    }\n\n    long long query(Tree& t, int l, int r,int ni, int nl,int nr){\n\
    \        if(!t)return 0;\n        if(nr<=l || r<=nl)return 0;\n        if(l<=nl\
    \ && nr<=r){\n            return t->acc;\n        }else{\n            long long\
    \ ret=(l<=ni && ni<r)?t->val:0;\n            if(t->l){\n                ret+=query(t->l,l,r,ni-1-cnt(t->l->r),nl,nl+cnt(t->l));\n\
    \            }\n            if(t->r){\n                ret+=query(t->r,l,r,ni+1+cnt(t->r->l),nr-cnt(t->r),nr);\n\
    \            }\n            return ret;\n        }\n    }\n\npublic:\n    void\
    \ insert(T val){\n        //val\u3092\u8FFD\u52A0\u3059\u308B O(log N)\n     \
    \   insert(root,new Node(val,rand()));\n    }\n\n    void erase(T val){\n    \
    \    //val\u3092\u6D88\u3059 O(log N)\n        erase(root,val);\n    }\n\n   \
    \ bool find(T val){\n        //val\u304C\u5B58\u5728\u3059\u308B\u304B\u8ABF\u3079\
    \u308B O(log N)\n        return find(root,val);\n    }\n\n    int index(T val){\n\
    \        //val\u306E\u6700\u3082\u5C0F\u3055\u3044index\u3092\u8ABF\u3079\u308B\
    \ \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F-1\u3092\u8FD4\u3059 O(log N)\n\
    \        return index(root,val,cnt(root->l));\n    }\n\n    int rindex(T val){\n\
    \        //val\u306E\u6700\u3082\u5927\u304D\u3044index\u3092\u8ABF\u3079\u308B\
    \ \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F-1\u3092\u8FD4\u3059 O(log N)\n\
    \        return rindex(root,val,cnt(root->l));\n    }\n\n    int count(T val){\n\
    \        //val\u306E\u6570\u3092\u8FD4\u3059 O(log N)\n        return rindex(val)-index(val)+1;\n\
    \    }\n\n    T operator[](int ind){\n        //index\u3067\u30E9\u30F3\u30C0\u30E0\
    \u30A2\u30AF\u30BB\u30B9 O(log N)\n        return at(root,ind,cnt(root->l));\n\
    \    }\n\n    long long query(int l, int r){\n        //[l,r)\u306E\u533A\u9593\
    \u548C O(log N)\n        return query(root,l,r,cnt(root->l),0,root->cnt);\n  \
    \  }\n};\n"
  code: "//\u53C2\u8003 https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n\
    //Treap<TYPE> hoge;\u3067\u521D\u671F\u5316\ntemplate<class T>\nclass Treap{\n\
    \    struct Node{\n        T val;\n        int priority;\n        int cnt=1;\n\
    \        long long acc;\n        Node *l, *r;\n        Node(T val,int priority):val(val),priority(priority),acc(val),l(nullptr),r(nullptr){};\n\
    \    }\n    *root=nullptr;\n    using Tree=Node *;\n\n    int cnt(Tree t) {\n\
    \        return t ? t->cnt : 0;\n    }\n\n    long long acc(Tree t){\n       \
    \ return t ? t->acc : 0;\n    }\n\n    void update(Tree t){\n        if(t){\n\
    \            t->cnt=1+cnt(t->l)+cnt(t->r);\n            t->acc=t->val+acc(t->l)+acc(t->r);\n\
    \        }\n    }\n\n    void split(Tree t, T val, Tree& l,Tree& r){\n       \
    \ if(!t){\n            l=r=nullptr;\n        }else if(val<t->val){\n         \
    \   split(t->l,val,l,t->l),r=t;\n        }else{\n            split(t->r,val,t->r,r),l=t;\n\
    \        }\n        update(t);\n    }\n\n    void merge(Tree& t, Tree l, Tree\
    \ r){\n        if(!l || !r){\n            t=l?l:r;\n        }else if(l->priority>r->priority){\n\
    \            merge(l->r,l->r,r),t=l;\n        }else{\n            merge(r->l,l,r->l),t=r;\n\
    \        }\n        update(t);\n    }\n\n    void insert(Tree& t,Tree item){\n\
    \        if(!t){\n            t=item;\n        }else if(item->priority>t->priority){\n\
    \            split(t,item->val,item->l,item->r),t=item;\n            update(t);\n\
    \        }else{\n            insert(item->val<t->val?t->l:t->r,item);\n      \
    \      update(t);\n        }\n    }\n\n    void erase(Tree& t,T val){\n      \
    \  if(t->val==val){\n            merge(t,t->l,t->r);\n            update(t);\n\
    \        }else{\n            erase(val<t->val?t->l:t->r,val);\n            update(t);\n\
    \        }\n    }\n\n    bool find(Tree& t, T val){\n        if(!t){\n       \
    \     return false;\n        }else if(t->val==val){\n            return true;\n\
    \        }else{\n            return find(val<t->val?t->l:t->r,val);\n        }\n\
    \    }\n\n    int ind_l(Tree& t, T val, int ni){\n        if(t->l && t->l->val==val){\n\
    \            return ind_l(t->l,val,ni-1-cnt(t->l->r));\n        }else{\n     \
    \       return ni;\n        }\n    }\n    \n    int ind_r(Tree& t, T val, int\
    \ ni){\n        if(t->r && t->r->val==val){\n            return ind_r(t->r,val,ni+1+cnt(t->r->l));\n\
    \        }else{\n            return ni;\n        }\n    }\n\n    int index(Tree&\
    \ t, T val, int ni){\n        if(!t){\n            return -1;\n        }else if(t->val==val){\n\
    \            return ind_l(t,val,ni);\n        }else if(val<t->val){\n        \
    \    return index(t->l,val,ni-1-cnt(t->l->r));\n        }else{\n            return\
    \ index(t->r,val,ni+1+cnt(t->r->l));\n        }\n    }\n\n    int rindex(Tree&\
    \ t, T val, int ni){\n        if(!t){\n            return -1;\n        }else if(t->val==val){\n\
    \            return ind_r(t,val,ni);\n        }else if(val<t->val){\n        \
    \    return index(t->l,val,ni-1-cnt(t->l->r));\n        }else{\n            return\
    \ index(t->r,val,ni+1+cnt(t->r->l));\n        }\n    }\n\n    T at(Tree& t, int\
    \ ind, int ni){\n        if(!t)return -1;\n        if(ni==ind){\n            return\
    \ t->val;\n        }else if(ind<ni){\n            return at(t->l,ind,ni-1-cnt(t->l->r));\n\
    \        }else{\n            return at(t->r,ind,ni+1+cnt(t->r->l));\n        }\n\
    \    }\n\n    long long query(Tree& t, int l, int r,int ni, int nl,int nr){\n\
    \        if(!t)return 0;\n        if(nr<=l || r<=nl)return 0;\n        if(l<=nl\
    \ && nr<=r){\n            return t->acc;\n        }else{\n            long long\
    \ ret=(l<=ni && ni<r)?t->val:0;\n            if(t->l){\n                ret+=query(t->l,l,r,ni-1-cnt(t->l->r),nl,nl+cnt(t->l));\n\
    \            }\n            if(t->r){\n                ret+=query(t->r,l,r,ni+1+cnt(t->r->l),nr-cnt(t->r),nr);\n\
    \            }\n            return ret;\n        }\n    }\n\npublic:\n    void\
    \ insert(T val){\n        //val\u3092\u8FFD\u52A0\u3059\u308B O(log N)\n     \
    \   insert(root,new Node(val,rand()));\n    }\n\n    void erase(T val){\n    \
    \    //val\u3092\u6D88\u3059 O(log N)\n        erase(root,val);\n    }\n\n   \
    \ bool find(T val){\n        //val\u304C\u5B58\u5728\u3059\u308B\u304B\u8ABF\u3079\
    \u308B O(log N)\n        return find(root,val);\n    }\n\n    int index(T val){\n\
    \        //val\u306E\u6700\u3082\u5C0F\u3055\u3044index\u3092\u8ABF\u3079\u308B\
    \ \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F-1\u3092\u8FD4\u3059 O(log N)\n\
    \        return index(root,val,cnt(root->l));\n    }\n\n    int rindex(T val){\n\
    \        //val\u306E\u6700\u3082\u5927\u304D\u3044index\u3092\u8ABF\u3079\u308B\
    \ \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F-1\u3092\u8FD4\u3059 O(log N)\n\
    \        return rindex(root,val,cnt(root->l));\n    }\n\n    int count(T val){\n\
    \        //val\u306E\u6570\u3092\u8FD4\u3059 O(log N)\n        return rindex(val)-index(val)+1;\n\
    \    }\n\n    T operator[](int ind){\n        //index\u3067\u30E9\u30F3\u30C0\u30E0\
    \u30A2\u30AF\u30BB\u30B9 O(log N)\n        return at(root,ind,cnt(root->l));\n\
    \    }\n\n    long long query(int l, int r){\n        //[l,r)\u306E\u533A\u9593\
    \u548C O(log N)\n        return query(root,l,r,cnt(root->l),0,root->cnt);\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: treap/treap-multiset.hpp
  requiredBy: []
  timestamp: '2023-02-24 09:21:27-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: treap/treap-multiset.hpp
layout: document
redirect_from:
- /library/treap/treap-multiset.hpp
- /library/treap/treap-multiset.hpp.html
title: treap/treap-multiset.hpp
---