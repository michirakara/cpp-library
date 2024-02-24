---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D
  bundledCode: "#line 1 \"verify/aoj/matrix-multiplication.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D\"\n\n#line\
    \ 1 \"math/matrix.hpp\"\n#include<vector>\ntemplate<class T>\nstruct Matrix{\n\
    \    std::vector<std::vector<T>> internal_matrix;\n    \n    Matrix(int H,int\
    \ W,T x=0):internal_matrix(H,std::vector<T>(W,x)){}\n\n    int height() const\
    \ {\n        return (int)internal_matrix.size();\n    }\n\n    int width() const\
    \ {\n        return (int)internal_matrix[0].size();\n    }\n\n    inline const\
    \ std::vector<T> &operator[](int idx)const{\n        return internal_matrix.at(idx);\n\
    \    }\n\n    inline std::vector<T> &operator[](int idx){\n        return internal_matrix.at(idx);\n\
    \    }\n\n    Matrix &operator+=(const Matrix &other){\n        for(int i=0;i<height();i++){\n\
    \            for(int j=0;j<width();j++){\n                (*this)[i][j]+=other[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix &operator-=(const\
    \ Matrix &other){\n        for(int i=0;i<height();i++){\n            for(int j=0;j<width();j++){\n\
    \                (*this)[i][j]-=other[i][j];\n            }\n        }\n     \
    \   return *this;\n    }\n\n    Matrix &operator*=(const Matrix &other){\n   \
    \     int l=height(),m=width(),n=other.width();\n        std::vector<std::vector<T>>\
    \ ret(l,std::vector<T>(n,0));\n        for(int i=0;i<l;i++){\n            for(int\
    \ j=0;j<n;j++){\n                for(int k=0;k<m;k++){\n                    ret[i][j]+=(*this)[i][k]*other[k][j];\n\
    \                }\n            }\n        }\n        internal_matrix.swap(ret);\n\
    \        return *this;\n    }\n\n    Matrix pow(long long p){\n        //\u884C\
    \u5217\u306E\u639B\u3051\u7B97\u306E\u5358\u4F4D\u5143\u306FM[i][i]=1(0<i<N),\u305D\
    \u308C\u4EE5\u5916\u306E\u30DE\u30B9\u304C0\u306E\u884C\u5217\n        Matrix\
    \ ret=Matrix<T>(height(),height(),0);\n        for(int i=0;i<height();i++)ret[i][i]=1;\n\
    \        while(p>0){\n            if(p&1)ret*=*this;\n            *this*=*this;\n\
    \            p>>=1ll;\n        }\n        return ret;\n    }\n\n    Matrix operator+(const\
    \ Matrix &other) const {\n        return (Matrix(*this)+=other);\n    }\n\n  \
    \  Matrix operator-(const Matrix &other) const {\n        return (Matrix(*this)-=other);\n\
    \    }\n\n    Matrix operator*(const Matrix &other) const {\n        return (Matrix(*this)*=other);\n\
    \    }\n};\n#line 4 \"verify/aoj/matrix-multiplication.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\nint main(){\n    int n,m,l;cin>>n>>m>>l;\n    Matrix<long\
    \ long> A(n,m),B(m,l);\n    for(int i=0;i<n;i++){\n        for(int j=0;j<m;j++){\n\
    \            cin>>A[i][j];\n        }\n    }\n    for(int i=0;i<m;i++){\n    \
    \    for(int j=0;j<l;j++){\n            cin>>B[i][j];\n        }\n    }\n    Matrix<long\
    \ long> C=A*B;\n\n    for(int i=0;i<n;i++){\n        for(int j=0;j<l;j++){\n \
    \           cout<<C[i][j]<<\" \\n\"[j==l-1];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D\"\
    \n\n#include \"../../math/matrix.hpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nint main(){\n    int n,m,l;cin>>n>>m>>l;\n    Matrix<long long> A(n,m),B(m,l);\n\
    \    for(int i=0;i<n;i++){\n        for(int j=0;j<m;j++){\n            cin>>A[i][j];\n\
    \        }\n    }\n    for(int i=0;i<m;i++){\n        for(int j=0;j<l;j++){\n\
    \            cin>>B[i][j];\n        }\n    }\n    Matrix<long long> C=A*B;\n\n\
    \    for(int i=0;i<n;i++){\n        for(int j=0;j<l;j++){\n            cout<<C[i][j]<<\"\
    \ \\n\"[j==l-1];\n        }\n    }\n}"
  dependsOn:
  - math/matrix.hpp
  isVerificationFile: true
  path: verify/aoj/matrix-multiplication.test.cpp
  requiredBy: []
  timestamp: '2023-09-24 11:37:30-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/matrix-multiplication.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/matrix-multiplication.test.cpp
- /verify/verify/aoj/matrix-multiplication.test.cpp.html
title: verify/aoj/matrix-multiplication.test.cpp
---