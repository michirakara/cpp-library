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
  bundledCode: "#line 1 \"math/modint.hpp\"\n#include<iostream>\n#include<utility>\n\
    \ntemplate <int mod>\nstruct modint{\n    long long internal_val;\n    modint():internal_val(0){}\n\
    \    modint(long long val):internal_val(val>=0 ? val%mod : (mod-(-val)%mod)%mod){}\n\
    \n    modint& operator++(){\n        internal_val++;\n        if(internal_val==mod)internal_val=0;\n\
    \        return *this;\n    }\n    modint& operator--(){\n        if(internal_val==0)internal_val=mod;\n\
    \        internal_val--;\n        return *this;\n    }\n    modint operator++(int){\n\
    \        modint ret=*this;\n        ++*this;\n        return ret;\n    }\n   \
    \ modint operator--(int){\n        modint ret=*this;\n        --*this;\n     \
    \   return ret;\n    }\n    modint& operator+=(const modint &other){\n       \
    \ if((internal_val+=other.internal_val)>=mod)internal_val-=mod;\n        return\
    \ *this;\n    }\n    modint& operator-=(const modint &other){\n        if((internal_val+=mod-other.internal_val)>=mod)internal_val-=mod;\n\
    \        return *this;\n    }\n    modint& operator*=(const modint &other){\n\
    \        internal_val=internal_val*other.internal_val%mod;\n        return *this;\n\
    \    }\n    modint& operator/=(const modint &other){\n        *this*=other.inv();\n\
    \        return *this;\n    }\n\n    modint operator-() const {return modint(-internal_val);}\n\
    \    modint operator+() const {return modint(internal_val);}\n    modint operator+(const\
    \ modint &other) const {return modint(*this)+=other;}\n    modint operator-(const\
    \ modint &other) const {return modint(*this)-=other;}\n    modint operator*(const\
    \ modint &other) const {return modint(*this)*=other;}\n    modint operator/(const\
    \ modint &other) const {return modint(*this)/=other;}\n    bool operator==(const\
    \ modint &other) const {return internal_val==other.internal_val;}\n    bool operator!=(const\
    \ modint &other) const {return internal_val!=other.internal_val;}\n    \n    modint\
    \ inv()const{\n        int a=internal_val,b=mod,u=1,v=0,t;\n        while(b>0){\n\
    \            t=a/b;\n            std::swap(a-=t*b,b);\n            std::swap(u-=t*v,v);\n\
    \        }\n        return modint(u);\n    }\n\n    modint pow(long long n) const\
    \ {\n        modint ret(1),mul(internal_val);\n        while(n>0){\n         \
    \   if(n&1)ret*=mul;\n            mul*=mul;\n            n>>=1;\n        }\n \
    \       return ret;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const modint &other){\n        return os<<other.internal_val;\n    }\n\
    \    friend std::istream &operator>>(std::istream &is, modint &other){\n     \
    \   long long t;\n        is>>t;\n        other=modint<mod>(t);\n        return\
    \ (is);\n    }\n\n    static int get_mod(){return mod;}\n};\n"
  code: "#include<iostream>\n#include<utility>\n\ntemplate <int mod>\nstruct modint{\n\
    \    long long internal_val;\n    modint():internal_val(0){}\n    modint(long\
    \ long val):internal_val(val>=0 ? val%mod : (mod-(-val)%mod)%mod){}\n\n    modint&\
    \ operator++(){\n        internal_val++;\n        if(internal_val==mod)internal_val=0;\n\
    \        return *this;\n    }\n    modint& operator--(){\n        if(internal_val==0)internal_val=mod;\n\
    \        internal_val--;\n        return *this;\n    }\n    modint operator++(int){\n\
    \        modint ret=*this;\n        ++*this;\n        return ret;\n    }\n   \
    \ modint operator--(int){\n        modint ret=*this;\n        --*this;\n     \
    \   return ret;\n    }\n    modint& operator+=(const modint &other){\n       \
    \ if((internal_val+=other.internal_val)>=mod)internal_val-=mod;\n        return\
    \ *this;\n    }\n    modint& operator-=(const modint &other){\n        if((internal_val+=mod-other.internal_val)>=mod)internal_val-=mod;\n\
    \        return *this;\n    }\n    modint& operator*=(const modint &other){\n\
    \        internal_val=internal_val*other.internal_val%mod;\n        return *this;\n\
    \    }\n    modint& operator/=(const modint &other){\n        *this*=other.inv();\n\
    \        return *this;\n    }\n\n    modint operator-() const {return modint(-internal_val);}\n\
    \    modint operator+() const {return modint(internal_val);}\n    modint operator+(const\
    \ modint &other) const {return modint(*this)+=other;}\n    modint operator-(const\
    \ modint &other) const {return modint(*this)-=other;}\n    modint operator*(const\
    \ modint &other) const {return modint(*this)*=other;}\n    modint operator/(const\
    \ modint &other) const {return modint(*this)/=other;}\n    bool operator==(const\
    \ modint &other) const {return internal_val==other.internal_val;}\n    bool operator!=(const\
    \ modint &other) const {return internal_val!=other.internal_val;}\n    \n    modint\
    \ inv()const{\n        int a=internal_val,b=mod,u=1,v=0,t;\n        while(b>0){\n\
    \            t=a/b;\n            std::swap(a-=t*b,b);\n            std::swap(u-=t*v,v);\n\
    \        }\n        return modint(u);\n    }\n\n    modint pow(long long n) const\
    \ {\n        modint ret(1),mul(internal_val);\n        while(n>0){\n         \
    \   if(n&1)ret*=mul;\n            mul*=mul;\n            n>>=1;\n        }\n \
    \       return ret;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const modint &other){\n        return os<<other.internal_val;\n    }\n\
    \    friend std::istream &operator>>(std::istream &is, modint &other){\n     \
    \   long long t;\n        is>>t;\n        other=modint<mod>(t);\n        return\
    \ (is);\n    }\n\n    static int get_mod(){return mod;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2023-09-23 15:00:32-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
