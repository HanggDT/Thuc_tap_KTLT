#include "Sapxep.h"

//Tim kiem tuan tu
void LinearSearch(vector<SinhVien> dssv, int Pointer){
	vector<SinhVien> result;
	char Key[50];
	kebang(77,1,1, 30);
	gotoxy(78,11);
	cout<<"Nhap keyword: ";
	gets(Key);
	switch (Pointer){
		case 1:{
			for(int i=0;i<dssv.size();i++){
		    	if(strstr(strlwr(dssv[i].Lop), Key) != NULL) 		//strlwr = tra ve string chu in thuong string lower
		    	    result.push_back(dssv[i]);
			}
		}
		break;
		case 2:	{
				for(int i=0;i < dssv.size();i++)
		    	{
		    		int id = dssv[i].ID;
					char strid[10];
					sprintf(strid, "%d", id);
		    		if(strstr(strid, Key) != NULL)
		    		    result.push_back(dssv[i]);
				}
		}
		break;		
		case 3: { 
			for(int i = 0; i < dssv.size(); i++){
		   		strlwr(dssv[i].Name);
		   		if(strstr(dssv[i].Name, Key) != NULL){
		   			ChuanHoa(dssv[i].Name);
		   			result.push_back(dssv[i]);
				}	    		   
			}
		}
		break;
		case 4:{   
			for(int i=0;i<dssv.size();i++){
		    	if(strstr(dssv[i].DOB,Key) != NULL)
		    	    result.push_back(dssv[i]);
			}
		}
		break;
		case 5:{
			char c[5];
			for(int i=0;i<dssv.size();i++){ 
			    sprintf(c,"%0.2f",dssv[i].Score);	
		   		if(strstr(c,Key) != NULL)
		   		    result.push_back(dssv[i]);
			}
		}
		break;		
	}
	xoabang1(77, 1, 30, 1);
	if(result.empty()){
		gotoxy(90,5);
		cout<<"Khong tim thay ket qua cho: ";
		TextColor(15);
		cout<<Key;
		TextColor(16);
		cout<<" !!!";
		Sleep(2000);
		xoadong(90, 5, 47+strlen(Key), 1);
	}else{
		gotoxy(90,5);
		cout<<"Ket qua tim kiem: "; 
		TextColor(15);
		cout<<Key;
		TextColor(16);
		cout<<" : ";
		InDanhSach(result, Pointer);
		xoadong(90, 5, 37+strlen(Key), 1);
	}
}
//Tim kiem nhi phan
int BinarySearch(vector<SinhVien> dssv, int L, int R, char Key[50], int Pointer){
	if(L >= R)
		return -1;
	else
	{
		int key = L + (R-L)/2;
		switch (Pointer)
		{
			case 1:
				{   
					strlwr(Key);
					if(strstr(strlwr(dssv[key].Lop), Key) != NULL) return key;
					else if(strcmp(Key, dssv[key].Lop)>0) return BinarySearch(dssv, key+1, R, Key, 1);
					else if(strcmp(Key, dssv[key].Lop)<0) return BinarySearch(dssv, L, key-1, Key, 1);
				}
				break;
			case 2:
				{
					int id = dssv[key].ID;
					char strid[10];
					sprintf(strid, "%d", id);
					if(strstr(strid, Key) != NULL) return key;
					else if(strcmp(Key, strid)>0)  return BinarySearch(dssv, key+1, R, Key, 2);
					else if(strcmp(Key, strid)<0)  return BinarySearch(dssv, L, key-1, Key, 2);
				}
				break;		
			case 3:
				{ 	
					strlwr(Key);
					char stdName[50];
					//strcpy(stdName, XuliTen(dssv[key].Name));
					if(strstr(stdName, Key) != NULL) return key;
					else if(strcmp(Key, stdName)>0) return BinarySearch(dssv, key+1, R, Key, 3);
					else if(strcmp(Key, stdName)<0) return BinarySearch(dssv, L, key-1, Key, 3);
				}
				break;		
			case 4:
				{   
					char Birthday[20];
					strcpy(Birthday, dssv[key].DOB);
					if(strstr(Birthday, Key) != NULL)	return key;
					else if(strcmp(Key, Birthday)>0) return BinarySearch(dssv, key+1, R, Key, 4);
					else if(strcmp(Key, Birthday)<0) return BinarySearch(dssv, L, key-1, Key, 4);
				}
				break;		
			case 5:
				{
					char c[5];
					float mKey = atof(Key);
					sprintf(c,"%0.2f",dssv[key].Score);
					if(strstr(c,Key) != NULL) return key;
					else if(mKey<dssv[key].Score) return BinarySearch(dssv, key+1, R, Key, 5);
					else if(mKey>dssv[key].Score) return BinarySearch(dssv, L, key-1, Key, 5);
				}
				break;
		}
	}
}
#ifndef TIMKIEM_H
#define TIMKIEM_H

class TimKiem
{
	public:
	protected:
};

#endif
