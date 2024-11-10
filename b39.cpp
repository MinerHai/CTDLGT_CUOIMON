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
    cout << "Nhap so luong:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_MH(ds[i]);
    }
}
void Xuat(MonHoc ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Xuat_MH(ds[i]);
    }
}
void HoanDoi(MonHoc &a, MonHoc &b)
{
    MonHoc tmp = a;
    a = b;
    b = tmp;
}
void BubbleSort(MonHoc ds[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (ds[j].sotietdaday < ds[j - 1].sotietdaday)
                HoanDoi(ds[j], ds[j - 1]);
}

void timkiem_np(MonHoc ds[], int n, int _sotietdaday)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].sotietdaday == _sotietdaday)
        {
            Xuat_MH(ds[m]);
            founded = true;
            int i = m + 1;
            while ( i <= r && ds[i].sotietdaday == _sotietdaday)
            {
                Xuat_MH(ds[i]);
                i++;
            }
            int j = m - 1;
            while (j >= l && ds[j].sotietdaday == _sotietdaday)
            {
                Xuat_MH(ds[j]);
                j--;
            }
            break;
        }
        else if (ds[m].sotietdaday < _sotietdaday)
            l = m + 1;
        else
            r = m - 1;
    }
    if (!founded) cout << "KHONG CO PHAN TU NAO TRONG MANG!! " << endl;
}
int main()
{
    int n;
    MonHoc ds[100];
    Nhap(ds, n);
    Xuat(ds, n);
    BubbleSort(ds, n);
    cout << "===============================" << endl;
    Xuat(ds, n);
    cout << "Nhap so tiet da day muon tim:";
    int _sotietdaday;
    cin >> _sotietdaday;
    cout << "Danh sach mon hoc co so tiet da day = " << _sotietdaday << " la:" << endl;
    timkiem_np(ds, n, _sotietdaday);
}