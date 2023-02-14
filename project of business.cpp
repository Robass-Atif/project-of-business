#include<iostream>
#include <conio.h>

using namespace std;

// prototypes of function
void hms();
void header();
void adminheader();
void doctorheader();
void patientheader();
void clearscreen();
int mainmenu();
int adminlogin();

main()
{   system("cls");
    int menuoption=0;
    while(menuoption!=4)
    {   hms();
        header();
        menuoption=mainmenu();
        if(menuoption==1)
        {
            hms();
            header();
            if(menuoption==1)
            {
                system("cls");
                // string name;
                // string password;
                int loginoption=adminlogin();
            }

            
        }
    }




}



void hms()
{
cout << "         ###        ###     ###                   ###     ##################       " <<endl ;
cout << "         ###        ###     ##  ##             ##  ##     ##                       " <<endl ;
cout << "         ###        ###     ##     ##      ##      ##       ##                     " <<endl ;
cout << "         ###        ###     ##         ##          ##         ##                   " <<endl ;
cout << "         ###        ###     ##                     ##           ##                 " <<endl ;
cout << "         ##############     ##                     ##             ##               " <<endl ;
cout << "         ###        ###     ##                     ##               ##             " <<endl ;
cout << "         ###        ###     ##                     ##                 ##           " <<endl ;
cout << "         ###        ###     ##                     ##                   ##         " <<endl ;
cout << "         ###        ###     ##                     ##                     ##       " <<endl ;
cout << "         ###        ###     ##                     ##      ##################      " <<endl ;
}



void  header()
{
cout << "*************************************************************"<<endl;
cout << "****************|Hospital management System|*****************"<<endl;
cout << "*************************************************************"<<endl;
}

void  adminheader()
{
    cout << "              ************                "<<endl;
    cout << "              |Admin menu|                "<<endl;
    cout << "              ************                "<<endl;
}

void doctorheader()
{
    cout << "              *************                "<<endl;
    cout << "              |Doctor menu|                "<<endl;
    cout << "              *************                "<<endl;
    
}

void patientheader()
{
    cout << "              *************                 "<<endl;
    cout << "              |patient menu|                "<<endl;
    cout << "              *************                 "<<endl;  
}

void clearscreen()
{
    cout << "Press any key to contonue!"<<endl;
    getch();
    system("cls");
}

int mainmenu()
{
    int option;
    cout << "Select one of the following option: "<<endl;
    cout<< endl<< endl;
    cout << "1.Admin"<<endl;
    cout << "2.Doctor"<<endl;
    cout << "3.Patient"<<endl;
    cout <<endl;
    cout <<endl;
    cout << "Option: ";
    cin >> option;
    return option;
}

int adminlogin()
{   int option;
    cout << "Login menu!"<<endl;
    cout << endl<<endl;

    cout << "1.signin"<<endl;
    cout << "2.signup"<<endl;
    cout << "3.exit"<<endl;
    cout << endl;
    cout << "option: ";
    cin >> option;
    return option;

}
