/*
PROJECT TITLE: SUDOKU PUZZLE GAME
COMPILED ON: TURBO C++ 3.0
DEVELOPED BY: BHEDA VISHAL
SUBMITED TO: GUJARAT TECHNICAL UNIVERSITY AHMEDABAD
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<string.h>

void mainSdk();
void box();
void checkSolution();
int checkRow(int,int,char);
int checkColumn(int,int,char);
int checkGrid(int,int,char);

void viewSolution(char[9][9],char[9][9]);
void msgbox(char[20]);
void howToPlay();
void record();
void saveRecord(char[20]);

int toNum(int);
void selectLvl();
void highlight(int);
void playSdk(char[9][9]);

int  level;
char opsdk[9][9]; //All operation done with this array
char pausesdk[9][9]; //Use when resume
char viewsdk[9][9];
int length;
int k=0;
int pause=0;
char pauseLvl;

time_t first,second;
float timespend;

/*to backtrack solution*/
struct stack
{
	int r,c;
	char value;
}st[81];

void main()
{
clrscr();
system("cls");
mainSdk(); //display main menu

}

/*to set header*/
void header()
{
	int i,l,j,k,m,n;
	textcolor(YELLOW);
	textbackground(BLACK);
	gotoxy(1,120);
	cprintf("%c",218);//print Right upper Corner

	for(k=2;k<80;k++)
	{
	gotoxy(k,1);
	cprintf("%c",196);//print Upper Line
	}

	gotoxy(80,1);
       cprintf("%c",191);//print Left Upper Corner

	for(l=2;l<5;l++)
	{
	gotoxy(1,l);
	cprintf("%c",179);//print right side line
	}

	for(m=2;m<5;m++)
	{
	gotoxy(80,m);
	cprintf("%c",179);//print left side line
	}

	gotoxy(1,5);
	cprintf("%c",192);//print bottm right corner


	for(n=2;n<80;n++)
	{
	gotoxy(n,5);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(80,5);
	cprintf("%c",217);//print bottom left corner
	textcolor(BLUE);
	gotoxy(2,2);
	cprintf("123768467463745284537472342836473647236427346734534576564564454123456789876513");
	gotoxy(2,3);
	cprintf("987654322345654356786543567865467896543267896543678954367854678432789654789654");
	gotoxy(2,4);
	cprintf("456789876545678987654345675436788765435677654567654334566543789654356754323456");
	gotoxy(35,3);
	textcolor(RED);
	cprintf(" SUDOKU ");

	textcolor(RED+GREEN);

}

//Display Main Menu
void mainSdk()
{

   int choice;
   int i,j;
Choice:
system("cls");
header();
textcolor(YELLOW);

	gotoxy(29,8);
	cprintf("%c",218);//print Right upper Corner

	for(i=30;i<=46;i++)
	{
	gotoxy(i,8);
	cprintf("%c",196); //print upper Line
	}

	gotoxy(47,8);
	cprintf("%c",191);//print Left Upper Corner

	for(i=9;i<14;i++)
	{
	gotoxy(29,i);
	cprintf("%c",179);//print right side line
	}

	for(i=9;i<14;i++)
	{
	gotoxy(47,i);
	cprintf("%c",179);//print left side line
	}

	gotoxy(29,14);
	cprintf("%c",192);//print bottm right corner


	for(i=30;i<=46;i++)
	{
	gotoxy(i,14);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(47,14);
	cprintf("%c",217);//print bottom left corner*/


textcolor(RED+GREEN);
gotoxy(31,9);
cprintf("PLAY GAME    [1]");
gotoxy(31,10);
cprintf("ACHIVEMENT   [2]");
gotoxy(31,11);
cprintf("HOW TO PLAY  [3]");
gotoxy(31,12);
cprintf("EXIT         [4]");

	 textcolor(BLUE+GREEN);
	 gotoxy(5,24);
	 printf("Info: Press 1 to 4 for select menu.");

	 gotoxy(30,15);
	 cprintf("Enter Your Choice:");
	 choice=getch();
	 switch(choice)
	   {
		case 49:
			selectLvl();
			break;

		 case 50:
			record();
			break;

		 case 51:
			howToPlay();
			break;

		 case 52:
			 exit(0);

		default:
			  gotoxy(30,17);
			  msgbox("Enter Valid Choice");
			  textbackground(BLACK);
			  goto Choice;
	   }

}

/*to display message box*/
void msgbox(char msg[20])
{

	int i,j;
	gotoxy(30,14);
	textcolor(RED);
	textbackground(GREEN+BLUE);
	for(i=13;i<=15;i++)
	{
		for(j=26;j<=48;j++)
		{
		gotoxy(j+1,i);
		cprintf("%c",176);
		}
	}

	gotoxy(30,14);
	printf("%s",msg);

	textbackground(BLACK);
	gotoxy(25,12);
	cprintf("%c",218);//print Right upper Corner

	for(i=26;i<=50;i++)
	{
	gotoxy(i,12);
	cprintf("%c",196); //print upper Line
	}

       gotoxy(51,12);
       cprintf("%c",191);//print Left Upper Corner

	for(i=13;i<16;i++)
	{
	gotoxy(25,i);
	cprintf("%c",179);//print right side line
	}

	for(i=13;i<16;i++)
	{
	gotoxy(51,i);
	cprintf("%c",179);//print left side line
	}

	gotoxy(25,16);
	cprintf("%c",192);//print bottm right corner


	for(i=26;i<=50;i++)
	{
	gotoxy(i,16);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(51,16);
	cprintf("%c",217);//print bottom left corner*/

	sleep(2);
	return;
}

/*to display empty Box*/
void box()
{
	int i;
	textcolor(GREEN+BLUE);
	gotoxy(26,7);
	cprintf("%c",218);//print Right upper Corner

	for(i=27;i<=53;i++)
	{
	gotoxy(i,7);
	cprintf("%c",196);//print Upper Line
	}

	gotoxy(54,7);
	cprintf("%c",191);//print Left Upper Corner

	for(i=8;i<=24;i++)
	{
	gotoxy(26,i);
	cprintf("%c",179);//print right side line
	}

	for(i=8;i<=24;i++)
	{
	gotoxy(54,i);
	cprintf("%c",179);//print left side line
	}

	for(i=8;i<=24;i++)
	{
	gotoxy(35,i);
	cprintf("%c",179);//print verticle diveder line
	}
	for(i=8;i<=24;i++)
	{
	gotoxy(44,i);
	cprintf("%c",179);//print verticle diveder line
	}

	for(i=27;i<=53;i++)
	{
	gotoxy(i,13);
	cprintf("%c",205);//print horizontal devider
	}
	for(i=27;i<=53;i++)
	{
	gotoxy(i,19);
	cprintf("%c",205);//print horizontal devider
	}

	gotoxy(26,25);
	cprintf("%c",192);//print bottm right corner

	for(i=27;i<=54;i++)
	{
	gotoxy(i,25);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(54,25);
	cprintf("%c",217);//print bottom left corner

}

/* Select Levels */
void selectLvl(void)
{
    int no=7,i,choice;
    int count=1;
    char ch='0';

	char lvl1[9][9]={'1','2',NULL,'4','5','6','7','8','9','7',NULL,'9','1','2','3','4',NULL,'6','4','5','6','7','8',NULL,'1','2','3','2','3','1','5','6',NULL,'8','9','7',NULL,NULL,'7','2','3','1','5','6','4','5','6','4',NULL,'9','7','2',NULL,'1','3','1','2','6','4','5','9','7',NULL,'9',NULL,'8','3',NULL,'2','6','4','5','6','4','5','9','7','8','3',NULL,'2'};
	char lvl2[9][9]={NULL,'1','3','6',NULL,NULL,NULL,NULL,NULL,NULL,'5','2',NULL,NULL,'3','8','4',NULL,NULL,NULL,'9',NULL,NULL,'1','5',NULL,NULL,'9',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'8',NULL,'3','8',NULL,NULL,NULL,'6','7',NULL,'1',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'3',NULL,NULL,'5','2',NULL,NULL,'1',NULL,NULL,NULL,'4','6','1',NULL,NULL,'2','8',NULL,NULL,NULL,NULL,NULL,NULL,'7','3','6',NULL};
	char lvl3[9][9]={'7',NULL,NULL,'4',NULL,'1',NULL,NULL,'9',NULL,'1','3',NULL,'6',NULL,NULL,'5',NULL,NULL,'6',NULL,'9',NULL,NULL,NULL,NULL,NULL,'3',NULL,'7',NULL,NULL,NULL,'9','1',NULL,NULL,NULL,NULL,'6',NULL,'5',NULL,NULL,NULL,NULL,'8','2',NULL,NULL,NULL,'5',NULL,'4',NULL,NULL,NULL,NULL,NULL,'2',NULL,'9',NULL,NULL,'3',NULL,NULL,'8',NULL,'1','4',NULL,'4',NULL,NULL,'5',NULL,'6',NULL,NULL,'2'};
	char lvl4[9][9]={NULL,'2',NULL,'1',NULL,NULL,NULL,NULL,NULL,'1','8',NULL,NULL,'6',NULL,NULL,'4','3','3',NULL,NULL,'2',NULL,NULL,'5','6',NULL,NULL,'6',NULL,'3',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'2',NULL,NULL,NULL,'1',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'9',NULL,'3',NULL,NULL,'5','8',NULL,NULL,'7',NULL,NULL,'9','9','4',NULL,NULL,'5',NULL,NULL,'7','8',NULL,NULL,NULL,NULL,NULL,'1',NULL,'5',NULL};
	char lvl5[9][9]={'6','4',NULL,NULL,'2',NULL,'8',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'4','3','2',NULL,NULL,NULL,'1',NULL,NULL,NULL,NULL,NULL,'5','9',NULL,NULL,'5',NULL,'3',NULL,NULL,'4',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'5',NULL,NULL,'1',NULL,'8',NULL,NULL,'6','7',NULL,NULL,NULL,NULL,NULL,'5',NULL,NULL,NULL,'2','9','7',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'6',NULL,'1',NULL,NULL,'8','7'};

    value:
    gotoxy(30,10);
    pause=0;
    while(1)
    {
	switch(ch)
	{
	case 80:
	    count++;
	    if (count==no+1) count=1;
	    break;
	case 72:
	    count--;
	    if(count==0) count=no;
	    break;
	}

	highlight(count);
	ch=getch();
	if(ch=='\r')
	{
	choice=count;
	select:
	      switch(choice)
		{
		case 2:
			level=1;
			playSdk(lvl1);
			break;

		case 3:
			level=2;
			playSdk(lvl2);
			break;

		case 4:
			level=3;
			playSdk(lvl3);
			break;

		case 5:
			level=4;
			playSdk(lvl4);
			break;

		case 6:
			level=5;
			playSdk(lvl5);
			break;

		case 7:
			mainSdk();
			break;

		case 1:
			if(level==NULL)
			{
			msgbox("Choose New Level");
			goto value;
			}
			else
			{
			pause=1;
			choice=level+1;
			goto select;
			break;
			}
	default:
	      getch();
	      mainSdk();

   }
	}


   }
}

/*to change the poiter and highlight level*/
void highlight(int count)
{
int i;
system("cls");
header();

		gotoxy(29,8);
		cprintf("%c",218);//print Right upper Corner

		for(i=30;i<=46;i++)
		{
		gotoxy(i,8);
		cprintf("%c",196); //print upper Line
		}

		gotoxy(47,8);
		cprintf("%c",191);//print Left Upper Corner

		for(i=9;i<16;i++)
		{
		gotoxy(29,i);
		cprintf("%c",179);//print right side line
		}

		for(i=9;i<16;i++)
		{
		gotoxy(47,i);
		cprintf("%c",179);//print left side line
		}

		gotoxy(29,16);
		cprintf("%c",192);//print bottm right corner


		for(i=30;i<=46;i++)
		{
		gotoxy(i,16);
		cprintf("%c",196);//print bottom line
		}

		gotoxy(47,16);
		cprintf("%c",217);//print bottom left corner


	textcolor(WHITE);
	gotoxy (32,9);
	cprintf("   Resume   ");
	gotoxy (32,10);
	cprintf("   Level 1  ");
	gotoxy (32,11);
	cprintf("   Level 2  ");
	gotoxy (32,12);
	cprintf("   Level 3  ");
	gotoxy (32,13);
	cprintf("   Level 4  ");
	gotoxy (32,14);
	cprintf("   Level 5  ");
	gotoxy (32,15);
	cprintf("   Back     ");

	textcolor(0);
	textbackground(11);

	switch(count)
	{
	case 1:
	    gotoxy (32,9);
	    cprintf(" - Resume   ");
	    break;
	case 2:
	    gotoxy (32,10);
	    cprintf(" - Level 1  ");
	    break;
	case 3:
	    gotoxy (32,11);
	    cprintf(" - Level 2  ");
	    break;
	case 4:
	    gotoxy (32,12);
	    cprintf(" - Level 3  ");
	    break;
	case 5:
	    gotoxy (32,13);
	    cprintf(" - Level 4  ");
	    break;
	case 6:
	    gotoxy (32,14);
	    cprintf(" - Level 5  ");
	    break;
	case 7:
	    gotoxy (32,15);
	    cprintf(" - Back     ");
	    break;
	}
}

/*to display grid of perticular level*/
void playSdk(char lvl[9][9])
{
	int i,j,l,m=0;
	int cmin=0,csec=0;
	int n=0,temp=0,flag=0;
	int checkr=0,checkc=0,checkg=0;
	char k;
	float ctime;
	system("cls");

	header();

	first=time(NULL);
	textbackground(BLACK);
	gotoxy(58,11);
	cprintf("%c",195);//print Right upper Corner

	gotoxy(58,9);
	cprintf("%c",218);

       for(i=59;i<=80;i++)
       {
	gotoxy(i,11);
	cprintf("%c",196); //print upper Line
       }

       for(i=59;i<=80;i++)
       {
       gotoxy(i,9);
       cprintf("%c",196);
       }

	for(i=12;i<17;i++)
	{
	gotoxy(58,i);
	cprintf("%c",179);//print left side line
	}

	gotoxy(58,10);
	cprintf("%c",179);

	gotoxy(58,17);
	cprintf("%c",192);//print bottm right corner


       for(i=59;i<=80;i++)
	{
	gotoxy(i,17);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(60,12);
	cprintf("Submit        [S]");
	gotoxy(60,14);
	cprintf("View Solution [V]");
	gotoxy(60,16);
	cprintf("Back          [B]");

	box();
	if(pause==0)
	{
	timespend=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
		opsdk[i][j]=lvl[i][j];
		viewsdk[i][j]=lvl[i][j];
		}
	}
	}
	else
	{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
		opsdk[i][j]=pausesdk[i][j];
		}
	}
	}

	do
	{
		m=0;
		for(i=0;i<9;i++)
		{
		box();

		l=0;
		m=m+2;

			for(j=0;j<9;j++)
			{

				l=l+3;
					if(lvl[i][j]==NULL || lvl[i][j]=='*')
					{
						if(lvl[i][j]=='*')
						{
						checkvalue: if(temp==0 && (k==49 || k==50 || k==51|| k==52 || k==53 || k==54 || k==55 || k==56 || k==57))
							    {
							      checkr=checkRow(i,j,k);
							      checkc=checkColumn(i,j,k);
							      checkg=checkGrid(i,j,k);
								if(checkr==1 && checkc==1 && checkg==1)
								{
									opsdk[i][j]=k;
									gotoxy(25+l,6+m);
									textcolor(RED);
									cprintf("%c",opsdk[i][j]);
									n=0;
									temp=1;
								}
								else
								{

									gotoxy(25+l,6+m);
									textcolor(RED);
									k=getch();
									goto checkvalue;

								}
							}
							else
							{
							   lvl[i][j]=NULL;
							   gotoxy(25+l,6+m);
							   textcolor(RED);
							   cprintf("%c",opsdk[i][j]);
							   n=0;
							   temp=0;

							}
						}
						else if(n!=1)
						{
							lvl[i][j]='*';
							gotoxy(25+l,6+m);
							if(flag==0)
							{
								printf(" ");
								k=46;
								flag=1;
							}
							else
							{
								textcolor(RED);
								k=getch();
							}
						 n=1;
						}
						else
						{
							gotoxy(25+l,6+m);
							textcolor(RED);
							cprintf("%c",opsdk[i][j]);
						}
				  }
				  else
				  {
				  gotoxy(25+l,6+m);
				  printf("%c",opsdk[i][j]);
				  }


			}// loop j is end
			printf("\n");

		} //loop i is end

	if(k==115)//ascii for s
	{
		second=time(NULL);
		ctime=difftime(second,first)+timespend;
		timespend=ctime;
		checkSolution();
	}

	else if(k==98)//ascii for b
	{
	pause=1;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
		pausesdk[i][j]=opsdk[i][j];
		}
	}
	second=time(NULL);
	timespend+=difftime(second,first);
	selectLvl();
	}

	else if(k==118)//ascii for v
	{
	pause=1;
	 for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
		pausesdk[i][j]=opsdk[i][j];
		opsdk[i][j]=viewsdk[i][j];
		}
	}
	second=time(NULL);
	timespend+=difftime(second,first);
	viewSolution(viewsdk,viewsdk);
	}

	else
	{
	second=time(NULL);
	ctime=difftime(second,first)+timespend;
	cmin=(int)ctime/60;
	csec=(int)ctime%60;
	gotoxy(60,10);
	textcolor(GREEN);
	cprintf("Timer %d:%d M/S",cmin,csec);
	continue;
	}

	}while(1);

       //	getch();

}

/* Check Solution Is True Or False */
void checkSolution()
{
char plname[20];
char choice;
int i,asc,j,count=0,sumrow,sumcol;
int n=9;
int checkSol[9][9];
system("cls");

header();

gotoxy(30,9);
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
    asc=opsdk[i][j];
    checkSol[i][j]=toNum(asc);
}
}

    for(i=0;i<n;i++)   //Check Column
    {
      sumcol=0;
	for(j=0;j<n;j++)
	{
		sumcol+=checkSol[j][i]; //sum of column
	}
	if(sumcol!=(n*(n+1)/2))
	{
		count++;
	}
    }

    for(i=0;i<n;i++) //Check Row
    {
    sumrow=0;
	for(j=0;j<n;j++)
	{
	sumrow+=checkSol[i][j];   //sum of row
	}

    if(sumrow!=(n*(n+1)/2))
    {
      count++;
    }
    }
	if(count==0)
	{
	textcolor(GREEN);
	}
	else
	{
	textcolor(RED);
	}
	gotoxy(26,7);
	cprintf("%c",218);//print Right upper Corner

	for(i=27;i<=54;i++)
	{
	gotoxy(i,7);
	cprintf("%c",196);//print Upper Line
	}

	gotoxy(55,7);
	cprintf("%c",191);//print Left Upper Corner

	for(i=8;i<=15;i++)
	{
	gotoxy(26,i);
	cprintf("%c",179);//print right side line
	}

       for(i=8;i<=15;i++)
	{
	gotoxy(55,i);
	cprintf("%c",179);//print left side line
	}

	gotoxy(26,15);
	cprintf("%c",192);//print bottm right corner

	for(i=27;i<=54;i++)
	{
	gotoxy(i,15);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(55,15);
	cprintf("%c",217);//print bottom left corner*/


  if(count==0)
  {
    gotoxy(28,9);
    cprintf("YOU WIN %c Congrats!!!!! ",1);
    gotoxy(28,10);

    cprintf("Time Spend %d:%d",(int)timespend/60,(int)timespend%60);
    gotoxy(28,12);
    cprintf("Enter Your Name: ");
    gets(plname);


    gotoxy(28,14);
    textattr(128+GREEN);
    cprintf("Press Enter to Countinue..");

    choice=getch();

	if(choice==13)
	{
		saveRecord(plname);
		timespend=0;
	}
	else
	{
		mainSdk();
		timespend=0;
	}

  }
  else
  {
     gotoxy(28,9);
     cprintf("Sorry You are FaiL..");
     gotoxy(28,11);
     cprintf("Better Luck Next Time..");
     gotoxy(28,13);
     textattr(128+RED);
     cprintf("Press Enter to Countinue..");

     choice=getch();

    if(choice==13)
    {
    selectLvl();
    }
    else
    {
    mainSdk();
    }
  }

getch();
}


/*Check Row if number is exist in row then return 0 otherwise return 1*/

int checkRow(int r,int c,char v)
{
   int i,j;

   for(i=r;i<=r;i++)  //check row
   {
	for(j=0;j<9;j++)
	{
		if(opsdk[i][j]==(char)v)
		{
		return 0;
		}
	}
   }
   return 1;
}

//Check Column  if number is exist in column then it return 0 otherwise 1

int checkColumn(int r,int c,char v)
{
int i,j;

   for(i=0;i<9;i++)   //check column
   {
	for(j=c;j<=c;j++)
	{
		if(opsdk[i][j]==(char)v)
		{
		return 0;
		}
	}
   }
  return 1;
 }

// check Grid

int checkGrid(int r,int c,char v)
{
int i,j;

   if(r>=0 && r<3)
   {
	if(c>=0 && c<3)
	{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
			return 0;
			}
		}
	}
	}
	else if(c>=3 && c<6)
	{
	for(i=0;i<3;i++)
	{
		for(j=3;j<6;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
				return 0;
			}
		}
	}
	}
	else if(c>=6 && c<9)
	{
	for(i=0;i<3;i++)
	{
		for(j=6;j<9;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
			return 0;
			}
		}
	}
	}
    }

   if(r>=3 && r<6)
   {

	if(c>=0 && c<3)
	{
	for(i=3;i<6;i++)
	{
		for(j=0;j<3;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
			return 0;
			}
		}
	}
	}
	else if(c>=3 && c<6)
	{
	for(i=3;i<6;i++)
	{
		for(j=3;j<6;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
				return 0;
			}
		}
	}
	}
	else if(c>=6 && c<9)
	{
	for(i=3;i<6;i++)
	{
		for(j=6;j<9;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
			return 0;
			}
		}
	}
	}

   }

  if(r>=6 && r<9)
   {

   if(c>=0 && c<3)
	{
	for(i=6;i<9;i++)
	{
		for(j=0;j<3;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
			return 0;
			}
		}
	}
	}
	else if(c>=3 && c<6)
	{
	for(i=6;i<9;i++)
	{
		for(j=3;j<6;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
				return 0;
			}
		}
	}
	}
	else if(c>=6 && c<9)
	{
	for(i=6;i<9;i++)
	{
		for(j=6;j<9;j++)
		{
			if(opsdk[i][j]==(char)v)
			{
			return 0;
			}
		}
	}
	}
   }

return 1;

}

int toNum(int num)
{
    if(num==49)
	 return 1;

    else if(num==50)
	return 2;

    else if(num==51)
	return 3;

    else if(num==52)
	return 4;

     else if(num==53)
	return 5;

    else if(num==54)
	return 6;

    else if(num==55)
	return 7;

     else if(num==56)
	return 8;

    else if(num==57)
	return 9;

}


/* to display record */
void record()
{
   char plnm[20];
   int i,k=6,j;
   char *temp="rcdlvl";
   char *lvl[5]={"1","2","3","4","5"};
   char filenm[20]={"rcdlvl"};
   char *ext=".txt";
   float timesp;
   FILE *fp;

  system("cls");
  header();

   for(j=0;j<5;j++)
   {
  strcat(filenm,lvl[j]);
  strcat(filenm,ext);

  fp=fopen(filenm,"r");
  fscanf(fp,"%s%f",&plnm,&timesp);

   textcolor(3+j);
   gotoxy(1,k);
   cprintf(" Level %d ",j+1);
   gotoxy(1,k+1);
   cprintf(" Player Name: %s",plnm);
   gotoxy(1,k+2);
   cprintf(" Time Spend[%d:%d]",(int)timesp/60,(int)timesp%60);
   if((timesp/60)<=2)
   {
   textattr(128+GREEN);
   cprintf("Excellent");
   }
   textcolor(3+j);
   gotoxy(1,k+3);
   cprintf("-----------------------------------------------");
   k+=4;
   fclose(fp);
   strcpy(filenm,temp);
  }

     getch();
     mainSdk();
}

/* to Save Record*/
void saveRecord(char plname[20])
{
    float timesp;
    char plnm[20];
    char *temp="rcdlvl";
    char *lvl[5]={"1","2","3","4","5"};
    char filenm[20]={"rcdlvl"};
    char *ext=".txt";

    FILE *fp;

  strcat(filenm,lvl[level-1]);
  strcat(filenm,ext);

    fp=fopen(filenm,"r");
    gotoxy(40,10);

    system("cls");
    header();

     fscanf(fp,"%s%f",&plnm,&timesp);
	  if(timespend<=timesp)
	  {
		timesp=timespend;
		fclose(fp);

		fp=fopen(filenm,"w");
		fprintf(fp,"%s\n%f",plname,timesp);
		fclose(fp);
	  }

     fclose(fp);
     level=NULL;
     mainSdk();
}

// View Solution of perticuler level thet passed in argument
void viewSolution(char arr[9][9],char solarr[9][9])
{
char choice;
int temp;
int i,j,m=0,l=0,count=0;
char v;

int checkr=0;
int checkc=0;
int checkg=0;

system("cls");

for(i=0;i<9;i++)
{
	for(j=0;j<9;j++)
	{

		if(arr[i][j]==NULL)
		{
		goto Check;
		}
		else
		{
		count++;
		}
	}
}

if(count==81)
{
header();
box();
	for(i=0;i<9;i++)
	{
	m=m+2;
	l=0;
		for(j=0;j<9;j++)
		{
		l=l+3;
		gotoxy(25+l,6+m);
		if(solarr[i][j]==NULL)
		{
		textcolor(RED);
		cprintf("%c",arr[i][j]);
		}
		else
		{
		textcolor(WHITE);
		cprintf("%c",arr[i][j]);

		}
		}
		printf("\n");
	}

  k=0;
  gotoxy(27,6);
  textattr(128+GREEN);
  cprintf("Press Any Key............");
  choice=getch();
  switch(choice)
  {
	default:
		selectLvl();
		break;
  }
}

Check :
for(v=49;v<58;v++)
{

     checkr=checkRow(i,j,v);
     checkc=checkColumn(i,j,v);
     checkg=checkGrid(i,j,v);

     if(checkr==1 && checkc==1 && checkg==1)
     {
     opsdk[i][j]=v;
     st[k].r=i;
     st[k].c=j;
     st[k].value=v;
     k++;
     viewSolution(opsdk,solarr);
     }

     else if(v==57)
     {
	k--;
	checkV:
	if(st[k].value==57)
	{
	  opsdk[st[k].r][st[k].c]=NULL;
	  k--;
	  goto checkV;
	}

     incV:
     st[k].value+=1;
     checkr=checkRow(st[k].r,st[k].c,st[k].value);
     checkc=checkColumn(st[k].r,st[k].c,st[k].value);
     checkg=checkGrid(st[k].r,st[k].c,st[k].value);

     if(checkr==1 && checkc==1 && checkg==1)
     {
	opsdk[st[k].r][st[k].c]=st[k].value;
	k++;
	viewSolution(opsdk,solarr);
     }
     else if(st[k].value==57)
     {
      opsdk[st[k].r][st[k].c]=NULL;
      k--;
      goto checkV;
     }
     else
     {
      goto incV;
     }

     }
}

}

/* to display how to play */
void howToPlay()
{
int i;
char choice;
system("cls");
header();

gotoxy(1,7);
textcolor(9);
cprintf("HOW TO PLAY");
gotoxy(27,8);
textcolor(RED);
cprintf("Playing Rules:\n");
textcolor(BLUE);
gotoxy(27,9);
cprintf("Fill in the grid so that every row,");
gotoxy(27,10);
cprintf("column, and 3x3 box contains digits");
gotoxy(27,11);
cprintf("1 through 9.");
textcolor(15);
	gotoxy(26,7);
	cprintf("%c",218);//print Right upper Corner

	for(i=27;i<=61;i++)
	{
	gotoxy(i,7);
	cprintf("%c",196);//print Upper Line
	}

	gotoxy(62,7);
	cprintf("%c",191);//print Left Upper Corner

	for(i=8;i<=12;i++)
	{
	gotoxy(26,i);
	cprintf("%c",179);//print right side line
	}

       for(i=8;i<=12;i++)
	{
	gotoxy(62,i);
	cprintf("%c",179);//print left side line
	}

	gotoxy(26,12);
	cprintf("%c",192);//print bottm right corner

	for(i=27;i<=61;i++)
	{
	gotoxy(i,12);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(62,12);
	cprintf("%c",217);//print bottom left corner*/


gotoxy(3,14);
textcolor(RED);
cprintf("Move:\n");
textcolor(BLUE);
gotoxy(3,16);
cprintf("To move press any key ");
gotoxy(3,17);
cprintf("from keyboard.");
gotoxy(3,19);
cprintf("Use arrow keys to move");
gotoxy(3,20);
cprintf("double");
textcolor(15);
	gotoxy(2,13);
	cprintf("%c",218);//print Right upper Corner

	for(i=3;i<=25;i++)
	{
	gotoxy(i,13);
	cprintf("%c",196);//print Upper Line
	}

	gotoxy(26,13);
	cprintf("%c",191);//print Left Upper Corner

	for(i=14;i<=23;i++)
	{
	gotoxy(2,i);
	cprintf("%c",179);//print right side line
	}

       for(i=14;i<=23;i++)
	{
	gotoxy(26,i);
	cprintf("%c",179);//print left side line
	}

	gotoxy(2,23);
	cprintf("%c",192);//print bottm right corner

	for(i=3;i<=25;i++)
	{
	gotoxy(i,23);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(26,23);
	cprintf("%c",217);//print bottom left corner



gotoxy(31,15);
textcolor(RED);
cprintf("About:\n");
textcolor(BLUE);
gotoxy(31,16);
cprintf("Developed By:");
gotoxy(31,17);
cprintf("   Bheda Vishal");
gotoxy(31,18);
cprintf("Submit To:");
gotoxy(31,19);
cprintf("   Gujarat Technical University");
textcolor(15);
	gotoxy(30,14);
	cprintf("%c",218);//print Right upper Corner

	for(i=31;i<=75;i++)
	{
	gotoxy(i,14);
	cprintf("%c",196);//print Upper Line
	}

	gotoxy(76,14);
	cprintf("%c",191);//print Left Upper Corner

	for(i=15;i<=20;i++)
	{
	gotoxy(30,i);
	cprintf("%c",179);//print right side line
	}

       for(i=15;i<=20;i++)
	{
	gotoxy(76,i);
	cprintf("%c",179);//print left side line
	}

	gotoxy(30,21);
	cprintf("%c",192);//print bottm right corner

	for(i=31;i<=75;i++)
	{
	gotoxy(i,21);
	cprintf("%c",196);//print bottom line
	}

	gotoxy(76,21);
	cprintf("%c",217);//print bottom left corner*/


choice=getch();
switch(choice)
{
	default :
		mainSdk();
}

}

/*THE END*/



