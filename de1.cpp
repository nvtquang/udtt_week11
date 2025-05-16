#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
struct CanRuou{
	char nhanHieu[50];
	int dungTich;
	long giaTri;
};
bool compareByPrice(CanRuou a, CanRuou b){
	return a.giaTri<b.giaTri;
}
int thuatToanA(CanRuou ds[], int n, int m, CanRuou ketQua[]){
	int tong=0,dem=0;
	for(int i=0;i<n;i++){
		if(tong+ds[i].giaTri<=m){
			ketQua[dem++]=ds[i];
			tong+=ds[i].giaTri;
		}else{
			break;
		}
	}
	return dem;
}

int main(int argc, char** argv){
	CanRuou ds[100] = {
	{"Vang Phap", 2 , 1200000},
	{"Vang Trung", 2 , 1100000},	
	{"Vang Viet", 2 , 1000000},
	{"Vang Nga", 2 , 1000000},	
	{"Vang My", 2 , 900000},
	{"Vang Thai", 2 , 800000},		
	};
	int n = 6;
	int m;
	sort(ds,ds+n,compareByPrice);
	cout<<"Nhap so tien: ";
	cin>>m;
	CanRuou ketQua[100];
	int sochai = thuatToanA(ds,n,m,ketQua);
	if(sochai == 0){
		cout<<"Khong the mua duoc can ruou nao!";
		cout<<endl;
	}else{
		cout<<"Mua duoc "<<sochai<<" can ruou!"<<endl;
		for(int i = 0; i < sochai; i++){
			cout<<"Nhan hieu: " <<ketQua[i].nhanHieu<<endl;
			cout<<"Gia tri: "<<ketQua[i].giaTri<<endl;
			cout<<"======================"<<endl;
		}
	}
}