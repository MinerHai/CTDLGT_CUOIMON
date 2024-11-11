#include <iostream>
using namespace std;
int n;
int a[100];
void Nhap(int a[], int &n)
{
    cout << "Nhap n";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void Xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n-----------------------------" << endl;
}
bool kiemtrasapxep(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
int ChiaMang(int a[], int l, int r)
{
    int p = a[l];
    int i = l - 1, j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < p);
        do
        {
            j--;
        } while (a[j] > p);
        if (i < j)
            swap(a[i], a[j]);
        else
            return j;
    }
}
void quicksort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = ChiaMang(a, l, r);
    quicksort(a, l, p);
    quicksort(a, p + 1, r);
}

bool timkiem(int a[], int l, int r, int num)
{
    while (l <=   r)
    {
        int m = (l + r) / 2;
        if (a[m] == num)
            return true;
        if (a[m] < num)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}
int main()
{
    Nhap(a, n);
    Xuat(a, n);
    if (!kiemtrasapxep(a, n))
        quicksort(a, 0, n - 1);
    Xuat(a, n);
    int num;
    cout << "Nhap so can tim:";
    cin >> num;
    if (timkiem(a, 0, n - 1, num))
        cout << "CO TRONG MANG" << endl;
    else 
        cout << "Khong co trong mang";
}