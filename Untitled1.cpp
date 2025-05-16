#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
struct LopHocPhan{
	char MaLop[20];
	char tenHocPhan[100];
	int HocPhi;
};
void sapxep(LopHocPhan ds[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
		   if(ds[i].HocPhi>ds[j].HocPhi)
		   swap(ds[i],ds[j]);
	}
}
int chonLopHocPhan(LopHocPhan ds[],int n,int p,LopHocPhan ketQua[]){
	sapxep(ds,n);
	int tong=0,dem=0;
	for(int i=0;i<n;i++){
		if(tong+ds[i].HocPhi<=p){
			ketQua[dem++]=ds[i];
			tong+=ds[i].HocPhi;
		}else{
			break;
		}
	}
	return dem;
}
int bmhSearch(const char*text,const char*pattern){
	int m=strlen(pattern);
	int n=strlen(text);
	if(m>n) return -1;
	int skip[256];
	for(int i=0;i<256;i++) skip[i]=m;
	for(int k=0;k<m-1;k++){
		skip[(unsigned char)pattern[k]]=m-k-1;
	}
	int i=m-1;
	while(i<n){
		int k=0;
		while(k<m&&pattern[m-1-k]==text[i-k]){
			k++;
		}
		if(k==m) return i-m+1;
		i+=skip[(unsigned char)text[i]];
	}
	return -1;
}
int main(){
	LopHocPhan ds[MAX]={
	 {"20243IT604001","Cau truc du lieu",1200000},
	 {"20243IT604000","Mang may tinh",1100000},
	 {"20243IT604002","Thuat toan",0},
	 {"20243IT604005","Hoc may",1400000},
	 {"20243IT604003","Tri tue nhan tao",1300000},
	 {"20243IT604004","An toan thong tin",1500000},
	};	
	int n=6;
	cout<<"CAU 1: Thuat Toan Tham Lam"<<endl;
	int p;
	cout<<"nhap so tien p ban co the chi tra: ";
	cin>>p;
	LopHocPhan ketQua[MAX]; 
	int solop=chonLopHocPhan(ds,n,p,ketQua);
	if(solop==0){
		cout<<"khong the dang ky lop vao voi so tien p = "<<p<<endl;
	
	}else{
		cout<<"Dang ky duoc "<<solop<<"lop hoc phan: "<<endl;
		for(int i=0;i<solop;i++){
		cout<<"Ma lop: "<<ketQua[i].MaLop
		    <<"ten hoc phan: "<<ketQua[i].tenHocPhan
		    <<"hoc phi: "<<ketQua[i].HocPhi<<endl;
	}
}
// cau2
cout<<"cau 2------------"<<endl;
const char pattern[]="20243IT604004";
int dem=0;
for(int i=0;i<n;i++){  
	if(bmhSearch(ds[i].MaLop,pattern)!=-1){
			cout<<"Ma lop: "<<ds[i].MaLop
		    <<"ten hoc phan: "<<ds[i].tenHocPhan
		    <<"hoc phi: "<<ds[i].HocPhi<<endl;
		    dem++;
	}
} 
	if(dem==0){
		cout<<"khong co lop hoc phan IT6044"<<endl;
		
	}else{
		cout<<"tong so lop tim duoc: "<<dem<<endl;
	}
	return 0;
}

