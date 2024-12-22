// Day3
// Part1: 175700056
// Part2: 71668682
#include <bits/stdc++.h>

using namespace std;

int partOne(const std::string &str)
{
    long long r = 0;
    regex pattern(R"(mul\([\d]{1,3},[\d]{1,3}\))");
    smatch matches;

    // search for mul(x,y)
    auto searchStart = str.cbegin();
    while (regex_search(searchStart, str.cend(), matches, pattern))
    {
        regex num(R"(\b\d{1,3}\b)");
        smatch numMatch;
        vector<int> numbers;
        string m = matches[0].str();

        // search for numbers in mul(x,y)
        auto search = m.cbegin();
        while (regex_search(search, m.cend(), numMatch, num))
        {
            numbers.push_back(stoi(numMatch.str()));
            search = numMatch[0].second;
        }
        r += numbers[0] * numbers[1];

        searchStart = matches[0].second;
    }
    return r;
}

bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

int partTwo(const std::string &str)
{
    long long sum = 0;
    std::vector<std::pair<int, int>> v = {{0, 1}};

    auto pos = str.find("don\'t()", 0);
    while (pos != std::string::npos)
    {
        v.push_back({pos, 0});
        pos = str.find("don\'t()", pos + 1);
    }

    pos = str.find("do()", 0);
    while (pos != std::string::npos)
    {
        v.push_back({pos, 1});
        pos = str.find("do()", pos + 1);
    }

    std::sort(v.begin(), v.end(), comp);

    if (v.back().second == 1)
        v.push_back({str.length(), 0});

    std::vector<std::pair<int, int>> vf = {v[0]};
    for (size_t i = 1; i < v.size(); ++i)
    {
        auto prev = v[i - 1];
        auto curr = v[i];

        if (prev.second != curr.second)
            vf.push_back(curr);
    }

    for (size_t i = 0; i < vf.size() - 1; i += 2)
    {
        size_t start = vf[i].first, end = vf[i + 1].first - start;
        sum += partOne(str.substr(start, end));
    }

    return sum;
}

int main()
{
    string str, s;
    long long res = 0;
    while (getline(cin, s))
    {
        str += s;
    }
    cout << partOne(str) << endl;
    cout << partTwo(str) << endl;
}