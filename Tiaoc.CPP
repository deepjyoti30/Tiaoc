#define _WIN32_WINNT 0x0500
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
using namespace std;
int main();

bool flag=0;

Changelog(){
	system("cls");
	system("Color 5A");
	char read;
	//This function shows the changelog at the beginning.
	fstream fs("changelog.txt",ios::in);
	while(!fs.eof()){
		fs.get(read);
		cout<<read;
	}
	flag=1;
	cout<<"\n\n\t\t\tPress any key if you're done";
	_getch();
}

	Resize(){
		HWND console=GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, 680, 600, TRUE);
	}

class Temp
	{
		char st[10];int plyr,k;
		public:
			Take_temp(int pos,int no,int ply)
				{
					plyr=ply;
				//	for(int i=0;i<10;i++)
						st[pos]=no;
					cout<<"\nData taking complete";
				}
			int Return_temp(int i)
				{
						return st[i];
				}
			Take_k(int no)
				{
					k=no;
				}
			int Return_k()
				{
					return k;
				}
			int return_plyr()
				{
					return plyr;
				}
	};

Temp t;char chi='a';

int Ask()
	{
		Resize();
		fstream fl("Game_pause.dat",ios::in);
		system("cls");
		system("Color 80");
		if(!fl)
			{
				while(1)
				{
				char choice;
				cout<<"\n\t\t\tWhom do you want to play with?\n\t\t\t1:Computer\n\t\t\t2:Person\n\t\t\t";
				cin>>choice;
				if(choice=='1')
					return 1;	
				else if(choice=='2')
							return 0;
						 else
							cout<<"\n\t\t\t||||INVALID OPTION||||\a";
				}
			}
		else
			{
				cout<<"\n\t\t\t*****Saved Game found!*****\n\t\t\tWould you like to continue?? \n\t\tPress Y if Yes, else press any key to Start new";
				//gets(chi);
				cin>>chi;
				if(chi=='Y')
					{
						fl.read((char*)&t,sizeof(t));
						int ret=t.Return_k();
						fl.close();
						return ret;
						remove("Game_pause.dat");
					}
				else
					{
						fl.close();
						remove("Game_pause.dat");
						while(1)
							{
							char choice;
							cout<<"\n\t\t\tWhom do you want to play with?\n\t\t\t1:Computer\n\t\t\t2:Person\n\t\t\t";
							cin>>choice;
							if(choice=='1')	
									return 1;
							else if(choice=='2')
										return 0;
									 else
										cout<<"\n\t\t\t||||INVALID OPTION||||\a";
							}		
					}		
			}
	}

char Return_smart(char sqr[])
	{
		if(sqr[1]=='X'){
			if(sqr[2]=='X'&&sqr[3]!='0')
				return '3';
			if(sqr[3]=='X'&&sqr[2]!='0')
				return '2';
			if(sqr[4]=='X'&&sqr[7]!='0')
				return '7';
			if(sqr[7]=='X'&&sqr[4]!='0')
				return '4';
			if(sqr[9]=='X'&&sqr[5]!='0')
				return '5';
			if(sqr[5]=='X'&&sqr[9]!='0')
				return '9';
		}
		else if(sqr[1]!='X'&&sqr[1]!='0') return '1';
		if(sqr[3]=='X'){
			if(sqr[6]=='X'&&sqr[9]!='0')
				return '9';
			if(sqr[9]=='X'&&sqr[6]!='0')
				return '6';
			if(sqr[5]=='X'&&sqr[7]!='0')
				return '7';
			if(sqr[7]=='X'&&sqr[5]!='0')
				return '5';
		}
		else if(sqr[3]!='0'&&sqr[3]!='X')
				return '3';
		if(sqr[9]=='X'){
			if(sqr[8]=='X'&&sqr[7]!='0')
				return '7';
			if(sqr[7]=='X'&&sqr[8]!='0')
				return '8';
		else if(sqr[9]!='0'&&sqr[9]!='X')
				return '9';
		}
		if(sqr[7]!='X'&&sqr[7]!=0)
			return '7';
		if(sqr[5]!='X'&&sqr[5]!='0')
			return '5';
		if(sqr[6]!='X'&&sqr[6]!='0')
			return '6';
		if(sqr[8]!='X'&&sqr[8]!='0')
			return '8';
		if(sqr[4]!='X'&&sqr[4]!='0')
			return '4';
		if(sqr[2]!='X'&&sqr[2]!='0')
			return '2';
		else return '0';
	}
Exit_Animation()
	{
		Resize();
		system("cls");
		system("Color 20");
		string Exit="\n================================================================================\n================================================================================\n\t\t\t\t   THANKS!!!                                    \n\t\t\t     FOR TRYING OUT OUR GAME                             \n================================================================================\n================================================================================";
		int x=0;
		while(Exit[x]!='\0')
			{
				cout<<Exit[x];
				Sleep(1);
				x++;
			}
	}

int Exit_by_saving(char sqr[],int plyr,int no)
	{
		Resize();
		int ch;
		cout<<"\n\t\t    Are you sure you want to exit at this stage??\n\t\t    Do you want to keep the games progress??\n\t\t    1:Yes\n\t\t    2:No\n\t\t    3:Go back to Game\n\t\t\t     *******NOTE******\n\t\t     DO NOT ENTER CHARACTER, only a number ";
		cin>>ch;
		if(ch==1)
			{
				fstream fi("Game_pause.dat",ios::out|ios::trunc);
				for(int k=0;k<10;k++)
					t.Take_temp(k,sqr[k],plyr);
				t.Take_k(no);
				fi.write((char*)&t,sizeof(t));
				cout<<"\n\t\t\tDone saving data!";
				fi.close();
				main();
				return 1;
			}
		else if(ch==2)
			{
				Exit_Animation();
				exit(0);
			}
			 else if(ch==3)
			 	return 0;
	}

int Check_plyr()
	{
		fstream fp("Game_pause.dat",ios::in);
		if(!fp)
			return 1;
		else
			{
				if(chi=='Y')
				{
					fp.read((char*)&t,sizeof(t));
					return t.return_plyr();
					fp.close();	
				}
				else
					return 1;
			}
	}

int Check_n_return(int i)
	{
		char st[10];
		char sqr[10] = {'o','1','2','3','4','5','6','7','8','9'};
		fstream fo("Game_pause.dat",ios::in);
		if(fo)
			if(i==0)
				{
					if(chi=='Y')
						{
							fo.read((char*)&t,sizeof(t));
						    for(int j=0;j<10;j++)
								st[j]=t.Return_temp(j);
							fo.close();	
							remove("Game_pause.dat");
						}			
				}
		if(chi=='Y')
			{
			if(i==9)
				chi='a';
			return st[i];
			}
		else
			{
			if(i==9)
				chi='a';
			return sqr[i];		
			}		
	}
int winchck(char sqr[])
			{
				if (sqr[1] == sqr[2] && sqr[2] == sqr[3])
					return 1;
				else if (sqr[4] == sqr[5] && sqr[5] == sqr[6])
					return 1;
				else if (sqr[7] == sqr[8] && sqr[8] == sqr[9])
					return 1;
				else if (sqr[1] == sqr[4] && sqr[4] == sqr[7])
					return 1;
				else if (sqr[2] == sqr[5] && sqr[5] == sqr[8])
					return 1;
				else if (sqr[3] == sqr[6] && sqr[6] == sqr[9])
					return 1;
				else if (sqr[1] == sqr[5] && sqr[5] == sqr[9])
					return 1;
				else if (sqr[3] == sqr[5] && sqr[5] == sqr[7])
					return 1;
				else if (sqr[1] != '1' && sqr[2] != '2' && sqr[3] != '3' && sqr[4] != '4' && sqr[5] != '5' && sqr[6] != '6' && sqr[7] != '7' && sqr[8] != '8' && sqr[9] != '9')
					return 0;
				else
					return -1;
			}
		void board(char sqr[])
			{
				Resize();
				system("cls");
				system("Color 6B");
				cout << "\n\t\t\t   Player 1 (X)  -  Player 2 (O)" << endl;
				cout << endl;
			//	cout << "\t\t\t       ---------------------\n";
				cout << "\t\t\t              |     |       " << endl;
				cout << "\t\t\t              |     |       " << endl;
				cout << "\t\t\t           " << sqr[1] << "  |  " << sqr[2] << "  |  " << sqr[3] << "    \n";
				cout << "\t\t\t         _____|_____|_____  " << endl;
				cout << "\t\t\t              |     |       " << endl;
				cout << "\t\t\t              |     |       " << endl;
				cout << "\t\t\t           " << sqr[4] << "  |  " << sqr[5] << "  |  " << sqr[6] << "    \n";
				cout << "\t\t\t         _____|_____|_____  " << endl;
				cout << "\t\t\t              |     |       " << endl;
				cout << "\t\t\t              |     |       " << endl;
				cout << "\t\t\t           " << sqr[7] << "  |  " << sqr[8] << "  |  " << sqr[9] << "    \n";
				cout << "\t\t\t              |     |       " << endl ;
				cout << "\t\t\t       ---------------------\n";
				cout<<"\t\t\t   -----Press 0 to exit now!-----";
				cout<<"\n\t    ----------->>>>DO NOT PRESS ENTER AFTER INPUT<<<<-----------\n";
			}
		void Show_off(char sqr[],int plyr)
			{
				Resize();
				if (sqr[1] == sqr[2] && sqr[2] == sqr[3])
					{
						sqr[1]='--';sqr[2]='--';sqr[3]='--';
					}
				else if (sqr[4] == sqr[5] && sqr[5] == sqr[6])
					{
						sqr[4]='--';sqr[5]='--';sqr[6]='--';
					}
				else if (sqr[7] == sqr[8] && sqr[8] == sqr[9])
					{
						sqr[7]='--';sqr[8]='--';sqr[9]='--';
					}
				else if (sqr[1] == sqr[4] && sqr[4] == sqr[7])
					{
						sqr[1]='||';sqr[4]='||';sqr[7]='||';
					}
				else if (sqr[2] == sqr[5] && sqr[5] == sqr[8])
					{
						sqr[2]='||';sqr[5]='||';sqr[8]='||';
					}
				else if (sqr[3] == sqr[6] && sqr[6] == sqr[9])
					{
						sqr[3]='||';sqr[6]='||';sqr[9]='||';
					}
				else if (sqr[1] == sqr[5] && sqr[5] == sqr[9])
					{
						sqr[1]='**';sqr[5]='**';sqr[9]='**';
					}
				else if (sqr[3] == sqr[5] && sqr[5] == sqr[7])
					{
						sqr[3]='**';sqr[5]='**';sqr[7]='**';
					}
					
				system("cls");
				system("Color 6B");
				board(sqr);
			}
		
class Game
	{
		char win[80],los[80];
		int sno,plyr;
		public:
			//Game()
			//	{
			//		sno=0;
			//	}
			 returnsno()
				{
					return sno;
				}
			take_sno(int no)
				{
					sno=no;
				}
			/* static inc_sno()
			 	{
					sno++;
				}*/
			 dec_sno()
				{
					sno--;
				}
			Take_data(int ply,int k)
			{
				if(k==0)
					{
					//cout<<"\nsno after"<<sno;
					cout<<"\n\t\t\tCongrats to player "<<ply<<" !!";
					cout<<"\n\t\tEnter the winners name (5 characters only)\n\t\t\t";
					gets(win);
					gets(win);
					cout<<"\n\t\tEnter the losers name (5 characters only)\n\t\t\t";
					//cin>>los;
					gets(los);	
					}
				else
					{
						if(ply==1)
							{
							cout<<"\n\t\t  Enter winners name \\5 characters only\n\t\t\t";
							gets(win);	
							gets(win);
							cout<<"\n\t\t  Enter the loser computers name \\5 characters only\n\t\t\t";
							gets(los);
							}
						else
							{
								cout<<"\n\t\t   Enter the awesome computers name \\5 characters only\n\t\t\t";
								gets(win);
								gets(win);
								cout<<"\n\t\t   Enter losers name \\5 characters only\n\t\t\t";
								gets(los);
							//	gets(los);
							}
						
					}
				
			}
		Show_data()
			{
				cout<<"\n\t\tGame no: "<<sno<<"\tWinner: "<<win<<"\t\tLoser: "<<los<<"\n\t\t\t----------------------------------\n";
			}
	};
	
	Game g;
	//fstream fi("Saved_Games.dat",ios::in|ios::out);
	
Delete_data()
	{
		Resize();
		char o;
		char ch;
		fstream fs("Saved_Games.dat",ios::in);
		fstream f("Game_pause.dat",ios::in);
		fs.read((char*)&g,sizeof(g));
		while(1)
			{
				cout<<"\n\t\t\t  -----Choose one-----";
				cout<<"\n\t\t\t1:Delete all Paused Games";
				cout<<"\n\t\t\t2:Delete last 10 records";
				cout<<"\n\t\t\t3:Delete both\n\t\t\t";
				cout<<"Option:";
				cin>>o;
				if(o!='1'&&o!='2'&&o!='3')
					{
						cout<<"\n\t\t\t  INVALID CHOICE\a";
						getch();
					}
				if(o=='2')
				{
				g.take_sno(0);
					if(fs)
						{
							fs.close();
							remove("Saved_Games.dat");	
							cout<<"\n\t\t-----Removed Last records----";
							break;
						}
					else
						{
								cout<<"\n\t\t------No Last records----\a";
								break;	
						}	
				}
		else if(o=='1')
				{
					if(f)
						{
							f.close();
							remove("Game_pause.dat");
							cout<<"\n\t\t\t----Removed Saved Games-----";
							break;
						}
					else
						{
							cout<<"\n\t\t\t----No Saved Games-----\a";
							break;	
						}		
				}
			else if(o=='3')
			{
				cout<<"\n\n\t\t-----Are you sure you want to delete all data-----\n\t\t-----including last 10 records and Saved Games-----\n\t\t   Press Y if Yes, else press any other key for No\n\t\t\tOption:";
				cin>>ch;
				if(ch=='Y')
					{
					g.take_sno(0);
					if(fs)
						{
							fs.close();
							remove("Saved_Games.dat");	
							cout<<"\n\t\t-----Removed Last records";
							break;
						}
					else
						{
							cout<<"\n\t\t------No Last records";
						}
					if(f)
						{
							f.close();
							remove("Game_pause.dat");
							cout<<"-**-Removed Saved Games-----\a";
							break;
						}
					else
						{
							cout<<"-**-No Saved Games-----\a";
							break;	
						}		
					}
			}
			}
		
		
		//cout<<"\n\t\tRemoved the file";
		//sno=0;
	}
	
Push_data()//////////////////////////////Working!!
	{
	int no=1;
	fstream fpush("Saved_Games.dat",ios::in);
	fstream fnew("temp.dat",ios::out);	
	fpush.seekg(sizeof(g),ios::beg);
			while(no<10)
				{
				fpush.read((char*)&g,sizeof(g));
						g.take_sno(no);
						fnew.write((char*)&g,sizeof(g));
						no++;			
				}
	fnew.close();
	fpush.close();
	remove("Saved_Games.dat");
	rename("temp.dat","Saved_Games.dat");
	}	

Check_data()/////////////////////////////////Working!!!!!
	{
		fstream fchk("Saved_Games.dat",ios::in);
		fchk.seekg(9*sizeof(g),ios::beg);
		fchk.read((char*)&g,sizeof(g));
		int no=g.returnsno();
		if(no==10)
			{
				fchk.close();
				Push_data();
			}
	}
	
int Add_smart()  //takes out the last sno and returns it/////////////////////////////////////Working!!!!!
	{
		int sno;
		fstream fa("Saved_Games.dat",ios::in|ios::app);
		fa.seekg(-1*sizeof(g),ios::end);
		fa.read((char*)&g,sizeof(g));
		sno=g.returnsno();
		sno++;
		fa.close();
		return sno;	
	}
	
Save_data(int plyr,int k)   //saves the data////////////////////////////////////////////Working!!!
	{
		Check_data();
		fstream ofs("Saved_Games.dat",ios::out|ios::app);
		ofs.seekg(0,ios::end);
		//check if 10 games' data has been already saved
		int no=Add_smart();
		g.take_sno(no); 
		//file opened
		g.Take_data(plyr,k);
		ofs.write((char*)&g,sizeof(g));
		//write complete
		ofs.close();
	}
	
Read_data()//////////////////////////////////////////Working!!!
	{
		Resize();
		system("cls");
		system("Color 80");
		cout<<"\n\t\t\t------||LAST 10 RECORDS ARE||------\n";
	  ifstream ifs("Saved_Games.dat");
	  	if(!ifs)
	  		cout<<"\n\t\t\t  --------NO SAVED DATA!\a--------";
	  	else
	  		{
	  			while(ifs.read((char*)&g,sizeof(g)))
				  	{
						g.Show_data();
					//	if(ifs.eof()); break;
					}
				ifs.close();	
			}
	}
	
Gameplay()
	{
		int ret=1;char sqr[10];
		//char sqr[10] = {'o','1','2','3','4','5','6','7','8','9'};
		int plyr,q,k=0;int num;
		char chice;
		k=Ask();
		plyr=Check_plyr();
		for(int i=0;i<10;i++)
			sqr[i]=Check_n_return(i);
		//getch();
		system("cls");
			do
			{
				board(sqr);
				plyr=(plyr%2)?1:2;
				if(k==1)
					{
						if(plyr==1)
							{
								cout << "\n\t      Player " << plyr << ", enter any available number in the board :  ";
								chice=_getch();
							}
						else
							{
								cout<<"\n\t\t\t   PC returned: "<<Return_smart(sqr)<<"\n";
								_getch();
								chice=Return_smart(sqr);	
							}
					}
				else
					{
						cout << "\n\t      Player " << plyr << ", enter any available number in the board :  ";
						chice=_getch();
					}
			//	int x=returnVal('X');
				num=(plyr == 1) ? 'X' : '0' ;
				if (chice == '1' && sqr[1] == '1')
					sqr[1] = num;
				else if (chice == '2' && sqr[2] == '2')
					sqr[2] = num;
				else if (chice == '3' && sqr[3] == '3')
					sqr[3] = num;
				else if (chice == '4' && sqr[4] == '4')
					sqr[4] = num;
				else if (chice == '5' && sqr[5] == '5')
					sqr[5] = num;
				else if (chice == '6' && sqr[6] == '6')
					sqr[6] = num;
				else if (chice == '7' && sqr[7] == '7')
					sqr[7] = num;
				else if (chice == '8' && sqr[8] == '8')
					sqr[8] = num;
				else if (chice == '9' && sqr[9] == '9')
					sqr[9] = num;
				else if(chice == '0')
					{
						plyr=(plyr%2)?1:2;
						ret=Exit_by_saving(sqr,plyr,k);	
					}
				else
				{
					cout<<"\n\t\t\tInvalid move ";
					plyr--;
					cout<<"\n\t\t\tPress any key to continue";
					getch();
				}
				q=winchck(sqr);
				plyr++;
				if(ret==0)
					{
					ret=1;
					plyr--;		
					}	
			}while(q==-1);
			board(sqr);
				if(q==1)
					{
					cout<<"==>\aPlayer "<<--plyr<<" win ";
						Show_off(sqr,plyr);
						Save_data(plyr,k);
					}
				else
					cout<<"==>\a\n\t\t\tGame draw";	
	}
	
Advanced()
	{
		Resize();
		int i=0,ch;
		char s;
		system("cls");
		cout<<"\n\n\n\n\n\n";
		string welc="\t\t\t   Welcome to Advanced menu...";
		while(welc[i]!='\0')
			{
				cout<<welc[i];Sleep(50);
				i++;
			}
		Sleep(100);
		getch();
		system("cls");
		cout<<"\n\n================================================================================\n";
		cout<<"  Assume that you make a program where the user enters a range and the program ";
		cout<<"   returns all the kaprekar numbers in that range. If only the range taking and ";
		cout<<"   output part is done in main(),how many global functions do you need to make?  ";
		cout<<"                  --Enter the answer in integers from 1 to 9--                    \n\t\t\t\t\t";
		cin>>ch;
		if(ch==2)
			{
				cout<<"\n\n\t\t\t\tCongrats!";
				cout<<"\n If you made this all by coincidence and don't like programming then pls leave";
				cout<<"\n\t\t\t    1:EXIT 2:Continue";
				cin>>s;
				if(s=='1')
					exit(0);
			}
		else
			{
				ch=0;
				cout<<"\n\n\t\t\t\tWRONG ANSWER!\a";
				exit(0);
			}
		getch();
		system("cls");
		//cout<<"\n\n================================================================================\n";
		cout<<"\n\n\t\tint check_DIG(int no)\n";
		cout<<"\t\t	{					\n";
		cout<<"\t\t	int i;				\n";
			//Here the numbers number of digits are checked
		cout<<"\t\t for(i=1;i<N;i++) \n";
		cout<<"\t\t		{				\n";
		cout<<"\t\t		int y=(no/(pow(10,i)));\n";
		cout<<"\t\t			if(y==0)		   \n";
		cout<<"\t\t	 			{      		   \n";
				 		//	cout<<"\nDigit calculated!";
		cout<<"\t\t				return i;  \n";
		cout<<"\t\t				break;	   \n";	
		cout<<"\t\t			}			   \n";
		cout<<"\t\t		}					   \n";
		cout<<"\t\t	 }\n";
		cout<<"If the above is a code chunk from Kaprekar Number's program. Then what would be at the place of N?\n";
		cin>>ch;
		if(ch!=1000)
			exit(0);
		else	
			{
				cout<<"\n\t\t\tCongratulations!!!";
				getch();
				system("cls");
				cout<<"\n\n ==============================================================================\n";
				//cout<<"  Assume that you make a program where the user enters a range and the program ";
				cout<<"       You will make a great programmer! While we were in school, we were   ";
				cout<<"     dissapointed to see that not many students gave importance to C.Sci and it was";
				cout<<"  the fav subject of many just because it is easy to score.You seem to have what    we";
				cout<<" had. Passion for programming! If I am right about you then please accept  ";
				cout<<"                            \tthis challenge.                   ";
				cout<<"                 We CHALLENGE you to write a program better than";
				cout<<" ours and email it to either  \t\t of us. You can also email us for any kind of help!";
				cout<<"\t\t\t\t\t\t\t\t\t\t";
				cout<<"                                                                  \t     -Deepjyoti Barman";
				cout<<"    ==============================THANK_YOU!!!===================================";
				cout<<"\n\n";
				cout<<"                                 								 Deepjyoti    ";
				cout<<"                                                                     Rozeen    ";
				getch();
				exit(0);
			}
	}
	
About()
	{
		Resize();
		char chi;
		system("Color 80");
		//Just to show info about the app
		system("cls");
		cout<<"\n\n\t\t\t\t---->>VERSION<<---\n\t\t\t\t\t3.0\n";
		cout<<"\t\t\t\tPress c for changelog";
		cout<<"\n\n\t\t\t\t--->>DEVELOPERS<<---\n";
		cout<<"\n\t\t--->>    		  Deepjyoti Barman   		   <<---";
		cout<<"\n\t\t--->>         Rozeen Hussain(DeVile)          <<---";
		cout<<"\n\n\t\t\t  -------------XXXXXX------------";
		cout<<"\n\t\t\t   Want to take a challenge?";
		cin>>chi;
		if(chi=='c')
			Changelog();
		else if(chi=='Y') Advanced();	
	}
	
Animation1()
	{
		Resize();
		system("cls");
		system("Color 80");
		string Certify="\n\n\n\n================================================================================ -----------------------------------------------------------------------------\n ||                              CERTIFICATE                                ||\n ||                                                                         ||\n ||       This is to certify that Deepjyoti Barman and Rozeen Hussain       ||\n ||      of class XII-A has succesfully completed the project under the     ||\n ||      guidance of subject teacher Mr. Rajesh Dwivedi during the year     ||\n ||                2017-18 from Kendriya Vidyalaya Khanapara.               ||\n ||                                                                         ||\n ||                                                                         ||\n ||                                                       Deepjyoti Barman  ||\n ||                                                         Rozeen Hussain  ||\n -----------------------------------------------------------------------------  ================================================================================";
		int x=0;
		while(Certify[x]!='\0')
			{
				cout<<Certify[x];Sleep(4);
				x++;
			}	
	}
	
Animation2()
	{
		Resize();
		system("cls");
		system("Color ");
		string Ini="\n\t\t\t\t   HELLO!!!\n\t\t\t\tWELCOME TO.....";
		string Welcome="\n\t\t\t\n================================================================================  ###########################################################################\n  #           === === ====  === ===== ====  === =====  ====                 #\n  #            |   |  |      |  |   | |      |  |   |  |___                 #\n  #            |   |  |      |  ===== |      |  |   |  |                    #\n  #            |  === ====   |  |   | ====   |  =====  ====                 #\n  #                                                                         #\n  #                                                 by Deepjyoti and Rozeen #\n  #                                                   	with R.Dwivedi(sir) #\n  #                                                                   XII-A #\n  #                                                                 2017-18 #\n  ###########################################################################\n================================================================================";
		int x=0;
		while(Ini[x]!='\0')
			{
				cout<<Ini[x];Sleep(100);
				x++;	
			}
		x=0;
		while(Welcome[x]!='\0')
			{
				cout<<Welcome[x];Sleep(5);
				x++;
			}
	}
int i=0;	
First()
	{
	Animation1();
	cout<<"\n\t\t\tPRESS ANY KEY TO CONTINUE";
	getch();
	Animation2();
	cout<<"\n\t\t\tPRESS ANY KEY TO CONTINUE";
	getch();
	i++;
	}	

int main()
{
	Resize();
	char j;
	if(flag==false) Changelog();
	if(i==0)
		First();
	while(1)
		{
			system("cls");
			system("Color B4");
			cout<<"\n================================================================================";
		    cout<<"  ###########################################################################";
		    cout<<"\n  #           === === ====  === ===== ====  === =====  ====                 #";
			cout<<"\n  #            |   |  |      |  |   | |      |  |   |  |___                 #";
			cout<<"\n  #            |   |  |      |  ===== |      |  |   |  |                    #";
			cout<<"\n  #            |  === ====   |  |   | ====   |  =====  ====                 #";
			cout<<"\n  #                                                                         #";
			cout<<"\n  #                                                 by Deepjyoti and Rozeen #";
			cout<<"\n  #                                                   	with R.Dwivedi(sir) #";
			cout<<"\n  #                                                                   XII-A #";
			cout<<"\n  #                                                                 2017-18 #";
			cout<<"\n  ###########################################################################\n";
			cout<<"================================================================================";
		//	cout<<"================================================================================\n";
			cout<<"\t\t\t\t|||||ENTER CHOICE|||||";
			cout<<"\n\t\t\t1:Play Game";
			cout<<"\n\t\t\t2:Show last 10 records";
			cout<<"\n\t\t\t3:Delete data";
			cout<<"\n\t\t\t4:About";
			cout<<"\n\t\t\t5:Exit";
			cout<<"\n\t\t\t***************************";
			cout<<"\n\t\t------------->>>>ENJOY THE GAME<<<<-------------\n";
			cout<<"--------------------------------------------------------------------------------\t\t\tOption:";
			cin>>j;//j=_getch();
			switch(j)
				{
					case '1':
					//	Check_saved();
						Gameplay();cout<<"\n\t\t\t   Press any Key to continue";getch();
					break;
					case '2':
						Read_data();cout<<"\n\t\t\t    Press any key to continue";getch();
					break;
					case '3':
						Delete_data();cout<<"\n\t\t\t   Press any key to continue";getch();
					break;
					case '4':
						About();cout<<"\n\t\t\t     Press any key to exit";getch();
					break;
					case '5':
						Exit_Animation();
						exit(0);
					break;
					default:
						cout<<"\n\aINVALID CHOICE!!";
					break;
				}
		}
	}
	
/*	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT	*/


	
