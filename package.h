#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class algorithm
{
public:
    string arr[300];
    virtual  string searchh()=0;
    int c;
    algorithm()
    {
        c=0;
        fstream f1;
        f1.open("file.txt",ios::in);
        if(f1==NULL)
        {
            cout<<"\nNot able to open the file";
        }
        else
        {
            string a;
            while(f1>>a)
            {
                arr[c]=a;
                c++;
            }
            //cout<<"\nThe number of words in myself file is "<<c<<endl;
            f1.close();
        }
    }
};
class soundex:public algorithm
{
public:
    string word,wordcpy;
    char match[7][11]= {{'a','u','i','o','e','h','w','y'},
        {'b','f','p','v'},{'c','g','j','k','q','s','x','z'},{'d','t'},{'l'},{'m','n'},{'r'}
    };
    int find1[10],find2[10],i=0,j=0,i1=0,nomatch=0,c3,count,num,flag,c1;
    char temp;
    friend istream & operator>>(istream & in,soundex& obj);
    soundex()
    {

    }
    string searchh()
    {
        string::iterator it=word.begin();
        ++it;
        for(; it!=word.end(); ++it)
        {
            if(*it!='a' && *it!='e'&& *it!='u' && *it!='i'&& *it!='o'&& *it!='h'&& *it!='w'&& *it!='y')
            {

                if(*it=='b' ||*it=='f' ||*it=='p' ||*it=='v')
                {
                    find1[i]=1;
                    i++;
                }
                else if(*it=='c' ||*it=='g' ||*it=='j' ||*it=='k'||*it=='q' ||*it=='s' ||*it=='x' ||*it=='z')
                {
                    find1[i]=2;
                    i++;
                }
                else if(*it=='d' ||*it=='t')
                {
                    find1[i]=3;
                    i++;
                }
                else if(*it=='l')
                {
                    find1[i]=4;
                    i++;
                }
                else if(*it=='m' ||*it=='n')
                {
                    find1[i]=5;
                    i++;
                }
                else
                {
                    find1[i]=6;
                    i++;
                }
            }
        }
        c1=0;
        for(int k=0; k<i; k++)
        {
            if(word[k]==word[k+1])
            {
                if(word[k+2]!='\0')
                {
                    word[k+1]=word[k+2];

                }
                c1++;
            }
        }
        i=i-c1;
        c1=0;
        for(int k=0; k<i; k++)
            // cout<<find1[k];
            for(j=0; j<c; j++)
            {
                i1=0;
                wordcpy=arr[j];
                string::iterator it1=wordcpy.begin();
                ++it1;
                for(; it1!=wordcpy.end(); ++it1)
                {
                    if(*it1!='a' && *it1!='e'&& *it1!='u' && *it1!='i'&& *it1!='o'&& *it1!='h'&& *it1!='w'&& *it1!='y')
                    {

                        if(*it1=='b' ||*it1=='f' ||*it1=='p' ||*it1=='v')
                        {
                            find2[i1]=1;
                            i1++;
                        }
                        else if(*it1=='c' ||*it1=='g' ||*it1=='j' ||*it1=='k'||*it1=='q' ||*it1=='s' ||*it1=='x' ||*it1=='z')
                        {
                            find2[i1]=2;
                            i1++;
                        }
                        else if(*it1=='d' ||*it1=='t')
                        {
                            find2[i1]=3;
                            i1++;
                        }
                        else if(*it1=='l')
                        {
                            find2[i1]=4;
                            i1++;
                        }
                        else if(*it1=='m' ||*it1=='n')
                        {
                            find2[i1]=5;
                            i1++;
                        }
                        else
                        {
                            find2[i1]=6;
                            i1++;
                        }
                    }
                }

                for(int k=0; k<i; k++)
                {
                    if(find2[k]==find2[k+1])
                    {
                        if(find2[k+2]!='\0')
                        {
                            find2[k+1]=find2[k+2];

                        }
                        c1++;
                    }
                }
                i1=i1-c1;
                c1=0;
                c3=0;
                count=0;
                num=9;
                flag=0;

                for(int m=0; m<7; m++)
                {
                    for(int n=0; match[m][n]!='\0'; n++)
                    {
                        if(word.at(0)==match[m][n])
                        {
                            num=m;
                            break;
                        }
                    }
                }

                for(int m=0; match[num][m]!='\0'; m++)
                {
                    if(word.at(0)==match[num][m])
                    {
                        count++;
                    }
                    if(wordcpy.at(0)==match[num][m])
                    {
                        count++;
                    }
                }

                for(int m=0,n=0; m<i && n<i1; m++,n++)
                {
                    if(find1[m]==find2[n])
                    {
                        c3++;
                    }
                }
                if((c3==i1 && c3==i && count==2)) // (a[i][0]==key[0]))
                {
                    nomatch++;
                    if(wordcpy!=word)
                    {
                        cout<<"\n Word having similar sound like user entered word is";
                        cout<<"\n-------------------------------------------------------"<<endl<<"    ";
                        cout<<wordcpy<<endl;
                    }
                }

            }
    }
    ~soundex()
    {

    }
};
istream & operator>>(istream & in,soundex & obj)
{
    cout<<"\nEnter the String  :   ";
    in>>obj.word;
    return in;
}
