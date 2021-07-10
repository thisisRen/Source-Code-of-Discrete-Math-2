#include <bits/stdc++.h>
using namespace std;
int n, a[100][100];
bool chuaxet[100];

void khoitao(){
    for(int i=1; i<=n;i++){
        chuaxet[i]= true;
    }
}
void BFS(int u){
    queue <int> QU;
    chuaxet[u]= false;
    QU.push(u);
    while (! QU.empty()){
        int s= QU.front();
        QU.pop();
        for(int v=1; v<=n; v++){
            if(a[s][v]==1 && chuaxet[v]== true){
                chuaxet[v]=false;
                QU.push(v);
            }
        }
    }
}
void DuyetTPLT(){
    khoitao();
    int soTPLT=0;
    for(int i=1; i<=n; i++){
        if(chuaxet[i]== true){
            soTPLT++;
            BFS(i);
            
        }
    }
    cout << soTPLT<<endl;
}
int main(){
    cin >>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    DuyetTPLT();
    
}









