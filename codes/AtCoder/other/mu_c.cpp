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
int N,M;
string s[2001];
int left_1[20001][20001];
int right_1[20001][20001];
int top[2001][2001];
int bottom[2001][2001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    rep(i,0,N){
        cin >> s[i];
    }

    rep(i,0,N){
        int l = 0;
        int r = 0;
        rep(j,1,M){
            if(s[i][j-1] == '.' && s[i][j] == '.'){
                l++;
                left_1[i][j] = l;
            }else{
                l = 0;
                left_1[i][j] = 0;
            }

            if(s[i][M-j] == '.' && s[i][M-1-j] == '.'){
                r++;
                right_1[i][M-1-j] = r;
            }else{
                r = 0;
                right_1[i][M-1-j] = 0;
            }
            
        }
    }
    rep(j,0,M){
        int t = 0;
        int b = 0;
        rep(i,1,N){
            if(s[i-1][j] == '.'&& s[i][j] == '.'){
                t++;
                top[i][j] = t;
            }else{
                t = 0;
                top[i][j] = 0;
            }
            if(s[N - i][j] == '.' && s[N-1-i][j] == '.'){
                b++;
                bottom[N-1-i][j] = b;
            }else{
                b = 0;
                bottom[N-1-i][j] = 0;
            }
        }
    }
    ll ans = 0;

    rep(i,0,N){
        rep(j,0,M){
            if(s[i][j] == '.'){
                ans += (top[i][j] + bottom[i][j]) * (left_1[i][j] + right_1[i][j]);
            }
        }
    }
    print(ans);

}
