CREATE TABLE food_Collection 
(
    id INT PRIMARY KEY,
    xDoc XML NOT NULL
)

SELECT * FROM food_Collection;
INSERT INTO food_Collection (id, xDoc) VALUES
(1,
'<breakfast_menu>
	<food type="Waffles">
	<name> Belgian Waffles</name>
	<price>60</price>
	<description>Two of our famous Belgian Waffles with plenty of real maple syrup</description>
	<calories>650</calories>
</food>
	<food type="Waffles">
	<name>Strawberry Belgian Waffles</name>
	<price>75</price>
	<description>Light Belgian waffles covered with strawberries and whipped cream</description>
	<calories>900</calories>
</food>
	<food type="Waffles">
	<name>Berry-Berry Belgian Waffles</name>
	<price>80</price>
	<description>Light Belgian waffles covered with an assortment of fresh berries and whipped cream</description>
	<calories>900</calories>
</food>
	<food type="Toast">
	<name>French Toast</name>
	<price>45</price>
	<description>Thick slices made from our homemade sourdough bread</description>
	<calories>600</calories>
</food>
	<food type="Toast">
	<name>Homestyle Breakfast</name>
	<price>70</price>
	<description>Two eggs, bacon or sausage, toast, and our ever-popular hash browns</description>
	<calories>950</calories>
</food>
	<food type="Quesadillas">
	<name>BBQ Chicken</name>
	<price>100</price>
	<description>Chicken, tortillas, BBQ Sauce, Cheese</description>
	<calories>1250</calories>
</food>
	<food type="Quesadillas">
	<name>Spinach and Mushroom</name>
	<price>100</price>
	<description>Spinach, Mushroom, tortillas, Cheese, Garlic</description>
	<calories>950</calories>
</food>
</breakfast_menu>')


--act 03--
--Q1--
SELECT xDoc.query('
                    for $food in //food
                    let $name := $food/name
                    return data($name)')
FROM food_Collection;
--Q2--
select xDoc.query ('

    for $food in //food
    let $name := $food/name
    return data($name)
')  FROM food_Collection;

--Q3--
-- Display the names of all Toasts
SELECT xDoc.query('

        for $food in //food
        let $name := $food/name
        let $type := $food/@type
        where $type = "Toast"
        return data($name)
') FROM food_Collection;

--Q4--


SELECT xDoc.query ('

    for $food in //food
    let $price  := $food/price 
    where $price > 60 and $price < 100
    return data($price)
') FROM food_Collection;

--Q5--
select xDoc.query('
    for $food in //food
    let $name := $food/name
    let $price := $food/price
    where $price < 80
    return data($name)
')
FROM food_Collection;

--Q6--
-- Display the names of food items with a price less than 80 AND calories greater than 800
select xDoc.query('

    for $food in //food
    let $name := $food/name
    let $price := $food/price 
    let $calories := $food/calories
    where ($price < 80) and ($calories > 800)
    return data($name)
')
FROM food_Collection;

--Q7--
-- Display the names of all Toasts (Note: This is a duplicate of Q3)
SELECT xDoc.query('
    for $food in //food
    let $name := $food/name
    let $type := $food/@type
    where $type = "Toast"
    return data($name)

')
FROM food_Collection;

--Q8--
-- Display the names of all food items with more than 500 calories
select xDoc.query ('

    for $food in //food
    let $name := $food/name
    let $calories := $food/calories
    where $calories > 500
    return data($name)
') FROM food_Collection;

-- A more concise way to write Q8 using an XPath predicate:
/*
SELECT xDoc.query('
    for $food in //food[calories > 500]
    return data($food/name)
') FROM food_Collection;
*/

--Q9--
-- Display the calories for "Berry-Berry Belgian Waffles"
SELECT xDoc.query('
    for $food in //food
    where normalize-space($food/name) = "Berry-Berry Belgian Waffles"
    return data($food/calories)
') FROM food_Collection;



-- Display unique food types
SELECT xDoc.query('
    <types> {
        for $t in distinct-values(//food/@type)
        order by $t
        return <type>{data($t)}</type>
    } </types>
') AS UniqueFoodTypes
FROM food_Collection;

--avarage of prices--
SELECT xDoc.query
('
    avg(//food/price)
') AS AveragePrice
FROM food_Collection;


-- Display the type and name for each food item as a single string
SELECT xDoc.query
('
    for $food in //food
    let $type := $food/@type, $name := $food/name
    return concat(data($type), " - ", data($name))

') AS availableFood
FROM food_Collection;

--count of number of food items
select xDoc.query
('  
    
    let $counttype := count(//food/@type)
    return $counttype
') AS foodCount
FROM food_Collection;

SELECT xDoc.query
('
    let $price := //food/price
    return min($price)
') AS Minprice
FROM food_Collection;


SELECT xDoc.query
('
    let $price := //food/price
    return max($price)
') AS Maxprice
FROM food_Collection;