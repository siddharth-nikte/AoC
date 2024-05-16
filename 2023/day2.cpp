                        //day2
                        //part 1 = 2377
                        //part 2 = 71220
#include <bits/stdc++.h>

using namespace std; 

int main()
{
    string s;
    int count = 0, power = 0;
    while(getline(cin, s))
    {
        int i = 5;
        string gno;
        while(int(s[i]) >= 48 && int(s[i]) <= 57)
        {
            gno.push_back(s[i]);
            i++;
        }
        i = 0;
        vector<int> b, g, r;
        while(i < s.length())
        {
            if(int(s[i]) >= 48 && int(s[i]) <= 57)
            {
                string t;
                t.push_back(s[i]);
                while(int(s[i+1]) >= 48 && int(s[i+1]) <= 57) 
                {
                    t.push_back(s[i+1]);
                    i++;
                }
                if(t.length() > 1)
                {
                    if(s[i+2] == 'b') {b.push_back(stoi(t));}
                    else if(s[i+2] == 'g') {g.push_back(stoi(t));}
                    else if(s[i+2] == 'r') {r.push_back(stoi(t));}
                }
                else
                {
                    if(s[i+2] == 'b') {b.push_back(s[i] - '0');}
                    else if(s[i+2] == 'g') {g.push_back(s[i] - '0');}
                    else if(s[i+2] == 'r') {r.push_back(s[i] - '0');}
                }
            }
            i++;
        }
        sort(b.begin(), b.end());
        sort(g.begin(), g.end());
        sort(r.begin(), r.end());
        if(b[b.size()-1] <= 14 && g[g.size()-1] <= 13 && r[r.size()-1] <= 12)
        {count += stoi(gno);}
        power += b[b.size()-1]*g[g.size()-1]*r[r.size()-1];
    }
    cout << count << power;
}