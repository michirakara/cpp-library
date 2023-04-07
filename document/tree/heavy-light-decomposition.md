---
title: HL分解
documentation_of: ../../tree/heavy-light-decomposition.hpp
---

# 概要
木構造を$\log N$本以下のパスに分解して、列に対するクエリの量を$α$とすると$O(α\log N)$で頂点から頂点までの辺に対するクエリが実行できます。  
# 例
- __HeavyLightDecomposition\<class S\>(UnweightedGraph T)__ := HLDの初期化をする $O(N)$
- __void set(int u,int v,S x,function<void(int,S)>)__ := $u$と$v$を繋ぐ辺の値を変更する。三個目の引数はデータ構造の$i$番目を$x$にする関数 $O(α)$
- __int lcu(int u,int v)__ := $u$と$v$のlcuを返す。$O(\log N)$
- __S query(int u,int v,S id,function<S(int,int)>,function<S(S,S)>)__ := $u$と$v$の間の辺に対するクエリを行う。query(u,v,単位元,データ構造のprod,二項演算) $O(α\log N)$