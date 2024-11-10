#include <iostream>
#include <fstream>
using namespace std;
const long long INF = 1e9;
void nhapDoThi(int g[6][6], int &n, string filepath)
{
    ifstream fin(filepath);
    if (!fin)
    {
        cout << "Khong the mo file ";
        return;
    }
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> g[i][j];
}
void xuatDoThi(int g[6][6], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}
void hienduongdi(int dgdi[], int dinh)
{
    if (dgdi[dinh] == -1)
    {
        cout << (char)(dinh + 'A' - 1) << " ";
        return;
    }
    hienduongdi(dgdi, dgdi[dinh]);
    cout << (char)(dinh + 'A' - 1) << " ";
}
int idx_dinh_co_kc_nhonhat(int dist[], bool visited[], int n)
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
void dijkstra(int g[6][6], int a, int b, int n)
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
    for (int i = 0; i < n - 1; i++)
    {
        int dinh = idx_dinh_co_kc_nhonhat(dist, visited, n);
        visited[dinh] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && g[dinh][j] && dist[dinh] != INF && dist[dinh] + g[dinh][j] < dist[j])
            {
                dist[j] = dist[dinh] + g[dinh][j];
                dgdi[j] = dinh;
            }
        }
    }
    cout << "Khoang cach tu " << (char)(a + 'A' - 1) << " den " << (char)(b + 'A' - 1) << " la: " << dist[b] << endl;
    hienduongdi(dgdi, b);
}
using namespace std;
int main()
{
    int n;
    int g[6][6];
    nhapDoThi(g, n, "text/b1.txt");
    xuatDoThi(g, n);
    dijkstra(g, 1, 4, n);
}