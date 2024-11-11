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
    cout << "Nhap so sotietdaday: ";
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
void HoanDoi(MonHoc &a, MonHoc &b)
{
    MonHoc tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(MonHoc ds[] , int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (ds[j].sotietdaday < ds[j - 1].sotietdaday)
                HoanDoi(ds[j], ds[j - 1]);
}
void timkiem_np(int n, MonHoc ds[], float sotietdaday)
{
    int l = 0;
    int r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / r;
        if (ds[m].sotietdaday == sotietdaday)
        {
            founded = true;
            Xuat_MH(ds[m]);
            int left_mid = m - 1;
            while (ds[left_mid].sotietdaday == sotietdaday && left_mid >= 0)
            {
                Xuat_MH(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (ds[right_mid].sotietdaday == sotietdaday && right_mid <= r)
            {
                Xuat_MH(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].sotietdaday < sotietdaday)
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
    MonHoc ds[100];
    Nhap(ds, n);
    Xuat(ds, n);
    BubbleSort(ds, n);
    cout << "===============================" << endl;
    Xuat(ds, n);
    cout << "Nhap so tiet da day muon tim:";
    int sotietdaday;
    cin >> sotietdaday;
    cout << "Danh sach MonHoc co sotietdaday = " << sotietdaday << " la:" << endl;
    timkiem_np(n, ds, sotietdaday);
}