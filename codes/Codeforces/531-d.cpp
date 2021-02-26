#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S;
    cin >> N >> S;
    ll c0 = 0, c1 = 0, c2 = 0;
    rep(i,0,N){
        if(S[i] == '0') c0++;
        if(S[i] == '1') c1++;
        if(S[i] == '2') c2++;
    }
    ll v = N / 3;
    char ans[300010];
    rep(i,0,N){
        ans[i] = S[i];
    }
    if(c0 > v && c1 <= v && c2 <= v){
        ll d1 = v-c1;
        ll d2 = v-c2;
        ll idx = 0;
        rrep(i,N-1,0){
            if(S[i] == '0'){
                if(idx < d2){
                    ans[i] = '2';
                }else if(idx < d1+d2){
                    ans[i] = '1';
                }
                idx++;
            }
        }
    }else if(c1 > v && c0 <= v && c2 <= v){
        ll d0 = v-c0;
        ll d2 = v-c2;
        ll idx = 0;
        rep(i,0,N){
            if(S[i] == '1'){
                if(idx < d0) ans[i] = '0';
                idx++;
            }
        }
        idx = 0;
        rrep(i,N-1,0){
            if(S[i] == '1'){
                if(idx < d2) ans[i] = '2';
                idx++;
            }
        }
    }else if(c2 > v && c0 <= v && c1 <= v){
        ll d0 = v-c0;
        ll d1 = v-c1;
        ll idx = 0;
        rep(i,0,N){
            if(S[i] == '2'){
                if(idx < d0){
                    ans[i] = '0';
                }else if(idx < d0 + d1){
                    ans[i] = '1';
                }
                idx++;
            }

        }
    }else if(c0 > v && c1 > v && c2 <= v){
        ll d0 = c0-v;
        ll d1 = c1-v;
        ll idx0 = 0;
        ll idx1 = 0;
        rrep(i,N-1,0){
            if(S[i] == '0'){
                if(idx0 < d0){
                    ans[i] = '2';
                    idx0++;
                }
            }else if(S[i] == '1'){
                if(idx1 < d1){
                    ans[i] = '2';
                    idx1++;
                }
            }
        }
    }else if(c0 <= v && c1 > v && c2 > v){
        ll d1 = c1-v;
        ll d2 = c2-v;
        ll idx1 = 0, idx2 = 0;
        rep(i,0,N){
            if(S[i] == '1'){
                if(idx1 < d1) ans[i] = '0';
                idx1++;
            }else if(S[i] == '2'){
                if(idx2 < d2) ans[i] = '0';
                idx2++; 
            }
        }
    }else if(c0 > v && c1 <= v && c2 > v){
        ll d0 = c0-v;
        ll d2 = c2-v;
        ll idx0 = 0, idx2 = 0;
        rep(i,0,N){
            if(S[i] == '2'){
                if(idx2 < d2) ans[i] = '1';
                idx2++;
            }
        }
        rrep(i,N-1,0){
            if(S[i] == '0'){
                if(idx0 < d0) ans[i] = '1';
                idx0++;
            }
        }
    }
    rep(i,0,N){
        cout << ans[i];
    }
    cout << endl;
}
