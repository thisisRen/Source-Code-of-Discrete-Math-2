#include <bits/stdc++.h>

using namespace std;

struct edg{
    int h,n1,n2, id;
    
};
class dothi{
    int n,a[100][100], ne, atree[100][100], dh;
    edg edglist[100], edgtree[100];
    public:
    bool chuaxet[100];
    void Init();
    void readdata();
    void kruskal();
    void BBsort();
    void dfs(int t);
  
};
void dothi :: readdata(){
    cin >>n; ne=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >>a[i][j];
            if(a[i][j]>0 && (i<j)){
                ne++;
                edglist[ne].h = a[i][j]; edglist[ne].id = ne;
                edglist[ne].n1 = i; edglist[ne].n2 = j;
            }
        }
    }
}

void dothi :: Init(){
    for(int i=1; i<=n; i++) chuaxet[i]= true;
}
void dothi :: BBsort(){
    for(int i=1; i<=n; i++){
        for(int j=ne; j>=i+1; j--){
            if(edglist[j].h <edglist[j-1].h){
                swap(edglist[j], edglist[j-1]);
            }
        }
    }
}
void dothi :: dfs(int u ){
    chuaxet[u]= false;
    for(int i=1; i<=n; i++){
        if(atree[u][i] ==1 && chuaxet[i]==true) dfs(i);
    }
}
void dothi :: kruskal(){
    int net=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            atree[i][j]=0;
        }
    }
    dh=0;
    BBsort();
    for(int i=1; i<=ne; i++){
        int n1 = edglist[i].n1; int n2 = edglist[i].n2;
        Init(); dfs(n1);
        if(chuaxet[n2]== true){
            dh+= edglist[i].h; net++;
            edgtree[net].n1 =n1 ;
            edgtree[net].n2 = n2;
            atree[n1][n2]=1;
            atree[n2][n1]=1;
        }
    }
    if(net==n-1){
        cout <<" dH = "<<dh <<endl;
        for(int i=1; i<=net; i++){
            cout << edgtree[i].n1 <<" "<<edgtree[i].n2 << endl;
        }
    }
}
int main(){
    dothi g;
    g.readdata();
    g.kruskal();
}
