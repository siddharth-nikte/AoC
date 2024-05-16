                            //day 1
                        //day1(1) = 54951
                        //day1(2) = 55218
#include <bits/stdc++.h>

using namespace std;

map<string, string> m = {
    {"one", "1"},
    {"two", "2"},
    {"three", "3"},
    {"four", "4"},
    {"five", "5"},
    {"six", "6"},
    {"seven", "7"},
    {"eight", "8"},
    {"nine", "9"}
};

int main()
{
    int num = 0;
    string s;
    while(cin >> s)
    {
        int min = s.length();
        string c1, c2, s1;
        map<string, string>::iterator it;
        for (it = m.begin(); it != m.end(); it++) //part 2
        {
            size_t f = s.find(it->first); //find letter digits
            if(f < min) //check for first
            {
                min = f;
                c1 = it->second;
            }
        }
        for (it = m.begin(); it != m.end(); it++) 
        {
            size_t f = s.find(it->second); //find digits
            if(f < min) //check for first
            {
                min = f;
                c1 = it->second;
            }
        }
        reverse(s.begin(), s.end()); 
        min = s.length();
        for (it = m.begin(); it != m.end(); it++) //part 2
        {
            string temp = it->first;
            reverse(temp.begin(), temp.end());
            size_t f = s.find(temp); //find letter digits
            if(f < min) //check for last
            {
                min = f;
                c2 = it->second;
            }
        }
        for (it = m.begin(); it != m.end(); it++) 
        {       
            size_t f = s.find(it->second); //find digits
            if(f < min) //check for last
            {
                min = f;
                c2 = it->second;
            }
        }
        s1 += c1;
        s1 += c2;
        num += stoi(s1);
    }
    cout << num;
}
