#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#define ENTER 13
#define BKSP 8
#define SPACE 32
#define TAB 9
#define CNN 15
#define CBN 4

COORD coordinates = {0,0};
void gotocoordinate(int x,int y)
{
    coordinates.X=x;
    coordinates.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}


void setcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);

    }
}

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i;
void login();
void loading();
void welcome();
void welcomeMessage();
void t();
void checking_code(char[]);
int checking(char[]);


typedef struct
{
    char name[CNN],code[CBN];
    float rate;
    int quantity;
} record;
record stocks;


void cur(int);
void departmentbill();
void department_menu();
void view(record *,int,int);
void window_screen(int,int,int,int);
void view_concern();
void department_search();
void h_light(int,int);


void exit();




int getcust_id();
int getsupp_id();


void welcome();
void main_menu();


void main_box();
void box1();
void wbox();


void bill();


void about();


void product();
void pro_sale();
void stock();
void update_stock();
void pro_entry();
void pro_search();
void reminder();


void supplier();
void supp_entry();
void supp_list();
void sup_update();
void search();
void search_id();
void search_name();

void customer();
void cust_search();
void search_cid();
void search_cname();
void cust_entry();
void cust_list();
void cust_update();


void report_menu();
void report();
void sale_rpt();
void sale_rpt_daily();
void profit_rpt();
void pur_rpt();
void pur_rpt_daily();


struct store
{
    char id[6];
    char pro_name[20];
    int rack;
    char cabnit[2];
    int quantity;
    float sale;
    float total;
    float unit;
    float cost;
    float profit;
    float bye;
    int qty;
    char pur_date[15];
    char exp_date[15];
    char manu_date[15];
    int bill_no;
    char comp_name[20];
    char supp_name[30];
};

struct store temp;
struct store x[20];
FILE *ptr;

char a[10];
struct supplier
{
    int supp_id;
    char supp_name[25];
    char city[20];
    char mob_no[11];


};
struct supplier temp1;

struct customer
{
    int cust_id;
    char cust_name[30];
    char city[20];
    char mob_no[11];


};
struct customer temp_c;
FILE *ptr1;

struct bill
{
    char billno[6];
    char cname[30];
    char proname[30];
    int pro_qty;
    float pro_rate;
    float total;
    int day;
    int month;
    int year;

};
struct bill bil;
FILE *ptrbill;
struct sales_report
{
    char pro_id[6];
    char pror_name[20];
    char cust_name[30];
    int sDay,sMonth,sYear;
    int qty;
    float rate;
    float total;
};
struct sales_report s_r;
FILE *ptrs_r;

struct purchase_report
{
    char pro_id[6];
    char pror_name[20];
    char supp_name[30];
    int sDay,sMonth,sYear;
    int qty;
    float rate;
    float total;
};
struct purchase_report p_r;
FILE *ptrp_r;

struct profit_report
{
    char pro_id[6];
    char pror_name[20];
    int sDay,sMonth,sYear;
    int qty;
    float rate;
    float unit;
    float profit;
};
struct profit_report pr_r;
FILE *ptrpr_r;

void linkfloat()
{
    float f,*p;
    p=&f;
    f=*p;
}




int main()
{
    system("COLOR F1");
    welcomeMessage();
    loading();
    login();

    main_menu();


}



void window_screen(int a,int b,int c,int d)
{
    int v;
    system("cls");
    gotocoordinate(22,10);

    for (v=1; v<=10; v++)
        printf("*");
    printf(" * BUBT * ");
    for (v=1; v<=10; v++)
        printf("*");
    printf("\n\n");
    gotocoordinate(30,11);
    printf("INTAKE-44,13");
    gotocoordinate(30,13);
    printf("TEAM - 1");
    for (v=a; v<=b; v++)
    {
        gotocoordinate(v,17);
        printf("\xcd");   //═
        gotocoordinate(v,19);
        printf("\xcd");
        gotocoordinate(v,c);
        printf("\xcd");
        gotocoordinate(v,d);
        printf("\xcd");
    }

    gotocoordinate(a,17);
    printf("\xc9");        //╔
    gotocoordinate(a,18);
    printf("\xba");
    gotocoordinate(a,19);
    printf("\xc8");
    gotocoordinate(b,17);
    printf("\xbb");
    gotocoordinate(b,18);
    printf("\xba");
    gotocoordinate(b,19);
    printf("\xbc");

    for(v=c; v<=d; v++)
    {
        gotocoordinate(a,v);
        printf("\xba"); //╩
        gotocoordinate(b,v);
        printf("\xba");
    }
    gotocoordinate(a,c);
    printf("\xc9");
    gotocoordinate(a,d);
    printf("\xc8");
    gotocoordinate(b,c);
    printf("\xbb");
    gotocoordinate(b,d);
    printf("\xbc");

}

void welcomeMessage()
{
    system("cls");
    setcolor(1);

    printf("\n\n\n\n\n");
    printf("\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t      =                  WELCOME                  =");
    printf("\n\t\t      =                    TO                     =");
    printf("\n\t\t      =                   STORE                   =");
    printf("\n\t\t      =                 MANAGEMENT                =");
    printf("\n\t\t      =                   SYSTEM                  =");
    printf("\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}


void loading()
{
    system("cls");
    int r,q;

    gotoxy(36,14);
    setcolor(1);
    printf("LOADING...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",177);
    }
    system("cls");


}



void welcome()
{
    int j,k,l,m;

    int r,q;


    for(m=0; m<5; m++)
    {


        wbox();
        for(i=0; i<5; i++)
        {

            gotoxy(35,20);
            printf("WELCOME");
            k=i+2;

            gotoxy(38,22);
            printf("TO");
            l=i+3;

            gotoxy(28,24);
            printf("STORE");

            gotoxy(36,24);
            printf("MANAGEMENT");

            gotoxy(42,24);
            printf(" SYSTEM");
            gotoxy(52,45);
            j=i+1;

            gotoxy(36,28);

            printf("LOADING...");
            Sleep(40);




        }
    }
}





void login()
{

    int valid=0;
    int n,p, i=0;
    char uname[20],a;
    char pword[10];


    setcolor(10);
    gotocoordinate(22,10);
    printf("** WELCOME TO STORE MANAGEMENT SYSTEM **");
    gotocoordinate(22,13);
    printf("<<<<<<<<<<<<< LOGIN PAGE >>>>>>>>>>>>>>>>>>");
    printf("\n\n");
    setcolor(5);
    gotocoordinate(18,15);
    printf("Please Enter Your Valid User Name & Password\n");
    setcolor(6);
    printf("\n\n 	             User Name:  ");
    scanf("%s",uname);

    printf("\n		    Password:  ");

    while(1)
    {
        a = getch();
        if(a ==13)
        {
            break;
        }
        printf("*");
        pword[i] = a;
        i++;
    }
    pword[i]='\0';

    n = strcmp("admin",uname);
    p = strcmp("12345",pword);
    if(n == 0 && p == 0)
    {
        main_menu();
    }
    else
    {

        printf("\n\a\tWrong Password Or User Name Please Enter Valid Password And User Name\n");
        system("cls");
        login();
    }


}



void t()
{


    struct tm * now ;
    time_t t = time(NULL);

    now= localtime( &t );


    gotoxy(35,10);
    printf("Date: %i-%i-%i ",now->tm_mday,now->tm_mon+1,now->tm_year+1900);



}

void animation()
{
    for (i=20; i>=1; i--)
    {
        Sleep(30);
        gotoxy(1,i);

    }
    for (i=1; i<=20; i++)
    {

        Sleep(40);
        gotoxy(1,i);
    }
}

void ventry(char t[],int code)
{
    int i=0;
    if(code==0)
    {
        while((t[i]=getch())!='\r' && i<30)
            if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
            {
                printf("%c",t[i]);
                i++;
            }
            else if(t[i]==8 && i>0)
            {
                printf("%c%c%c",8,32,8);
                i--;

            }
    }
    else if(code==1)
    {
        while((t[i]=getch())!='\r' && i<11 )
            if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
            {
                printf("%c",t[i]);
                i++;
            }
            else if(t[i]==8 && i>0)
            {
                printf("%c%c%c",8,32,8);
                i--;

            }
    }
    else if(code==2)
    {
        while((t[i]=getch())!='\r' && i<30 )
            if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
            {
                printf("%c",t[i]);
                i++;
            }
            else if(t[i]==8 && i>0)
            {
                printf("%c%c%c",8,32,8);
                i--;

            }
    }

    t[i]='\0';
}

void box()
{
    for(i=3; i<=79; i++)
    {
        gotoxy(i,3);
        printf("%c",219);
        gotoxy(78,45);
        printf("%c",219);
        gotoxy(i,45);
        printf("%c",219);
    }

    for(i=3; i<=45; i++)
    {

        gotoxy(3,i);
        printf("%c",219);
        gotoxy(79,i);
        printf("%c",219);
    }
}
void wbox()
{
    for(i=5; i<=75; i++)
    {
        gotoxy(i,5);
        printf("%c",219);
        gotoxy(74,40);
        printf("%c",219);
        gotoxy(i,40);
        printf("%c",219);
    }

    for(i=5; i<=40; i++)
    {

        gotoxy(5,i);
        printf("%c",219);
        gotoxy(75,i);
        printf("%c",219);
    }
}

int getsupp_id()
{

    FILE *fp;
    fp=fopen("supplier.txt","r");
    if(fp==NULL)
    {
        gotoxy(22,15);
        printf("Data not Found.....");
        getch();
    }
    else
    {
        temp1.supp_id=100;
        rewind(fp);
        while(fscanf(fp,"%d %s %s %s ",&temp1.supp_id,temp1.supp_name,temp1.city, temp1.mob_no)!=EOF)
        {
        }
    }
    fclose(fp);
    return temp1.supp_id+1;
}

int getcust_id()
{
    FILE *fp;
    fp=fopen("customer.txt","r");
    if(fp==NULL)
    {
        gotoxy(22,15);
        printf("Data not Found.....");
        getch();
    }
    else
    {
        temp_c.cust_id=100;
        rewind(fp);
        while(fscanf(fp,"%d %s %s %s ",&temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no)!=EOF)
        {
        }
    }
    fclose(fp);
    return temp_c.cust_id+1;
}



void lbox()
{
    gotoxy(25,6);
    printf("%c",201);
    for(i=26; i<55; i++)
    {
        gotoxy(i,6);
        printf("%c",205);
    }
    gotoxy(55,6);
    printf("%c",187);
    gotoxy(25,6);
    for(i=6; i<8; i++)
    {
        gotoxy(25,i+1);
        printf("%c",186);
    }
    gotoxy(25,9);
    printf("%c",200);
    for(i=26; i<55; i++)
    {
        gotoxy(i,9);
        printf("%c",205);
    }
    gotoxy(55,9);
    printf("%c",188);
    gotoxy(55,6);
    for(i=6; i<8; i++)
    {
        gotoxy(55,i+1);
        printf("%c",186);
    }

}

void box1()
{
    gotoxy(1,3);
    printf("%c",201);
    for(i=1; i<79; i++)
    {
        gotoxy(1+i,3);
        printf("%c",205);
    }

    gotoxy(80,3);
    printf("%c",187);
    gotoxy(1,3);
    for(i=4; i<10; i++)
    {
        gotoxy(1,i);
        printf("%c",186);
    }
    gotoxy(1,9);
    for(i=4; i<8; i++)
    {
        gotoxy(80,i);
        printf("%c",186);
    }
}

void main_box()
{
    gotoxy(1,6);
    printf("%c",201);
    for(i=1; i<79; i++)
    {
        gotoxy(1+i,6);
        printf("%c",205);
    }

    gotoxy(80,6);
    printf("%c",187);
    gotoxy(1,6);
    for(i=5; i<35; i++)
    {
        gotoxy(1,2+i);
        printf("%c",186);
    }
    gotoxy(1,37);
    printf("%c",200);
    for(i=1; i<79; i++)
    {
        gotoxy(1+i,37);
        printf("%c",205);
    }
    gotoxy(80,37);
    printf("%c",188);
    gotoxy(80,6);
    for(i=5; i<35; i++)
    {
        gotoxy(80,2+i);
        printf("%c",186);
    }
}


void main_menu()
{
    FILE *fp;
    char ch='0';
    int no;
    int counting=1;

    const char *main_menu[]= {"  product ","   customer","  supplier ","   report_menu ","   bill", "   about","   Exit"};


    time_t t;
    int a;
    time(&t);
    system("cls");
    window_screen(16,60,21,31);
    gotocoordinate(25,16);
    setcolor(6);

    printf("%s",ctime(&t));
    gotocoordinate(33,18);
    setcolor(12);
    printf("MAIN MENU");
    for (a=0; a<=6; a++)
    {
        gotocoordinate(30,22+a+1);
        setcolor(50);
        printf("%s\n\n\n",main_menu[a]);
    }

    gotoxy(20,2);
    printf("Welcome To Store Management System");


    cur(7);

}


void cur(int no)
{
    FILE *fp;
    int counting=1;
    char ch='0';

    while(1)
    {

        switch(ch)
        {
        case 80:
            counting++;
            if(counting==no+1) counting=1;
            break;
        case 72:
            counting--;
            if(counting==0) counting=no;
            break;
        }
        h_light(no,counting);
        ch=getch();
        if(ch=='\r')
        {


            if(no==5)
            {
                if(counting==1) pro_entry();
                else if(counting==2) pro_sale();
                else if(counting==3) stock();
                else if(counting==4) pro_search();
                else main_menu();
            }

            if(no==6)
            {
                if(counting==1)  pur_rpt();
                else if(counting==2) profit_rpt();
                else if(counting==3) sale_rpt();
                else if(counting==4)  sale_rpt_daily();
                else if(counting==5)  pur_rpt_daily();
                else main_menu();
            }


            if(no==7)
            {
                if(counting==1)product();
                else if(counting==2)bill();
                else if(counting==3)supplier() ;
                else if(counting==4)customer();
                else if(counting==5)report_menu();
                else if(counting==6)about();
                else exit(0);
            }


        }


    }


}


void h_light(int no,int count)

{


    if(no==5)
    {

        gotoxy(23,23);
        printf("  Purchase New Product            ");
        gotoxy(23,24);
        printf("  Sale Product                    ");
        gotoxy(23,25);
        printf("  Stock of Product                ");
        gotoxy(23,26);
        printf("  Search Product                  ");
        gotoxy(23,27);
        printf("  Main Menu                        ");



        switch(count)
        {
        case 1:
            gotoxy(24,23);

            printf("->Purchase New Product         ");
            break;
        case 2:
            gotoxy(24,24);
            printf("->Sale Product                  ");
            break;
        case 3:
            gotoxy(24,25);
            printf("->Stock of Product              ");
            break;
        case 4:
            gotoxy(24,26);
            printf("->Search Product                ");
            break;
        case 5:
            gotoxy(24,27);
            printf("->Main Menu                     ");
            break;


        }
    }




    if(no==7)
    {

        gotoxy(28,23);
        printf("  Product                ");
        gotoxy(28,24);
        printf("  Bill                   ");
        gotoxy(28,25);
        printf("  supplier               ");
        gotoxy(28,26);
        printf("  customer               ");
        gotoxy(28,27);
        printf("  Report Menu             ");
        gotoxy(28,28);
        printf("  About                   ");
        gotoxy(28,29);
        printf("  Exit                    ");


        switch(count)
        {
        case 1:
            gotoxy(30,23);

            printf("->Product             ");
            break;
        case 2:
            gotoxy(30,24);
            printf("->Bill                ");
            break;
        case 3:
            gotoxy(30,25);
            printf("->Supplier             ");
            break;
        case 4:
            gotoxy(30,26);
            printf("->Customer             ");
            break;
        case 5:
            gotoxy(30,27);
            printf("->Report Menu           ");
            break;
        case 6:
            gotoxy(30,28);
            printf("->About                 ");
            break;
        case 7:
            gotoxy(30,29);
            printf("->Close shop                ");
            break;

        }

    }


    if(no==6)
    {

       gotoxy(28,23);
        printf("  Purchase Report                ");
        gotoxy(28,24);
        printf("  Profit Report                  ");
        gotoxy(28,25);
        printf("  Sale Report                    ");
        gotoxy(28,26);
        printf("  Daily Sale Report              ");
        gotoxy(28,27);
        printf("  Daily Purchase Report           ");
        gotoxy(28,28);
        printf("  Main Menu                       ");



        switch(count)
        {
        case 1:
            gotoxy(30,23);

            printf("->Purchase Report              ");
            break;
        case 2:
            gotoxy(30,24);
            printf("->Profit Report                 ");
            break;
        case 3:
            gotoxy(30,25);
            printf("->Sale Report                   ");
            break;
        case 4:
            gotoxy(30,26);
            printf("->Daily Sale Report             ");
            break;
        case 5:
            gotoxy(30,27);
            printf("->Daily Purchase Report           ");
            break;
        case 6:
            gotoxy(30,28);
            printf("->Main Menu                      ");
            break;


        }

    }


}


void supplier()
{
    char ch;
    do
    {
        system("cls");
        box();

        gotoxy(34,3);

        printf("----------------");
        gotoxy(35,4);

        printf("SUPPLIER MENU");
        gotoxy(34,5);

        printf("----------------");

        gotoxy(23,10);
        printf("1-Add New Supplier                 ");
        gotoxy(23,11);
        printf("2-Search Supplier                  ");
        gotoxy(23,12);
        printf("3-List of Existing Supplier        ");
        gotoxy(23,13);
        printf("4-Main Menu                        ");
        gotoxy(20,20);
        printf("Enter Value further Operation : ");

        ch=toupper(getch());
        switch(ch)
        {
        case '1':
            animation();
            supp_entry();
            break;
        case '2':
            animation();
            search();
            break;
        case '3':
            supp_list();
            break;
        case '4':
            main_menu();
            break;
        default:
            gotoxy(11,34);
            printf("Please Enter Right Character Only (1,2,3,4).");
            getch();
            system("cls");
        }
    }
    while(ch!='M');




}

void supp_entry()
{
    int id;
    char ch;
    FILE *fp;
    system("cls");
    fp=fopen("supplier.txt","a");

    if(fp==NULL)
    {
        printf("\n Can not open file!!");
        exit(0);
    }
    system("cls");
    ch='y';
    while(ch=='y')
    {
        system("cls");

        t();
        box();
        lbox();
        gotoxy(30,8);
        printf(" SUPPLIER ENTRY ");
        gotoxy(8,13);

        temp1.supp_id = getsupp_id();
        printf("SUPPLIER ID : %d ",temp1.supp_id);


        gotoxy(39,13);
        printf("SUPPLIER NAME : ");
        gotoxy(8,18);
        printf("CITY        : ");
        gotoxy(39,18);
        printf("CONTACT NO.  : ");


        gotoxy(55,13);
        ventry(temp1.supp_name,0);
        gotoxy(22,18);
        ventry(temp1.city,0);
        gotoxy(55,18);
        ventry(temp1.mob_no,1);

        gotoxy(20,30);
        printf("Save");
        gotoxy(28,30);
        printf("Cancel");
        gotoxy(18,36);
        printf("Press first character for the operation : ");
        ch=getch();
        if(ch=='s' || ch=='S')
        {
            fprintf(fp,"%d %s %s %s \n\n",temp1.supp_id,temp1.supp_name,temp1.city,temp1.mob_no);
            fprintf(fp,"\n");
            system("cls");
            gotoxy(20,20);
            printf("Supplier Added Successfully!!!!!");
            gotoxy(20,25);
            printf("More Entries  [y/n]");
            ch=getche();
            system("cls");
        }
    }
    fclose(fp);

}

void supp_list()
{
    char ch;
    int i;
    FILE *ptr1;
    system("cls");
    ptr1=fopen("supplier.txt","r");
    if(ptr1==NULL)
    {
        printf("\n\t Can Not Open File! ");
        supplier();
    }
    system("cls");
    box();
    t();

    gotoxy(8,48);
    printf("Press Any Key To Go To SUPPLIER MENU !!!");

    lbox();
    gotoxy(30,8);
    printf(" SUPPLIER LIST ");

    gotoxy(5,10);
    printf("ID.  SUPPLIER NAME.       CITY.     PH.NO.    ");
    gotoxy(6,12);
    i=14;
    printf("=====================================================");
    while(fscanf(ptr1,"%d %s %s %s ",&temp1.supp_id,temp1.supp_name,temp1.city,temp1.mob_no)!=EOF)
    {
        gotoxy(5,i);
        printf(" %d",temp1.supp_id);
        gotoxy(10,i);
        printf(" %s",temp1.supp_name);
        gotoxy(25,i);
        printf(" %s",temp1.city);
        gotoxy(41,i);
        printf(" %s",temp1.mob_no);
        i=i+2;
    }
    getche();
    system("cls");
}

void search()
{
    int ch;

    do
    {
        system("cls");

        gotoxy(17,10);
        printf(" Two Options Available For Searching ");
        gotoxy(15,15);
        printf("1-Search By ID Number  ");


        gotoxy(15,18);
        printf("2-Search By Name  ");


        gotoxy(15,21);

        printf("3-Return  ");

        main_box();
        gotoxy(17,24);
        printf("Press First Character For The Operation : ");
        ch=toupper(getche());
        switch(ch)
        {
        case '1':
            animation();
            search_id();
            break;
        case '2':
            animation();
            search_name();
            break;
        case '3':
            animation();
            supplier();
            break;
        default:
            gotoxy(22,18);
            printf("You entered wrong choice(1,2,3)!!");
            getche();

        }
    }
    while(ch!='R');
    getche();
}

void search_id()
{
    int id;
    int i;
    FILE *fp;
    system("cls");
    box();
    fp=fopen("supplier.txt","rb");
    gotoxy(13,8);
    printf("\xDB\xDB\xB2  Enter id to be searched:");

    scanf("%d",&id);

    i=18;
    gotoxy(9,15);
    printf("ID.  SUPPLIER NAME.   CITY.     PH.NO.     ");
    gotoxy(8,16);
    printf("===============================================");
    while(fscanf(fp,"%d %s %s %s ",&temp1.supp_id,temp1.supp_name,temp1.city,temp1.mob_no)!=EOF)
    {
        if(temp1.supp_id==id)
        {
            gotoxy(8,i);
            printf(" %d",temp1.supp_id);
            gotoxy(15,i);
            printf(" %s",temp1.supp_name);
            gotoxy(28,i);
            printf(" %s",temp1.city);
            gotoxy(40,i);
            printf(" %s",temp1.mob_no);
           gotoxy(20,35);

             i++;
            printf("Press Any key to Return Back Menu ....");
            break;
        }
    }
    if(temp1.supp_id!=id)
    {
        gotoxy(20,30);
        printf("Record not found!");
        system("cls");
        search();

    }
    fclose(fp);
    getche();
}

void search_name()
{
    int i;
    char name[20];
    FILE *fp;
    system("cls");
    box();
    fp=fopen("supplier.txt","rb");
    gotoxy(13,8);
    printf(" Enter Supplier Name to be searched : ");
    scanf("%s",&name);

    i=18;
    gotoxy(12,14);
    printf("ID. SUPPLIER NAME.   CITY.     PH.NO.  ");
    gotoxy(12,16);
    printf("===============================================");

    while(fscanf(fp,"%d %s %s %s ",&temp1.supp_id,temp1.supp_name, temp1.city,temp1.mob_no)!=EOF)
    {
        if(strcmp(temp1.supp_name,name)==0)
        {
            gotoxy(8,i);
            printf(" %d",temp1.supp_id);
            gotoxy(15,i);
            printf(" %s",temp1.supp_name);
            gotoxy(28,i);
            printf(" %s",temp1.city);
            gotoxy(40,i);
            printf(" %s",temp1.mob_no);
           i++;

 gotoxy(20,35);
    printf("Press Any key to Return Back Menu ....");
            break;
        }
    }
    if(strcmp(temp1.supp_name,name)!=0)
    {
        gotoxy(20,30);
        printf("Record not found!!!");
        search();
    }
    fclose(fp);
    getche();
}

void sup_update()
{
    int i;
    char ch;
    int sid;
    FILE *fp;
    FILE *ptr1;
    FILE *ft;
    system("cls");
    box();
    ptr1=fopen("supplier.txt","r+");
    if(ptr1==NULL )
    {
        printf("\n\t Can not open file!! ");
        supplier();
    }
    lbox();
    gotoxy(30,8);
    printf(" Modifying Supplier ");
    gotoxy(12,13);
    printf("Enter supplier ID :  ");

    scanf("%d",&sid);
    gotoxy(12,15);

    ft=fopen("temp.txt","w");
    if(ft==NULL)
    {
        printf(" Can not open file");
        supplier();
    }
    else
    {
        while(fscanf(ptr1,"%d %s %s %s ",&temp1.supp_id,temp1.supp_name, temp1.city,temp1.mob_no)!=EOF)
        {
            if(temp1.supp_id==sid)
            {
                gotoxy(18,11);
                printf(" Existing Record  ");
                gotoxy(10,13);
                printf("=================================================================");
                gotoxy(19,15);
                printf("ID:  \n");
                gotoxy(19,16);
                printf("SUPPLIER NAME:  \n");
                gotoxy(19,17);
                printf("CITY:  \n");
                gotoxy(19,18);
                printf("PH.NO:  \n") ;


                i=14;


                gotoxy(35,15);
                printf("%d",temp1.supp_id);
                gotoxy(35,16);
                printf("%s",temp1.supp_name);
                gotoxy(35,17);
                printf("%s", temp1.city);
                gotoxy(35,18);
                printf("%s",temp1.mob_no) ;




                gotoxy(12,22);
                printf("Enter New Name       : ");
                ventry(temp1.supp_name,0);
                gotoxy(12,24);
                printf("Enter New City       : ");
                ventry(temp1.city,0);

                gotoxy(12,26);
                printf("Enter New mobile no  : ");
                ventry(temp1.mob_no,1);


                gotoxy(20,32);
                printf("Update");
                gotoxy(30,32);
                printf("Cancel");
                gotoxy(18,36);
                printf("Press First character for the operation : ");
                ch=getch();
                if(ch=='u' || ch=='U')
                {
                    fprintf(ft,"%d %s %s %s \n",temp1.supp_id,temp1.supp_name,temp1.city,temp1.mob_no);
                    gotoxy(20,38);
                    printf("Supplier updated successfully...");
                    remove("supplier.txt");
                    rename("temp.txt","supplier.txt");

                }
            }
            else
            {
                fprintf(ft,"%d %s %s %s \n",temp1.supp_id,temp1.supp_name,temp1.city,temp1.mob_no);
                fflush(stdin);
            }
        }

        fclose(ft);
        fclose(ptr1);
    }
}

void customer()
{
    char ch;
    do
    {

        system("cls");
        box();



        gotoxy(34,3);
        printf("---------------");
        gotoxy(35,4);
        printf("Customer Menu.");
        gotoxy(34,5);
        printf("---------------");

        gotoxy(23,10);
        printf("1-Add New Customer                ");
        gotoxy(23,11);
        printf("2-Search Customer                 ");
        gotoxy(23,12);
        printf("3-List of Existing Customer       ");
        gotoxy(23,13);
        printf("4-Main Menu                       ");


        gotoxy(10,18);
        printf("Enter value further Operation ");


        ch=toupper(getch());
        switch(ch)
        {
        case '1':
            animation();
            cust_entry();
            break;
        case '2':
            animation();
            cust_search();
            break;
        case '3':
            cust_list();
            break;
        case '4':
            main_menu();
            break;
        default:
            gotoxy(11,34);
            printf("Please Enter Right Character Only(1,2,3,4).");
            getch();
        }
    }
    while(ch!='M');



}


void product()
{

    FILE *fp;
    char st;
    int d;
    const char *main_menu[]= {"   Add New Product","  Update Product","   Search Product ","   List of Existing Product","   Main Menu "};
    system("cls");


    window_screen(16,60,20,32);
    gotocoordinate(32,18);
    printf("PRODUCT");
    for (d=0; d<=4; d++)
    {
        setcolor(4);
        gotocoordinate(30,22+d+1);
        printf("%s\n\n\n",main_menu[d]);
    }

    cur(5);

}

void report_menu()
{
    FILE *fp;
    char ch;
    int e;
    const char *main_menu[]= {"   Purchase Report","  Profit Report"," Sale Report ","   Daily Sale Report ","  Daily Purchase Report","   Main Menu "};
    system("cls");


    window_screen(16,65,20,32);
    gotocoordinate(32,18);
    printf("REPORT MENU");
    for (e=0; e<=5; e++)
    {
        setcolor(4);
        gotocoordinate(30,22+e+1);
        printf("%s\n\n\n",main_menu[e]);
    }

    cur(6);


}

void about()
{
    int c;
    system("cls");

    do
    {

        gotoxy(28,4);
        printf("*****## STORE MANAGEMENT SYSTEM ##*****");
        gotoxy(10,8);
        printf("=> This Project Is About Store Management System");
        gotoxy(10,10);
        printf("=> In This Project we Can Add Product ,Customer,Supplier Details");
        gotoxy(10,12);
        printf("=> We Can Modify & Delete Existing Record");
        gotoxy(10,14);
        printf("=> We Can Also Search Product ,Customer , Supplier Details");
        gotoxy(10,16);
        printf("=> It's Helpful For Display Stock Of Product ");

        printf("\n\n\t==>Press 1 for main menu->>>>");
        c = (getche());

        switch (c)
        {
        case '1':
            animation();
            main_menu();
            gotoxy(26,24);
            puts("<<--ENTER FROM 1 PLEASE-->>");
            getch();
        }

    }
    while(c != '1');

}

void reminder()
{
    FILE *ptr1;
    ptr1=fopen("store.txt","r");
    if(ptr1==NULL)
    {
        //	printf("\n\t Can not open File! ");
    }
    while((fread(&temp,sizeof(temp),1,ptr1))==1)
    {
        if(temp.quantity<10)
        {
            gotoxy(10,20);

            printf("%s : ",temp.pro_name);
            printf("Quantity of this Product is less then 10");
        }
    }
}



void bill()
{

    struct tm * now ;
    time_t t = time(NULL);

    now= localtime( &t );

    FILE *ptrbill;
    char id[6];
    int j=1,d1,m,y,k;
    float netamt=0.0;


    system("cls");
    ptrbill=fopen("dbbill.txt","r");
    gotoxy(13,4);
    printf("Enter bill no : ");
    scanf("%s",&id);
    system("cls");
    gotoxy(25,3);

    box();
    gotoxy(7,7);
    printf("Bill No: ");
    printf(" %s",id);
    gotoxy(7,9);
    printf("Customer Name: ");
    gotoxy(40,7);
    printf("Date & Time: ");
    printf("Date: %i-%i-%i ",now->tm_mday,now->tm_mon+1,now->tm_year+1900);
    gotoxy(7,12);
    printf("Sr.No   Product Name       Qty          Rate         Total ");
    gotoxy(6,14);
    printf("---------------------------------------------------------------------");

    i=15;
    while(fscanf(ptrbill,"%s %s %s %d %f %f %d %d %d",bil.billno,bil.cname,bil.proname,&bil.pro_qty,&bil.pro_rate,&bil.total,&bil.day,&bil.month,&bil.year)!=EOF)
    {

        do
        {
            if(strcmp(id,bil.billno)==0)
            {
                gotoxy(7,i);
                printf(" %d",j);
                gotoxy(14,i);
                printf(" %s",bil.proname);
                gotoxy(22,9);
                printf(" %s",bil.cname);
                gotoxy(35,i);
                printf(" %d",bil.pro_qty);
                gotoxy(47,i);
                printf(" %.2f",bil.pro_rate);
                gotoxy(60,i);
                printf(" %.2f",bil.total);
                netamt=netamt+bil.total;
                i++;
                j++;
                gotoxy(35,32);
                printf("                                ");
                gotoxy(20,50);

                printf("Press Any key to go to  MENU ...........");

            }


        }
        while(feof(ptrbill));

    }


    gotoxy(6,35);
    printf("---------------------------------------------------------------------");
    gotoxy(50,37);
    printf("Net Amount : ");
    printf("%.2f",netamt);

    fclose(ptrbill);
    getch();

    system("cls");
    main_menu();
}


void cust_entry()
{
    char ch;
    int id;
    FILE *fp;
    system("cls");
    fp=fopen("customer.txt","a");
    if(fp==NULL)
    {
        printf("\n Can not open file!!");
        exit(0);
    }
    system("cls");
    ch='y';
    while(ch=='y')
    {
        system("cls");
        t();
        box();
        lbox();
        gotoxy(30,8);
        printf(" CUSTOMER ENTRY ");
        gotoxy(8,13);
        temp_c.cust_id=getcust_id();
        printf("CUSTOMER ID :%d",temp_c.cust_id);

        gotoxy(39,13);
        printf("CUSTOMER NAME : ");
        gotoxy(8,18);
        printf("CITY        : ");
        gotoxy(39,18);
        printf("CONTACT NO.   : ");


        gotoxy(55,13);
        ventry(temp_c.cust_name,0);
        gotoxy(22,18);
        ventry(temp_c.city,0);
        gotoxy(55,18);
        ventry(temp_c.mob_no,1);



        gotoxy(20,30);
        printf("Save");
        gotoxy(28,30);
        printf("Cancel");
        gotoxy(18,36);
        printf("Press First Character For The Operation : ");
        ch=getch();
        if(ch=='s' || ch=='S')
        {
            fprintf(fp,"%d %s %s %s\n",temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no);
            fprintf(fp,"\n");
            fflush(stdin);
            system("cls");
            gotoxy(20,20);
            printf("Customer Added Successfully!!!!!");
            gotoxy(20,25);
            printf("More Entries  [y/n] ");
            ch=getche();
            system("cls");



        }
    }
    fclose(fp);
}

void cust_list()
{
    FILE *ptr1;
    char ch;
    system("cls");
    ptr1=fopen("customer.txt","r");
    if(ptr1==NULL)
    {
        printf("\n\t Can not open File! ");
        customer();
    }
    system("cls");
    box();

    gotoxy(8,48);
    printf("Press Any key to go to CUSTOMER MENU!!!");

    lbox();
    gotoxy(30,8);
    printf(" CUSTOMER LIST ");

    i=14;
    gotoxy(5,10);
    printf(" ID. CUSTOMER NAME.    CITY.     MOBILE.NO.   ");
    gotoxy(4,12);
    printf("================================================");
    while(fscanf(ptr1,"%d %s %s %s",&temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no)!=EOF)
    {
        gotoxy(5,i);
        printf(" %d",temp_c.cust_id);
        gotoxy(11,i);
        printf(" %s",temp_c.cust_name);
        gotoxy(28,i);
        printf(" %s",temp_c.city);
        gotoxy(40,i);
        printf(" %s",temp_c.mob_no);

        i=i+2;
    }
    getche();
}

void cust_search()
{
    int ch;

    do
    {
        system("cls");
        gotoxy(17,10);
        printf(" Two options Available for searching ");
        gotoxy(15,15);
        printf("1-Search by ID number  ");
        gotoxy(15,18);
        printf("2-Search by Name  ");
        gotoxy(15,21);
        printf("3-Return");
        main_box();
        gotoxy(17,24);
        printf("Press First character for the operation : ");
        ch=toupper(getche());
        switch(ch)
        {
        case '1':
            animation();
            search_cid();

            break;
        case '2':
            animation();
            search_cname();
            break;
        case '3':
            animation();
            customer();
            break;
        default:
            gotoxy(22,18);
            printf("You entered wrong choice!!!!!");
            getch();
        }
    }
    while(ch!='R');
    getche();
}

void search_cid()
{
    FILE *ptr1;
    int id;
    system("cls");
    box();
    ptr1=fopen("customer.txt","rb");
    gotoxy(13,8);
    printf("\xDB\xDB\xB2  Enter id to be searched:");
    scanf("%d",&id);

    i=18;
    gotoxy(9,15);
    printf(" ID. CUSTOMER NAME.    CITY.     MOBILE.NO.   ");
    gotoxy(8,16);
    printf("==============================================================");
    while(fscanf(ptr1,"%d %s %s %s",&temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no)!=EOF)
    {
        if(temp_c.cust_id==id)
        {
            gotoxy(8,i);
            printf(" %d",temp_c.cust_id);
            gotoxy(15,i);
            printf(" %s",temp_c.cust_name);
            gotoxy(28,i);
            printf(" %s",temp_c.city);
            gotoxy(40,i);
            printf(" %s",temp_c.mob_no);

            gotoxy(20,35);

            printf("Press Any key to go to CUSTOMER MENU ...........");
            break;
        }
    }
    if(temp_c.cust_id!=id)
    {
        gotoxy(20,30);
        printf("Record not found!");
        system("cls");
        customer();
    }
    fclose(ptr1);
    getche();
}

void search_cname()
{
    FILE *ptr1;
    char name[20];
    system("cls");
    box();
    ptr1=fopen("customer.txt","rb");
    gotoxy(12,8);
    printf("\xDB\xDB\xB2  Enter Customer Name to be searched:");
    scanf("%s",&name);

    i=18;
    gotoxy(9,15);
    printf(" ID. CUSTOMER NAME.    CITY.     MOBILE.NO.  ");
    gotoxy(8,16);
    printf("=================================================");
    while(fscanf(ptr1,"%d %s %s %s",&temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no)!=EOF)
    {
        if(strcmp(temp_c.cust_name,name)==0)
        {
            gotoxy(8,i);
            printf(" %d",temp_c.cust_id);
            gotoxy(15,i);
            printf(" %s",temp_c.cust_name);
            gotoxy(28,i);
            printf(" %s",temp_c.city);
            gotoxy(40,i);
            printf(" %s",temp_c.mob_no);

            gotoxy(20,35);
            printf("Press Any key to go to CUSTOMER MENU ...........");
            break;
        }
    }
    if(strcmp(temp_c.cust_name,name)!=0)
    {
        gotoxy(5,10);

        printf("Record not found!");
        system("cls");
        cust_search();
    }
    fclose(ptr1);
    getche();
}

void cust_update()
{
    int i;
    char ch;
    int cid;
    FILE *ft;
    FILE *ptr1;
    system("cls");
    box();
    ptr1=fopen("customer.txt","rb+");
    if(ptr1==NULL)
    {
        printf("\n\t Can not open file!! ");
        customer();
    }
    lbox();
    gotoxy(30,8);
    printf(" Modifying customer ");
    gotoxy(12,13);
    printf("Enter the CUSTOMER ID : ");
    scanf("%d",&cid);
    gotoxy(12,15);

    ft=fopen("temp.txt","w");
    if(ft==NULL)
    {
        printf("\n Can not open file");
        customer();
    }
    else
    {

        while(fscanf(ptr1,"%d %s %s %s ",&temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no)!=EOF)
        {
            if(temp_c.cust_id==cid)
            {
                gotoxy(25,17);
                printf("*** Existing Record ***");
                gotoxy(10,19);
                printf("%d\t %s \t%s \t%s ",temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no);
                gotoxy(12,22);
                printf("Enter New Name         : ");
                ventry(temp_c.cust_name,0);
                gotoxy(12,24);
                printf("Enter New City         : ");
                ventry(temp_c.city,0);
                gotoxy(12,26);
                printf("Enter New mobile no    : ");
                ventry(temp_c.mob_no,1);

                gotoxy(20,32);
                printf("Update");
                gotoxy(30,32);
                printf("Cancel");
                gotoxy(18,35);
                printf("Press First character for the operation : ");
                ch=getch();
                if(ch=='u' || ch=='U')
                {
                    fprintf(ft,"%d %s %s %s \n",temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no);

                    fflush(stdin);
                    gotoxy(20,36);
                    printf("Customer updated successfully...");
                    remove("customer.txt");
                    rename("temp.txt","customer.txt");
                }
            }
            else
            {
                fprintf(ft,"%d %s %s %s \n",temp_c.cust_id,temp_c.cust_name, temp_c.city,temp_c.mob_no);
                fflush(stdin);
            }
        }


        fclose(ft);
        fclose(ptr1);
    }

}

void pro_entry()
{
    char ch,id[6];
    time_t t = time(0);
    struct tm * now = localtime( & t );
    int f;
    FILE *fp, *ft;
    FILE *ptrp_r;
    ptrp_r=fopen("purreport.txt","a");
    system("cls");
    ch='Y';
    while(ch=='Y')
    {
        system("cls");
        box();
        lbox();
        gotoxy(30,8);
        printf(" PRODUCT PURCHASE  ");
        {

            gotoxy(7,11);
            printf("PRODUCT-ID      : ");

            gotoxy(40,11);
            printf("PRODUCT NAME    : ");

            gotoxy(7,14);
            printf("ENTER LEVEL NO  : ");

            gotoxy(40,14);
            printf("ENTER BLOCK NO  : ");

            gotoxy(7,18);
            printf("COMPANY NAME    : ");

            gotoxy(40,18);
            printf("SUPPLIER NAME   : ");

            gotoxy(7,21);
            printf("UNIT COST   TK. :  ");

            gotoxy(40,21);
            printf("SALE COST   TK. : ");

            gotoxy(7,24);
            printf("QUANTITY        :  ");

            gotoxy(7,27);
            printf("MFG.DATE(dd-mm-yyyy): ");

            gotoxy(7,29);
            printf("EXP.DATE(dd-mm-yyyy): ");

            gotoxy(25,11);
            ventry(temp.id,1);
            strcpy(id,temp.id);

            fp=fopen("store.txt","r");
            while((fread(&temp,sizeof(temp),1,fp))==1)
            {

                if(strcmp(id,temp.id)==0)
                {
                    f=1;
                    break;
                }
            }
            fclose(fp);
            if(f==1)
            {
                gotoxy(20,31);
                printf("ID Already Exists");
                getch();
                system("cls");
                pro_entry();
            }
            else
            {
                ptr=fopen("store.txt","a+b");
                strcpy(temp.id,id);
                strcpy(p_r.pro_id,temp.id);
            }

            gotoxy(58,11);
            ventry(temp.pro_name,0);
            strcpy(p_r.pror_name,temp.pro_name);

            gotoxy(25,14);
            ventry(a,1);
            temp.rack= atoi(a);

            gotoxy(58,14);
            ventry(temp.cabnit,2);

            gotoxy(25,18);
            ventry(temp.comp_name,0);

            gotoxy(58,18);
            ventry(temp.supp_name,0);
            strcpy(p_r.supp_name,temp.supp_name);

            gotoxy(25,21);
            ventry(a,1);
            temp.unit= atof(a);

            p_r.rate=temp.unit;
            gotoxy(58,21);
            ventry(a,1);
            temp.sale= atof(a);

            gotoxy(25,24);
            ventry(a,1);
            temp.quantity= atoi(a);
            p_r.qty=temp.quantity;

            gotoxy(29,27);

            ventry(temp.manu_date,1);
            gotoxy(29,29);

            ventry(temp.exp_date,1);

            gotoxy(7,31);
            printf("==========================================================");
            temp.total=temp.quantity*temp.sale;
            gotoxy(10,33);
            printf("TOTAL SALE COST = TK. %.2f",temp.total);
            temp.cost=(temp.unit*temp.quantity);
            gotoxy(40,33);
            printf("TOTAL UNIT COST = TK. %.2f",temp.cost);
            p_r.total=temp.cost;
            p_r.sDay=now->tm_mday;
            p_r.sMonth=now->tm_mon+1;
            p_r.sYear=now->tm_year+1900;
        }
        gotoxy(20,35);
        printf("S");
        gotoxy(21,35);
        printf("ave");
        gotoxy(28,35);
        printf("C");
        gotoxy(29,35);
        printf("ancel");
        gotoxy(18,38);
        printf("Press First character for the operation : ");
        ch=toupper(getche());
        system("cls");

        if(ch=='S')
        {
            fwrite(&temp,sizeof(temp),1,ptr);
            fflush(stdin);

            fprintf(ptrp_r,"%s %s %s %d %.2f %.2f %d %d %d\n",p_r.pro_id,p_r.pror_name,p_r.supp_name,p_r.qty,p_r.rate,p_r.total,p_r.sDay,p_r.sMonth,p_r.sYear);
            system("cls");
            gotoxy(20,20);
            printf("Product Added successfully!!!!!!");
            gotoxy(20,25);
            printf("More entries  [y/n]");
            ch=toupper(getch());
            system("cls");
        }
    }
    fclose(ptr);
    fclose(ptrp_r);
}

void pro_sale()
{
    struct bill bil;

    time_t t = time(0);
    struct tm * now = localtime( &t );
    int j,n,i,a,billno;
    int d1,m,y;
    float b,total,rate;
    char tar[30],ch,proname[30],c_name[30],cname[30];
    FILE *fp,*fpc,*ptr1,*ptr,*ptrs_r,*ptrpr_r;

    int count=0;

    d1=now->tm_mday;
    m=now->tm_mon+1;
    y=now->tm_year+1900;
    ch='y';
    while(ch=='y')
    {
        fp = fopen("dbbill.txt","a");
        ptr1 = fopen("customer.txt","r");
        ptr = fopen("store.txt","r");
        ptrs_r=fopen("saleRpt.txt","a");
        ptrpr_r=fopen("profitRpt.txt","a");
        system("cls");
        box();
        for(i=3; i<=45; i++)
        {
            gotoxy(50,i);
            printf("%c",219);
        }
        i=9;
        gotoxy(52,7);
        printf("Cust_ID    Cust_Name");

        while(fscanf(ptr1,"%d %s %s %s ",&temp_c.cust_id,&temp_c.cust_name,&temp_c.mob_no,&temp_c.city)!=EOF)
        {
            gotoxy(53,i);
            printf("%d",temp_c.cust_id);
            gotoxy(64,i);
            printf("%s",temp_c.cust_name);
            i+=2;
        }

        gotoxy(9,7);
        printf("ENTER PRODUCT ID TO BE SOLD  : ");
        ventry(tar,1);

        j=0;
        while((fread(&temp,sizeof(temp),1,ptr))==1)
        {
            if((strcmp(temp.id,tar)<0) || (strcmp(temp.id,tar)>0))
            {
                x[j] = temp;
                j++;
            }
            else if((strcmp(temp.id,tar)==0))
            {

                gotoxy(8,10);
                printf(" Product Name        : %s",temp.pro_name);
                gotoxy(8,12);
                printf(" Quantity in stock    : %d",temp.quantity);
                gotoxy(8,14);
                printf(" Sales price          : %.2f",temp.sale);
                gotoxy(8,16);
                printf("Enter bill number     : ");

                ventry(bil.billno,1);

                gotoxy(8,18);
                printf("Enter customer Name   : ");

                ventry(c_name,0);

                gotoxy(8,20);
                printf("Quantity want to sale : ");

                scanf("%d",&a);

                pr_r.profit=(temp.sale-temp.unit)*a;
                x[j]=temp;
                x[j].quantity=(x[j].quantity-a);
                x[j].total=(x[j].quantity*temp.sale);
                x[j].cost=(x[j].quantity*temp.unit);
                x[j].bye=(x[j].sale*a);
                b=x[j].bye;
                x[j].qty=a;
                j++;
                count++;
                strcpy(bil.cname,c_name);
                strcpy(s_r.cust_name,c_name);
                strcpy(bil.proname,temp.pro_name);
                bil.pro_qty=a;
                bil.pro_rate=temp.sale;
                bil.total=temp.sale*a;

                bil.day=d1;
                bil.month=m;
                bil.year=y;

                fprintf(fp,"%s %s %s %d %.2f %.2f %d %d %d\n",bil.billno,bil.cname,bil.proname,bil.pro_qty,bil.pro_rate,bil.total,bil.day,bil.month,bil.year);
                fflush(stdin);

                fclose(fp);

                s_r.sDay=d1;
                s_r.sMonth=m;
                s_r.sYear=y;
                strcpy(s_r.pro_id,tar);
                strcpy(s_r.pror_name,temp.pro_name);
                s_r.qty=a;
                s_r.rate=temp.sale;
                s_r.total=temp.sale*a;


                fprintf(ptrs_r,"%s %s %s %d %.2f %.2f %d %d %d\n",s_r.pro_id,s_r.pror_name,s_r.cust_name,s_r.qty,s_r.rate,s_r.total,s_r.sDay,s_r.sMonth,s_r.sYear);
                fflush(stdin);
                fclose(ptrs_r);


                pr_r.sDay=d1;
                pr_r.sMonth=m;
                pr_r.sYear=y;
                strcpy(pr_r.pro_id,tar);
                strcpy(pr_r.pror_name,temp.pro_name);
                pr_r.qty=a;
                pr_r.rate=temp.sale;
                pr_r.unit=temp.unit;
                fprintf(ptrpr_r,"%s %s %d %d %d %d %.2f %.2f  %.2f\n",pr_r.pro_id,pr_r.pror_name,d1,pr_r.sMonth,pr_r.sYear,pr_r.qty,pr_r.unit,pr_r.rate,pr_r.profit);
                fflush(stdin);
                fclose(ptrpr_r);

            }
        }
        if (count==0)
        {
            system("cls");
            gotoxy(33,10);
            printf("Not in stock!!!!!");
            getch();
            return;
        }
        fclose(ptr1);
        fclose(ptr);
        n = j;
        system("cls");
        ptr=fopen("store.txt","wb");
        for(i=0; i<n; i++)
            fwrite(&x[i],sizeof(x[i]),1,ptr);
        fclose(ptr);
        system("cls");
        box();
        gotoxy(8,15);
        printf("* Price paid by customer = %.2f",b);
        gotoxy(8,17);
        printf("* Quantity sold          = %d",a);
        getch();
        gotoxy(10,20);
        printf("More Entries =(y/n) :");
        ch=getch();

        system("cls");
        product();
    }

}

void stock()
{
    char ch;
    FILE *ptr1;
    int i,c;
    do
    {
        system("cls");
        ptr1=fopen("store.txt","r");
        if(ptr1==NULL)
        {
            printf("\n\t Can not open File! ");
            exit(1);
        }
        system("cls");
        box();
        lbox();
        gotoxy(30,8);
        printf(" STOCK OF PRODUCT ");
        i=14;
        gotoxy(9,10);
        printf("ID.   PRODUCT NAME.    QTY     Supplier Name     Exp.Date");
        gotoxy(9,12);
        printf("==================================================================\n");

        while((fread(&temp,sizeof(temp),1,ptr1))==1)
        {
            gotoxy(9,i);
            printf(" %s",temp.id);
            gotoxy(15,i);
            printf(" %s",temp.pro_name);
            gotoxy(32,i);
            printf(" %d",temp.quantity);
            gotoxy(43,i);
            printf(" %s",temp.supp_name);
            gotoxy(60,i);
            printf(" %s",temp.exp_date);
            i++;
        }
        gotoxy(10,42);
        printf("Press [1] for Update Product Stock  & [0] for main menu ");
        c = (getche());
        switch (c)
        {
        case '0':
            animation();
            main_menu();
            break;
        case '1':
            update_stock();
            break;
        }

    }
    while(c != '1');
    getch();
    system("cls");
    product();
}


void pro_search()
{
    char mid[6];
    FILE *ptr1;
    int i,c;
    system("cls");
    ptr1=fopen("store.txt","r");
    if(ptr1==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    box();

    gotoxy(10,7);
    printf("Enter Product Id to be searched : ");
    scanf("%s",&mid);
    system("cls");
    box();
    lbox();
    gotoxy(30,8);
    printf(" PRODUCT ");
    i=14;
    gotoxy(9,10);
    printf("ID.   PRODUCT NAME.    QTY     Supplier Name     Exp.Date");
    gotoxy(9,12);
    printf("==================================================================\n");
    while((fread(&temp,sizeof(temp),1,ptr1))==1)
    {
        if(strcmp(mid,temp.id)==0)
        {
            gotoxy(9,i);
            printf(" %s",temp.id);
            gotoxy(15,i);
            printf(" %s",temp.pro_name);
            gotoxy(32,i);
            printf(" %d",temp.quantity);
            gotoxy(43,i);
            printf(" %s",temp.supp_name);
            gotoxy(60,i);
            printf(" %s",temp.exp_date);
            i++;
            break;
        }

    }
    if(strcmp(mid,temp.id)!=0)
    {
        gotoxy(20,20);
        printf("Not in Stock.....");
    }
    getch();
    system("cls");
    product();

}

void update_stock()
{
    char mid[6];
    FILE *ptr;
    int j,a,count=0,n;
    system("cls");
    ptr=fopen("store.txt","rb");
    if(ptr==NULL)
    {
        printf("\n\t Can not open File! ");
        product();
    }
    system("cls");
    box();
    gotoxy(20,45);
    printf("Press Enter to go to MENU ...........");
    gotoxy(27,8);
    printf(" UPDATE PRODUCT QUANTITY ");
    gotoxy(9,10);
    printf("Enter Product id to be update qty: ");
    scanf("%s",&mid);
    j=0;

    while((fread(&temp,sizeof(temp),1,ptr))==1)
    {
        if((strcmp(temp.id,mid)<0) || (strcmp(temp.id,mid)>0))
        {
            x[j] = temp;
            j++;
        }
        else
        {
            gotoxy(8,12);
            printf("Product Name     : %s",temp.pro_name);
            gotoxy(8,14);
            printf("Quantity in stock : %d",temp.quantity);
            gotoxy(8,16);
            printf("Quantity want to update : ");
            scanf("%d",&a);
            x[j]=temp;
            x[j].quantity=(x[j].quantity+a);
            x[j].total=(x[j].quantity*temp.sale);
            x[j].cost=(x[j].quantity*temp.unit);
            x[j].bye=(x[j].sale*a);
            x[j].qty=a;
            j++;
            count++;
        }
    }
    if (count==0)
    {
        system("cls");
        gotoxy(33,10);
        printf("Not in stock!!!!!!");
        getch();
        stock();
    }
    fclose(ptr);
    n = j;
    system("cls");
    ptr=fopen("store.txt","wb");
    for(i=0; i<n; i++)
        fwrite(&x[i],sizeof(x[i]),1,ptr);
    fclose(ptr);
}




void sale_rpt()
{
    char ch;
    FILE *ptrs_r;
    int j;
    system("cls");
    ptrs_r=fopen("saleRpt.txt","r");
    if(ptrs_r==NULL)
    {
        printf("\n\t Can not open File! ");

        report_menu();
    }
    system("cls");
    box();
    gotoxy(20,50);
    printf("Press any key to go to REPORT MENU ...........");
    lbox();
    gotoxy(30,8);
    printf("Sales Report");
    gotoxy(7,10);
    printf("ID. Product Name.  Customer Name.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.pro_id,s_r.pror_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
    {
        gotoxy(6,j);
        printf("%s",s_r.pro_id);
        gotoxy(11,j);
        printf("%s",s_r.pror_name);
        gotoxy(28,j);
        printf("%s",s_r.cust_name);
        gotoxy(44,j);
        printf("%d",s_r.qty);
        gotoxy(50,j);
        printf("%.2f",s_r.rate);
        gotoxy(57,j);
        printf("%.2f",s_r.total);
        gotoxy(65,j);
        printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
        j=j+2;
    }

    getch();
    system("cls");
    report_menu();






}

void pur_rpt()
{
    char ch;
    FILE *ptrs_r;
    struct tm * now ;
    time_t t = time(NULL);
    now= localtime( &t );

    int j;
    system("cls");

    box();
    ptrp_r=fopen("purreport.txt","r");
    if(ptrp_r==NULL)
    {
        printf("\n\t Can not open File! ");
        report_menu();
    }
    gotoxy(20,50);
    printf("Press Enter to go to REPORT MENU ...........");
    lbox();
    gotoxy(30,8);
    printf("Purchase Report");
    gotoxy(7,10);
    printf("ID. Product Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.pro_id,p_r.pror_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
    {
        gotoxy(6,j);
        printf("%s",p_r.pro_id);
        gotoxy(11,j);
        printf("%s",p_r.pror_name);
        gotoxy(28,j);
        printf("%s",p_r.supp_name);
        gotoxy(44,j);
        printf("%d",p_r.qty);
        gotoxy(50,j);
        printf("%.2f",p_r.rate);
        gotoxy(57,j);
        printf("%.2f",p_r.total);
        gotoxy(65,j);

        printf("%i-%i-%i ",now->tm_mday,now->tm_mon+1,now->tm_year+1900);

        j+=2;
    }
    getch();
    system("cls");
    report_menu();
}




void profit_rpt()
{
    char ch;
    FILE *ptrpr_r;
    int j;
    system("cls");
    t();
    box();
    ptrpr_r=fopen("profitRpt.txt","r");
    if(ptrpr_r==NULL)
    {
        printf("\n\t Can not open File! ");
        report_menu();
    }
    gotoxy(20,50);
    printf("Press Enter to go to REPORT MENU ...........");

    lbox();

    gotoxy(30,8);
    printf("Profit Report");
    gotoxy(7,10);
    printf("ID. Product Name.   Date        Qty.  Unit Price  Sale Price. Profit. ");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrpr_r," %s %s %d %d %d %d %f %f %f \n",pr_r.pro_id,pr_r.pror_name,&pr_r.sDay,&pr_r.sMonth,&pr_r.sYear,&pr_r.qty,&pr_r.unit,&pr_r.rate,&pr_r.profit)!=EOF)
    {
        gotoxy(6,j);

        printf("%s ",pr_r.pro_id);
        gotoxy(11,j);
        printf(" %s",pr_r.pror_name);
        gotoxy(28,j);
        printf("%d-%d-%d",pr_r.sDay,pr_r.sMonth,pr_r.sYear);
        gotoxy(40,j);
        printf("%d",pr_r.qty);
        gotoxy(48,j);
        printf("%.2f",pr_r.unit);
        gotoxy(60,j);
        printf("%.2f",pr_r.rate);
        gotoxy(70,j);
        printf("%.2f",pr_r.profit);
        gotoxy(10,j);
        printf("%c",124);
        j+=2;

    }
    getch();
    system("cls");
    report_menu();
}


void sale_rpt_daily()
{
    char ch;
    FILE *ptrs_r;
    int j,d,m,y;
    float total=0.00;
    system("cls");
    ptrs_r=fopen("saleRpt.txt","r");
    if(ptrs_r==NULL)
    {
        printf("\n\t Can not open File! ");
        report_menu();
    }
    system("cls");
    gotoxy(15,10);
    printf("Enter Date(dd-mm-yyyy):  ");
    scanf("%d-%d-%d",&d,&m,&y);
    system("cls");
    gotoxy(20,50);
    printf("Press any key to go to REPORT MENU ...........");
    box();
    lbox();
    gotoxy(30,8);
    printf("Sales Report Daily");
    gotoxy(7,10);
    printf("ID. Product Name.  Customer Name.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.pro_id,s_r.pror_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
    {
        if(d==s_r.sDay &&m== s_r.sMonth && y==s_r.sYear)
        {
            gotoxy(6,j);
            printf("%s",s_r.pro_id);
            gotoxy(11,j);
            printf("%s",s_r.pror_name);
            gotoxy(28,j);
            printf("%s",s_r.cust_name);
            gotoxy(44,j);
            printf("%d",s_r.qty);
            gotoxy(50,j);
            printf("%.2f",s_r.rate);
            gotoxy(57,j);
            printf("%.2f",s_r.total);
            gotoxy(65,j);
            printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
            j=j+2;
            total=total+s_r.total;
        }
    }
    gotoxy(7,42);
    printf("-------------------------------------------------------------------");
    gotoxy(45,43);
    printf("Total:        %.2f",total);
    getch();
    system("cls");
    report_menu();
     fclose(ptrs_r);
}
void pur_rpt_daily()
{
    char ch;
    FILE *ptrp_r;
    int j,d,m,y;
    float total=0.00;

    ptrp_r=fopen("purreport.txt","r");
    if(ptrp_r==NULL)
    {
        printf("\n\t Can not open File! ");

        report_menu();
    }
    system("cls");
    gotoxy(15,10);
    printf("Enter Date(dd-mm-yyyy):  ");
    scanf("%i-%i-%i",&d,&m,&y);
    system("cls");
    gotoxy(20,50);
    printf("Press Enter to go to REPORT MENU ...........");
    t();
    box();
    lbox();
    gotoxy(30,8);
    printf("Purchase Report Daily");
    gotoxy(7,10);
    printf("ID. Product Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.pro_id,p_r.pror_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
    {
        if(d==p_r.sDay &&m== p_r.sMonth && y==p_r.sYear)
        {
            gotoxy(6,j);
            printf("%s",p_r.pro_id);
            gotoxy(11,j);
            printf("%s",p_r.pror_name);
            gotoxy(28,j);
            printf("%s",p_r.supp_name);
            gotoxy(44,j);
            printf("%d",p_r.qty);
            gotoxy(50,j);
            printf("%.2f",p_r.rate);
            gotoxy(57,j);
            printf("%.2f",p_r.total);
            gotoxy(65,j);
            printf("%d-%d-%d",p_r.sDay,p_r.sMonth,p_r.sYear);
            j+=2;
            total=total+p_r.total;
        }
    }
    gotoxy(7,42);
    printf("-------------------------------------------------------------------");
    gotoxy(45,43);
    printf("Total:        %.2f",total);
    getch();
    system("cls");
    report_menu();
    fclose(ptrp_r);

}

//=============================================:) THE END :) =================================
