#include <iostream>
#include <vector>
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
void Nhap(vector<HangHoa> &ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        HangHoa tmp;
        Nhap_HH(tmp);
        ds.push_back(tmp);
    }
}
void Xuat(vector<HangHoa> ds)
{
    for (int i = 0; i < ds.size(); i++)
        Xuat_HH(ds[i]);
    
}
void Swap(HangHoa &a, HangHoa &b)
{
    HangHoa tmp = a;
    a = b;
    b = tmp;
}
void SelectionSort(vector<HangHoa> &ds)
{
    int n = ds.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ds[minIdx].gia > ds[j].gia)
                minIdx = j;
        }
        Swap(ds[i], ds[minIdx]);
    }
}
int main()
{
    int n;
    cout << "Nhap so luong phan tu:";
    cin >> n;
    vector<HangHoa> ds;
    Nhap(ds, n);
    Xuat(ds);
    SelectionSort(ds);
    cout << "-------------------------------------" << endl;
    Xuat(ds);
}