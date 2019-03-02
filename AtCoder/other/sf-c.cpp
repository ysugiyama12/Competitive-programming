#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
// typedef struct{
//     ll r;
//     ll c;
//     ll ad;
// } ee;
ll R,C;
char A[45][45];
ll is_visit[45][45] = {};
ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
// ll dfs1(ll r, ll c){
//     ll visit_tmp[45][45] = {};
//     stack<ee> st;
//     ee tmp = {r,c,1};
//     st.push(tmp);
//     // ll val = 0;
//     map<lpair, ll> mp;
//     while(!st.empty()){
//         ee e1 = st.top();
//         st.pop();
//         if(visit_tmp[e1.r][e1.c]) continue;
//         visit_tmp[e1.r][e1.c] = 1;
//         if(e1.ad == 1){
//             mp[make_pair(e1.r, e1.c)]++;
//             rep(i,0,4){
//                 ll ry = e1.r + dy[i];
//                 ll cx = e1.c + dx[i];
//                 if(ry < 0 || ry >= R || cx < 0 || cx >= C) continue;
//                 if(A[ry][cx] == '*') continue;
//                 if(visit_tmp[ry][cx] == 1) continue;
//                 ee tt = {ry, cx, 0};
//                 st.push(tt);
//             }
//         }else{
//             rep(i,0,4){
//                 ll ry = e1.r + dy[i];
//                 ll cx = e1.c + dx[i];
//                 if(ry < 0 || ry >= R || cx < 0 || cx >= C) continue;
//                 if(A[ry][cx] == '*') continue;
//                 if(visit_tmp[ry][cx] == 1) continue;
//                 ee tt = {ry, cx, 1};
//                 st.push(tt);
//             }

//         }
//     }
//     return mp.size();
// }

// ll dfs2(ll r, ll c){
//     // ll visit_tmp[45][45] = {};
//     stack<ee> st;
//     ee tmp = {r,c,0};
//     st.push(tmp);
//     map<lpair, ll> mp;
//     while(!st.empty()){
//         ee e1 = st.top();
//         st.pop();
//         if(is_visit[e1.r][e1.c]) continue;
//         is_visit[e1.r][e1.c] = 1;
//         if(e1.ad == 1){
//             mp[make_pair(e1.r, e1.c)]++;
//             rep(i,0,4){
//                 ll ry = e1.r + dy[i];
//                 ll cx = e1.c + dx[i];
//                 if(ry < 0 || ry >= R || cx < 0 || cx >= C) continue;
//                 if(A[ry][cx] == '*') continue;
//                 if(is_visit[ry][cx] == 1) continue;
//                 ee tt = {ry, cx, 0};
//                 st.push(tt);
//             }
//         }else{
//             rep(i,0,4){
//                 ll ry = e1.r + dy[i];
//                 ll cx = e1.c + dx[i];
//                 if(ry < 0 || ry >= R || cx < 0 || cx >= C) continue;
//                 if(A[ry][cx] == '*') continue;
//                 if(is_visit[ry][cx] == 1) continue;
//                 ee tt = {ry, cx, 1};
//                 st.push(tt);
//             }

//         }
//     }
//     return mp.size();
// }

ll dfs(ll r, ll c){
    ll odd = 0, even = 0;
    stack<lpair> st;
    st.push(make_pair(r,c));
    while(!st.empty()){
        lpair l1 = st.top();
        st.pop();
        if(is_visit[l1.first][l1.second]) continue;
        is_visit[l1.first][l1.second] = 1;
        if((l1.first + l1.second) % 2 == 0){
            even++;
        }else{
            odd++;
        }
        rep(i,0,4){
            ll ry = l1.first + dy[i];
            ll cx = l1.second + dx[i];
            if(ry < 0 || ry >= R || cx < 0 || cx >= C) continue;
            if(A[ry][cx] == '*') continue;
            if(is_visit[ry][cx] == 1) continue;
            st.push(make_pair(ry, cx));
        }
    }
    return max(odd, even);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> R >> C;
    rep(i,0,R){
        rep(j,0,C){
            cin >> A[i][j];
        }
    }
    ll ans = 0;
    rep(i,0,R){
        rep(j,0,C){
            if(A[i][j] == '*') continue;
            if(is_visit[i][j] == 1) continue;
            // ans += max(dfs1(i,j), dfs2(i,j));
            ans += dfs(i,j);
            
        }
    }
    print(ans);


}
