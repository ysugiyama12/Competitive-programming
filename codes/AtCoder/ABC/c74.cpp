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
    double A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    double density_max = 0;
    double water_max = 0;
    double sugar_max = 0;
    rep(i,0,101){
        rep(j,0,101){
            rep(k,0,101){
                rep(l,0,101){
                    double water = 100 * A * i + 100 * B * j;
                    double sugar = C * k + D * l;
                    if(water + sugar <= F && water + sugar != 0 && water != 0){
                        double density = 100 * sugar /(water + sugar);
                        double d_E = 100 * E / (100 + E);
                        if(density <= d_E){
                            if(density >= density_max){
                                density_max = density;
                                water_max = water;
                                sugar_max = sugar;
                            }

                        }
                    }
                }
            }

        }
    }
    cout << water_max + sugar_max << " " << sugar_max << endl;

}
