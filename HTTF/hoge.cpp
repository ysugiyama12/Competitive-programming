//どこがバグってるんですか？

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pa = pair<int,int>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

vec<pair<int,int>> ans_edges;

struct P{
    int x,y,c;
};

int dist2(P& a,P& b){
    int dx = b.x-a.x,dy = b.y-a.y;
    return dx*dx+dy*dy;
}

bool is_connectable(P& a,P& b){
    return dist2(a,b)<=(a.c+b.c)*(a.c+b.c);
}

struct tree{
    int size;
    int id;
    vvec<int> t;
/*    vec<int> operator[](const int& i){
        return t[i];
    }*/

    bool operator<(const tree& r)const{
        return size>r.size;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,S;
    cin >> N >> S;
    vec<P> points(N);
    for(int i=0;i<N;i++){
        int x,y,c;
        cin >> x >> y >> c;
        points[i] = {x,y,c};
    }
    vec<tree> trees;
    vec<int> ids(S);
    for(int i=0;i<S;i++){
        int K;
        cin >> K;
        vvec<int> t(K);
        for(int j=1;j<=K-1;j++){
            int p;
            cin >> p;
            p--;
            t[p].push_back(j);
            t[j].push_back(p);
        }
        trees.push_back((tree){K,i,t});
    }
//    sort(trees.begin(),trees.end());
//    for(int i=0;i<S;i++) ids[i] = trees[i].id;
    vvec<int> use_cnt(N,vec<int>(N,0));
    vvec<int> edges(N);
    set<Pa> edge_set;
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++){
        if(is_connectable(points[i],points[j])){
            use_cnt[i][j] = 2;
            use_cnt[j][i] = 2;
            edges[i].push_back(j);
            edges[j].push_back(i);
        }
    }

    for(int i=0;i<N;i++) sort(edges[i].begin(),edges[i].end(),[&](int a,int b){return edges[a].size()>edges[b].size();});

    for(int i=0;i<S;i++){
        for(int j=0;j<trees[i].size;j++){
            if(trees[i].t[j].empty()) continue;
            sort(trees[i].t[j].begin(),trees[i].t[j].end(),[&](int a,int b){return trees[i].t[a].size()>trees[i].t[b].size();});
        }
    }

    vvec<int> d_list(110);
    vec<bool> used(N,0);
    vec<int> make(S,0);
    int s = 0,ma_deg = -1;
    for(int i=1;i<N;i++) if(ma_deg<(int) edges[i].size()){
        s = i;
        ma_deg = edges[i].size();
    }

    struct state{
        int cur,now,par,depth;
    };

    vec<unordered_map<int,int>> result(S);
    int inf = 1e9;
    vec<int> dist(N,inf);
    used[s] = 1;
    for(int i=0;i<S;i++){
        set<int> nodes;
        vvec<int> t = trees[i].t;
        unordered_map<int,int> res;
        queue<state> Q;
        vec<bool> used2(N,0);
        int parent = -1,ma = 0;
        for(int j=0;j<trees[i].size;j++) if(ma<(int) t[j].size()){
            parent = j;
            ma = t[j].size();
        }
        vec<int> d_list_id(110,0);
        vvec<int> d_list2(110);
        vec<Pa> edge_list;
        Q.push({parent,s,-1,0});
        bool valid = true;
        while(!Q.empty()){
            state p = Q.front(); Q.pop();
            int cur = p.cur,now = p.now,d = p.depth;
            res[cur] = now;
            nodes.insert(now);
            for(auto c:t[cur]) if(c!=p.par){
                if(d_list_id[d+1]<(int)d_list[d+1].size()){
                    Q.push((state){c,d_list[d+1][d_list_id[d+1]],cur,d+1});
                    d_list_id[d+1]++;
                }else{
                    bool ok = false;
                    for(auto e:edges[now]){
                        if(!used[e] && !used2[e]){
                            used2[e] = 1;
                            ok = true;
                            edge_list.emplace_back(min(now,e),max(now,e));
                            d_list2[d+1].push_back(e);
                            d_list_id[d+1]++;
                            Q.push((state){c,e,cur,d+1});
                            break;
                        }
                    }
                    if(!ok){//木が作れない
                        valid = false;
                        break;
                    }
                }
            }
            if(!valid) break;
        }
        if(valid){
            for(auto& x:edge_list){
                ans_edges.push_back(x);
                edge_set.insert(x);
            }
            for(int j=0;j<N;j++) used[j] = (used[j] || used2[j]);
            for(int j=0;j<101;j++) for(auto& x:d_list2[j]) d_list[j].push_back(x);
//            assert(nodes.size()==trees[i].size);
        }
        make[i] = valid;
        result[i] = res;
    }

    assert((int)edge_set.size()==(int)ans_edges.size());
    cout << ans_edges.size() << endl;
    set<int> ans_node;
    for(auto& x:ans_edges){
        ans_node.insert(x.first);
        ans_node.insert(x.second);
    }
    std::cerr << ans_node.size() << " " << ans_edges.size() << endl;
    for(auto& x:ans_edges) std::cout << x.first+1 << " " << x.second+1 << endl;
    
    for(int i=0;i<101;i++) for(int j=i+1;j<101;j++){
        int sum = d_list[i].size()+d_list[j].size();
        set<int> node;
        for(auto& x:d_list[i]) node.insert(x);
        for(auto& x:d_list[j]) node.insert(x);
        assert(sum==(int)node.size());
    }

    for(int i=0;i<100;i++){
        int si = d_list[i].size();
        for(int j=0;j<si;j++) for(int k=j+1;k<si;k++) assert(!edge_set.count({min(d_list[i][j],d_list[i][k]),max(d_list[i][j],d_list[i][k])}));
    }

    int cnt = 0;
    for(int i=0;i<S;i++){
        int k = trees[i].size;
        cnt += make[i];
        vec<int> a;
        for(int j=0;j<k;j++){
            std::cout << (make[i]? result[i][j]+1:j+1) << (j!=k-1? " ":"\n");
            if(make[i]) a.push_back(result[i][j]);
        }
        if(make[i]){
            int c = 0;
            for(int j=0;j<k;j++) for(int l=j+1;l<k;l++) if(edge_set.count({min(a[l],a[j]),max(a[l],a[j])})) c++;
 //           cerr << c << " " << k-1 << endl;
            // assert(c==k-1);
        }
    }
    cerr << cnt << endl;
}
