#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include<iomanip>
#include <unordered_map>
using namespace std;

class Sach
{
protected:
    string tensach;
    string masach;
    string tacgia;
    string theloai;
    string ngaymuon;
    string tinhtrang;

public:
    // Ham khoi tao
    Sach(string tensach,
         string masach,
         string tacgia,
         string theloai,
         string ngaymuon,
         string tinhtrang)
    {
        this->tensach = tensach;
        this->masach = masach;
        this->tacgia = tacgia;
        this->theloai = theloai;
        this->ngaymuon = ngaymuon;
        this->tinhtrang = tinhtrang;
    }

    Sach()
    {
        tensach = "0";
    }

    void nhapthongtin()
    {
        cin.ignore();
        cout << "1. Nhap ten sach: ";
        getline(cin, tensach);
        cout << "2. Nhap ma sach: ";
        getline(cin, masach);
        cout << "3. Nhap tac gia: ";
        getline(cin, tacgia);
        cout << "4. Nhap the loai: ";
        getline(cin, theloai);
        cout << "5. Nhap ngay muon: ";
        getline(cin, ngaymuon);
        cout << "6. Nhap tinh trang: ";
        getline(cin, tinhtrang);
        cin.ignore();
    }

    // ham hien thi thong tin
    void hienthithongtin()
    {
        cout << "Ten sach: " << tensach << endl;
        cout << "Ma sach: " << masach << endl;
        cout << "Tac gia: " << tacgia << endl;
        cout << "The loai: " << theloai << endl;
        cout << "Ngay muon: " << ngaymuon << endl;
        cout << "Tinh trang: " << tinhtrang << endl;
    }
    string getFullInfo()
    {
        string nl = "\n";
        return tensach + nl + masach + nl + tacgia + nl + theloai + nl + ngaymuon + nl + tinhtrang;
    }
    string
    GetterTensach()
    {
        return this->tensach;
    }

    string
    GetterMasach()
    {
        return this->masach;
    }
};

class TimKiemSach : public Sach
{
public:
    static void Tim_Kiem_Thong_Tin_Danh_Sach_Theo_Tensach(vector<Sach> &ds)
    {
        string tensach;
        cin.ignore();
        cout << "\nMoi ban nhap ten sach can tim: ";
        getline(cin, tensach);

        for (int i = 0; i < ds.size(); i++)
        {
            if (strcmp(tensach.c_str(), ds[i].GetterTensach().c_str()) == 0)
            {
                ds[i].hienthithongtin();
            }
        }
        system("pause");
    }

    static void Tim_Kiem_Thong_Tin_Danh_Sach_Theo_Masach(vector<Sach> &ds)
    {
        string masach;
        cin.ignore();
        cout << "\nMoi ban nhap ma sach can tim: ";
        getline(cin, masach);

        for (int i = 0; i < ds.size(); i++)
        {
            if (strcmp(masach.c_str(), ds[i].GetterMasach().c_str()) == 0)
            {
                ds[i].hienthithongtin();
                system("pause");
                
            }
        }
    }
    static void Cap_Nhat_Thong_Tin(vector<Sach> &ds)
    {
        string masach;
        cout << "Nhap ma sach de cap nhat thong tin: " << endl;
        cin.ignore();
        getline(cin, masach);
        for (int i = 0; i < ds.size(); i++)
        {
            if (strcmp(masach.c_str(), ds[i].GetterMasach().c_str()) == 0)
            {
                ds[i].nhapthongtin();

                system("pause");
               
            }
        }
        system("pause");
    }
    static void Xoa_Thong_Tin(vector<Sach> &ds)
    {
        string masach;
        cout << "Nhap ma sach de xoa thong tin: " << endl;
        cin.ignore();
        getline(cin, masach);
        int vitrixoa = -1;
        for (int i = 0; i < ds.size(); i++)
        {
            if (strcmp(masach.c_str(), ds[i].GetterMasach().c_str()) == 0)
            {
                vitrixoa = i;
                break;
            }
        }
        if (vitrixoa == -1)
            cout << "Khong tim duoc thong tin can xoa:" << endl;
        else
        {
            ds.erase(ds.begin() + vitrixoa);
        }
    }
};

// ham nhap thong tin cho danh sach sach
void Nhap_Thong_Tin_Danh_Sach(vector<Sach> &ds)
{
    Sach x;
    x.nhapthongtin();
    ds.push_back(x);
}

void Hien_Thi_Thong_Tin_Danh_Sach(vector<Sach> &ds)
{
    for (int i = 0; i < ds.size(); i++)
    {
        cout << "\n\tThong tin sach thu " << i + 1 << " : ";
        ds[i].hienthithongtin();
    }
    system("pause");
}
// Thiet lap menu
void MenuSach(vector<Sach> &ds)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ============= QUAN LI =============";
        cout << "\n\t\t1. Nhap thong tin danh sach";
        cout << "\n\t\t2. Xuat thong tin danh sach";
        cout << "\n\t\t3. Tim kiem thong tin theo ten sach";
        cout << "\n\t\t4. Tim kiem thong tin theo ma sach";
        cout << "\n\t\t5. Cap nhat thong tin";
        cout << "\n\t\t6. Xoa thong tin";
        cout << "\n\t\t7. Thoat chuong trinh va luu file";

        cout << "\nNhap lua chon:";
        cin >> luachon;

        if (luachon == 1)
        {
            Nhap_Thong_Tin_Danh_Sach(ds);
        }

        else if (luachon == 2)
        {
            Hien_Thi_Thong_Tin_Danh_Sach(ds);
        }

        else if (luachon == 3)
        {
            TimKiemSach::Tim_Kiem_Thong_Tin_Danh_Sach_Theo_Tensach(ds);
        }

        else if (luachon == 4)
        {
            TimKiemSach::Tim_Kiem_Thong_Tin_Danh_Sach_Theo_Masach(ds);
        }
        else if (luachon == 5)
        {
            TimKiemSach::Cap_Nhat_Thong_Tin(ds);
        }
        else if (luachon == 6)
        {
            TimKiemSach::Xoa_Thong_Tin(ds);
        }
        else if (luachon == 7)
        {
            return;
        }
    }
}
void Viet_Xuat_File(string file, vector<Sach> &ds)
{
    ofstream fileOutput(file);

    if (fileOutput.fail())
    {
        cout << " Khong the mo file  " << file << endl;
        return;
    }
    for (int i = 0; i < ds.size(); i++)
    {
        fileOutput << ds[i].getFullInfo();
        if (i != ds.size() - 1)
            fileOutput << "\n";
    }
}
void Doc_File(string file, vector<Sach> &ds)
{
    ifstream fileInput(file);
    if (fileInput.fail())
    {
        cout << " Khong the mo file  " << file << endl;
        return;
    }

    while (!fileInput.eof())
    {
        char tensach[255],
            masach[255],
            tacgia[255],
            theloai[255],
            ngaymuon[255],
            tinhtrang[255];

        fileInput.getline(tensach, 255);
        fileInput.getline(masach, 255);
        fileInput.getline(tacgia, 255);
        fileInput.getline(theloai, 255);
        fileInput.getline(ngaymuon, 255);
        fileInput.getline(tinhtrang, 255);
        string tens = tensach, ma = masach, tg = tacgia, tl = theloai,
               ngaym = ngaymuon,
               ttrang = tinhtrang;
        Sach s(tens, ma, tg, tl, ngaym, ttrang);
        ds.push_back(s);
    }
}


class Book {
protected:
    string bookname;
    string author;
    string bookcode;
    int pages;

public:
    Book() {}

    Book(string bookname, string author, string bookcode, int pages) {
        this->bookname = bookname;
        this->author = author;
        this->bookcode = bookcode;
        this->pages = pages;
    }

    void PrintInfoBook() const {
        cout << "\nBookname: " << bookname;
        cout << "\nAuthor: " << author;
        cout << "\nBookcode: " << bookcode;
        cout << "\nPages: " << pages << endl;
    }

    void DocFile(ifstream &infile) {
        getline(infile, bookname);
        getline(infile, author);
        getline(infile, bookcode);
        infile >> pages;
        infile.ignore(); // Để bỏ qua ký tự newline sau pages
    }

    void GetInformation() {
        cin.ignore();
        cout << "\nNhap ten sach: ";
        getline(cin, bookname);
        cout << "\nNhap Tac Gia: ";
        getline(cin, author);
        cout << "\nNhap ma sach: ";
        getline(cin, bookcode);
        cout << "\nNhap so trang: ";
        cin >> pages;
    }

    string GetterBookname() const { return bookname; }
    string GetterAuthor() const { return author; }
    string GetterBookcode() const { return bookcode; }
    int GetterPage() const { return pages; }
};

// Cấu trúc để lưu trữ thông tin sinh viên mượn sách
class BorrowInfo {
    private:
    	string studentName;
    	string studentID;
	protected:
    Book book;
    

public:
    BorrowInfo() {}
    string GetStudentName() const { return studentName; }
    void SetStudentName(const string& name) {
        studentName = name;
    }
    string GetStudentID() const { return studentID; }
    void SetStudentID(const string& id) {
        studentID = id;
    }
    Book GetBorrowedBook() const { return book; }
    BorrowInfo(const Book& book, const string& studentName, const string& studentID) : book(book), studentName(studentName), studentID(studentID) {}

    void PrintInfoBorrowInfo() const {
        cout << "\nStudent Name: " << studentName;
        cout << "\nStudent ID: " << studentID;
        cout << "\nBook Information:";
        book.PrintInfoBook();
    }

};
// Hàm để in thông tin sinh viên mượn sách
void In_Thong_Tin_Sinh_Vien_Muon_Sach(const vector<BorrowInfo>& borrowList) {
    cout << "\n\n\t\t =================== DANH SACH SINH VIEN MUON SACH =========================\n";
    for (int j = 0; j < 72; j++) {
        cout << "_";
    }
    cout << endl;

    for (int i = 0; i < borrowList.size(); i++) {
        cout << "\nTen sinh vien: " << borrowList[i].GetStudentName();
        cout << "\nMa sinh vien: " << borrowList[i].GetStudentID(); // Assume GetStudentID() is a method in BorrowInfo
        cout << "\nThong tin sach muon: ";
        borrowList[i].GetBorrowedBook().PrintInfoBook(); // Assume GetBook() is a method in BorrowInfo returning a Book object
        cout << endl;
    }
}


void Doc_File_Danh_Sach_Book(ifstream &filein, vector<Book> &ds_sach) {
    while (!filein.eof()) {
        Book x;
        x.DocFile(filein);
        ds_sach.push_back(x);
        string temp;
        getline(filein, temp); // to skip to the next line
    }
}

void In_Danh_Sach_Sach(const vector<Book> &ds) {
    cout << "\n\n\t\t =================== DANH SACH SACH =========================\n";
    for (int j = 0; j < 72; j++) {
        cout << "_";
    }
    cout << endl;

    cout << "|STT|" << setw(25) << "Ten sach" << "|" << setw(21) << "Tac gia" << "|Ma sach  |" << "So trang|" << endl;
    cout << "|___|_________________________|_____________________|_________|________|" << endl;

    for (int i = 0; i < ds.size(); i++) {
        cout << "|" << setw(3) << i + 1 << "|"
             << setw(25) << ds[i].GetterBookname() << "|"
             << setw(21) << ds[i].GetterAuthor() << "|"
             << setw(9) << ds[i].GetterBookcode() << "|"
             << setw(8) << ds[i].GetterPage() << "|" << endl;

        cout << "|___|_________________________|_____________________|_________|________|" << endl;
    }
    system("pause");
}

void Them_Thong_Tin_Sach(vector<Book> &ds) {
    int n;
    cout << "\nNhap so luong sach can them: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap Thong Tin Sach Thu " << i + 1 << ": ";
        Book temp;
        temp.GetInformation();
        ds.push_back(temp);
    }
}

void Xoa_Thong_Tin_Sach_Theo_Ten_Sach(vector<Book> &ds) {
    int n;
    cout << "\nNhap so quyen sach can xoa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin.ignore();
        cout << "\nNhap ten quyen sach can xoa thu " << i + 1 << ": ";
        getline(cin, x);
        for (int j = 0; j < ds.size(); j++) {
            if (strcasecmp(x.c_str(), ds[j].GetterBookname().c_str()) == 0) {
                ds.erase(ds.begin() + j);
                cout << "Da xoa sach!\n";
                break;
            }
        }
    }
}

void Xoa_Thong_Tin_Sach_Theo_Ma_Sach(vector<Book> &ds) {
    int n;
    cout << "\nNhap so quyen sach can xoa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin.ignore();
        cout << "\nNhap ma sach can xoa thu " << i + 1 << ": ";
        getline(cin, x);
        for (int j = 0; j < ds.size(); j++) {
            if (strcasecmp(x.c_str(), ds[j].GetterBookcode().c_str()) == 0) {
                ds.erase(ds.begin() + j);
                cout << "Da xoa sach!\n";
                break;
            }
        }
    }
}

void Tim_Kiem_Thong_Tin_Sach_Theo_Ten_Sach(const vector<Book> &ds) {
    string s;
    cin.ignore();
    cout << "\nMoi ban nhap ten sach tim kiem: ";
    getline(cin, s);
    for (int i = 0; i < ds.size(); i++) {
        if (strcasecmp(s.c_str(), ds[i].GetterBookname().c_str()) == 0) {
            cout << "\nSach can tim la: ";
            ds[i].PrintInfoBook();
        }
    }
    system("pause");
}

void Tim_Kiem_Thong_Tin_Sach_Theo_Tac_Gia(const vector<Book> &ds) {
    string s;
    cin.ignore();
    cout << "\nMoi ban nhap ten tac gia tim kiem: ";
    getline(cin, s);
    for (int i = 0; i < ds.size(); i++) {
        if (strcasecmp(s.c_str(), ds[i].GetterAuthor().c_str()) == 0) {
            cout << "\nSach can tim la: ";
            ds[i].PrintInfoBook();
        }
    }
    system("pause");
}

void Tim_Kiem_Thong_Tin_Sach_Theo_Ma_Sach(const vector<Book> &ds) {
    string s;
    cin.ignore();
    cout << "\nMoi ban nhap ma sach tim kiem: ";
    getline(cin, s);
    for (int i = 0; i < ds.size(); i++) {
        if (strcasecmp(s.c_str(), ds[i].GetterBookcode().c_str()) == 0) {
            cout << "\nSach can tim la: ";
            ds[i].PrintInfoBook();
        }
    }
    system("pause");
}

void Ghi_Danh_Sach_Sach(ofstream &outfile, const vector<Book> &ds) {
    for (const auto& book : ds) {
        outfile << book.GetterBookname() << endl;
        outfile << book.GetterAuthor() << endl;
        outfile << book.GetterBookcode() << endl;
        outfile << book.GetterPage() << endl;
    }
}
bool KiemTraTenSach(const vector<Book>& ds_sach, const string& tenSach) {
    for (const Book& sach : ds_sach) {
        if (sach.GetterBookname() == tenSach) {
            return true; // Tìm thấy tên sách trong danh sách
        }
    }
    return false; // Không tìm thấy tên sách trong danh sách
}
Book timSachTheoTen(const vector<Book>& ds_sach, const string& tenSach) {
    for (const Book& sach : ds_sach) {
        if (sach.GetterBookname() == tenSach) {
            return sach;
        }
    }
    return Book();
    // Nếu không tìm thấy sách, bạn có thể trả về một sách mặc định hoặc xử lý theo ý của bạn
}
void Menusach(vector<Book> &ds_sach, vector<BorrowInfo> &borrowList) {
    int luachon1;
    while (true) {
        system("cls");
        cout << "\n\n\t\t ================== QUAN LI SACH =================";
        cout << "\n\t\t0. GHI DANH SACH SACH RA MAN HINH";
        cout << "\n\t\t1. GHI DANH SACH SACH RA FILE";
        cout << "\n\t\t2. THEM SACH VAO DANH SACH SACH THU VIEN";
        cout << "\n\t\t3. XOA SACH O DANH SACH THU VIEN THEO TEN";
        cout << "\n\t\t4. XOA SACH O DANH SACH THU VIEN THEO MA";
        cout << "\n\t\t5. TIM KIEM SACH THEO TEN";
        cout << "\n\t\t6. TIM KIEM SACH THEO TAC GIA";
        cout << "\n\t\t7. TIM KIEM SACH THEO MA SACH";
        cout << "\n\t\t8. XEM THONG TIN SINH VIEN MUON SACH";
        cout << "\n\t\t9. THEM THONG TIN SINH VIEN MUON SACH";
        cout << "\n\t\t10. THOAT";
        cout << "\n\nMoi ban nhap lua chon: ";
        cin >> luachon1;

        if (luachon1 == 10) {
            break;
        }

        switch (luachon1) {
            case 0:
                In_Danh_Sach_Sach(ds_sach);
                break;
            case 1: {
                ofstream outfile("DanhSachSach.txt");
                if (outfile.is_open()) {
                    Ghi_Danh_Sach_Sach(outfile, ds_sach);
                    outfile.close();
                    cout << "\nDa ghi danh sach sach ra file 'DanhSachSach.txt' thanh cong!\n";
                } else {
                    cout << "\nKhong the mo file de ghi!\n";
                }
                system("pause");
                break;
            }
            case 2:
                Them_Thong_Tin_Sach(ds_sach);
                break;
            case 3:
                Xoa_Thong_Tin_Sach_Theo_Ten_Sach(ds_sach);
                break;
            case 4:
                Xoa_Thong_Tin_Sach_Theo_Ma_Sach(ds_sach);
                break;
            case 5:
                Tim_Kiem_Thong_Tin_Sach_Theo_Ten_Sach(ds_sach);
                break;
            case 6:
                Tim_Kiem_Thong_Tin_Sach_Theo_Tac_Gia(ds_sach);
                break;
            case 7:
                Tim_Kiem_Thong_Tin_Sach_Theo_Ma_Sach(ds_sach);
                break;
            case 8:
                In_Thong_Tin_Sinh_Vien_Muon_Sach(borrowList);
                system("pause");
                break;
            case 9: {
                BorrowInfo borrowInfo;
                cin.ignore();
                cout << "\nNhap ten sinh vien: ";
                string name;
                getline(cin, name);
                borrowInfo.SetStudentName(name);
                
                cout << "\nNhap ma sinh vien: ";
                string id;
                getline(cin, id);
                borrowInfo.SetStudentID(id);

                 while (true) {
        string tenSach;
        cout << "\nNhap ten sach muon: ";
        getline(cin, tenSach);

        if (KiemTraTenSach(ds_sach, tenSach)) {
            borrowInfo.GetBorrowedBook()= timSachTheoTen(ds_sach, tenSach); // Gán sách mượn vào borrowInfo
            borrowList.push_back(borrowInfo);
            cout << "\nDa them thong tin sinh vien muon sach!\n";
            break;
        } else {
            cout << "\nTen sach khong ton tai. Vui long nhap lai!\n";
        }
    }
    system("pause");
}
            default:
                cout << "\nLua chon khong hop le. Vui long chon lai.\n";
                system("pause");
                break;
        }
    }
}
struct TaiKhoan {
    string tenDangNhap;
    string matKhau;
};

void taiTaiKhoan(const string& filePath, unordered_map<string, string>& taiKhoan) {
    ifstream file(filePath);
    string tenDangNhap, matKhau;
    while (file >> tenDangNhap >> matKhau) {
        taiKhoan[tenDangNhap] = matKhau;
    }
    file.close();
}

bool dangNhap(const unordered_map<string, string>& taiKhoan) {
    string tenDangNhap, matKhau;
    cout << "Nhập tên đăng nhập: ";
    cin >> tenDangNhap;
    cout << "Nhập mật khẩu: ";
    cin >> matKhau;
    auto it = taiKhoan.find(tenDangNhap);
    if (it != taiKhoan.end() && it->second == matKhau) {
        return true;
    } else {
        cout << "Tên đăng nhập hoặc mật khẩu không đúng!" << endl;
        return false;
    }
}


void QuanLy(vector<Book> &ds_sach, vector<BorrowInfo> &borrowList, string filein, vector<Sach> &ds, string filePath,string fileTaiKhoan)
{
unordered_map<string, string> taiKhoan;
    taiTaiKhoan(fileTaiKhoan, taiKhoan);
    int choice;

    while (true)
    {
        cout << "----- QUAN LY -----" << endl;
        cout << "1. Thu vien sach" << endl;
        cout << "2. Quan ly" << endl;
        cout << "3. Thoat" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Menusach(ds_sach,borrowList);
            break;
        case 2:
           if(dangNhap(taiKhoan)) {
                MenuSach(ds);
                Viet_Xuat_File(filePath, ds);
            }
            break;
        case 3:
            return;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }
}
string tenTaiKhoan="";
void Login(){
    int choice;
    string filetaikhoan = "D:/taikhoan.txt";
    map<string, string> maptk;
    
    std::ifstream inputFile("D:/taikhoan.txt");
    string key, value;
    while(inputFile >> key >> value) {
        maptk.insert(make_pair(key,value));
    }
    inputFile.close();
    

    while (tenTaiKhoan.length()==0)
    {
        cout << "----- Dang nhap -----" << endl;
        cout << "1. Dang nhap" << endl;
        cout << "2. Dang ki" << endl;
        cout << "3. Thoat" << endl;
        cin >> choice;
        switch (choice)
        {
       case 1:{
    string tk,mk;
    cout<<"Nhap tai khoan:";
    cin>>tk; //tai khoan
            
    auto tim=maptk.find(tk);
    if (tim==maptk.end()) {
        cout<<"Tai khoan khong ton tai"<<endl;
        break;
    }
    
    cout<<endl<<"Nhap mat khau:";
    cin>>mk; //mat khau
            
    if (maptk[tk]==mk) {
        tenTaiKhoan=tk;
        cout<<"Dang nhap thanh cong"<<endl;
        
        // Ghi thông tin đăng nhập vào file nếu đăng nhập thành công
        std::ofstream outputFile(filetaikhoan, std::ofstream::app);
        outputFile << tk << ' ' << mk << '\n';
        outputFile.close();
    }
    else {
        cout<<"Dang nhap that bai"<<endl;
    }
    break;
}
case 2:{
    string tk,mk;
    cout<<"Dang ki"<<endl;
    cout<<"Nhap tai khoan:";
    cin>>tk; //tai khoan
    
    // Kiểm tra xem tài khoản đã tồn tại chưa
    auto tim=maptk.find(tk);
    if (tim != maptk.end()) {
        cout<<"Tai khoan da ton tai"<<endl;
        break;
    }
    
    cout<<endl<<"Nhap mat khau:";
    cin>>mk; //mat khau
            
    // Mở file để ghi thông tin tài khoản mới
    std::ofstream outputFile(filetaikhoan, std::ofstream::app);
    // Ghi thông tin tài khoản mới vào file
    outputFile << tk << ' ' << mk << '\n';
    outputFile.close();
    
    // Cập nhật thông tin trong bộ nhớ
    maptk.insert(make_pair(tk,mk));
    tenTaiKhoan=tk;
    cout<<"Dang ki thanh cong"<<endl; 
    break;
}

        case 3:
            return;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    }
}


int main()
{
    // Duong xuat file o tai o dia D

    string filePath = "D:\\quanly.txt";
    string filein = "D:\\DanhSachSach.txt";
    string fileTaikhoan = "D:\\accounts.txt";
    vector<Sach> ds;
    vector<Book> ds_sach;
     vector<BorrowInfo> borrowList;
    // KhachHang
    Doc_File(filePath, ds);
    Login();
    
    if (tenTaiKhoan.length()>0)
    {
         QuanLy(ds_sach, borrowList, filein, ds, filePath,fileTaikhoan);

    cout << " Ban co the xem file code cpp o : https://github.com/ttvu77/ttv77 " << endl;
    }
  ifstream bookFile(filein);
    if (bookFile.is_open()) {
        Doc_File_Danh_Sach_Book(bookFile, ds_sach);
        bookFile.close();
    } else {
        cout << "Không thể mở file " << filein << endl;
    }

    
      Menusach(ds_sach,borrowList);
    
    //Login bang file taikhoan.txt , moi dong ghi taikhoan matkhau
    //abc 123
    //admin 12345
    

    return 0;
}
