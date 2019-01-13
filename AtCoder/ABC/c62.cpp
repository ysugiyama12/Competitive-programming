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
    ll H,W;
    cin >> H >> W;
    ll ans = 1e12;
    ll s1, s2, s3, d, min_val, max_val;
    rep(i,1,H){
        s1 = i * W;
        d = W/2;
        s2 = (H - i) * d;
        s3 = (H - i) * (W - d);
        min_val = min(s1,min(s2,s3));
        max_val = max(s1,max(s2,s3));
        ans = min(ans, max_val - min_val);

        d = (H-i)/2;
        s2 = W * d;
        s3 = W * (H - i - d);
        min_val = min(s1,min(s2,s3));
        max_val = max(s1,max(s2,s3));
        ans = min(ans, max_val - min_val);
    }
    swap(H,W);
    rep(i,1,H){
        s1 = i * W;
        d = W/2;
        s2 = (H - i) * d;
        s3 = (H - i) * (W - d);
        min_val = min(s1,min(s2,s3));
        max_val = max(s1,max(s2,s3));
        ans = min(ans, max_val - min_val);

        d = (H-i)/2;
        s2 = W * d;
        s3 = W * (H - i - d);
        min_val = min(s1,min(s2,s3));
        max_val = max(s1,max(s2,s3));
        ans = min(ans, max_val - min_val);
    }

    print(ans);

}
