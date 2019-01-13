#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string s = to_string(N);
    int nn = s.size();
    ll ans = 0;
    rep(i,1,nn+1){
        rep(j,0,pow(3,i)){
            ll tt = j;
            ll v[11] = {};
            ll idx = 0;
            while(tt > 0){
                v[idx] = tt % 3;
                tt /= 3;
                idx++;
            }
            ll cnt[3] = {};
            rep(m,0,i){
                cnt[v[m]]++;
            }
            if(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
                ll val = 0;
                rep(m,0,i){
                    if(v[m] == 0){
                        val += 3 * pow(10, m);
                    }else if(v[m] == 1){
                        val += 5 * pow(10,m);
                    }else{
                        val += 7 * pow(10,m);
                    }
                }
                if(val <= N){
                    ans++;
                }
            }

        }
    }
    print(ans);
    // ll ans = 0;
    // rep(i,0,nn){
    //     if(nn-i < 3) continue;
    //     ll tt = 1;
    //     rep(j,i,nn){
    //         char sv = s[j];
    //         print(sv);
    //         int sn = sv - '0';
    //         if(sn >= 3 && sn < 5){
    //             tt *= 1;
    //         }else if(sn >= 5 && sn < 7){
    //             tt *= 2;
    //         }else if(sn >= 7){
    //             tt *= 3;
    //         }else{
    //             tt *= 0;
    //         }
    //     }
    //     print(tt);
    //     print("---");
    //     ans += tt;
    //     // ll tt = 1;
    //     // char sv = s[nn-i-1];
    //     // int sn = sv - '0';
    //     // if(sn >= 3 && sn < 5){
    //     //     ans += pow(3,i-1);
    //     // }else if(sn >= 5 && sn < 7){
    //     //     ans += 2 * pow(3,i-1);
    //     // }else if(sn >= 7){
    //     //     ans += 3 * pow(3,i-1);
    //     // }
    // }
    // ll tt = 1;
    // rep(i,0,nn){
    //     char sv = s[i];
    //     int sn = sv - '0';
    //     if(s[i] >= 3 && s[i] < 5){
    //         tt *= 1;
    //     }else if(s[i] >= 5 && s[i] < 7){
    //         tt *= 2;
    //     }else if(s[i] >= 7){
    //         tt *= 3;
    //     }else{
    //         tt *= 0;
    //     }
    // }
    // ans += tt;
    // print(ans);

}
