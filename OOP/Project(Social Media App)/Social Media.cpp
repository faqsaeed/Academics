#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

const int MAX = 10;


class Date
{
private:
	int day;
	int month;
	int year;

public:

	Date()
	{
		day = 17;
		month = 4;
		year = 2024;
	}

	void setDate(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	int dateToDays() const
	{
		return year * 365 + month * 30 + day;
	}


	void displayDate() const
	{
		cout << day << "/" << month << "/" << year;
	}

	bool isSameDay(Date& other) const
	{
		return day == other.day && month == other.month && year == other.year;
	}
};

class Uid {
private:
	string id;
	static int post;
	static int page;
	static int user;
public:
	string getId() const
	{
		return id;
	}

	Uid(string initial) //initiaiser is used to differentiate between Uid of pot, comments etc
	{
		if (initial == "P")
		{
			id = initial + to_string(post);
			post++;
		}
		else if (initial == "U")
		{
			id = initial + to_string(user);
			user++;
		}
		else if (initial == "G")
		{
			id = initial + to_string(page);
			page++;
		}
	}
};

class Comment {
private:
	static int num;
	string text;
	string owner;
public:
	Comment(string txt, string id) : text(txt), owner(id) {}
};


class Post : public Uid {
private:
	Date t;
	string text;
	string* likes = new string[MAX];
	Comment** com = new Comment * [MAX];
	int comm = 0;
public:
	Post(string Text) :Uid("P"), text(Text) {}
	string getText() const
	{
		return text;
	}
	
	void setDate(int d, int m, int y)
	{
		t.setDate(d, m, y);
	}
	
	void getDate() const
	{
		t.displayDate();
	}

	void addComment(string text)
	{
		string a = this->getId();
		com[comm] = new Comment(text, a);
		comm++;
	}
	
	~Post()
	{
		delete[] likes;
		likes = nullptr;
		for (int i = 0; i < comm; ++i)
		{
			delete[] com[i];
		}
		delete[] com;
		com = nullptr;
	}
};

class Page : public Uid{
private:
	Post** post = new Post * [MAX];
	string name;
	int posts = 0;
public:
	
	Page(string Name) : Uid("G"), name(Name) {}

	string getPageName() const
	{
		return name;
	}

	void createPost(string text)
	{
		post[posts] = new Post(text);
		posts++;
	}

	~Page()
	{
		for (int i = 0; i < posts; ++i)
		{
			delete[] post[i];
		}
		delete[] post;
		post = nullptr;
	}
};

class User : public Uid{
private:
	string* friends = new string [MAX];
	string name;
	Post** post = new Post * [MAX];
	static int posts;
	Page** page = new Page * [MAX];
	static int pages;
public:
	User(string Name) : Uid("U"), name(Name) {}

	void createPost(string text, int y, int m , int d)
	{
		post[posts] = new Post(text);
		post[posts]->setDate(d, m, y);
		posts++;
	
	}

	void createPage(string txt)
	{
		page[pages] = new Page(txt);
		pages++;
	}

	string getName() const
	{
		return name;
	}

	void printPost() const
	{
		for (int i = 0; i < posts; ++i)
		{
			cout << post[i]->getId() << "\t" << name << " posted on "; 
			post[i]->getDate();
			cout << "\n\t\t" << post[i]->getText() << endl;
		}
	}
	~User()
	{
		delete[] friends;
		friends = nullptr;

		for (int i = 0; i < posts; ++i)
		{
			delete[] post[i];
		}
		delete[] post;
		post = nullptr;
	}
};

class SocialMediaApp{
private:
	User** users = new User * [MAX];
	string* password = new string[MAX];
	fstream f;
	Date today;
public:
	
	
	SocialMediaApp()
	{
		f.open("Data.txt");
		string name;
		for (int i = 0; i < MAX; ++i)
		{
			getline(f, name);
			users[i] = new User(name);
			getline(f, name);
			password[i] = name;
			for (int i = 0; i < 5; ++i)
			{
				int y, m, d;
				f >> d >> m >> y;
				string line;
				getline(f, line);
				cout << "hi\n";
				cout << line;
				users[i]->createPost(line, d, m, y);
				cout << "Hello\n";
				//users[i]->printPost();
			}
		}
	}

	int authentication()
	{
		string name, pass;
		cout << "\nEnter Username:\t";
		getline(cin, name);

		cout << "Enter Password:\t";
		getline(cin, pass);

		for (int i = 0; i < MAX; i++)
		{
			if (name == users[i]->getName() && pass == password[i])
			{
				system("CLS");
				cout << "\t\tWelcome " << users[i]->getName() << endl;
				return i;
			}
		}
		system("CLS");
		cout << "\n\t\tIncorrect Username or Password (Both Username and Password are case senstive)\nTry Again\n\n";
		authentication();
	}

	void Run()
	{
		cout << "\t\tWelcome to the Social Media App\n\n";
		int choice = 0;
		int currentUser = authentication();
		while (choice >= 0 && choice <= 10)
		{
			cout << endl;
			cout << "\tTo Change User Enter 0\n";
			cout << "\tTo Go To Home Page Enter 1\n";
			cout << "\tTo View Your Profile Enter 2\n";
			cout << "\tTo View Your Friend List Enter 3\n";
			cout << "\tTo View a Page Enter 4\n";
			//cout << "\tTo Enter 5\n";
			//cout << "\tTo Enter 6\n";
			//cout << "\tTo Enter 7\n";
			//cout << "\tTo Enter 8\n";
			//cout << "\tTo Enter 9\n";
			cout << "\tTo Exit Enter 10 or gretaer\n";
			cin >> choice;
			switch (choice)
			{
			case 0:
				cout << "\n\n\tLogged Out Succcesfully\n\n";
				cin.ignore();
				system("CLS");
				currentUser = authentication();
				continue;
				break;
			case 1:
				
				break;
			case 2:
				users[currentUser]->printPost();
				break;
			case 3:
				break;
			case 4:
				break;
			//case 5:
			//	break;
			//case 6:
			//	break;
			//case 7:
			//	break;
			//case 8:
			//	break;
			//case 9:
			//	break;
			//default:
			//	break;
			}
		}
	}
};

int Comment::num = 0;
int Uid::page = 0;
int Uid::user = 0;
int Uid::post = 0;
int User::pages = 0;
int User::posts = 0;
int main()
{
	SocialMediaApp instance;
	instance.Run();
}
