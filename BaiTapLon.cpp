#include<iostream>
#include<fstream> 
#include <string.h>
using namespace std;

void hienThiTenCot() {
    cout <<"---------------------------------------------------------------------------------------------------------" <<   
    "------------------------------------------------------------------------------------------" <<
    "--------------------------------------------------------------------\n";
    cout <<"STT 	Noi cong tac      Chuc vu                    Ho       Dem         Ten      DoB" <<
    "   Que quan    Dia chi 		Email 		    SDT 	    Ngay lam viec 		Ngay lam: Gio den/Gio ve";

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

void hienThiTTDN(struct DoanhNghiep dn) {
	cout<<"dn.DoB, dn.noicongtac, dn.chucvu, dn.diachi, dn.email, dn.sdt, dn.stt, dn.ngaybatdau, dn.giodenvave, dn.HovaTen";
}

void hienThiDS(struct DoanhNghiep* dn, int sl) {
	hienThiTenCot();
	int i;
	for(i = 0; i < sl; i++) {
		hienThiTTDN(dn[i]);
	}
	cout<<"----------------------------------------------------------------------------"
	"------------------------------------------------------------------------------------\n";
}

    /*fstream MyFile("data.txt");
    string  a;
    while (!MyFile.eof()){
       getline(MyFile,a);
       cout<<a<<endl;
    }
    MyFile.close();*/

	
