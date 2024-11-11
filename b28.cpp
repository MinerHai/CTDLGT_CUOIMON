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
    cout << "Nhap so luong: ";
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
void Swap (TaiLieu a, TaiLieu b){
   TaiLieu tmp = a;
   a = b;
   b = tmp;
}
void SelectionSort(TaiLieu a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[i].giaban> a[j].giaban)
                minIdx = j;
        Swap(a[i], a[minIdx]);
    }
}
void timkiem_nhiphan(TaiLieu ds[], int n, int _giaban)
{
    int l = 0, r = n - 1;
    bool founded = false;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ds[m].giaban == _giaban)
        {
            founded = true;
            Xuat_TL(ds[m]);
            int left_mid = m - 1;
            while (left_mid >= l && ds[left_mid].giaban == _giaban)
            {
                Xuat_TL(ds[left_mid]);
                left_mid--;
            }
            int right_mid = m + 1;
            while (right_mid <= r && ds[right_mid].giaban == _giaban)
            {
                Xuat_TL(ds[right_mid]);
                right_mid++;
            }
            break;
        }
        else if (ds[m].giaban > _giaban ){
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if(!founded)
        cout << "KHONG CO PHAN TU CO giaban LA: " << _giaban << "TRONG DANH SACH!!" << endl; 
}
int main()
{
    int n;
    TaiLieu ds[50];
    Nhap(ds, n);
    Xuat(ds, n);
    cout << "====================================" << endl;
    SelectionSort(ds, n);
    Xuat(ds, n);
    cout << "Nhap giaban muon tim:";
    int _giaban;
    cin >> _giaban;
    timkiem_nhiphan(ds, n, _giaban);    
}