#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<cstring>
#include<time.h>
using namespace std;
void position();
void Boss();
void Teacher();
void Student();
void bossOrder();
void tchOrder();
void stuOrder();
void tchSign();
void StuSign();
int tchCount();
int stuCount();
void tchSort(int);
void stuSort(int);
void tchList(int);
void stuList(int);
void logout();
void examInfo();
void mkExam();
void chkEtime();
void perExam(int, int, long int, int);
void allResults();
void stuResult();

struct TcherData
{
    char username[10] ;
    char password[10] ;

};

struct StuData
{
    char username[10] ;
    char password[10] ;

};

struct ExameData
{
    int eCode;
    char name[10];
    short int length;
    short int quNum;
    int rawTime;
};

struct Exam
{
    char question[100];
    char ans[4][50];
    short int rightAns;
};

struct StuResult
{
    int eCode;
    char stuName[20];
    char stuFamily[20];
    char eName[20];
    float mark;
    int eRawTime;
};

int NEC, QNUM;
float stMark=0;

int main()
{

    cout<< "***************Welcome to the  exames performing system***************" << endl <<
     "Enter your position:" << endl << "1. Admin" << endl << "2. Teacher" << endl<< "3. Student"<<endl ;

    position() ;

}
//to distinguish user's position:

void position()
{
    int place;

    cin>> place;

    if( place == 1 ) 
    {
        Boss();
    }

    else if( place == 2 )
    {
        Teacher();
    }

    else if( place == 3 )
    {
        Student();
    }

    else
    {
     cout<< "Invalid input!! Try again..." << endl;
     position();
    }
}
//boss position:

void Boss()
{
    char Username[11] , password[11], order;

    cout<< "Username: ";
    cin>> Username;
    cout<< "Password: ";
    cin>> password;

    if( strcmp( Username , "aarrmmnn") == 0 && strcmp( password , "11228") == 0 )
    {
        system("cls");

        cout<< "Hi sir" << endl << "What's your command?"<< endl;

        bossOrder();
    }

    else 
    {
        system("cls");
        cout<< "Invalid username or password!! "<<
        "Try again"<< endl;
        
        Boss();
    }
}
//teacher positune:

void Teacher()
{
    char username[11] , password[11];
    TcherData tch;
    bool nottch = true;

    cout<< "Username: ";
    cin>> username;
    cout<< "Password: ";
    cin>> password;

    FILE *tp;
    tp = fopen("TchrsList.dat" , "rb");
    if(!tp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek( tp , 0 , SEEK_SET);

    fread(&tch , sizeof(tch) , 1 , tp);
    while (!feof(tp))
    {
        if( strcmp(tch.username , username ) == 0 && strcmp(tch.password , password) == 0 )
        {
            nottch = false;
            system("cls");
            
            cout<< "Hi teacher" << endl<< "what's your command?" << endl;
            
            tchOrder();

            break;
        }

        fread(&tch , sizeof(tch) , 1 , tp);
    }
    fclose(tp);

    if(nottch)
    {
        cout<< "Invalid username or password!!" << endl <<
        "plz try again" << endl;
        system("cls");
        Teacher();
    }

}
//student positune:

void Student()
{
    char username[11] , password[11];
    int acc;
    bool newstu =true ;
    StuData stu;

    cout<< "1 => Sign up"<< endl << "2 => Login"<< endl;

    cin>> acc;

    if(acc == 2)
    {
        cout<< "Username: ";
        cin>> username;
        cout<< "Password: ";
        cin>> password;

        FILE *sp;
        sp = fopen("StuList.dat" , "rb");
        if(!sp)
        {
            cout<< "File was not found";
            exit(0);
        }

        fseek( sp , 0 , SEEK_SET);

        fread(&stu , sizeof(stu) , 1 , sp);
        while (!feof(sp))
        {
            if( strcmp(stu.username , username ) == 0 && strcmp(stu.password , password) == 0 )
            {
                newstu = false;
                system("cls");
                stuOrder();

                break;
            }

            fread(&stu , sizeof(stu) , 1 , sp);
        }
        fclose(sp);

        if(newstu)
        {
            cout<< "invalid username or password!! try again:" << endl;
        
            Student();
        }
    }

    else if(acc == 1)
    {
        cout<< "Username: ";
        cin>> stu.username ;
        cout<< "Password: ";
        cin>> stu.password;

        FILE *spp;

        spp = fopen("StuList.dat" , "ab");
        if(!spp)
        {
            cout<< "File was not found";
            exit(0);
        }

        fwrite(&stu , sizeof(stu) , 1 , spp);

        fclose(spp);

        cout<< "acount created successfully."<< endl;

        system("cls");
        cout<< "Hi nigga" << endl<< "what you want to do?" << endl;

        stuOrder();
    }

}

//what boss want's to do:

void bossOrder()
{
    int order, n;
    char nxt[2];

    cout<< "1 => Singn up a new Teacher" << endl
    << "2 => Singn up a new Student" << endl
    << "3 => Teachers List" << endl 
    << "4 => Students List" << endl 
    << "5 => Performed exames and results" << endl
    << "6 => Logout" << endl;

    cin>> order;

    switch (order)
    {
        case 1:
            tchSign();

            cout<< "Do you have any other commands? (y or n)"<< endl;

            cin>> nxt;

            if(strcmp(nxt , "y") == 0)
            {
                system("cls");
                bossOrder();
            }
                

            else if(strcmp(nxt , "n") == 0)
                logout();

            break;

        case 2:
            StuSign();

            cout<< "Do you have any other commands? (y or n)"<< endl;

            cin>> nxt;

            if(strcmp(nxt , "y") == 0)
            {
                system("cls");
                bossOrder();
            }

            else if(strcmp(nxt , "n") == 0)
                logout();

            break;

        case 3:
            n = tchCount();

            tchSort(n);

            tchList(n);

            cout<< "Do you have any other commands? (y or n)"<< endl;

            cin>> nxt;

            if(strcmp(nxt , "y") == 0)
            {
                system("cls");
                bossOrder();
            }

            else if(strcmp(nxt , "n") == 0)
                logout();
            
            break;

        case 4:
            n = stuCount();

            stuSort(n);

            stuList(n);

            cout<< "Do you have any other commands? (y or n)"<< endl;

            cin>> nxt;

            if(strcmp(nxt , "y") == 0)
            {
                system("cls");
                bossOrder();
            }

            else if(strcmp(nxt , "n") == 0)
                logout();

            break;

        case 5:
            allResults();

            cout<< "Do you have any other commands? (y or n)"<< endl;

            cin>> nxt;

            if(strcmp(nxt , "y") == 0)
            {
                system("cls");
                bossOrder();
            }

            else if(strcmp(nxt , "n") == 0)
                logout();
            break;

        case 6:
            logout();
            break;

    default:

    cout<< "Invalid input!! try again..."<< endl;
    bossOrder();
        break;
    }
}

//what teacher want's to do:
void tchOrder()
{

    int order, n;
    char nxt[2];

    cout<< "1 => Make a new exam" << endl
    << "2 => Performed exams and results" << endl
    << "3 => Singn up a new Student" << endl 
    << "4 => Students List" << endl 
    << "5 => Logout" << endl ;

    cin>> order;

    switch (order)
    {
    case 1:
        cout<< "Enter exam code: "; cin>> NEC; 
        cout<< "Enter the number of questions: " ; cin>> QNUM;

        examInfo();
        mkExam();

        cout<< "Do you have any other commands? (y or n)"<< endl;
        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            tchOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();
        break;

    case 2:
        allResults();

        cout<< "Do you have any other commands? (y or n)"<< endl;
        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            tchOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();
        break;
    
    case 3:
        StuSign();

        cout<< "Do you have any other commands? (y or n)"<< endl;
        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            tchOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();

        break;

    case 4:
        n = stuCount();
        stuSort(n);
        stuList(n);

        cout<< "Do you have any other commands? (y or n)"<< endl;
        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            tchOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();
        break;

    case 5:
        logout();
        break;

    default:
        
    cout<< "invalid order!! Plz try again"<< endl;
    tchOrder();
        break;
    }
}

//what student want's to do:
void stuOrder()
{
    int order, n;
    char nxt[2];

    cout << "1 => Current exames" << endl
    << "2 => Finished exams and results" << endl
    << "3 => Logout" << endl ;

    cin>> order;

    switch (order)
    {
    case 1:
        chkEtime();

        cout<< "Do you have any other commands? (y or n)"<< endl;
        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            stuOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();

        break;

    case 2:
        stuResult();

        cout<< "Do you have any other commands? (y or n)"<< endl;
        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            stuOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();

        break;

    case 3:
        logout();
        break;

    default:
        
    cout<< "Invalid input!! Plz try again"<< endl;
    stuOrder();
        break;
    }

}

//logout function:
void logout()
{
    system("cls");
    cout << "---Tanks for using our exam performing system---" << endl
            << "         come back soon:)  (By lord Arman) "<< endl<< "Press enter to exit..." ;
    cin.ignore();
    cin.ignore();
    exit(0);
}

//Boss signs up new teachers:
void tchSign()
{
    int n, i;

    cout<< "How many teacheres do you want to sign up?"<< endl;

    cin>> n;

    cout<< "Enter their username and password"<< endl;

    TcherData *teacher = new TcherData[n];
    
    for(i=0 ; i<n ;i++)
    {
    cin>> teacher[i].username ;
    cin>> teacher[i].password ;
    }

    FILE *tp ;
    tp = fopen("TchrsList.dat" , "a+b");
    if(!tp)
    {
        cout<< "File was not created";
        exit(0);
    }
    fwrite( teacher , sizeof(TcherData) , n , tp) ;

    fclose(tp) ;
}

//new students sign up:

void StuSign()
{
    int n, i;

    cout<< "How many students do you want to sign up?"<< endl;

    cin>> n;

    cout<< "Enter their username and password"<< endl;

    StuData *student = new StuData[n] ;

    for(i=0 ; i<n ; i++)
    {
        cin>> student[i].username;
        cin>> student[i].password;
    }

    FILE *sp ;
    sp = fopen("StuList.dat" , "ab");
    if(!sp)
    {
        cout<< "File was not created";
        exit(0);
    }

    fwrite(student , sizeof(StuData) , n , sp);
    fclose(sp);
}

//Count how many teachers have been signed in:

int tchCount()
{
    int n=0;

    TcherData teacher;

    FILE *tp ;
    tp = fopen("TchrsList.dat" , "rb");
    if(!tp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(tp , 0 , SEEK_SET);
    fread(&teacher , sizeof(teacher) , 1 , tp );
    while (!feof(tp))
    {
        ++n;

        fread(&teacher , sizeof(teacher) , 1 , tp );
    }

    fclose(tp) ;

    return n;
    
}

//Count how many students have been signed in:

int stuCount()
{
    int n=0;

    StuData stu;

    FILE *sp ;

    sp = fopen("StuList.dat" , "rb");
    if(!sp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(sp , 0 , SEEK_SET);
    fread(&stu , sizeof(stu) , 1 , sp );
    while (!feof(sp))
    {
        ++n;

        fread(&stu , sizeof(stu) , 1 , sp );
    }

    fclose(sp) ;

    return n;
}

//sort signrd up teachers file:
void tchSort(int n)
{
    TcherData *teacher = new TcherData[n] ;
    TcherData temp;

    FILE *tp;
    tp = fopen("TchrsList.dat" , "rb");
    if(!tp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(tp , 0 , SEEK_SET);
    fread(teacher , sizeof(TcherData) , n , tp );
    fclose(tp);

    for(int j=0 ; j < n-1 ; j++)
    {
        for(int i=0 ; i < n - j - 1 ; i++)
        {
            if(strcmp(teacher[i].username , teacher[i+1].username) > 0)
            {
                temp = teacher[i];
                teacher[i] = teacher[i+1];
                teacher[i+1] = temp;
            }
        }
    }

    FILE *tpp;
    tpp = fopen("TchrsList.dat" , "wb");
    if(!tpp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(tpp , 0 , SEEK_SET);
    fwrite(teacher , sizeof(TcherData) , n , tpp);
    fclose(tpp);

}

//sort signed up students file:

void stuSort(int n)
{
    StuData *student = new StuData[n];
    StuData temp;

    FILE *sp;
    sp = fopen("StuList.dat" , "rb");
    if(!sp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(sp , 0 , SEEK_SET);
    fread(student , sizeof(StuData) , n , sp);
    fclose(sp);

    for(int j=0 ; j < n-1 ; j++)
    {
        for(int i=0 ; i < n-1-j ; i++)
        {
            if(strcmp(student[i].username , student[i+1].username) > 0)
            {
                temp = student[i];
                student[i] = student[i+1];
                student[i+1] = temp;
            }
        }
    }
    FILE *spp;
    spp = fopen("StuList.dat" , "wb");
    if(!spp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(spp , 0 , SEEK_SET);
    fwrite(student , sizeof(StuData) , n , spp);
    fclose(spp);
}

//print signed up teachers list:

void tchList(int n)
{
    int c=1;
    TcherData *teacher = new TcherData[n] ;

    FILE *tp;
    tp = fopen("TchrsList.dat" , "rb");
    if(!tp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(tp , 0 , SEEK_SET);
    fread(teacher , sizeof(TcherData) , n , tp );

    for(int i = 0 ; i<n ; i++)
    {
        cout<< c << ". Ostad " << teacher[i].username << endl;

        c++;
    }

    fclose(tp);
}

//print signed up students list:
void stuList(int n)
{
    int c=1;
    StuData *student = new StuData[n];

    FILE *sp;
    sp = fopen("StuList.dat" , "rb");
    if(!sp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(sp , 0 , SEEK_SET);
    fread(student , sizeof(StuData) , n , sp);

    for(int i = 0 ; i<n ; i++)
    {
        cout<< c << ". " << student[i].username << endl;

        c++;
    }

    fclose(sp);
} 

//saving new exam specifications:

void examInfo()
{
    int year, mon ,day, hour, min, u=0;
    ExameData exam;
    time_t rawtime;
    struct tm *examTime;

    exam.eCode = NEC;
    exam.quNum = QNUM;
    cout<<"Enter lesson name: " ; cin>> exam.name;
    cout<<"*Enter exam date*"<< endl ;
    cout<<"Enter year: " ; cin>> year;
    cout<<"Enter month: " ; cin>> mon;
    cout<<"Enter month day: " ; cin>> day;
    cout<<"Enter hour: " ; cin>> hour;
    cout<<"Enter minute: " ; cin>> min;
    cout<<"Enter exam length (minutes): " ; cin>> exam.length;

    time ( &rawtime );
    examTime = localtime ( &rawtime );
    examTime->tm_year = year - 1900;
    examTime->tm_mon = mon - 1;
    examTime->tm_mday = day;
    examTime->tm_hour = hour;
    examTime->tm_min = min;
    examTime->tm_sec = 0;
    
    exam.rawTime = mktime( examTime );

    FILE *ep;
    ep = fopen("ExamesInf.dat" , "wb");
    if(!ep)
    {
        cout<< "File was not found";
        exit(0);
    }
    fseek(ep , 0 , SEEK_SET);
    fwrite(&exam , sizeof(exam) , 1 , ep);
    fclose(ep);

}

//define questiones and answeres:
void mkExam()
{
    int n = QNUM, i;

    cout<<"now for each one" << endl;

    Exam *test = new Exam[n];
    for(i=0 ; i < n ; i++)
    {
        cout<< "Enter question " << i+1 << ":"<< endl;
        cin.ignore();
        cin.ignore();
        fgets(test[i].question, sizeof(test[i].question), stdin);

        cout<< "Enter four choices"<< endl;

        cout<< "Enter choice 1 : "; fgets(test[i].ans[0], sizeof(test[i].ans[0]), stdin);
        cout<< "Enter choice 2 : "; fgets(test[i].ans[1], sizeof(test[i].ans[1]), stdin);
        cout<< "Enter choice 3 : "; fgets(test[i].ans[2], sizeof(test[i].ans[2]), stdin);
        cout<< "Enter choice 4 : "; fgets(test[i].ans[3], sizeof(test[i].ans[3]), stdin);
        cout<< "Enter right answer:(1,2...4) "; cin>> test[i].rightAns ;

    }
    system("cls");

    FILE *tp;
    tp = fopen("ExamesQues.dat" , "ab");
    if(!tp)
    {
        cout<< "File was not found";
        exit(0);
    }
    fwrite(&NEC , sizeof(NEC) , 1 , tp);
    fwrite(test , sizeof(Exam) , n , tp);
    fclose(tp);
    
    system("cls");
    cout<< "Exam saved successfully"<< endl;
}

//get the stu name and exam code then check exam time:
//if its exam time call perform function and save stu mark in StudentResult and ResultList
void chkEtime()
{
    struct stuResult
    {
        int Ecode;
        char Name[20];
        char famil[20];
        float Mark;
    }danshju;
    
    time_t nowraw;
    ExameData nexam;
    int ecode, elength, qnum, u;
    long int erawtime;
    char nxt[2], stuname[20], stufml[20], ename[10];
    bool RightCode=false;

    cout<< "Enter exam code: "; cin>> ecode;

    FILE *ep;
    ep = fopen("ExamesInf.dat" , "rb");
    if(!ep)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(ep , 0 , SEEK_SET);
    fread(&nexam , sizeof(nexam) , 1 , ep);
    while (!feof(ep))
    {
        if( ecode == nexam.eCode )
        {
            RightCode = true;
            erawtime = nexam.rawTime ;
            elength = nexam.length ;
            qnum = nexam.quNum ;
            strcpy(ename , nexam.name);
            break;
        }

        fread(&nexam , sizeof(nexam) , 1 , ep);
    }
    fclose(ep);

    if (!RightCode)
    {
        cout<< "No exam found."<< endl;
        cout<< "Do you have any other commands? (y or n)"<< endl;

        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            stuOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();
        
    }
    
    time(&nowraw);
    if(difftime(nowraw , erawtime) < 0)
    {
        cout<< "Exam time not arrived yet..."<< endl;

        cout<< "Do you have any other commands? (y or n)"<< endl;

        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            stuOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();
    }

    else if( difftime(nowraw , erawtime) >= (elength * 60))
    {
        cout<< "Exam has been finished..."<< endl;
        cout<< "Do you have any other commands? (y or n)"<< endl;

        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            stuOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();
    }

    cout<< "Enter your first name: "; cin>> stuname;
    cout<< "Enter your last name: "; cin>> stufml;
    time(&nowraw);
    if (difftime(nowraw , erawtime) > 0 && difftime(nowraw , erawtime) < (elength * 60))
    {
        perExam(qnum , ecode, erawtime, elength);
    }

    //save for stu result request
    StuResult stu;
    stu.eCode = ecode;
    strcpy(stu.stuName , stuname);
    strcpy(stu.stuFamily , stufml);
    strcpy(stu.eName , ename);
    stu.mark = stMark;
    stu.eRawTime = erawtime;

    FILE *srp;
    srp = fopen("StudentsResults.dat" , "ab");
    if(!srp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fwrite(&stu , sizeof(stu) , 1 , srp);
    fclose(srp);

    //save for tech or boss result request 
    danshju.Ecode = ecode;
    strcpy( danshju.Name , stuname);
    strcpy( danshju.famil , stufml);
    danshju.Mark = stMark;

    FILE *rlp;
    rlp = fopen("ResultList.dat" , "ab");
    if(!rlp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fwrite(&danshju , sizeof(danshju) , 1 , rlp);
    fclose(rlp);

    system("cls");

    cout<<"The answers saved successfully. Do you have any other commands? (y or n)"<< endl;

        cin>> nxt;

        if(strcmp(nxt , "y") == 0)
        {
            system("cls");
            stuOrder();
        }

        else if(strcmp(nxt , "n") == 0)
            logout();

}

//perform exam and print quesstions and get answers:
void perExam(int qnum, int ecode, long int erawtime, int elength)
{
    time_t nowraw;
    Exam *test = new Exam[qnum];
    float qmark;
    int codCheck, i, stuans, c, z;
    bool found = false, end = false, notold= true ;
    qmark = (float) 20/qnum ;

    FILE *tep;
    tep = fopen("ExamesQues.dat" , "rb");
    if(!tep)
    {
        cout<< "File was not found";
        exit(0);
    }
    
    fseek(tep , 0 , SEEK_SET);
    fread(&codCheck , sizeof(codCheck) , 1 , tep);
    while (!feof(tep))
    {
        if( codCheck == ecode )
        {
            found = true;
            fread(test , sizeof(Exam), qnum , tep);
            break;
        }
        fread(&codCheck , sizeof(codCheck) , 1 , tep);
    }
    fclose(tep);

    if(!found)
    {
        cout<<"Exam not found!! check the code and Enter again: "<< endl;
        chkEtime();
    }

    cout<<"**Exam startes**"<< endl;
    time(&nowraw);
    int x = ((erawtime + (elength*60) ) - nowraw) / 60 ;
    cout<< "Notices :"<< endl;
    cout<< "1) you have "<< x+1 << " minutes from now."<< endl;
    cout<< "2) Exam has "<< qnum << " questions." << endl;
    cout<< "3) The questions don't have return ability."<< endl;
    cout<< "4) If you enter in exam more than 1 time teacher will find and considers only the first mark."<< endl;
    cout<< "5) The answers after exam time won't be saved."<< endl;

    for(i=0 ; i < qnum ; ++i)
    {
        c=1;
        cout<< endl<< i+1<< ". "<< test[i].question<< endl;
        cout<< c <<") "<<test[i].ans[0] ; c++;
        cout<< c <<") "<<test[i].ans[1] ; c++;
        cout<< c <<") "<<test[i].ans[2] ; c++;
        cout<< c <<") "<<test[i].ans[3] ; c++;
        
        cout<<"Enter your answer: "; cin>> stuans;

        time(&nowraw);
        z = difftime(nowraw , erawtime);
        if( (((elength*60) - z) < 30) && notold )
        {
            cout<<"**Be careful you have less than 30 second time**"<< endl;
            notold = false;
        }
        if(difftime(nowraw , erawtime) > (elength * 60))
        {
            stuans = 0;
            end = true;
        }
    
        if(test[i].rightAns == stuans)
        {
            stMark += qmark;
        }

        if(end)
        {
            cout<< "Time finished"<< endl;
            break;
        } 

    }

}

//show 1 students mark in a exam;
void stuResult()
{
    StuResult studnt;
    int ecode;
    char stuname[20];
    char stufml[20];
    bool found=false;
    time_t date;
    cout<<"Enter exam code: "; cin>> ecode;
    cin.ignore();
    cout<< "Enter your name: "; cin>> stuname;
    cout<< "Enter your Last name: "; cin>> stufml;

    FILE *arp;
    arp = fopen("StudentsResults.dat" , "rb");
    if(!arp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(arp , 0 , SEEK_SET);
    fread(&studnt, sizeof(studnt), 1, arp);
    while (!feof(arp))
    {
        if(studnt.eCode == ecode)
        {
            if(strcmp(studnt.stuName , stuname) == 0 && strcmp(studnt.stuFamily , stufml) == 0)
            {
              cout<<"---"<< studnt.eName<< " Exam---"<< endl;
              date = studnt.eRawTime;
              cout<< "-performed on: "<< ctime(&date);
              cout<<"-mark: "<< studnt.mark<< " of 20"<< endl;
              found = true;
              break;
            }
        }
        fread(&studnt, sizeof(studnt), 1, arp);
    }
    fclose(arp);

    if(!found)
    {
        cout<< "Invalid exam code or wrong name! try again..."<< endl;
        stuResult();
    }
}

//show all students mark ;
void allResults()
{
    struct stuResult
    {
        int Ecode;
        char Name[20];
        char family[20];
        float Mark;
    }danshju;
    int entcode;
    int c=1;
    bool efound = false;
    
    cout<< "Enter exam code: "; cin>> entcode;

    FILE *rp;
    rp = fopen("ResultList.dat" , "rb");
    if(!rp)
    {
        cout<< "File was not found";
        exit(0);
    }

    fseek(rp , 0 , SEEK_SET);
    fread(&danshju , sizeof(danshju), 1 , rp);
    while (!feof(rp))
    {
        if(danshju.Ecode == entcode)
        {
            efound = true;
            cout<< c << ") ";
            cout<< danshju.Name << " "<< danshju.family<< ": "<< danshju.Mark << " of 20"<< endl;
            c++;
        }
        fread(&danshju , sizeof(danshju), 1 , rp);
    }
    fclose(rp);

    if(!efound) 
    {
        cout<< "Invalid code"<< endl;
    }
}
