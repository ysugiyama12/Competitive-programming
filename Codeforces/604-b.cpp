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
    ll n0,n1,n2,n3;
    cin >> n0 >> n1 >> n2 >> n3;
    vector<ll> odd;
    vector<ll> even;
    rep(i,0,n0) even.push_back(0);
    rep(i,0,n2) even.push_back(2);
    rep(i,0,n1) odd.push_back(1);
    rep(i,0,n3) odd.push_back(3);
    if(abs(n0+n2 - n1-n3) > 1){
        print("NO");
    }else{
        ll sum = n0+n1+n2+n3;
        bool ok = true;
        vector<ll> v;
        if(n0+n2 > n1+n3){
            rep(i,0,n1+n3){
                v.push_back(even[i]);
                v.push_back(odd[i]);
            }
            v.push_back(even[n1+n3]);
            rep(i,0,sum-1){
                if(abs(v[i] - v[i+1]) != 1) ok = false;
            }
            if(ok){
                print("YES");
                printa(v, sum);
            }else{
                print("NO");
            }
        }else if(n0+n2 < n1+n3){
            rep(i,0,n0+n2){
                v.push_back(odd[i]);
                v.push_back(even[i]);
            }
            v.push_back(odd[n0+n2]);
            rep(i,0,sum-1){
                if(abs(v[i] - v[i+1]) != 1) ok = false;
            }
            if(ok){
                print("YES");
                printa(v, sum);
            }else{
                print("NO");
            }   
        }else{
            rep(i,0,n0+n2){
                v.push_back(odd[i]);
                v.push_back(even[i]);
            }
            rep(i,0,sum-1){
                if(abs(v[i] - v[i+1]) != 1) ok = false;
            }
            if(ok){
                print("YES");
                printa(v, sum);
                return 0;
            }
            ok = true;
            v.clear();
            rep(i,0,n0+n2){
                v.push_back(even[i]);
                v.push_back(odd[i]);
            }
            rep(i,0,sum-1){
                if(abs(v[i] - v[i+1]) != 1) ok = false;
            }
            if(ok){
                print("YES");
                printa(v, sum);
                return 0;
            }else{
                print("NO");
            }
        }
    }



    

}