#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll deg, dis;
    cin >> deg >> dis;
    deg *= 10;
    if(dis < 15){
        cout << "C ";
    }else if(deg < 1125){
        cout << "N ";
    }else if(deg < 3375){
        cout << "NNE ";
    }else if(deg < 5625){
        cout << "NE "; 
    }else if(deg < 7875){
        cout << "ENE "; 
    }else if(deg < 10125){
        cout << "E "; 
    }else if(deg < 12375){
        cout << "ESE "; 
    }else if(deg < 14625){
        cout << "SE "; 
    }else if(deg < 16875){
        cout << "SSE "; 
    }else if(deg < 19125){
        cout << "S "; 
    }else if(deg < 21375){
        cout << "SSW "; 
    }else if(deg < 23625){
        cout << "SW "; 
    }else if(deg < 25875){
        cout << "WSW "; 
    }else if(deg < 28125){
        cout << "W "; 
    }else if(deg < 30375){
        cout << "WNW "; 
    }else if(deg < 32625){
        cout << "NW "; 
    }else if(deg < 34875){
        cout << "NNW "; 
    }else{
        cout << "N ";
    }
    if(dis < 15){
        print(0);
    }else if(dis < 93){
        print(1);
    }else if(dis < 201){
        print(2);
    }else if(dis < 327){
        print(3);
    }else if(dis < 477){
        print(4);
    }else if(dis < 645){
        print(5);
    }else if(dis < 831){
        print(6);
    }else if(dis < 1029){
        print(7);
    }else if(dis < 1245){
        print(8);
    }else if(dis < 1467){
        print(9);
    }else if(dis < 1707){
        print(10);
    }else if(dis < 1959){
        print(11);
    }else{
        print(12);
    }

}

