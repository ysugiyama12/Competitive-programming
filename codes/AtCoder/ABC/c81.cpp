#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
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
    int N,K;
    int A[200010];
    cin >> N >> K;
    rep(i,0,N){
        cin >> A[i];
    }
    int cnt[200010] = {};
    rep(i,0,N){
        cnt[A[i]]++;
    }
    sort(cnt, cnt+N+1, greater<int>());
    ll ans = 0;
    rep(i,0,N+1){
        if(i >= K){
            ans += cnt[i];
        }
    }
    print(ans);
    

}
