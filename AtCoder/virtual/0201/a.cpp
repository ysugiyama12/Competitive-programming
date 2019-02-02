#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[100010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    map<ll,ll> cnt;
    rep(i,0,N){
        cnt[A[i]]++;
    }
    ll ans = 0;
    rep(i,0,N){
        if(cnt[A[i]] == 0) continue;
        ans++;
        cnt[A[i]]--;
        if(A[i] == 1){
            if(cnt[3] != 0){
                cnt[3]--;
            }else if(cnt[2] != 0 && cnt[1] != 0){
                cnt[2]--;
                cnt[1]--;
            }else if(cnt[1] >= 3){
                cnt[1] -= 3;
            }else if(cnt[2] != 0){
                cnt[2]--;
            }else if(cnt[1] >= 2){
                cnt[1] -= 2;
            }else if(cnt[1] != 0){
                cnt[1]--;
            }
        }else if(A[i] == 2){
            if(cnt[2] != 0){
                cnt[2]--;
            }else if(cnt[1] >= 2){
                cnt[1] -= 2;
            }else if(cnt[1] != 0){
                cnt[1]--;
            }
        }else if(A[i] == 3){
            if(cnt[1] != 0){
                cnt[1]--;
            }
        }


    }
    print(ans);
    // sort(A, A+N);
    // ll ans = 0;
    // ll p1 = 0, p2 = N-1;
    // while(p2 > p1){
    //     ll v1 = A[p1];
    //     ll v2 = A[p2];
    //     if(v1+v2 <= 4){
    //         ans++;
    //         p1++;
    //         p2--;
    //     }else{
    //         ans++;
    //         p2--;
    //     }
    // }
    // print(ans);
}
