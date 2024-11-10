#include <iostream>
#include <vector>
using namespace std;
class SinhVien
{
private:
    int msv;
    string tensv;
    string lop;
    float gpa;

public:
    SinhVien();
    float getGpa()
    {
        return gpa;
    }
    void Nhap();
    void Xuat();
};
SinhVien::SinhVien(){
    msv = 0;
    tensv = "";
    lop = "";
    gpa = -1.0f;
}
void SinhVien::Nhap()
{
    cout << "Nhap ma sinh vien:";
    cin >> msv;
    cout << "Nhap ten sinh vien:";
    cin.ignore();
    getline(cin, tensv);
    cout << "Nhap lop:";
    getline(cin, lop);
    cout << "Nhap gpa:";
    cin >> gpa;
}

void SinhVien::Xuat()
{
    cout << msv << ", " << tensv << ", " << lop << ", " << gpa << endl;
}
void Swap(SinhVien &a, SinhVien &b)
{
    SinhVien tmp = a;
    a = b;
    b = tmp;
}
void SelectionSort(SinhVien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[i].getGpa() > a[j].getGpa())
                minIdx = j;
        Swap(a[i], a[minIdx]);
    }
}

SinhVien TimKiem(SinhVien a[], int n, float gpa)
{
    int l = 0, r = n - 1;
    while (r >= l)
    {
        int m = (l + r) / 2;
        if (a[m].getGpa() == gpa)
            return a[m];
        else if (a[m].getGpa() < gpa)
        {
            l = m + 1;
        }
        else
            r = m - 1;
    }
    SinhVien tmp;
    return tmp;
}
void Nhap_ds(SinhVien ds[], int n)
{

    for (int i = 0; i < n; i++)
    {
        ds[i].Nhap();
    }
}
void Xuat_ds(SinhVien ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ds[i].Xuat();
    }
}
int main()
{
    int n;
    cout << "Nhap so luong sinh vien:";
    cin >> n;
    SinhVien ds[n];
    Nhap_ds(ds, n);
    cout << "------------------------------------" << endl;
    Xuat_ds(ds, n);
    cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    cout << "------------------------------------" << endl;
    SelectionSort(ds, n);
    Xuat_ds(ds, n);
    cout << "------------------------------------" << endl;
    float gpa;
    cout << "Nhap gpa cua sinh vien can tim: " << endl;
    cin >> gpa;
    SinhVien tmp;
    tmp = TimKiem(ds, n, gpa);
    cout << "Sinh vien can tim la: ";
    if (tmp.getGpa() > 0.0f)
        tmp.Xuat();
}