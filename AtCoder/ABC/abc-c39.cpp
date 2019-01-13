#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
#define make_pair mp
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if(s == "WBWBWWBWBWBWWBWBWWBW"){
        print("Do");
    }else if(s == "WBWWBWBWBWWBWBWWBWBW"){
        print("Re");
    }else if(s == "WWBWBWBWWBWBWWBWBWBW"){
        print("Mi");
    }else if(s == "WBWBWBWWBWBWWBWBWBWW"){
        print("Fa");
    }else if(s == "WBWBWWBWBWWBWBWBWWBW"){
        print("So");
    }else if(s == "WBWWBWBWWBWBWBWWBWBW"){
        print("La");
    }else{
        print("Si");
    }
}
