#include "IOPrintFile.h"
#include "List.h"
#include <vector>


//them ho so
void ThemHoSo(SinhVien &sv){
	kebang(77,0,5,70);
	for(int z = 0; z < 5; z++){
		gotoxy(79,10+2*z);
		printf("%s",sinhvien[z]);
		cout<<"\n";
	}
	for (int j=1; j<6;j++){
 		gotoxy(16+80,8+2*j);
		cout<<(char) 186;
	}		
	gotoxy(100,10);sv.NhapClass();
	gotoxy(100,12);sv.NhapID();
	gotoxy(100,14);sv.NhapName();	
	gotoxy(100,16);sv.NhapDOB();
   	gotoxy(100,18);sv.NhapScore();
   	gotoxy(100,1);TextColor(16);cout<<sv.Name<<" da luu !\n";
   	Sleep(2000);
   	TextColor(16);
   	xoadong(100,1,strlen(sv.Name)+9,1);
   	xoabang1(77, 0, 71, 5);
}
//xoa ho so
void XoaSV(vector<SinhVien> &dssv){
	InDanhSach(dssv, 0);
	int stt;
	cout<<endl;
	gotoxy(36, 19);
	cout<<"Nhap stt sinh vien can xoa: ";
	cin>>stt;
	if(stt <= dssv.size() && stt > 0){
		xoadong(90, 7, 39+5, 1);
		xoabang1(77, 0, 163-77+1 ,dssv.size()*2);
		dssv.erase(dssv.begin()+(stt-1)); //xoa cac ki tu khoi chuoi va de trong no
		
		InDanhSach(dssv, 0);	
		gotoxy(36, 19);		
		cout<<"Da xoa sinh vien thanh cong"<<endl;
	}
	else{
		gotoxy(36, 19);
		cout<<"Khong ton tai sinh vien stt "<<stt<<endl;
	}
	Sleep(2000);	
	xoadong(36, 19, 28+4, 1);
}
//sua ho so
void SuaSV(vector<SinhVien> &dssv){
	InDanhSach(dssv, 0);
	int stt;
	cout<<endl;
	gotoxy(36, 19);
	cout<<"Nhap stt sinh vien can sua: ";
	cin>>stt;
	if(stt <= dssv.size() && stt > 0){
		xoadong(90, 7, 39+5, 1);
		xoabang1(77, 0, 163-77+1 ,dssv.size()*2);
		ThemHoSo(dssv.at(stt-1));
		InDanhSach(dssv, 0);	
		gotoxy(36, 19);		
		cout<<"Da sua sinh vien thanh cong"<<endl;
	}
	else{
		gotoxy(36, 19);
		cout<<"Khong ton tai sinh vien stt "<<stt<<endl;
	}
	Sleep(2000);	
	xoadong(36, 19, 28+4, 1);
}
