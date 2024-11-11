#include <iostream>
using namespace std;
struct VDV
{
    int mdv;
    string tendv;
    int tuoi;
    float luong;
};
void Nhap_VDV(VDV &v)
{
    cout << "Nhap ma van dong vien:";
    cin >> v.mdv;
    cout << "Nhap ten van dong vien:";
    cin.ignore();
    getline(cin, v.tendv);
    cout << "Nhap tuoi:";
    cin >> v.tuoi;
    cout << "Nhap luong:";
    cin >> v.luong;
}
void Xuat_VDV(VDV v)
{
    cout << v.mdv << ", " << v.tendv << ", " << v.tuoi << ", " << v.luong << endl;
}
void Nhap(VDV ds[], int &n)
{
    cout << "Nhap so luong:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_VDV(ds[i]);
    }
}
void Xuat(VDV ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Xuat_VDV(ds[i]);
    }
}
void HoanDoi(VDV &a, VDV &b)
{
    VDV tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(VDV ds[] , int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (ds[j].luong < ds[j - 1].luong)
                HoanDoi(ds[j], ds[j - 1]);
}
void timkiem_np(int n, VDV ds[], float luong)
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
            Xuat_VDV(ds[m]);
            int left_mid = m - 1;
            while (ds[left_mid].luong == luong && left_mid >= 0)
            {
                Xuat_VDV(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (ds[right_mid].luong == luong && right_mid <= r)
            {
                Xuat_VDV(ds[right_mid]);
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
    VDV ds[100];
    Nhap(ds, n);
    Xuat(ds, n);
    BubbleSort(ds, n);
    cout << "===============================" << endl;
    Xuat(ds, n);
    cout << "Nhap so tiet da day muon tim:";
    int luong;
    cin >> luong;
    cout << "Danh sach VDV co luong = " << luong << " la:" << endl;
    timkiem_np(n, ds, luong);
}