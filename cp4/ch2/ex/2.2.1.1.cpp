/*
Sort the following array of N elements. Use built-in library if possible.
1. N tuples (integer age (ASCENDING), string last name # (descending order), string first name (ASCENDING)).
2*. N fractions ( numerator denominator ) in " (ascending order).
*/

#include <bits/stdc++.h>
using namespace std;

const int ch_MAX = 26;
string RandomString(int ch)
{
    char alpha[ch_MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z'};
    string result = "";
    for (int i = 0; i < ch; i++)
        result = result + alpha[rand() % ch_MAX];

    return result;
}

bool compare(const tuple<int, string, string> &t1, const tuple<int, string, string> &t2)
{
    if (get<0>(t1) != get<0>(t2))
        return get<0>(t1) < get<0>(t2);
    if (get<1>(t1) != get<1>(t2))
        return get<1>(t1) > get<1>(t2);
    return get<2>(t1) < get<2>(t2);
}

bool compareFractions(const float &f1, const float &f2){
    return f1 < f2;
}

void sortTuples(vector<tuple<int, string, string>> &v)
{
    int x;
    string s1, s2;

    cout << "Before Sorting:" << endl;
    for (const auto &i : v)
    {
        tie(x, s1, s2) = i;
        cout << x << " " << s1 << " " << s2 << endl;
    }
    cout << endl;

    sort(v.begin(), v.end(), compare);

    cout << "After Sorting:" << endl;
    for (const auto &i : v)
    {
        tie(x, s1, s2) = i;
        cout << x << " " << s1 << " " << s2 << endl;
    }
}

void sortFractions(vector<float> v){
    cout << "Before Sorting:" << endl;
    for (auto &i : v)
    {
        cout << i << endl;
    }
    cout << endl;

    sort(v.begin(), v.end(), compareFractions);

    cout << "After Sorting:" << endl;
    for (auto &i : v)
    {
        cout << i << endl;
    }
}

int main(){
    vector<tuple<int, string, string>> v;

    for (int i = 0; i < 5; i++){
        tuple<int, string, string> geek;
        geek = make_tuple(rand(), RandomString(15), RandomString(15));
        v.push_back(geek);
    }

    // sortTuples(v);

    vector<float> v1({1.234, 0.234, 1.666});
    sortFractions(v1);
    return 0;
}