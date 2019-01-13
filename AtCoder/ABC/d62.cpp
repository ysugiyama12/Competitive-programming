#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
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
    int N;
    ll a[300010] = {};
    cin >> N;
    rep(i,0,N*3){
        cin >> a[i];
    }
    ll sum_1[300010] = {};
    ll sum_2[300010] = {};
    priority_queue< ll, vector<ll>, greater<ll> > q1;
    priority_queue<ll, vector<ll>, less<ll> > q2;
    ll sum_now = 0;
    rep(i,0,N){
        q1.push(a[i]);
        sum_now += a[i];
    }
    sum_1[N-1] = sum_now;
    rep(i,N,2*N){
        q1.push(a[i]);
        ll val = q1.top();
        q1.pop();
        if(val != a[i]){
            sum_now += a[i] - val;
        }
        sum_1[i] = sum_now;
    }
    sum_now = 0;
    rep(i,2*N,3*N){
        q2.push(a[i]);
        sum_now += a[i];
    }
    sum_2[2*N - 1] = sum_now;
    rep(j,N+1,2*N+1){
        int i = 3*N - 1 - j;
        q2.push(a[i+1]);
        ll val = q2.top();
        q2.pop();
        if(val != a[i+1]){
            sum_now += a[i+1] - val;
        }
        sum_2[i] = sum_now;

    }
    ll ans = -1e18;
    rep(i,N-1, 2*N){
        ans = max(ans, sum_1[i] - sum_2[i]);
    }
    print(ans);

}
