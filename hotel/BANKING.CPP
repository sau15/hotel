#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>
#include<fstream.h>
#include<math.h>
#include<ctype.h>
#include<dos.h>
#define line "\t-------------------------------------------------------------------"
ofstream f1;

struct logindata // please note the password : pfpss
{
char username[10];
char password[10];
};

void login()
{
	clrscr() ;
	char pass1, pass2, pass3, pass4, pass5 ;
	cout<<"Enter the password : " ;
	pass1=getch() ;
	cout<<"*" ;
	pass2=getch() ;
	cout<<"*" ;
	pass3=getch() ;
	cout<<"*" ;
	pass4=getch() ;
	cout<<"*" ;
	pass5=getch() ;
	cout<<"*" ;
	getch();
	if (pass1 == 'p' && pass2 == 'f' && pass3 == 'p' && pass4 == 's' && pass5 == 's')
	     {
	     return;

			     }
	clrscr();
	
	cout<<"   WRONG PASSWORD   " ;
	
	getch() ;
	exit(0) ;
}






struct Name
   {
    char first[10]  ,mid[10]  ,last[10];
   };

struct Address
   {
    int hno;
    char area[10]  ,city[10]  ,state[15];
   };

struct Date
  {
   int day  ,mon  ,year;
  };

struct roomno
  { 
    int rn;
    int avail;
  } r;

struct Hotel
  {
     int bno, rno;
     Name cna;
     Address addr;
     Date ci, co;
     char occu[25];
     int rt;
     int type;
     int n;
     char cf[25],gt[25];
     long bill;
 }H;

void avail()
       {
         f1.open("trial2",ios::binary|ios::out);
         for(int i=1;i<51;i++)        
           {
            r.rn=i;
            r.avail=0;
            f1.write((char*)&r,sizeof(r));
           }
         f1.close();

       }
void faci()
  {    
       cout<<"\n\n\n\n"<<line<<endl<<"\n\t\tFACILITIES:\n\n"
           <<line<<"\n\n\n\n";
       cout<<"\n\t\t1.BAR                           400/-\n"<<
             "\n\t\t2.RESTAURANT                    600/-\n"<<
             "\n\t\t3.SWIMMING POOL                 300/-\n"<<
             "\n\t\t4.HEALTH CLUB                   400/-\n"<<
             "\n\t\t5.COMMUNICATION FACILITIES      200/-\n"<<
             "\n\t\t6.TRANSPORT FACILITIES         5000/-\n"<<
             "\n\t\t7.TOURISM                      1500/-\n"<<
             "\n\n\n\t  Charges Are Calculated Per Day.\n\n"<<line;
  };  

void room()
  {   
      cout<<"\n\n\n\n"<<line<<endl<<"\t\tROOM TYPES:\n\n"
          <<line<<"\n\n\n\n";
      cout<<"\n\t\t1.SINGLE ROOM(1-10)                900/-\n"<<
            "\n\t\t2.DOUBLE ROOM(11-20)               1200/-\n"<<
            "\n\t\t3.SINGLE A.C.ROOM(21-30)           1500/-\n"<<
            "\n\t\t4.DOUBLE A.C.ROOM (31-40)          2000/-\n"<<
            "\n\t\t5.PRESIDENT SUIT(41-50)            4500/-\n"<<
            "\n\n\n\t  Charges Are Calculated Per Day.\n\n"<<line;
  };




void book()
  {  
    clrscr();  
    getch();
    int q;
    int c,x; 
    c=x=0;

    fstream f;

    f.open("trial2",ios::in| ios::out| ios::binary);
    if(!f)
        { 
          cout<<"^Cannot open file !!";
	  return;
	}

    f.seekg(0,ios::beg);
    int a[5]={0,0,0,0,0};
    while(f.read((char*)&r,sizeof(r)))
	{
	  if(r.avail==1)
	    { 
              if(H.rt==1)
                {
                  if(r.rn>0&&r.rn<11)
	            {
                      cout<<"Room no."<<r.rn<<" Already booked";
                      a[0]=1;
	              cout<<"\n";
                    }
                   
                }
             else if(H.rt==2)
                {
                  if(r.rn>10&&r.rn<21)
	            {
                      cout<<"Room no."<<r.rn<<" Already booked";
                      a[1]=1;
	              cout<<"\n";
                    }
                   
                }
              else if(H.rt==3)
                {
                  if(r.rn>20&&r.rn<31)
	            {
                      cout<<"Room no."<<r.rn<<" Already booked";
                      a[2]=1;
	              cout<<"\n";
                    }
                   
                }
               else if(H.rt==4)
                {
                  if(r.rn>30&&r.rn<41)
	            {
                      cout<<"Room no."<<r.rn<<" Already booked";
                      a[3]=1;
	              cout<<"\n";
                    }
                  
                }
              else if(H.rt==5)
                {
                  if(r.rn>40&&r.rn<51)
	            {
                      cout<<"Room no."<<r.rn<<" Already booked";
                      a[4]=1;
	              cout<<"\n";
                    }
                  
                }
              
              
              
	    }
	  
	};
   
        if(a[0]==0  &&  H.rt==1)
        cout<<"All rooms available of type 1\n";

        else if(a[1]==0  &&  H.rt==2)
        cout<<"All rooms available of type 2\n";      

        else if(a[2]==0  &&  H.rt==3)
        cout<<"All rooms available of type 3\n";

        else if(a[3]==0  &&  H.rt==4)
        cout<<"All rooms available of type 4\n";    

        else if(a[4]==0  &&  H.rt==5)
        cout<<"All rooms available of type 5\n";
f.close();

    f.open("trial2",ios::in| ios::out| ios::binary);
    if(!f)
       {
	 cout<<"&Cannot open file !!";
	 return;
       }
   top:
   cout<<"\n\n\t\tEnter the room number(1-50)\t";
   cin>>q;
   f.seekg(0,ios::beg);

   while(f.read((char*)&r,sizeof(r)))
      {
	x++;
	if(q==r.rn && r.avail!=1)
	   { 
             if(q>0&&q<11  &&  H.rt==1)  
               {
                 cout<<"ROOM BOOKED";
	         r.avail=1;
	         c=9;

       	         f.seekp((x-1)*sizeof(r),ios::beg);
	         f.write((char*)&r,sizeof(r));
	         break;
               }
             else if(q>10&&q<21  &&  H.rt==2)  
               {
                 cout<<"ROOM BOOKED";
	         r.avail=1;
	         c=9;

       	         f.seekp((x-1)*sizeof(r),ios::beg);
	         f.write((char*)&r,sizeof(r));
	         break;
               }
             
             else if(q>20&&q<31  &&  H.rt==3)  
               {
                 cout<<"ROOM BOOKED";
	         r.avail=1;
	         c=9;
       	         f.seekp((x-1)*sizeof(r),ios::beg);
	         f.write((char*)&r,sizeof(r));
	         break;
               }
             else if(q>30&&q<41  &&  H.rt==4)  
               {
                 cout<<"ROOM BOOKED";
	         r.avail=1;
	         c=9;

       	         f.seekp((x-1)*sizeof(r),ios::beg);
	         f.write((char*)&r,sizeof(r));
	         break;
               }
             else if(q>40&&q<51  &&  H.rt==5)  
               {
                 cout<<"ROOM BOOKED";
	         r.avail=1;
	         c=9;

       	         f.seekp((x-1)*sizeof(r),ios::beg);
	         f.write((char*)&r,sizeof(r));
	         break;
               }
             
	   }
       }
      if(c!=9)
      { 
        cout<<"invalid";
        goto top;
      };

   
   
    f.close(); 
    H.rno=q;
  }

void report()
 {  
     clrscr(); 
     fstream f;
     f.open("trial2",ios::in| ios::out| ios::binary);
     if(!f)
     { 
       cout<<"CANNOT OPEN FILE !!";
       return ;
     }

     cout<<line<<"\n\n\n\tROOM REPORT:-\n\n";
     f.seekg(0,ios::beg);
	int a=0;
     while(f.read((char*)&r,sizeof(r)))
     {   
         if(r.avail==1)
	    {
	      cout<<"Room no."<<r.rn<<" Already booked";
              a=1;
	      cout<<"\n";
	    }
	  
         
     };
     if(a==0)
     cout<<"All rooms available\n";
     cout<<endl<<endl<<line;
     f.close();
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t HOTEL PARADISE";
 }

void booking()
 {
    clrscr();

    cout<<"\n\n\t ENTER BOOKING NUMBER:-  ";
    cin>>H.bno;

    cout<<"\n\t ENTER FIRST NAME:-        ";
    cin>>H.cna.first;
    cout<<"\n\t ENTER MID NAME:-          ";
    cin>>H.cna.mid;
    cout<<"\n\t ENTER LAST NAME:-         ";
    cin>>H.cna.last;

    cout<<"\n\t     -:ADDRESS:-           ";cout<<endl;
    cout<<"\n\t ENTER HNo.:-              ";
    cin>>H.addr.hno;
    cout<<"\n\t ENTER Area:-              ";
    cin>>H.addr.area;
    cout<<"\n\t ENTER City:-              ";
    cin>>H.addr.city;
    cout<<"\n\t ENTER State:-             ";
    cin>>H.addr.state;

    cout<<"\n\t   -:ENTER THE DATE OF CHECKIN:-   ";cout<<endl;
    cout<<"\n\t DAY:-                     ";
    cin>>H.ci.day;
    cout<<"\n\t MONTH:-                   ";
    cin>>H.ci.mon;
    cout<<"\n\t YEAR:-                    ";
    cin>>H.ci.year;

    cout<<"\n\t   -:ENTER THE DATE OF CHECKOUT:-  ";cout<<endl;
    cout<<"\n\t DAY:-                     ";
    cin>>H.co.day;
    cout<<"\n\t MONTH:-                   ";
    cin>>H.co.mon;
    cout<<"\n\t YEAR:-                    ";
    cin>>H.co.year;

  H.n=H.co.day-H.ci.day;

  cout<<"\n\t ENTER OCCUPATION:-          ";
  cin>>H.occu;

  cout<<"\n\t CUSTOMER COMING FROM:-      ";
  cin>>H.cf;
  cout<<"\n\t CUSTOMER GOING TO:-         ";
  cin>>H.gt;
  clrscr();

  top:
  cout<<"\n\n\tCHOOSE & ENTER NUMBER OF ROOM TYPE:-\n\n\t    ";
  room();
  cin>>H.rt;


    switch(H.rt)
    {
     case 1:  
       H.type='1';
       H.bill=2000+900*H.n;
       break;
     case 2:   
       H.type='2';
       H.bill=2000+1200*H.n;
       break;
     case 3:
       H.type='3';
       H.bill=2000+1500*H.n;
       break;
     case 4:
       H.type='4';
       H.bill=2000+2000*H.n;
       break;
     case 5: 
       H.type='5';
       H.bill=2000+4500*H.n;
       break;
     default: {
               cout<<"\n\n\t\tINVALID CHOICE!"<<
               "\n\tENTER AGAIN.....\n\n\t";
               goto top;
              }
    }


  book();
  getch();
 }

void type()
 {  
    switch(H.rt)
    {
      case 1:
        H.type='1';
        cout<<"SINGLE"; 
        break;
      case 2:
	H.type='2';
	cout<<"DOUBLE";
	break;
      case 3:
	H.type='3';
	cout<<"A.C.SINGLE";
	break;
      case 4:
	H.type='4';
	cout<<"A.C.DOUBLE";
	break;
      case 5:
	H.type='5';
	cout<<"PRESIDENT SUIT";
	break;
    }
 }

void display()
 {
    fstream fio;
    fio.open("trial",ios::in|  ios::out|  ios::binary);
    if(!fio)
       cout<<"SORRY! *CANNOT OPEN FILE.....";
    clrscr();
    fio.seekg(0,ios::beg);
    while(!fio.eof())
     {
       fio.read((char*)&H,sizeof(H));
       clrscr();
       cout<<endl<<endl<<endl<<line
	   <<"\n\n\t\tBNO:         "<<H.bno
	   <<"\n\n\t\tRNO:         "<<H.rno
	   <<"\n\n\t\tROOM TYPE:   ";
       type();
       cout<<"\n\n\t\tNAME:        "<<H.cna.first<<" "<<H.cna.mid<<" "
	   <<H.cna.last<<" "
	   <<"\n\n\t\tADDRESS:     "<<H.addr.hno<<","<<H.addr.area<<","
	   <<H.addr.city<<","<<H.addr.state<<"."
	   <<"\n\n\t\tOCCUPATION:  "<<H.occu
	   <<"\n\n\t\tCHECK IN:    "<<H.ci.day<<"/"<<H.ci.mon<<"/"<<H.ci.year
	   <<"\n\n\t\tCHECK OUT:   "<<H.co.day<<"/"<<H.co.mon<<"/"<<H.co.year
	   <<"\n\n\t\tBILL:         "<<H.bill
	   <<"\n\n\t\tCOMING FROM: "<<H.cf
	   <<"\n\n\t\tGOING TO:    "<<H.gt<<endl;
      cout<<endl<<line;
      getch();
    }
   fio.close();
   fio.clear();
 }

void add()
 {
   char ans;
   fstream fio;
   fio.open("trial",ios::in|  ios::out|  ios::binary);
   if(!fio)
     cout<<"SORRY! @CANNOT OPEN FILE.....";
   clrscr();
   fio.seekp(0,ios::end);
   do
   {
      booking();
      fio.write((char*)&H,sizeof(H));
      cout<<"WANT YOU TO ADD MORE ? (Y/N)...";
      cin>>ans;
   }
   while(toupper(ans)=='Y');
   fio.close();
 }

void modify()
 {
     int e,r=0;

     fstream fio;
     fio.open("trial",ios::in|  ios::out|  ios::binary);
     if(!fio)
       cout<<"SORRY! #CANNOT OPEN FILE.....";
     fio.seekg(0,ios::beg);
     cout<<"\t ENTER BOOKING NUMBER:  "; cin>>e;
     while(fio.read((char*)&H,sizeof(H)))
     {
	r++;
	if(e==H.bno)
	{
	  clrscr();
	  cout<<"\nCUSTOMER DETAILS ARE AS FOLLOWS:\n";
	  cout<<endl<<endl<<endl<<line
	       <<"\n\n\t\tBNO:         "<<H.bno
	       <<"\n\n\t\tRNO:         "<<H.rno
	       <<"\n\n\t\tROOM TYPE:    ";
	       type();
	   cout<<"\n\n\t\tNAME:        "<<H.cna.first<<" "<<H.cna.mid<<" "
	       <<H.cna.last<<" "
	       <<"\n\n\t\tADDRESS:     "<<H.addr.hno<<","<<H.addr.area<<","
	       <<H.addr.city<<","<<H.addr.state
	       <<"\n\n\t\tOCCUPATION:  "<<H.occu
	       <<"\n\n\t\tCHECK IN:    "<<H.ci.day<<"/"<<H.ci.mon<<"/"<<H.ci.year
	       <<"\n\n\t\tCHECK OUT:   "<<H.co.day<<"/"<<H.co.mon<<"/"<<H.co.year
	       <<"\n\n\t\tCOMING FROM: "<<H.cf
	       <<"\n\n\t\tGOING TO:    "<<H.gt
	       <<"\n\n\tBILL:         "<<H.bill<<endl;
	   getch();


	   cout<<endl<<line;
	   cout<<"\nENTER NEW DETAILS:\n";
	   booking();
	   fio.seekg((r-1)*sizeof(H),ios::beg);
	   fio.write((char*)&H,sizeof(H));
	   break;
	}
     }

    fio.close();

 }


void bill()
 {
    int e,r=0;
    fstream fio;
    fio.open("trial",ios::in|  ios::out|  ios::binary);
    if(!fio)
       cout<<"SORRY! $CANNOT OPEN FILE.....";
    fio.seekg(0,ios::beg);
       cout<<"\t ENTER BOOKING NUMBER:  "; cin>>e;
    while(fio.read((char*)&H,sizeof(H)))
    {
     r++;
     if(e==H.bno)
      {
	clrscr();
//	cout<<"\n  CUSTOMERS DETAILS ARE AS FOLLOW:-\n";
//	cout<<"\n\t\t\t\t$$$$";

//	cout<<"\n\n\t\tRNO:           "<<H.rno
//	    <<"\n\n\t\tROOM TYPE:     ";
//	type();
	cout<<"\n\n\t\tNAME:          "<<H.cna.first<<" "<<H.cna.mid<<" "
	    <<H.cna.last<<" "
//	    <<"\n\n\t\tADDRESS:       "<<H.addr.hno<<","<<H.addr.area<<","
//	    <<H.addr.city<<","<<H.addr.state<<"."
//	    <<"\n\n\t\tOCCUPATION:    "<<H.occu
	    <<"\n\t\tCHECK IN:      "<<H.ci.day<<"/"<<H.ci.mon<<"/"<<H.ci.year
	    <<"\n\t\tCHECK OUT:     "<<H.co.day<<"/"<<H.co.mon<<"/"<<H.co.year
//	    <<"\n\n\t\tCOMING FROM:   "<<H.cf
//	    <<"\n\n\t\tGOING TO:      "<<H.gt
	    <<"\n\t\tDURATION:      "<<H.n<<" days";
//	cout<<endl<<"\n\t\t\t\t$$$$";

	cout<<"\n\tBILL:-         "<<endl;
	cout<<"\n\n\n\tFOOD CHARGES                   1450/-";

       switch(H.rt)
	{
	  case 1:
	    H.type='1';
	    cout<<"\n\tROOM CHARGES             900*"<<H.n<<"="<<H.n*900<<"/-";break;
	  case 2:
	    H.type='2';
	    cout<<"\n\tROOM CHARGES             1200*"<<H.n<<"="<<H.n*1200<<"/-";break;
	  case 3:
	    H.type='3';
	    cout<<"\n\tROOM CHARGES             1500*"<<H.n<<"="<<H.n*1200<<"/-";break;
	  case 4:
	    H.type='4';
	    cout<<"\n\tROOM CHARGES             2000*"<<H.n<<"="<<H.n*2000<<"/-";break;
	  case 5:
	    H.type='5';
	    cout<<"\n\tROOM CHARGES             4500*"<<H.n<<"="<<H.n*4500<<"/-";break;
	}
       cout<<"\n\tOTHER FACILITIES                450/-"
	   <<"\n\tTAX                             100/-\n"<<line
	   <<"\n\tTOTAL TO BE PAID -              "<<H.bill<<"/-\n" <<line;
       cout<<"\n\t\t\tAll Charges Are Calculated Per Day ";
       cout<<"\n\t\t\t\t HOTEL PARADISE";

       getch();
      }

    }

  fio.close();
}


void main()
 {
   clrscr();
 
   avail();
   int ch;
 cout<<"\n--------------------------------------------------------------------------------";
	   cout<<"\n--------------------------------------------------------------------------------";
	   cout<<"\n******************** WELCOME TO HOTEL MANAGEMENT SYSTEM ************************";
	   cout<<"\n--------------------------------------------------------------------------------";
	   cout<<"\n";
	   cout<<"Submitted By:";
	   
	   cout<<"Palash, Fevin, Parth, Saurab, Swaminathan";
  login();

   do
   {
     clrscr();

     cout<<"WELCOME TO HOTEL PARADISE";
     cout<<"\n\n"<<line<<endl<<line;

     cout<<"\n\n\t\t\t\t";
     cout<<"\n\n\n"<<
           "\t\t\t\tMENU:\n"<<
           "\n\n\t\t\t1.CHECK-IN:"<<
           "\n\n\t\t\t2.FACILITIES:"<<
           "\n\n\t\t\t3.ROOM-TYPES & CHARGES:"<<
           "\n\n\t\t\t4.CUSTOMER INFORMATION:"<<
           "\n\n\t\t\t5.CHECK-OUT:"<<
           "\n\n\t\t\t6.REPORT:"<<
           "\n\n\t\t\t0.EXIT:"<<
           "\n\n\n\t\t\t\t....\n\n\n"<<
           "\n\n\t\t\tENTER YOUR CHOICE.....";
     cin>>ch;

    switch(ch) 
    {

       case 1:  
         fstream fio;
         fio.open("trial",ios::in|  ios::out|  ios::binary);
	 if(!fio)
	       cout<<"SORRY! %CANNOT OPEN FILE.....";

         fio.seekp(0,ios::end);

        char ans='Y';
        while(toupper(ans)=='Y')
          { 
            booking();
            fio.write((char*)&H,sizeof(H));
            cout<<"WANT YOU TO ADD MORE ? (Y/N)...";
	    cin>>ans;
          }
       fio.close();
       getch();
       break;

      case 2:
	clrscr();
	faci();
	getch();
	break;

      case 3:
	clrscr();
	room();
	getch();
	break;

      case 4:
	int z;
	do
	{
	  clrscr();
	  cout<<"\n\n\n\n"<<line;

	  cout<<"\n\n\t\tCUSTOMER INFORMATION:\n\n"
	      <<line<<"\n\n\n\n\t\t\t\t...."
	      <<"\n\n\n\t\t\tWHAT YOU WANT YOU TO DO ?\n"
	      <<"\n\n\n\t\t\t1.ADD RECORD:\n\n\t\t\t2.MODIFY RECORD:"
	      <<"\n\n\t\t\t3.DISPLAY RECORD:\n\n\t\t\t0.EXIT:\n\n\n"
	      <<"\t\t\t\t....\n\n\n\t\t\t  YOUR CHOICE.....";
	  cin>>z;

	  if(z==1)
	   {
	     add();
	   }
	  if(z==2)
	  {
	     modify();
	  }
	  if(z==3)
	  {
	     display();
	  }
       }while(z!=0);

       getch();
       break;

     case 5:
       do
       {
	 clrscr();
	 cout<<"\n\n\n\n"<<line;
	 cout<<"\n\n\t\tCUSTOMER CHECK-OUT:\n\n"
	     <<line<<"\n\n\n\n\t\t\t\t...."
	     <<"\n\n\n\t\t\tWHAT YOU WANT YOU TO DO ?\n"
	     <<"\n\n\n\t\t\t1.DISPLAY RECORD & BILL:\n\n\t\t\t2.REPLACE RECORD:"
	     <<"\n\n\t\t\t0.EXIT:\n\n\n"
	     <<"\t\t\t\t....\n\n\n\t\t\t  YOUR CHOICE.....";
	 cin>>z;

	 if(z==1)
	   {
	     bill()  ;
	   }
	 if(z==2)
	   {
	     modify();
	   }
       }while(z!=0);
       getch();
       break;

     case 6:
       report();
       getch();
       break;

     case 0:
       exit(0);
       break;

     default:
       cout<<"\nENTER THE RIGHT CHOICE.....";
       getch();
       break;

    }
  }while(ch!=0);
getch();
}





