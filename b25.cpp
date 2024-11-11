#include <iostream>
using namespace std;

struct date
{
    int ngay, thang, nam;
};

struct NhanVien
{
    int manv;
    string hoten;
    date ngaysinh;
    float luong;
};

void NV_Nhap(NhanVien &nv)
{
    cout << "Nhap ma nhan vien:";
    cin >> nv.manv;
    cout << "Nhap ho ten:";
    cin.ignore();
    getline(cin, nv.hoten);
    cout << "Nhap ngay-thang-nam:";
    cin >> nv.ngaysinh.ngay >> nv.ngaysinh.thang >> nv.ngaysinh.nam;
    cout << "Nhap luong:";
    cin >> nv.luong;
}

void NV_Xuat(NhanVien nv)
{
    cout << nv.manv << ", " << nv.hoten << ", " << nv.ngaysinh.ngay << "/" << nv.ngaysinh.thang << "/" << nv.ngaysinh.nam << ", " << nv.luong << endl;
}
void Nhap(NhanVien ds[], int &n)
{
    cout << "Nhap so luong n:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        NV_Nhap(ds[i]);
    }
}
void Xuat(NhanVien ds[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        NV_Xuat(ds[i]);
    }
}
void Swap (NhanVien a, NhanVien b){
   NhanVien tmp = a;
   a = b;
   b = tmp;
}
void SelectionSort(NhanVien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[i].luong> a[j].luong)
                minIdx = j;
        Swap(a[i], a[minIdx]);
    }
}
void timkiem_nhiphan(NhanVien ds[], int n, int _luong)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].luong == _luong)
        {
            founded = true;
            NV_Xuat(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].luong == _luong)
            {
                NV_Xuat(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].luong == _luong)
            {
                NV_Xuat(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].luong > _luong ){
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if(!founded)
        cout << "KHONG CO PHAN TU CO luong LA: " << _luong << "TRONG DANH SACH!!" << endl; 
}
int main()
{
    int n;
    NhanVien ds[50];
    Nhap(ds, n);
    Xuat(ds, n);
    cout << "====================================" << endl;
    SelectionSort(ds, n);
    Xuat(ds, n);
    cout << "Nhap luong muon tim:";
    int _luong;
    cin >> _luong;
    timkiem_nhiphan(ds, n, _luong);    
}