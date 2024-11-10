#include <iostream>
using namespace std;
struct MonHoc
{
    int mhh;
    string tenmh;
    int sotc;
    int sotiet;
};
void Nhap_MH(MonHoc &mh)
{
    cout << "Nhap ma mon hoc:";
    cin >> mh.mhh;
    cout << "Nhap ten mon hoc:";
    cin.ignore();
    getline(cin, mh.tenmh);
    cout << "Nhap so tin chi:";
    cin >> mh.sotc;
    cout << "Nhap so tiet";
    cin >> mh.sotiet;
}

void Xuat_Mh(MonHoc mh)
{
    cout << mh.mhh << ", " << mh.tenmh << ", " << mh.sotc << ", " << mh.sotc << endl;
}
struct node
{
    MonHoc data;
    node *left;
    node *right;
}; void khoitao(node *&root)
{
    root = NULL;
}
node *makeNode(MonHoc mh)
{
    node *newNode = new node;
    newNode->data = mh;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

node *Add(node *root, MonHoc mh)
{
    if (root == NULL)
        return makeNode(mh);
    if (root->data.mhh > mh.mhh)
    {
        root->left = Add(root->left, mh);
    }
    else if (root->data.mhh < mh.mhh)
    {
        root->right = Add(root->right, mh);
    }
    return root;
}
node *timkiem(node *root, int mhh)
{
    if (root == NULL || root->data.mhh == mhh)
        return root;
    if (root->data.mhh > mhh)
        return timkiem(root->left, mhh);
    return timkiem(root->right, mhh);
}
void DuyetCay(node *root)
{
    if (root != NULL)
    {
        DuyetCay(root->left);
        Xuat_Mh(root->data);
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
        MonHoc tmp;
        Nhap_MH(tmp);
        root = Add(root,tmp);
    }
    DuyetCay(root);
    cout << "Nhap ma mon hoc can tim:";
    int mmh;
    cin >> mmh;
    if (timkiem(root, mmh) == NULL)
    {
        cout << "Khong co trong tree";
    }
    else{
        Xuat_Mh(timkiem(root,mmh)->data);
    }
}