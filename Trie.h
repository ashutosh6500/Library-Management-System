#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
long long int cnt=0;
class TRIE
{
public:
    unordered_map<char,TRIE *>occ;
    bool Is_end;
    long long int copies,pages,book_id;
    string auther;
    double price;
    TRIE()
    {
        Is_end=false;
        copies=0;
    }
};
TRIE* getNewTrieNode()
{
	TRIE* node = new TRIE();
	node->Is_end= false;
	node->copies=0;
	return node;
}
void insert(TRIE  *& root,string s,long long int pages,double price)
{
    if(root == nullptr)
        root=getNewTrieNode();
    TRIE * current=root;
    for(auto x:s)
    {
          if (current->occ.find(x) == current->occ.end())
			current->occ[x] = getNewTrieNode();
		current = current->occ[x];
    }
    current->Is_end=true;
    (current -> copies) ++;
    current -> price = price;
    current -> pages=pages;
    current -> book_id=cnt;
    string auther;
    cerr<<"Enter Auther name:\n";
    cin.ignore();
    getline(cin,auther);
    current -> auther=auther;
    cnt++;
}
void Search(TRIE * root,string s)
{
    if(root==nullptr)
    {
        cerr<<"No Book present inside the library\n";
        return;
    }
    TRIE * current=root;
    for(auto q:s)
    {
        if(current==nullptr)
        {
            cerr<<"The Book doesn't exists in the Library\n";
            return;
        }
        current=current -> occ[q];
    }
    if(current -> Is_end)
    {
         cerr<<"The Book exists in the Library.\n";
         cerr<<"Want to know details about the book?(type y/n)\n";
         char ch;
         cin>>ch;
         if(ch=='y')
         {
             cerr<<"Written by - "<<current -> auther<<"\nPrice - "<<current ->price<<"\nNumber of pages - "<<current ->pages<<"\nBook ID - "<<current ->book_id<<"\n";
         }
    }
    else
        cerr<<"The Book doesn't exists in the Library \n";
}
