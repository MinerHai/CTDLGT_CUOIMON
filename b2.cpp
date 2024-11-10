#include <iostream>
#include <fstream>
using namespace std;
const long long INF = 1e9;
void inDuongDi(int parent[], int j)
{
    if (parent[j] == -1)
    {
        cout << j << " ";
        return;
    }
    inDuongDi(parent, parent[j]);
    cout << j << " ";
}
void nhapDoThi(int &n, int g[6][6], string filename)
{
    ifstream fin(filename);
    if (!fin)
    {
        cerr << "Không thể mở file" << endl;
        return;
    }
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> g[i][j];
    fin.close();
}
void xuatDoThi(int n, int g[6][6])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}

int kcDinhNhoNhat(int dist[], bool visited[], int n)
{
    int min = INF, min_idx;
    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_idx = v;
        }
    }
    return min_idx;
}
void dijkstra(int g[6][6], int a, int b, int n)
{
    int dist[n];
    bool visited[n];
    int luuduongdi[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        luuduongdi[i] = -1;
    }
    dist[a] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int dinh = kcDinhNhoNhat(dist, visited, n);
        visited[dinh] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && g[dinh][j] && dist[dinh] != INF && dist[dinh] + g[dinh][j] < dist[j])
            {
                dist[j] = dist[dinh] + g[dinh][j];
                luuduongdi[j] = dinh;
            }
        }
    }
    cout << "Khoagn cach ngan nhat tu " << a << " den " << b << ": " << dist[b] << endl;
    inDuongDi(luuduongdi, b);
}
int main()
{
    int n;
    int g[6][6];
    nhapDoThi(n, g, "text/b2.txt");
    xuatDoThi(n, g);
    dijkstra(g, 0, 5, n);
}