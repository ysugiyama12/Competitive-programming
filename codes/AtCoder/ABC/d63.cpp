#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,A,B;
    ll h[100010];
    cin >> N >> A >> B;
    rep(i,0,N){
        cin >> h[i];
    }
    sort(h, h+N, greater<int>());

    ll l = -1, r = 1e9 + 7;
    ll h_tmp[100010];
    while(r - l > 1){
        rep(i,0,N){
            h_tmp[i] = h[i];
        }
        ll mid = (r + l)/2;
        bool is_ok = false;
        ll cnt_A = 0, dmg = A - B;
        rep(i,0,N){
            if(h_tmp[i] <= mid * B){
                h_tmp[i] = 0;
            }else{
                h_tmp[i] -= mid * B;
            }
            if(h_tmp[i] % dmg == 0){
                cnt_A += h_tmp[i] / dmg;
            }else{
                cnt_A += h_tmp[i] / dmg + 1;
            }
        }
        if(cnt_A <= mid){
            r = mid;
        }else{
            l = mid;
        }

    }
    print(r);


}
