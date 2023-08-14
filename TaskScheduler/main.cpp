//
//  main.cpp
//  TaskScheduler
//
//  Created by Sart Way on 18/5/23.
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
void mergeSort(vector<int*>& setter, int begin, int end);
void merger(vector<int*>& setter, int begin, int mid, int end);
void taskScheduler(set<int>setter);
int BiTree[100001];
int arr[100001];
vector<int>deadline_time[100000];


void taskScheduler(set<int>setter)
{
    
}

void mergeSort(vector<int*>& setter, int begin, int end)
{
    if(begin>=end)
    {
        return;
    }
    int mid = begin + (end-begin)/2;
    mergeSort(setter,begin,mid);
    mergeSort(setter,mid+1,end);
    merger(setter,begin,mid,end);
}

void merger(vector<int*>& setter, int begin, int mid, int end)
{
    vector<int*> leftarr_copy((mid-begin)+1);
    vector<int*> rightarr_copy(end-mid);
    int right = 0;
    int left = 0;
    
    for(int x=begin;x<=mid;++x)
        leftarr_copy[left++]=setter[x];
    
    for(int x=mid+1;x<=end;++x)
        rightarr_copy[right++]=setter[x];
    
    int right_ptr = 0;
    int left_ptr = 0;
    int x = begin;
    
    while(right_ptr<right && left_ptr<left)
    {
        if(rightarr_copy[right_ptr][0] < leftarr_copy[left_ptr][0])
        {
            setter[x++] = rightarr_copy[right_ptr++];
        } else {
            setter[x++] = leftarr_copy[left_ptr++];
        }
    }
    
    if(left_ptr==left)
    {
        while(right_ptr<right)
        {
            setter[x++]=rightarr_copy[right_ptr++];
        }
    } else {
        while(left_ptr<left)
        {
            setter[x++]=leftarr_copy[left_ptr++];
        }
    }
    
    return;
    
}


int main(int argc, const char * argv[]) {
    fstream input("file.txt", ios::in | ios::out);
    string q_temp;
    if(input.is_open())
    {
        cout << "File is open" << endl;
    }
    getline(input, q_temp);
    
    //cout << q_temp << endl;
    int t = stoi(ltrim(rtrim(q_temp)));
    cout << t << endl;
    set<int, greater<int>>setter;
    
    for(int t_itr = 0; t_itr < t; t_itr++)
    {
        string first_multiple_input;
        getline(input, first_multiple_input);
        vector<string> firster = split(rtrim(first_multiple_input));
        setter.insert(stoi(firster[0]));
        deadline_time[stoi(firster[0])].push_back(stoi(firster[1]));
        //mergeSort(setter, 0, setter.size()-1);
    }
    //mergeSort(setter, 0, setter.size()-1);
    cout << setter.size() << endl;
    for(auto i : setter)
    {
        cout << i << " ";
    }
    cout << endl;
//    for(auto x=setter.begin();x!=setter.end();++x)
//    {
//        cout << (*x)[0] << " ";
//    }
//    cout << endl;
    
    
    return 0;
}


string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
