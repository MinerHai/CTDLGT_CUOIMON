#include <fstream>
#include <iostream>
using namespace std;
long long INF = 1e9;
void Nhap(int g[6][6], int &n, string filePath)
{
    ifstream fin(filePath);
    if (!fin)
        cout << "NOPE LIEN KET DUOC" << endl;
    else
    {
        fin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                fin >> g[i][j];
    }
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
void HienDgdi(int dgdi[], int dinh)
{
    if (dgdi[dinh] == -1)
    {
        cout << dinh + 1 << " ";
        return;
    }
    HienDgdi(dgdi, dgdi[dinh]);
    cout << dinh + 1 << " ";
}
int min_Distance(int dist[], bool visited[], int n)
{
    int minIdx, min = INF;
    for (int i = 0; i < n; i++)
        if (!visited[i] && min > dist[i])
        {
            min = dist[i];
            minIdx = i;
        }
    return minIdx;
}
void Dijkstra(int g[6][6], int n, int a, int b)
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
        int dinh = min_Distance(dist, visited, n);
        visited[dinh] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && g[dinh][j] && g[dinh][j] && dist[j] > g[dinh][j] + dist[dinh])
            {
                dist[j] = dist[dinh] + g[dinh][j];
                dgdi[j] = dinh;
            }
        }
    }
    cout << "Khoang cach tu dinh " << a + 1 << " den dinh " << b + 1 << " la: " << dist[b] << endl;
    HienDgdi(dgdi, b);
}
int main()
{
    int n;
    int g[6][6];
    Nhap(g, n, "text/b8.txt");
    Xuat(g, n);
    Dijkstra(g, n, 0, 4);
}