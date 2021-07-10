#include<bits/stdc++.h>
using namespace std;
int n,k, a[100][100], b[100];
bool chuaxet[100];
int dem=0;

void inPut(){
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; i++){
			cin >>a[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		chuaxet[i]= true;
	}
}

void Output(){
	for(int i=n; i>=1; i++){
		cout << b[i]<<" ";
	}
	dem++;
	cout <<endl;
}

void Hamilton(int *b, int *chuaxet, int i){ 
	int j, k; 
	for(j=1; j<=n; j++){ 
		if(a[b[i-1]][j]==1 && chuaxet[j]==0){ 
			b[i]=j; chuaxet[j]=1; 
			if(i<n) Hamilton(b, chuaxet, i+1); 
			else
				if(b[i]==b[0]) Result(); 
				chuaxet[j]=0; 

		} 

	} 

} 
int main(){
	b[0]=1; 
	int i=1;
	d=0;
	Init(); 
	Hamilton(b,chuaxet,i); 
	if(d==0) 
		cout<<"Khong co chu trinh Hamilton"; 

} 


