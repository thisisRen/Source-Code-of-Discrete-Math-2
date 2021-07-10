#include <bits/stdc++.h>
#include <stack>
#define MAX 100
using namespace std;
class Dothi{
    int n;
    int a[MAX][MAX]; // matranke
    public :
    bool chuaxet[MAX];
    void readdata();
    void init();
    void DFS(int u);
};
void Dothi ::init(){
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
void Dothi :: DFS(int u){
    stack <int> st;
    cout <<u<<" ";
    chuaxet[u]=false;
    st.push(u);
    while(!st.empty()){
        int s= st.top();
        st.pop();
        for(int v=1; v<=n; v++){
            if(a[s][v]==1 && chuaxet[v]==true){
                cout <<v<<" ";
                chuaxet[v]=false;
                st.push(s);
                st.push(v);
                break;
            }
        }
    }
    
}


int main(){
    Dothi G;
    G.init();
    G.readdata();
    G.DFS(1);
}
