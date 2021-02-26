#include <bits/stdc++.h>
using namespace std;

vector<bool> r;

void dfs(int v, const vector<vector<int> > &G) {
    r[v] = true;
    for(int to : G[v]) {
        if(!r[to]) dfs(to, G);
    }
}


/**********************************************/
template <typename T>
struct edge{
    int from;
    int to;
    T weight;
};

template <typename T>
class BellmanFord {
public:
    BellmanFord(int V, vector<edge<T> > E)
    :V(V), E(E), source(-1), INF(numeric_limits<T>::max()) {}

    // solve the single-source shortest path problem
    void build(int source) {
        // initialize
        this->source = source;
        dist.resize(V, INF);
        dist[source] = 0;
        pred.resize(V);
        edge<T> t = {-1, source, 0};
        pred[source] = t;

        // relax
        for(int i = 1; i < V; ++i) {
            for(edge<T> e : E) {
                if(dist[e.from] == INF) continue;
                if(dist[e.to] > dist[e.from] + e.weight) {
                    dist[e.to] = dist[e.from] + e.weight;
                    pred[e.to] = e;
                }
            }
        }

        // negative-weight cycle check
        for(edge<T> e : E) {
            if(dist[e.from] == INF) continue;
            if(dist[e.to] > dist[e.from] + e.weight) {
                // detected a negative-weight cycle!
                if(!r[e.to]) continue;
                dist[source] = -1;
            }
       }
    }

    // return the distance between source and destination
    // build if necessary
    T distance(int source, int destination) {
        if(this->source != source) build(source);
        return dist[destination];
    }

    // return the path between source and destination
    // Return value holds the edges in the reverse order
    // build if necessary
    vector<edge<T> > shortest_path(int source, int destination) {
        if(this->source != source) build(source);
        
        if(dist[destination] == INF) {
            return vector<edge<T> >(0);
        } else {
            vector<edge<T> > path;
            int cur = destination;
            do {
                path.push_back(pred[cur]);
                cur = pred[cur].from;
            } while(cur != -1);
            return path;
        }
    }

private:
    int V;
    vector<edge<T> > E;
    vector<T> dist;
    vector<edge<T> > pred;
    int source;
    const T INF;
};
/**********************************************/


using pp = pair<int, long long>;
int main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<edge<long long> > E(N);
    vector<vector<int> > rG(N, vector<int>(0));
    for(int i=0; i<M; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        edge<long long> e = {a - 1, b - 1, P - c};
        E[i] = e;
        rG[b - 1].push_back(a - 1);
    }
    cout << "hoge" << endl;

    r.resize(N, false);
    dfs(N - 1, rG);

    BellmanFord<long long> bf(N, E);
    if(bf.distance(0, 0) == -1) cout << -1 << endl;
    else cout << max(-bf.distance(0, N - 1), 0LL) << endl;
}
