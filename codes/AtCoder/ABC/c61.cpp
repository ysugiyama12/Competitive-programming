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
    ll N,K;
    ll a[100010], b[100010];
    cin >> N >> K;
    vector< pair<ll, ll> > pairs(N);

    rep(i,0,N){
        cin >> a[i] >> b[i];
    }
    rep(i,0,N){
        pairs[i] = make_pair(a[i], b[i]);
    }
    sort(pairs.begin(), pairs.end());
    ll cnt = 0;
    rep(i,0,N){
        cnt += pairs[i].second;
        if(cnt >= K){
            print(pairs[i].first);
            return 0;
        }
    }

}
