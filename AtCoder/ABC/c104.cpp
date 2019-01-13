#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
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
    int D,G;
    ll p[20];
    ll c[20];
    cin >> D >> G;
    rep(i,0,D){
        cin >> p[i] >> c[i];
    }
    int ans = 1e5;

    rep(i,0,(1<<D)){
        int sum = 0;
        int max_pos = -1;
        int count = 0;
        rep(j,0,D){
            if((i >> j) & 1){
                sum += c[j] + (j+1) * 100 * p[j];
                count += p[j];
            }else{
                max_pos = max(max_pos, j);
            }
        }
        if(sum >= G){
            ans = min(ans, count);
        }else if(max_pos != -1){
            int g = G - sum;
            int t = 0;
            while(g > 0 && t <= p[max_pos] - 1 ){
                g -= (max_pos + 1) * 100;
                count++;
                t++;
            }
            if(g <= 0){
                ans = min(ans, count);
            }
        }



    }
    print(ans);
}
