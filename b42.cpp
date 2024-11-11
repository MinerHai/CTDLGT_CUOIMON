#include <iostream>
using namespace std;
struct KhachHang
{
    int mkh;
    string tenkh;
    string sdt;
    float tongtien;
};
void Nhap_KH(KhachHang &hh)
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
struct node
{
    KhachHang data;
    node *left;
    node *right;
};
void khoitao(node *&root)
{
    root = NULL;
}
node *makeNode(KhachHang mh)
{
    node *newNode = new node;
    newNode->data = mh;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

node *Add(node *root, KhachHang mh)
{
    if (root == NULL)
        return makeNode(mh);
    if (root->data.mkh > mh.mkh)
    {
        root->left = Add(root->left, mh);
    }
    else if (root->data.mkh < mh.mkh)
    {
        root->right = Add(root->right, mh);
    }
    return root;
}
node *timkiem(node *root, int mkh)
{
    if (root == NULL || root->data.mkh == mkh)
        return root;
    if (root->data.mkh > mkh)
        return timkiem(root->left, mkh);
    return timkiem(root->right, mkh);
}
void DuyetCay(node *root)
{
    if (root != NULL)
    {
        DuyetCay(root->left);
        Xuat_HH(root->data);
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
        KhachHang tmp;
        Nhap_KH(tmp);
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
        Xuat_HH(timkiem(root, mmh)->data);
    }
}