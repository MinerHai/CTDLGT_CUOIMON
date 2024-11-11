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
    cout << "Nhap so luong: ";
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
void Swap(VDV a, VDV b)
{
    VDV tmp = a;
    a = b;
    b = tmp;
}
void SelectionSort(VDV a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[i].luong > a[j].luong)
                minIdx = j;
        Swap(a[i], a[minIdx]);
    }
}
void timkiem_nhiphan(VDV ds[], int n, int _luong)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].luong == _luong)
        {
            founded = true;
            Xuat_VDV(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].luong == _luong)
            {
                Xuat_VDV(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].luong == _luong)
            {
                Xuat_VDV(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].luong > _luong)
        {
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if (!founded)
        cout << "KHONG CO PHAN TU CO luong LA: " << _luong << "TRONG DANH SACH!!" << endl;
}
int main()
{
    int n;
    VDV ds[50];
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