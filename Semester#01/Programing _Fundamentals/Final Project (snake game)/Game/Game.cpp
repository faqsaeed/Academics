#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include<iostream>
#include<string>
#include <ctime>
#include<fstream>

using namespace std;
using namespace sf;

void death(int score);
void game_play();
void high_score();

void main_menu()
{
    RenderWindow window(VideoMode(800, 800), "Snake Game");
    window.setMouseCursorVisible(false);

    Font f;
    f.loadFromFile("rb.ttf");

    Text te, t2, t3, l;
    l.setFont(f);
    l.setString("Snake Game");
    l.setPosition(Vector2f(300, 50));
    l.setCharacterSize(80);
    l.setFillColor(Color::Black);

    te.setFont(f);
    te.setString("    New game");
    te.setCharacterSize(21);
    te.setFillColor(Color(Color::Black));
    te.setPosition(Vector2f(100, 250));

    RectangleShape r, r1, r2;
    r.setFillColor(Color::Red);
    RectangleShape b2, b3;
    b2.setFillColor(Color::Red);
    b3.setFillColor(Color::Red);

    b2.setSize(Vector2f(200, 50));
    b3.setSize(Vector2f(200, 50));

    b2.setPosition(Vector2f(200, 350));
    b3.setPosition(Vector2f(120, 450));

    t2.setFont(f);
    t2.setString("                         High Score");
    t2.setCharacterSize(21);
    t2.setFillColor(Color(Color::Black));
    t2.setPosition(Vector2f(100, 350));

    t3.setFont(f);
    t3.setString("     Exit");
    t3.setCharacterSize(26);
    t3.setFillColor(Color(Color::Black));
    t3.setPosition(Vector2f(100, 450));


    r1.setSize(Vector2f(800, 800));
    Texture t, s, u;
    s.loadFromFile("sfml.jpg");
    t.loadFromFile("project.jpg");
    r1.setTexture(&t);
    r.setSize(Vector2f(200, 50));
    r.setPosition(Vector2f(110, 250));
    r.setTexture(&s);
    r2.setSize(Vector2f(40, 40));
    u.loadFromFile("mouse1.png");
    r2.setTexture(&u);

    Mouse m;
    Vector2i mi;
    Vector2i w;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (Mouse::getPosition(window).x > r.getGlobalBounds().left && Mouse::getPosition(window).x < r.getGlobalBounds().left + r.getGlobalBounds().width && Mouse::getPosition().y > r.getGlobalBounds().top && Mouse::getPosition(window).y < (r.getGlobalBounds().top + r.getGlobalBounds().height))
                {
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        window.close();
                        game_play();
                    }
                }
                if (Mouse::getPosition(window).x > b2.getGlobalBounds().left && Mouse::getPosition(window).x < b2.getGlobalBounds().left + b2.getGlobalBounds().width && Mouse::getPosition().y > b2.getGlobalBounds().top && Mouse::getPosition(window).y < (b2.getGlobalBounds().top + b2.getGlobalBounds().height))
                {
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        high_score();
                    }
                }

                if (Mouse::getPosition(window).x > b3.getGlobalBounds().left && Mouse::getPosition(window).x < b3.getGlobalBounds().left + b3.getGlobalBounds().width && Mouse::getPosition().y > b3.getGlobalBounds().top && Mouse::getPosition(window).y < (b3.getGlobalBounds().top + b3.getGlobalBounds().height))
                {
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        window.close();
                    }
                }
            }
        }
        w.x = window.getPosition().x;
        w.y = window.getPosition().y;
        mi.y = m.getPosition().y;
        mi.x = m.getPosition().x;

        Vector2i mo;
        mo.x = mi.x - w.x - 11;
        mo.y = mi.y - w.y - 45;
        r2.setPosition(mo.x, mo.y);

        window.clear();

        window.draw(r1);
        window.draw(r);
        window.draw(te);
        window.draw(l);
        window.draw(b2);
        window.draw(b3);
        window.draw(t2);
        window.draw(t3);
        window.draw(r2);

        window.display();
    }
}

void high_score()
{

    fstream file;
    file.open("score.doc");

    string score;
    file >> score;

    RenderWindow window(VideoMode(963, 600), "High Scores");

    Texture ex;
    ex.loadFromFile("project.jpg");

    Sprite bg;
    bg.setTexture(ex);

    Font font;
    font.loadFromFile("rb.ttf");

    Text end;

    end.setFont(font);
    end.setCharacterSize(70);
    end.setFillColor(Color::Black);
    end.setString(score);
    end.setPosition(40.f, 40.f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();

        window.draw(bg);
        window.draw(end);

        window.display();

    }
}
void game_play()
{
   //music

    Music starting, eating, die;
    starting.openFromFile("song.WAV");
    starting.setVolume(20);
    starting.play();

    eating.openFromFile("s2.mp3");
    eating.setVolume(60);

    die.openFromFile("mm.mp3");
    die.setVolume(45);

    int score = 0;
    float snake_size = 20.0;

    //text

    Font font;
    font.loadFromFile("tnrb.ttf");

    Text text;
    text.setFont(font);
    text.setCharacterSize(14);
    text.setString("Score: ");

    Text score1;
    score1.setFont(font);

    score1.setCharacterSize(14);
    score1.setPosition(text.getPosition().x + 42.f, text.getPosition().y);


    srand(time(0));
    RenderWindow window(VideoMode(963, 600), "Snake Game Project");
    window.setFramerateLimit(45);

    RectangleShape snake(Vector2f(snake_size, snake_size));
    RectangleShape body[1000];

    int body_size = 1;

    snake.setFillColor(Color::Black);
    const float x = window.getSize().x / 2;
    const float y = window.getSize().y / 2;

    snake.setPosition(x, y);

    // Boundaries

    float boundaries = 20.0;
    RectangleShape left_boundary(Vector2f(boundaries, 2 * y));
    RectangleShape right_boundary(Vector2f(boundaries, 2 * y));
    RectangleShape upper_boundary(Vector2f(2 * x, boundaries));
    RectangleShape lower_boundary(Vector2f(2 * x, boundaries));
    left_boundary.setFillColor(Color::Blue);
    right_boundary.setFillColor(Color::Blue);
    upper_boundary.setFillColor(Color::Blue);
    lower_boundary.setFillColor(Color::Blue);
    right_boundary.setPosition(2 * x - 20.f, 0.f);
    lower_boundary.setPosition(0.f, 2 * y - 20.f);

    // Food 

  CircleShape food(10.f);
  food.setFillColor(Color::Red);

   do
  {
      food.setPosition(rand() % (window.getSize().x - 40) + 20, rand() % (window.getSize().y - 40) + 20);
  } while (food.getGlobalBounds().intersects(lower_boundary.getGlobalBounds()) || food.getGlobalBounds().intersects(right_boundary.getGlobalBounds()) || food.getGlobalBounds().intersects(left_boundary.getGlobalBounds()) || food.getGlobalBounds().intersects(upper_boundary.getGlobalBounds()));

    // Movement variables

    float x_speed = 0.0f;
    float y_speed = 0.0f;
    float speed = 4.f;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }

        // Movement 
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Up && y_speed == 0)
            {
                x_speed = 0;
                y_speed = -speed;
            }
            else if (event.key.code == Keyboard::Down && y_speed == 0)
            {
                x_speed = 0;
                y_speed = speed;
            }
            else if (event.key.code == Keyboard::Left && x_speed == 0)
            {
                x_speed = -speed;
                y_speed = 0;
            }
            else if (event.key.code == Keyboard::Right && x_speed == 0)
            {
                x_speed = speed;
                y_speed = 0;
            }
        }
        //Boundary hitting 


        if (snake.getGlobalBounds().intersects(lower_boundary.getGlobalBounds()) || snake.getGlobalBounds().intersects(right_boundary.getGlobalBounds()) || snake.getGlobalBounds().intersects(left_boundary.getGlobalBounds()) || snake.getGlobalBounds().intersects(upper_boundary.getGlobalBounds()))
        {
            die.play();
            sleep(seconds(1.5));
            window.close();
            death(score);
            window.close();
        }

        snake.move(x_speed, y_speed);

        // Body following
        for (int i = body_size - 1; i > 0; --i)
        {
            body[i].setPosition(body[i - 1].getPosition());
        }

        // First body segment
       body[0].setPosition(snake.getPosition());

        // Eating and scoring
        if (snake.getGlobalBounds().intersects(food.getGlobalBounds()))
        {
            eating.play();
            score += 5;
            body_size++;
            body[body_size - 1].setSize(Vector2f(snake_size, snake_size));
            do
            {
                food.setPosition(rand() % (window.getSize().x - 40) + 20, rand() % (window.getSize().y - 40) + 20);
            } while (food.getGlobalBounds().intersects(lower_boundary.getGlobalBounds()) || food.getGlobalBounds().intersects(right_boundary.getGlobalBounds()) || food.getGlobalBounds().intersects(left_boundary.getGlobalBounds()) || food.getGlobalBounds().intersects(upper_boundary.getGlobalBounds()));
        }

        string s = to_string(score);
        score1.setString(s);

        window.clear(Color::Cyan);

        for (int i = 0; i < body_size; ++i)
        {
            window.draw(body[i]);
        }
        window.draw(snake);
        window.draw(food);
        window.draw(lower_boundary);
        window.draw(upper_boundary);
        window.draw(right_boundary);
        window.draw(left_boundary);
        window.draw(text);
        window.draw(score1);

        window.display();
    }
}

void death(int score)
{
    fstream file;
    file.open("score.doc", ios::app);
    file << score << endl;
    file.close();

    RenderWindow window(VideoMode(963, 600), "Game Over");

    Texture ex, again_tr, home_tr;
    ex.loadFromFile("project.jpg");
    again_tr.loadFromFile("pause.png");
    home_tr.loadFromFile("home.png");

    Sprite exits, agains, homes;

    exits.setTexture(ex);
    agains.setTexture(again_tr);
    homes.setTexture(home_tr);

    agains.setPosition(80.f, 250.f);
    homes.setPosition(350.f, 250.f);

    Font font;
    font.loadFromFile("rb.ttf");

    Text end, aga, home, scoret, text;

    end.setFont(font);
    end.setCharacterSize(100);
    end.setFillColor(Color::Black);
    end.setString("GAME OVER!!!");
    end.setPosition(40.f, 60.f);

    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(Color::Black);
    text.setString("Your Score is");
    text.setPosition(50.f, 180.f);

    string s = to_string(score);
    scoret.setFont(font);
    scoret.setCharacterSize(25);
    scoret.setFillColor(Color::Black);
    scoret.setString(s);
    scoret.setPosition(text.getPosition().x + 156.f, text.getPosition().y);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (Mouse::getPosition(window).x > agains.getGlobalBounds().left && Mouse::getPosition(window).x < agains.getGlobalBounds().left + agains.getGlobalBounds().width && sf::Mouse::getPosition().y > agains.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (agains.getGlobalBounds().top + agains.getGlobalBounds().height))
                {
                    agains.setColor(Color::White);
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        window.close();
                        game_play();
                    }
                }
                if (Mouse::getPosition(window).x > homes.getGlobalBounds().left && Mouse::getPosition(window).x < homes.getGlobalBounds().left + homes.getGlobalBounds().width && sf::Mouse::getPosition().y > homes.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (homes.getGlobalBounds().top + homes.getGlobalBounds().height))
                {
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        window.close();
                        main_menu();
                    }
                }
            }
        }

        window.clear();

        window.draw(exits);
        window.draw(end);
        window.draw(agains);
        window.draw(homes);
        window.draw(text);
        window.draw(scoret);

        window.display();
    }
}

int main()
{
    main_menu();
}