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
int N,M;
vector<int> mm[200010];
int a[200010], b[200010], dist[200010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        mm[a[i]].push_back(b[i]);
        mm[b[i]].push_back(a[i]);
    }
    bool ans = false;
    rep(i,1,N-1){
        int cnt = 0;
        for(auto &e : mm[i]){
            if(e == 0 || e == N-1){
                cnt++;
            }
        }
        if(cnt == 2) ans = true;
    }
    if(ans){
        print("POSSIBLE");
    }else{
        print("IMPOSSIBLE");
    }

}
