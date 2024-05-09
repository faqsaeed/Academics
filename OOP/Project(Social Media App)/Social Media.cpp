#include <iostream>
#include <vector>
#include <string>
#include <ctime>
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
		
		int val = rand() % 100;
		
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

class Post: public Uid{
private:
	time_t t;// time add krna hai bc fujtionality requires so :(
	string text;
	string* likes = new string[10]; // might replace it with user ki array ;<
public:
	Post(string Text) :Uid("P"), text(Text) {}

	string getText() const
	{
		return text;
	}
	 
	~Post()
	{
		delete[] likes;
		likes = nullptr;
	}
};

class User : public Uid {
private:
	User** friends = new User * [MAX];
	string name;
	Post** post = new Post * [MAX];
	int posts = 0;
public:
	User(string Name) : Uid("U"), name(Name) {}

	void createPost(string text)
	{
		post[posts] = new Post(text);
		posts++;
	}

	string getName() const
	{
		return name;
	}

	void printPost() const
	{
		for (int i = 0; i < posts; ++i)
		{
			cout << post[i]->getId() << endl << post[i]->getText() << endl;
		}
	}
};


int Uid::page = 0;
int Uid::user = 0;
int Uid::post = 0;


int main()
{
	User u1("Faiq");
	User u2("Ali");
	cout << u1.getId() << endl << u2.getId() << endl;
	u1.createPost("General Asim Munir");
	u2.createPost("Pakitan Zindabad");
	u1.createPost("PTI lai loi");
	u2.createPost("Pak Debate Forum");
	u1.printPost();
	u2.printPost();
}