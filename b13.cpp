#include <iostream>
#include <vector>
using namespace std;
struct SinhVien
{
    int msv;
    string tensv, lopsv;
    float gpa;
};
void InsertionSort(vector<SinhVien> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        SinhVien tmp = a[i];
        int pos = i - 1;
        while (pos >= 0 && tmp.gpa < a[pos].gpa)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = tmp;
    }
}
void Nhap(SinhVien &sv)
{
    cout << "Nhap ma sinh vien:";
    cin >> sv.msv;
    cout << "Nhap ten sinh vien:";
    cin.ignore();
    getline(cin, sv.tensv);
    cout << "Nhap lop:";
    getline(cin, sv.lopsv);
    cout << "Nhap gpa:";
    cin >> sv.gpa;
}
void Xuat(SinhVien sv)
{
    cout << sv.msv << ", " << sv.tensv << ", " << sv.lopsv << ", " << sv.gpa << endl;
}

void Nhap_SV(vector<SinhVien> &ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        SinhVien tmp;
        Nhap(tmp);
        ds.push_back(tmp);
    }
}
void Xuat_SV(vector<SinhVien> ds)
{
    for (int i = 0; i < ds.size(); i++)
        Xuat(ds[i]);
}
int main()
{
    int n;
    cout << "Nhap so luong sinh vien:";
    cin >> n;
    vector<SinhVien> a;
    Nhap_SV(a, n);
    Xuat_SV(a);
    InsertionSort(a);
    cout << "------------------------------------" << endl;
    Xuat_SV(a);
}