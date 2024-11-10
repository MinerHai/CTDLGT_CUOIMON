#include <iostream>
using namespace std;
struct VDV
{
    int mdv;
    string tendv;
    int tuoi;
    float luong;
};
void Nhap_VDV(VDV &v)
{
    cout << "Nhap ma van dong vien:";
    cin >> v.mdv;
    cout << "Nhap ten van dong vien:";
    cin.ignore();
    getline(cin, v.tendv);
    cout << "Nhap tuoi:";
    cin >> v.tuoi;
    cout << "Nhap luong:";
    cin >> v.luong;
}
void Xuat_VDV(VDV v)
{
    cout << v.mdv << ", " << v.tendv << ", " << v.tuoi << ", " << v.luong << endl;
}

struct node
{
    VDV data;
    node *left;
    node *right;
};
void khoitao(node *&root)
{
    root = nullptr;
}
node *makeNode(VDV v)
{
    node *newNode = new node;
    newNode->data = v;
    newNode->right = nullptr;
    newNode->left = nullptr;
    return newNode;
}
node *Add(node *root, VDV v)
{
    if (root == nullptr)
        return makeNode(v);
    if (root->data.mdv > v.mdv)
        root->left = Add(root->left, v);
    else if (root->data.mdv < v.mdv)
        root->right = Add(root->right, v);
    return root;
}
void Duyet(node *root)
{
    if (root != nullptr)
    {
        Duyet(root->left);
        Xuat_VDV(root->data);
        Duyet(root->right);
    }
}
node *TimKiem(node *root, int mvd)
{
    if (root == nullptr || root->data.mdv == mvd)
        return root;
    if (root->data.mdv > mvd)
        return TimKiem(root->left, mvd);
    return TimKiem(root->right, mvd);
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
        VDV tmp;
        Nhap_VDV(tmp);
        root = Add(root, tmp);
    }
    Duyet(root);
    cout << "Nhap ma can tim:";
    int mvdv;
    cin >> mvdv;
    if (TimKiem(root, mvdv) == nullptr)
        cout << "Khong ton tai trong cay" << endl;
    else
        Xuat_VDV(TimKiem(root, mvdv)->data);
}