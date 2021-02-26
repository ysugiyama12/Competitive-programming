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
    string S;
    ll k;
    cin >> S;
    cin >> k;
    ll n = S.size();
    ll candy_cnt = 0, snow_cnt = 0, char_cnt = 0;
    rep(i,0,n){
        if(S[i] == '?'){
            candy_cnt++;
        }else if(S[i] == '*'){
            snow_cnt++;
        }else{
            char_cnt++;
        }
    }
    ll diff = char_cnt - k;
    if(diff == 0){
        rep(i,0,n){
            if(S[i] != '?' && S[i] != '*'){
                cout << S[i];
            }
        }
        cout << endl;
    }else if(diff < 0){
        if(snow_cnt == 0){
            print("Impossible");
        }else{
            bool flg = true;
            ll v = abs(diff);
            rep(i,0,n){
                if(S[i] == '*' && flg){
                    flg = false;
                    rep(j,0,v){
                        cout << S[i-1];
                    }
                }
                if(S[i] != '?' && S[i] != '*'){
                    cout << S[i];
                }
            }
            cout << endl;
        }
    }else{
        if(snow_cnt + candy_cnt < diff){
            print("Impossible");
        }else{
            ll cnt = 0;
            char ss[210];
            ll idx = 0;
            rep(i,0,n){
                if((S[i] == '?' || S[i] == '*') && cnt < diff){
                    cnt++;
                    idx--;
                }
                if(S[i] != '?' && S[i] != '*'){
                    ss[idx] = S[i];
                    idx++;
                }
            }
            rep(k,0,idx){
                cout << ss[k];
            }
            cout << endl;
        }
    }
}
