#include <bits/stdc++.h>
using namespace std;

int n,k,socanh;
int a[100][100];
int tree[100][2];
bool chuaxet[100];

void init(){
    cin >>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >>a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        chuaxet[i]=true;
    }
}
void dfs(int u){
	chuaxet[u]=false;
	if(socanh == n-1) return;
    for(int v=1; v<=n; v++){
        if(a[u][v]==1 && chuaxet[v]==true){
        	chuaxet[v]=false;
        	socanh++;
            tree[socanh][1]=u;
            tree[socanh][2]=v;
            if(socanh==n-1)return;
            dfs(v);
        }
    }
}
void treeDFS(){
    for(int i=1; i<= socanh ; i++){
    	cout <<i<<' ';
    	for(int j=1; j<=2; i++){
    		cout <<tree[i][j]<<endl;
		}
	}
	getch();
}
int main(){
	init();
	socanh=0;
	dfs(k);
	treeDFS();
	getch();
	
}
