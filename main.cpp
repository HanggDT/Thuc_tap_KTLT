#include "ThongKe.h"

//luu ten file
void ReNameFile(vector<SinhVien> dssv){
	int capRen = 3, vitriRen = 1, lenRename = 2;
	cout<<"\n\tBan co muon dat ten file xuat ra?"<<endl;
	kebang(capRen - 1, 0, lenRename, 25);
	dieukhiencontro(capRen, vitriRen, Rename, lenRename);
	switch(vitriRen){
		case 1:{
			cout<<endl;
			cout<<"\n \tDien ten file ban muon luu dssv (*.txt): ";
			char ListFName[50];
			gets(ListFName);
			Output(ListFName, dssv);
			break;
		}
		case 2:{
			break;
		}
	}	
}
//ham menu
void Menu()
{
	system("color 3F");
	TextColor(16);
	SinhVien sv;
	vector<SinhVien> dssv;
	ReadFile(dssv);
	again: 			//nhan dan de menu quay tro lai
	int vitri = 1;
	
	gotoxy(32,0); cout<<"+----------------------------------------+";
	gotoxy(32,1); cout<<"|       THUC TAP KY THUAT LAP TRINH      |";
	gotoxy(32,2); cout<<"+----------------------------------------+";
	gotoxy(32,3); cout<<"|        ->> QUAN LY SINH VIEN <<-       |";
	gotoxy(32,4); cout<<"+----------------------------------------+";
	
	gotoxy(4, 7); cout<<"Dung phim mui ten va enter de lua chon."<<endl;
	int cap1 = 2, lenmenu = 6;
	kebang(cap1 - 1, vitri - 1, lenmenu, 31);
	dieukhiencontro(cap1, vitri, menu, lenmenu);
	
	switch(vitri)// ham xu ly tung chuc nang duoc chon trong menu
	{
	case 1:	again1:	//chuc nang cap nhat ho so cho sinh vien
	{
		int vitri1 = 1, cap2 = 34, lencn = 4;		
		kebang(cap2 - 1, vitri1 - 1, lencn, 29);
		dieukhiencontro(cap2, vitri1, hoso, lencn);
		switch(vitri1)
		{
			case 1:	// them ho so sinh vien
			{
				cursortype();
				ThemHoSo(sv);
				dssv.push_back(sv);
				goto again1;
				break;
			}
			case 2:	// sua ho so sinh vien
			{
				SuaSV(dssv);
				goto again1;
				break;
			}	
			case 3:	// xoa ho so sinh vien
			{
				XoaSV(dssv);
				goto again1;
				break;
			}
			case 4:	// tro lai
			{
				system("cls");
				goto again;
				break;
			}
		}		
		break;
	}
	case 2:	// chuc nang in danh sach sinh vien
	{
		int vitri2 = 3;
		InDanhSach(dssv, 0);
		WriteFile(dssv);
		system("cls");
		goto again;
		break;
	}
	case 3:	again3:	// chuc nang sap xep danh sach sinh vien
	{
		int vitri3 = 5, cap2 = 34, lensx = 5;
		kebang(cap2 - 1, vitri3 -1, lensx, 29);
		
		dieukhiencontro(cap2, vitri3, sapxep, lensx);
		switch(vitri3)
		{
			case 1:	again31:// sap xep chon theo cac truong khoa
			{
				int vitri31 = 5, cap3 = 66, lensv = 6;
				kebang(cap3 - 1, vitri31 - 1, lensv, 29);
				dieukhiencontro(cap3, vitri31, sinhvien, lensv);
				xoabang(cap3, 5, lensv);
				if(vitri31 != 6){
					Selection_Sort( dssv, vitri31 );
					InDanhSach(dssv, 0);
					goto again31;
				}
				else{
					goto again3;
				}
				break;
			}
			case 2:	again32:// sap xep chen theo cac truong khoa
			{
				int vitri32 = 7, cap3 = 66, lensv = 6;
				kebang(cap3 - 1, vitri32 - 1, lensv, 29);
				dieukhiencontro(cap3, vitri32, sinhvien, lensv);
				xoabang(cap3, 7, lensv);
				if(vitri32 != 6){
					Insertion_Sort(dssv, vitri32);
					InDanhSach(dssv, 0);
					goto again32;					
				}
				else{
					goto again3;
				}
			}
			case 3:	again33://sap xep noi bot theo cac truong khoa
			{
				int vitri33 = 9, cap3 = 66, lensv = 6;
				kebang(cap3 - 1, vitri33 - 1, lensv, 29);
				dieukhiencontro(cap3, vitri33, sinhvien, lensv);
				xoabang(cap3, 9, lensv);
				if(vitri33 != 6){
					Bubble_Sort(dssv, vitri33);
					InDanhSach(dssv, 0);
					goto again33;
				}
				else{
					goto again3;
				}
			}
			case 4:	again34:// sap xep nhanh theo cac truong khoa
			{
				
				int vitri34 = 11, cap3 = 66, lensv = 6;
				kebang(cap3 - 1, vitri34 - 1, lensv, 29);
				dieukhiencontro(cap3, vitri34, sinhvien, lensv);
				xoabang(cap3, 11, lensv);
				if(vitri34 != 6){
					Quick_Sort(dssv, 0, dssv.size() - 1, vitri34);
					InDanhSach(dssv, 0);
					goto again34;
				}
				else{
					goto again3;
				}
				break;
			}
			case 5:// tro lai
			{
				system("cls");
				goto again;
				break;
			}
		}
		break;
	}
	case 4:again4:	// chuc nang tim kiem
	{
		int vitri4 = 7, cap2 = 34, lentk =3;
		kebang(cap2 - 1, vitri4 - 1, lentk, 29);
		dieukhiencontro(cap2, vitri4, timkiem, lentk);
		switch(vitri4)
		{
			case 1:	again41:		// tim kiem tuan tu
			{
				int vitri41 = 7, cap3 = 66, lensv = 6;
				kebang(cap3 - 1, vitri41 - 1, lensv, 29);
				dieukhiencontro(cap3, vitri41, sinhvien, lensv);
				switch(vitri41)
				{
					case 1:			// tim kiem theo ma lop
					{
						xoabang(cap3, 7, lensv);
						LinearSearch(dssv, 1);
						goto again41;
						break;
					}
					case 2:			// tim kiem theo ma sinh vien
					{
						xoabang(cap3, 7, lensv);
						LinearSearch(dssv, 2);
						goto again41;
						break;
					}	
					case 3:			// tim kiem theo ten sinh vien
					{
						xoabang(cap3, 7, lensv);
						LinearSearch(dssv, 3);
						goto again41;
						break;
					}
					case 4:			// tim kiem theo ngay sinh
					{
						xoabang(cap3, 7, lensv);
						LinearSearch(dssv, 4);
						goto again41;
						break;
					}
					case 5:			// tim kiem theo diem trung binh tich luy
					{
						xoabang(cap3, 7, lensv);
						LinearSearch(dssv, 5);					
						goto again41;
						break;
					}
					case 6:			//tro lai
					{
						xoabang(cap3, 7, lensv);
						goto again4;
						break;
					}
				}
				break;
			}
			case 2:	again42:		// tim kiem nhi phan
			{
				int vitri42 = 9, cap3 =66, lensv = 6;
				kebang(cap3 - 1, vitri42 - 1, 6, 29);
				dieukhiencontro(cap3, vitri42, sinhvien, lensv);
				switch(vitri42)
				{					
					case 1:			// tim kiem theo ma lop
					{
						
					}
					case 2:			// tim kiem theo ma sinh vien
					{
						
						
					}	
					case 3:			// tim kiem theo ten sinh vien
					{
						
						
					}
					case 4:			// tim kiem theo ngay sinh
					{
						
						
					}
					case 5:			// tim kiem theo diem trung binh tich luy
					{
						xoabang(cap3, 9, lensv);
						Quick_Sort(dssv, 0, dssv.size()-1, vitri42);
						vector<SinhVien> result, svp(dssv);
						kebang(77,1,1, 30);
						char Keyword[50];
						gotoxy(78,11);
						cout<<"Nhap keyword: ";
						fflush(stdin);
						gets(Keyword);					
						int i;
						while(BinarySearch(svp, 0, svp.size(), Keyword, vitri42)>=0){
							i=BinarySearch(svp, 0, svp.size(), Keyword, vitri42);
							result.push_back(svp[i]);
							svp.erase(svp.begin()+i);
						}
						xoabang1(77, 1, 30, 1);
						if(result.empty()){								
							gotoxy(90,5);
							cout<<"Khong tim thay ket qua cho: ";
							TextColor(15);
							cout<<Keyword;
							TextColor(16);
							cout<<" !!!";
							Sleep(2000);
							xoadong(90, 5, 47+strlen(Keyword), 1);
						}else{
							gotoxy(90,5);
							cout<<"Ket qua tim kiem: "; 
							TextColor(15);
							cout<<Keyword;
							TextColor(16);
							cout<<" : ";
							InDanhSach(result, vitri42);
							xoadong(90, 5, 37+strlen(Keyword), 1);
						}
						goto again42;
					}
					case 6:			//tro lai
					{
						xoabang(cap3, 9, lensv);
						goto again4;
						break;
					}
				}
				break;
			}
			case 3:			// tro lai
			{
				system("cls");
				goto again;
				break;
			}
		}
		break;
	}
	case 5:	again5:	// thong ke 
	{
		int vitri5 = 9, cap2 = 34, lentk =3;
		kebang(cap2 - 1, vitri5 - 1, lentk, 29);
		dieukhiencontro(cap2, vitri5, thongke, lentk);
		switch(vitri5){
			case 1:
			{
				Thongke(dssv, 1);
				break;
			}
			case 2:
			{
				Thongke(dssv, 2);
				break;
			}
			case 3:
			{
				system("cls");
				goto again;
				break;
			}
		}
		goto again;
		break;
	}
	case 6:		// thoat
		break;
	}
	WriteFile(dssv);
	system("cls");
	ReNameFile(dssv);
}

int main() {
	//Buoc console mo full screen
	system("mode 550");
	MoveCenter();
	Menu();
}
