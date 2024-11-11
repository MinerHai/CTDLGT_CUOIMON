#include <iostream>
using namespace std;
struct Date
{
    int ngay, thang, nam;
};

struct HangHoa
{
    int mhh;
    string tenhh;
    Date ngayxuat;
    float gia;
};
void Nhap_HH(HangHoa &hh)
{
    cout << "Nhap ma hang hoa:";
    cin >> hh.mhh;
    cin.ignore();
    cout << "Nhap ten hang hoa:";
    getline(cin, hh.tenhh);
    cout << "Nhap ngay-thang-nam:";
    cin >> hh.ngayxuat.ngay >> hh.ngayxuat.thang >> hh.ngayxuat.nam;
    cout << "Nhap gia:";
    cin >> hh.gia;
}
void Xuat_HH(HangHoa hh)
{
    cout << hh.mhh << ", " << hh.tenhh << ", " << hh.ngayxuat.ngay << "/" << hh.ngayxuat.thang << "/" << hh.ngayxuat.nam <<", "<< hh.gia << endl;
}
void Nhap(HangHoa ds[], int &n)
{
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_HH(ds[i]);
    }
}

void Xuat(HangHoa ds[], int n)
{
    for (int i = 0; i < n; i++)
        Xuat_HH(ds[i]);
}
void HoanDoi(HangHoa &a, HangHoa &b)
{
    HangHoa tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(HangHoa ds[] , int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (ds[j].gia < ds[j - 1].gia)
                HoanDoi(ds[j], ds[j - 1]);
}
void timkiem_np(int n, HangHoa ds[], float gia)
{
    int l = 0;
    int r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / r;
        if (ds[m].gia == gia)
        {
            founded = true;
            Xuat_HH(ds[m]);
            int left_mid = m - 1;
            while (ds[left_mid].gia == gia && left_mid >= 0)
            {
                Xuat_HH(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (ds[right_mid].gia == gia && right_mid <= r)
            {
                Xuat_HH(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].gia < gia)
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
    HangHoa ds[100];
    Nhap(ds, n);
    Xuat(ds, n);
    BubbleSort(ds, n);
    cout << "===============================" << endl;
    Xuat(ds, n);
    cout << "Nhap so tiet da day muon tim:";
    int gia;
    cin >> gia;
    cout << "Danh sach HangHoa co gia = " << gia << " la:" << endl;
    timkiem_np(n, ds, gia);
}