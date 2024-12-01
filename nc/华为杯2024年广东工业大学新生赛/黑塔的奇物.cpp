#include <bits/stdc++.h>
using namespace std;

int xorSum(const vector<int>& nums) 
{
    int result = 0;
    for (int num : nums) 
    {
        result ^= num;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 1; i <= n; ++i) 
    {
        nums[i-1] = i;
    }

    int result = xorSum(nums);
    cout << result << endl;
/*
1 2 3
2 2 3
2 3 3
2 3 1
*/
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cout<<nums[j];
            if(j!=n-1)cout<<" ";
        }
        int temp = nums[0];
        for(int j = 0;j < n-1;j++)
        {
            nums[j]=nums[j+1];
        }
        nums[n-1]=temp;
        cout<<endl;
    }
    return 0;
}