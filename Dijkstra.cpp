#include <bits/stdc++.h>
#define vc 1000000
using namespace std;
int n,k;
int a[100][100];
int truoc[100];
int d[100];
bool chuaxet[100];
int t,s;

void Dijkstra(int s){
    int sum=0;
    string str="";
    int INF,u;
    d[s]=0;
    truoc[s]=0;
    chuaxet[s]= true;
    str += " <- " + (s-'0');
    for(int v=1; v<=n; v++){
        if(v!= s){
            d[v]= a[s][v];
            truoc[v]=s;
            chuaxet[v]=false;
        }
    }
    
    while(!chuaxet[t]){
        INF=vc;
        for(int v=1; v<=n;v++){
            if(!chuaxet[v] && INF > d[v]){
                u=v;
                d[v]=INF;
            }
        }
        chuaxet[u]=true;
        if(!chuaxet[t]){
            for(int v=1; v<=n; v++ ){
                if(!chuaxet[v] && (d[u] + a[u][v] < d[v])){
                    d[v]= d[u]+ a[u][v];
                    truoc[v]=u;
                    
                    
                    cout << "K/c" << " "<< s-'0' <<" -> " << v-'0' <<" = " << d[v]-'0';
                    str= " <- " + (v-'0');
                    cout << v <<" <- " <<u<<endl;
                }
            }
        }
    }
    
}
int main(){
    cin >>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            if(a[i][j]==0) a[i][j]=vc;
        }
    }
    Dijkstra(k);

}
