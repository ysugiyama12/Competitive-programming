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
    ll N,M,K;
    cin >> N >> M >> K;
    if(N == 1 && M == 1){
        print("NO");
        return 0;
    }
    if(K > 4*N*M - 2*N - 2*M){
        print("NO");
        return 0;
    }
    print("YES");
    vector< pair<ll, string> > ans;
    if(N == 1){
        ans.push_back({M-1, "R"});
        ans.push_back({M-1, "L"});      

    }else if(M == 1){
        ans.push_back({N-1, "D"});
        ans.push_back({N-1, "U"});    

    }else{
        ans.push_back({M-1, "R"});
        ans.push_back({M-1, "L"});
        ans.push_back({N-1, "D"});
        ans.push_back({M-1, "R"});
        ans.push_back({N-1, "U"});
        rep(i,0,N-2){
            ans.push_back({M-2, "DLU"});
            ans.push_back({1, "DL"});
            if(i == N-3){
                ans.push_back({M-2, "RDU"});
                ans.push_back({1, "RD"});
            }else{
                ans.push_back({M-1, "R"});
            }
        }
        if(N == 2) ans.push_back({1, "D"});
        ans.push_back({M-1, "L"});
        ans.push_back({N-1, "U"});
    }
    vector< pair<ll, string> > ans2;
    for(auto &e: ans){
        if(e.first != 0) ans2.push_back(e);
    }
    vector< pair<ll, string> > ans3;
    ll sum = 0;
    for(auto &e: ans2){
        // ans3.push_back(e);
        ll val = e.first, len = e.second.size();
        if(sum + val * len >= K){
            ll amari = K - sum;
            ll shou = amari / len;
            ll amari2 = amari % len;
            if(shou != 0) ans3.push_back({shou, e.second});
            if(amari2 != 0) ans3.push_back({1, e.second.substr(0,amari2)});

            break;

        }else{
            ans3.push_back(e);
            sum += val * len;
        }
    }
    print(ans3.size());
    for(auto &e: ans3){
        print(e.first, e.second);
    }

    

}