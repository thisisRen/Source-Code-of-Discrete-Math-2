#include<iostream>

using namespace std;

#define MAX 100

class dothi{
    int n,A[MAX][MAX];
    
    public:
    bool chuaxet[MAX];
    int X[MAX];
    void read();
    void init();
    void hmt(int k);
    
};

void dothi::read(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> A[i][j];
        }
    }
}

void dothi::init(){
    for(int i=1;i<=n;i++) chuaxet[i] = true;
    X[1] = 1;
    chuaxet[X[1]] = false;
}

void dothi::hmt(int k){
    for(int y=1; y<=n;y++){
        if(A[X[k-1]][y] == 1){          // y ke voi X[k-1]
            if(k == n+1 && y == X[1]){
                cout << endl;
                for(int i=1;i<=n;i++){
                    cout << " " << X[i];
                }
                cout << " " << X[1];
            }
            else{
                if(chuaxet[y] == true){
                    X[k] = y;
                    chuaxet[y] = false;
                    hmt(k+1);
                    chuaxet[y] = true;
                }
            }
        }
    }
}

int main(){
    dothi G;
    G.read();
    G.init();
    G.hmt(2);
    
    
    return 0;
}