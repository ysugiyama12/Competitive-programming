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
    int N,K;
    cin >> N >> K;
    int c[100001];
    rep(i,0,N){
        cin >> c[i];
    }
    rep(i,0,N){
        if(c[i] == 0){
            print(N);
            return 0;
        }
    }
    int left = 0, right = 0;
    int ans = 0;
    ll mul = c[0];
    while(right < N){
        if(mul <= K){
            ans = max(ans, right - left + 1);
            right++;
            if(right == N) break;
            mul *= c[right];
        }else{
            if(left == right){
                right++;
                if(right == N) break;
                mul *= c[right];
            }
            mul /= c[left];
            left++;
        }
    }
    print(ans);
}
