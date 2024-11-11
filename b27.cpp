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
void Swap (HangHoa a, HangHoa b){
   HangHoa tmp = a;
   a = b;
   b = tmp;
}
void SelectionSort(HangHoa a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[i].gia> a[j].gia)
                minIdx = j;
        Swap(a[i], a[minIdx]);
    }
}
void timkiem_nhiphan(HangHoa ds[], int n, int _gia)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].gia == _gia)
        {
            founded = true;
            Xuat_HH(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].gia == _gia)
            {
                Xuat_HH(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].gia == _gia)
            {
                Xuat_HH(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].gia > _gia ){
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
    HangHoa ds[50];
    Nhap(ds, n);
    Xuat(ds, n);
    cout << "====================================" << endl;
    SelectionSort(ds, n);
    Xuat(ds, n);
    cout << "Nhap gia muon tim:";
    int _gia;
    cin >> _gia;
    timkiem_nhiphan(ds, n, _gia);    
}