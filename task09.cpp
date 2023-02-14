#include <iostream>
using namespace std;

main()
{
    string moves[] = {"shimmy", "shake", "pirouette", "slide", "boxstep", "headspin", "dosado", "pop", "lock", "arabeque"};
    string num;
    cout << "enter number: ";
    cin >> num;
    int n=0;


    
    
      bool check=false;
    for( int i=0; i<4;i++)
    {
        if((num[i]=='0')||(num[i]=='1')||(num[i]=='2')||(num[i]=='3')||(num[i]=='4')||(num[i]=='5')||(num[i]=='6')||(num[i]=='7')||(num[i]=='8')||(num[i]=='9'))
        {
            check=true;
        }
        else
        {
            check=false;
            break;
        }
    }

    if(check==0)
    {
        cout << "this is invalid";
    }

    
    else if(check==1)
    {
        for(int j=0;j<4;j++)
        { 
            
        
           n=j+num[j];
        //    cout << n<<endl;
           
           
           if((n>10)||(n==10))
           {
            n=n%10;
            cout<<moves[n]<<" ";
           } 
           else
           {
            cout<<moves[n]<<"  ";
           }
            
            
        }
    }
    


        

    
}



