#include <bits/stdc++.h>
using namespace std;
int n,t,s,a[100][100];
bool chuaxet[100];
int truoc[100];

void Result(){
    if(truoc[t]==0){
        cout <<"no path";
        return;
    }
    int j=t;
    cout <<t<<" ";
    while(truoc[j] != s){
        cout <<truoc[j]<<" ";
        j= truoc[j];
    }
    cout <<s;
}
void BFS(int u){
    queue <int> Qu;
    chuaxet[u]=false;
    Qu.push(u);
    while(!Qu.empty()){
        int s= Qu.front();
        Qu.pop();
        for(int v=1; v<=n; v++){
            if(a[s][v]==1 && chuaxet[v]== true){
                chuaxet[v]=false;
                Qu.push(v);
                truoc[v]=s;
            }
        }
    }
}
void DFS(int u){
    chuaxet[u]=false;
    for(int v=1; v<=n; v++){
        if(a[u][v]==1 && chuaxet[v]==true){
            truoc[v]=u;
            DFS(v);
        }
    }
}
int main(){
    cin >>n>>s>>t;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >>a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        chuaxet[i]=true;
        truoc[i]=0;
    }
    DFS(s);
    cout <<"DFS path: ";Result();
    cout <<endl;
    
    for(int i=1; i<=n; i++){
        chuaxet[i]=true;
        truoc[i]=0;
    }
    BFS(s);
    cout <<"BFS path: ";Result();
    cout <<endl;
}


