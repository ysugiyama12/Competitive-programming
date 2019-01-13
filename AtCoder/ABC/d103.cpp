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
int a[100010];
int b[100010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i];
    }
    vector<pair<int, int> > pairs(M);
    rep(i,0,M){
        pairs[i] = make_pair(b[i],a[i]);
    }
    sort(pairs.begin(), pairs.end());
    int bb = -1;
    int ans = 0;
    rep(i,0,M){
        int i_left = pairs[i].second;
        int i_right = pairs[i].first;
        if(i_left <= bb && bb < i_right){
            continue;
        }else{
            ans++;
            bb = i_right - 1;
        }
    }
    print(ans);





}
