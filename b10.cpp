#include<iostream>
#include<fstream>
using namespace std;
const long long INF = 1e9;
void Nhap(int g[6][6], int &n, string path)
{
	ifstream fin(path);
	if (!fin)
		cout << "KHONG THE MO FILE!!" << endl;
	else{
		fin >> n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				fin >> g[i][j];
		}
	}
}
void Xuat(int g[6][6], int n){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << g[i][j] << " ";
		cout << endl;		
	}	
}
void HienThiDgDi(int dgdi[], int dinh){
	if (dgdi[dinh] == -1)
		cout << dinh << " ";
	else{
		HienThiDgDi(dgdi, dgdi[dinh]);
		cout << dinh << " ";
	}
}
int min_dist(int dist[], bool visited[], int n){
	int min = INF, minIdx;
	for (int i = 0; i < n; i++)
	{	
		if (min > dist[i] && !visited[i])
		{
			min = dist[i];
			minIdx = i;
		}
	}
	return minIdx;
}
void Dijkstra(int g[6][6], int n, int a, int b){
	int dist[n], dgdi[n];
	bool visited[n];
	for (int i = 0; i < n; i++){
		dist[i] = INF;
		visited[i] = false;
		dgdi[i] = -1;
	}
	dist[a] = 0;
	for (int i = 0; i < n; i++){
		int dinh = min_dist(dist, visited, n);
		visited[dinh] = true;
		for (int j = 0; j < n; j++){
			if (!visited[j] && g[dinh][j] && dist[dinh] != INF && dist[j] > dist[dinh] + g[dinh][j])
			{
				dist[j] = dist[dinh] + g[dinh][j];
				dgdi[j] = dinh;
			}  
		}
	}
	cout << "Khoang cach nho nhat tu dinh " << a <<" den dinh " << b << " la: " << dist[b] << endl; 
	HienThiDgDi(dgdi, b);
}
int main(){
	int g[6][6], n;
	Nhap(g, n, "text/b10.txt");
	Xuat(g, n);
	Dijkstra(g, n, 0, 5);
	
}
