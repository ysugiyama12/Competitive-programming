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
    int a[110];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    sort(a, a+N);
    int color[8] = {};
    ll over_red = 0;
    rep(i,0,N){
        if(a[i] < 400) color[0]++;
        else if(a[i] < 800) color[1]++;
        else if(a[i] < 1200) color[2]++;
        else if(a[i] < 1600) color[3]++;
        else if(a[i] < 2000) color[4]++;
        else if(a[i] < 2400) color[5]++;
        else if(a[i] < 2800) color[6]++;
        else if(a[i] < 3200) color[7]++;
        else over_red++;
    }
    int variation = 0;
    rep(i,0,8){
        if(color[i] > 0) variation++;
    }
    if(over_red == 0){
        cout << variation << " " << variation << endl;
    }else if(variation == 0){
        cout << 1 << " " << over_red << endl;
    }else{
        cout << variation << " " << variation + over_red << endl;
    }
}
