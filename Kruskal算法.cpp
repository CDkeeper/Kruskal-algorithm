#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int p[N];

struct Edge{
    int a, b, w;

    bool operator<(const Edge &e) const{
        return w < e.w;
    }
} es[M];

int find(int x){
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int kruskal(){
    int cnt = 0, res = 0;
    sort(es, es + m);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++){
        int a = es[i].a, b = es[i].b, w = es[i].w;
        a = find(a), b = find(b);
        if (a != b){
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1)
        return INF;
    else
        return res;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        es[i] = {a, b, w};
    }

    int t = kruskal();
    if (t == INF)
        cout << "无法实现!";
    else
        cout <<t;
}
