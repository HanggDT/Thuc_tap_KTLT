#include "TimKiem.h"
#include <vector>
#include <iomanip>

vector<SinhVien> setMaLop(vector<SinhVien> dssv){
	vector<SinhVien> dsLop;
	int count = 0;
	for(int i = 0; i < dssv.size(); i++){
		for(int j = 0; j < dsLop.size(); j++){
			if(strcmp(dssv[i].Lop, dsLop[j].Lop) == 0 )
			    count ++;
		}
		if(count == 0)
		    dsLop.push_back(dssv[i]);
		count = 0;
	}
	Bubble_Sort(dsLop, 1);
	return dsLop;
}

int demSinhVien(vector<SinhVien> dssv, vector<SinhVien> dsLop, int vitriLop){
    int count = 0;
    for(int i = 0; i < dssv.size(); i++){
	    if(strcmp(dssv[i].Lop, dsLop[vitriLop].Lop) == 0)
	       	count++;
	}
    return count;
}

int demTheoHocLuc(vector<SinhVien> dssv, vector<SinhVien> dsLop, int vitriLop,int a){
    int count = 0;
    switch (a) {
    case 1: //dem theo hoc sinh xuat sac
        {
            for (int i = 0; i < dssv.size(); i++) {
                if (strcmp(dssv[i].Lop, dsLop[vitriLop].Lop) == 0 && dssv[i].Score >= 9)
                    count++;
            }
            break;
        }
    case 2: //dem theo hoc sinh gioi
        {
            for (int i = 0; i < dssv.size(); i++) {
                if (strcmp(dssv[i].Lop, dsLop[vitriLop].Lop) == 0 && dssv[i].Score >= 8 && dssv[i].Score < 9)
                    count++;
            }
            break;
        }
    case 3: //dem theo hoc sinh kha
        {
            for (int i = 0; i < dssv.size(); i++) {
                if (strcmp(dssv[i].Lop, dsLop[vitriLop].Lop) == 0 && dssv[i].Score >= 6 && dssv[i].Score < 8)
                    count++;
            }
            break;
        }
    case 4: //dem theo hoc sinh trung binh
        {
            for (int i = 0; i < dssv.size(); i++) {
                if (strcmp(dssv[i].Lop, dsLop[vitriLop].Lop) == 0 && dssv[i].Score >= 5 && dssv[i].Score < 6)
                    count++;
            }
            break;
        }
    case 5: //dem theo hoc sinh yeu
        {
            for (int i = 0; i < dssv.size(); i++) {
                if (strcmp(dssv[i].Lop, dsLop[vitriLop].Lop) == 0 && dssv[i].Score < 5)
                    count++;
            }
            break;
        }
    }
    return count;
}

void Thongke(vector<SinhVien> &dssv, int Pointer){
	switch (Pointer) {
	case 1:
	    {
	    	system("cls");
	    	cout<<"\n\n\t Press any key to exit tab";
	    	vector<SinhVien> dsLop = setMaLop(dssv);
			int number, sum,
				current = 1,
				limit, 
				i = 0, sizePrint = 10,		//in ra 10 sinh vien/1 page
				vitriin = 10;
			  
			if(dsLop.size() <= 10){
				sizePrint = dsLop.size();
			}
			
			
			printAgain:
				
			char ascii = (char) 205;
			gotoxy(vitriin+1,9);
			for(int j=1;j<27;j++)
				cout<<ascii;
			cout<<"\n";
			gotoxy(vitriin,9);		//dong tren trai 
			cout<<(char) 201;
			gotoxy((vitriin)+27,9);		//dong tren phai
			cout<<(char) 187;
			ascii = (char) 209;		//ki tu so =.=
			gotoxy((vitriin)+11,9); cout<<ascii;
			gotoxy(vitriin,10);
			cout.width(10); cout<<"Ma Lop";
			ascii = (char) 179;
			cout.width(2); cout<<ascii;
			cout.width(10); cout<<"So Luong";

			sum = 0, number = 0;
			for (i; i < sizePrint; i++){
				number = demSinhVien(dssv, dsLop, i);
				sum += number;
				
				gotoxy((vitriin)+1,11+2*(i%10));
				for(int j=1;j<27;j++)
					cout<<(char) 205;		//ki tu so =
				ascii = (char) 216;		//ki tu so =|=
				gotoxy((vitriin)+11,11+2*(i%10)); cout<<ascii;
				gotoxy(vitriin,10+2*(i%10));
				cout<<(char) 186;		//ki tu 2 so doc ||
				gotoxy((vitriin)+27,10+2*(i%10));
				cout<<(char) 186;
				gotoxy(vitriin,11+2*(i%10));
				cout<<(char) 204;		//ki tu so ||=
				gotoxy((vitriin)+27,11+2*(i%10));
				cout<<(char) 185;		//ki tu so =||
				gotoxy((vitriin)+1,12+2*(i%10));
				ascii = (char) 179;		//ki tu so doc '|'
				cout.width(8); cout<<strupr(dsLop[i].Lop);
				cout.width(3); cout<<ascii;
				cout.width(8); cout<<number;
			}
			int PositionEnd = 2*(sizePrint);
			if(i > 9){
				PositionEnd = 2*(sizePrint - 10*(current-1));
			}
			gotoxy((vitriin)+1,11+PositionEnd);
			for(int j=1;j<27;j++)
				cout<<(char) 205;
			ascii = (char) 207;		//ki tu phan bang duoi =`=
			gotoxy((vitriin)+11,11+PositionEnd); cout<<ascii;
			cout<<"\n";
			gotoxy(vitriin,11+PositionEnd);cout<<(char) 200;gotoxy((vitriin)+27,11+PositionEnd);cout<<(char) 188;
			gotoxy(vitriin,10+PositionEnd);cout<<(char) 186;gotoxy((vitriin)+27,10+PositionEnd);cout<<(char) 186;
			
			
	    	gotoxy(vitriin, 12+PositionEnd);
			cout.width(8);
			cout<<"-> Tong";
			cout.width(12);
			cout<< sum<<" sv";
			
			// hien thi number trang hien tai
			if(dssv.size() % 10 != 0){
				limit = dsLop.size()/10 +1;
			}
			else{
				limit = dsLop.size()/10;
			}
			gotoxy((vitriin)+3, 34);
			cout<<"Page: "<<current<<"/"<<limit;
			
	    	
			
			if(dsLop.size()%10 != 0 && current+1 == limit){		//neu ds khong du 10sv va dang o trang ke cuoi
				sizePrint += dsLop.size()%10;		//tang sizePrint len so du dsLop.size()/10;
			}
			else{
				sizePrint += 10;		//tang sizePrint len 10 don vi;	
			}
			current++;			//tang chi so page hien tai len 1 don vi
			if(current <= limit){		//chua phai page cuoi thi con in tiep
				vitriin += 35;
				goto printAgain;
			}
			
			getch();
			system("cls");
			break;
		}
	case 2:
	    {
	        vector<SinhVien> dsLop = setMaLop(dssv);
			char Key[50];
			int maLop;
			kebang(77,1,1, 30);
			gotoxy(78,11);
			cout<<"Nhap ten lop: ";
			gets(Key);
	        for(int i=0;i<dsLop.size();i++){
		    	if(strstr(dsLop[i].Lop, Key) != NULL){
		    		maLop = i;
		    		break;
				}
				else
					maLop = -1;
			}
			xoabang1(77, 1, 30, 1);
			if(maLop == -1){
				gotoxy(90,5);
				cout<<"--------Khong tim thay lop: ";
				TextColor(15);
				cout<<Key;
				TextColor(16);
				cout<<" !!!-------";
				Sleep(2000);
				xoadong(90, 5, 47+strlen(Key), 1);
			}else{
				kebang(77,4,4,76);
				int
					hsxs, hsg, hsk, hstb, hsy,
		        	tong = demSinhVien(dssv, dsLop, maLop);
		        int u = 12;
		        
	            hsxs = demTheoHocLuc(dssv, dsLop, maLop, 1);
	            
	            hsg = demTheoHocLuc(dssv, dsLop, maLop, 2);
	            
	            hsk = demTheoHocLuc(dssv, dsLop, maLop, 3);
	            
	            hstb = demTheoHocLuc(dssv, dsLop, maLop, 4);
	            
	            hsy = demTheoHocLuc(dssv, dsLop, maLop, 5);
	            
	            gotoxy(79, 9+5);
	            cout.width(20);
	            cout<<"Lop "<<strupr(dsLop[maLop].Lop)<<" co: "<<tong<<" sinh vien";	//strupr : chuyen ki tu thuong sang in hoa
	            
	            gotoxy(79, 9+7);
	            cout.width(22);
				cout<<"Xuat sac";
				cout<<setw(u)<<"Gioi"<<setw(u)<<"Kha"<<setw(u+2)<<"Trung binh"<<setw(u-2)<<"Yeu";
				
				gotoxy(79, 9+9);
				cout<<"So luong: ";
				cout<<setw(u)<<hsxs<<setw(u)<<hsg<<setw(u)<<hsk<<setw(u)<<hstb<<setw(u)<<hsy;
				
				gotoxy(79, 9+11);
				cout.precision(2);cout<<fixed;
				cout<<"Ti le (%):"<<setw(u)<<(float) hsxs * 100 / tong<<setw(u)<<(float) hsg * 100 / tong<<setw(u)<<(float) hsk * 100 / tong<<setw(u)<<(float) hstb * 100 / tong<<setw(u)<<(float) hsy * 100 /tong;
				
				
			}
			
	        getch();
	        system("cls");
			break;
	    }
	}
}
