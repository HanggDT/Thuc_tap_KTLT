#include "ClassSV.h"
#include <fstream>
#include <vector>

//doc ds tu file nhi phan
void ReadFile(vector<SinhVien> &dssv){
	SinhVien sv;
	ifstream read("dssv.dat", ios::in | ios::binary);
	while(read.read(reinterpret_cast <char *>(&sv), sizeof(SinhVien))){
		dssv.push_back(sv);
	}
	read.close();
}
//ghi ds ra file nhi phan
void WriteFile(vector<SinhVien> dssv){
	ofstream write("dssv.dat", ios::out | ios::binary);
	write.write(reinterpret_cast<const char*>(&dssv[0]), dssv.size()*sizeof(SinhVien));		//ep doi tuong ve con tro hang ki tu
	write.close();
}
//ghi ds ra file text
void Output(char *filename, vector<SinhVien> dssv){
	FILE *f1;
	int i=1;
	f1=fopen(filename,"wt");
	fprintf(f1,"                    -----------------DANH SACH SINH VIEN-----------------\n");
	fprintf(f1,"---------------------------------------------------------------------------------------------\n");
    fprintf(f1,"|  STT |    MA LOP  |     MA SV    |          HO TEN         |    NGAY SINH    |  DIEM TB   |\n");
   	for (int i = 0; i < dssv.size(); i++)
	{	
		fprintf(f1,"---------------------------------------------------------------------------------------------\n"); 
		fprintf(f1,"|%5.03d | %10s | %12d | %23s | %15s | %10.2f |\n",
					 (i+1), dssv[i].Lop, dssv[i].ID, dssv[i].Name, dssv[i].DOB, dssv[i].Score);
	}
	fprintf(f1,"---------------------------------------------------------------------------------------------\n"); 	
	fclose(f1);	
}


//in danh sach sinh vien
void InDanhSach(vector<SinhVien> dssv, int Color){
	char ascii;
	gotoxy(90,7);
	TextColor(16);
	cout << "--------DANH SACH CO "<< dssv.size() <<" SINH VIEN--------";
	ascii = (char) 205;
	gotoxy(78,9);
	for(int j=1;j<86;j++)
		cout<<ascii;
	cout<<"\n";
	gotoxy(77,9);//dong tren trai 
	cout<<(char) 201;
	gotoxy(163,9);//dong tren phai
	cout<<(char) 187;
	ascii = (char) 209;//ki tu so =.=
	gotoxy(84,9); cout<<ascii;
	gotoxy(77+20,9); cout<<ascii;
	gotoxy(77+20+18,9); cout<<ascii;
	gotoxy(77+20+18+23,9); cout<<ascii;
	gotoxy(77+21+17+23+15,9); cout<<ascii;
	gotoxy(77,10);
	cout.width(6); cout<<"STT";
	ascii = (char) 179;
	cout.width(2); cout<<ascii;
	cout.width(10); cout<<"Ma Lop";
	cout.width(3); cout<<ascii;
	cout.width(15); cout<<"Ma Sinh Vien";
	cout.width(3); cout<<ascii;
	cout.width(16); cout<<"Ho va Ten";
	cout.width(7); cout<<ascii;
	cout.width(12); cout<<"Ngay Sinh";
	cout.width(3); cout<<ascii;
	cout.width(8); cout<<"Diem TB";
	
	if(dssv.size() > 10 || dssv.size() <= 10){
		int current = 1, limit;
		BeginPrint:
		int i = 0, sizePrint = 10;//in ra 10 sinh vien/1 page
		if(dssv.size() <= 10){
			sizePrint = dssv.size();
		}
		printAgain:
		for (i; i < sizePrint; i++){
			gotoxy(78,11+2*(i%10));
			for(int j=1;j<86;j++)
				cout<<(char) 205;//ki tu so =
			ascii = (char) 216;//ki tu so =|=
			gotoxy(84,11+2*(i%10)); cout<<ascii;
			gotoxy(77+20,11+2*(i%10)); cout<<ascii;
			gotoxy(77+20+18,11+2*(i%10)); cout<<ascii;
			gotoxy(77+20+18+23,11+2*(i%10)); cout<<ascii;
			gotoxy(77+21+17+23+15,11+2*(i%10)); cout<<ascii;
			gotoxy(77,10+2*(i%10));
			cout<<(char) 186;		//ki tu 2 so doc ||
			gotoxy(163,10+2*(i%10));
			cout<<(char) 186;
			gotoxy(77,11+2*(i%10));
			cout<<(char) 204;		//ki tu so ||=
			gotoxy(163,11+2*(i%10));
			cout<<(char) 185;		//ki tu so =||
			gotoxy(78,12+2*(i%10));
			ascii = (char) 179;		//ki tu so doc '|'
			cout.width(4); cout<<i+1;
			cout.width(3); cout<<ascii;
			if(Color == 1){
				TextColor(15);
			}
			cout.width(8); cout<<strupr(dssv[i].Lop);
			TextColor(16);
			cout.width(5); cout<<ascii;
			if(Color == 2){
				TextColor(15);
			}
			cout.width(13); cout<<dssv[i].ID;
			TextColor(16);
			cout.width(5); cout<<ascii;
			if(Color == 3){
				TextColor(15);
			}
			cout.width(20); cout<<dssv[i].Name;
			TextColor(16);
			cout.width(3); cout<<ascii;
			if(Color == 4){
				TextColor(15);
			}
			cout.width(12); cout<<dssv[i].DOB;
			TextColor(16);
			cout.width(3); cout<<ascii;
			if(Color == 5){
				TextColor(15);
			}
			cout.width(7); cout.precision(2);cout<<fixed<<dssv[i].Score;		//set dang float co 2 chu so thap phan
			TextColor(16);
		}
		int PositionEnd = 2*(sizePrint);
		if(i > 9){
			PositionEnd = 2*(sizePrint - 10*(current-1));
		}
		gotoxy(78,11+PositionEnd);
		for(int j=1;j<87;j++)
			cout<<(char) 205;
		ascii = (char) 207;		//ki tu phan bang duoi =`=
		gotoxy(84,11+PositionEnd); cout<<ascii;
		gotoxy(77+20,11+PositionEnd); cout<<ascii;
		gotoxy(77+20+18,11+PositionEnd); cout<<ascii;
		gotoxy(77+20+18+23,11+PositionEnd); cout<<ascii;
		gotoxy(77+21+17+23+15,11+PositionEnd); cout<<ascii;
		cout<<"\n";
		gotoxy(77,11+PositionEnd);cout<<(char) 200;gotoxy(163,11+PositionEnd);cout<<(char) 188;
		gotoxy(77,10+PositionEnd);cout<<(char) 186;gotoxy(163,10+PositionEnd);cout<<(char) 186;
		
		// hien thi number trang hien tai
		if(dssv.size() % 10 != 0){
			limit = dssv.size()/10 +1;
		}
		else{
			limit = dssv.size()/10;
		}
		gotoxy(80, 33);
		cout<<"Page: "<<current<<"/"<<limit;
		
		// hien thi cac tuy chon button
		gotoxy(80,35);
		cout<<"NextPage: DownArrow       PreviousPage: UpArrow       Escape: Esc";
		int key;// tinh nang cuon trang khi an phim len xuong
		do{
			key = getch();
			if(key == 80){//Down Arrow
				if(current == limit){//cuoi ds <=> current == limit
					gotoxy(80,37);
					cout<<"Cuoi danh sach !!!";
					Sleep(2000);
					xoadong(80,37,20,1);
					break;
				}
				xoabang1(77, 2, 163-77+1, 12*2);
				gotoxy(0,0);
				if(dssv.size()%10 != 0 && current+1 == limit){//neu ds khong du 10sv va dang o trang ke cuoi
					sizePrint += dssv.size()%10;//tang sizePrint len so du dssv.size()/10;
				}
				else{
					sizePrint += 10;//tang sizePrint len 10 don vi;	
				}
				current++;//tang chi so page hien tai len 1 don vi
				goto printAgain;
			}
			else{
				if(key == 72){//Up Arrow
					if(current > 1){
						if(current == 2){//neu la trang thu 2 thi reset ve trang dau
							i = 0;
						}
						else{
								if(current == limit){
									i -= 10 + dssv.size()%10;//neu la trang cuoi
								}
								else{
									i -= 20;//khong thi giam i xuong 20 don vi								
								}
						}
					}
					else{
						if(current <= 1){//i <10 thi la trang dau danh sach
							gotoxy(80,37);
							cout<<"Dau danh sach !!!";	
							Sleep(2000);
							xoadong(80,37,20,1);
							break;
						}
					}
					if(dssv.size()%10 != 0 && current == limit){//neu ds khong du 10sv va dang o trang cuoi
						sizePrint -= dssv.size()%10;//giam sizePrint xuong so du dssv.size()/10;
					}
					else{
						sizePrint -= 10;//giam sizePrint xuong 10 don vi;	
					}
					current--;//giam chi so page hien tai xuong 1 don vi
					xoabang1(77, 2, 163-77+1, 12*2);
					gotoxy(0,0);
					goto printAgain;
				}
			}
		}
		while(key != 27);
	}
	xoadong(80,33,15,1);//xoa dong hien thi page
	xoadong(80,35,65,1);//xoa dong hien thi chuc nang button
	xoadong(90, 7, 39+5, 1);
	xoabang1(77, 0, 88, 12*2);//xoa bang da in ra
	TextColor(16);
}
