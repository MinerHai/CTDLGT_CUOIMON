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
struct node
{
    HangHoa data;
    node *left;
    node *right;
}; void khoitao(node *&root)
{
    root = NULL;
}
node *makeNode(HangHoa mh)
{
    node *newNode = new node;
    newNode->data = mh;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

node *Add(node *root, HangHoa mh)
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
        HangHoa tmp;
        Nhap_HH(tmp);
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
        Xuat_HH(timkiem(root,mmh)->data);
    }
}