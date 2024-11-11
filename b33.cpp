#include <iostream>
using namespace std;
struct KhachHang
{
    int mkh;
    string tenkh;
    string sdt;
    float tongtien;
};
void Nhap_HH(KhachHang &hh)
{
    cout << "Nhap ma khach hang:";
    cin >> hh.mkh;
    cin.ignore();
    cout << "Nhap ten khach hang:";
    getline(cin, hh.tenkh);
    cout << "Nhap so dien thoai:";
    getline(cin, hh.sdt);
    cout << "Nhap tongtien:";
    cin >> hh.tongtien;
}
void Xuat_KH(KhachHang hh)
{
    cout << hh.mkh << ", " << hh.tenkh << ", " << hh.sdt <<", "<< hh.tongtien << endl;
}
void Nhap(KhachHang ds[], int &n)
{
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_HH(ds[i]);
    }
}

void Xuat(KhachHang ds[], int n)
{
    for (int i = 0; i < n; i++)
        Xuat_KH(ds[i]);
}
void HoanDoi(KhachHang &a, KhachHang &b)
{
    KhachHang tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(KhachHang ds[] , int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (ds[j].tongtien < ds[j - 1].tongtien)
                HoanDoi(ds[j], ds[j - 1]);
}
void timkiem_np(int n, KhachHang ds[], float tongtien)
{
    int l = 0;
    int r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / r;
        if (ds[m].tongtien == tongtien)
        {
            founded = true;
            Xuat_KH(ds[m]);
            int left_mid = m - 1;
            while (ds[left_mid].tongtien == tongtien && left_mid >= 0)
            {
                Xuat_KH(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (ds[right_mid].tongtien == tongtien && right_mid <= r)
            {
                Xuat_KH(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].tongtien < tongtien)
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
    KhachHang ds[100];
    Nhap(ds, n);
    Xuat(ds, n);
    BubbleSort(ds, n);
    cout << "===============================" << endl;
    Xuat(ds, n);
    cout << "Nhap so tiet da day muon tim:";
    int tongtien;
    cin >> tongtien;
    cout << "Danh sach KhachHang co tongtien = " << tongtien << " la:" << endl;
    timkiem_np(n, ds, tongtien);
}