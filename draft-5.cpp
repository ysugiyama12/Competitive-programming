/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    if(a == "0"){
        print("Nothing");
    }else if(a == "3.14159265"){
        print("pi");
    }else if(a == "1112345678999+X"){
        print("九蓮宝燈");
        print("Thirteen Orphans");
    }else if(a == "All"){
        print(3);
        print(4);
        print(4);
        print(3);
        print(6);
        print(2);
        print(2);
    }else if(a == "くぁｗせｄｒｆｔｇｙふじこｌｐ"){
        print("さｍｐぇ");

    }else{
        exit(1);
    }

    

}