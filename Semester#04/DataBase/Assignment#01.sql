CREATE DATABASE Assignment1

USE Assignment1

-- Create Users table
CREATE TABLE Users (
    user_id INT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(100) NOT NULL UNIQUE,
    dob DATE NOT NULL,
    created_at DATE
);

-- Create Books table
CREATE TABLE Books (
    book_id INT PRIMARY KEY,
    title VARCHAR(200) NOT NULL,
    author VARCHAR(100) NOT NULL,
    published_date DATE NOT NULL,
    genre VARCHAR(50) NOT NULL,
    created_at DATE
);

-- Create Chapters table
CREATE TABLE Chapters (
    chapter_id INT PRIMARY KEY,
    book_id INT,
    chapter_number INT NOT NULL,
    title VARCHAR(200) NOT NULL,
    content TEXT NOT NULL,
    total_words INT NOT NULL,
    FOREIGN KEY (book_id) REFERENCES Books(book_id)
);

-- Create Reviews table
CREATE TABLE Reviews (
    review_id INT PRIMARY KEY,
    user_id INT,
    book_id INT,
    rating INT CHECK (rating >= 1 AND rating <= 5),
    review_text TEXT NOT NULL,
    created_at DATE,
    FOREIGN KEY (user_id) REFERENCES Users(user_id),
    FOREIGN KEY (book_id) REFERENCES Books(book_id)
);

-- Create Liked_Books table
CREATE TABLE Liked_Books (
    like_id INT PRIMARY KEY,
    user_id INT,
    book_id INT,
    liked_at DATE,
    FOREIGN KEY (user_id) REFERENCES Users(user_id),
    FOREIGN KEY (book_id) REFERENCES Books(book_id)
);






-- Insert sample data into Users table--
INSERT INTO Users (user_id, username, email, dob, created_at) VALUES
(1, 'john_doe', 'john@email.com', '1990-05-15', '2023-01-15'),
(2, 'jane_smith', 'jane@email.com', '1995-08-22', '2023-03-22'),
(3, 'ali_khan', 'ali@email.com', '2005-03-10', '2023-06-10'),
(4, 'sara_ahmed', 'sara@email.com', '2000-11-30', '2023-08-05'),
(5, 'mike_wilson', 'mike@email.com', '1988-12-25', '2023-09-05'),
(6, 'teen_reader', 'teen@email.com', '2008-01-01', '2023-10-20'),
(7, 'bob_brown', 'bob@email.com', '1975-06-15', '2023-11-05'),
(8, 'emma_davis', 'emma@email.com', '2010-12-01', '2023-12-18'),
(9, 'david_miller', 'david@email.com', '1985-03-20', '2024-01-07'),
(10, 'sophia_lee', 'sophia@email.com', '2007-09-10', '2024-01-25');

-- Insert sample data into Books table--

INSERT INTO Books (book_id, title, author, published_date, genre, created_at) VALUES
(1, 'The Adventure Begins', 'Ali', '2010-01-01', 'Adventure', '2023-02-10'),
(2, 'Mystery Manor', 'Sarah Williams', '2015-06-15', 'Mystery', '2023-04-15'),
(3, 'Comic Adventures', 'Mike Brown', '1960-03-20', 'Comics', '2023-06-20'),
(4, 'The Great Journey', 'Ali', '2012-09-10', 'Adventure', '2023-07-30'),
(5, 'Technical Guide', 'John Smith', '2020-12-05', 'Education', '2023-09-05'),
(6, 'Epic Tales', 'Ali', '2019-05-20', 'Fantasy', '2023-10-12'),
(7, 'Comic World', 'Mike Brown', '1965-07-15', 'Comics', '2023-11-25'),
(8, 'Long Story', 'Jane Doe', '2018-11-30', 'Novel', '2023-12-30'),
(9, 'Word Master', 'Ali', '2021-02-28', 'Education', '2024-01-15'),
(10, 'Ancient Tales', 'Sarah Williams', '1950-04-10', 'Fantasy', '2024-02-01');


INSERT INTO Reviews (review_id, user_id, book_id, rating, review_text, created_at) VALUES
(1, 1, 1, 4, 'Great book!', '2023-03-15'),
(2, 1, 2, 5, 'Absolutely loved it', '2023-04-20'),
(3, 2, 2, 3, 'Decent read', '2023-05-25'),
(4, 3, 3, 4, 'Very entertaining', '2023-06-30'),
(5, 4, 4, 5, 'Highly recommended', '2023-07-10'),
(6, 5, 2, 4, 'Interesting plot', '2023-08-15'),
(7, 6, 2, 5, 'Amazing story', '2023-09-20'),
(8, 7, 2, 4, 'Well written', '2023-10-25'),
(9, 1, 3, 3, 'Good comic', '2023-11-30'),
(10, 2, 3, 4, 'Fun read', '2023-12-05'),
(11, 6, 3, 5, 'Best comic ever', '2024-01-10'),
(12, 8, 1, 4, 'Nice adventure', '2024-02-05');


-- Insert sample data into Liked_Books table
INSERT INTO Liked_Books (like_id, user_id, book_id, liked_at) VALUES
(1, 1, 3, '2023-03-20'),
(2, 1, 5, '2023-04-25'),
(3, 3, 2, '2023-05-30'),
(4, 3, 3, '2023-07-05'),
(5, 7, 4, '2023-08-10'),
(6, 1, 9, '2023-09-15'),
(7, 2, 3, '2023-10-20'),
(8, 5, 9, '2023-11-25'),
(9, 5, 2, '2023-12-30'),
(10, 4, 3, '2024-01-05'),
(11, 5, 4, '2024-01-15'),
(12, 10, 5, '2024-01-25'),
(13, 6, 3, '2024-02-01'),
(14, 7, 10, '2024-02-10');

INSERT INTO Chapters (chapter_id, book_id, chapter_number, title, content, total_words) VALUES
-- Book 1 (6 chapters)--
(1, 1, 1, 'Beginning', 'Content...', 2500),
(2, 1, 2, 'Middle', 'Content...', 3000),
(3, 1, 3, 'Climax', 'Content...', 2800),
(4, 1, 4, 'Resolution', 'Content...', 2600),
(5, 1, 5, 'Ending', 'Content...', 2700),
(6, 1, 6, 'Epilogue', 'Content...', 2400),
-- Book 2 (12 chapters)--
(7, 2, 1, 'Mystery Begins', 'Content...', 250),
(8, 2, 2, 'The Clue', 'Content...', 250),
(9, 2, 3, 'The Search', 'Content...', 250),
(10, 2, 4, 'The Discovery', 'Content...', 250),
(11, 2, 5, 'The Revelation', 'Content...', 250),
(12, 2, 6, 'The Chase', 'Content...', 250),
(13, 2, 7, 'The Trap', 'Content...', 250),
(14, 2, 8, 'The Escape', 'Content...', 250),
(15, 2, 9, 'The Truth', 'Content...', 250),
(16, 2, 10, 'The Confrontation', 'Content...', 250),
(17, 2, 11, 'The Resolution', 'Content...', 250),
(18, 2, 12, 'The End', 'Content...', 250),
-- Book 3 (3 chapters)--
(19, 3, 1, 'Comic Start', 'Content...', 1500),
(20, 3, 2, 'Comic Middle', 'Content...', 1600),
(21, 3, 3, 'Comic End', 'Content...', 1700);



--Question#02(a)--
SELECT DISTINCT b.title AS Book_Names
FROM (Liked_Books AS l JOIN Reviews AS r ON l.user_id = r.user_id AND l.book_id = r.book_id) JOIN Books b ON l.book_id = b.book_id;

--Question#02(b)--
SELECT DISTINCT username
FROM (Users AS U JOIN Liked_Books AS L ON U.user_id = L.user_id) JOIN Books AS B ON B.book_id = L.book_id
WHERE YEAR(U.dob)-20 >= YEAR(published_date)

--Question#02(c)--
SELECT B.title AS Book_Names
FROM (Books AS B LEFT JOIN Reviews AS R ON B.book_id = R.book_id)
where user_id IS NULL
INTERSECT
SELECT B.title AS Book_Names
FROM (Books AS B LEFT JOIN Liked_Books AS L ON B.book_id = L.book_id)
where user_id IS NULL

--Question#02(d)--
SELECT  Distinct L.book_id, U.username
FROM (Liked_Books AS L JOIN Reviews AS r ON L.user_id = r.user_id AND L.book_id = r.book_id) Join Users as U on U.user_id = R.user_id

--Question#02(e)--
SELECT username AS Names
FROM (Users AS U LEFT JOIN Liked_Books AS L ON U.user_id = L.user_id) LEFT JOIN Reviews AS R ON U.user_id = R.user_id
where L.like_id IS NULL AND R.review_id is NULL

--Question#02(f)--
SELECT username AS Names, l.like_id, r.review_id
FROM (Liked_Books AS l JOIN Reviews AS r ON l.user_id = r.user_id AND l.book_id = r.book_id) Join Users AS U ON U.user_id = l.user_id
WHERE l.liked_at <> r.created_at

--Question#02(g)--
SELECT Distinct B.title 
FROM (Liked_Books AS L FULL JOIN Reviews AS R ON L.book_id = R.book_id) JOIN Books AS B ON B.book_id = R.book_id
WHERE (like_id IS NOT NULL AND review_id IS NULL) OR (like_id IS NULL AND review_id IS NOT NULL);

---Question#02(h)--
SELECT Distinct B.title 
FROM (Reviews AS R JOIN Chapters AS C ON R.book_id = C.book_id) JOIN Books as B ON B.book_id = R.book_id;


--QUESTION#03--3) 


--Question#03(a)--
SELECT B.title 
FROM Chapters AS C Join Books AS B ON C.book_id = B.book_id
Group By B.title
HAVING count(C.book_id)>5

--Question#03(B)--
SELECT TOP 3 count(B.book_id) AS Total_Reviews, B.title
FROM Reviews AS R JOIN Books AS B ON R.book_id = B.book_id
Group By B.title
ORDER BY Total_Reviews DESC


--Question#03(C)--
SELECT AVG(R.rating) AS Average
FROM Reviews AS R  JOIN Books AS B ON R.book_id = B.book_id 
WHERE B.author = 'Ali'


--Question#03(D)--
SELECT U.username, COUNT(L.like_id) AS Total_Likes
FROM Users AS U 
JOIN Liked_Books AS L ON U.user_id = L.user_id
GROUP BY U.username
HAVING COUNT(L.like_id) > 5;

--Question#03(E)--

SELECT B.title, CAST(R.review_text AS VARCHAR(MAX)) AS review_text
FROM Books AS B
JOIN Reviews AS R ON B.book_id = R.book_id
JOIN Chapters AS C ON B.book_id = C.book_id
GROUP BY B.book_id, B.title, CAST(R.review_text AS VARCHAR(MAX))
HAVING MAX(C.chapter_number) >= 10;

--Question#03(F)--
SELECT 
    AVG(CASE WHEN 2025 - YEAR(U.dob) BETWEEN 13 AND 19 THEN R.rating END) AS Teen_Avg_Rating,
    AVG(CASE WHEN 2025 - YEAR(U.dob) NOT BETWEEN 13 AND 19 THEN R.rating END) AS Non_Teen_Avg_Rating
FROM Users AS U
JOIN Reviews AS R ON U.user_id = R.user_id;



--Question#03(G)--
SELECT AVG(2025 - YEAR(U.dob))  AS Average_age
FROM (Users AS U JOIN Liked_Books AS L ON U.user_id = L.user_id) JOIN Books AS B ON L.book_id = B.book_id
WHERE B.genre = 'Comics';


--Question#03(H)--
SELECT U.username
FROM (Users AS U JOIN Liked_Books AS L ON U.user_id = L.user_id) JOIN Reviews AS R ON U.user_id = R.user_id AND L.book_id = R.book_id JOIN Chapters AS C ON R.book_id = C.book_id
GROUP BY U.username, C.book_id
HAVING AVG(C.total_words) = 250;


--Question#03(i)--
SELECT (COUNT(DISTINCT R.book_id))*100/ COUNT(DISTINCT B.book_id)AS Reviewed_Percentage
FROM Books AS B LEFT JOIN Reviews AS R ON B.book_id = R.book_id;
