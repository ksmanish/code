#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int n;
vector<vector<int> > graph;
int dist[1001];
bool visited[1001];
void dfs(int i){
    dist[i]++;
    visited[i] = true;
    vector<int>::iterator itr;
    for(itr=graph[i].begin();itr!=graph[i].end();itr++){
        int j = *itr;
        if(!visited[j]){
            dist[j] = dist[i];
            dfs(j);
        }
    }

}

int main(int argc, char *argv[]) {
    cin>>n;
    vector<int> tmp;
    int arr[n+1];
    for(int i=0;i<=n;i++){
        graph.push_back(tmp);
        arr[i] = 0;
        dist[i] = 0;
        visited[i] = false;
    }
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a;
        arr[a] = 1;
    }
    dist[1] = -1;
    dfs(1);
    int res = INT_MAX;
    int index = 0;
    for(int i=2;i<=n;i++){
        if(arr[i]==1&&dist[i]<res){
            res = dist[i];
            index = i;
        }
    }
    cout<<index<<endl;
    graph.clear();
}