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
    int N;
    ll a[100010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    ll cnt_2 = 0;
    ll cnt_4 = 0;
    rep(i,0,N){
        if(a[i] % 4 == 0){
            cnt_4++;
        }else if(a[i] % 2 == 0){
            cnt_2++;
        }
    }

    ll ans = N;
    ans -= 2 * cnt_4;
    if(ans <= 1){
        print("Yes");
    }else{
        ans -= cnt_2;
        if(ans <= 0){
            print("Yes");
        }else{
            print("No");
        }
    }

}
