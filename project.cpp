#include <iostream>
#include <conio.h>

using namespace std;
// Global variables and array
// string functions
const int userarrsize = 50;
string users[userarrsize];
string passwords[userarrsize];
string doctor[userarrsize];
string doctorpasswords[userarrsize];
string doctorsalary[userarrsize];
string doctorfee[userarrsize];
string patient[userarrsize];
string patientpasswords[userarrsize];
string patientage[userarrsize];
string patientdisease[userarrsize];
string patientcontact[userarrsize];
string patientmedicine[userarrsize];
string patienttest[userarrsize];
string patienttestresult[userarrsize];
string reviews[userarrsize];
string appointmentday[userarrsize];
string appointmenttime[userarrsize];
string patientprescription[userarrsize];
int billpayment[userarrsize];




// int functions
int usercount = 0;
int doctorusercount = 0;
int patientusercount = 0;
int reviewcount = 0;




// prototypes of function
void hms();
void header();
void adminheader();
void doctorheader();
void patientheader();
void clearscreen();
int mainmenu();
int adminlogin();
bool signup(string, string);
bool signin(string, string);
int adminmenu();
int doctormenu();
int patientmenu();
void admininterface();
void doctorinterface();
void patientinterface(int);
bool logindoctor(string, string);
bool doctoradd(string, string,string,string);
bool loginpatient(string, string,string,string,string,string);
int patientcheck(string,string);
bool reviewsaved(string);
bool addfee(string,string);
bool salarycheck(string,string,string);
bool doctordelete(string,string);
bool patientappointment(string,string,string);
bool patientdeleteappointment(string);
bool patientdelete(string,string);
bool addprescription(string,string);
int checkprescription(string);
int feechecker(string);
int addition(int,int);
void testchecker(string,string);







main()
{
    system("cls");
    int menuoption = 0;
    while (menuoption != 4)
    {
        hms();
        header();
        menuoption = mainmenu();
        if (menuoption == 1)
        {

            system("cls");
            hms();
            int loginoption = adminlogin();
            if (loginoption == 2)
            {
                system("cls");
                bool satisfy;

                hms();
                header();
                adminheader();
                string name;
                string password;
                cout << "enter id name: ";
                cin >> name;
                cout << "enter password: ";
                cin >> password;
                satisfy = signup(name, password);
                if (satisfy == true)
                {
                    cout << "sucessfully signup" << endl;
                }
                else
                {
                    cout << "Users in the System have exceeded the Capacity";
                }
            }

            else if (loginoption == 1)
            {
                system("cls");
                hms();
                header();
                adminheader();
                string name;
                string password;
                cout << "enter id : ";
                cin >> name;
                cout << "enter password: ";
                cin >> password;
                bool option = signin(name, password);
                if (option == true)
                {
                    clearscreen();
                    admininterface();
                }
                else if (option == false)
                {
                    cout << "you enter wrong credential." << endl;
                }
            }
        }

        if (menuoption == 2)
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name;
            string password;
            cout << "enter name: ";
            cin >> name;
            cout << "enter password: ";
            cin >> password;
            bool check = logindoctor(name, password);
            if (check == true)
            {
                clearscreen();
                doctorinterface();
            }
            else
            {
                cout << "your credential is not correct" << endl;
            }
        }

        if (menuoption == 3)
        {
            system("cls");
            hms();
            header();
            patientheader();
            string name;
            string password;
            cout << "enter patient name: ";
            cin >> name;
            cout << "enter password:";
            cin >> password;
            int check = patientcheck(name,password);
            if (check != (-1))
            {
                clearscreen();
                patientinterface(check);
            }
            else
            {
                cout << "you enter wrong credential" << endl;
            }
        }
        clearscreen();
    }
}



// function starts from here
bool loginpatient(string name, string password,string age,string disease,string medicine, string contact )
{
    if (patientusercount < userarrsize)
    {
        patient[patientusercount] = name;
        patientpasswords[patientusercount] = password;
        patientage[patientusercount]=age;
        patientdisease[patientusercount]=disease;
        patientmedicine[patientusercount]=medicine;
        patientcontact[patientusercount]=contact;
        patientusercount++;
        return true;
    }
    return false;
}

bool reviewsaved(string review)
{
    if (reviewcount < userarrsize)
    {
        reviews[reviewcount] = review;
        reviewcount++;
        return true;
    }
    return false;
}
bool salarycheck(string name,string password,string salary)
{
    for(int index=0;index<doctorusercount;index++)
    {
        if((doctor[index]==name)&& (doctorpasswords[index]==password))
        {
            doctorsalary[index]=salary;
            return true;
        }
    }
    return false;
}

void doctorinterface()
{
    int doctoroption = 0;

    while (doctoroption != 10)
    {
        hms();
        header();
        doctorheader();

        doctoroption = doctormenu();
        if (doctoroption == 1)
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name,age,disease,medicine,contact;
            string password;
            cout << "enter patient  name: ";
            cin >> name;
            cout << "enter password: ";
            cin >> password;
            cout<< "enter patient age:";
            cin>>age;
            cout<< "enter disease: ";
            cin >>disease;
            cout<< "enter medicine: ";
            cin >>medicine;
            cout<< "enter contact (without spaces): ";
            cin.ignore();
            getline(cin,contact);
            
            
            bool check = loginpatient(name, password,age,disease,medicine,contact);
            if (check == true)
            {
                cout << "sucessfully login!" << endl;
            }
            else
            {
                cout << "you enter wrong credential" << endl;
            }
            clearscreen();
        }

        if(doctoroption==5)
        {   system("cls");
            hms();
            header();
            doctorheader();
            string name,day,time;
            cout<<"enter name of patient: ";
            cin>>name;
            cout<< "enter day of appoitment: ";
            cin >> day;
            cout<<"time:";
            cin>>time;
            bool check=patientappointment(name,day,time);
            if(check==true)
            {
                cout<< "appointment added"<<endl;
            }
            else
            {
                cout << "you enter wrong credential"<<endl;
            }
            clearscreen();            
        }
        if(doctoroption==6)
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name,prescription;
            cout<< "enter name: ";
            cin>> name;
            cout<<"enter prescription: ";
            cin.ignore();
            getline(cin,prescription);
            bool check =addprescription(name,prescription);
            if(check==true)
            {
                cout<< "added prescription!"<<endl;
            }
            else
            {
                cout<< "you enter wrong credential"<<endl;
            }
            clearscreen();
        }


        if(doctoroption==4)
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name;
            cout<< "enter patient name: ";
            cin >> name;
            // bool check=true;
            bool check2=patientdeleteappointment(name);
            if(check2==true)
            {
                cout << "appointment cancel sucessfully!"<<endl;
            }
            else
            {
                cout<< "you enter wrong credential!"<<endl;
            }
            clearscreen();
        }
        if( doctoroption==2)
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name,password;
            cout << "enter discharge patient name: ";
            cin>>name;
            cout<<"enter password: ";
            cin>>password;
            bool check=patientdelete(name,password);
            if(check==true)
            {
                cout<<"patient discharge!"<<endl;
            }
            else
            {
                cout<<"you enter wrong credential"<<endl;
            }
            clearscreen();
        }

        if(doctoroption==3)
        {   system("cls");
            hms();
            header();
            doctorheader();
            cout<< "patient"<<"\t"<<"appointmentday"<<"\t\t"<<"appointmenttime"<<endl;
            for(int index=0;index<patientusercount;index++)
            {
                cout<<patient[index]<<"\t"<<appointmentday[index]<<"\t\t"<<appointmenttime[index]<<endl;
            }
            clearscreen();
        }

        if(doctoroption==9)
        {
            system("cls");
            hms();
            header();
            doctorheader();
            cout<<"patients"<<"\t"<<"passwords"<<"\t"<<"age"<<"\t"<<"diseases"<<"\t"<<"medicine"<<"\t"<<"contacts"<<endl;
            for(int index=0;index<patientusercount;index++)
            {
               cout<< patient[index]<<"\t\t"<<patientpasswords[index]<<"\t\t"<<patientage[index]<<"\t"<<patientdisease[index]<<"\t\t"<<patientmedicine[index]<<"\t"<<patientcontact[index]<<endl;
            }
            clearscreen();
        }
        if(doctoroption==8)
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name,test;
            cout<< "enter patient name: ";
            cin >> name;
            cout<< "enter test name: ";
            cin >>test;
            testchecker(name,test);
            
            clearscreen();
        }
        
    }
}

void testchecker(string name,string test)
{   
    int j=0;
    bool recordnew=false;
    for(int index=0;index<patientusercount;index++)
    {
        if(patient[index]==name)
        {
            patienttest[index]=test;
            recordnew=true;
            j=index;
            break;
            
        }
    }
    cout<< endl;
    if( recordnew==true)
    {
        string result;
        cout<<"enter result of test: ";
        cin >> patienttestresult[j];
    cout<< endl;
    }
    else
    {
        cout<<"you enter wrong credential!"<<endl;

    }
    
}

bool addprescription(string name,string prescription)
{
    for(int index=0;index<patientusercount;index++)
    {
        if(patient[index]==name)
        {
            patientprescription[index]=prescription;
            return true;
        }
    }
    return false;
}

bool patientdelete(string name,string password)
{
    bool recordnew=false;
    int j;
    for(int index=0;index<patientusercount;index++)
    {
        if((patient[index]==name)&&(patientpasswords[index]==password))
        {
            j=index;
            recordnew=true;
            break;
        }
    }

    if(recordnew==true)
    {
        for(int i=j;i<patientusercount;i++)
        {
            patient[i]=patient[i+1];
            patientpasswords[i]=patientpasswords[i+1];
            patientage[i]=patientage[i+1];
            appointmentday[i]=appointmentday[i+1];
            appointmenttime[i]=appointmenttime[i+1];
            patientcontact[i]=patientcontact[i+1];
        }
        patientusercount--;
    }
    return recordnew;
}
bool patientdeleteappointment(string name)
{
    bool recordnew=false;
    int j=0;
    for(int index=0;index<patientusercount;index++)
    {
        if(patient[index]==name)
        {
            j=index;
            recordnew=true;
            break;
        }
    }

    if(recordnew==true)
    {
        for(int i=j;i<patientusercount;i++)
        {
            appointmentday[i]=appointmentday[i+1];
            appointmenttime[i]=appointmenttime[i+1];

        }

    }
return recordnew;
}
bool patientappointment(string name,string day,string time)
{
    for(int index=0;index<patientusercount;index++)
    {
        if (name==patient[index])
        {
            appointmentday[index]=day;
            appointmenttime[index]=time;
            return true;
        }

    }
        return false;
}
bool  doctordelete( string name,string password)
{
  bool recordnew=false;
  int j=0;
  for( int index=0;index<doctorusercount;index++)
  {
    if((doctor[index]==name)&&(doctorpasswords[index]==password))
    {
        j=index;
        recordnew=true;
        break;

    }
  }

  if(recordnew==true)
  {
    for(int i=j;i<doctorusercount;i++)
        {
            doctor[i]=doctor[i+1];
            doctorpasswords[i]=doctorpasswords[i+1];
            doctorsalary[i]=doctorsalary[i+1];
            doctorfee[i]=doctorfee[i+1];
        }
        doctorusercount--;
  }  

return recordnew;
}

int patientcheck(string name,string password)
{int count=-1;
    for(int index=0;index<patientusercount;index++)
    {
        if((patient[index]==name)&&(patientpasswords[index]==password))
        {
            count=index;
            
        }
    }
    return count;
}

void patientinterface(int check)
{   int count=check;
    int patientoption = 0;
    while (patientoption != 7)
    {   system ("cls");
        hms();
        header();
        patientheader();
        patientoption = patientmenu();
        if (patientoption == 5)
        {
            system("cls");
            hms();
            header();
            patientheader();
            string review;
            cout << "enter your review: ";
            cin.ignore();
            getline(cin,review);
            bool check = reviewsaved(review);
            if (check == true)
            {
                cout << "your review saved sucessfully." << endl;
            }
            else
            {
                cout << "sorry!your review does not saved in record" << endl;
            }
            clearscreen();
        }
        if(patientoption==1)
        {
            system("cls");
            hms();
            header();
            patientheader();
            cout<< "your prescription: "<<endl;
            cout<< patientprescription[count]<<endl;
        
            clearscreen();
        }
        if(patientoption==2)
        {
            system("cls");
            hms();
            header();
            patientheader();
            int fee,test;
            cout<< "enter doctor fee: ";
            cin >>fee;
            cout<< "enter test fee: ";
            cin >>test;
            
            int total=addition(fee,test);
            
                
            cout<< "total bill you paid: "<<total<<endl;
            billpayment[count]=total;
            
            clearscreen();
        }
        if(patientoption==3)
        {
            system("cls");
            hms();
            header();
            patientheader();
            string name;
            cout<<"your doctor name: ";
            cin>>name;
            int check=feechecker(name);
            if(check!=(-1))
            {
                cout<< "your doctor fee: "<<endl;
                cout<< doctorfee[check]<<endl;
            }
            else
            {
                cout<< "you enter wrong credential"<<endl;
            }
            clearscreen();
        }

        if(patientoption==4)
        {
            system("cls");
            hms();
            header();
            patientheader();
            cout<< "your appointment:"<<endl;
            cout << appointmentday[count]<<endl;
            cout<< appointmenttime[count]<<endl;
            clearscreen();
        }

        if(patientoption==6)
        {
            system("cls");
            hms();
            header();
            patientheader();
            cout<< "your test name: ";
            cout <<patienttest[count]<<endl;
            cout<< "your test result :";
            cout<<patienttestresult[count]<<endl;
            clearscreen();
        }
        
    }
}


 int addition(int fee, int test)
 {
    int total=fee+test;
    return total;
 }
int feechecker(string name)
{
    int count=-1;
    for(int index=0;index<doctorusercount;index++)
    {
        if(doctor[index]==name)
        {
            count=index;
            break;
        }
    }
    return count;
}
bool logindoctor(string name, string password)
{
    for (int index = 0; index < doctorusercount; index++)
    {
        if ((doctor[index] == name) && (doctorpasswords[index] == password))
        {
            return true;
        }
    }
    return false;
}
bool doctoradd(string name, string password,string salary,string fee)
{

    if (doctorusercount < userarrsize)
    {
        doctor[doctorusercount] = name;
        doctorpasswords[doctorusercount] = password;
        doctorsalary[doctorusercount]=salary;
        doctorfee[doctorusercount]=fee;
        doctorusercount++;
        return true;
    }
    else
    {
        return false;
    }
}

bool signup(string name, string password)
{

    if (usercount < userarrsize)
    {
        users[usercount] = name;
        passwords[usercount] = password;
        usercount++;
        return true;
    }
    else
    {
        return false;
    }
}

bool signin(string name, string password)
{
    for (int index = 0; index < usercount; index++)
    {
        if ((users[index] == name) && (passwords[index] == password))
        {
            return true;
        }
    }
    return false;
}

bool addfee(string name,string fee)
{
    for( int index=0; index<doctorusercount;index++)
    {
        if(doctor[index]==name)
        {
            doctorfee[index]=fee;
            return true;
        }
    }
    return false;
}
void admininterface()
{
    int adminoption = 0;
    while (adminoption != 10)
    {
        hms();
        header();
        adminheader();
        adminoption = adminmenu();
        if (adminoption == 3)
        {
            system("cls");
            hms();
            header();
            adminheader();
            string name;
            string password;
            string salary;
            string fee;
            
            cout << "enter doctor id:";
            cin >> name;
            cout << "enter password: ";
            cin >> password;
            cout << "enter salary: ";
            cin >> salary;
            cout<< "enter fee: ";
            cin >>fee;
            
            bool option = doctoradd(name, password,salary,fee);
            if (option == true)
            {
                cout << "sucessfully added" << endl;
            }
            else
            {
                cout << "you exceed the limit! So try again" << endl;
            }

            clearscreen();
        }
        if( adminoption==5)
        {   system("cls");
            hms();
            header();
            adminheader();
            for(int index=0;index<reviewcount;index++)
            {
                cout<<index+1<<"."<< reviews[index]<<endl;
            }
            clearscreen();
        }

        if( adminoption==1)
        {   system("cls");
             hms();
            header();
            adminheader();
                cout<<  "\t"<<"doctors"<<"\t\t"<<"passwords"<<"\t"<<"salary"<<"\t"<<"fee"<<endl;
            for( int index=0;index<doctorusercount;index++)
            {
                cout<<index+1<<"."<<"\t"<<doctor[index]<<"\t"<<"\t"<<doctorpasswords[index]<<"\t\t"<<doctorsalary[index]<<"\t"<<doctorfee[index]<<endl;
            }
            cout<<endl<<endl;
            clearscreen();
        }

        if( adminoption==2)
        {system("cls");
            hms();
            header();
            adminheader();
            string name,fee;
            cout <<"enter doctor name: ";
            cin >>name;
            cout<< "enter fee: ";
            cin>> fee;
            bool check=addfee(name,fee);
            if(check==true)
            {
                cout<< "Doctor  fee update sucessfully"<<endl;
            } 
            else
            {
                cout<< "you enter wrong credential"<<endl;
            }
            clearscreen();

        }
        
        if(adminoption==9)
        {
            system("cls");
            hms();
            header();
            adminheader();
            string name,password,salary;
            cout << "enter doctor name: ";
            cin>>name;
            cout << "enter doctor password: ";
            cin >> password;
            cout << "enter doctor salary: ";
            cin>> salary;
            bool check=salarycheck(name,password,salary);
            if(check==true)
            {
                cout << "doctor salary update!"<<endl;
            } 
            else
            {
                cout<< "you enter wrong credential!"<<endl;
            }
            clearscreen();
        }

        if( adminoption==4)
        {
            system("cls");
            hms();
            header();
            adminheader();
            string name,password;
            cout << "enter doctor name: ";
            cin>> name;
            cout << "enter password: ";
            cin >> password;
            bool check=doctordelete(name,password);
            if(check==true)
            {
                cout<<"doctor deleted."<<endl;
            }
            else
            {
                cout<<"you enter wrong credential"<<endl;
            }
            clearscreen();
        }

        if( adminoption==7)
        {
            system("cls");
            hms();
            header();
            adminoption;
            cout<<"patients"<<"\t"<<"passwords"<<"\t"<<"age"<<"\t"<<"disease"<<"\t\t"<<"medicine"<<"\t"<<"contact"<<endl;
            for(int index=0;index<patientusercount;index++)
            {
                cout<<patient[index]<<"\t\t"<<patientpasswords[index]<<"\t\t"<<patientage[index]<<"\t"<<patientdisease[index]<<"\t\t"<<patientmedicine[index]<<"\t\t"<<patientcontact[index]<<endl;        
            }
            clearscreen();
        }

        if(adminoption==8)
        {
            system("cls");
            hms();
            header();
            adminheader();
            cout<<"bill payments"<<endl;
            cout<<endl;
            cout<<"patients"<<"\t"<<"payments"<<endl;
            for(int index=0;index<patientusercount;index++)
            {
                cout<< patient[index]<<"\t\t"<<billpayment[index]<<endl;
            }
            clearscreen();
        }
        if(adminoption==6)
        {
            system("cls");
            hms();
            header();
            adminheader();
            for(int index=0;index<doctorusercount;index++)
            {
                doctor[index]=doctor[index+1];
                doctorpasswords[index]=doctorpasswords[index+1];
                doctorfee[index]=doctorfee[index+1];
                doctorsalary[index]=doctorsalary[index+1];

            }
            doctorusercount=0;
            clearscreen();

        }
    }


}


int adminlogin()
{
    int option;
    cout << "Login menu!" << endl;
    cout << endl
         << endl;
    cout << "1.signin" << endl;
    cout << "2.signup" << endl;
    cout << "3.exit" << endl;
    cout << endl;
    cout << "option: ";
    cin >> option;
    return option;
}
void clearscreen()
{
    cout << "Press any key to continue!" << endl;
    getch();
    system("cls");
}

int mainmenu()
{
    int option;
    cout << "Select one of the following option: " << endl;
    cout << endl
         << endl;
    cout << "1.Admin" << endl;
    cout << "2.Doctor" << endl;
    cout << "3.Patient" << endl;
    cout << "4.exit " << endl;
    cout << endl;
    cout << "Option: ";
    cin >> option;
    return option;
}
int adminmenu()
{
    cout << "Select one of the following!" << endl;
    cout << endl
         << endl;
    cout << "1.view record" << endl;
    cout << "2.update fee" << endl;
    cout << "3.add doctor" << endl;
    cout << "4.delete doctor" << endl;
    cout << "5.view reviews" << endl;
    // cout << "6.doctor fee" << endl;
    cout << "6.delete record" << endl;
    cout << "7.view patient" << endl;
    cout << "8.view bill payments" << endl;
    cout << "9.update salary" << endl;
    cout << "10.exit" << endl;
    cout << endl
         << endl;
    int option;
    cout << "Option: ";
    cin >> option;
    return option;
}

int doctormenu()
{
    cout << "Select the following option!" << endl;
    cout << endl
         << endl;
    cout << "1.add patient" << endl;
    cout << "2.delete patient" << endl;
    cout << "3.view appointment" << endl;
    cout << "4.cancel appointment" << endl;
    cout << "5.add appointment" << endl;
    cout << "6.add prescription" << endl;
    cout << "7.view bill payment" << endl;
    cout << "8.generate test reports"<<endl; 
    cout<<  "9.view record"<<endl;
    cout << "10.exit" << endl;
    cout << endl
         << endl;
    int option;
    cout << "Option:";
    cin >> option;
    return option;
}

int patientmenu()
{
    cout << "select the following option!";
    cout << endl
         << endl;
    cout << "1.view prescription" << endl;
    cout << "2.bill payment" << endl;
    cout << "3.checkup fee" << endl;
    cout << "4.view appointment" << endl;
    cout << "5.give review" << endl;
    cout<<  "6.view test reports."<<endl;
    cout << "7.exit" << endl;
    cout << endl
         << endl;
    int option;
    cout << "Option: ";
    cin >> option;
    return option;
}

void hms()
{
    cout << "         ###        ###     ###                   ###     ##################       " << endl;
    cout << "         ###        ###     ##  ##             ##  ##     ##                       " << endl;
    cout << "         ###        ###     ##     ##      ##      ##       ##                     " << endl;
    cout << "         ###        ###     ##         ##          ##         ##                   " << endl;
    cout << "         ###        ###     ##                     ##           ##                 " << endl;
    cout << "         ##############     ##                     ##             ##               " << endl;
    cout << "         ###        ###     ##                     ##               ##             " << endl;
    cout << "         ###        ###     ##                     ##                 ##           " << endl;
    cout << "         ###        ###     ##                     ##                   ##         " << endl;
    cout << "         ###        ###     ##                     ##                     ##       " << endl;
    cout << "         ###        ###     ##                     ##      ##################      " << endl;
    cout << endl;
}

void header()
{
    cout << "*************************************************************" << endl;
    cout << "****************|Hospital management System|*****************" << endl;
    cout << "*************************************************************" << endl;
    cout << endl;
}

void adminheader()
{
    cout << "              ************                " << endl;
    cout << "              |Admin menu|                " << endl;
    cout << "              ************                " << endl;
    cout << endl;
}

void doctorheader()
{
    cout << "              *************                " << endl;
    cout << "              |Doctor menu|                " << endl;
    cout << "              *************                " << endl;
    cout << endl;
}

void patientheader()
{
    cout << "              *************                 " << endl;
    cout << "              |patient menu|                " << endl;
    cout << "              *************                 " << endl;
    cout << endl;
}
