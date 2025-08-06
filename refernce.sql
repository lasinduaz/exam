-- activity 01--

create table Food_Collection_Sa23800182 (
id int primary key,
xDoc xml not null
)

select * from Food_Collection_Sa23800182 

 
 -- Activity 02-- 

insert into Food_Collection_Sa23800182 values

(1,'<breakfast_menu>
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

-- Activity 02 (get all food item names)
select xDoc.query(' 
					for $food in //food
					let $name := $food/name
					return data($name)')

from Food_Collection_Sa23800182



-- Activity03--

select * from Food_Collection_Sa23800182

select xDoc.query(' 
					for $food in //food
					let $name := $food/name
					let $type := $food/@type
					where $type = "waffles"
					return data($name)')

from Food_Collection_Sa23800182


-- Activity04--
select xDoc.query(' 
					for $food in //food
					let $name := $food/name
					let $type := $food/@type
					where $type = "Toast"
					return data($name)')

from Food_Collection_Sa23800182



-- Activity 05--
select xDoc.query(' 
					for $food in //food
					let $name := $food/name
					let $price := $food/price
                    where $price>60 and price<100 					
					return data($name)')

from Food_Collection_Sa23800182

-- without using variables --

select xDoc.query(' 
					for $food in //food
                    where $food/price>60 and $food/price<100 					
					return data($food/price)')

from Food_Collection_Sa23800182

-- Activity 06--

select xDoc.query(' 
					for $food in //food
                    where $food/price>80 					
					return data($food/price)')

from Food_Collection_Sa23800182

-- Activity 07--
select xDoc.query(' 
					for $food in //food
					let $name := $food/name
					let $type := $food/@type
					let $price := $food/price
					let $calory := $food/calories
                    where $type = "waffles" and price<80 and $calory>700		
					return data($name)')

from Food_Collection_Sa23800182

--Activity 08--

select xDoc.query(' for $food in //food
					let $type := $food/@type
			        let $price := $food/price
					where $type = "Toast"
					return data($price)')
					
from Food_Collection_Sa23800182


--Activity 09--

select xDoc.query(' for $food in //food
					let $name := $food/name
					let $type := $food/@type
			        let $calory := $food/calory
					where $type = "Quesadillas" and $calory >500
					return data($name)')
					
from Food_Collection_Sa23800182

--Activity 10--

select xDoc.query(' for $food in //food
					let $name := $food/name
			        let $calory := $food/calories
					where $name = "Berry-Berry Belgian Waffles"
					return data($calory)')
					
from Food_Collection_Sa23800182


--Activity 11--

select xDoc.query(' for $type in distinct-values(//food/@type)
					return data ($type)')
					
from Food_Collection_Sa23800182


--Activity 12--

select xDoc.query(' for $avgprice in avg (//food/@avgprice)
					return data ($avgprice)')
					
from Food_Collection_Sa23800182

--Activity 13--

select xDoc.query(' for $count in count (//food/@type)
					return $count')
					
from Food_Collection_Sa23800182


--Activity 14--

select xDoc.query(' for $total in sum (//food/@calory)
					return $total')
					
from Food_Collection_Sa23800182


--Activity 15--

select xDoc.query(' for $total in sum (//food/@calory)
					return $total')
					
from Food_Collection_Sa23800182


--Activity 16--

select xDoc.query(' for $maxprice in max (//food/@price)
					return $maxprice')
					
from Food_Collection_Sa23800182

--Activity 17--

select xDoc.query(' for $food in //food
					let $name := $food/name
			        let $calory := $food/calories
					let $avgcalory := avg(//food/calories)
					where $calory>$avgcalory
					return data($name)')
					
from Food_Collection_Sa23800182


--Activity 18--				

select xDoc.query(' for $food in //food
					where $food/price >80
					return data($name)')
					
from Food_Collection_Sa23800182

