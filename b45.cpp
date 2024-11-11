#include <iostream>
using namespace std;
void Nhap(int &n, float a[])
{
    cout << "Nhap n:";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void Xuat(int n, float a[])
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n==============================" << endl;
}

int phanhoach(float a[], int l, int r)
{
    float pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(a[i], a[j]);
        else
            return j;
    }
}
void quicksort(float a[], int l, int r)
{
    if (l >= r)
        return;
    int m = phanhoach(a, l, r);
    quicksort(a, l, m);
    quicksort(a, m + 1, r);
}
bool kiemtrasapxep(float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
bool timkiem(float a[], int n, float num)
{
    int l = 0, r = n - 1;
    while (l <= r)
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
    int n;
    float a[100];
    Nhap(n, a);
    Xuat(n, a);
    if (!kiemtrasapxep(a, n))
        quicksort(a, 0, n - 1);
    Xuat(n, a);
    float num;
    cin >> num;
    if (timkiem(a, n, num))
        cout << "Co so" << num << "Ton tai trong mang" << endl;
    else
        cout << "Khong co so" << num << "Ton tai trong mang" << endl;
}