#include <iostream>
using namespace std;
struct MonHoc
{
    int mamh;
    string tenmh;
    int sotc;
    int sotietdaday;
};

void Nhap_MH(MonHoc &mh)
{
    cout << "Nhap ma mon hoc:";
    cin >> mh.mamh;
    cout << "Nhap ten mon hoc:";
    cin.ignore();
    getline(cin, mh.tenmh);
    cout << "Nhap so tin chi:";
    cin >> mh.sotc;
    cout << "Nhap so tiet da day:";
    cin >> mh.sotietdaday;
}

void Xuat_MH(MonHoc mh)
{
    cout << mh.mamh << ", " << mh.tenmh << ", " << mh.sotc << ", " << mh.sotietdaday << endl;
}


void Nhap(MonHoc ds[], int &n)
{
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_MH(ds[i]);
    }
}

void Xuat(MonHoc ds[], int n)
{
    for (int i = 0; i < n; i++)
        Xuat_MH(ds[i]);
}
void insertion_Sort(MonHoc ds[], int n)
{
    for (int i = 1; i < n; i++)
    {
        MonHoc tmp = ds[i];
        int pos = i - 1;
        while (pos >= 0 && ds[pos].sotietdaday > tmp.sotietdaday)
        {
            ds[pos + 1] = ds[pos];
            pos--;
        }
        ds[pos + 1] = tmp;
    }
}
void timkiem_nhiphan(MonHoc ds[], int n, int _gia)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].sotietdaday == _gia)
        {
            founded = true;
            Xuat_MH(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].sotietdaday == _gia)
            {
                Xuat_MH(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].sotietdaday == _gia)
            {
                Xuat_MH(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].sotietdaday > _gia ){
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
    MonHoc ds[50];
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