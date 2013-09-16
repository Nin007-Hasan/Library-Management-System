

#include<stdio.h>   //Declarations for all of the functions in the Windows API(Application Programming Interfaces)
#include<string.h>
#include <windows.h>
#include<stdlib.h>


void  menu();
void gotoxy(int x,int y);
void searchbook();
void addbook();
void deletebook();
void viewlistbook();
void editbookrecords();
void closeapplication();
void returnfunc();
int checkid(int t);
int getdata();
void passwordChange();
void changePass();
void confirma(char pass[]);


FILE * fp, *ft;
char findbook='\0';
struct library
{
    long int book_id;
    char bookname[50];
    char author[30];
    int year;
    int quantity;
}add;

COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void  menu()
{
    system("cls");
    gotoxy(20,1);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//    Sleep(2000);

    int choice;
    gotoxy(20,3);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Search Book\n");
    gotoxy(20,5);//Sleep(1000);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Add Book\n");
    gotoxy(20,7);//Sleep(1000);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Delete Book\n");
    gotoxy(20,9);//Sleep(1000);
    printf("\xDB\xDB\xDB\xDB\xB2 4. View Booklist\n");
    gotoxy(20,11);//Sleep(1000);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Edit Book Records\n");
    gotoxy(20,13);//Sleep(1000);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Change Password\n");
    gotoxy(20,15);//Sleep(1000);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application\n");
    gotoxy(20,17);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,18);
	tym();

    gotoxy(20,21);
    fflush(stdin);
    printf("Select an option: ");
    scanf("%d", &choice);

    switch(choice)
	{
		case 1:
		searchbook();
		break;
	case 2:
		addbook();
		break;
    case 3:
		deletebook();
	    break;
	case 4:
		viewlistbook();
	    break;
    case 5:
		editbookrecords();
		break;
    case 6:
		passwordChange();
		break;

	case 7:
	    {
		closeapplication();
	    }
	    default:
		{
		gotoxy(10,23);
		printf("\aWrong Entry!!Please re-entered correct option");
		if(getch())
		menu();
		}

    }
    exit(0);
}

void searchbook()
{
    system("cls");
    int d;
    char z;
    printf("******************************** Search Books **********************************");
    gotoxy(15,3);
    printf("\xDB\xDB\xDB\xB2 1. Search By ID");
    gotoxy(17,5);
    printf("\xDB\xDB\xDB\xB2 2. Search By Name");
    gotoxy(19,7);
    printf("\xDB\xDB\xDB\xB2 3. Search By Author");
    gotoxy( 21,10);
    printf("Enter Your Choice:");
    fp=fopen("quizdata.txt","rb+");
    rewind(fp);
    int ch;
    scanf("%d",&ch);
    fflush(stdin);
    switch(ch)
    {
	  case 1:
    {
	    system("cls");
	    gotoxy(25,4);
	    printf("****Search Books By Id****");
	    gotoxy(20,5);
	    printf("Enter the book id:");
	    scanf("%d",&d);

	    while(fread(&add,sizeof(add),1,fp)==1)
	    {
		if(add.book_id==d)
		{
		    Sleep(500);
		    gotoxy(20,7);
		    printf("The Book is available");
		    gotoxy(18,8);
		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    gotoxy(18,9);
		    printf("\xB2 ID:%d",add.book_id);gotoxy(56,9);printf("\xB2");
		    gotoxy(18,10);
		    printf("\xB2 Name:%s",add.bookname);gotoxy(56,10);printf("\xB2");
		    gotoxy(18,11);
		    printf("\xB2 Author:%s ",add.author);gotoxy(56,11);printf("\xB2");
		    gotoxy(18,12);
		    printf("\xB2 Qantity:%d ",add.quantity);gotoxy(56,12);printf("\xB2");
		    gotoxy(18,13);

		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    findbook='t';
		}



	    }
	    if(findbook!='t')
	    {
	    gotoxy(20,8);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	    gotoxy(20,10);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(22,9);printf("\aNo Record Found");
	    }
	    gotoxy(20,17);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
            searchbook();
	    else
            menu();
	    break;
	}

	case 2:
	{
	    char s[15];
	    system("cls");
	    gotoxy(25,4);
	    printf("****Search Books By Name****");
	    gotoxy(20,5);
	    printf("Enter Book Name:");
	    gets(s);
	    int d=0;
	    int index=7;
	    while(fread(&add,sizeof(add),1,fp)==1)
	    {
		if(findSubstring(add.bookname,s)!=0)
		{
		    gotoxy(20,index++);
		    if(d==0)
                printf("The Book is available");
		    gotoxy(20,index++);
		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    gotoxy(20,index++);
		    printf("\xB2 ID:%d",add.book_id);gotoxy(47,9);printf("\xB2");
		    gotoxy(20,index++);
		    printf("\xB2 Name:%s",add.bookname);gotoxy(47,10);printf("\xB2");
		    gotoxy(20,index++);
		    printf("\xB2 Author:%s",add.author);gotoxy(47,11);printf("\xB2");
		    gotoxy(20,index++);
		    printf("\xB2 Qantity:%d",add.quantity);gotoxy(47,12);printf("\xB2");
		    gotoxy(20,index++);

		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    d++;
		}

	    }
	    if(d==0)
	    {
	    gotoxy(20,8);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	    gotoxy(20,10);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(22,9);printf("\aNo Record Found");
	    }
	    gotoxy(20,index++);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
            searchbook();
	    else
            menu();
	    break;
	}

	case 3:
	{
	    char s[15];
	    system("cls");
	    gotoxy(25,4);
	    printf("****Search Books By Author****");
	    gotoxy(20,5);
	    printf("Enter Author Name:");
	    gets(s);
	    int d=0;
	    int index=7;
	    while(fread(&add,sizeof(add),1,fp)==1)
	    {
		if(findSubstring(add.author,s)!=0) //checks whether a.name is equal to s or not
		{
		    gotoxy(20,index++);
		    if(d==0)
                printf("The Book is available");
		    gotoxy(20,index++);
		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    gotoxy(20,index++);
		    printf("\xB2 ID:%d",add.book_id);gotoxy(47,9);printf("\xB2");
		    gotoxy(20,index++);
		    printf("\xB2 Name:%s",add.bookname);gotoxy(47,10);printf("\xB2");
		    gotoxy(20,index++);
		    printf("\xB2 Author:%s",add.author);gotoxy(47,11);printf("\xB2");
		    gotoxy(20,index++);
		    printf("\xB2 Qantity:%d",add.quantity);gotoxy(47,12);printf("\xB2");
		    gotoxy(20,index++);

		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    d++;
		}

	    }
	    if(d==0)
	    {
	    gotoxy(20,8);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	    gotoxy(20,10);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(22,9);printf("\aNo Record Found");
	    }
	    gotoxy(20,index++);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchbook();
	    else
            menu();
	    break;
	}


	default :
	getch();
	searchbook();
    }
    fclose(fp);

}

int findSubstring(char c[], char d[])
{
    int i=0,j=0,k=0,l=0,start =0;
    char a[50],b[50];
    strcpy(a,c);
    strcpy(b,d);

    for(i=0;i<strlen(a);i++) //Converting all characters to lowercase
        if(a[i]<97 && a[i] != 32)
            a[i]+=32;

    for(i=0;i<strlen(b);i++)  //Converting all characters to lowercase
        if(b[i]<97)
            b[i]+=32;
    i=0;
    while(a[i] != '\0')
    {
        if(a[i] == b[j])
        {
            start=1;
            l=i;
        }

        while(a[i] == b[j])
        {
            if(a[i] == '\0')
                return ++k; //if substring found at the end of main string
            i++;
            j++;
        }
        if(b[j] == '\0' && k==0 )
            return ++k; //if substring found before the end of main string
        if(start==1)
        {
            i=l;
            start=0;
        }
        i++;
        j=0;
    }
    return k;
}

int tym(void)
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));

    return 0 ;
}

void addbook()
{
    system("cls");

    fp = fopen ( "quizdata.txt" , "a+" );

    if(getdata()==1)
	{
	fseek(fp,0,SEEK_END);
	fwrite(&add,sizeof(add),1,fp);
	fclose(fp);
	gotoxy(21,14);
	printf("The record is sucessfully saved");
	gotoxy(21,15);
	printf("Save any more?(Y / N):");
	if(getch()=='n')
	    menu();
	else
	    system("cls");
	    addbook();
	}
    exit(0);
}

void deletebook()
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')
    {
	system("cls");
	gotoxy(10,5);
	printf("Enter the Book ID to  delete:");
	scanf("%d",&d);
	fp=fopen("quizdata.txt","rb+");
	rewind(fp);
	while(fread(&add,sizeof(add),1,fp)==1)
	{
	    if(add.book_id==d)
	    {

		gotoxy(10,7);
		printf("The book record is available");
		gotoxy(10,8);
		printf("Book name is %s",add.bookname);
		gotoxy(10,9);
		findbook='t';
	    }
	}
	if(findbook!='t')
	{
	    gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    menu();
	}
	if(findbook=='t' )
	{
	    gotoxy(10,12);
	    printf("Are you sure you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
		ft=fopen("temp.txt","wb+");
		rewind(fp);
		while(fread(&add,sizeof(add),1,fp)==1)
		{
		    if(add.book_id!=d)
		    {
			fwrite(&add,sizeof(add),1,ft);
		    }
		}
		fclose(ft);
		fclose(fp);
		remove("quizdata.txt");
		rename("temp.txt","quizdata.txt");
		fp=fopen("quizdata.txt","rb+");
		if(findbook=='t')
		{
		    gotoxy(10,14);
		    printf("The record is sucessfully deleted");
		    gotoxy(10,16);
		    printf("Delete another record?(Y/N)");
		}
	    }
	else
	menu();
	fflush(stdin);
	another=getch();
	}
	}
    gotoxy(10,15);
    menu();
}

void viewlistbook()
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" BOOK ID         BOOK NAME              AUTHOR              YEAR     QUANTITY ");
    j=4;
    fp=fopen("quizdata.txt","rb");
    while(fread(&add,sizeof(add),1,fp)==1)
    {
	gotoxy(4,j);
	printf("%d",add.book_id);
	gotoxy(16,j);
	puts(add.bookname);
	gotoxy(42,j);
	puts(add.author);
	gotoxy(62,j);
	printf("%d",add.year);
	gotoxy(73,j);
	printf("%d",add.quantity);

	printf("\n\n");
	j++;
	i=i+add.quantity;
      }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fp);
      gotoxy(35,25);
      returnfunc();
    exit(0);
}

void returnfunc()
{
    printf(" Press ENTER to return to main menu");
    a:
    if(getch()==13) //allow only use of enter
        menu();
    else
    goto a;
}

void editbookrecords()
{
    system("cls");
	int c=0;
	int d,e;
	gotoxy(20,4);
	printf("****Edit Books Section****");
	char another='y';
	while(another=='y')
	{
		system("cls");
		gotoxy(20,2);
		printf("Enter Book ID to be edited:");
		scanf("%d",&d);
		fp=fopen("quizdata.txt","rb+");
		while(fread(&add,sizeof(add),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				gotoxy(25,4);
				printf("The book is AVAILABLE.");
				gotoxy(25,6);
				printf("The Book ID: %d",add.book_id);
				gotoxy(1,8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(1,9);
				printf("\xB2 Current name: ");puts(add.bookname);gotoxy(38,9);printf("\xB2");
				gotoxy(1,10);
				printf("\xB2 Current Author:");puts(add.author);gotoxy(38,10);printf("\xB2");
				gotoxy(1,11);
				printf("\xB2 Current year:");printf("%d",add.year);gotoxy(38,11);printf("\xB2");
				gotoxy(1,12);
				printf("\xB2 Current quantity:");printf("%d",add.quantity);gotoxy(38,12);printf("\xB2");
                gotoxy(1,13);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                fflush(stdin);
                gotoxy(40,8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


                gotoxy(40,9);printf("\xB2");
                gotoxy(40,10);printf("\xB2");
                gotoxy(40,11);printf("\xB2");
                gotoxy(40,12);printf("\xB2");

                gotoxy(78,9);printf("\xB2");
                gotoxy(78,10);printf("\xB2");
                gotoxy(78,11);printf("\xB2");
                gotoxy(78,12);printf("\xB2");
                gotoxy(40,13);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

                gotoxy(40,9);
				printf("\xB2 Enter new name:");gets(add.bookname);
				gotoxy(40,10);
				printf("\xB2 Enter new Author:");gets(add.author);
				gotoxy(40,11);
				printf("\xB2 Enter new year:");scanf("%d",&add.year);
				gotoxy(40,12);
				printf("\xB2 Enter new quantity:");scanf("%d",&add.quantity);

				gotoxy(22,17);
				printf("The record is modified");
				fseek(fp,-sizeof(add),1);
				fwrite(&add,sizeof(add),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(22,20);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		gotoxy(50,20);
		another=getch() ;
	}
		returnfunc();
}

void closeapplication()
{

    system("cls");
    gotoxy(16,3);
    printf("Created By......");
    Sleep(1000);
    gotoxy(16,5);
    printf("1. HASAN AL MAMUN");
    gotoxy(16,7);

    printf("I.D.-1110364542");
    gotoxy(16,9);
    Sleep(2000);
    printf("   Thank you.............");
    Sleep(1000);
    gotoxy(16,15);

    exit(0);
}

int getdata()
{
	int t;
	gotoxy(20,3);printf("Enter the Information Below");
	gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(53,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(53,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(53,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(53,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(53,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(53,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(53,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(21,6);
	printf("Book ID:\t");
	gotoxy(30,6);
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
		gotoxy(21,13);
		printf("\aThe book id already exists\a");
		getch();
		menu();
		return 0;
	}
	add.book_id=t;
	fflush(stdin);
	gotoxy(21,7);
	printf("Book Name:");
	fflush(stdin);
	gotoxy(31,7);
	gets(add.bookname);
	fflush(stdin);
	gotoxy(21,8);
	printf("Author:");gotoxy(28,8);
	fflush(stdin);
	gets(add.author);
	gotoxy(21,9);
	printf("Year:");gotoxy(28,9);
	scanf("%d",&add.year);
	fflush(stdin);
	gotoxy(21,10);
	printf("Quantity:");gotoxy(31,10);
	scanf("%d",&add.quantity);
	gotoxy(21,10);
	return 1;
}

int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while(fread(&add,sizeof(add),1,fp)==1)
	if(add.book_id==t)
        return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}
void Password(void) //for password option
{
    system("cls");
    gotoxy(25,2);
    printf("<<<<<LIBRARY MANGEMENT SYSTEM>>>>>");
    char ch,pass[50];
    int i=0,j;
    gotoxy(15,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(28,6);
    printf("Enter PASSWORD to log in");
    gotoxy(15,5);printf("\xB2");gotoxy(15,6);printf("\xB2");gotoxy(15,7);printf("\xB2");gotoxy(15,8);printf("\xB2");gotoxy(15,9);printf("\xB2");gotoxy(15,10);printf("\xB2");gotoxy(15,11);printf("\xB2");gotoxy(15,12);printf("\xB2");
    gotoxy(15,13);printf("\xB2");gotoxy(15,14);printf("\xB2");gotoxy(15,15);printf("\xB2");gotoxy(15,16);printf("\xB2");gotoxy(15,17);printf("\xB2");gotoxy(15,18);printf("\xB2");gotoxy(15,19);printf("\xB2");gotoxy(15,20);printf("\xB2");

    gotoxy(68,5);printf("\xB2");gotoxy(68,6);printf("\xB2");gotoxy(68,7);printf("\xB2");gotoxy(68,8);printf("\xB2");gotoxy(68,9);printf("\xB2");gotoxy(68,10);printf("\xB2");gotoxy(68,11);printf("\xB2");gotoxy(68,12);printf("\xB2");
    gotoxy(68,13);printf("\xB2");gotoxy(68,14);printf("\xB2");gotoxy(68,15);printf("\xB2");gotoxy(68,16);printf("\xB2");gotoxy(68,17);printf("\xB2");gotoxy(68,18);printf("\xB2");gotoxy(68,19);printf("\xB2");gotoxy(68,20);printf("\xB2");

    gotoxy(15,20);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


       gotoxy(20,8);
       printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';

    FILE *z;
    z=fopen("password.txt","r");
    char passFile[50];
    if(fread(&passFile,sizeof(passFile),1,z)==1)
        ;
    printf("\n");


   if(strcmp(pass,passFile)==0)
   {

        gotoxy(25,11);
        //textcolor(BLINK);
        printf("Password match");
        gotoxy(25,13);
        printf("Press any key to countinue.....");
        getch();
        menu();
   }
   else
   {
	 gotoxy(25,13);
	 printf("\aWarning!! Incorrect Password");
	 getch();
	 rewind(z);
	 Password();
   }

}
void passwordChange()
{
    system("cls");

    char ch,curPass[50];
    int i=0;
    gotoxy(15,7);
       printf("Enter Current password:");

   while(ch!=13)
   {
       fflush(stdin);
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('*');
	curPass[i] = ch;
	i++;
	}
   }
   curPass[i] = '\0';

    FILE *z;
    z=fopen("password.txt","r");
    char passFile[50];
    if(fread(&passFile,sizeof(passFile),1,z)==1)
        ;
  //  printf("\n");
    //puts(passFile);
    //puts(curPass);

    if(strcmp(curPass,passFile)==0)
        changePass();
    else
    {
        printf("Incorrect current password");
        returnfunc();
    }
    exit(0);
}
void changePass()
{
    //system("cls");
    char ch,newPass[50];
    int i=0;
    gotoxy(15,9);
    //getch();
    printf("Enter New password:");
    while(ch!=13)
    {
        fflush(stdin);
        ch=getch();
        if(ch!=13 && ch!=8){
        putch('*');
        newPass[i] = ch;
        i++;
        }
    }
    newPass[i] = '\0';
    confirma(newPass);
    //exit(0);
}

void confirma(char pass[])
{
    //system("cls");
    char ch,conNewPass[50];
    int i=0;
    gotoxy(15,11);
    printf("Confirm password:");

    while(ch!=13)
    {
        fflush(stdin);
        ch=getch();
        if(ch!=13 && ch!=8){
        putch('*');
        conNewPass[i] = ch;
        i++;
        }
    }
    conNewPass[i] = '\0';

    if(strcmp(pass,conNewPass)==0)
    {
        FILE *y;
        y=fopen("password.txt","w");
        //char pass[50];
        //strcpy(pass,"saad");
        if(fwrite(&conNewPass,sizeof(conNewPass),1,y)==1)
        gotoxy(15,13);
        printf("Password has successfully changed!");
        gotoxy(14,17);
        returnfunc();
    }
    else
    {
        gotoxy(15,13);
        printf("New Password is NOT matched!");
        gotoxy(14,17);
        returnfunc();
    }
    //exit(0);
}


int main()
{
    Password();
    return 0;
}


