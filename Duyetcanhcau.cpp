#include <bits/stdc++.h>
#define Max 100
using namespace std;
class Dothi{
    int n;
    int a[Max][Max];
    public:
    bool chuaxet[Max];
    void init();
    void readdata();
    void DequyDFS(int u);
    void duyetcau();
};
void Dothi :: readdata(){
    cin >>n;
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
}
void Dothi :: init(){
    for(int i=1; i<=n; i++){
        chuaxet[i]=true;
    }
}
void Dothi :: DequyDFS(int u){
    chuaxet[u]=false;
    for(int v=1; v<=n; v++){
        if(a[u][v]==1 && chuaxet[v]== true){
            DequyDFS(v);
        }
    }
}
void Dothi :: duyetcau(){
    init();
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(a[i][j]== 1){
                a[i][j]=0;
                a[j][i]=0;
                DequyDFS(1);
                for(int k=1; k<=n; k++){
                    if(chuaxet[k]== true){
                        cout << i<<" "<<j<<endl;
                        break;
                    }
                }
                a[i][j]=1;
                a[j][i]=1;
                init();
            }
        }
    }
}
    
    
int main(){
    Dothi g;
    g.readdata();
    g.duyetcau();
    
}
