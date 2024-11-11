#include <iostream>
using namespace std;
struct date
{
    int ngay, thang, nam;
};

struct NhanVien
{
    int manv;
    string hoten;
    date ngaysinh;
    float luong;
};

void NV_Nhap(NhanVien &nv)
{
    cout << "Nhap ma nhan vien:";
    cin >> nv.manv;
    cout << "Nhap ho ten:";
    cin.ignore();
    getline(cin, nv.hoten);
    cout << "Nhap ngay-thang-nam:";
    cin >> nv.ngaysinh.ngay >> nv.ngaysinh.thang >> nv.ngaysinh.nam;
    cout << "Nhap luong:";
    cin >> nv.luong;
}

void NV_Xuat(NhanVien nv)
{
    cout << nv.manv << ", " << nv.hoten << ", " << nv.ngaysinh.ngay << "/" << nv.ngaysinh.thang << "/" << nv.ngaysinh.nam << ", " << nv.luong << endl;
}
struct node
{
    NhanVien data;
    node *left;
    node *right;
};
void khoitao(node *&root)
{
    root = NULL;
}
node *makeNode(NhanVien mh)
{
    node *newNode = new node;
    newNode->data = mh;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

node *Add(node *root, NhanVien mh)
{
    if (root == NULL)
        return makeNode(mh);
    if (root->data.manv > mh.manv)
    {
        root->left = Add(root->left, mh);
    }
    else if (root->data.manv < mh.manv)
    {
        root->right = Add(root->right, mh);
    }
    return root;
}
node *timkiem(node *root, int mkh)
{
    if (root == NULL || root->data.manv == mkh)
        return root;
    if (root->data.manv > mkh)
        return timkiem(root->left, mkh);
    return timkiem(root->right, mkh);
}
void DuyetCay(node *root)
{
    if (root != NULL)
    {
        DuyetCay(root->left);
        NV_Xuat(root->data);
        DuyetCay(root->right);
    }
}
int main()
{
    node *root;
    khoitao(root);
    int n;
    cout << "Nhap so luong:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        NhanVien tmp;
        NV_Nhap(tmp);
        root = Add(root, tmp);
    }
    DuyetCay(root);
    cout << "Nhap ma mon hoc can tim:";
    int mmh;
    cin >> mmh;
    if (timkiem(root, mmh) == NULL)
    {
        cout << "Khong co trong tree";
    }
    else
    {
        NV_Xuat(timkiem(root, mmh)->data);
    }
}