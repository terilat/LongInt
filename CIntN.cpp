#include <iostream>
#include "CIntN.h"
#include <string>
#include <cstring>
#define MX(a, b) (a > b ? a : b)
#define MN(a, b) (a > b ? b : a)

CIntN::CIntN(){
    N = 2;
    num = new char[N + 1];
    for(int i = 0; i <= N; i++) num[i] = 0;
}
CIntN::CIntN(int n){
    N = n;
    num = new char[N + 1];
    for(int i = 0; i <= N; i++) num[i] = 0;
}
CIntN::CIntN(int n, int a) {
    N = n;
    num = new char[N + 1];
    if (a == 0){
        for(int i = 0; i <= N; i++) num[i] = 0;
    }
    for(int i = 0; i < N && a != 0; i++){
        num[i] = a % 10; a /= 10;
    }
}
CIntN::CIntN(const CIntN &tmp){
    N = tmp.N;
    delete(num);
    num = new char[N + 1];
    memcpy(num, tmp.num, N + 1);
}
CIntN::~CIntN() {
    delete(num);
    num = nullptr;
    N = 0;
}
CIntN CIntN::operator+(const CIntN &tmp){
    CIntN res(MX(N, tmp.N));
    int i;
    for(i = 0; i < MN(N, tmp.N); i++){
        res.num[i] = num[i] + tmp.num[i] + res.num[i];
        if (res.num[i] > 9) { res.num[i + 1] += 1; res.num[i] -= 10; }
    }
    //i -= 1;
    if (N > tmp.N){
        for(; i < N; i++){
            res.num[i] = num[i] + res.num[i];
            if (res.num[i] > 9) { res.num[i + 1] += 1; res.num[i] -= 10; }
        }
    } else{
        for(; i < tmp.N; i++){
            res.num[i] = tmp.num[i] + res.num[i];
            if (res.num[i] > 9) { res.num[i + 1] += 1; res.num[i] -= 10; }
        }
    }
    res.num[MX(N, tmp.N)] = 0;
    return res;
}
CIntN CIntN::operator-(const CIntN &tmp){
    CIntN res(MX(N, tmp.N));
    int i;
    for(i = 0; i < MN(N, tmp.N); i++){
        res.num[i] = num[i] - tmp.num[i] + res.num[i];
        if (res.num[i] < 0){ res.num[i + 1] -= 1; res.num[i] += 10; }
        //std::cout << *this << " " << tmp << " " << res << std::endl;
    }
    if (N > tmp.N){
        for(; i < N; i++){
            res.num[i] = num[i] + res.num[i];
            if (res.num[i] < 0){ res.num[i + 1] -= 1; res.num[i] += 10; }
        }
    } else {
        for(; i < tmp.N; i++){
            res.num[i] = -tmp.num[i] + res.num[i];
            if (res.num[i] < 0){ res.num[i + 1] -= 1; res.num[i] += 10; }
        }
    }
    res.num[MX(N, tmp.N)] = 0;
    //std::cout << this << " " << tmp << " " << res << std::endl;
    return res;
}
CIntN& CIntN::operator=(const CIntN &tmp){
    if (*this == tmp) return *this;
    N = tmp.N;
    delete(num);
    num = new char[N + 1];
    for(int i = 0; i < N; i++) num[i] = tmp.num[i];
    return *this;
}
std::ostream& operator<<(std::ostream &out, const CIntN &tmp){
    bool q = true;
    for(int i = tmp.N - 1; i > -1; i--) {
        if (tmp.num[i] == 0 && q) q = true;
        else { std::cout << (int)tmp.num[i]; q = false; }
        //std::cout << (int)tmp.num[i] << " " << i << std::endl;
    }
    if (q) std::cout << 0;
    //std::cout << "Number is showen\n";
    //std::cout << std::endl;
    return out;
}
std::istream& operator>>(std::istream &in, CIntN &tmp){
    std::string str;
    in >> str;
    for(int i = 0; i < tmp.N; i++) tmp.num[i] = (char)(((int)str.length() - 1 < i) ? 0 : (str[str.length() - 1 - i] - 48));
    return in;
}
bool operator==(const CIntN &a, const CIntN &b){
    int i;
    for(i = 0; i < MN(a.N, b.N); i++){
        if (a.num[i] != b.num[i]) return false;
    }
    if (a.N > b.N) {
        for(; i < a.N; i++) if (a.num[i] != 0) return false;
    } else {
        for(; i < b.N; i++) if (b.num[i] != 0) return false;
    }
    return true;
}

int CIntN::GetN(){
    return N;
}
