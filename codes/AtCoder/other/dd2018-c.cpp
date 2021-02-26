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
const ll MOD = 1LL<<32;
typedef pair<ll, ll> lpair;
typedef struct {
    ll L;
    ll R;
    ll idx;
} pp;

string S;
ll Q;
ll L[100010], R[100010];
ll cnt[1000010][5] = {};
ll cnt2[1000010][5] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S >> Q;
    ll N = S.size();
    rep(i,0,Q){
        cin >> L[i] >> R[i];
    }
    rep(i,0,N){
        if(S[i] == 'D'){
            cnt[i+1][0] = cnt[i][0] + 1;
            cnt[i+1][1] = cnt[i][1];
            cnt[i+1][2] = cnt[i][2];
            cnt[i+1][3] = cnt[i][3];
            cnt[i+1][4] = cnt[i][4];
        }
        if(S[i] == 'I'){
            cnt[i+1][1] += cnt[i][0] + cnt[i][1];
            cnt[i+1][0] = cnt[i][0];
            cnt[i+1][2] = cnt[i][2];
            cnt[i+1][3] = cnt[i][3];
            cnt[i+1][4] = cnt[i][4];
        }
        if(S[i] == 'S'){
            cnt[i+1][2] += cnt[i][1] + cnt[i][2];
            cnt[i+1][0] = cnt[i][0];
            cnt[i+1][1] = cnt[i][1];
            cnt[i+1][3] = cnt[i][3];
            cnt[i+1][4] = cnt[i][4];
        }
        if(S[i] == 'C'){
            cnt[i+1][3] += cnt[i][2] + cnt[i][3];
            cnt[i+1][0] = cnt[i][0];
            cnt[i+1][1] = cnt[i][1];
            cnt[i+1][2] = cnt[i][2];
            cnt[i+1][4] = cnt[i][4];
        }
        if(S[i] == 'O'){
            cnt[i+1][4] += cnt[i][3] + cnt[i][4];
            cnt[i+1][0] = cnt[i][0];
            cnt[i+1][1] = cnt[i][1];
            cnt[i+1][2] = cnt[i][2];
            cnt[i+1][3] = cnt[i][3];
        }
    }
    rrep(i,N-1,0){
        if(S[i] == 'O'){
            cnt2[i][0] = cnt2[i+1][0] + 1;
            cnt2[i][1] = cnt2[i+1][1];
            cnt2[i][2] = cnt2[i+1][2];
            cnt2[i][3] = cnt2[i+1][3];
            cnt2[i][4] = cnt2[i+1][4];
        }
        if(S[i] == 'C'){
            cnt2[i][1] += cnt2[i+1][0] + cnt2[i+1][1];
            cnt2[i][0] = cnt2[i+1][0];
            cnt2[i][2] = cnt2[i+1][2];
            cnt2[i][3] = cnt2[i+1][3];
            cnt2[i][4] = cnt2[i+1][4];
        }
        if(S[i] == 'S'){
            cnt2[i][2] += cnt2[i+1][1] + cnt2[i+1][2];
            cnt2[i][0] = cnt2[i+1][0];
            cnt2[i][1] = cnt2[i+1][1];
            cnt2[i][3] = cnt2[i+1][3];
            cnt2[i][4] = cnt2[i+1][4];
        }
        if(S[i] == 'I'){
            cnt2[i][3] += cnt2[i+1][2] + cnt2[i+1][3];
            cnt2[i][0] = cnt2[i+1][0];
            cnt2[i][1] = cnt2[i+1][1];
            cnt2[i][2] = cnt2[i+1][2];
            cnt2[i][4] = cnt2[i+1][4];
        }
        if(S[i] == 'D'){
            cnt2[i][4] += cnt2[i+1][3] + cnt[i+1][4];
            cnt2[i][0] = cnt2[i+1][0];
            cnt2[i][1] = cnt2[i+1][1];
            cnt2[i][2] = cnt2[i+1][2];
            cnt2[i][3] = cnt2[i+1][3];
        }
    }
    rep(i,0,5){
        rep(j,0,N+1){
            cout << cnt[j+1][i] << " ";
        }
        cout << endl;
    }
    rep(i,0,5){
        rep(j,0,N+1){
            cout << cnt2[j+1][i] << " ";
        }
        cout << endl;
    }
    rep(i,0,Q){
        ll ans = cnt[R[i]][4];
        print(ans);
        rep(j,0,4){
            ans -= cnt[L[i]-1][j] * cnt2[L[i]][3-j];
        }
        print(ans);
        ans -= cnt[L[i]-1][4];
        print(ans);
        ans %= (1LL<<32);
        print("---");
    }

}
