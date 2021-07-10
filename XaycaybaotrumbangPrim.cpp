#include <bits/stdc++.h>
using namespace std;

struct edg{ int id, u, v;};
class dothi{
  int n, start, dH, ne;
  int a[100][100];
  bool chuaxet[100], Vtree[100];
  edg edglist[100], edgtree[100];
  public:
  void init();
  void readdata();
  void Sort();
  void Prim();
};

void dothi :: readdata(){
    cin >>n>>start;
    ne=0; //so canh cua do thi
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >>a[i][j];
            if(a[i][j]> 0 && i<j){
                ne++;
                edglist[ne].u=i;
                edglist[ne].v=j;
                edglist[ne].id= a[i][j];
            }
        }
    }
}
void dothi:: init(){
    for(int i=1; i<=n; i++){
        chuaxet[i]=true;
        Vtree[i]=0;
    }
}
void dothi ::Sort(){
    for(int i=1; i<=n; i++){
        for(int j= ne ; j >= i+1 ; j--){
            if(edglist[j-1].id > edglist[j].id){
                swap(edglist[j-1] , edglist[j]);
            }
        }
    }
}
void dothi :: Prim(){
    init();
    Vtree[start]=1;
    chuaxet[start]=false;
    dH=0;
    int net =0; // so canh cua cay
    Sort();
    while(net < n-1){
        int u,v,id;
        for(int i=1; i<=ne; i++){
            u= edglist[i].u;
            v= edglist[i].v;
            id= edglist[i].id;
            if(chuaxet[u] == true&& Vtree[v]== 1){
                net++;
                edgtree[net].u= u;
                edgtree[net].v=v;
                dH+=id;
                Vtree[u]=1;
                chuaxet[u]=false;
                break;
            }
            else if(chuaxet[v]==true && Vtree[u]==1){
                net++;
                edgtree[net].u = u;
                edgtree[net].v = v;
                dH+=id;
                Vtree[v]=1;
                chuaxet[v]=false;
                break;
            }
        }
    }
    if(net== n-1){
        cout <<"dH = "<<dH<<endl;
        for(int i=1; i<=net; i++){
            cout << edgtree[i].u << " "<< edgtree[i].v<<endl;
        }
    }
}   
int main(){
    dothi g;
    g.readdata();
    g.Prim();
    return 0;
}

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

