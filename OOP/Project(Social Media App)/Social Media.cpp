#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Uid {
private:
	string id;
	static int post;
	static int comment;
	static int page;
	static int user;
public:
	string getId() const
	{
		return id;
	}

	Uid(string initial) //initiaiser is used to differentiate between pot, comments etc
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
		else if (initial == "C")
		{
			id = initial + to_string(comment);
			comment++;
		}
	}
};

int Uid::comment = 0;
int Uid::page = 0;
int Uid::user = 0;
int Uid::post = 0;


int main()
{
	Uid u1("U");
	Uid u2("U");
	Uid p1("P");
	cout << u1.getId() << " " << u2.getId() << " " << p1.getId();
}