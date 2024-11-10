#include <iostream>
using namespace std;
struct TaiLieu
{
    int mtl;
    string tentl;
    int namxb;
    float giaban;
};

void Nhap_TL(TaiLieu &tl)
{
    cout << "Nhap ma tai lieu: ";
    cin >> tl.mtl;
    cout << "Nhap ten tai lieu: ";
    cin.ignore();
    getline(cin, tl.tentl);
    cout << "Nhap nam xuat ban:";
    cin >> tl.namxb;
    cout << "Nhap gia ban:";
    cin >> tl.giaban;
}

void Xuat_TL(TaiLieu tl)
{
    cout << tl.mtl << ", " << tl.tentl << ", " << tl.namxb << " " << tl.giaban << endl;
}

void Nhap(TaiLieu ds[], int &n)
{
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_TL(ds[i]);
    }
}

void Xuat(TaiLieu ds[], int n)
{
    for (int i = 0; i < n; i++)
        Xuat_TL(ds[i]);
}
void insertion_Sort(TaiLieu ds[], int n)
{
    for (int i = 1; i < n; i++)
    {
        TaiLieu tmp = ds[i];
        int pos = i - 1;
        while (pos >= 0 && ds[pos].giaban > tmp.giaban)
        {
            ds[pos + 1] = ds[pos];
            pos--;
        }
        ds[pos + 1] = tmp;
    }
}
void timkiem_nhiphan(TaiLieu ds[], int n, int _gia)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].giaban == _gia)
        {
            founded = true;
            Xuat_TL(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].giaban == _gia)
            {
                Xuat_TL(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].giaban == _gia)
            {
                Xuat_TL(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].giaban > _gia ){
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
    TaiLieu ds[50];
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