#include "Console.h"


class SinhVien{
	public:
		char Lop[50];
		int ID;
		char Name[50];
		char DOB[50];
		int Day, Month, Year;
		float Score;
		
		SinhVien();
		SinhVien(char Lop[50], int ID, char Name[50], char DOB[50], float Score);
		void NhapClass();
		void NhapID();
		void NhapName();
		bool TestNgaySinh(int Ngay, int Thang, int Nam);
		void NhapDOB();
		void NhapScore();
		
		//Ham thuoc tinh
		char getLop();
		void setLop(char Lop[50]);
		char getName();
		void setName(char Name[50]);
		int getID();
		void setID(int ID);
		char getDOB();
		void setDOB(char DOB[50]);
		float getScore();
		void setScore(float Score);
};

//ham khoi tao sinh vien khong co tham so
SinhVien::SinhVien(){
	this->Lop[50] = {0};
	this->ID = ID;
	this->Name[50] = {0};
	this->Score = Score;
	this->DOB[50] = {0};
}
//ham khoi tao sinh vien co tham so day du	
SinhVien::SinhVien(char Lop[50], int ID, char Name[50], char DOB[50], float Score){
	this->Lop[50] = Lop[50];
	this->ID = ID;
	this->Name[50] = Name[50];
	this->Score = Score;
	this->DOB[50] = DOB[50];
}

//cac ham nhap thuoc tinh cua SV
//nhap ma lop
void SinhVien::NhapClass(){
	malop://nhan dan 
	gotoxy(100,10);
	cin.getline(this->Lop, 50, '\n'); 
	if(strlen(this->Lop) == 0)
		goto malop;
}

//nhap ma Sinh Vien
void SinhVien::NhapID(){

	int n, len = 0;
	char s[20] = {0};
	do{
		n = getch();
		if(n >= '0' && n <= '9' && len < 8){
			putch(n);
			s[len++] = n;
		}     
		if(n == '\b' && len > 0){
			cout<<"\b \b";
			s[--len] == 0;
		}
	}
	while(len < 8 || n != 13);
	this->ID = atoi(s);  //ham atoi = a to int , chuyen doi mot chuoi duoc tro toi boi tham so str thanh mot so nguyen
}


//nhap Ho ten
void SinhVien::NhapName(){
	hoten:
	cin.getline(this->Name, 50, '\n');
	if(this->Name == '\0'){
		gotoxy(100,1);
		cout<<"Chua nhap ten, nhap lai"<<endl;
		Sleep(2000);
		xoadong(100,1,50,1);
		gotoxy(100,14);
		goto hoten;
	}
	ChuanHoa(this->Name);
}

//nhap Ngay sinh
bool SinhVien::TestNgaySinh(int Ngay, int Thang, int Nam){
	if(Ngay != NULL){
		if(Nam > 1900 && Nam < 2001){
			if(Thang > 0 && Thang <= 12){
				if(Thang == 2){
					if(Ngay <= 29)
						return true;
				}
				else{
					if(Thang == 1,3,5,7,8,10,12){
						if(Ngay > 0 && Ngay <=31)
							return true;
					}
					else{
						if(Ngay > 0 && Ngay <=30)
							return true;
					}
				}
			}
			else
				return false;
		}
		else{
			return false;
		}
	}
	else
		return false;
};

void SinhVien::NhapDOB(){
	nhapDOB:
		char Ngay[10] = "", Thang[10] = "", Nam[10] = "";
		int k;
		cout<<"dd/mm/yyyy";
		gotoxy(100,16);
		cin.getline(this->DOB, 20, '\n');
		for(int i= strlen(this->DOB) -1; i>=0; i--){
			if(isalpha(this->DOB[i])){
				cout<<endl;
				gotoxy(100,1);
				cout<<"Nhap sai, vui long nhap lai !"<<endl;
				Sleep(2000);
				xoadong(100,1, 50,1);
				xoadong(100,16,20,1);
				gotoxy(100, 16);
				goto nhapDOB;
			}
		}
		for(int i=strlen(this->DOB)-1;i>=0;i--){
			if (this->DOB[i]==47){  
			k=i;
			break;
			}
		}
		strncpy(Ngay,this->DOB+0,2); 	//strncpy	sao chep n ki tu dau tien cua chuoi nguon vao chuoi dich
		strncpy(Thang,this->DOB+3,2); 
		strncpy(Nam,this->DOB+6,strlen(DOB)-6);
		this->Day=atoi(Ngay);	// atoi	chuyen doi mot chuoi duoc tro toi boi tham so sttr thanh mot so nguyen
		this->Month=atoi(Thang);
		this->Year=atoi(Nam);	
	
	if(!TestNgaySinh(this->Day, this->Month, this->Year)){
		cout<<endl;
		gotoxy(100,1);
		cout<<"Nhap sai, vui long nhap lai !"<<endl;
		Sleep(2000);
		xoadong(100,1, 50,1);
		xoadong(100,16,20,1);
		gotoxy(100, 16);
		goto nhapDOB;
	}
}

//nhap diem
void SinhVien::NhapScore(){
	diem:
	int flag = 1;
	char Diem[15];
	cin.getline(Diem, 5);
	if(strlen(Diem) && Diem[0] != '\0'){
		for(int i = 0; i < strlen(Diem); i++){
			if(isalpha(Diem[i])){	//isalpha	kiem tra xem ki tu nhap vao co phai la chu cai khong	
				goto saidiem;
			}
		}
		if( atof(Diem) < 0 || atof(Diem) > 10.00){
			goto saidiem;
		}
		else
			this->Score = atof(Diem);	// atof	chuan chuyen doi mot chuoi duoc tro toi boi tham so str thanh mot so thuc dau cham dong
	}
	else{
		saidiem:
		cout<<endl;
		gotoxy(100,1);
		cout<<"Nhap sai, vui long nhap lai"<<endl;
		Sleep(2000);
		xoadong(100,1,50,1);
		xoadong(100,18,sizeof Diem,1);
		gotoxy(100,18);
		goto diem;
	}
	this->Score ;
}

//Cac ham get, set thuoc tinh
char SinhVien::getLop(){
	return this->Lop[50] ;
}
void SinhVien::setLop(char Lop[50]){
	this->Lop[50] = Lop[50];
}
char SinhVien::getName(){
	return this->Name[50] ;
}
void SinhVien::setName(char Name[50]){
	this->Name[50] = Name[50];
}
int SinhVien::getID(){
	return this->ID;
}
void SinhVien::setID(int ID){
	this->ID = ID;
}
float SinhVien::getScore(){
	return this->Score;
}
void SinhVien::setScore(float Score){
	this->Score = Score;
}
char SinhVien::getDOB(){
	return this->DOB[50];
}
void SinhVien::setDOB(char DOB[50]){
	this->DOB[50] = DOB[50];
}

