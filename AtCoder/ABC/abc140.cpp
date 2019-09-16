/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> v;
    ll cnt = 1;
    rep(i,0,N-1){
        if(S[i] != S[i+1]){
            v.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    v.push_back(cnt);
    // printa(v, v.size());
    ll m = v.size();
    vector<ll> v2;
    cnt = 1;
    string T = S.substr(0,1);
    rep(i,0,N-1){
        if(S[i] != S[i+1]){
            v2.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
        if(v2.size() % 2 == 1){
            if((v2.size() + 1) / 2 <= K){
                if(S[i+1] == 'L'){
                    T += 'R';
                }else{
                    T += 'L';
                }
            }else{
                T += S[i+1];
            }
        }else{
            T += S[i+1];
        }
    }
    ll ans = 0;
    rep(i,0,N){
        if(T[i] == 'L'){
            if(i != 0 && T[i-1] == 'L') ans++;
        }else{
            if(i != N-1 && T[i+1] == 'R') ans++;
        }
    }
    print(ans);


    
}