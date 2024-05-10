#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

const int MAX = 10;

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
	time_t t;// time add krna hai bc fujtionality requires so :(
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
	int posts = 0;
	Page** page = new Page * [MAX];
	int pages = 0;
public:
	User(string Name) : Uid("U"), name(Name) {}

	void createPost(string text)
	{
		post[posts] = new Post(text);
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
			cout << post[i]->getText() << endl;
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
public:
	
	
	SocialMediaApp()
	{
		f.open("Data.txt");
	}
	void Run()
	{}

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
