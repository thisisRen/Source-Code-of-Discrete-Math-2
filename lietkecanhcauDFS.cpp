#include<bits/stdc++.h>
using namespace std;
void FIO(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
}
vector <int> ke[1003];
bool check[1003];
int trace[1003];
int a,b;
vector <pair <int, int> > ans;

void DFS(int u){
	check[u]=true;
	for(int i=0; i<ke[u].size(); i++){
		if(!check[ke[u][i]]){
			trace[ke[u][i]]=u;
			DFS(ke[u][i]);
		}
	}
}
int TPLT(){
	int dem=0;
	for(int i=1; i<=a; i++){
		if(!check[i]){
			dem++;
			DFS(i);
		}
	}
	return dem;
}
void Canhcau(int canh, int res, vector <pair <int,int> > tmp){
	for(int i=0; i< b; i++){
		if(i!=canh){
			ke[tmp[i].first] .push_back(tmp[i].second);
			ke[tmp[i].second] .push_back(tmp[i].first);
		}
	}
	int dem= TPLT();
	if(dem >res){
		if(tmp[canh].first < tmp[canh].second){
			ans.push_back({tmp[canh].first, tmp[canh].second});
		}
		else{
			ans.push_back({tmp[canh].second, tmp[canh].first});
		}
	}
}
void start(){
	for(int i=0; i<1001; i++){
		ke[i].clear();
	}
	for(int i=0; i<1001; i++) check[i]=false;
}
int main(){
	FIO();
	int t;
	cin >>t;
	while(t--){
		start();
		ans.clear();
		cin >>a>>b;
		vector <pair <int,int> > tmp;
		for(int i=0; i<b; i++){
			int u,v; cin >>u>>v;
			tmp.push_back({u,v});
			ke[u].push_back(v);
			ke[v].push_back(u);
		}
		int res = TPLT();
		for(int canh=0; canh <b; canh++){
			start();
			Canhcau(canh,res,tmp);
		}
		sort(ans.begin(), ans.end());
		for(int i=0; i<ans.size(); i++){
			cout << ans[i].first << " "<< ans[i].second<<" ";
		}
		cout <<endl;
	
	}
}

