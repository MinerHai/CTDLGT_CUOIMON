#include <iostream>
#include <fstream>
using namespace std;
const long long INF = 1e9;
void nhapDoThi(int g[7][7], int &n, string filepath)
{
    ifstream fin(filepath);
    if (!fin)
    {
        cout << "Khong the mo file" << endl;
        return;
    }
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> g[i][j];
}

void xuatDoThi(int g[7][7], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}

void hienthiduongdi(int dgdi[], int dinh){
    if (dgdi[dinh] == -1)
    {
        cout << dinh << " ";
        return;
    }
    hienthiduongdi(dgdi, dgdi[dinh]);
    cout << dinh << " ";
}
int minDist_idx(int dist[], bool visited[], int n)
{
    int min = INF, minIdx;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}
void dijkstra(int g[7][7], int a, int b, int n)
{
    int dist[n];
    bool visited[n];
    int dgdi[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        dgdi[i] = -1;
    }
    dist[a] = 0;
    for (int i = 0; i < n; i++)
    {
        int dinh = minDist_idx(dist, visited, n);
        visited[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && g[dinh][j] && dist[dinh] != INF && dist[dinh] + g[dinh][j] < dist[j]){
                dist[j] = dist[dinh] + g[dinh][j];
                dgdi[j] = dinh;
            }
        }
    }
    cout << "Duong di ngan nhat tu " << a << " den " << b << "la: " << dist[b] << endl;
    hienthiduongdi(dgdi, b);
}
int main()
{
     int n;
    int g[7][7];
    nhapDoThi(g, n, "text/b3.txt");
    xuatDoThi(g, n);
    dijkstra(g, 0, 6, n);

}