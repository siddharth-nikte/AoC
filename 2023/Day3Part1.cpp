                        //day3
                        //part 1 = 540212
#include <bits/stdc++.h>

using namespace std; 

bool isNumber(char x){return (x >= '0' && x <= '9');}

bool isValid(vector<string> s, int row, int col)
{
    int numRows = s.size();
    int numCols = s[0].size();
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {return false;}
    return (!isNumber(s[row][col]) && s[row][col] != '.');
}

bool num(vector<string> s, int row, int col)
{
    for (int i = row - 1; i <= row + 1; i++) 
    {
        for (int j = col - 1; j <= col + 1; j++) 
        {
            if (i == row && j == col){continue;}
            if (isValid(s, i, j)){return true;}
        }
    }
    return false;
}

int main()
{
    int count = 0;
    string str;
    vector<string> s;
    set<tuple<string, int, int>> numbers;
    while(getline(cin, str)){s.push_back(str);}
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < s[i].size(); j++)
        {
            if(num(s,i,j) && isNumber(s[i][j]))
            {
                int c1 = j, c2 = j;
                string t;
                while(isNumber(s[i][c1]) && c1 > -1){c1--;}
                while(isNumber(s[i][c2]) && c2 < s[j].size()){c2++;}
                for(int k = ++c1; k < c2; k++){t += s[i][k];}
                numbers.insert({t, i, c1});        
            }
        }
    }
    for (auto& num : numbers) {count += stoi(get<0>(num));}
    cout << count;
}