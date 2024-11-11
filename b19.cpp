#include <iostream>
using namespace std;
struct DuAn
{
    int maduAn;
    string tenduAn;
    float tongkinhphi;
};
void Nhap_DuAn(DuAn &da)
{
    cout << "Nhap ma du an:";
    cin >> da.maduAn;
    cout << "Nhap ten du an:";
    cin.ignore();
    getline(cin, da.tenduAn);
    cout << "Nhap tong kinh phi:";
    cin >> da.tongkinhphi;
}
void Xuat_DuAn(DuAn da)
{
    cout << da.maduAn << ", " << da.tenduAn << ", " << da.tongkinhphi << endl;
}


void Nhap(DuAn ds[], int &n)
{
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_DuAn(ds[i]);
    }
}

void Xuat(DuAn ds[], int n)
{
    for (int i = 0; i < n; i++)
        Xuat_DuAn(ds[i]);
}
void insertion_Sort(DuAn ds[], int n)
{
    for (int i = 1; i < n; i++)
    {
        DuAn tmp = ds[i];
        int pos = i - 1;
        while (pos >= 0 && ds[pos].tongkinhphi > tmp.tongkinhphi)
        {
            ds[pos + 1] = ds[pos];
            pos--;
        }
        ds[pos + 1] = tmp;
    }
}
void timkiem_nhiphan(DuAn ds[], int n, int _gia)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].tongkinhphi == _gia)
        {
            founded = true;
            Xuat_DuAn(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].tongkinhphi == _gia)
            {
                Xuat_DuAn(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].tongkinhphi == _gia)
            {
                Xuat_DuAn(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].tongkinhphi > _gia ){
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if(!founded)
        cout << "KHONG CO PHAN TU CO GIA LA: " << _gia << "TRONG DANH SACH!!" << endl; 
}
int main()
{
    int n;
    DuAn ds[50];
    Nhap(ds, n);
    Xuat(ds, n);
    cout << "====================================" << endl;
    insertion_Sort(ds, n);
    Xuat(ds, n);
    cout << "Nhap gia muon tim:";
    int _gia;
    cin >> _gia;
    timkiem_nhiphan(ds, n, _gia);    
}