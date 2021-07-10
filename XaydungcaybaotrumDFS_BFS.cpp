#include <bits/stdc++.h>
using namespace std;
class dothi{
	int n,k,socanh=0;
  	int a[100][100];
  	public:
    int tree[100][2];
   	bool chuaxet[100];
   	void readdata();
  	void init();
  	void dfs(int t);
    void treeDFS();
    void bfs(int t);
    void treeBFS(int t);
   
};
void dothi ::init(){
    cin >>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >>a[i][j];
        }
    }
}
void dothi :: readdata(){
    for(int i=1; i<=n; i++){
        chuaxet[i]=true;
    }
}
void dothi :: dfs(int u){
	if(socanh == n-1) return;
    for(int v=1; v<=n; v++){
        if(a[u][v]==1 && chuaxet[v]==true){
        	socanh++;
            tree[socanh][1]=u;
            tree[socanh][2]=v;
            if(socanh==n-1)return;
            dfs(v);
        }
    }
}
void dothi :: treeDFS(){
    for(int i=1; i<= socanh ; i++){
    	cout <<i<<' ';
    	for(int j=1; j<=2; i++){
    		cout <<tree[i][j];
		}
	}
}
int main(){
	dothi g;
	g.init();
	g.dfs(k)
	g.treeDFS();
}

