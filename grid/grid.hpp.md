---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"grid/grid.hpp\"\n#include<vector>\n#include<utility>\n#include<cmath>\n\
    \nstruct Grid{\n    int h,w;\n    std::vector<std::vector<char>> grid;\n\n   \
    \ Grid(std::vector<std::vector<char>> gr){\n        h=gr.size();\n        w=gr[0].size();\n\
    \        grid=gr; \n    }\n    Grid(int h,int w){\n        Grid::h=h;\n      \
    \  Grid::w=w;\n        grid=std::vector<std::vector<char>>(h,std::vector<char>(w,'.'));\n\
    \    }\n\n    void set(int h_idx,int w_idx,char c){\n        grid[h_idx][w_idx]=c;\n\
    \    }\n\n    bool is_empty(int h_idx,int w_idx){\n        if(0<=h_idx && h_idx<h\
    \ && 0<=w_idx && w_idx<w && grid[h_idx][w_idx]=='.'){\n            return true;\n\
    \        }\n        return false;\n    }\n\n    bool is_in_grid(int h_idx,int\
    \ w_idx){\n        if(0<=h_idx && h_idx<h && 0<=w_idx && w_idx<w){\n         \
    \   return true;\n        }\n        return false;\n    }\n\n    std::pair<int,int>\
    \ retidx(int h_idx,int w_idx,int dx,int dy){\n        return {h_idx+dx,w_idx+dy};\n\
    \    }\n    std::pair<int,int> retidx(int h_idx,int w_idx,char dir){\n       \
    \ if(dir=='R')return retidx(h_idx,w_idx,0,1);\n        if(dir=='L')return retidx(h_idx,w_idx,0,-1);\n\
    \        if(dir=='U')return retidx(h_idx,w_idx,-1,0);\n        if(dir=='D')return\
    \ retidx(h_idx,w_idx,1,0);\n    }\n\n    std::vector<std::pair<int,int>> next_4(int\
    \ h_idx,int w_idx){\n        std::vector<std::pair<int,int>> ret;\n        for(int\
    \ dx=-1;dx<=1;dx++){\n            for(int dy=-1;dy<=1;dy++){\n               \
    \ if(std::abs(dx)+std::abs(dy)!=1)continue;\n                std::pair<int,int>\
    \ tmp=retidx(h_idx,w_idx,dx,dy);\n                if(is_in_grid(tmp.first,tmp.second))ret.push_back(tmp);\n\
    \            }\n        }\n        return ret;\n    }\n    std::vector<std::pair<int,int>>\
    \ next_8(int h_idx,int w_idx){\n        std::vector<std::pair<int,int>> ret;\n\
    \        for(int dx=-1;dx<=1;dx++){\n            for(int dy=-1;dy<=1;dy++){\n\
    \                std::pair<int,int> tmp=retidx(h_idx,w_idx,dx,dy);\n         \
    \       if(is_in_grid(tmp.first,tmp.second))ret.push_back(tmp);\n            }\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#include<vector>\n#include<utility>\n#include<cmath>\n\nstruct Grid{\n  \
    \  int h,w;\n    std::vector<std::vector<char>> grid;\n\n    Grid(std::vector<std::vector<char>>\
    \ gr){\n        h=gr.size();\n        w=gr[0].size();\n        grid=gr; \n   \
    \ }\n    Grid(int h,int w){\n        Grid::h=h;\n        Grid::w=w;\n        grid=std::vector<std::vector<char>>(h,std::vector<char>(w,'.'));\n\
    \    }\n\n    void set(int h_idx,int w_idx,char c){\n        grid[h_idx][w_idx]=c;\n\
    \    }\n\n    bool is_empty(int h_idx,int w_idx){\n        if(0<=h_idx && h_idx<h\
    \ && 0<=w_idx && w_idx<w && grid[h_idx][w_idx]=='.'){\n            return true;\n\
    \        }\n        return false;\n    }\n\n    bool is_in_grid(int h_idx,int\
    \ w_idx){\n        if(0<=h_idx && h_idx<h && 0<=w_idx && w_idx<w){\n         \
    \   return true;\n        }\n        return false;\n    }\n\n    std::pair<int,int>\
    \ retidx(int h_idx,int w_idx,int dx,int dy){\n        return {h_idx+dx,w_idx+dy};\n\
    \    }\n    std::pair<int,int> retidx(int h_idx,int w_idx,char dir){\n       \
    \ if(dir=='R')return retidx(h_idx,w_idx,0,1);\n        if(dir=='L')return retidx(h_idx,w_idx,0,-1);\n\
    \        if(dir=='U')return retidx(h_idx,w_idx,-1,0);\n        if(dir=='D')return\
    \ retidx(h_idx,w_idx,1,0);\n    }\n\n    std::vector<std::pair<int,int>> next_4(int\
    \ h_idx,int w_idx){\n        std::vector<std::pair<int,int>> ret;\n        for(int\
    \ dx=-1;dx<=1;dx++){\n            for(int dy=-1;dy<=1;dy++){\n               \
    \ if(std::abs(dx)+std::abs(dy)!=1)continue;\n                std::pair<int,int>\
    \ tmp=retidx(h_idx,w_idx,dx,dy);\n                if(is_in_grid(tmp.first,tmp.second))ret.push_back(tmp);\n\
    \            }\n        }\n        return ret;\n    }\n    std::vector<std::pair<int,int>>\
    \ next_8(int h_idx,int w_idx){\n        std::vector<std::pair<int,int>> ret;\n\
    \        for(int dx=-1;dx<=1;dx++){\n            for(int dy=-1;dy<=1;dy++){\n\
    \                std::pair<int,int> tmp=retidx(h_idx,w_idx,dx,dy);\n         \
    \       if(is_in_grid(tmp.first,tmp.second))ret.push_back(tmp);\n            }\n\
    \        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: grid/grid.hpp
  requiredBy: []
  timestamp: '2024-02-23 19:44:07-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: grid/grid.hpp
layout: document
title: Grid
---

# 概要
グリッドの便利な関数を詰め込みました

# 例
- 初期化  
    - __Grid(int h,int w)__  
    h*wの`.`で初期化されたグリッドを作る
    - __Grid(vector<vector<char>> gr)__  
    grで初期化されたグリッドを作る
- __void set(int h,int w,char c)__  
    `grid[h][w]`を$c$にする  
    cが`#`と`.`以外のときの挙動は未定義です
- __bool is_empty(int h_idx, int w_idx)__  
    `grid[h_idx][w_idx]`が存在するかつ`.`ならtrueを返す
- __bool is_in_grid(int h_idx, int w_idx)__  
    `grid[h_idx][w_idx]`が存在するならtrueを返す
- __retidx__
    - __pair<int,int> retidx(int h_idx,int w_idx,int dx,int dy)__
    - __pair<int,int> retidx(int h_idx,int w_idx,char dir)__  
    大体想像通りのものを返します
- __vector<pair<int,int>> next_4(int h_idx,int w_idx)__  
    4方向でグリッド内のマス目を返します  
    グリッドの中身が何かは判定しないので`is_empty`を使ったりして判定してください
- __vector<pair<int,int>> next_8(int h_idx,int w_idx)__  
    ↑の8方向版です
