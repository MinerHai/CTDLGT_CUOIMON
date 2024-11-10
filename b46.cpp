#include <iostream>
using namespace std;
struct DuAn
{
    int maduAn;
    string tenduAn;
    float tongkinhphi;
};
void Nhap_DuAn(DuAn &da)
{
    cout << "Nhap ma du an:";
    cin >> da.maduAn;
    cout << "Nhap ten du an:";
    cin.ignore();
    getline(cin, da.tenduAn);
    cout << "Nhap tong kinh phi:";
    cin >> da.tongkinhphi;
}
void Xuat_DuAn(DuAn da)
{
    cout << da.maduAn << ", " << da.tenduAn << ", " << da.tongkinhphi << endl;
}
struct node
{
    DuAn data;
    node *left;
    node *right;
};
void khoitao(node *&root)
{
    root = NULL;
}
node *makeNode(DuAn data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->right = nullptr;
    newNode->left = nullptr;
    return newNode;
}

node *Insert(node *root, DuAn data)
{
    if (root == nullptr)
        return makeNode(data);
    if (root->data.maduAn > data.maduAn)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

void DuyetCay(node *root)
{
    if (root == nullptr)
        return;
    DuyetCay(root->left);
    Xuat_DuAn(root->data);
    DuyetCay(root->right);
}

node *timkiem(node *root, int _mda)
{
    if (root == nullptr)
        return root;
    if (root->data.maduAn == _mda)
        return root;
    if (root->data.maduAn > _mda)
        return timkiem(root->left, _mda);
    return timkiem(root->right, _mda);
}
int main()
{
    int n;
    cout << "Nhap so luong:";
    cin >> n;
    node *root;
    khoitao(root);
    for (int i = 0; i < n; i++)
    {
        DuAn data;
        Nhap_DuAn(data);
        root = Insert(root, data);
    }
    DuyetCay(root);
    cout << "========================================" << endl;
    cout << "Nhap ma du an can tim: ";
    int _mda;
    cin >> _mda;
    node *found = timkiem(root, _mda);
    if (found == nullptr)
        cout << "Khong ton tai ma du an trong cay!!" << endl;
    else
        Xuat_DuAn(found->data);
}