#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void rem();
void modify();
int check(int no);
void password();
void Employee_menu();
void add();
 void Pizza_menu();
   int flag=0;
   	struct Pizza
{
   int sno;
   char name[21];
   float sp,mp,lp;
};
struct Cust{
	char name[30];
long long int phno;
}cu;
long long int cu_ph;	char cu_name[30];
COORD coord = {0,0};
long int item;
struct Bill
{
	int sno;
	char name[30];
	long long int phno;
	int psno;
	char pname[21];
	char size;
	int qty;
	float price;
	float gtot;
	int day,mon,year,min,sec,hr;
}bill;
int main() {

login();
getch();
return 0;
}
void login()
{
	char ch;
	printf("*******************************************************************************\n");
printf("\t\t\t\t  _____________\n\n");
 printf("\t\t\t\t  | Pizzadice |\n");
 printf("\t\t\t\t  _____________");
	printf("\n\nHow do you want to Login?\n1 Customer\n2 Employee\n");	
    	 ch=getchar();
	 while(isspace(ch)!=0){
				ch=getchar();
		}
//Asking user its login option
	 switch(ch)
	 {
		case '1':
			cust_login();
		break;	
	    case '2':
	    	printf("Enter your password\nPassword is 1234\n");
       fflush(stdin);// IT IS A METHOD THAT REMOVES EXTRA CHARCTERS
		              // THAT THE USER MAY HAVE INPUTTED
	 flag=0;
     password();
		break;
		default:
			printf("Please make a correct choice\n");
			Sleep(1000);
			fflush(stdin);
		    system("cls");
            login();
	}
	}
	
void password(){
		int i=0;
		char pass[11]=" ";
		char in;
 while(i<10)
{
in=getch();
if(!(in==8 || in==13))
{
printf("*");
pass[i]=in;
i++;
}
else
if(in==8 && i>0 )
{
printf("\b");
printf(" ");
printf("\b");
i--;
}
else
if(in==13)
break;
   }			 
			 if(strcmp(pass,"1234")==0)//method to compare password
			 {					 
			fflush(stdin);
		system("cls");
		Employee_menu();
		}
			  else{
		if(flag<2){
			  printf("\nPassword incorrect.Try again\n");
			  flag++;
			  	fflush(stdin);
			  password();
		}
		else
		{
		printf("\n3 attempts failed.\n Access Denied");
	Sleep(2000);
		fflush(stdin);
		 system("cls");
		 login();	
		}
		}
	} 
	
	void Employee_menu()
	{
	 fflush(stdin);
	 system("cls");
		char ch;
		printf("What would you like to do?\n1.View a La Carte\n2.Add more choices \n3.Modify the Menu\n4.Return to login page\n");
      scanf("%c",&ch);
		while(isspace(ch)!=0){
				ch=getchar();
		}
		switch(ch)
		{
				case '1':
			  Pizza_menu();
		break;	
	    case '2':
	    	fflush(stdin);
	    	system("cls");
	    	char c;
	    	printf("Wanna add a new pizza?(Y/N)\n");
		fflush(stdin);
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
			system("cls");//Method to clear console
			fflush(stdin);
		if(c=='Y'||c=='y')
		{
			add();
        }
		else
		Employee_menu();
		break;
		case '3':
			fflush(stdin);
	    	system("cls");
			modify();
			break;
		case '4':
			system("cls");
			fflush(stdin);
			login();
			break;
		default:
	       printf("Please make a correct choice\n");
			Sleep(1000);
			fflush(stdin);
		    system("cls");
		    Employee_menu();
		    }
	}
	
	void add()
	{
	fflush(stdin);
   struct Pizza p;
   FILE *fptr;
   if ((fptr = fopen("pizza.bin","ab+")) == NULL){
       printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
 char ch;
  printf("\t\t\t_____________\n\n");
 printf("\t\t\t| Pizzadice |\n");
 printf("\t\t\t_____________\n");
 if(fseek(fptr,-sizeof(struct Pizza),SEEK_END)!=0)
 {
 	p.sno=0;
 }
    fread(&p.sno, sizeof(int), 1, fptr);
	 fseek(fptr,0,SEEK_END);
	 p.sno++;
 printf("Enter Pizza Details................\n");
   fflush(stdin);
   printf("Name :\n");
   while("%d",scanf("%[^\n]%*c",p.name)==0)
   {
   	fflush(stdin);
	      }
 printf("Enter price .......................\n");
 printf("Small :\n");
   while((scanf("%f%c",&p.sp,&ch) !=2 || ch!='\n')|| p.sp<=0.00)
   {
  printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
   fflush(stdin);
   printf("Medium : \n");
  while((scanf("%f%c",&p.mp,&ch) !=2 || ch!='\n')|| p.mp<=0.00)//scanf returns the number of arguments sucessfully read;
   {
   printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
   fflush(stdin);
      printf("Large :\n");
while((scanf("%f%c",&p.lp,&ch) !=2 || ch!='\n')|| p.lp<=0.00)
   {
   printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
   fflush(stdin);
      fwrite(&p, sizeof(struct Pizza), 1, fptr); 
   fclose(fptr); 
		printf("Pizza added sucessfullly.\n");
		printf("Add another?(Y/N)\n");
		fflush(stdin);
		while((ch=getche())!='Y'&& ch!='N'&& ch!='y'&& ch!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(ch=='Y'||ch=='y')
		{
			add();
        }
		else
		Employee_menu();	
	}
	void Pizza_menu()
	{
	menu();
   printf("\n\n\nPress any key to return to main menu");
   getch();
   system("cls");
   Employee_menu();	
	     }
	     
void del()
{
	fflush(stdin);
      system("cls");
      menu();
	int sno; char ch;
	printf("Enter S.No of pizza you would like to delete :\n");
	while((scanf("%d%c",&sno,&ch) !=2 || ch!='\n')|| sno<=0)
   {
   printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
int n=	check(sno);
if( n==1){
	struct Pizza p;
	FILE *f1,*f2; 
	f1=fopen("pizza.bin","rb");
	f2=fopen("vas.bin","wb");
	if(f1==NULL||f2==NULL)
	{
	printf("Error opening file!");
	exit(1);
}
 fseek(f1,0,SEEK_END);
 int pos=ftell(f1);
 rewind(f1);	
 while(ftell(f1)!=pos)
 {
 	fread(&p,sizeof(struct Pizza),1,f1);	
 		if(p.sno!=sno)
 		{
 			if(p.sno>sno)
 			p.sno--;
   int g= fwrite(&p,sizeof(struct Pizza),1,f2);
 	if(g==0)
 	printf("Cannot write items");
 }
 }
 fclose(f1);
 	fclose(f2);	
 	 rem();
 }
 else
 if(n==0)
 {
 	printf("OOps,Record not found\n");
 	Sleep(1700);
 	del();
 }
 else
 {
 	fflush(stdin);
 	system("cls");
 	printf("Try adding some records first\n");
 	Sleep(1500);
 	Employee_menu();
 }
 printf("Pizza deleted sucessfullly.\n");
		printf("Delete another?(Y/N)\n");
		fflush(stdin);
		while((ch=getche())!='Y'&& ch!='N'&& ch!='y'&& ch!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(ch=='Y'||ch=='y')
		{
			del();
        }
		else
		Employee_menu();
}

int check(int no) 
{
	struct Pizza p; int n=0;
	   FILE *fptr;
   if ((fptr = fopen("pizza.bin","rb")) == NULL){
       printf("No items found.\n");
       Sleep(1500);
       exit(1);
   }
  fseek(fptr,0,SEEK_END);
  int pos=ftell(fptr);
  if(pos==0)
  {
  	n=2;
  }
  rewind(fptr);
   while(ftell(fptr)!=pos)
   {
      fread(&p, sizeof(struct Pizza), 1, fptr); 
      if(p.sno==no)
      {	 
	n=1;
	break;
	}
 }
 fclose(fptr);
 return n;                           
}

void rem()//function to remove and rename
{
	char newname[]="pizza.bin",oldname[]="vas.bin";
 	 int mn=remove(newname),nm=rename(oldname,newname);
 	if(mn!=0)
    printf("\n Not DELETED");
    if(nm!=0)
    printf(" NOT RENAMED");
}

void modify(){
	system("cls");
	fflush(stdin);
	printf("Choose your option\n1.Modify Prices\n2.Delete Pizza\n3.Return to main Menu\n");
	 char ch=getchar();
	  while(isspace(ch)!=0){
				ch=getchar();			
		}
		//accepting user input
    	char c;
	 switch(ch){
		case '1':	
			system("cls");
       fflush(stdin);
   	fflush(stdin);
	    	system("cls");
	    	printf("Wanna change price?(Y/N)\n");
		fflush(stdin);
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(c=='Y'||c=='y')
		{
			edit();
        }
		else
		modify();
		break;	
	    case '2':
	    	system("cls");
       fflush(stdin);
   	fflush(stdin);
	    	system("cls");
	    	printf("Sure you want to delete?(Y/N)\n");
		fflush(stdin);
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(c=='Y'||c=='y')
		{
			del();
        }
		else
		modify();
		break;
		case '3':
	system("cls");
       fflush(stdin);
			Employee_menu();
			break;
		default:
			printf("Please make a correct choice\n");
			Sleep(1000);
			fflush(stdin);
		    system("cls");
            modify();
}
}
void menu()
{
		fflush(stdin);
		system("cls");
			struct Pizza p;
   FILE *fptr;
   if ((fptr = fopen("pizza.bin","rb")) == NULL){
       printf("No items available in the menu.\n");
  Sleep(1500);
       system("cls");
       fflush(stdin);
       login();
   }
  fseek(fptr,0,SEEK_END);
  int pos=ftell(fptr);
  rewind(fptr);
   printf("\t\t\t\t  _____________\n\n");
 printf("\t\t\t\t  | Pizzadice |\n");
 printf("\t\t\t\t  _____________\n\n");
	    printf("  S.No\t\t   Pizza Name\t\t\t      Price\n");
	    printf("\t\t\t\t      small\t     medium\t      large\n\n\n");
   while(ftell(fptr)!=pos)
   {
      fread(&p, sizeof(struct Pizza), 1, fptr); 
     printf(" %3d\t %20s\t %10.2f\t %10.2f\t %10.2f\n", p.sno, p.name, p.sp,p.mp,p.lp);
   }
   fclose(fptr); 
}
void edit()
{
	fflush(stdin);
      system("cls");
      menu();
	int sno; char ch;
	printf("Enter S.No of pizza you would like to change price of :\n");
	while((scanf("%d%c",&sno,&ch) !=2 || ch!='\n')|| sno<=0)
   {
   printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
int n=	check(sno);
if( n==1){
FILE *f1,*f2; 
	f1=fopen("pizza.bin","rb");
	f2=fopen("vas.bin","wb");
	struct Pizza p;
	if(f1==NULL||f2==NULL)
	{
	printf("Error opening file!");
	exit(1);
}
 fseek(f1,0,SEEK_END);
 int pos=ftell(f1);
 rewind(f1);	
 while(ftell(f1)!=pos)
 {
 	fread(&p,sizeof(struct Pizza),1,f1);
if(p.sno==sno)
{
	printf("Enter the updated price of pizza--->\n");
 printf("Small :\n");
   while((scanf("%f%c",&p.sp,&ch) !=2 || ch!='\n')|| p.sp<=0.00)
   {
  printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
   fflush(stdin);
   printf("Medium : \n");
  while((scanf("%f%c",&p.mp,&ch) !=2 || ch!='\n')|| p.mp<=0.00)//scanf returns the number of arguments sucessfully read;
   {
   printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
   fflush(stdin);
      printf("Large :\n");
while((scanf("%f%c",&p.lp,&ch) !=2 || ch!='\n')|| p.lp<=0.00)
   {
   printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
   fflush(stdin);
}
 int g= fwrite(&p,sizeof(struct Pizza),1,f2);
 	if(g==0)
 	printf("Cannot write items");
 }
 fclose(f1);
 	fclose(f2);	
 	 rem();
 }
 else
 if(n==0)
 {
 	printf("OOps,Record not found\n");
 	Sleep(1000);
 	edit();
 }
 else
 {
 	fflush(stdin);
 	system("cls");
 	printf("Try adding some records first\n");
 	Sleep(1500);
 	Employee_menu();
 }
 printf("Price changed sucessfullly.\n");
		printf("Update another price?(Y/N)\n");
		fflush(stdin);		
		while((ch=getche())!='Y'&& ch!='N'&& ch!='y'&& ch!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(ch=='Y'||ch=='y')
		{
			edit();
        }
		else
		Employee_menu();
}

int check_p( long long int no)
{
	FILE *fp;int n=0;
	fp=fopen("Customer.bin","rb");
	if(fp==NULL)
	{
		printf("Creating new file....");
		FILE *f1=fopen("Customer.bin","ab");
		fclose(f1);
	}
	fseek(fp,0,SEEK_END);
	int pos=ftell(fp);
	rewind(fp);
	while(ftell(fp)!=pos)
	{
		fread(&cu,sizeof(struct Cust),1,fp);		
		if(cu.phno==no)
		{
			strcpy(cu_name,cu.name);
		n=1;
		break;
		}
	}
	return n;
	fclose(fp);
}
void add_c()
{
	FILE *fp;
	char ch;
	fp=fopen("Customer.bin","ab");
	if(fp==NULL)
	{
		printf("File not found");
	}
			 fflush(stdin);
   printf("Your name Ms\\Mr :\n");
   while("%d",scanf("%[^\n]%*c",cu_name)==0)
   {
   	fflush(stdin);
	      }
   strcpy(cu.name,cu_name);
 cu.phno=cu_ph;
   fflush(stdin);
	fwrite(&cu,sizeof( struct Cust),1,fp);
	fclose(fp);
fflush(stdin);
system("cls");
printf("Welcome to the Pizza Paradice.....");
cust_menu();
}

void cust_login()
{
	char ch;
printf("Enter you mobile number here :\n");
while((scanf("%lld%c",&cu_ph,&ch) !=2 || ch!='\n')|| cu_ph<=0)
   {
  printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
  int n= check_p(cu_ph);
  if(n==0)
  add_c();
  else
  {
     fflush(stdin);
     system("cls");
    cust_menu();
    }
}
void cust_menu()
{
	//please do not use system("cls") at the beginnig.
	remove("temp_bill.bin");	
	printf("\nHey %s, What would you like to do today?\n1.View a La Carte\n2.Order now\n3.Check out your order history\n4.Return to login page\n",cu_name);
		char ch;char c;
		ch=getche();
		while(isspace(ch)!=0){
				ch=getche();
		}
	 switch(ch)
		{
				case '1':
			  menu();
			  printf("Press any key to return to main menu\n");
			  getch();
			  fflush(stdin);
			  system("cls");
			  cust_menu();
		break;	
	    case '2':
	    	printf("\nWould you like to order now(Y/N)?\n");
		while(isspace(c)!=0||c=='\n'){
				c=getche();
		}
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(c=='Y'||c=='y')
		{
			 fflush(stdin);
			  system("cls");
			input();
        }
		else 
		{
	fflush(stdin);
			  system("cls");
		cust_menu();
			}
		break;
		case '3':
			system("cls");
			fflush(stdin);
			d_bill();
			break;
		case '4':
			system("cls");
			fflush(stdin);
			login();
			break;
		default:
	       printf("Please make a correct choice\n");
			Sleep(1000);
			fflush(stdin);
		    system("cls");
		    cust_menu();
		}
}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void input()
{
	FILE *fp;
	cust_pizzamenu();
	gotoxy(0,9);
	printf("                                                                             ");
    int sno,qty;char size;
    gotoxy(0,1);
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t       Pizzas' in cart :%ld",item);
    printf("\n");
    printf("Enter details to add to cart :");    	
    gotoxy(0,8);
    printf("S.no    Size(s/m/l)    Qty\n");
     gotoxy(0,9);
     char c;
     fflush(stdin);
     int n,i;
    while((scanf("%d%c",&sno,&c))!=2 || c!='\n'||sno<0|| (n=check(sno))==0)
    {
    	printf("\nPlease make a correct choice");
    	Sleep(500);	
	    printf("\r                                  ");
    	gotoxy(0,9);
    	printf("                                                                        ");
    	   for( i=0;i<20;i++)
    	   {
    	   	printf("\n                                  ");
		   }
		   fflush(stdin);
		    gotoxy(1,1);
			gotoxy(0,9);
	if(n==2)
	{
		printf("\n No items exists in menu");
		//take to customer menu page
	}
}
    gotoxy(8,9);
    fflush(stdin);
    SIZE: size=getchar();
    switch(size)
    {
    case 's':
    case 'S':
    break;
    case 'm':
    case 'M':
	break;
	case 'l':
	case 'L':
	break;
	default: 
		printf("\nPlease make a correct choice");
			Sleep(500);
			printf("\r                             ");
			fflush(stdin);
			 gotoxy(8,9);
			 printf("                                                                    ");
			 gotoxy(8,9);	
			 goto SIZE;
	}
    fflush(stdin);
    gotoxy(23,9);
     while((scanf("%d%c",&qty,&c))!=2 || c!='\n' || qty<=0||qty>500)
    {
    	printf("\nPlease make a correct choice");
    	Sleep(500);
    	printf("\r                               ");
    	gotoxy(23,9);
    	printf("                                                                                                                          ");
    	   fflush(stdin);
			gotoxy(23,9);
	}
//remove temp bill before login
  fp=fopen("temp_bill.bin","ab");
  if(fp==NULL)  
  {
  	printf("\nCannot generate bill\n");
  	exit(1);
  }
   if(fseek(fp,-sizeof(struct Bill),SEEK_END)!=0)
 {
 	bill.sno=0;	
 }
    fread(&bill.sno, sizeof(int), 1, fp);
	 fseek(fp,0,SEEK_END);
	 bill.sno++;
  strcpy(bill.name,cu_name);
bill.phno=cu_ph;
  bill.psno=sno;
bill.size=size;
bill.qty=qty;
setname(sno);
setprice(sno,size);
int tot=bill.price*bill.qty;
Date_Time();
bill.gtot=tot+(0.04*tot);
fwrite(&bill,sizeof(struct Bill),1,fp);
item+=qty;
fclose(fp);
    printf("\nAdd another item to cart?(Y/N)\n");
    char ch;
    fflush(stdin);
CHOICE : ch=getche();
while(isspace(ch)!=0||ch=='\n')
	ch=getche();
   switch(ch)
    {
    	case 'y':
    		case 'Y':
    		fflush(stdin);
    		system("cls");
    		input();
    		break;
        case 'n':
        case 'N':
        	fflush(stdin);
    		system("cls");
		 Cart();
		 break;	
		default:
		 printf("\nPlease enter Y or N only.\n");
		 fflush(stdin);
		Sleep(1000);
		goto CHOICE;	
	}

}
void Date_Time()
{
    time_t t =time(NULL);
    struct tm tm = *localtime(&t);
   bill.day=tm.tm_mday;
    bill.mon=tm.tm_mon+1;
    bill.year=tm.tm_year+1900;
    bill.hr=tm.tm_hour;
    bill.min=tm.tm_min;
    bill.sec=tm.tm_sec;
    //printf("Current Date = %02d-%02d-%d",day,mon,year);
   // printf("\nCurrent Time = %02d:%02d:%02d",hr,min,sec);
}

void setname(int sno)
 {
 		struct Pizza p; 
	   FILE *fptr;
   if ((fptr = fopen("pizza.bin","rb")) == NULL){
       printf("Error loading file.\n");
       Sleep(1500);
       exit(1);
   }
  fseek(fptr,0,SEEK_END);
  int pos=ftell(fptr); 
  rewind(fptr);
   while(ftell(fptr)!=pos)
   {
      fread(&p, sizeof(struct Pizza), 1, fptr); 
      if(p.sno==sno)
      {
	strcpy(bill.pname,p.name);
	break;
	}
}
	fclose(fptr);
 }
 void setprice(int sno,char size){
 	struct Pizza p; 
	   FILE *fptr;
   if ((fptr = fopen("pizza.bin","rb")) == NULL){
       printf("Error loading file.\n");
       Sleep(1500);
       exit(1);
   }
  fseek(fptr,0,SEEK_END);
  int pos=ftell(fptr);
  rewind(fptr);
   while(ftell(fptr)!=pos)
   {
      fread(&p, sizeof(struct Pizza), 1, fptr); 
      if(p.sno==sno)
      {
	 switch(size)
	 {
	 	case 's':
	 	case 'S':
	 	bill.price=p.sp;
	 	break;
	 	case 'l':
		case 'L':
		bill.price=p.lp;
		break;
		case 'm':
		case 'M':
		bill.price=p.mp;
		break;	
		default:
		printf("\nWrong size was passed\n");
		exit(1);
	 }
break;
	}	
	}
	fclose(fptr);
 }
 
 void Cart(){	
onlycart();
printf("\nOrder Summary.Press :\n1.Confirm Order\n2.Add pizzas\n3.Edit bill\n4.Discard bill\n");
  char ch;
  fflush(stdin);
 ch=getche();
	 while(isspace(ch)!=0 ||  ch=='\n'){
			ch=getche();
			fflush(stdin);
		}
	char c;
	 switch(ch){
	 	case '1':
		printf("\nSure to pay now?(Y/N)\n");
		fflush(stdin);
		while(isspace(c)!=0||c=='\n'){
				c=getche();
		}
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(c=='Y'||c=='y')
		{
			Confirm();
        }
		else 
		Cart();
		break;	
	    case '2':
	    	printf("\nSure to add more Pizzas?(Y/N)\n");
		fflush(stdin);
		while(isspace(c)!=0||c=='\n'){
				c=getche();
		}
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
    		}
			system("cls");
			fflush(stdin);
			if(c=='Y'||c=='y')
		{
				addbill();
        }
		else 
		Cart();
	   fflush(stdin); 
	    case '3':
	    	editbill();
		break;
		case '4':
	    printf("\nAll items in your cart will deleted.Sure to discard bill?(Y/N)\n");
		fflush(stdin);
		while(isspace(c)!=0||c=='\n'){
				c=getche();
		}
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(c=='Y'||c=='y')
		{
			Discard();
        }
		else 
		Cart();
		break;
		default:
			printf("Please make a correct choice\n");
			Sleep(1000);
			fflush(stdin);
		    system("cls");
            Cart();
	}
 }
 
 void onlycart()
 {	
 	 	fflush(stdin);
 	system("cls");
 	float G_tot;
 struct Bill b;
 printf("      Cart :\n\n");
 printf("\t\t\t\t  _____________\n\n");  
 printf("\t\t\t\t  | Pizzadice |\n");
 printf("\t\t\t\t\  _____________\n\n");
 printf("                                  tax charged @4 %%\n\n");
 printf("S.No            Pizza Name       Size     Qty         Rate           Value     \n");
 FILE *fp;
 fp=fopen("temp_bill.bin","rb");
 if(fp==NULL)
 {
 printf("No items in cart");	
 }
 fseek(fp,0,SEEK_END);
 int pos=ftell(fp);
 rewind(fp);
 while(ftell(fp)!=pos)
 {
 fread(&b,sizeof(struct Bill),1,fp);
 printf("%3d   %20s\t%5c\t%5d\t%10.2f\t%10.2f\t\n",b.sno,b.pname,b.size,b.qty,b.price,b.gtot);
 G_tot+=b.gtot;
}
printf("\t\t\t\t\t\t             _____________");
printf("\n          Grand total: %51.2f\n\n",G_tot);
  fclose(fp);
}

 void cust_pizzamenu()
{
	int i=35,j=11;
		fflush(stdin);
		system("cls");
			struct Pizza p;
   FILE *fptr;
   if ((fptr = fopen("pizza.bin","rb")) == NULL){
       printf("No items available in the menu.\n");
  Sleep(1500);
       system("cls");
       fflush(stdin);
      exit(1);
   }
  fseek(fptr,0,SEEK_END);
  int pos=ftell(fptr);
  rewind(fptr);
   printf("\n\n\t\t\t\t\t\t\t\t  _____________\n\n");
 printf("\t\t\t\t\t\t\t\t  | Pizzadice |\n");
 printf("\t\t\t\t\t\t\t\t  _____________\n\n");
 gotoxy(34,8);
	    printf("  S.No\t   Pizza Name\t\t\t      Price\n");
	    gotoxy(46,10);
		printf("\t\t\t      small\t     medium\t      large\n\n\n");
   while(ftell(fptr)!=pos)
   {
      fread(&p, sizeof(struct Pizza), 1, fptr); 
      gotoxy(i,j);
     printf("%3d\t %20s\t %10.2f\t %10.2f\t %10.2f\n", p.sno, p.name, p.sp,p.mp,p.lp);
   j++;
   }
   fclose(fptr); 
}

void Discard()
{
	fflush(stdin);
	printf("\nBill discarded...");
	Sleep(1500);
		system("cls");
	cust_menu();
}

void Confirm()
{
	FILE *f1,*f2; 
	f1=fopen("temp_bill.bin","rb");
	f2=fopen("bill.bin","ab");
	if(f1==NULL||f2==NULL)
	{
	printf("Error opening file!");
	exit(1);
}	
 fseek(f1,0,SEEK_END);
 int pos=ftell(f1);
 rewind(f1);	
 while(ftell(f1)!=pos)
 {
 	fread(&bill,sizeof(struct Bill),1,f1);
	   int g= fwrite(&bill,sizeof(struct Bill),1,f2);
 	if(g==0)
 	printf("Cannot write items");
 }
 fclose(f1);
 	fclose(f2);	
	printf("\nGood food is Good mood:-)\nWe're sure you'll love to have the pizzas' as much as we love preparing them for you<3\n\nPress any key to continue.....");
   getch();
		system("cls");
	cust_menu();
}

void addbill(){
	fflush(stdin);
	system("cls");
	input();
}

void editbill(){
	fflush(stdin);
	system("cls");
	printf("Choose your option :\n1.Delete pizza\n2.Modify size(s/m/l)\n3.Retur to Cart\n");	
		char ch;
    	 ch=getche();
	 while(isspace(ch)!=0){
				ch=getche();
		}
    char c;
	 switch(ch){
		case '1':
			printf("\nSure to delete pizza?(Y/N)\n");
		fflush(stdin);	
		while(isspace(c)!=0||c=='\n'){
				c=getche();
		}
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(c=='Y'||c=='y')
		{
			delbill();
	    }
	    else 
		Cart();
		break;	
	    case '2':
	    	printf("\nSure to edit size of pizza?(Y/N)\n");
		fflush(stdin);
		while(isspace(c)!=0||c=='\n'){
				c=getche();
		}
		while((c=getche())!='Y'&& c!='N'&& c!='y'&& c!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(c=='Y'||c=='y')
		{
				modsize();
	    }	
	    else
	     Cart();	
		break;
		case '3':
				fflush(stdin);
		    system("cls");
		    Cart();
		default:
			printf("Please make a correct choice\n");
			Sleep(1000);
			fflush(stdin);
		    system("cls");
            editbill();
		}	
}

int checkbill(int no) 
{
	struct Bill b; int n=0;
	   FILE *fptr;
   if ((fptr = fopen("temp_bill.bin","rb")) == NULL){
       printf("No items found.\n");
       Sleep(1500);
       exit(1);
   }
  fseek(fptr,0,SEEK_END);
  int pos=ftell(fptr);
  if(pos==0)
  {
  	n=2;
  } 
  rewind(fptr);
   while(ftell(fptr)!=pos)
   {
      fread(&b, sizeof(struct Bill), 1, fptr); 
      if(b.sno==no)
      {	 
	n=1;
	break;
	}
 }
 fclose(fptr);
 return n;                           
}
void delbill()
{
		fflush(stdin);
      system("cls");	
		FILE *fp;
	fp=fopen("temp_bill.bin","rb");
	fseek(fp,0,SEEK_END);
	if(ftell(fp)==0)
	{
	printf("Please add in some pizzas first\n");
 	Sleep(1700);
 	input();	
	}
	fclose(fp);
	onlycart();
	int sno; char ch;
	printf("Enter S.No of pizza you would like to delete from cart :\n");
	while((scanf("%d%c",&sno,&ch) !=2 || ch!='\n')|| sno<=0)
   {
   printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
int n=	checkbill(sno);
if( n==1){
	struct Bill b;
	FILE *f1,*f2; 
	f1=fopen("temp_bill.bin","rb");
	f2=fopen("temp_bill2.bin","wb");
	if(f1==NULL||f2==NULL)
	{
	printf("Error opening file!");
	exit(1);
}
 fseek(f1,0,SEEK_END);
 int pos=ftell(f1);
 rewind(f1);	
 while(ftell(f1)!=pos)
 {
 	fread(&b,sizeof(struct Bill),1,f1);	
 		if(b.sno!=sno)
 		{
 			if(b.sno>sno)
 			b.sno--;
   int g= fwrite(&b,sizeof(struct Bill),1,f2);
 	if(g==0)
 	printf("Cannot write items");
 }
 else
 {
 	item=item-b.qty;
 }
 }
 fclose(f1);
 	fclose(f2);	
 	int mn=remove("temp_bill.bin"),nm=rename("temp_bill2.bin","temp_bill.bin");
 	if(mn!=0)
    printf("\n Not DELETED");  
    if(nm!=0)
    printf(" NOT RENAMED");
 }
  else
 if(n==0)
 {
 	printf("OOps,Record not found\n");
 	Sleep(1700);
 	delbill();
 }
 else
 {
 	printf("Please add in some pizzas first\n");
 	Sleep(1700);
 	input();
 }
 printf("Pizza deleted sucessfullly from your cart.\n");
 printf("Delete another?(Y/N)\n");
		fflush(stdin);		
		while((ch=getche())!='Y'&& ch!='N'&& ch!='y'&& ch!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(ch=='Y'||ch=='y')
		{
			delbill();
        }
		else
		Cart();
}

void modsize()
{
	fflush(stdin);
      system("cls");
	FILE *fp;
	fp=fopen("temp_bill.bin","rb");
	fseek(fp,0,SEEK_END);
	if(ftell(fp)==0)
	{
	printf("Please add in some pizzas in your cart first\n");
 	Sleep(1700);
 	input();	
	}
	fclose(fp);	
      onlycart();
	int sno; char ch; 
	printf("Enter S.No of pizza you would like to change price of :\n");
	while((scanf("%d%c",&sno,&ch) !=2 || ch!='\n')|| sno<=0)
   {
   printf("Invalid Input.Try again!\n");
   fflush(stdin);
   }
int n=	checkbill(sno);
if( n==1){
FILE *f1,*f2; 
	f1=fopen("temp_bill.bin","rb");
	f2=fopen("temp_bill2.bin","wb");
	struct Bill b;
	if(f1==NULL||f2==NULL)
	{
	printf("Error opening file!");
	exit(1);
}
 fseek(f1,0,SEEK_END);
 int pos=ftell(f1);
 rewind(f1);	
 while(ftell(f1)!=pos)
 {
 	fread(&b,sizeof(struct Bill),1,f1);
if(b.sno==sno)
{
	printf("Enter the new size--->\n");
 fflush(stdin);
    SIZE: b.size=getchar();
    switch(b.size)
    {
    case 's':
    case 'S':
    break;
    case 'm':
    case 'M':
	break;
	case 'l':
	case 'L':
	break;
	default: 
		printf("\nPlease make a correct choice");
			fflush(stdin);
			 goto SIZE;
	}
}
 int g= fwrite(&b,sizeof(struct Bill),1,f2);
 	if(g==0)
 	printf("Cannot write items");
 }
 fclose(f1);
 	fclose(f2);	
 int mn=remove("temp_bill.bin"),nm=rename("temp_bill2.bin","temp_bill.bin");
 	if(mn!=0)
    printf("\n Not DELETED");  
    if(nm!=0)
    printf(" NOT RENAMED");
 }
 else
if(n==0)
 {
 	printf("OOps,Record not found\n");
 	Sleep(1000);
 	modsize();
 }
 else
 {
 	printf("Please add in some pizzas first\n");
 	Sleep(1700);
 	input();
 }
 printf("\nSize modified sucessfullly.\n");
	printf("Change size of another pizza?(Y/N)\n");
		fflush(stdin);	
		while((ch=getche())!='Y'&& ch!='N'&& ch!='y'&& ch!='n')
		{
		printf(" is an invalid Input.Enter again. ");
       Sleep(1000);
    printf("\r                                                     \r");
		}
		system("cls");
			fflush(stdin);
		if(ch=='Y'||ch=='y')
		{
		modsize();
        }
		else
		Cart();
}

void d_bill()
{
    FILE *file;
    file = fopen("bill.bin","rb");
    printf("Name :- %s",cu_name);
   printf("\nMobile Number :-  %lld\n",cu_ph);
   printf("                                        Bill History\n");
   printf("\nDate               Time                  Pizza     Size    Qty        Rate           Value\n");  
   fseek(file,0,SEEK_END);
 int pos=ftell(file);
 rewind(file);
 while(ftell(file)!=pos)
 {
 	  fread(&bill,sizeof(bill),1,file);
       if(bill.phno==cu_ph)           
            {
            printf("%02d-%02d-%d       ",bill.day,bill.mon,bill.year);
            printf(" %02d:%02d:%02d",bill.hr,bill.min,bill.sec);
printf("%20s\t%5c\t%5d\t%10.2f\t%10.2f\t\n",bill.pname,bill.size,bill.qty,bill.price,bill.gtot);
        printf("\n\n");
       
    }
}
     fclose(file);
    
}

