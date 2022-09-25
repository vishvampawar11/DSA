// Finds connected components in graph

#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5+7;
 
int parent[N];
int sizes[N];
 
void make(int v) {
  parent[v] = v;
  sizes[v] = 1;
}
 
int findParent(int v) {
  if(parent[v] == v)
    return v;
  return parent[v] = findParent(parent[v]);
}
 
void unionParents(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if(a != b) {
    if(sizes[a] < sizes[b])
      swap(a, b);
    parent[b] = a;
    sizes[a] += sizes[b];
  }
}
 
 
int main() {
	int n, k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		make(i);
	for(int i=0;i<k;i++) {
		int a, b;
		cin>>a>>b;
		unionParents(a, b);
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(findParent(i) == i)
			ans++;
	}
	cout<<ans<<"\n";
}
