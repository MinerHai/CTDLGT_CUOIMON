#include <iostream>
#include <fstream>
using namespace std;
const int INF = 1e9;
void Nhap(int g[6][6], int &n, string filePath)
{
    ifstream fin(filePath);
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> g[i][j];
}
void Xuat(int g[6][6], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}
int minDist_idx(int dist[], bool visited[], int n)
{
    int min = INF, minIdx;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            visited[i] = true;
            minIdx = i;
        }
    }
    return minIdx;
}
void duyetdgdi(int dgdi[], int dinh)
{
    if (dgdi[dinh] == -1)
    {
        cout << dinh << " ";
        return;
    }
    duyetdgdi(dgdi, dgdi[dinh]);
    cout << dinh << " ";
}
void dijkstra(int g[6][6], int a, int b, int n)
{
    int dist[n];
    bool visited[n];
    int luudgdi[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        luudgdi[i] = -1;
    }
    dist[a] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int dinh = minDist_idx(dist, visited, n);
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && g[dinh][j] && dist[j] > dist[dinh] + g[dinh][j])
            {
                dist[j] = dist[dinh] + g[dinh][j];
                luudgdi[j] = dinh;
            }
        }
    }
    cout << "Khoang cach tu " << a << " den " << b << "la: " << dist[b] << endl;
    duyetdgdi(luudgdi, b);
}

int main()
{
    int g[6][6];
    int n;
    Nhap(g, n, "text/b5.txt");
    Xuat(g, n);
    dijkstra(g, 0, 5, n);
}