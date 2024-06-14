#include <iostream>
using namespace std;

int tour[7]; // ####
int n=6;     // ####

bool check(int a[],int q){
	for(int i=0;i<n;i++){
		if(a[i]==q) return false;
	}
	return true;
}

int gst1(int matran[6][6],int x){ //###
	int dem=0,sum=0,i=x,luu,min=999,kiem=0;
	int close[n];
	for(int t=0;t<n;t++) close[t]=-1;
	close[n-1]=x;
	tour[0]=x;
	while(dem<n){
		for(int j=0;j<n;j++){
			if(matran[i][j]==0) continue;
			if(min>matran[i][j] && check(close,j)){
				min = matran[i][j];
				kiem=min;
				luu=j;	
			}
		}
		sum+=kiem;
		i=luu;
		min=999;
		kiem=0;
		tour[dem+1]=luu;
		close[dem]=luu;
		dem++;
	}
	tour[n]=x;
	sum+=matran[luu][x];
	for(int x=0;x<n;x++){
		cout<<tour[x]<<" --> ";
	}
	cout<<tour[n]<<endl;
	return sum;
}
void gst2(int matran[6][6],int p[],int v){//##
	int ketqua[v],j=0,luu=p[0];
	for( int i=0;i<v;i++){
		cout<<endl;
		ketqua[i]=gst1(matran,p[i]);
		cout<<"Chi phi: "<<ketqua[i]<<endl;
	}
	int min=ketqua[0];
	do{
		if(min>ketqua[j]){
			luu=p[j];
			min=ketqua[j];
		}
		j++;
	}while(j<v);
	cout<<endl<<"GST2"<<endl;
	cout<<"Duong di tot nhat: "<<endl;
	ketqua[luu]=gst1(matran,luu);
	cout<<"Chi phi: "<<ketqua[luu]<<endl;
//	cout<<gst1(matran,luu)<<endl;
//	cout<<"Duong di tot nhat:"<<endl;
//	for(int x=0;x<n;x++){
//		cout<<tour[x]<<" --> ";
//	}
//	cout<<tour[n];
}
int main()
{
	int v=4; //###
	int a[4]={4,2,0,3}; //###
	// ######$$$
	int matran[6][6] = { { 0, 20, 42, 31, 6, 24 },
								{ 10, 0, 17, 6, 35, 18 },
								{ 25, 5, 0, 27, 14, 9 },
								{ 12, 9, 24, 0, 30, 12 },
								{ 14, 7, 21, 15, 0, 38},
								{ 40, 15, 16, 5, 20, 0}};
	gst2(matran,a,v);
	return 0;
}
