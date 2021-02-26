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
bool dp[2010][2010] = {};
// i個目までみてk回変えた時
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    string S[2010];
    rep(i,0,N) cin >> S[i];
    bitset<7> bit_s[2010];
    rep(i,0,N) bit_s[i] = bitset<7>(S[i]);
    dp[N][0] = true;
    bitset<7> bit_n[11];

    string num[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    rep(i,0,10){
        bit_n[i] = bitset<7>(num[i]);
    }

    rrep(i,N-1,0){
        rep(k,0,K+1){
            rep(n,0,10){ // nができるか
                if(((~bit_n[n]) & bit_s[i]) != 0){
                    continue;
                }
                bitset<7> bs = (bit_n[n] & (~bit_s[i]));
                ll cnt = bs.count();
                if(k - cnt >= 0){
                    dp[i][k] |= dp[i+1][k-cnt];
                }
            }
        }
    }
    if(dp[0][K] == false){
        print(-1);
        return 0;
    }
    string ans = "";
    ll cur = K;
    rep(i,0,N){
        rrep(n,9,0){
            if(((~bit_n[n]) & bit_s[i]) != 0) continue;
            bitset<7> bs = (bit_n[n] & (~bit_s[i]));
            ll cnt = bs.count();
            if(cur-cnt < 0) continue;
            if(dp[i][cur] == true && dp[i+1][cur-cnt] == true){
                cur -= cnt;
                ans += to_string(n);
                break;
            }
        }
    }
    print(ans);



    

}