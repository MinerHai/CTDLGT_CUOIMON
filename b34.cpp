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
void HoanDoi(NhanVien &a, NhanVien &b)
{
    NhanVien tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(NhanVien ds[] , int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (ds[j].luong < ds[j - 1].luong)
                HoanDoi(ds[j], ds[j - 1]);
}
void timkiem_np(int n, NhanVien ds[], float luong)
{
    int l = 0;
    int r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / r;
        if (ds[m].luong == luong)
        {
            founded = true;
            NV_Xuat(ds[m]);
            int left_mid = m - 1;
            while (ds[left_mid].luong == luong && left_mid >= 0)
            {
                NV_Xuat(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (ds[right_mid].luong == luong && right_mid <= r)
            {
                NV_Xuat(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].luong < luong)
        {
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if (!founded)
        cout << "KHONG CO PHAN TU NAO TRONG MANG!!" << endl;
}
int main()
{
    int n;
    NhanVien ds[100];
    Nhap(ds, n);
    Xuat(ds, n);
    BubbleSort(ds, n);
    cout << "===============================" << endl;
    Xuat(ds, n);
    cout << "Nhap so tiet da day muon tim:";
    int luong;
    cin >> luong;
    cout << "Danh sach NhanVien co luong = " << luong << " la:" << endl;
    timkiem_np(n, ds, luong);
}