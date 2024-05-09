#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Page{};
class Comment{};
class Post{};

class User {
private:
    int id;
    string name;
    vector<User*> friendList;
    vector<Page*> likedPages;

public:
    User(int _id, const string& _name) : id(_id), name(_name) {}

    void ViewFriendList() {
        cout << name << " - Friend List\n";
        for (User* friendUser : friendList) {
            cout << friendUser->GetId() << " - " << friendUser->GetName() << endl;
        }
    }

    void ViewLikedPages() {
        cout << name << " - Liked Pages\n";
        for (Page* page : likedPages) {
            cout << page->GetId() << " - " << page->GetTitle() << endl;
        }
    }

    int GetId() const { return id; }
    string GetName() const { return name; }
    void AddFriend(User* friendUser) { friendList.push_back(friendUser); }
    void AddLikedPage(Page* page) { likedPages.push_back(page); }
};

class Page {
private:
    int id;
    User* owner;
    string title;
    vector<Post*> posts;
    int numLikes;
public:
    Page(int _id, User* _owner, const string& _title) : id(_id), owner(_owner), title(_title), numLikes(0) {}

    void ViewPosts() {
        cout << "Posts of Page: " << title << endl;
        for (Post* post : posts) {
            cout << "Post ID: " << post->GetId() << ", Description: " << post->GetDescription() << endl;
        }
    }

    int GetId() const { return id; }
    string GetTitle() const { return title; }
    void AddPost(Post* post) { posts.push_back(post); }
    void IncrementLikes() { numLikes++; }
};

class Post {
private:
    int id;
    string description;
    vector<User*> likes;
    vector<Comment*> comments;
    string sharedDate;


public:
    Post(int _id, const string& _description) : id(_id), description(_description) {

        time_t now = time(0);
        sharedDate = ctime(&now);
    }

    int GetId() const { return id; }
    string GetDescription() const { return description; }
    string GetSharedDate() const { return sharedDate; }

    void Like(User* user) 
    {
        if (likes.size() < 10) 
        {
            likes.push_back(user);
        }
        else 
        {
            cout << "Maximum likes reached for this post." << endl;
        }
    }

    void AddComment(Comment* comment) 
    {
        comments.push_back(comment);
    }

    void ViewLikes() {
        cout << "People who liked this post:" << endl;
        for (User* user : likes) {
            cout << user->GetName() << endl;
        }
    }

    void ViewComments() {
        cout << "Comments on this post:" << endl;
        for (Comment* comment : comments) {
            cout << "Comment by " << comment->GetAuthor()->GetName() << ": " << comment->GetText() << endl;
        }
    }
};

class Comment {
private:
    int id;
    string text;
    User* author;
public:
    Comment(int _id, const string& _text, User* _author) : id(_id), text(_text), author(_author) {}

    int GetId() const { return id; }
    string GetText() const { return text; }
    User* GetAuthor() const { return author; }
};

int main() {

    User u1(1, "John");
    User u2(2, "Alice");
    Page p1(1, &u1, "Food Fusion");
    Post post1(1, "Recipe for chicken curry");
    Comment comment1(1, "Looks delicious!", &u2);

    u1.AddFriend(&u2);
    u1.AddLikedPage(&p1);
    p1.AddPost(&post1);
    post1.AddComment(&comment1);

    cout << "User's Friend List:" << endl;
    u1.ViewFriendList();

    cout << "\nUser's Liked Pages:" << endl;
    u1.ViewLikedPages();

    cout << "\nPosts of Liked Page:" << endl;
    p1.ViewPosts();

    cout << "\nLikes on Post:" << endl;
    post1.Like(&u2);
    post1.ViewLikes();

    cout << "\nComments on Post:" << endl;
    post1.ViewComments();

    return 0;
}