#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<char> &arr, int n, int k)
{
    //make a window of 2 as two characters are there and check if anyone has frequency greater then k if yes return false 
    int window[2] = {0,0}; 
    for(int i=0; i<mid; i++) window[arr[i]-'a']++;
    if(k>=min(window[0],window[1])) return true;
    //now start contract and shrink window
    for(int i=0; i+mid<n; i++)
    {
        window[arr[i]-'a']--;
        window[arr[i+mid]-'a']++;
        if(k>=min(window[0],window[1])) return true;
    }
    return false;
}

void solve(vector<char> &arr, int n, int k)
{
    int s = 0, e = n;
    int ans = INT_MIN;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        if(check(mid,arr,n,k))
        {
            ans = max(ans,mid);
            s = mid+1;
        }
        else e = mid-1;
    }
    cout << ans << endl;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<char> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    solve(arr,n,k);
    return 0;
}
