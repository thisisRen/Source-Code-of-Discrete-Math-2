#include<bits/stdc++.h>
using namespace std;
int n, a[100][100];
bool chuaxet[100];

void khoitao(){
	for(int i=1; i<=n; i++) chuaxet[i]= true;
}
int DFS(int u){
	int dem=0;
	stack <int> st;
    chuaxet[u]=false;
    st.push(u);
    dem++;
    while(!st.empty()){
        int s= st.top();
        st.pop();
        for(int v=1; v<=n; v++){
            if(a[s][v]==1 && chuaxet[v]==true){
                dem++;
                chuaxet[v]=false;
                st.push(s);
                st.push(v);
                break;
            }
        }
    }
    return dem;
}
void DuyetTru(){
	khoitao();
	for(int i=1; i<=n; i++){
		chuaxet[i]= false;
		if(i==1){
			if(DFS(2) != n-1) cout << i<<" ";
		}
		else{
			if(DFS(1) != n-1) cout << i <<" ";
		}
		khoitao();
	}
	
}
int main(){
	cin >>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >>a[i][j];
		}
	}
	DuyetTru();
}

