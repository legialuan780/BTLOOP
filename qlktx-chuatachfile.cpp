//HEADER
#include<iostream>
#include<vector>
#include<string>
#include <dos.h>
#include <unistd.h>
#include<fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//DATE
class Date{
	private:
   		int ngay;
    	int thang;
    	int nam;
	public:
    	Date();
    	Date(int ngay, int thang, int nam);

    	void setNgay(int ngay);
    	void setThang(int thang);
    	void setNam(int nam);

    	int getNgay();
    	int getThang();
    	int getNam();

    	void Nhap();
    	void Xuat();
};
Date::Date()
{
    ngay = 0;
    thang = 0;
    nam = 0000;
}

Date::Date(int n, int t, int y)
{
    ngay = n;
    thang = t;
    nam = y;
    
}

void Date::setNgay(int n)
{
    ngay = n;
}

void Date::setThang(int t)
{
    thang = t;   
}

void Date::setNam(int y)
{
    nam = y;
}

int Date::getNgay()
{
    return ngay;
}

int Date::getThang()
{
    return thang;
}

int Date::getNam()
{
    return nam;
}

void Date::Nhap(){
    int check=1;
	do{
		do{
			cout<<"Nhap ngay sinh: ";cin>>ngay;
			if (ngay<1 or ngay>31) cout<<"Nhap lai ngay!"<<endl;
		} while (ngay<1 or ngay>31);
		do{
			cout<<"Nhap thang: ";cin>>thang;
			if (thang<1 or thang>12) cout<<"Nhap lai thang!"<<endl;	
		} while (thang<1 or thang>12);
		do{
			cout<<"Nhap nam: ";cin>>nam;
			if (nam<1900 or nam>2025) cout<<"Nhap lai nam!"<<endl;
		} while (nam<1900 or nam>2025);
		if (nam%4==0 and thang==2 and ngay>29) check=0;
		else if (nam%4!=0 and thang == 2 and ngay>28) check=0;
		else if ((thang ==4 or thang ==6 or thang==9 or thang ==11) and ngay>30) check=0;
		else check=1;
		if (check==0) cout<<"Ngay da nhap khong hop le"<<"\nVui long nhap lai!"<<endl;
	}while (check==0);
}

void Date::Xuat()
{
    if (ngay<10) cout<<"0"<<ngay;
    else cout<<ngay;
    cout<<" / ";
    if (thang<10) cout<<"0"<<thang;
    else cout<<thang;
    cout<<" / ";
    cout<<nam;
}



//SV
class SinhVien{
    private:
        string HoTen, MSSV, DiaChi, Lop, Khoa, GioiTinh, SDT;
        Date NgaySinh;
    public:
        SinhVien();
        SinhVien(string hoTen, string mssv, string diaChi, string lop, string khoa, string gioiTinh, string sdt, Date ngaySinh);

        void setHoTen(string hoTen);
        void setMSSV(string mssv);
        void setDiaChi(string diaChi);
        void setLop(string lop);
        void setKhoa(string khoa);
        void setGioiTinh(string gioiTinh);
        void setSDT(string sdt);
        void setNgaySinh(Date ngaySinh);

        string getHoTen();
        string getMSSV();
        string getDiaChi();
        string getLop();
        string getKhoa();
        string getGioiTinh();
        string getSDT();
        Date getNgaySinh();

        void Nhap();
        void Xuat();
        void XuatBang();
        
        bool KiemTraKhoa();
        
        bool TimSinhVienTheoTen(string ten);
};
SinhVien::SinhVien() {
    HoTen = "";
    MSSV = "";
    DiaChi = "";
    Lop = "";
    Khoa = "";
    GioiTinh = "";
    SDT = "";
    NgaySinh = Date();
}

SinhVien::SinhVien(string hoTen, string mssv, string diaChi, string lop, string khoa, string gioiTinh, string sdt, Date ngaySinh)
    : HoTen(hoTen), MSSV(mssv), DiaChi(diaChi), Lop(lop), Khoa(khoa), GioiTinh(gioiTinh), SDT(sdt), NgaySinh(ngaySinh) {}

void SinhVien::setHoTen(string hoTen) {HoTen = hoTen;}
void SinhVien::setMSSV(string mssv) {MSSV = mssv;}
void SinhVien::setDiaChi(string diaChi) {DiaChi = diaChi;}
void SinhVien::setLop(string lop) {Lop = lop;}
void SinhVien::setKhoa(string khoa) {Khoa = khoa;}
void SinhVien::setGioiTinh(string gioiTinh) {GioiTinh = gioiTinh;}
void SinhVien::setSDT(string sdt) {SDT = sdt;}
void SinhVien::setNgaySinh(Date ngaySinh) {NgaySinh = ngaySinh;}

string SinhVien::getHoTen() {return HoTen;}
string SinhVien::getMSSV() {return MSSV;}
string SinhVien::getDiaChi() {return DiaChi;}
string SinhVien::getLop() {return Lop;}
string SinhVien::getKhoa() {return Khoa;}
string SinhVien::getGioiTinh() {return GioiTinh;}
string SinhVien::getSDT() {return SDT;}
Date SinhVien::getNgaySinh() {return NgaySinh;}

void SinhVien::Nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    do{
    	cout << "Nhap MSSV: ";
    	getline(cin, MSSV);	
    	if (MSSV.size()!=10) cout<<"MSSV khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	} while (MSSV.size()!=10);
    
    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);
    cout << "Nhap lop: ";
    getline(cin, Lop);
    
    cout << "Nhap khoa [Kxx]: ";
    getline(cin, Khoa);
    

	do{
		cout << "Nhap gioi tinh: ";
    	getline(cin, GioiTinh);	
    	if (GioiTinh!="Nam" and GioiTinh!="Nu") cout<<"Gioi tinh khong hop le!"<<endl<<"Vui long nhap lai! [Nam/Nu]"<<endl<<endl;
	}while(GioiTinh!="Nam" and GioiTinh!="Nu");
    
    do{
    	cout << "Nhap so dien thoai: ";
    	getline(cin, SDT);
	}while (SDT.size()!=10);
    NgaySinh.Nhap();
    cin.ignore();  // Để bỏ qua ký tự xuống dòng sau khi nhập số
}

void SinhVien::Xuat() {
    cout << "Ho ten: " << HoTen << endl;
    cout << "MSSV: " << MSSV << endl;
    cout << "Dia chi: " << DiaChi << endl;
    cout << "Lop: " << Lop << endl;
    cout << "Khoa: " << Khoa << endl;
    cout << "Gioi tinh: " << GioiTinh << endl;
    cout << "So dien thoai: " << SDT << endl;
    cout << "Ngay sinh: ";
    NgaySinh.Xuat();
}

void SinhVien::XuatBang(){
	cout <<setw(18)<< HoTen <<" |"<<setw(13)<< MSSV << " |"<<setw(8)<< Lop << " |"<<setw(8)<< Khoa << " |" <<setw(13)<<GioiTinh << " |"<<setw(13)<< SDT << " |   ";
    NgaySinh.Xuat();
    cout <<" |"<< endl;
}
bool SinhVien::KiemTraKhoa(){
	if (!(Khoa=="K65" or Khoa=="K64" or Khoa=="K63" or Khoa=="K62")){
    	cout<<"Khoa da nhap khong hop le hoac vuot qua khoa quy dinh cua KTX";
    	return false;
	}
	return true;
}
//PHONG
class Phong{
	private:
		string TenPhong;
		int ThuTuPhong;
		static int ThuTuPhongMoi;
		int SoNguoiToiDa;
		int SoNguoiHienTai;
		int SoDienCu, SoDienMoi;
		vector<SinhVien> DsSV;
	public:
    
    string getTenPhong();
    int getSoNguoiToiDa();
    int getSoNguoiHienTai();
    int getSoDienCu();
    int getSoDienMoi();
	
	void setTenPhong(string tenPhong);
    void setSoNguoiToiDa(int soNguoi);
    void setSoDienCu(int soDienCu); 
    void setSoDienMoi(int SoDienMoi);

	void KhoiTaoPhong(int ThuTu);
	void NhapSinhVien(SinhVien sv);
	void XuatDsSinhVien(string tenDay);
	
    void XuatThongTinPhong();  // Xuất thông tin phòng
    
    bool KiemTraMSSV(string mssv);
    bool KiemTraPhongTrong();
    
    void TimSinhVienTheoTen(string ten, int thuTuDay, int thuTuPhong);
};

string Phong::getTenPhong(){return TenPhong;}
int Phong::getSoNguoiToiDa(){return SoNguoiToiDa;}
int Phong::getSoNguoiHienTai(){return SoNguoiHienTai;}
int Phong::getSoDienCu(){return SoDienCu;}
int Phong::getSoDienMoi(){return SoDienMoi;}
	
void Phong::setTenPhong(string tenPhong){TenPhong=tenPhong;}
void Phong::setSoNguoiToiDa(int soNguoi){SoNguoiToiDa=soNguoi;}
void Phong::setSoDienCu(int soDienCu){SoDienCu=soDienCu;}
void Phong::setSoDienMoi(int SoDienMoi){SoDienMoi=SoDienMoi;}

void Phong::KhoiTaoPhong(int ThuTu){
	SoNguoiToiDa=6;
	SoNguoiHienTai=0;
	SoDienCu=0;
	SoDienMoi=0;
	switch (ThuTu){
		case 0:ThuTuPhong=0; TenPhong="P01"; break;
		case 1:ThuTuPhong=1; TenPhong="P02"; break;
		case 2:ThuTuPhong=2; TenPhong="P03"; break;
		case 3:ThuTuPhong=3; TenPhong="P04"; break;
		case 4:ThuTuPhong=4; TenPhong="P05"; break;
	}
}

void Phong::NhapSinhVien(SinhVien sv){
	DsSV.push_back(sv);
	SoNguoiHienTai=DsSV.size();
}
void Phong::XuatThongTinPhong() {
    cout << "Ten phong: " << TenPhong << endl;
    cout << "So nguoi toi da: " << SoNguoiToiDa << endl;
    cout << "So nguoi hien tai: " << SoNguoiHienTai << endl;
    cout << "So dien cu: " << SoDienCu << endl;
    cout << "So dien moi: " << SoDienMoi << endl;
}
void Phong::XuatDsSinhVien(string tenDay){
	if (DsSV.size() == 0) {
//        cout << "Phong " << TenPhong << " trong day " << tenDay << " hien khong co sinh vien nao.\n";
        return;
    }
    
    for (int i = 0; i < DsSV.size(); i++) {
//    	if (i==0) 
		cout <<setw(5)<< tenDay <<" |"<<setw(8)<< TenPhong<<" |";
        DsSV[i].XuatBang();
    }
}

bool Phong::KiemTraMSSV(string mssv){
	bool kt=true;
    for (int i=0; i<DsSV.size();i++){
    	if (DsSV[i].getMSSV()==mssv) kt=false;
    	if (kt==false) return kt;
	}
	return kt;
}
bool Phong::KiemTraPhongTrong(){
	return (SoNguoiHienTai<SoNguoiToiDa);
}
void Phong::TimSinhVienTheoTen(string ten, int thuTuDay, int thuTuPhong){
	for (int i=0; i<DsSV.size();i++){
		DsSV[i].TimSinhVienTheoTen(ten, thuTuDay, thuTuPhong);
	}
}
//DAY
class Day{
	private:
		int ThuTuDay;
		static int ThuTuDayMoi;
		string TenDay;	
		string LoaiDay;
		vector<Phong> DsPhong;
		int SoLuongPhong;
	public:
		
		string getTenDay();
		int getSoLuongPhong();
		
		void setTenDay(string tenDay);
		void setSoLuongPhong(int);
		
		void KhoiTaoDay(int ThuTu);
		void NhapSinhVien(SinhVien sv, int thuTuPhong);
		void XuatDsSinhVien();
		
		void XuatThongTinDay();
		void XuatTenPhong(int thuTuDay, int thuTuPhong);
		
		bool KiemTraMSSV(string mssv);
		bool KiemTraPhongTrong(int thuTuDay, int thuTuPhong, string gioiTinh);
		
		void TimSinhVienTheoTen(string ten, int thuTuDay);
};
int Day::ThuTuDayMoi=0;
string Day::getTenDay(){return TenDay;}
int Day::getSoLuongPhong(){return SoLuongPhong;}

void Day::setTenDay(string tenDay){ TenDay=tenDay;}
void Day::setSoLuongPhong(int soLuongPhong){
	SoLuongPhong=soLuongPhong;
}

void Day::KhoiTaoDay(int ThuTu){
	SoLuongPhong = 5;
	DsPhong.resize(SoLuongPhong);
	switch (ThuTu){
		case 0:ThuTuDay=0; TenDay="D1"; LoaiDay="Nam"; break;
		case 1:ThuTuDay=1; TenDay="D2"; LoaiDay="Nam"; break;
		case 2:ThuTuDay=2; TenDay="D3"; LoaiDay="Nam"; break;
		case 3:ThuTuDay=3; TenDay="N1"; LoaiDay="Nu"; break;
		case 4:ThuTuDay=4; TenDay="N2"; LoaiDay="Nu"; break;
	}
	for (int i=0; i<SoLuongPhong; i++){
		DsPhong[i].KhoiTaoPhong(i);
	}
}

void Day::NhapSinhVien(SinhVien sv, int thuTuPhong){
	DsPhong[thuTuPhong].NhapSinhVien(sv);
}

void Day::XuatDsSinhVien(){
	for (int i = 0; i < SoLuongPhong; i++) {
        DsPhong[i].XuatDsSinhVien(TenDay);  // Xuất thông tin sinh viên kèm theo tên dãy
    }
}

void Day::XuatTenPhong(int thuTuDay, int thuTuPhong){
	cout<<TenDay<<"-"<<DsPhong[thuTuPhong].getTenPhong();
}
bool Day::KiemTraMSSV(string mssv){
    bool kt=true;
    for (int i=0; i<DsPhong.size();i++){
    	kt=DsPhong[i].KiemTraMSSV(mssv);
    	if (kt==false) return kt;
	}
	return kt;
}
bool Day::KiemTraPhongTrong(int thuTuDay, int thuTuPhong, string gioiTinh){
	if (LoaiDay==gioiTinh)
		return DsPhong[thuTuPhong].KiemTraPhongTrong();
	return false;
}
void Day::TimSinhVienTheoTen(string ten, int thuTuDay){
	for (int i=0; i<DsPhong.size(); i++){
		DsPhong[i].TimSinhVienTheoTen(ten, thuTuDay, i);
	}
}
//KTX
class KTX{
	private:
		vector <Day> DsDay;
		int SoLuongDay;
	public:
		
		int getSoLuongDay();
    	void setSoLuongDay(int soLuongDay);
	
		void KhoiTaoDsDay();
		void ThemSinhVien(SinhVien sv, int thuTuDay, int thuTuPhong);
		void NhapThongTinTuFile();
		void NhapSinhVien();
		void XuatDsSinhVien();
		
    	void NhapDanhSachDay();
    	void XuatDsDay();
    	
    	void XuatDsPhongTrong(string gioiTinh);
    	
    	bool KiemTraMSSV(string mssv);
    	bool KiemTraPhongTrong(int thuTuDay, int thuTuPhong, string gioiTinh);
    	
    	int TenDayInt(string tenDay);
    	int TenPhongInt(string tenPhong);
    	
    	void TimSinhVienTheoTen(string ten);
    	void TimSinhVienTheoMSSV(string mssv);
};

int KTX::getSoLuongDay(){return SoLuongDay;}
void KTX::setSoLuongDay(int soLuongDay){
	SoLuongDay=soLuongDay;
} 
void KTX::KhoiTaoDsDay(){
	SoLuongDay=5;
	DsDay.resize(SoLuongDay);
	for (int i=0; i<SoLuongDay; i++){
		DsDay[i].KhoiTaoDay(i);
	}
}
void KTX::ThemSinhVien(SinhVien sv, int thuTuDay, int thuTuPhong){
	DsDay[thuTuDay].NhapSinhVien(sv, thuTuPhong);
}


void KTX::NhapThongTinTuFile() {
    ifstream file("DanhSachSinhVien.txt");
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file de doc!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) { 
        stringstream ss(line);
        string hoTen, mssv, diaChi, lop, khoa, gioiTinh, sdt;
        int ngay, thang, nam;
        int thuTuDay, thuTuPhong;

        // Tách các phần tử từ dòng
        getline(ss, hoTen, ',');
        getline(ss, mssv, ',');
        getline(ss, diaChi, ',');
        getline(ss, lop, ',');
        getline(ss, khoa, ',');
        getline(ss, gioiTinh, ',');
        getline(ss, sdt, ',');
        ss >> ngay; ss.ignore();  
        ss >> thang; ss.ignore(); 
        ss >> nam; ss.ignore(); 
        ss >> thuTuDay; ss.ignore();
        ss >> thuTuPhong;

        // Khởi tạo đối tượng Date và SinhVien
        Date ngaySinh(ngay, thang, nam);
        SinhVien sv(hoTen, mssv, diaChi, lop, khoa, gioiTinh, sdt, ngaySinh);
		
        // Thêm sinh viên vào dãy và phòng
        ThemSinhVien(sv, thuTuDay, thuTuPhong);
    }
	cout<<"Da Nhap";
    file.close(); 
}

void KTX::NhapSinhVien(){
	SinhVien sv;
	cout<<"<*Luu y: Viet hoa chu cai dau*>"<<endl;
	sv.Nhap();
	if (!(KiemTraMSSV(sv.getMSSV()))){
		cout<<"MSSV da nhap khong hop le!";
		return;
	}
	if (!(sv.KiemTraKhoa())){
		return;
	}
	int dem=0;
	cout<<"Danh sach phong con trong:"<<endl;
	XuatDsPhongTrong(sv.getGioiTinh());
	
	string thuTuDayStr, thuTuPhongStr;
	int thuTuPhong, thuTuDay;
	do{
		cout<<"\nNhap ten day: ";
		cin>>thuTuDayStr;cin.ignore();
		cout<<"Nhap ten phong: ";
		cin>>thuTuPhongStr;cin.ignore();
		thuTuDay=TenDayInt(thuTuDayStr);
		thuTuPhong=TenPhongInt(thuTuPhongStr);
		if ((thuTuDay<0 or thuTuDay>4) and (thuTuPhong<0 or thuTuPhong>4)) cout <<"Day va phong da nhap khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	}while (((thuTuDay<0 or thuTuDay>4) and (thuTuPhong<0 or thuTuPhong>4)));
	
	if (KiemTraPhongTrong(thuTuDay,  thuTuPhong, sv.getGioiTinh())){
		ThemSinhVien(sv, thuTuDay, thuTuPhong);
		cout<<"Da them sinh vien"<<endl;
	}
	else {
		cout<<"Phong da day hoac thong tin nhap vao khong hop le!"<<endl<<endl;
	}

}

void KTX::XuatDsSinhVien(){
	 // Xuất tiêu đề bảng
    cout <<setw(7)<<"Day |"<<setw(10)<<"Phong |"<<setw(20)<<"Ho ten |"<<setw(15)<<"MSSV |"<<setw(10)<<"Lop |"<<setw(10)<<"Khoa |"<<setw(15)<<"Gioi tinh |"<<setw(15)<<"SDT |"<<setw(20)<<"Ngay sinh |\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";

    // Xuất thông tin từng dãy
    for (int i = 0; i < SoLuongDay; i++) {
//    	if (i!=0)
//    		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        DsDay[i].XuatDsSinhVien();
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
}

void KTX::XuatDsPhongTrong(string gioiTinh){
	int dem=0;
	for (int i=0; i<DsDay.size(); i++){
		for (int j=0; j<DsDay[i].getSoLuongPhong(); j++){
			if (KiemTraPhongTrong(i,j, gioiTinh)){
				cout<<"|"; DsDay[i].XuatTenPhong(i,j); cout<<"|   ";
				dem++;
			} 
		}
	}
	if (dem==0) cout<<"KTX khong con phong trong";
}

bool KTX::KiemTraMSSV(string mssv){
	bool kt=true;
    for (int i=0; i<DsDay.size();i++){
    	kt=DsDay[i].KiemTraMSSV(mssv);
    	if (kt==false) return kt;
	}
	return kt;
}
bool KTX::KiemTraPhongTrong(int thuTuDay, int thuTuPhong, string gioiTinh){
    return DsDay[thuTuDay].KiemTraPhongTrong(thuTuDay, thuTuPhong, gioiTinh);
}

int KTX::TenDayInt(string tenDay){
	
	if (tenDay=="D1") return 0;
	else if (tenDay=="D2") return 1;
	else if (tenDay=="D3") return 2;
	else if (tenDay=="N1") return 3;
	else  return 4;
}

int KTX::TenPhongInt(string tenPhong){
	if (tenPhong=="P01") return 0;
	else if (tenPhong=="P02") return 1;
	else if (tenPhong=="P03") return 2;
	else if (tenPhong=="P04") return 3;
	else  return 4;
}
void KTX::TimSinhVienTheoTen(string ten){
	for (int i=0; i<DsDay.size(); i++){
		DsDay[i].TimSinhVienTheoTen(ten,i);
	}
}
//MAIN
void XoaManHinh();
void Begin(KTX &ktx);
void menu(KTX &ktx);
void menuSV(KTX &ktx);
void menuSV1(KTX &ktx);
void menuDayPhong(KTX &ktx);

void Begin(KTX &ktx){
//	cout<<"Dang Khoi Tao Danh Sach KTX..."<<endl;
	ktx.KhoiTaoDsDay();
//	sleep(2);
	XoaManHinh();
	string c;
	do{
		cout<<"Ban co muon nhap du lieu sinh vien tu file khong [y/n]:";
		cin>>c;
		if (!(c=="y" or c=="n")) cout<<"Lua chon khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	} while (!(c=="y" or c=="n"));
	if (c=="y") ktx.NhapThongTinTuFile();
	XoaManHinh();
}

void menu(KTX &ktx) {
    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "CHON DOI TUONG THUC HIEN" << endl;
        cout << "\t1. Sinh vien" << endl;
        cout << "\t2. Day/phong" << endl;
        cout << "\t0. Thoat" << endl;
        cout << "->Nhap lua chon: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
            	XoaManHinh();
                menuSV(ktx);  
                break;
            case 2:
                
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    } while (choice != 0);
}

void menuSV(KTX &ktx) {
    int choice;
    do {
        cout << "\n--- Menu Sinh Vien ---\n";
        cout << "\t1. Nhap sinh vien" << endl;
        cout << "\t2. Xuat danh sach sinh vien" << endl;
        cout << "\t3. Tim sinh vien" << endl;
        cout << "\t4. Xoa sinh vien" << endl;
        cout << "\t0. Quay lai" << endl;
        cout << "->Nhap lua chon: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                ktx.NhapSinhVien();  
                break;
            case 2:
                ktx.XuatDsSinhVien();  
                break;
            case 3:
                 
                break;
            case 4:
                 
                break;
            case 0:
                cout << "Quay lai menu chinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    } while (choice != 0); 
}

void XoaManHinh(){system("cls");}
int main(){
	KTX ktx;
	Begin(ktx);
	XoaManHinh();
	menu(ktx);
}