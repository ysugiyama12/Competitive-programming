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
    int N;
    int a[100010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    int cnt[100010] = {};
    ll ans = 0;
    rep(i,0,N){
        if(a[i] <= 1e5){
            cnt[a[i]]++;        
        }else{
            ans++;
        }
    }
    rep(i,1,100001){
        if(cnt[i] < i){
            ans += cnt[i];
        }else if(cnt[i] > i){
            ans += cnt[i] - i;
        }
    }
    print(ans);

}
