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
    cout << "Nhap so giaban: ";
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
void HoanDoi(TaiLieu &a, TaiLieu &b)
{
    TaiLieu tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(TaiLieu ds[] , int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (ds[j].giaban < ds[j - 1].giaban)
                HoanDoi(ds[j], ds[j - 1]);
}
void timkiem_np(int n, TaiLieu ds[], float giaban)
{
    int l = 0;
    int r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / r;
        if (ds[m].giaban == giaban)
        {
            founded = true;
            Xuat_TL(ds[m]);
            int left_mid = m - 1;
            while (ds[left_mid].giaban == giaban && left_mid >= 0)
            {
                Xuat_TL(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (ds[right_mid].giaban == giaban && right_mid <= r)
            {
                Xuat_TL(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].giaban < giaban)
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
    TaiLieu ds[100];
    Nhap(ds, n);
    Xuat(ds, n);
    BubbleSort(ds, n);
    cout << "===============================" << endl;
    Xuat(ds, n);
    cout << "Nhap so tiet da day muon tim:";
    int giaban;
    cin >> giaban;
    cout << "Danh sach TaiLieu co giaban = " << giaban << " la:" << endl;
    timkiem_np(n, ds, giaban);
}