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
void HoanDoi(VeMayBay &a, VeMayBay &b)
{
    VeMayBay tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(VeMayBay ds[] , int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (ds[j].giave < ds[j - 1].giave)
                HoanDoi(ds[j], ds[j - 1]);
}
void timkiem_np(int n, VeMayBay ds[], float giave)
{
    int l = 0;
    int r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / r;
        if (ds[m].giave == giave)
        {
            founded = true;
            Xuat_ve(ds[m]);
            int left_mid = m - 1;
            while (ds[left_mid].giave == giave && left_mid >= 0)
            {
                Xuat_ve(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (ds[right_mid].giave == giave && right_mid <= r)
            {
                Xuat_ve(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].giave < giave)
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
    VeMayBay ds[100];
    Nhap(ds, n);
    Xuat(ds, n);
    BubbleSort(ds, n);
    cout << "===============================" << endl;
    Xuat(ds, n);
    cout << "Nhap so tiet da day muon tim:";
    int giave;
    cin >> giave;
    cout << "Danh sach VeMayBay co giave = " << giave << " la:" << endl;
    timkiem_np(n, ds, giave);
}