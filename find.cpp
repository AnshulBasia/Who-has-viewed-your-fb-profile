#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int to_find;
void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}
 
//check whether target string contains pattern 
bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];     
    preKMP(pattern, f);     
    int i = 0;
    int k = 0;        
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m){
            	to_find = i-k;
                return 1;
            }
        }
        else
            k = f[k];
    }
    return 0;
}

int main(){
	ifstream file("rishi.html");
	string text;
	cout<<"Enter the number of friends you want to see the name of"<<endl;
	int n;
	cin>>n;
	string s = "InitialChatFriendsList";
	int t;
	string id;
	vector<string> v;
	while(getline(file,text,'\n')){
		
		if(KMP(s,text)){
			t = to_find + 45;
			while(v.size()<n){
				id = "";
				while(text[t]!='-'){
					id = id + text[t];
					t++;
				}
				cout<<id<<endl;
				if(find(v.begin(),v.end(),id)==v.end()){
					v.push_back(id);
				}
				t = t+ 5;
			}
			break;
		}
	}

	for(int j=0;j<v.size();j++){
		cout<<v[j]<<endl;
		s = "firefox -new-tab http://www.facebook.com/"+v[j];
		system(s.c_str());
	}
}