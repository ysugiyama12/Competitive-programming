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
    int n;
    ll a[200010];
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
    }
    vector<int> ans;
    if(n % 2 == 0){
        rep(i,0,n/2){
            ans.push_back(a[2*(n/2 - i) - 1]);
        }
        rep(i,0,n/2){
            ans.push_back(a[2 * i]);
        }
    }else{
        rep(i,0,(n+1)/2){
            ans.push_back(a[2 * ((n+1)/2 - i - 1)]);
        }
        rep(i,0,(n-1)/2){
            ans.push_back(a[2 * i + 1]);
        }
    }
    int ll = ans.size();
    rep(i,0,ll){
        if(i == ll-1){
            cout << ans[i] << endl;
        }else{
            cout << ans[i] << " ";
        }
    }


}
