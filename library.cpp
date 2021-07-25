#include "Trie.h"
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
#include <stdio.h>
#include <conio.h>
#include <iterator>
using namespace std;
long long int cnt1=0;
class Student
{
public:
    string name;
    long long int student_id;
    int books_issued;
    Student()
    {
        books_issued=0;
        student_id=cnt1;
        cnt1++;
    }
    void setdata()
    {
        cerr<<"Enter your name\n";
        getline(cin,name);
    }
};
unordered_map<long long int,Student>catlogue;

class Library : public Student
{
private:
    void Change_Password();
    void Add_Books();
    void Show_Admin_Options();
    void Show_Student_Options();
    void Issue_Book(){}
    void Return_Book(){}
    void Search_Book();
    string To_Lower(string s);
    string password;
    TRIE * root;
public:
    long long int total_books;
    Library();
    void start();
};
Library:: Library()
{
    total_books=0;
    password="a";
    root=nullptr;
}
void Library:: start()
{
    while(1)
    {
             cerr<<"SELECT SECTION\n";
             cerr<<"1 - ADMIN\n2 - STUDENT\n3 - EXIT\n";
             char opt=getch();
             if(opt=='3')
                break;
             if(opt<'1' || opt >'2')
             {
                 cerr<<"invalid choice of option\n";
                    continue;
             }
             switch(opt)
             {
             case 49:
                Show_Admin_Options();break;
             case 50:
                Show_Student_Options();break;
             }
    }
}
void Library:: Show_Admin_Options()
{
    cerr<<"Enter password:\n";
    string s;
    cin>>s;
    if(s==password)
    {
        while(1)
        {
            cerr<<"Select one choice\n";
            cerr<<" 1 - Change the password\n 2 - Add books to Library\n 3 - Go back to main menu\n";
           char opt=getch();
             if(opt=='3')
                break;
             if(opt<'1' || opt >'2')
             {
                 cerr<<"invalid choice of option\n";
                    continue;
             }
            switch(opt)
            {
            case 49:
                Change_Password();break;
            case 50:
                Add_Books();break;
            }
        }
    }
    else
    {
        cerr<<"Wrong password!\n";
        return;
    }
}
void Library:: Show_Student_Options()
{
    while(1)
        {
            cerr<<"Select one choice\n";
            cerr<<" 1 - Issue Book\n 2 - Return Book\n 3 - Search in Library\n 4 - Go back to main menu\n";
            char opt=getch();
             if(opt=='4')
                break;
             if(opt<'1' || opt >'3')
             {
                 cerr<<"invalid choice of option\n";
                    continue;
             }
            switch(opt)
            {
            case 49:
                Issue_Book();break;
            case 50:
                Return_Book();break;
            case 51:
                Search_Book();break;
            }
        }
}
string Library :: To_Lower(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
            s[i]='_';
        else if(s[i] >= 'A' && s[i] <='Z')
            s[i]=(char(int(s[i]) + 32)); //converting to lowercase
    }
        return s;
}
void Library :: Change_Password()
{
    cerr<<"Enter your current password\n";
    string str;
    cin>>str;
    if(str==password)
    {
        cerr<<"Enter new password\n";
        cin>>password;
    }
    else
    {
        cerr<<"Wrong password!\n";
        return;
    }
}
void Library :: Search_Book()
{
    cerr<<"Enter the name of Book you want to search\n";
    string name;
    cin.ignore();
    getline(cin,name);
    name=To_Lower(name);
    Search(root,name);
}
void Library :: Add_Books()
{
    cerr<<"Enter number of books you want to add:\n";
    int no;
    cin>>no;
    if(no<0)
        cerr<<"Invalid number\n";
    else
    {
        total_books+=no;
        for(int i=0;i<no;i++)
        {
            cerr<<"Enter Book name:\n";
            string st;
            cin.ignore();
            getline(cin,st);
            cerr<<"Enter Book price:\n";
            double p;
            cin>>p;
            cerr<<"Enter Pages in book:\n";
            long long int pages;
            cin>>pages;
            st=To_Lower(st);
            insert(root,st,pages,p);
        }
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cerr.tie(NULL);
    cerr<<"\t\t\t--------------------LIBRARY MANAGEMENT SYSTEM---------------------\n\n\n";
    Library l;
    l.start();
    return 0;
}
