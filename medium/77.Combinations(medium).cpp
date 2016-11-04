#include <iostream>
#include <vector>

using namespace std;

void DFS(vector< vector<int> > &ret, vector<int> &cur, int n, int k, int level)
{
	if (cur.size() == k)
	{
		ret.push_back(cur);
		return;
	}

	if (cur.size() > k)
		return;

	for (int i = level;i<=n;++i)
	{
		cur.push_back(i);
		DFS(ret, cur, n, k, i+1);
		cur.pop_back();
	}
	
}

// select k from n
vector< vector<int> > combine(int n, int k) 
{
	vector< vector<int> > ret;
	if (n <= 0)
		return ret;
	vector<int> cur;
	DFS(ret, cur, n, k, 1);
	return ret;
}

int main()
{
	vector< vector<int> > v = combine(10,2);
	for (int i = 0;i<v.size();++i)
	{
		vector<int> in = v[i];
		for (int j = 0;j<in.size();++j)
			cout << in[j] << " ";
		cout << endl;
	}
	return 0;
}