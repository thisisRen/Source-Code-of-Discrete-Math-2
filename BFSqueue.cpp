#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class Dothi{
    int n;
    int a[MAX][MAX];
    public:
    bool chuaxet[MAX];
    void readdata();
    void init();
    void BFS(int u);
    
};

void Dothi :: init(){
    cin >>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >>a[i][j];
        }
    }
}
void Dothi :: readdata(){
    for(int i=1; i<=n; i++){
        chuaxet[i]= true;
    }
}
void Dothi :: BFS(int u){
    queue <int> Qu;
    cout <<u<<" ";
    chuaxet[u]= false;
    Qu.push(u);
    while(!Qu.empty()){
        int s= Qu.front();
        Qu.pop();
        for(int v=1; v<=n; v++){
            if(a[s][v]==1 && chuaxet[v]==true){
                cout <<v<<" ";
                chuaxet[v]=false;
                Qu.push(v);
            }
        }
    }
}
int main(){
    Dothi D;
    D.init();
    D.readdata();
    D.BFS(2);
}

