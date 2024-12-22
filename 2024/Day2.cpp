// Day2
// Part1: 326
// Part2: 381
#include <bits/stdc++.h>

using namespace std;

bool partOne(vector<int> v)
{
    bool increasing = v[0] < v[1];
    for(int i = 0; i < v.size()-1; i++)
    {
        int diff = abs(v[i] - v[i + 1]);
        if(increasing)
        {
            if(v[i] >= v[i+1] || diff > 3 || diff < 1) {return false;}
        }
        else
        {
            if(v[i] <= v[i+1] || diff > 3 || diff < 1) {return false;}
        }
    }
    return true;
}

bool partTwo(vector<int> v)
{
    if (partOne(v)) {return true;}
    else
    {
        for (int i = 0; i < v.size(); ++i)
        {
            vector<int> newV = v;
            newV.erase(newV.begin() + i);
            if (partOne(newV)) {return true;}
        }
    }
    return false;
}

int main()
{
    string str;
    long long res1 = 0, res2 = 0;
    while(getline(cin,str))
    {
        vector<int> v;
        istringstream iss(str);
        int temp;
        while (iss >> temp) {v.push_back(temp);}
        if(partOne(v)) {res1++;}
        if(partTwo(v)) {res2++;}
    }
    cout << "PartOne: " << res1 << endl;
    cout << "PartTwo: " << res2 << endl;
}