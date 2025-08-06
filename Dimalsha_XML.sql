--Iyaaa Lajjai Osaaaniii <3 -----

CREATE TABLE IyaaOshani ( 
id int primary key, 
xDoc Xml not null 
) 

insert into IyaaOshani values (1,'<bookstore>
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
</bookstore>')


select * from IyaaOshani


--- a -----

select xDoc.query(

'//book'
)from IyaaOshani where id = 1;

--- b --- 
select xDoc.query(

'/bookstore/book/title'
)from IyaaOshani where id = 1;


--- c ---
select xDoc.query(

'//author'
)from IyaaOshani where id = 1;

---- d ----\
select xDoc.query(

'/bookstore/book[price>35]/price'
)from IyaaOshani where id = 1;


-- e ---
select xDoc.query(

'/bookstore/book[@category="WEB"]'
)from IyaaOshani where id = 1;


--f---

select xDoc.query(

'/bookstore/book[2]'
)from IyaaOshani where id = 1;


---g---

select xDoc.query(

'/bookstore/book[2]/title'
)from IyaaOshani where id = 1;

--h--
select xDoc.query(

'/bookstore/book [@category="WEB"][2]'
)from IyaaOshani where id = 1;


---I --
select xDoc.query(

'/bookstore/book [@category="CHILDREN"and price>25]'
)from IyaaOshani where id = 1;


---j---
select xDoc.query(

'/bookstore/book [@category="WEB" or price<25]'
)from IyaaOshani where id = 1;


--- k ---
select xDoc.query(

'/bookstore/book[1]/title'
)from IyaaOshani where id = 1;


----l ----
select xDoc.query(

'/bookstore/book[price>35]/title'
)from IyaaOshani where id = 1;

--m --
select xDoc.query(

'/bookstore/book/title/text()'
)from IyaaOshani where id = 1;

