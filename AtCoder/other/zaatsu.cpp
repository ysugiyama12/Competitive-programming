#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int is_visit[2010][2010] = {};
int imos[2010][2010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll W,H,N;
    cin >> W >> H >> N;
    vector<ll> X,Y;
    ll x1[1010],y1[1010],x2[1010],y2[1010];
    rep(i,0,N){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        X.push_back(x1[i]);
        X.push_back(x2[i]);
        Y.push_back(y1[i]);
        Y.push_back(y2[i]);
    }
    X.push_back(0);
    X.push_back(W);
    Y.push_back(0);
    Y.push_back(H);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    rep(i,0,N){
        ll x_1 = lower_bound(X.begin(), X.end(), x1[i]) - X.begin();
        ll x_2 = lower_bound(X.begin(), X.end(), x2[i]) - X.begin();
        ll y_1 = lower_bound(Y.begin(), Y.end(), y1[i]) - Y.begin();
        ll y_2 = lower_bound(Y.begin(), Y.end(), y2[i]) - Y.begin();

        imos[y_1][x_1]++;
        imos[y_2][x_2]++;
        imos[y_2][x_1]--;
        imos[y_1][x_2]--;
    }
    rep(i,0,Y.size()){
        rep(j,1,X.size()){
            imos[i][j] += imos[i][j-1];
        }
    }
    rep(j,0,X.size()){
        rep(i,1,Y.size()){
            imos[i][j] += imos[i-1][j];
        }
    }
    ll ans = 0;
    ll dx[4] = {0,0,1,-1};
    ll dy[4] = {1,-1,0,0};
    rep(i,0,(ll)Y.size()-1){
        rep(j,0,(ll)X.size()-1){
            if(is_visit[i][j] || imos[i][j] != 0) continue;
            ans++;
            queue<lpair> qq;
            qq.push(make_pair(i,j));
            while(!qq.empty()){
                lpair q1 = qq.front();
                qq.pop();
                if(is_visit[q1.first][q1.second] == 1) continue;
                is_visit[q1.first][q1.second] = 1;
                rep(k,0,4){
                    ll yy = q1.first + dy[k];
                    ll xx = q1.second + dx[k];
                    if(yy >= 0 && yy < (ll)Y.size()-1 && xx >= 0 && xx < (ll)X.size()-1){
                        if(is_visit[yy][xx] == 0 && imos[yy][xx] == 0){
                            qq.push(make_pair(yy,xx));
                        }
                    }
                }
            }
        }
    }
    print(ans);
}