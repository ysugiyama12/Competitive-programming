#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    string S;
    cin >> N >> K;
    cin >> S;
    ll cnt[27] = {};
    ll cnt_def[27] = {};
    rep(i,0,N){
        cnt[S[i]-'a']++;
        cnt_def[S[i]-'a']++;
    }
    char ans[110];
    rep(i,0,N){
        rep(j,0,26){
            if(cnt[j] == 0) continue;
            char c = 'a' + j;
            ll diff1 = 0;
            rep(k,0,i){
                if(ans[k] != S[k]) diff1++;
            }
            if(c != S[i]) diff1++;
            ll cnt1[27] = {};
            rep(k,i+1,N){
                cnt1[S[k]-'a']++;
            }
            ll cnt2[27] = {};
            rep(k,0,26){
                cnt2[k] = cnt_def[k];
            }
            rep(k,0,i){
                cnt2[ans[k]-'a']--;
            }
            cnt2[j]--;
            ll diff2 = 0;
            rep(k,0,26){
                diff2 += min(cnt1[k], cnt2[k]);
            }
            diff2 = (N-i-1) - diff2;
            if(diff2 + diff1 <= K){
                ans[i] = c;
                cout << c;
                cnt[j]--;
                break;
            }
        }
    }
    cout << endl;


}
