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
  bundledCode: "#line 1 \"math/gauss-jordan.hpp\"\n#include<vector>\n#include<cassert>\n\
    #include<utility>\n#include<math/matrix.hpp>\ntemplate<class T>\nstruct GaussJordan{\n\
    \    Matrix<T> mat;\n\n    GaussJordan(Matrix<T> system):mat(system){\n      \
    \  assert(mat.height()==mat.width()-1);\n    }\n    std::vector<T> solve(){\n\
    \        for(int i=0;i<mat.width()-1;i++){\n            for(int j=i;j<mat.height();j++){\n\
    \                if(mat[j][i]!=0){\n                    std::swap(mat[j],mat[i]);\n\
    \                    T to_div=mat[i][i];\n                    for(int k=0;k<mat.width();k++){\n\
    \                        mat[i][k]/=to_div;\n                    }\n         \
    \           for(int k=0;k<mat.height();k++){\n                        if(i==k)continue;\n\
    \                        T mul_by=-mat[k][i];\n                        for(int\
    \ l=0;l<mat.width();l++){\n                            mat[k][l]+=mul_by*mat[i][l];\n\
    \                        }\n                    }\n                    break;\n\
    \                }\n            }\n        }\n        std::vector<T> ret(mat.height());\n\
    \        for(int i=0;i<mat.height();i++){\n            ret[i]=mat[i][mat.width()-1];\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#include<vector>\n#include<cassert>\n#include<utility>\n#include<math/matrix.hpp>\n\
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
  timestamp: '2023-09-29 10:21:17-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gauss-jordan.hpp
layout: document
redirect_from:
- /library/math/gauss-jordan.hpp
- /library/math/gauss-jordan.hpp.html
title: math/gauss-jordan.hpp
---
