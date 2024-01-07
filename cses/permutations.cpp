#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1, j = n;

    if (n < 4)
        cout << "NO SOLUTION";
    else
    {
        vector<int> v;

        while (i < j)
        {
            v.push_back(i);
            v.push_back(j);
            i += 1;
            j -= 1;
        }
        if (i == j)
            v.push_back(i);
        swap(v[0],v[n - 1]);

        for (auto i : v)    cout << i << " ";
    }
    
}