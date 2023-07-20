#include<iostream>
#include<fstream> 
#include <string.h>
using namespace std;
struct HoTen {
	string ho;
	string dem;
	string ten;
};

struct DoanhNghiep {
    int stt;
    string DoB;
    string noicongtac;
    string chucvu;
    string diachi;
    string email;
    int sdt;
    string quequan;
    string ngaybatdau;
    string giodenvave;   
    struct HoTen HovaTen;
};

void hienThiTenCot() {
    cout <<"---------------------------------------------------------------------------------------------------------" <<   
         "--------------------------------------------------------------------------------------------------------\n";
    cout <<"STT 	Noi cong tac      Chuc vu                    Ho       Dem         Ten      DoB" <<
    "   Que quan    Dia chi 		Email 		    SDT 	    Ngay lam viec 		Ngay lam: Gio den/Gio ve"<< endl;

};
void hienThiTTDN(struct DoanhNghiep cn) {
	cout<< *(&cn.stt), cn.noicongtac, cn.chucvu, cn.HovaTen, cn.DoB, cn.quequan, cn.diachi, cn.email, *(&cn.sdt), cn.ngaybatdau, cn.giodenvave;
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
            cout << *(&cn.stt), cn.noicongtac, cn.chucvu, cn.HovaTen, cn.DoB, cn.quequan, cn.diachi, cn.email, *(&cn.sdt), cn.ngaybatdau, cn.giodenvave;
            dn[i++] = cn;
            if (MyReadFile.eof())  {
                break;
            }
        }
    }
    else cout<<"Unable to open file!";
MyReadFile.close();
*sl = i;
};
void ghiFile(struct DoanhNghiep* dn, int sl) {
	string fName;
    cout <<"Nhap ten file: ";
    getline(cin, fName );
	ifstream MyReadFile("data2.txt");
	int i;
	for(i = 0; i < sl; i++) {
		struct DoanhNghiep cn = dn[i];
		cout <<	*(&cn.stt), cn.noicongtac, cn.chucvu, cn.HovaTen, cn.DoB, cn.quequan, cn.diachi, cn.email, *(&cn.sdt), cn.ngaybatdau, cn.giodenvave;
	}
	MyReadFile.close();
}

int main(){
    struct DoanhNghiep dn[100];
    int sl = 0;
    hienThiDS(dn,sl);
    docFile(dn, &sl);
   return 0;
}

	
