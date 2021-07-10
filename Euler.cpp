#include<iostream>
#include<stack>
#include<vector>

using namespace std;
#define MAX 100
class DoThi{
    int n;
    int A[MAX][MAX];
    
    public:
    int u;
    
    void readData();
    void init();
    void Euler(int u);
    
};

void DoThi::readData(){
    cin >> n >> u;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> A[i][j];
        }
    }
}

void DoThi::init(){
    
}

void DoThi::Euler(int u){
    stack<int>st;
    vector<int>CE;
    
    st.push(u);
    while(st.size()){
        u = st.top();
        int v = 0;
        for(int i=1;i<=n;i++){
            if(A[u][i] == 1 && A[i][u] == 1){
                v = i; 
                break;
            }
        }
        if(v){
            st.push(v);
            A[u][v] = 0;
            A[v][u] = 0;
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
    DoThi G;
    G.readData();
    G.Euler(G.u);

    return 0;
}