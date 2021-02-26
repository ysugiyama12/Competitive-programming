#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double A,B;
    ll N;
    cin >> A >> B >> N;
    double C[5010], D[5010];
    rep(i,0,N){
        cin >> C[i] >> D[i];
    }
    rep(i,0,N){
        if((A <= C[i] && B <= D[i]) || (A <= D[i] && B <= C[i])){
            print("YES");
        }else if((A > C[i] && B > D[i]) || (A > D[i] && B > C[i])){
            print("NO");
        }else{
            if(A > C[i]){
                double cross = sqrt(pow(A,2) + pow(B,2));
                double cs = A / cross;
                
            }else{
                if(A * B / D[i] <= C[i]){
                    print("YES");
                }else{
                    print("NO");
                }

            }

        }

    }
}
