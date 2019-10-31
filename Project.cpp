#include <iostream>//input /output statements
#include <string>//string library
#include <fstream>//file handling
#include <sstream>//string management
#include <ctime>//importing time

using namespace std;
struct record //attributes to record books
{
	string	name;//name
	string author;//author
	string 	id;//id
	int copy;//copy
};
struct issues //attributes of issued books
{
	string stu;//student
	string boo;//book
	string date;//date
};
class all  //this function will generate current date
{
	public:
		record book[50];
		issues student[50];
		int a,b,m,n,o;		
		all() //constructor for global variables
		{
			a=0;
			b=0;
			time_t t= time(NULL);//time
			tm* now = localtime(&t);//local time
			m=now->tm_mday;
			n=(now->tm_mon + 1) ;
			o=(now->tm_year + 1900);
		}
		void menu() //GUI i.e main menu
		{
			cout<<"1. RECEPTION MENU"<<endl<<endl<<"2. LIBRARIAN MENU"<<endl<<endl<<"3. EXIT"<<endl<<endl<<"CHOOSE OPTION . . ."<<endl<<endl;
			int u;
			cin>>u;
			system("cls");
			if(u==1)
			{
				string q;
				do
				{
					cout<<"PASSWORD: ";
					cin>>q;
					if(q=="password") //password to enter reception menu
					{
						login_rec();
					}
					else
					{
						cout<<"WRONG PASSWORD,AGAIN ENTER ";
					}
				}while(-1);
			}
			if(u==2)
			{
				login_lib(); //to login to librarian menu	
			}
			if(u==3)
			{
				save();
				exit(0);
			}
			menu();
		}
		void login_rec() //reception  menu
		{
			cout<<"___RECEPTION LOGIN___"<<endl<<endl<<"1. ISSUE BOOK"<<endl<<endl<<"2. DIPOSIT BOOK"<<endl<<endl<<"3. BACK TO MAIN MENU"<<endl<<endl<<"4. EXIT"<<endl<<endl<<"CHOOSE OPTION . . .";
			int w;
			cin>>w;
			if(w==1)
			{
				string x,y;
				cout<<"ENTER NAME OF STUDENT: ";//enter name
				getline(cin >>ws,x);
				cout<<"ENTER BOOK: ";
				getline(cin >>ws,y);
				issue(x,y);
			}
			if(w==2)
			{
				returned();
			}
			if(w==3)
			{
				menu();	
			}
			if(w==4)
			{
				save();//saving changes and updates
				exit(0);
			}
			if(w<1 || w>4) //restriction to put numbers from 1 to 4
			{
				cout<<"YOU CAN CHOOSE ONLY 1-4"<<endl<<endl;
				login_rec();
			}
			
			login_rec();
		}
		void login_lib()
		{
			system("cls");
			string user,pass;
			cout<<"USERNAME: ";
			cin>>user;
			cout<<"PASSWORD: ";
			cin>>pass;
			cout<<endl;
			string username,password;
			ifstream admin;
			admin.open("admin.txt");
			string line;
			int t=0;
			while(getline(admin,line))
			{
				stringstream ad(line); //it associates string with stream (seperation with commas)
				getline(ad,username,',');
				getline(ad,password,',');
				if(user==username && pass==password)
				{

					cout<<"YOU ARE SUCCESSFULLY LOGGED IN . . ."<<endl<<endl;
					system("cls"); //to clear screen
					int x;
					do
					{	//choice of option
						cout<<"1. SHOW BOOKS"<<endl<<endl<<"2. ADD BOOKS"<<endl<<endl<<"3. EDIT BOOK"<<endl<<endl<<"4. DELETE BOOK"<<endl<<endl<<"5. SEARCH BOOK"<<endl<<endl<<"6. STUDENT RECORD"<<endl<<endl<<"7. BACK TO MAIN MENU"<<endl<<endl<<"8. EXIT FROM PROGRAM"<<endl<<endl<<"CHOOSE OPTION . . ."<<endl;
						cin>>x;
						system("cls");
						if(x==1)
						{
							show();		
						}
						if(x==2)
						{
							add();		
						}
				
						if(x==3)
						{
							show();
							edit();		
						}
						if(x==4)
						{
							show();
							del();			
						}
						if(x==5)
						{
							search();
						}
				
						if(x==6)
						{
							s_record();
						}
						if(x==7)
						{
							menu();
						}
						if(x==8)
						{
							save();
							exit(0);
						}
					
					}while(-1);
				}
				else
				{
					t++;
				}
			}
			if(t!=0)
			{
				cout<<"WRONG USERNAME OR PASSWORD"<<endl<<endl<<"1. ENTER AGAIN"<<endl<<"... BACK TO MAIN MENU . ."<<endl<<endl;
				char c;
				cin>>c;
				system("cls");
				if(c=='1')
				{
					login_lib();
				}
				else
				{
					menu();	
				}
			}
		}
		void load()  //to get information about book from file (storing strings in varibles(to array))
		{
			string names,authors,ids,copies;
			string line,word;
			int co;
			ifstream file;
			file.open("book.txt");
			int i=0;
			while(getline(file,line))
			{
				stringstream s(line);
				getline(s,names,',');
				book[i].name=names;
				getline(s,authors,',');
				book[i].author=authors;
				getline(s,ids,',');
				book[i].id=ids;
				getline(s,copies,',');
				stringstream ss(copies);
				ss>>co;
				book[i].copy=co;
				i++;
				a++;
			}
			string stud,books,dates;
			ifstream students;
			students.open("students.txt");
			int j=0;
			string words;
			while(getline(students,words))
			{
				stringstream sss(words);
				getline(sss,stud,',');
				student[j].stu=stud;
				getline(sss,books,',');
				student[j].boo=books;
				getline(sss,dates,',');
				student[j].date=dates;
				j++;
				b++;
			}
			file.close();
		}
		void save() //to store book information in file
		{
			string names,authors,ids;
			int copies;
			ofstream file;
			file.open("book.txt");
			int i=0;
			while(i<a)
			{
				names=book[i].name;
				authors=book[i].author;
				ids=book[i].id;
				copies=book[i].copy;
				file<<names<<","<<authors<<","<<ids<<","<<copies<<endl<<endl;
				i++;
			}
			string stud,books,dates;
			ofstream students;
			students.open("students.txt");
			int j=0;
			while(j<b)
			{
				stud=student[j].stu;
				books=student[j].boo;
				dates=student[j].date;
				students<<stud<<","<<books<<","<<dates<<endl<<endl;
				j++;
			}
			students.close();
			file.close();	
		}
		void show() //to show all available books
		{
			cout<<"    NAME                  AUTHOR                  ID         COPIES"<<endl;
			for(int i=0;i<a;i++)
		 	{
				cout<<i+1<<". "<<book[i].name<<"           "<<book[i].author<<"           "<<book[i].id<<"          "<<book[i].copy<<endl;
			}	
		}
		void add() //to add new books
		{
			string g,h,j;
			int k;
			cout<<"ENTER NAME OF BOOK: ";
			getline(cin >>ws,g );


			cout<<"ENTER AUTHOR OF BOOK: ";
			getline(cin >>ws,h);

			cout<<"ENTER ID OF BOOK: ";
			cin>>j;

			cout<<"ENTER COPIES OF BOOK: ";
			cin>>k;
			int r=0;
			for(int i=0;i<a;i++)
			{
				if((g==book[i].name)||(j==book[i].id))
				{
					r++;
				}
			}
			if(r==0)
			{
				book[a].name=g;
				book[a].author=h;
				book[a].id=j;
				book[a].copy=k;
				cout<<"YOUR BOOK IS ADDED SUCCESSFULLY"<<endl<<endl;
				a++;
			}
			else
			{
				cout<<"BOOK IS ALREADY ADDED, ENTER DETAILS AGAIN"<<endl<<endl;
				add();
			}
			char p;
			cout<<"DO YOU WANT TO ENTER ANOTHER BOOK('y' for 'YES' and any other letter for 'NO')";
			cin>> p;
			if(p=='y')
			{
				add();
			}
		}
		void edit()  //to edit 
		{
			string g,h,j;
			int y,k;
			cout<<"CHOOSE BOOK YOU WANT TO EDIT: ";
			cin>>y;
			cout<<endl;
			if(y<=a)
			{
				cout<<"      ENTER NEW DETAILS      "<<endl;
				cout<<"NAME: ";
				getline(cin >>ws,g);
	
				cout<<"AUTHOR: ";
				getline(cin >>ws,h );
	
				cout<<"ID: ";
				cin>>j;
	
				cout<<"COPIES: ";
				cin>>k;
				int r=0;
				for(int i=0;i<a;i++)
				{
					if((g==book[i].name)||(j==book[i].id))
					{
						r++;
					}
				}
				if(r==0)
				{
					book[y-1].name=g;
					book[y-1].author=h;
					book[y-1].id=j;
					book[y-1].copy=k;
					cout<<"YOU EDITTED THE BOOK"<<endl<<endl;
				}
				else
				{
					cout<<"BOOK IS ALREADY ADDED, ENTER DETAILS AGAIN"<<endl<<endl;
					edit();
				}
			}
			else
			{
				cout<<"BOOK DOES NOT EXIST"<<endl<<endl;
				edit();
			}
		}
		void del() //to delet books from record
		{
			int y;
			cout<<"CHOOSE BOOK TO BE DELETED: ";
			cin>>y;
			if(y<=a)
			{
				book[y-1].name=book[a-1].name;
				book[y-1].author=book[a-1].author;
				book[y-1].id=book[a-1].id;
				book[y-1].copy=book[a-1].copy;
			}
			else
			{
				cout<<"     BOOK DOES NOT EXIST"<<endl<<endl;
			}
			a--;
		}
		void search() //to search book by name
		{
			int y;
			cout<<"SEARCH BOOK BY: "<<endl<<"1. NAME"<<endl<<"2. AUTHOR"<<endl;
			cin>>y;
			if(y==1)
			{
				string n;
				int z=0;
				cout<<"ENTER NAME OF BOOK: ";
				getline(cin>>ws,n);
				for(int i=0;i<a;i++)
				{
					if(book[i].name==n)
					{
						z++;
					}
				}
				if(z==0)
				{cout<<"_SORRY, NO BOOKS FOUND_"<<endl<<endl;}
				else
				{
					cout<<"BOOK #       NAME                AUTHOR          ID           COPIES           SHELF NO."<<endl;
					for(int i=0;i<a;i++)
					{
						if(book[i].name==n)
						{
							cout<<i+1<<"         "<<book[i].name<<"          "<<book[i].author<<"     "<<book[i].id<<"           "<<book[i].copy<<"                "<<(i/20)+1<<endl;
						}
					}
					cout<<endl;
				}
			}
			if(y==2)
			{
				string n;
				int z=0;
				cout<<"ENTER AUTHOR OF BOOK: ";
				getline(cin>>ws,n);
				for(int i=0;i<a;i++)
				{
					if(book[i].author==n)
					{
						z++;
					}
				}
				if(z==0)
				{cout<<"_SORRY, NO BOOKS FOUND_"<<endl<<endl;}
				else
				{
					cout<<"BOOK #       NAME                AUTHOR          ID           COPIES           SHELF NO."<<endl;
					for(int i=0;i<a;i++)
					{
						if(book[i].author==n)
						{
							cout<<i+1<<"         "<<book[i].name<<"          "<<book[i].author<<"     "<<book[i].id<<"           "<<book[i].copy<<"                "<<(i/20)+1<<endl;
						}
					}
					cout<<endl;
				}
			}
		}
		void issue(string x,string y)  //to issue  book
		{
			string z;
			string q,w,e;
			int f,g,h;
			cout<<"ENTER DATE(dd/mm/yyyy): ";
			cin>>z;
			stringstream s(z);
			getline(s,q,'/');
			stringstream ss(q);
			ss>>f;
			getline(s,w,'/');
			stringstream sss(w);
			sss>>g;
			getline(s,e,'/');
			stringstream ssss(e);
			ssss>>h;
			if((f<=31 && f>0)&&(g<=12 && g>0)&&(h>=2019))
			{
				int t=0,r=0;
				char p;
				for(int i=0;i<a;i++)
				{
					if(book[i].name==y)
					{
						t++;
						break;
					}
					r++;
				}
				if(t!=0 && book[r].copy!=0)
				{
					cout<<"DO YOU WANT TO VIEW COPIES OF BOOK('y' for '_YES_' and any other letter for '_NO_')";
					cin>>p;
					if(p=='y')
					{
						for(int v=0;v<a;v++)
						{
							if(book[v].name==y)
							{
								cout<<"BOOK HAS "<<book[v].copy<<" COPIES"<<endl;
							}
						}
					}
					student[b].stu=x;
					student[b].boo=y;
					student[b].date=z;
					cout<<"YOUR BOOK IS ISSUED"<<endl<<endl;
					b++;
					book[r].copy=book[r].copy-1;
				}
				
				if(t==0 || book[r].copy==0)
				{
					cout<<"BOOK IS NOT AVAILABLE"<<endl<<endl;
				}
			}
			else
			{
				cout<<"INVALID DATE, AGAIN ";
				issue(x,y);
				
			}
		}
		void returned()
		{
			string x;
			cout<<"BOOK NAME: ";
			getline(cin>>ws,x);
			int r=0;
			for(int i=0;i<a;i++)
			{
				if(x==book[i].name)
				{
					r++;
					book[i].copy=book[i].copy+1;
					break;
				}
			}
			int t=0;
			for(int i=0;i<a;i++)
			{
				if(x==student[i].boo)
				{
					t++;
					break;
				}
			}
			string q,w,e;
			string temp;
			int f,g,h;
			for(int j=0;j<b;j++)
			{
				if(x==student[j].boo)
				{
					temp=student[j].boo;
					break;
				}
			}
			stringstream s(temp);
			getline(s,q,'/');
			stringstream ss(q);
			ss>>f;
			getline(s,w,'/');
			stringstream sss(w);
			sss>>g;
			getline(s,e,'/');
			stringstream ssss(e);
			ssss>>h;
			if(r!=0 )
			{
				if(t!=0)
				{
					if((o>h) || (o==h && n>g) || (o==h && n==g && m>f))
					{
						cout<<"STUDENT IS FINED Rs. 10"<<endl<<endl;
					}
				}
				else
				{
					cout<<"___BOOK HAS NOT BEEN BORROWED___"<<endl<<endl;
				}				
			}
			else
			{
				cout<<"___BOOK MAY NOT EXIST IN LIBRARY___"<<endl<<endl;
			}
		}
		void s_record()
		{
			string iden;
			cout<<"ENTER STUDENT NAME OF WHOM YOU WANT TO SEE RECORD: ";
			cin>>iden;
			int r=0;
			for(int i=0;i<b;i++)
			{
				if(student[i].stu==iden)
				{
					r++;
				}
			}
			if(r!=0)
			{
				cout<<"STUDENT NAME         BOOK NAME                 DUE DATE"<<endl;
				for(int j=0;j<b;j++)
				{
					if(student[j].stu==iden)
					{
	
						cout<<student[j].stu<<"              "<<student[j].boo<<"               "<<student[j].date<<endl;
					}
				}
			}
			else
			{
				cout<<"STUDENT HAS NOT BORROWED ANY BOOK FROM LIBRARY"<<endl<<endl;
			}
		}
};
//MAIN RUNS HERE//
int main()
{
	int x;
	all obj;
	obj.load();
	cout<<"___WELCOME TO OUR LIBRARY MANAGEMENT SYSTEM___"<<endl<<endl;
	obj.menu();
	system("cls");
	obj.save();
	return 0;
}
//THE END//
