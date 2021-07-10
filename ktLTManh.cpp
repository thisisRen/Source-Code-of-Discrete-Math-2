#include<bits/stdc++.h>
using namespace std;
int n, a[100][100];
bool chuaxet[100];

void khoitao(){
	for(int i=1; i<=n; i++) chuaxet[i]= true;
}
int BFS(int u){
	khoitao();
	int dem=0;
	queue <int> Qu;
    chuaxet[u]= false;
    Qu.push(u);
    while(!Qu.empty()){
        int s= Qu.front();
        dem++;
        Qu.pop();
        for(int v=1; v<=n; v++){
            if(a[s][v]==1 && chuaxet[v]==true){
                chuaxet[v]=false;
                Qu.push(v);
            }
        }
    }
    return dem;
}
bool DuyetLTM(){
	for(int i=1; i<=n; i++){
		if(BFS(i) != n){
			return false;
			break;
			
		}
	}
	return true;
}
int main(){
	cin >>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >>a[i][j];
		}
	}
	if(DuyetLTM() == true){
		cout <<"strongly connected";
	}
	else{
		cout <<"not strongly connected";
	}
}

