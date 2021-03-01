#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
using namespace std;

//an hien con tro
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void cursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

//can bang dieu khien ra giua man hinh
void MoveCenter()
{
    RECT rectClient, rectWindow;
    HWND hWnd = GetConsoleWindow();
    GetClientRect(hWnd, &rectClient);
    GetWindowRect(hWnd, &rectWindow);
    int posx, posy;
    posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
    posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,

    MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

//dua con tro toi vi tri toa do x, y 
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

//tao mau
void TextColor(int color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	int wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//ke bang
void kebang(int x, int y,int n,int t)//ke tu cot x, hang thu y; bang gom n hang, do dai bang: t
{				
	for(int i=0;i<=n;i++){
		gotoxy(x,y+9);cout<<(char) 201;//goc tren trai
		gotoxy(x+t-1,y+9);cout<<(char) 187;//goc tren phai
		gotoxy(x+1,y+9+2*i); for (int j=0;j<t-2;j++) cout<<(char) 205;//ke ngang
		for(int k=0;k<n;k++)
		{
			gotoxy(x,y+11+2*k);cout<<(char) 204;//giao trai
		 	gotoxy(x+t-1,y+11+2*k);cout<<(char) 185;//giao phai
		 	gotoxy(x,y+10+2*k);cout<<(char) 186;//ke doc
			gotoxy(x+t-1,y+10+2*k);cout<<(char) 186;
		}	
		gotoxy(x,y+9+2*n);cout<<(char) 200;//goc duoi trai
		gotoxy(x+t-1,y+9+2*n);cout<<(char) 188;//goc duoi phai
	}
}

//xoa dong
void xoadong(int x, int y,int t, int n)//xoa t ki tu, n dong. bat dau tu vi tri x, dong thu y
{
	int i = y;
	while(i < y + n ){
		char c[t];
		for(int j = 0; j < t; j++)
		{
			c[j] = ' ';	//ghi de ki tu khoang trang len ki tu ban dau
			if(j == t-1)
				c[j+1] = '\0';
		}
		gotoxy(x, i);
		cout<<c;
		i++;
	}
	gotoxy(0,0);
}

//xoa bang
void xoabang(int cap, int vitri, int sohang)//dung cho bang co do dai = 29;
{
	xoadong(cap - 1, vitri + 7, 29, (sohang*2) + 2);/* xoa theo cap cua bang ( 1, 2, 3), xoa tu dong thu y +7 ( y = vitri K (k = 1,2,3..))
													lay vitri de xac dinh dong can xoa bat dau tu dau
													29 la chieu dai mac dinh cua bang,
													so hang can xoa = so dong cua menu + so dong cua dong ke bang.*/
	//	vd: xoadong(cap3 - 1, vitri + 9, 29, lensv*2+1);												
}

void xoabang1(int cap, int vitri, int dodai, int sohang)//dung cho bang co do dai = dodai;
{
	xoadong(cap, vitri + 9, dodai, (sohang*2) + 2);/* xoa theo cap cua bang ( 1, 2, 3), xoa tu dong thu y +9 ( y = vitriK (k = 1,2,3..))
													lay vitri de xac dinh dong can xoa bat dau tu dau
													dodai la chieu dai mac dinh cua bang,
													so hang can xoa = so dong cua menu + so dong cua dong ke bang.*/
	//	vd: xoadong(cap3 - 1, vitri + 9, 29, lensv*2+1);												
}

//dieu khien con tro va doi mau
void dieukhiencontro(int cap, int &vitri, char *chara[], int len)//ket hop su dung voi switch(vitri) case:{vitri = 1,2,..len};
{
	Nocursortype();
	int dieukhien;
	int contro = vitri;
	vitri = 1;
	do{
		for(int i = 1; i <= len; i++)// thay doi mau chu doi voi chuc nang duoc chon
			if(vitri == i){
				gotoxy(cap,contro-1+8+2*i);
				TextColor(15);
				cout<<" ->> "<<chara[i-1]<<" <<-"<<endl;
				TextColor(16);
			}
			else{
				gotoxy(cap,contro-1+8+2*i);
				cout<<" [+] "<<chara[i-1]<<"    "<<endl;
			}
		do// nguoi su dung cac phim mui ten hoac phim enter
			{
				dieukhien = getch();
			}
			while(!(dieukhien==72 || dieukhien==80 || dieukhien==13));
			
			if(dieukhien == 80)// dieu khien phim mui ten xuong
			{
				vitri++;
				if(vitri == len+1) vitri = 1;
			}
			if(dieukhien == 72)// dieu khien phim mui ten len							
			{
				vitri--;
				if(vitri == 0) vitri = len;
			}
		}
	while(!(dieukhien == 13));
	cursortype();
}

//Chuan hoa - tham khao http://diendan.congdongcviet.com/threads/t14004::bai-tap-chuan-hoa-chuoi.cpp
void strdelete(char *s,int vt,int sl)// xoa ki tu o vi tri vt, sl la so luong
{  
    int n=strlen(s),i;
    for (i=vt;i<=n-sl;i++)
        s[i]=s[i+sl];
}

void ChuanHoa(char a[])
{
    int i;
    while(a[strlen(a)-1]==' ')// xoa khoang trang o cuoi
        a[strlen(a)-1]=0;
    while(a[0]==' ')//xoa khoang trang o dau
        strdelete(a,0,1);
    for(i=0;i<strlen(a);i++)
        if((a[i]>=65)&&(a[i]<=90))//kiem tra co phai la ky tu hoa
            a[i]+=32;//chuyen tat ca ve ky tu thuong
    i=0;
    while(i<strlen(a))//xoa hai khoang trang lien tiep
     if((a[i]==' ')&&(a[i+1]==' '))
         strdelete(a,i,1);
     else i++;
   for(i=0;i<strlen(a);i++)
    if(a[i]==' ')
        a[i+1]-=32;//chuyen chu cai sau khoang trang thanh chu hoa  
   a[0]=toupper(a[0]);//chuyen chu cai dau tien thanh chu hoa
}
