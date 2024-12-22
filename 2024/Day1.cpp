// Day1
// Part1: 2769675
// Part2: 24643097
#include <bits/stdc++.h>

using namespace std;

int partOne(vector<int> l1, vector<int> l2)
{
    long long res = 0;
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    for(int i = 0; i < l1.size(); i++)
    {
        res += abs(l1[i]-l2[i]);
    }
    return res;
}

int partTwo(vector<int> l1, vector<int> l2)
{
    long long res = 0;
    for(int i = 0; i < l1.size(); i++)
    {
        res += l1[i]*count(l2.begin(), l2.end(), l1[i]);
    }
    return res;
}

int main()
{
    string str;
    int num = 0;
    vector<int> l1, l2;
    while(cin >> str)
    {
        int t = stoi(str);
        if(num == 0)
        {
            l1.push_back(t);
            num++;
        }
        else
        {
            l2.push_back(t);
            num--;
        }
    }
    cout << "Part One:" << partOne(l1, l2) << endl;
    cout << "Part Two:" << partTwo(l1, l2) << endl;
}
