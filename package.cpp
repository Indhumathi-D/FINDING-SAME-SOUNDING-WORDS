#include"package.h"
int main()
{
    int option,t1;
    do
    {
        soundex e;
        cin>>e;
        e.searchh();
        try
        {
            if(e.nomatch<=1)
                throw "Entered word is not found in file";
        }
        catch (const char* x)
        {
            cerr<<"\n"<<x<<endl;
        }
        cout<<"\n Want to continue(1-yes)";
        cin>>option;
    }
    while(option==1);
}
