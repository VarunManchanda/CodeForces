#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
bool canVisitLast(int mid, int last, string s) //O(n)
{
	int vis[last];
	memset(vis,0,sizeof(vis));
	vis[0] = 1;
	int step = mid;
	while(step<last)
	{
		if(vis[step]==1) return false;
		if(s[step]=='R')
		{
			vis[step] = 1;
			step += mid;
			if(step>=last) return true;
		}
		else if(s[step]=='L')
		{
			vis[step] = 1;
			step -= 1;
			if(vis[step]) return false;
		}
		
	}
	return true;
}
 
int solve(string ss) //O(logN)
{
	bool flag = 0;
	for(int i=0; i<ss.length(); i++)
	{
		if(ss[i]!='R')
		{
			flag = 1;
			break;
		}
	}
	if(!flag) return 1;
	int n = ss.length();
	string news = "";
	news += 'x';
	for(auto i : ss) news += i;
	news += 'z';
	int s = 0, e = n+1;
	int ans = 0;
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(canVisitLast(mid,n+1,news))
		{
			ans = mid;
			e = mid-1;
		}
		else
		{
			s = mid+1;
		}
	}
	return ans;
 
}
 
 //Time Complexity:- O(nlogn)
 
int main()
{
	_fast_;
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}
