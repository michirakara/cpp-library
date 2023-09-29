---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\n#include<vector>\ntemplate<class T>\n\
    struct Matrix{\n    std::vector<std::vector<T>> internal_matrix;\n    \n    Matrix(int\
    \ H,int W,T x=0):internal_matrix(H,std::vector<T>(W,x)){}\n\n    int height()\
    \ const {\n        return (int)internal_matrix.size();\n    }\n\n    int width()\
    \ const {\n        return (int)internal_matrix[0].size();\n    }\n\n    inline\
    \ const std::vector<T> &operator[](int idx)const{\n        return internal_matrix.at(idx);\n\
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
    \    }\n};\n#line 3 \"math/gauss-jordan.hpp\"\n#include<cassert>\n#include<utility>\n\
    template<class T>\nstruct GaussJordan{\n    Matrix<T> mat;\n\n    GaussJordan(Matrix<T>\
    \ system):mat(system){\n        assert(mat.height()==mat.width()-1);\n    }\n\
    \    std::vector<T> solve(){\n        for(int i=0;i<mat.width()-1;i++){\n    \
    \        for(int j=i;j<mat.height();j++){\n                if(mat[j][i]!=0){\n\
    \                    std::swap(mat[j],mat[i]);\n                    T to_div=mat[i][i];\n\
    \                    for(int k=0;k<mat.width();k++){\n                       \
    \ mat[i][k]/=to_div;\n                    }\n                    for(int k=0;k<mat.height();k++){\n\
    \                        if(i==k)continue;\n                        T mul_by=-mat[k][i];\n\
    \                        for(int l=0;l<mat.width();l++){\n                   \
    \         mat[k][l]+=mul_by*mat[i][l];\n                        }\n          \
    \          }\n                    break;\n                }\n            }\n \
    \       }\n        std::vector<T> ret(mat.height());\n        for(int i=0;i<mat.height();i++){\n\
    \            ret[i]=mat[i][mat.width()-1];\n        }\n        return ret;\n \
    \   }\n};\n"
  code: "#include \"math/matrix.hpp\"\n#include<vector>\n#include<cassert>\n#include<utility>\n\
    template<class T>\nstruct GaussJordan{\n    Matrix<T> mat;\n\n    GaussJordan(Matrix<T>\
    \ system):mat(system){\n        assert(mat.height()==mat.width()-1);\n    }\n\
    \    std::vector<T> solve(){\n        for(int i=0;i<mat.width()-1;i++){\n    \
    \        for(int j=i;j<mat.height();j++){\n                if(mat[j][i]!=0){\n\
    \                    std::swap(mat[j],mat[i]);\n                    T to_div=mat[i][i];\n\
    \                    for(int k=0;k<mat.width();k++){\n                       \
    \ mat[i][k]/=to_div;\n                    }\n                    for(int k=0;k<mat.height();k++){\n\
    \                        if(i==k)continue;\n                        T mul_by=-mat[k][i];\n\
    \                        for(int l=0;l<mat.width();l++){\n                   \
    \         mat[k][l]+=mul_by*mat[i][l];\n                        }\n          \
    \          }\n                    break;\n                }\n            }\n \
    \       }\n        std::vector<T> ret(mat.height());\n        for(int i=0;i<mat.height();i++){\n\
    \            ret[i]=mat[i][mat.width()-1];\n        }\n        return ret;\n \
    \   }\n};"
  dependsOn:
  - math/matrix.hpp
  isVerificationFile: false
  path: math/gauss-jordan.hpp
  requiredBy: []
  timestamp: '2023-09-29 10:24:52-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gauss-jordan.hpp
layout: document
redirect_from:
- /library/math/gauss-jordan.hpp
- /library/math/gauss-jordan.hpp.html
title: math/gauss-jordan.hpp
---
