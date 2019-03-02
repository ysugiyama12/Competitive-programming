#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
map<string, ll> mp_k, mp_other;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll A[100010];
    rep(i,0,K){
        cin >> A[i];
        A[i]--;
    }
    string S[100010];
    rep(i,0,N) cin >> S[i];
    ll r = A[0];
    map<ll,ll> idx;
    rep(i,1,K) idx[A[i]]++;
    ll M = INF;
    rep(i,0,N){
        if(idx[i] == 1){
            ll v1 = 0;
            ll nn = min(S[r].size(), S[i].size());
            rep(j,0,S[i].size()){
                if(S[i][j] == S[r][j]){
                    v1++;
                }else{
                    break;
                }
            }
            M = min(M, v1);
        }
    }
    ll m = -1;
    rep(i,0,N){
        if(i == r) continue;
        if(idx[i] == 0){
            ll v1 = 0;
            ll nn = min(S[r].size(), S[i].size());
            rep(j,0,S[i].size()){
                if(S[i][j] == S[r][j]){
                    v1++;
                }else{
                    break;
                }
            }
            m = max(m, v1);
        }
    }
    if(m < M){
        if(N == K){
            print("");
        }else{
            print(S[r].substr(0, m+1));
        }
    }else{
        print(-1);
    }
    // rep(i,0,N) S[i] = string(50000, 'a');
    // vector<char> s2[100010];
    // rep(i,0,N){
    //     rep(j,0,S[i].size()){
    //         s2[i].push_back(S[i][j]);
    //     }
    // }
    // print("a");
    // map<ll,ll> idx;
    // rep(i,0,K) idx[A[i]-1] = 1;
    // string ss = "";

    // rep(i,0,N){
    //     if(idx[i] == 1){
    //         ss = S[i];
    //         break;
    //     }
    // }
    // // print("a");
    // rep(i,0,N){
    //     ll sz = S[i].size();
    //     if(idx[i] == 1){
    //         string st = "";
    //         rep(j,0,sz){
    //             st += s2[i][j];
    //             print(st);
    //             mp_k[st]++;
    //         }
    //     }else{
    //         string st = "";
    //         rep(j,0,sz){
    //             st += s2[i][j];
    //             mp_other[st]++;
    //         }
    //     }
    // }
    // if(N == K){
    //     print("");
    //     return 0;
    // }
    // string ans = "";
    // ll sz2 = ss.size();
    // rep(i,0,sz2){
    //     if(mp_k[ans + ss[i]] != K) break;
    //     ans += ss[i];
    //     if(mp_other[ans] == 0) break;
    // }
    // if(ans == ""){
    //     print(-1);
    // }else{
    //     if(mp_other[ans] == 0){
    //         print(ans);
    //     }else{
    //         print(-1);
    //     }
    // }

}
