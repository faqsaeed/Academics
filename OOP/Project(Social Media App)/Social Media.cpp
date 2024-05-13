#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

const int MAX = 10; //This is the maximum limit of the number of times any functionality can be done within the programe

class Date {
private:
	int day;
	int month;
	int year;

public:

	void setDate(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	void displayDate() const
	{
		cout << day << "/" << month << "/" << year;
	}

	bool operator==(Date& rhs)
	{
		return(this->day == rhs.day && this->month == rhs.month && this->year == rhs.year);
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

	string getText() const {
		return text;
	}

	string getOwner() const {
		return owner;
	}
};

class Post : public Uid {
private:
	Date t;
	string text;
	string* likes = new string[MAX];
	Comment** com = new Comment * [MAX];
	int comm = 0;
	int like;
public:
	Post(string Text) :Uid("P"), text(Text) {}

	void makePost(string txt)
	{
		text = txt;
	}

	Date getDate() const
	{
		return t;
	}

	void displayDate() const
	{
		t.displayDate();
	}

	string getText() const
	{
		return text;
	}

	void setDate(int d, int m, int y)
	{
		t.setDate(d, m, y);
	}

	void addComment(string text)
	{
		string a = this->getId();
		com[comm] = new Comment(text, a);
		comm++;
	}

	int getlike() const
	{
		return like;
	}

	void addLike(string userID)
	{
		likes[like] = userID;
		++like;
	}

	void displayPost() const
	{
		cout << "Post ID: " << getId() << endl;
		cout << "Date: ";
		getDate().displayDate();
		cout << "\nText: " << text << endl;
		cout << "Comments:\n";
		for (int i = 0; i < comm; ++i)
		{
			cout << "Comment by " << com[i]->getOwner() << ": " << com[i]->getText() << endl;
		}
		cout << "Likes: " << getlike() << endl;
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

class Page : public Uid {
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

	Post* getPost(int index) const
	{
		return *(post + index);
	}

	int getPosts() const
	{
		return posts;
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

class User : public Uid {
private:
	string* friends = new string[MAX];
	string name;
	Post** post = new Post * [MAX];
	int posts;
	Page** likedPages = new Page * [MAX];
	int numLikedPages;
	Page** page = new Page * [MAX];
	int pages;
	int frnd;
public:
	User(string Name) : Uid("U"), name(Name)
	{
		posts = 0;
		frnd = 0;
	}

	string* returnFriends() const
	{
		return friends;
	}

	void addFriend(string user)
	{
		friends[frnd] = user;
		frnd++;
	}

	void createPost(const string& text, int d, int m, int y)
	{
		if (posts < MAX)
		{
			post[posts] = new Post(text);
			post[posts]->setDate(d, m, y);
			posts++;
		}
		else
		{
			cout << "Maximum number of posts reached." << endl;
		}

	}

	bool isPageLiked(string pageID) const
	{
		for (int i = 0; i < numLikedPages; ++i)
		{
			if (likedPages[i]->getId() == pageID)
			{
				return true;
			}
		}
		return false;
	}


	Post* getPost(int index) const
	{
		return post[index];
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
			post[i]->displayDate();
			cout << "\t'" << post[i]->getText() << "'\n";
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

class SocialMediaApp {
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
			for (int j = 0; j < 5; ++j)
			{
				int y, m, d;
				f >> d >> m >> y;
				getline(f, name);
				users[i]->createPost(name, d, m, y);
			}
			for (int j = 0; j < 3; ++j)
			{
				getline(f, name);
				users[i]->addFriend(name);
			}
		}
	}

	void viewHomeOfCurrentUser(int CurrentUser) {
		cout << "\nPosts shared by friends in the last 24 hours:\n";
		int num = 0;
		for (int i = 0; i < MAX; ++i)
		{
			string* frnd = users[CurrentUser]->returnFriends();
			if (users[i]->getId() == *(frnd + num))
			{
				num++;
				for (int j = 0; j < 5; ++j)
				{
					if (users[i]->getPost(j)->getDate() == today)
					{
						cout << users[i]->getPost(j)->getId() << "  " << users[i]->getName() << ": " << users[i]->getPost(j)->getText() << endl;
					}
				}
			}
		}

		cout << "\nPosts shared by liked pages in the last 24 hours:\n";
		for (int i = 0; i < MAX; ++i)
		{
			if (users[CurrentUser]->isPageLiked(users[i]->getId()))
			{
				for (int j = 0; j < 5; ++j)
				{
					if (users[i]->getPost(j)->getDate() == today)
					{
						cout << users[i]->getName() << ": " << users[i]->getPost(j)->getText() << endl;
					}
				}
			}
		}
	}

	void viewLikesOfPost()
	{
		string postID;
		cout << "Enter the ID of the post you want to view likes for: ";
		cin >> postID;
		for (int i = 0; i < MAX; ++i) {
			for (int j = 0; j < 5; ++j)
			{
				if (users[i]->getPost(j)->getId() == postID)
				{
					cout << "Likes for the post:\t" << users[i]->getPost(j)->getlike();
					return;
				}
			}
		}
		cout << "Post not found.\n";
	}

	void viewPost() {
		string postID;
		cout << "Enter the ID of the post you want to view: ";
		cin >> postID;

		for (int i = 0; i < MAX; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (users[i]->getPost(j)->getId() == postID) {
					users[i]->getPost(j)->displayPost();
					break;
				}
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

	void likePost(int CurrentUser)
	{
		string postID;
		cout << "Enter the ID of the post you want to like: ";
		cin >> postID;
		for (int i = 0; i < MAX; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (users[i]->getPost(j)->getId() == postID)
				{
					if (users[i]->getPost(j)->getlike() < MAX)
					{
						users[i]->getPost(j)->addLike(users[CurrentUser]->getId());
						cout << "You liked the post.\n";
						return;
					}
					else
					{
						cout << "Maximum number of likes reached for this post.\n";
						return;
					}
				}
			}
		}
		cout << "Post not found.\n";
	}

	void printFriends(int current)
	{
		string* friends = users[current]->returnFriends();
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (users[j]->getId() == friends[i])
				{
					cout << users[j]->getName() << endl;
					break;
				}
			}
		}
	}

	void commentOnPost(int current)
	{
		string postID;
		cout << "Enter the ID of the post you want to like: ";
		cin >> postID;
		string text;
		cout << "Enter the text of the comment\t";
		getline(cin, text);
		for (int i = 0; i < MAX; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (users[i]->getPost(j)->getId() == postID)
				{
					users[i]->getPost(j)->addComment(text);
				}
			}
		}
	}

	void Run()
	{
		int day, month, year;
		cout << "Enter today's date\t";
		cin >> day;
		cout << "Enter current month\t";
		cin >> month;
		cout << "Enter current year\t";
		cin >> year;
		today.setDate(day, month, year);
		system("CLS");
		cin.ignore();
		cout << "\t\tWelcome to the Social Media App\n\n";
		int choice = 0;
		int currentUser = authentication();
		while (choice >= 0 && choice <= 10)
		{
			//system("CLS");
			cout << "\nTo Change User Enter 0\n";
			cout << "To Go To Home Page Enter 1\n";
			cout << "To View Your Profile Enter 2\n";
			cout << "To View Your Friend List Enter 3\n";
			cout << "To View a Page Enter 4\n";
			cout << "To Like a Post Enter 5\n";
			cout << "To View Likes of a Post Enter 6\n";
			cout << "To Comment on a Post Enter 7\n";
			cout << "To View a Post Enter 8\n";
			cout << "To Share a Memory Enter 9\n";
			cout << "To Exit Enter 10 or greater\n";
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
				system("CLS");
				viewHomeOfCurrentUser(currentUser);
				break;
			case 2:
				system("CLS");
				users[currentUser]->printPost();
				cout << "\n\nTo go back Enter 0\n";
				break;
			case 3:
				system("CLS");
				cout << "\n\nYou have added the following people as your Friends\n\n";
				printFriends(currentUser);
				break;
			case 4:
				break;
			case 5:
				system("CLS");
				likePost(currentUser);
				break;
			case 6:
				system("CLS");
				viewLikesOfPost();
				break;
			case 7:
				system("CLS");
				commentOnPost(currentUser);
				break;
			case 8:
				system("CLS");
				viewPost();
				break;
			case 9:
				break;
			default:
				return;
				break;
			}
		}
	}
};

int Comment::num = 0;
int Uid::page = 0;
int Uid::user = 0;
int Uid::post = 0;

int main()
{
	SocialMediaApp instance;
	instance.Run();
}