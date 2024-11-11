#include <iostream>
using namespace std;
struct VeMayBay
{
    int mave;
    string khoihanh;
    string diemden;
    float giave;
};

void Nhap_ve(VeMayBay &ve)
{
    cout << "Nhap ma ma ve: ";
    cin >> ve.mave;
    cout << "Nhap diem khoi hanh: ";
    cin.ignore();
    getline(cin, ve.khoihanh);
    cout << "Nhap diem den: ";
    cin.ignore();
    getline(cin, ve.diemden);
    cout << "Nhap gia ban:";
    cin >> ve.giave;
}

void Xuat_ve(VeMayBay ve)
{
    cout << ve.mave << ", " << ve.khoihanh << ", " << ve.diemden << " " << ve.giave << endl;
}

void Nhap(VeMayBay ds[], int &n)
{
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_ve(ds[i]);
    }
}

void Xuat(VeMayBay ds[], int n)
{
    for (int i = 0; i < n; i++)
        Xuat_ve(ds[i]);
}
void insertion_Sort(VeMayBay ds[], int n)
{
    for (int i = 1; i < n; i++)
    {
        VeMayBay tmp = ds[i];
        int pos = i - 1;
        while (pos >= 0 && ds[pos].giave > tmp.giave)
        {
            ds[pos + 1] = ds[pos];
            pos--;
        }
        ds[pos + 1] = tmp;
    }
}
void timkiem_nhiphan(VeMayBay ds[], int n, int _gia)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].giave == _gia)
        {
            founded = true;
            Xuat_ve(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].giave == _gia)
            {
                Xuat_ve(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].giave == _gia)
            {
                Xuat_ve(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].giave > _gia ){
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
    VeMayBay ds[50];
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