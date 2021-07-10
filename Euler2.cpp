#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100][100];
bool chuaxet[100];
void Init(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >>a[i][j];
		}
	}
}
void Euler(int u){
	stack<int>st;
    vector<int>CE;
    
    st.push(u);
    while(st.size()){
        u = st.top();
        int v = 0;
        for(int i=1;i<=n;i++){
            if(a[u][i] == 1 && a[i][u] == 1){
                v = i; 
                break;
            }
        }
        if(v){
            st.push(v);
            a[u][v] = 0;
            a[v][u] = 0;
        }
        else{
            CE.push_back(u);
            st.pop();
        }
    }
    for(int i=CE.size()-1;i>=0;i--) cout << CE[i] << ' ';
    cout << endl;
}

int main(){
	cin>>n>>k;
	Init();
	Euler(k);
}
	
