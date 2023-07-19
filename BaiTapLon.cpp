#include<iostream>
#include<fstream> 
#include <string.h>
using namespace std;

void hienThiTenCot() {
    cout <<"---------------------------------------------------------------------------------------------------------" <<   
         "--------------------------------------------------------------------------------------------------------\n";
    cout <<"STT 	Noi cong tac      Chuc vu                    Ho       Dem         Ten      DoB" <<
    "   Que quan    Dia chi 		Email 		    SDT 	    Ngay lam viec 		Ngay lam: Gio den/Gio ve"<< endl;

};

struct HoTen {
	char ho[20];
	char dem[21];
	char ten[20];
};

struct DoanhNghiep {
    char DoB[20];
    char noicongtac[20];
    char chucvu[20];
    char diachi[20];
    char email[21];
    int sdt;
    int stt;
    char ngaybatdau[21];
    char giodenvave[21];   
    struct HoTen HovaTen;
};

void hienThiTTDN(struct DoanhNghiep cn) {
	cout<<cn.DoB, cn.noicongtac, cn.chucvu, cn.diachi, cn.email, &cn.sdt, &cn.stt, cn.ngaybatdau, cn.giodenvave, cn.HovaTen;
}

void hienThiDS(struct DoanhNghiep* dn, int sl) {
	hienThiTenCot();
	int i;
	for(i = 0; i < sl; i++) {
		hienThiTTDN(dn[i]);
	}
	cout<<"----------------------------------------------------------------------------------------------------------------------"
	"-------------------------------------------------------------------------------------------\n";
}
void docFile(struct DoanhNghiep* dn, int* sl){
    string mytext;
    ifstream MyReadFile("data2.txt");
    int i;
    if(MyReadFile.is_open()){   
        for(;;){
            struct DoanhNghiep cn;
            cout <<cn.DoB, cn.noicongtac, cn.chucvu, cn.diachi, cn.email, &cn.sdt, &cn.stt, cn.ngaybatdau, cn.giodenvave, cn.HovaTen;
            dn[i++] = cn;
        }
    }
    else cout<<"Unable to open file!";
MyReadFile.close();
*sl = i;
};
void ghiFile(struct DoanhNghiep* dn, int sl) {
	string fName;
    getline(cin, fName );
	cout <<"Nhap ten file: ";
	ifstream MyReadFile("data2.txt");
	int i;
	for(i = 0; i < sl; i++) {
		struct DoanhNghiep cn = dn[i];
		cout <<	cn.DoB, cn.noicongtac, cn.chucvu, cn.diachi, cn.email, &cn.sdt, &cn.stt, cn.ngaybatdau, cn.giodenvave, cn.HovaTen;
	}
	MyReadFile.close();
}

int main(){
    struct DoanhNghiep dn[1000];
    int sl = 0;
    hienThiDS(dn,sl);
    docFile(dn, &sl);
   return 0;
}

	
