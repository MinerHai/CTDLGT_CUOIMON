#include <iostream>
using namespace std;

struct KhachHang
{
    int mkh;
    string tenkh;
    string sdt;
    float tongtien;
};
void Nhap_HH(KhachHang &hh)
{
    cout << "Nhap ma khach hang:";
    cin >> hh.mkh;
    cin.ignore();
    cout << "Nhap ten khach hang:";
    getline(cin, hh.tenkh);
    cout << "Nhap so dien thoai:";
    getline(cin, hh.sdt);
    cout << "Nhap tongtien:";
    cin >> hh.tongtien;
}
void Xuat_HH(KhachHang hh)
{
    cout << hh.mkh << ", " << hh.tenkh << ", " << hh.sdt <<", "<< hh.tongtien << endl;
}
void Nhap(KhachHang ds[], int &n)
{
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Nhap_HH(ds[i]);
    }
}

void Xuat(KhachHang ds[], int n)
{
    for (int i = 0; i < n; i++)
        Xuat_HH(ds[i]);
}
void Swap (KhachHang a, KhachHang b){
   KhachHang tmp = a;
   a = b;
   b = tmp;
}
void SelectionSort(KhachHang a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[i].tongtien> a[j].tongtien)
                minIdx = j;
        Swap(a[i], a[minIdx]);
    }
}
void timkiem_nhiphan(KhachHang ds[], int n, int _tongtien)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].tongtien == _tongtien)
        {
            founded = true;
            Xuat_HH(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].tongtien == _tongtien)
            {
                Xuat_HH(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].tongtien == _tongtien)
            {
                Xuat_HH(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].tongtien > _tongtien ){
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if(!founded)
        cout << "KHONG CO PHAN TU CO tongtien LA: " << _tongtien << "TRONG DANH SACH!!" << endl; 
}
int main()
{
    int n;
    KhachHang ds[50];
    Nhap(ds, n);
    Xuat(ds, n);
    cout << "====================================" << endl;
    SelectionSort(ds, n);
    Xuat(ds, n);
    cout << "Nhap tongtien muon tim:";
    int _tongtien;
    cin >> _tongtien;
    timkiem_nhiphan(ds, n, _tongtien);    
}