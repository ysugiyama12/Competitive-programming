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
bool comp1(lpair l1, lpair l2){
    return (l1.second < l2.second);
}

bool comp2(lpair l1, lpair l2){
    return (l1.first < l2.first);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string s[100010];
    cin >> N;
    rep(i,0,N){
        cin >> s[i];
    }
    ll lv[100010] = {}, rv[100010] = {};
    rep(i,0,N){
        rep(n,0,s[i].size()){
            if(s[i][n] == '('){
                lv[i]++;
            }else{
                if(lv[i] != 0){
                    lv[i]--;
                }else{
                    rv[i]++;
                }
            }
        }
    }
    map<ll, ll> mp1, mp2;
    ll cnt = 0;
    rep(i,0,N){
        if(lv[i] == 0 && rv[i] != 0){
            mp1[rv[i]]++;
        }else if(lv[i] != 0 && rv[i] == 0){
            mp2[lv[i]]++;
        }else if(lv[i] == 0 && rv[i] == 0){
            cnt++;
        }
    }
    ll ans = 0;
    ans += cnt/2;
    for(auto &e: mp1){
        ans += min(e.second, mp2[e.first]);
    }
    print(ans);



}
