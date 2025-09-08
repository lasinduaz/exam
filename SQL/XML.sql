CREATE TABLE ADMIN
(
    id int PRIMARY KEY,
    xDoc XML not NULL
)
SELECT *  FROM ADMIN
-- this will return nicer way to view XML data--
SELECT xDoc.query('.') AS PrettyXML
FROM ADMIN;

-- Add a new record containing the bookstore XML data.
-- Specifying columns and adding comments improves clarity.
INSERT INTO ADMIN (id, xDoc)
VALUES (
    1, -- The primary key for this record
    '<bookstore>
        <book category="COOKING">
            <title lang="en">Everyday Italian</title>
            <author>Giada De Laurentiis</author>
            <year>2006</year>
            <price>35.00</price>
        </book>
        <book category="CHILDREN">
            <title lang="en">Harry Potter</title>
            <author>J K. Rowling</author>
            <year>2004</year>
            <price>29.99</price>
        </book>
        <book category="WEB">
            <title lang="en">XQuery Kick Start</title>
            <author>James McGovern</author>
            <author>Per Bothner</author>
            <author>Kurt Cagle</author>
            <author>James Linn</author>
            <author>Vaidyanathan Nagarajan</author>
            <year>2003</year>
            <price>49.99</price>
        </book>
        <book category="WEB">
            <title lang="en">Learning XML</title>
            <author>Erik T. Ray</author>
            <year>2003</year>
            <price>39.95</price>
        </book>
    </bookstore>'
);


--A--
SELECT xDoc.query('.') AS PrettyXML
FROM ADMIN;

--B--
SELECT xDoc.query('/bookstore/book/title') AS BookTitles
FROM ADMIN;

--C--
SELECT xDoc.query('/bookstore/book/author') AS BookAuthors
FROM ADMIN;

--D--
SELECT xDoc.query('bookstore/book/price') AS BookPrices
FROM ADMIN;

--E--

SELECT xDoc.query('/bookstore/book[@category="WEB"]') AS WebBooks
FROM ADMIN;

--F--
SELECT xDoc.query('/bookstore/book[2]') AS SecondBook
FROM ADMIN;

--G--
SELECT xDoc.query('/bookstore/book[2][@category ="WEB"]') AS SecondWebBook
FROM ADMIN;

--H--
select xDoc.query('/bookstore/book[price > 25][@category = "CHILDREN"]')
FROM ADMIN;

--I--
SELECT xDoc.query('/bookstore/book[price > 25][@category = "WEB"]')
FROM ADMIN;

--k--
SELECT xDoc.query('/bookstore/book[1]/title') AS titleOfFirstBook
FROM ADMIN;


--i--
select xDoc.query('/bookstore/book[price > 35]') AS ExpensiveBooks
FROM ADMIN;

--N--
SELECT xDoc.query('/bookstore/book/title') AS BookTitles
FROM ADMIN;

--M--
SELECT xDoc.query('/bookstore/book/price') AS BookPrices
FROM ADMIN;

--o--
SELECT xDoc.query('/bookstore/book[author = "J K. Rowling"]') AS RowlingBooks
FROM ADMIN;

--p--
SELECT xDoc.query('/bookstore/book[year > 2000]') AS After2000Books
FROM ADMIN;

--F--
SELECT xDoc.query('/bookstore/child::book') AS Books
FROM ADMIN;

-- This query is corrected to find all author elements.
-- The 'author' element is a child of 'book', not 'bookstore', so we must specify the full path.
SELECT xDoc.query('/bookstore/book/author') AS Authors
FROM ADMIN;