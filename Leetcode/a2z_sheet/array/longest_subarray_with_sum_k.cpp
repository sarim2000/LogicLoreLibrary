#include <bits/stdc++.h>
using namespace std;

/*
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]

Output: 3

Explanation: Subarrays whose sum = ‘3’ are:

[1, 2], [3], [1, 1, 1] and [1, 1, 1]
*/

// brute force approach

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int sum = 0, ans = 0;

    for (int i = 0; i < a.size(); i++){
        sum = a[i];
        for (int j = i + 1; j < a.size(); j++){
            sum += a[j];
            if (sum == k){
                ans = max(ans,j - i);
                break;
            }
        }
    }
}

/*
Time Complexity --> O(n^2)
*/

// better approach
/*
    Store the prefix sum in a hashmap and check if u find a element whose (targetsum - sum) till now exists in the hashmap
*/

int longestSubarrayWithSumK(vector<int> a, long long k){
    map<int,int> mp;
    long long sum = 0;
    int ans = 0;
    for (int i = 0; i < a.size(); i++){
        sum += a[i];
        if (sum == k){
            ans = max(ans, i + 1);
        }
        long long rem = k - sum;

        if (mp.find(rem) != mp.end()){
            int len = i - mp[rem];
            ans = max(ans, i + 1);
        }

        if (mp.find(sum) == mp.end()){
            mp[sum] = i;
        }

    }
    return ans;
}

/*
Time Complexity --> O(nlogn) or O(n) (depends on data structure)
Space Complexity --> O(n)
*/

//optimal approach for positive number only

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int n = a.size(); 

    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    while (right < n)
    {
        
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
            sum += a[right];
    }

    return maxLen;
}