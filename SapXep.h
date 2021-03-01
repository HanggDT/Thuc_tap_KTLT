#include "CapNhatHoSo.h"

//doi cho SV
void swap(SinhVien &sv1, SinhVien &sv2){
	SinhVien temp;
	temp = sv1;
	sv1 = sv2;
	sv2 = temp;
}
//Xoa bo '/' trong DOB
char *XuliDOB(char ngaysinh[20]){
	char temp[30], date[20], *m[20];
	strcpy(date, ngaysinh);
	char *p;
	int i = 0;
	p = strtok(date, "/");  	//strtok chia chuoi str thanh 1 day cac token duoc phan biet rieng re boi dau tach delim
	while(p!=NULL){
		m[i] = p;
		i++;
		p = strtok(NULL, "/");
	}
	strcpy(temp, m[i-1]);
	for(int j = i-2; j >= 0; j--){
		strcat(temp, "/"); 
		strcat(temp, m[j]);
	}
	return temp;
}
//xoa bo ' ' trong name
char *XuliTen(char name[50]){
	char ten[50], temp[10], ten1[50];
	strcpy(ten, name);
	int i=0;
	int n=strlen(ten)-1;
	while(ten[n]!=' '){
		temp[i]=ten[n];
		i++;
		n--;
	}
	temp[i]='\0';
	ten[n]='\0';
	strcpy(ten1, strrev(temp));		//strrev ham dao chuoi
	strcat(ten1, " ");
	strcat(ten1, ten);
	return ten1;
}
//Sap xep chon
void Selection_Sort(vector<SinhVien> &dssv, int Pointer){
	int min;
	char temp1[30], temp2[30];
	for(int i = 0; i < dssv.size() - 1; i++){
		min = i;
		for(int j = i + 1; j < dssv.size(); j++){
			switch (Pointer)
			{
				case 1://sxep theo lop
				{
					if(strcmp(dssv[min].Lop, dssv[j].Lop)>0)
						min=j;
				}
				break;
				case 2://sxep theo ma sv
				{
					if(dssv[min].ID> dssv[j].ID)
						min=j;
				}
				break;
				case 3://sxep theo ten
				{
					strcpy(temp1, XuliTen(dssv[min].Name));
					strcpy(temp2, XuliTen(dssv[j].Name));
					if(strcmp(temp1, temp2)>0)
						min=j;
				}
				break;
				case 4://sxep theo ngay sinh
				{
					strcpy(temp1, XuliDOB(dssv[min].DOB));
					strcpy(temp2, XuliDOB(dssv[j].DOB));
					if(strcmp(temp1, temp2)>0)
						min=j;
				}
				break;
				case 5:// sxep theo diem
				{
					if(dssv[min].Score<dssv[j].Score)
						min=j;
				}
				break;     
				case 6:// tro lai
				{
					xoabang(66, 5, 6);
//					goto again3;
				}
				break;
			}            
		}
		swap(dssv[i], dssv[min]);
	}
}
//Sap xep chen
void Insertion_Sort(vector<SinhVien> &dssv, int Pointer){
	SinhVien temp;
	char temp1[50], temp2[50];
	for(int i=1; i<dssv.size(); i++){
		temp=dssv[i];
		int j=i-1;
		switch (Pointer)
		{
			case 1:	//key: Lop
			{
				while((j>=0) && strcmp(temp.Lop, dssv[j].Lop)<0){
					dssv[j+1]=dssv[j];
					j=j-1;
				}
			}
				break;
			case 2:	//key: Ma Sv
			{
				while((j>=0)&&(temp.ID < dssv[j].ID)){
					dssv[j+1]=dssv[j];
					j=j-1;
				}
			}
				break;
			case 3:	//key: Ten
			{
				strcpy(temp1, XuliTen(temp.Name));
				while(j>=0){
					strcpy(temp2, XuliTen(dssv[j].Name));
					if(strcmp(temp1, temp2)<0){
						dssv[j+1]=dssv[j];
						j=j-1;
					}else{
						break;
					}
				}
			}
				break;
			case 4:	//key: Ngay sinh
			{
				strcpy(temp1, XuliDOB(temp.DOB));
				while(j>=0){
					strcpy(temp2, XuliDOB(dssv[j].DOB));
					if(strcmp(temp1, temp2)<0){
						dssv[j+1]=dssv[j];
						j=j-1;
					}else{
						break;
					}
				}
			}
				break;
			case 5:	//key: Diem so
			{
				while((j>=0)&&(temp.Score>dssv[j].Score)){
					dssv[j+1]=dssv[j];
					j=j-1;
				}
			}
				break;
			case 6:	// tro lai
			{
				xoabang(66, 7, 6);
	//			goto again3;
			}
			break;
		}
		dssv[j+1]=temp;
	}
}
//Sap xep noi bot
void Bubble_Sort(vector<SinhVien> &dssv, int Pointer){
	char temp1[50], temp2[50];
	for(int i=0; i<dssv.size()-1; i++){
		for(int j=dssv.size()-1; j>i; j--){
			switch (Pointer){
				case 1:	//key: Lop
				{
					if(strcmp(dssv[j].Lop, dssv[j-1].Lop)<0)
						swap(dssv[j], dssv[j-1]);
					break;
				}
				case 2:	//key: Ma Sv
				{
					if(dssv[j].ID < dssv[j-1].ID)
						swap(dssv[j], dssv[j-1]);
					break;
				}
				case 3:	//key: Ten
				{
					strcpy(temp1, XuliTen(dssv[j].Name));
					strcpy(temp2, XuliTen(dssv[j-1].Name));
					if(strcmp(temp1, temp2)<0)
						swap(dssv[j], dssv[j-1]);
					break;
				}
				case 4:	//key: Ngay sinh
				{
					strcpy(temp1, XuliDOB(dssv[j].DOB));
					strcpy(temp2, XuliDOB(dssv[j-1].DOB));
					if(strcmp(temp1, temp2)<0)
						swap(dssv[j], dssv[j-1]);
					break;
				}
				case 5:	//key: Diem so
				{
					if(dssv[j].Score>dssv[j-1].Score)
						swap(dssv[j], dssv[j-1]);
					break;   
				}
				case 6:	// tro lai
				{
					xoabang(66, 9, 6);
//					goto again3;
					break;
				}
			}       
		}
	}
}
//Sap xep nhanh
void Quick_Sort(vector<SinhVien> &dssv, int L, int R, int Pointer){
	int i=L;
	int j=R;      
	SinhVien key=dssv[(L+R)/2];
	char cKey[50], temp[50];

	while (i<=j){
		switch (Pointer)
		{
		case 1:	//key: Lop
			{
				while(strcmp(dssv[i].Lop, key.Lop)<0)
					i++;         
				while(strcmp(dssv[j].Lop, key.Lop)>0)
					j--;
			}
			break;			
		case 2:	//key: Ma Sv
			{
				while(dssv[i].ID < key.ID)
					i++;
				while(dssv[j].ID > key.ID)
					j--;
			}
			break;
		case 3:	//key: Ten
			{
				strcpy(cKey, XuliTen(key.Name));
				while(1){
					strcpy(temp, XuliTen(dssv[i].Name));
					if(strcmp(temp, cKey)<0)
						i++;
					else
						break;
				}
				while(1){
					strcpy(temp, XuliTen(dssv[j].Name)); 
					if(strcmp(temp, cKey)>0)
						j--;
					else
						break;
				}
			}
			break;
		case 4:	//key: Ten
			{
				strcpy(cKey, XuliDOB(key.DOB));
				while(1){
					strcpy(temp, XuliDOB(dssv[i].DOB));
					if(strcmp(temp, cKey)<0)
						i++;
					else
						break;
				}
				while(1){
					strcpy(temp, XuliDOB(dssv[j].DOB));
					if(strcmp(temp, cKey)>0)
						j--;
					else
						break;
				}
			}
			break;
		case 5:	//key: Diem so
			{
				while(dssv[i].Score>key.Score)
					i++;
				while(dssv[j].Score<key.Score)
					j--;
			}
			break;
		case 6:	// tro lai
			{
				xoabang(66, 11, 6);
//				goto again3;
			}
			break;
		}
		if(i<=j){
			swap(dssv[i], dssv[j]);
			i++;
			j--;
		}
	}
	if(L<j)
		Quick_Sort(dssv, L, j, Pointer);
	if(i<R)
		Quick_Sort(dssv, i, R, Pointer);
}
