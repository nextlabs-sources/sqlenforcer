-- DB-19:Allow by Default.
/* EMPTY */

-- DB-20:Allow by Default.
/* EMPTY */

-- DB-21:Allow by Default.
/* EMPTY */

-- DB-22:The relationship among different policies is OR
/* EMPTY */

-- DB-23:Not influence SQL Server security system
/* EMPTY */

-- DB-54:<row value ctor> <comp op> <row value ctor>
insert into sa.CUSTOMER select * from sa.CUSTOMER_COPY where c_custkey = 'breakingbad'and c_privilege_level = 1;

-- DB-55:VALUES <row value ctor list>
insert into sa.CUSTOMER values ('breakingbad', 'Cateing', 2);

-- DB-56:All columns by default
insert into sa.CUSTOMER_DEFAULT default values;

-- DB-57:DELETE FROM <target table>
delete from sa.CUSTOMER;

-- DB-58:<left paren><column name list><right paren> VALUES <row value ctor list>
insert into sa.CUSTOMER (c_custkey, c_mktsegment, c_privilege_level) values ('breakingbad', 'Cateing', 2);

-- DB-59:Some columns by default
insert into sa.CUSTOMER_DEFAULT (c_privilege_level) values (1);

-- DB-62:<left paren> <insert column list> <right paren> <query expression>
insert into sa.CUSTOMER (c_custkey, c_mktsegment, c_privilege_level) select c_custkey, c_mktsegment, c_privilege_level from sa.CUSTOMER_COPY where c_custkey = 'breakingbad'and c_privilege_level = 1;
insert into sa.CUSTOMER_VIEW (c_custkey, c_mktsegment, c_privilege_level) select c_custkey, c_mktsegment, c_privilege_level from sa.CUSTOMER_COPY where c_custkey = 'breakingbad'and c_privilege_level = 1;

-- DB-63:The priority fro UNION, EXCEPT, INTERSECT
select * from sa.CUSTOMER union all (select * from sa.CUSTOMER_COPY EXCEPT select * from sa.CUSTOMER where c_privilege_level = 1) INTERSECT select * from dbo.CUSTOMER_VIEW;

-- DB-66:<value expression>
Select * from sa.Customer order by c_privilege_level;

-- DB-67:<value expression> ASC
Select * from sa.Customer order by c_privilege_level ASC;

-- DB-68:<value expression> DESC
Select sa.c_privilege_level, sa.c_mktsegment from sa.Customer where c_mktsegment = 'building' order by c_privilege_level DESC;

-- DB-69:<sort specification>, <sort specification>...
Select * from sa.Customer where c_mktsegment = 'building' order by c_privilege_level ASC, customer_id DESC;
Select * from sa.Customer where c_mktsegment = 'building' order by c_privilege_level, customer_id DESC;

-- DB-70:<with list> ::= <with list element> { <comma> <with list element> }
with a(a_id, a_custkey) as
(select customer_id,c_custkey from sa.CUSTOMER),
b(b_id,b_custkey) as
(select order_id,o_custkey from sa.ORDERS)
select * from a
inner join b on a_id=b_id;

-- DB-71:<with list element> ::= <query name> ( <column name list> ) AS ( <query expression> )
with a(a_id, a_mktsegment) as
(select customer_id,c_mktsegment from sa.CUSTOMER)
select * from a;

-- DB-72:SELECT DISTINCT <select list> <table expression>
select DISTINCT c_mktsegment from sa.CUSTOMER;

-- DB-73:SELECT ALL <select list> <table expression>
select ALL c_mktsegment from sa.CUSTOMER;

-- DB-74:<select list> ::= <select sublist>, <select sublist>...
select customer_id,c_privilege_level from sa.CUSTOMER;

-- DB-75:<select sublist> ::= <asterisk>
select * from sa.CUSTOMER;

-- DB-76:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
select customer_id, CASE when c_privilege_level=-2
then customer_id else c_privilege_level end
from test01.sa.CUSTOMER;

-- DB-77:<select sublist> ==> <row value ctor> <as clause>
select customer_id, CASE when c_privilege_level=-2
then customer_id else c_privilege_level end as "case"
from test01.sa.CUSTOMER;

-- DB-78:<select sublist> ==> <regular identifier> <period> <asterisk>
select sa.CUSTOMER.* from sa.CUSTOMER;

-- DB-79:<select sublist> ==> " <delimited identifier body> " <period> <asterisk>
select  "select sa customer".* from sa.CUSTOMER "select sa customer";

-- DB-80:<select sublist> ==> <regular identifier>."<delimited identifier body>".<asterisk>
select  test01.sa."select sa customer".* from sa."select sa customer";

-- DB-81:<table reference> { <comma> <table reference> }...
SELECT sa.CUSTOMER.customer_id, sa.CUSTOMER.c_mktsegment, sa.ORDERS.o_orderdate
FROM sa.CUSTOMER,sa.ORDERS
WHERE sa.CUSTOMER.c_custkey=sa.ORDERS.o_custkey;

-- DB-82:<qualified identifier>
Select * from Sales;

-- DB-83:<schema name> <period> <qualified identifier> <correlation name>
select customer_id,c_mktsegment from sa.CUSTOMER temptable;

-- DB-84:<schema name> <period> <qualified identifier> AS <correlation name>
select customer_id,c_mktsegment from sa.CUSTOMER as temptable;

-- DB-85:( <query expression> ) AS <correlation name> (<derived column list>)
select a, b from (select c_privilege_level, c_mktsegment from sa.CUSTOMER) AS cus(a, b);

-- DB-86:( <query expression> ) <correlation name> (<derived column list>)
select a, b from (select c_privilege_level, c_mktsegment from sa.CUSTOMER) cus(a, b);

-- DB-87:<schema name> <period> <qualified identifier>
select customer_id,c_mktsegment from sa.CUSTOMER;

-- DB-88:<cross join> CROSS JOIN <table primary>
SELECT * FROM
sa.CUSTOMER
cross join sa.ORDERS
cross join sa.Sales
where order_id=OrderID and c_custkey=o_custkey;

-- DB-89:<inner join> CROSS JOIN <table primary>
SELECT * FROM
sa.CUSTOMER
inner join sa.ORDERS
cross join sa.Sales
on order_id=OrderID and c_custkey=o_custkey;

-- DB-90:<schema name> <period> <qualified identifier>
SELECT * FROM sa.CUSTOMER CROSS JOIN sa.ORDERS where c_custkey=o_custkey;

-- DB-91:<qualified identifier>
/* EMPTY */

-- DB-92:<schema name> <period> <qualified identifier> <correlation name>
SELECT *
FROM sa.CUSTOMER a cross join sa.ORDERS b
WHERE a.c_custkey=b.o_custkey;

-- DB-93:<schema name> <period> <qualified identifier> AS <correlation name>
SELECT *
FROM sa.CUSTOMER as a cross join sa.ORDERS as b
WHERE a.c_custkey=b.o_custkey;

-- DB-94:( <query expression> ) AS <correlation name> (<derived column list>)
SELECT * FROM (select * from sa.customer as a cross join sa.ORDERS as b where a.c_custkey=b.o_custkey ) as temptable;

-- DB-95:( <query expression> ) <correlation name> (<derived column list>)
SELECT *
FROM (select * from sa.customer a cross join sa.ORDERS b where a.c_custkey=b.o_custkey )
temptable;

-- DB-96:<schema name> <period> <qualified identifier>
/* EMPTY */

-- DB-97:<qualified identifier>
/* EMPTY */

-- DB-98:<schema name> <period> <qualified identifier> <correlation name>
/* EMPTY */

-- DB-99:<schema name> <period> <qualified identifier> AS <correlation name>
/*EMPTY*/

-- DB-100:( <query expression> ) AS <correlation name> (<derived column list>)
select a, b from (select c_privilege_level, c_mktsegment from sa.CUSTOMER) AS cus(a, b);

-- DB-101:( <query expression> ) <correlation name> (<derived column list>)
select a, b from (select c_privilege_level, c_mktsegment from sa.CUSTOMER) cus(a, b);

-- DB-102:<left join> CROSS JOIN <table primary>
SELECT * FROM
sa.CUSTOMER
left join sa.ORDERS
cross join sa.Sales
on order_id=OrderID and c_custkey=o_custkey;

-- DB-103:<right join> CROSS JOIN <table primary>
SELECT * FROM
sa.CUSTOMER
right join sa.ORDERS
cross join sa.Sales
on order_id=OrderID and c_custkey=o_custkey;

-- DB-104:<full join> CROSS JOIN <table primary>
SELECT * FROM
sa.CUSTOMER
full join sa.ORDERS
cross join sa.Sales
on order_id=OrderID and c_custkey=o_custkey;

-- DB-105:<joined table><inner join><table primary>ON <search condition>
select a.*, b.* from (select * from sa.CUSTOMER) a inner join sa.CUSTOMER_COPY b on a.c_mktsegment = 'building' and a.customer_id = 4;

-- DB-106:<table primary><left join><table primary>ON <search condition>
select * from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on a.customer_id between 2 and 3;

-- DB-107:<table primary><right join><joined table>ON <search condition>
select * from sa.CUSTOMER a right join sa.CUSTOMER_COPY b on a.customer_id between 2 and 3;

-- DB-108:<joined table><full join><joined table>ON <search condition>
select * from sa.CUSTOMER a full join sa.CUSTOMER_COPY b on a.customer_id between 2 and 3;

-- DB-109:group by DISTINCT <grouping column reference>
/* EMPTY */

-- DB-110:group by ALL <grouping column reference>
SELECT customer_id,c_mktsegment FROM sa.CUSTOMER group by all customer_id,c_mktsegment;

-- DB-111:<column reference> COLLATE < collation_name>
SELECT SalesRep collate Latin1_General_CI_AI FROM sa.Sales group by SalesRep collate Latin1_General_CI_AI;
 SELECT SalesRep collate database_default FROM sa.Sales group by SalesRep collate database_default;

-- DB-113:MODULE <period> <qualified identifier> <period> <column name>
/* EMPTY */

-- DB-114:<identifier>
/* EMPTY */

-- DB-115:<identifier><period> <identifier>
SELECT OrderID,count(*) FROM sa.Sales group by OrderID;

-- DB-116:ROLLUP <ordinary grouping set list>
SELECT OrderID,count(*) FROM sa.Sales group by rollup(OrderID);

-- DB-117:CUBE <ordinary grouping set list>
SELECT OrderID,count(*) FROM sa.Sales group by cube(OrderID);

-- <marked error-todo GROUP BY> DB-118:<empty grouping set>
SELECT count(OrderID),sum(Qty) FROM sa.Sales group by();

-- <marked error-todo GROUP BY> DB-119:GROUPING SETS <ordinary grouping set>
SELECT OrderID,sum(Qty) FROM sa.Sales group by grouping sets ((OrderID),());

-- DB-120:<query primary> INTERSECT <query primary>
select c_mktsegment from sa.CUSTOMER intersect select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level =1;

-- DB-121:<query primary> INTERSECT <query primary> INTERSECT <query primary>
select c_mktsegment from sa.CUSTOMER INTERSECT select c_mktsegment from dbo.CUSTOMER_VIEW INTERSECT select c_mktsegment from sa.CUSTOMER_COPY;

-- DB-122:The priority for UNION, EXCEPT
select * from sa.CUSTOMER union all select * from sa.CUSTOMER_COPY EXCEPT select * from sa.CUSTOMER where c_privilege_level = 1;

-- <marked error-todo GROUP BY> DB-123:GROUPING SETS <rollup list>
SELECT OrderID,Qty
FROM sa.Sales
group by
grouping sets (rollup(OrderID),(Qty));

-- DB-124:GROUPING SETS <cube list>
/* EMPTY */

-- <marked error-todo GROUP BY> DB-125:GROUPING SETS<empty grouping set> (marked error)
SELECT OrderID,sum(Qty) FROM sa.Sales group by grouping sets ((OrderID),());

-- DB-126:<query expression body> UNION ALL <query term>
SELECT c_custkey,customer_id from sa.CUSTOMER
union all
select o_custkey,order_id from sa.ORDERS;

-- DB-127:<query expression body> UNION <query term>
SELECT c_custkey,customer_id from sa.CUSTOMER
union
select o_custkey,order_id from sa.ORDERS;

-- DB-129:<query expression body> EXCEPT <query term>
SELECT c_custkey,customer_id from sa.CUSTOMER
except
select c_custkey,customer_id from dbo.CUSTOMER_VIEW;

-- DB-130:<row value ctor> <comp op> <row value ctor>
select * from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id;

-- DB-131:<row value ctor> <comp op> <all> <subquery>
select * from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id <= all (select customer_id from sa.CUSTOMER);

-- DB-132:<row value ctor> <comp op> <some> <subquery>
select * from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = some (select customer_id from sa.CUSTOMER);

-- DB-133:<row value ctor> <comp op> <any> <subquery>
select * from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = any (select customer_id from sa.CUSTOMER);

-- DB-134:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
select * from sa.CUSTOMER a right join sa.CUSTOMER_COPY b on a.customer_id between 2 and 3;

-- DB-135:<row value ctor> NOT BETWEEN <row value ctor> AND <row value ctor>
select * from sa.CUSTOMER a right join sa.CUSTOMER_COPY b on a.customer_id not between 2 and 3;

-- DB-136:<row value ctor> LIKE <row value ctor>
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a right join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id AND a.c_mktsegment like 'Ca%';

-- DB-137:<row value ctor> NOT LIKE <row value ctor>
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a right join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id AND a.c_mktsegment not like 'Bu%';

-- DB-138:<row value ctor> IN <subquery>
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on a.c_mktsegment in (select c_mktsegment from sa.CUSTOMER_COPY);

-- DB-139:<row value ctor> NOT IN <subquery>
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on a.c_mktsegment not in (select c_mktsegment from sa.CUSTOMER_COPY);

-- DB-140:<row value ctor> IS NULL
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on a.c_mktsegment is null;

-- DB-141:<row value ctor> IS NOT NULL
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on a.c_mktsegment is not null;

-- DB-142:EXISTS <subquery>
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on exists(select * from sa.CUSTOMER where c_mktsegment is null);

-- DB-143:<row value ctor> IN ( <row value ctor list> )
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id or a.c_mktsegment in ('building','Catering');

-- DB-144:<row value ctor> NOT IN ( <row value ctor list> ）
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id or a.c_mktsegment not in ('building','Catering');

-- DB-146:Not <boolean factor>
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a left join sa.CUSTOMER_COPY b on NOT exists(select * from sa.CUSTOMER where c_mktsegment is null);

-- DB-147:<boolean term> AND <boolean factor>
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id AND a.c_mktsegment like'%bu%';

-- DB-148:<with clause>
with a(a_id, a_mktsegment) as
(select customer_id,c_mktsegment from sa.CUSTOMER)
select * from (select * from a where a.a_id<10)
as b;

-- DB-149:SELECT <select list> <table primary>
select * from (select customer_id,c_privilege_level from sa.CUSTOMER) as temptable;

-- DB-150:<query primary> INTERSECT <query primary>
select * from
(SELECT c_custkey,customer_id from sa.CUSTOMER
INTERSECT
select o_custkey,order_id from sa.ORDERS)
as c;

-- DB-151:<query expression body> UNION ALL <query term>
select * from (select c_custkey,customer_id from sa.CUSTOMER
union all
select o_custkey,order_id from sa.ORDERS)
as c;

-- DB-152:<query expression body> EXCEPT <query term>
select * from (select c_custkey,customer_id from sa.CUSTOMER
except
select c_custkey,customer_id from sa.CUSTOMER_COPY)
as c;

-- DB-153:<search condition> OR <boolean term>
select a.customer_id, a.c_mktsegment, b.customer_id, b.c_mktsegment from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on (a.customer_id = b.customer_id AND a.c_mktsegment like'%bu%') OR b.c_mktsegment = 'building';

-- DB-154:SELECT <select list> <joined table>
select * from (SELECT customer_id,c_mktsegment
FROM sa.CUSTOMER as a cross join sa.ORDERS as b
WHERE a.c_custkey=b.o_custkey)
as c;

-- DB-155:The priority for NOT, AND, OR
select a.customer_id, a.c_mktsegment,a.c_privilege_level, b.customer_id, b.c_mktsegment from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on NOT a.c_privilege_level < 0 OR a.customer_id = b.customer_id AND (a.c_mktsegment = 'building' OR b.c_mktsegment = 'building');

-- DB-156:<factor 4> ::= <column reference>
select CUSTOMER.customer_id, CUSTOMER.c_mktsegment, CUSTOMER_COPY.customer_id, CUSTOMER_COPY.c_mktsegment from sa.CUSTOMER inner join sa.CUSTOMER_COPY on test01.sa.CUSTOMER.customer_id = test01.sa.CUSTOMER_COPY.customer_id;

-- DB-157:<factor 4> ::= <expression const>
select a.customer_id, a.c_mktsegment,a.c_custkey, b.customer_id, b.c_mktsegment from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.c_mktsegment = N'retail' AND a.c_privilege_level = -1 AND a.c_custkey is not null;

-- DB-158:<factor 4> ::= <scalar function expression>
select a.*, b.* from sa.CUSTOMER_DEFAULT a inner join sa.CUSTOMER b on dbo.return0() in (select c_privilege_level from sa.CUSTOMER) AND ABS(b.c_privilege_level) = 1;

-- DB-159:<factor 4> ::= CAST <left paren> <row value ctor> AS <data type> <right paren>
select a.*, b.* from sa.CUSTOMER_DEFAULT a inner join sa.CUSTOMER_COPY b on CAST(a.salary AS int) > 1000;

-- DB-160:<factor 4> ::= COALESCE <left paren> <row value ctor> <right paren>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = coalesce(null,null,1 ,2);

-- DB-161:<factor 4> ::= CURRENT_TIMESTAMP
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on CURRENT_TIMESTAMP = getdate();

-- DB-162:<factor 4> ::= CURRENT_USER
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on CURRENT_USER = 'dbo';

-- DB-163:<factor 4> ::= SESSION_USER
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on SESSION_USER = 'dbo';

-- DB-164:<factor 4> ::= SYSTEM_USER
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on SYSTEM_USER = 'sa';

-- DB-165:<factor 4> ::= NULLIF <left paren> <row value ctor> <comma> <row value ctor> <right paren>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on NULLIF(a.c_privilege_level,-1) is null;

-- DB-166:<factor 4> ::= <subquery>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on (select c_privilege_level from sa.CUSTOMER_DEFAULT where c_create_date < '2019-05-16 00:59:13.740') = 1 and a.customer_id = b.customer_id;

-- DB-167:<factor 4> ::= <left paren> <row value ctor list> <right paren>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.c_privilege_level > 3 * ( 1 + 2) and a.customer_id = b.customer_id;

-- DB-168:CASE WHEN <search condition> THEN <row value ctor> END
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id AND CASE when 'retail' in(select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level < 0) then a.c_privilege_level END < 0;

-- DB-169:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> END
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on CASE a.c_mktsegment when 'retail' then a.c_privilege_level end = -1;

-- DB-170:CASE WHEN <search condition> THEN <row value ctor> ELSE <row value ctor> END
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id AND CASE when 'retail' not in (select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level >= 0) then a.c_privilege_level Else b.c_privilege_level END > 0;

-- DB-171:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id AND CASE a.c_mktsegment when 'Catering' then a.c_privilege_level ELSE b.c_privilege_level END = 1;

-- DB-172:<when clause list> ::= <when clause> <comma> <when clause>...
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id AND CASE when exists(select * from sa.CUSTOMER where c_mktsegment is null) then a.c_privilege_level when exists(select * from sa.CUSTOMER where c_mktsegment is not null) then a.customer_id ELSE b.c_privilege_level END = 1006;

-- DB-173:<factor 3> ::= <plus or minus op> <factor 4>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on (a.c_privilege_level = +2 OR a.c_privilege_level = -1) and a.customer_id = b.customer_id;

-- DB-174:<factor 2> ::= <factor 2> <circumflex> <factor 3>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.customer_id = b.customer_id and a.c_privilege_level > 3^5;

-- DB-175:<factor 1> ::= <factor 1> <mul op> <factor 2>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.c_privilege_level = -1*1 and a.customer_id = b.customer_id;

-- DB-176:<factor 1> ::= <factor 1> <div op> <factor 2>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)/2 and a.customer_id = b.customer_id;

-- DB-177:<factor 1> ::= <factor 1> <per op> <factor 2>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 5)%3 and a.customer_id = b.customer_id;

-- DB-178:<factor 0> ::= <factor 0> <plus op> <factor 1>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.c_mktsegment = 'ret'+'ail' and a.c_privilege_level = -2 + 1;

-- DB-179:<factor 0> ::= <factor 0> <minus op> <factor 1>
select a.*, b.* from sa.CUSTOMER a inner join sa.CUSTOMER_COPY b on a.c_mktsegment = 'ret'+'ail' and a.c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 2) - 2;

-- DB-180: CROSS JOIN
INSERT INTO TEST01.SA.CUSTOMER SELECT a.c_custkey, a.c_mktsegment, a.c_privilege_level FROM sa.CUSTOMER as a cross join sa.CUSTOMER_COPY as b WHERE a.c_privilege_level=b.c_privilege_level;

-- DB-182:<row value ctor> <comp op> <row value ctor>
select c_mktsegment, c_privilege_level, sum(c_privilege_level) total from sa.CUSTOMER group by c_mktsegment, c_privilege_level having c_privilege_level = +1 OR c_privilege_level = -1;

-- DB-183:<row value ctor> <comp op> <all> <subquery>
select customer_id, c_mktsegment, c_privilege_level from sa.CUSTOMER where c_privilege_level = 1 group by customer_id, c_privilege_level, c_mktsegment having c_privilege_level >= all(select c_privilege_level from sa.CUSTOMER_COPY);

-- DB-184:<row value ctor> <comp op> <some> <subquery>
select customer_id, c_mktsegment, c_privilege_level from sa.CUSTOMER where c_privilege_level = 1 group by customer_id, c_privilege_level, c_mktsegment having c_privilege_level > some(select c_privilege_level from sa.CUSTOMER_COPY);

-- DB-185:<row value ctor> <comp op> <any> <subquery>
select customer_id, c_mktsegment, c_privilege_level from sa.CUSTOMER where c_privilege_level = 1 group by customer_id, c_privilege_level, c_mktsegment having c_privilege_level > any(select c_privilege_level from sa.CUSTOMER_COPY);

-- DB-186:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
select customer_id, c_privilege_level from sa.CUSTOMER where c_mktsegment is null group by customer_id, c_privilege_level, c_mktsegment having c_privilege_level between 2 and 100;

-- DB-187:<row value ctor> NOT BETWEEN <row value ctor> AND <row value ctor>
select customer_id, c_privilege_level from sa.CUSTOMER where c_mktsegment is null group by customer_id, c_privilege_level, c_mktsegment having c_privilege_level not between 2 and 100;

-- DB-188:<row value ctor> LIKE <row value ctor>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER where c_privilege_level > 1 group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment like '%re%';

-- DB-189:<row value ctor> NOT LIKE <row value ctor>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER where c_privilege_level > 10 group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment not like '%bu%';

-- DB-190:<row value ctor> IN <subquery>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER where c_privilege_level < -1 group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment in (select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level >= 0);

-- DB-191:<row value ctor> NOT IN <subquery>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER where c_privilege_level < -1 group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment not in (select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level >= 0);

-- DB-192:<row value ctor> IS NULL
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER where c_privilege_level > 1 group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment is null;

-- DB-193:<row value ctor> IS NOT NULL
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER where c_privilege_level > 1 group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment is not null;

-- DB-194:EXISTS <subquery>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having exists(select * from sa.CUSTOMER where c_mktsegment is null) and c_privilege_level > 1;

-- DB-195:<row value ctor> IN ( <row value ctor list> )
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER where c_privilege_level < -1 group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment in ('building','FMCG');

-- DB-196:<row value ctor> NOT IN ( <row value ctor list> ）
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER where c_privilege_level < -1 group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment not in ('building','FMCG');

-- DB-197:Not <boolean factor>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having not exists(select * from sa.CUSTOMER where c_mktsegment = 'SA') and c_privilege_level > 1;

-- DB-198:<boolean term> AND <boolean factor>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having exists(select * from sa.CUSTOMER where c_mktsegment is null) and c_privilege_level > 1;

-- DB-199:<search condition> OR <boolean term>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having c_privilege_level < 0 or c_privilege_level >10;

-- DB-200:The priority for NOT, AND, OR
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having not c_privilege_level <= 0 or c_mktsegment = 'building' and (c_privilege_level > 10 or c_privilege_level <0);

-- DB-201:<factor 4> ::= <column reference>
select test01.sa.CUSTOMER.c_mktsegment from sa.CUSTOMER group by test01.sa.CUSTOMER.c_mktsegment, test01.sa.CUSTOMER.c_privilege_level having test01.sa.CUSTOMER.c_privilege_level < 1;

-- DB-202:<factor 4> ::= <expression const>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having c_mktsegment = N'retail' AND c_privilege_level > -1 ;

-- DB-203:<factor 4> ::= <scalar function expression>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having ABS(c_privilege_level) = 2 or c_privilege_level = dbo.return0();

-- DB-204:<factor 4> ::= CAST <left paren> <row value ctor> AS <data type> <right paren>
select customer_id, c_privilege_level, c_mktsegment, salary from sa.CUSTOMER_DEFAULT group by customer_id, c_privilege_level, c_mktsegment, salary having CAST(salary AS int) = 1000;

-- DB-205:<factor 4> ::= COALESCE <left paren> <row value ctor> <right paren>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having c_privilege_level > coalesce(null,null,1 ,2);

-- DB-206:<factor 4> ::= CURRENT_TIMESTAMP
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having CURRENT_TIMESTAMP = getdate();

-- DB-207:<factor 4> ::= CURRENT_USER
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having CURRENT_USER = 'dbo';

-- DB-208:<factor 4> ::= SESSION_USER
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having SESSION_USER = 'dbo';

-- DB-209:<factor 4> ::= SYSTEM_USER
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having SYSTEM_USER = 'sa';

-- DB-210:<factor 4> ::= NULLIF <left paren> <row value ctor> <comma> <row value ctor> <right paren>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having NULLIF(c_privilege_level,-2) is null;

-- DB-211:<factor 4> ::= <subquery>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having (select c_privilege_level from sa.CUSTOMER where c_mktsegment = 'retail') > 1;

-- DB-212:<factor 4> ::= <left paren> <row value ctor list> <right paren>
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having c_privilege_level > -1 * (2+1);

-- DB-213:<factor 3> ::= <plus or minus op> <factor 4>
select c_mktsegment, c_privilege_level, sum(c_privilege_level) total from sa.CUSTOMER group by c_mktsegment, c_privilege_level having c_privilege_level = +1 OR c_privilege_level = -1;

-- DB-214:<factor 2> ::= <factor 2> <circumflex> <factor 3>
select c_mktsegment, c_privilege_level, sum(c_privilege_level) total from sa.CUSTOMER group by c_mktsegment, c_privilege_level having c_privilege_level > 3^5;

-- DB-215:<factor 1> ::= <factor 1> <mul op> <factor 2>
select c_privilege_level, sum(c_privilege_level) total from sa.CUSTOMER group by c_mktsegment, c_privilege_level having c_privilege_level = -1*1;

-- DB-216:<factor 1> ::= <factor 1> <div op> <factor 2>
select c_mktsegment, c_privilege_level, sum(c_privilege_level) total from sa.CUSTOMER group by c_mktsegment, c_privilege_level having c_privilege_level = 2/2;

-- DB-217:<factor 1> ::= <factor 1> <per op> <factor 2>
select c_mktsegment, c_privilege_level, sum(c_privilege_level) total from sa.CUSTOMER group by c_mktsegment, c_privilege_level having c_privilege_level = 4%3;

-- DB-218:<factor 0> ::= <factor 0> <plus op> <factor 1>
select c_mktsegment, c_privilege_level, sum(c_privilege_level) total from sa.CUSTOMER group by c_mktsegment, c_privilege_level having (select c_privilege_level from sa.CUSTOMER where customer_id = 1) > -3 + 2 and c_privilege_level > -3+4;

-- DB-219:<factor 0> ::= <factor 0> <minus op> <factor 1>
select c_mktsegment, c_privilege_level, sum(c_privilege_level) total from sa.CUSTOMER group by c_mktsegment, c_privilege_level having (select c_privilege_level from sa.CUSTOMER where customer_id = 1) > 1-2 and c_privilege_level > 1-2;

-- DB-220:<subquery>
INSERT INTO TEST01.SA.CUSTOMER (c_custkey, c_mktsegment, c_privilege_level) select * from (select c_custkey, c_mktsegment, c_privilege_level from sa.CUSTOMER_COPY) as temptable;

-- DB-221:CASE WHEN <search condition> THEN <row value ctor> END
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having CASE when 'FMCG' in(select c_mktsegment from sa.CUSTOMER where c_privilege_level < 0) then c_privilege_level END < 0;

-- DB-222:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> END
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having CASE c_mktsegment when 'retail' then c_privilege_level end > 0;

-- DB-223:CASE WHEN <search condition> THEN <row value ctor> ELSE <row value ctor> END
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having CASE when 'FMCG' in(select c_mktsegment from sa.CUSTOMER where c_privilege_level > 0) then c_privilege_level ELSE customer_id END > 10;

-- DB-224:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
select customer_id, c_privilege_level, c_mktsegment from sa.CUSTOMER group by customer_id, c_privilege_level, c_mktsegment having CASE c_mktsegment when 'retails' then c_privilege_level ELSE customer_id end > 30;

-- DB-225:<when clause list> ::= <when clause> <comma> <when clause>...
select customer_id, c_privilege_level, c_mktsegment,salary from sa.CUSTOMER_DEFAULT group by customer_id, c_privilege_level, c_mktsegment, salary having CASE c_mktsegment when 'Education' then c_privilege_level when 'building' then salary  ELSE customer_id end > 1;

-- DB-226:<row value ctor> <comp op> <row value ctor>
select * from sa.CUSTOMER where c_privilege_level = 1;

-- DB-227:<row value ctor> <comp op> <all> <subquery>
select * from sa.CUSTOMER where customer_id < all (select customer_id from sa.CUSTOMER_COPY);

-- DB-228:<row value ctor> <comp op> <some> <subquery>
select * from sa.CUSTOMER where customer_id = some (select customer_id from sa.CUSTOMER_COPY);

-- DB-229:<row value ctor> <comp op> <any> <subquery>
select * from sa.CUSTOMER where customer_id = any (select customer_id from sa.CUSTOMER_COPY);

-- DB-230:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
select * from sa.CUSTOMER  where customer_id between 2 and 3;

-- DB-231:<row value ctor> NOT BETWEEN <row value ctor> AND <row value ctor>
select * from sa.CUSTOMER  where customer_id not between 2 and 10;

-- DB-232:<row value ctor> LIKE <row value ctor>
select customer_id, c_mktsegment from sa.CUSTOMER where c_mktsegment like 'Ca%';

-- DB-233:<row value ctor> NOT LIKE <row value ctor>
select customer_id, c_mktsegment from sa.CUSTOMER where c_mktsegment NOT like 'Ca%';

-- DB-234:<row value ctor> IN <subquery>
select customer_id, c_mktsegment AS "Select c_mktsegment" from sa.CUSTOMER where c_mktsegment in (select distinct c_mktsegment from sa.CUSTOMER_COPY);

-- DB-235:<row value ctor> NOT IN <subquery>
select customer_id, c_mktsegment "(Select c_mktsegment)",c_privilege_level from sa.CUSTOMER where c_privilege_level not in (select distinct c_privilege_level from sa.CUSTOMER_COPY);

-- DB-236:<row value ctor> IS NULL
select customer_id, c_mktsegment,c_custkey from sa.CUSTOMER where c_custkey is null;

-- DB-237:<row value ctor> IS NOT NULL
select customer_id, c_mktsegment,c_custkey from sa.CUSTOMER where c_custkey is not null;

-- DB-238:EXISTS <subquery>
select * from sa.CUSTOMER where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail');

-- DB-239:<row value ctor> IN ( <row value ctor list> )
select * from sa.CUSTOMER where c_mktsegment in ('building','Catering');

-- DB-240:<row value ctor> NOT IN ( <row value ctor list> ）
select * from sa.CUSTOMER where c_mktsegment not in ('building','Catering');

-- DB-241:Not <boolean factor>
select * from sa.CUSTOMER where not exists(select * from sa.CUSTOMER where c_privilege_level = 2);

-- DB-242:<boolean term> AND <boolean factor>
select a.*, b.* from test01.sa.CUSTOMER a, test01.sa.CUSTOMER_COPY b where a.customer_id = b.customer_id AND a.c_mktsegment like'%bu%';

-- DB-243:<search condition> OR <boolean term>
select a.*from sa.CUSTOMER a where a.c_privilege_level = -1 OR a.c_mktsegment = 'building' ;

-- DB-244:The priority for NOT, AND, OR
select a.customer_id, a.c_mktsegment,a.c_privilege_level, b.customer_id, b.c_mktsegment from sa.CUSTOMER a, sa.CUSTOMER_COPY b where NOT a.c_privilege_level < 0 OR a.customer_id = b.customer_id AND (a.c_mktsegment = 'building' OR b.c_mktsegment = 'building');

-- DB-245:<factor 4> ::= <column reference>
select CUSTOMER.customer_id, CUSTOMER.c_mktsegment, CUSTOMER_COPY.customer_id, CUSTOMER_COPY.c_mktsegment from sa.CUSTOMER, sa.CUSTOMER_COPY where test01.sa.CUSTOMER.customer_id = test01.sa.CUSTOMER_COPY.customer_id;

-- DB-246:<factor 4> ::= <expression const>
select a.* from sa.CUSTOMER a where a.c_mktsegment = N'retail' OR a.c_privilege_level = -1 AND a.c_custkey is not null;

-- DB-247:<factor 4> ::= <scalar function expression>
select a.* from sa.CUSTOMER a where dbo.return0() in (select c_privilege_level from sa.CUSTOMER) AND ABS(a.c_privilege_level) = 1;

-- DB-248:<factor 4> ::= CAST <left paren> <row value ctor> AS <data type> <right paren>
select a.*, CAST(a.salary AS int) Salary_INT from sa.CUSTOMER_DEFAULT a where CAST(a.salary AS int) > 1000;

-- DB-249:<factor 4> ::= COALESCE <left paren> <row value ctor> <right paren>
select a.* from sa.CUSTOMER a where a.customer_id = coalesce(null,null,1 ,2);

-- DB-250:<factor 4> ::= CURRENT_TIMESTAMP
select * from sa.CUSTOMER where CURRENT_TIMESTAMP = getdate();

-- DB-251:<factor 4> ::= CURRENT_USER
select * from sa.CUSTOMER where CURRENT_USER = 'dbo';

-- DB-252:<factor 4> ::= SESSION_USER
select * from sa.CUSTOMER where SESSION_USER = 'dbo';

-- DB-253:<factor 4> ::= SYSTEM_USER
select * from sa.CUSTOMER where SYSTEM_USER = 'sa';

-- DB-254:<factor 4> ::= NULLIF <left paren> <row value ctor> <comma> <row value ctor> <right paren>
select a.* from sa.CUSTOMER a where NULLIF(a.c_privilege_level,-1) is null;

-- DB-255:<factor 4> ::= <subquery>
select a.*, b.* from sa.CUSTOMER a, sa.CUSTOMER_COPY b where a.c_privilege_level <(select sum(c_privilege_level) from sa.CUSTOMER_COPY where c_mktsegment = 'building') and a.customer_id = b.customer_id;

-- DB-256:<factor 4> ::= <left paren> <row value ctor list> <right paren>
select a.* from sa.CUSTOMER a where a.c_privilege_level = -1*(1+1);

-- DB-257:<factor 3> ::= <plus or minus op> <factor 4>
select a.* from sa.CUSTOMER a where a.c_privilege_level = +2 OR a.c_privilege_level = -1;

-- DB-258:<factor 2> ::= <factor 2> <circumflex> <factor 3>
select a.* from sa.CUSTOMER a where a.c_privilege_level > 3^5;

-- DB-259:<factor 1> ::= <factor 1> <mul op> <factor 2>
select a.* from sa.CUSTOMER a where a.c_privilege_level = 2*1;

-- DB-260:<factor 1> ::= <factor 1> <div op> <factor 2>
select * from sa.CUSTOMER where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)/2;

-- DB-261:<factor 1> ::= <factor 1> <per op> <factor 2>
select * from sa.CUSTOMER where c_privilege_level = 4%2;

-- DB-262:<factor 0> ::= <factor 0> <plus op> <factor 1>
select * from sa.CUSTOMER where c_mktsegment = 'ret'+'ail';

-- DB-263:<factor 0> ::= <factor 0> <minus op> <factor 1>
select * from sa.CUSTOMER where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)-2;

-- DB-264:<joined table><inner join><table primary>ON <search condition>
INSERT INTO TEST01.SA.CUSTOMER select a.c_custkey, a.c_mktsegment, a.c_privilege_level from (select * from sa.CUSTOMER) a inner join sa.CUSTOMER_COPY b on a.c_mktsegment = 'building' and a.customer_id = 4;

-- DB-265:CASE WHEN <search condition> THEN <row value ctor> END
select a.* from sa.CUSTOMER a where CASE when 'building' in(select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level < 0) then a.c_privilege_level END < 0;

-- DB-266:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> END
select a.* from sa.CUSTOMER a where CASE a.c_mktsegment when 'retail' then a.c_privilege_level end = -1;

-- DB-267:CASE WHEN <search condition> THEN <row value ctor> ELSE <row value ctor> END
select a.*, b.* from sa.CUSTOMER a, sa.CUSTOMER_COPY b where a.customer_id = b.customer_id AND CASE when 'retail' not in (select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level >= 0) then a.c_privilege_level Else b.c_privilege_level END > 0;

-- DB-268:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
select a.*, b.* from sa.CUSTOMER a, sa.CUSTOMER_COPY b where a.customer_id = b.customer_id AND CASE a.c_mktsegment when 'Catering' then a.c_privilege_level ELSE b.c_privilege_level END = 1;

-- DB-269:<when clause list> ::= <when clause> <comma> <when clause>...
select a.*, b.* from sa.CUSTOMER a, sa.CUSTOMER_COPY b where a.customer_id = b.customer_id AND CASE when exists(select * from sa.CUSTOMER where c_mktsegment is null) then a.c_privilege_level when exists(select * from sa.CUSTOMER where c_mktsegment is not null) then a.customer_id ELSE b.c_privilege_level END = 1006;

-- DB-270:<row value ctor> <comp op> <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = 1;

-- DB-271:<row value ctor> <comp op> <all> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id > all (select customer_id from sa.CUSTOMER_COPY);

-- DB-272:<row value ctor> <comp op> <some> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id = some (select customer_id from sa.CUSTOMER_COPY);

-- DB-273:<row value ctor> <comp op> <any> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id = any (select customer_id from sa.CUSTOMER_COPY);

-- DB-274:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id between 2 and 3;

-- DB-275:<row value ctor> NOT BETWEEN <row value ctor> AND <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id not between 2 and 10;

-- DB-276:<row value ctor> LIKE <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment like 'Ca%';

-- DB-277:<row value ctor> NOT LIKE <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment NOT like 'Ca%';

-- DB-278:<row value ctor> IN <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment in (select distinct c_mktsegment from sa.CUSTOMER_COPY);

-- DB-279:<row value ctor> NOT IN <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level not in (select distinct c_privilege_level from sa.CUSTOMER_COPY);

-- DB-280:<row value ctor> IS NULL
update sa.CUSTOMER set c_mktsegment = 'retail' where c_custkey is null;

-- DB-281:<row value ctor> IS NOT NULL
update sa.CUSTOMER set c_mktsegment = 'retail' where c_custkey is not null;

-- DB-282:EXISTS <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail');

-- DB-283:<row value ctor> IN ( <row value ctor list> )
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment in ('building','Catering');

-- DB-284:<row value ctor> NOT IN ( <row value ctor list> ）
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment not in ('building','Catering');

-- DB-285:Not <boolean factor>
update sa.CUSTOMER set c_mktsegment = 'retail' where not exists(select * from sa.CUSTOMER where c_privilege_level = 2);

-- DB-286:<boolean term> AND <boolean factor>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level < 0 AND c_mktsegment like'%bu%';

-- DB-287:<search condition> OR <boolean term>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = -1 OR c_mktsegment = 'building';

-- DB-288:The priority for NOT, AND, OR
update sa.CUSTOMER_DEFAULT set c_mktsegment = 'retail' where NOT c_privilege_level < 0 OR customer_id > 10 AND (c_mktsegment = 'building' OR salary > 1000);

-- DB-289:<factor 4> ::= <column reference>
update sa.CUSTOMER set c_mktsegment = 'retail' where test01.sa.CUSTOMER.customer_id in (select customer_id from test01.sa.CUSTOMER_COPY);

-- DB-290:<factor 4> ::= <expression const>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment = N'retail' OR c_privilege_level = -1 AND c_custkey is not null;

-- DB-291:<factor 4> ::= <scalar function expression>
update sa.CUSTOMER set c_mktsegment = 'retail' where dbo.return0() in (select c_privilege_level from sa.CUSTOMER) AND ABS(c_privilege_level) = 1;

-- DB-292:<factor 4> ::= CAST <left paren> <row value ctor> AS <data type> <right paren>
update sa.CUSTOMER_DEFAULT set c_mktsegment = 'retail' where CAST(salary AS int) > 1000;

-- DB-293:<factor 4> ::= COALESCE <left paren> <row value ctor> <right paren>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id = coalesce(null,null,1 ,2);

-- DB-294:<factor 4> ::= CURRENT_TIMESTAMP
update sa.CUSTOMER_DEFAULT set c_mktsegment = 'retail' where c_create_date < CURRENT_TIMESTAMP;

-- DB-295:<factor 4> ::= CURRENT_USER
update sa.CUSTOMER set c_mktsegment = 'retail'  where CURRENT_USER = 'dbo';

-- DB-296:<factor 4> ::= SESSION_USER
update sa.CUSTOMER set c_mktsegment = 'retail' where SESSION_USER = 'dbo';

-- DB-297:<factor 4> ::= SYSTEM_USER
update sa.CUSTOMER set c_mktsegment = 'retail' where SYSTEM_USER = 'sa';

-- DB-298:<factor 4> ::= NULLIF <left paren> <row value ctor> <comma> <row value ctor> <right paren>
update sa.CUSTOMER set c_mktsegment = 'retail' where NULLIF(c_privilege_level,-1) is null;

-- DB-299:<factor 4> ::= <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where (select sum(c_privilege_level) from sa.CUSTOMER where c_mktsegment = 'building') < 0;

-- DB-300:<factor 4> ::= <left paren> <row value ctor list> <right paren>
update sa.CUSTOMER set c_mktsegment = 'retail' where -1 * (NULLIF(a.c_privilege_level,-1) + 3) <= 0;

-- DB-301:<factor 3> ::= <plus or minus op> <factor 4>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = +1 OR c_privilege_level = -1;

-- DB-302:<factor 2> ::= <factor 2> <circumflex> <factor 3>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level > 3^5;

-- DB-303:<factor 1> ::= <factor 1> <mul op> <factor 2>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = -1*1;

-- DB-304:<factor 1> ::= <factor 1> <div op> <factor 2>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = 4/2;

-- DB-305:<factor 1> ::= <factor 1> <per op> <factor 2>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = 4%2;

-- DB-306:<factor 0> ::= <factor 0> <plus op> <factor 1>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = 1+1;

-- DB-307:<factor 0> ::= <factor 0> <minus op> <factor 1>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)-1;

-- DB-308:<row value ctor> ::= <row value ctor> <cnn op> <factor 0>
/* EMPTY */

-- DB-309:CASE WHEN <search condition> THEN <row value ctor> END
update sa.CUSTOMER set c_mktsegment = 'retail' where Case when 'building' in(select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level < 0) then c_privilege_level END < 0;

-- DB-310:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> END
update sa.CUSTOMER set c_mktsegment = 'retail' where CASE c_mktsegment when 'retail' then c_privilege_level end = -1;

-- DB-311:CASE WHEN <search condition> THEN <row value ctor> ELSE <row value ctor> END
update sa.CUSTOMER set c_mktsegment = 'retail' where CASE when 'retail' not in (select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level >= 0) then c_privilege_level Else customer_id END > 1;

-- DB-312:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
update sa.CUSTOMER set c_mktsegment = 'retail' where CASE c_mktsegment when 'Catering' then c_privilege_level ELSE customer_id END = 1;

-- DB-313:<when clause list> ::= <when clause> <comma> <when clause>...
update sa.CUSTOMER_DEFAULT set c_mktsegment = 'retail' where CASE when exists(select * from sa.CUSTOMER where c_mktsegment is null) then c_privilege_level when exists(select * from sa.CUSTOMER where c_mktsegment is not null) then customer_id ELSE salary END > 1;

-- DB-314:<row value ctor> <comp op> <all> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id > all (select customer_id from sa.CUSTOMER_COPY);

-- DB-315:<row value ctor> <comp op> <some> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id = some (select customer_id from sa.CUSTOMER_COPY);

-- DB-316:<row value ctor> <comp op> <row value ctor>
delete from sa.CUSTOMER where c_privilege_level = 1;

-- DB-317:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
delete from sa.CUSTOMER where customer_id between 2 and 3;

-- DB-318:<row value ctor> NOT BETWEEN <row value ctor> AND <row value ctor>
delete from sa.CUSTOMER where customer_id not between 2 and 10;

-- DB-319:<row value ctor> LIKE <row value ctor>
delete from sa.CUSTOMER where c_mktsegment like 'Ca%';

-- DB-320:<row value ctor> NOT LIKE <row value ctor>
delete from sa.CUSTOMER where c_mktsegment not like 'Ca%' and c_privilege_level = 1;

-- DB-321:<row value ctor> IN <subquery>
delete from sa.CUSTOMER where c_mktsegment in (select distinct c_mktsegment from sa.CUSTOMER_COPY) and c_privilege_level = 1;

-- DB-322:<row value ctor> NOT IN <subquery>
delete from sa.CUSTOMER where c_privilege_level not in (select distinct c_privilege_level from sa.CUSTOMER_COPY) and c_mktsegment = 'retail';

-- DB-323:<row value ctor> IS NULL
delete from sa.CUSTOMER where (select c_custkey from sa.CUSTOMER_COPY where c_custkey is null) is null and c_privilege_level = 1;

-- DB-324:<row value ctor> IS NOT NULL
delete from sa.CUSTOMER where (select c_custkey from sa.CUSTOMER_COPY where c_custkey is null) is not null and c_privilege_level = 0;

-- DB-325:EXISTS <subquery>
delete from sa.CUSTOMER where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail') and c_privilege_level = 2;

-- DB-326:<row value ctor> IN ( <row value ctor list> )
delete from sa.CUSTOMER where(select c_mktsegment from sa.CUSTOMER_COPY where customer_id = 1) in ('building','Catering');

-- DB-327:<row value ctor> NOT IN ( <row value ctor list> ）
delete from sa.CUSTOMER where c_mktsegment not in ('building','Catering');

-- DB-328:Not <boolean factor>
delete from sa.CUSTOMER where not exists(select * from sa.CUSTOMER where c_privilege_level = 2);

-- DB-329:<boolean term> AND <boolean factor>
delete from sa.CUSTOMER where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail') and c_privilege_level = 2;

-- DB-330:<search condition> OR <boolean term>
delete from sa.CUSTOMER where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail') OR c_privilege_level = 2;

-- DB-331:The priority for NOT, AND, OR
delete from sa.CUSTOMER where NOT c_privilege_level < 0 OR c_privilege_level = -2 AND (c_mktsegment = 'building' OR (select c_mktsegment from sa.CUSTOMER_COPY where customer_id = 1005) = 'retail');

-- DB-332:<factor 4> ::= <column reference>
delete from test01.sa.CUSTOMER where exists(select * from test01.sa.CUSTOMER where test01.sa.CUSTOMER.c_mktsegment = 'retail') OR test01.sa.CUSTOMER.c_privilege_level = 2;

-- DB-333:<factor 4> ::= <expression const>
delete from sa.CUSTOMER where c_mktsegment = N'retail' OR c_privilege_level = -1 AND c_custkey is not null;

-- DB-334:<factor 4> ::= <scalar function expression>
delete from sa.CUSTOMER where dbo.return0() in (select c_privilege_level from sa.CUSTOMER) AND ABS(c_privilege_level) = 1;

-- DB-335:<factor 4> ::= CAST <left paren> <row value ctor> AS <data type> <right paren>
delete from sa.CUSTOMER_DEFAULT  where CAST(salary AS int) > 1000;

-- DB-336:<factor 4> ::= COALESCE <left paren> <row value ctor> <right paren>
delete from sa.CUSTOMER where customer_id = coalesce(null,null,1 ,2);

-- DB-337:<factor 4> ::= CURRENT_TIMESTAMP
delete from sa.CUSTOMER where CURRENT_TIMESTAMP = getdate() and c_privilege_level = 1;

-- DB-338:<factor 4> ::= CURRENT_USER
delete from sa.CUSTOMER where CURRENT_USER = 'dbo' and c_privilege_level = 1;

-- DB-339:<factor 4> ::= SESSION_USER
delete from sa.CUSTOMER where SESSION_USER = 'dbo' and c_privilege_level = 1;

-- DB-340:<factor 4> ::= SYSTEM_USER
delete from sa.CUSTOMER where SYSTEM_USER = 'sa' and c_privilege_level = 1;

-- DB-341:<factor 4> ::= NULLIF <left paren> <row value ctor> <comma> <row value ctor> <right paren>  <marked error>
--delete from sa.CUSTOMER sa.CUSTOMER where NULLIF(c_privilege_level,1) is null;

-- DB-342:<factor 4> ::= <subquery>
delete from sa.CUSTOMER where (select sum(c_privilege_level) from sa.CUSTOMER where c_mktsegment = 'building') < 0 and customer_id = 3;

-- DB-343:<factor 4> ::= <left paren> <row value ctor list> <right paren>
delete from sa.CUSTOMER where -1 * (NULLIF(c_privilege_level,-1) + 2) >= 0;

-- DB-344:<factor 3> ::= <plus or minus op> <factor 4>
delete from sa.CUSTOMER where c_privilege_level = +1 OR c_privilege_level = -1;

-- DB-345:<factor 2> ::= <factor 2> <circumflex> <factor 3>
delete from sa.CUSTOMER where c_privilege_level > 3^5;

-- DB-346:<factor 1> ::= <factor 1> <mul op> <factor 2>
delete from sa.CUSTOMER where c_privilege_level = -1*1;

-- DB-347:<factor 1> ::= <factor 1> <div op> <factor 2>
delete from sa.CUSTOMER where c_privilege_level = 4/2;

-- DB-348:<factor 1> ::= <factor 1> <per op> <factor 2>
delete from sa.CUSTOMER where c_privilege_level = 4%2;

-- DB-349:<factor 0> ::= <factor 0> <plus op> <factor 1>
delete from sa.CUSTOMER where c_privilege_level = 1+1;

-- DB-350:<factor 0> ::= <factor 0> <minus op> <factor 1>
delete from sa.CUSTOMER where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)-1;

-- DB-351:CASE WHEN <search condition> THEN <row value ctor> END
INSERT INTO TEST01.SA.CUSTOMER VALUES ('breakingbad', (select CASE when customer_id = 1 then c_mktsegment end from test01.sa.CUSTOMER_COPY where customer_id = 1005), 0);

-- DB-352:<row value ctor> <comp op> <some> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id = some (select customer_id from sa.CUSTOMER_COPY);

-- DB-353:<row value ctor> <comp op> <all> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id > all (select customer_id from sa.CUSTOMER_COPY);

-- DB-354:CASE WHEN <search condition> THEN <row value ctor> END
delete from sa.CUSTOMER where CASE when 'retail' in(select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level < 0) then c_privilege_level END < 0;

-- DB-355:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> END
delete from sa.CUSTOMER where CASE c_mktsegment when 'retail' then c_privilege_level end = -1;

-- DB-356:CASE WHEN <search condition> THEN <row value ctor> ELSE <row value ctor> END
delete from sa.CUSTOMER_DEFAULT where CASE when 'retail' not in (select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level >= 0) then c_privilege_level Else salary END > 1000;

-- DB-357:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
delete from sa.CUSTOMER_DEFAULT where CASE c_mktsegment when 'Catering' then c_privilege_level ELSE salary END = 1;

-- DB-358:<when clause list> ::= <when clause> <comma> <when clause>...
delete from sa.CUSTOMER_DEFAULT where CASE when exists(select * from sa.CUSTOMER where c_mktsegment is null) then c_privilege_level when exists(select * from sa.CUSTOMER where c_mktsegment is not null) then customer_id ELSE salary END = 1006;

-- DB-359:<row value ctor> <comp op> <any> <subquery>
delete from sa.CUSTOMER_COPY where customer_id = any (select customer_id from sa.CUSTOMER_COPY) and customer_id = 1;

-- DB-360:<row value ctor> <comp op> <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = (select c_privilege_level from sa.CUSTOMER_COPY where customer_id = 1);

-- DB-361:<row value ctor> <comp op> <all> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id > all (select customer_id from sa.CUSTOMER_COPY);

-- DB-362:<row value ctor> <comp op> <some> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id = some (select customer_id from sa.CUSTOMER_COPY);

-- DB-363:<row value ctor> <comp op> <any> <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id = any (select customer_id from sa.CUSTOMER_COPY);

-- DB-364:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id between 2 and 3;

-- DB-365:<row value ctor> NOT BETWEEN <row value ctor> AND <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id not between 2 and 10;

-- DB-366:<row value ctor> LIKE <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment like 'Ca%';

-- DB-367:<row value ctor> NOT LIKE <row value ctor>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment NOT like 'Ca%';

-- DB-368:<row value ctor> IN <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment in (select distinct c_mktsegment from sa.CUSTOMER_COPY);

-- DB-369:<row value ctor> NOT IN <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level not in (select distinct c_privilege_level from sa.CUSTOMER_COPY);

-- DB-370:<row value ctor> IS NULL
update sa.CUSTOMER set c_mktsegment = 'retail' where c_custkey is null;

-- DB-371:<row value ctor> IS NOT NULL
update sa.CUSTOMER set c_mktsegment = 'retail' where c_custkey is not null;

-- DB-372:EXISTS <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail');

-- DB-373:<row value ctor> IN ( <row value ctor list> )
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment in ('building','Catering');

-- DB-374:<row value ctor> NOT IN ( <row value ctor list> ）
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment not in ('building','Catering');

-- DB-375:Not <boolean factor>
update sa.CUSTOMER set c_mktsegment = 'retail' where not exists(select * from sa.CUSTOMER where c_privilege_level = 2);

-- DB-376:<boolean term> AND <boolean factor>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level < 0 AND c_mktsegment like'%bu%';

-- DB-377:<search condition> OR <boolean term>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = -1 OR c_mktsegment = 'building' ;

-- DB-378:The priority for NOT, AND, OR
update sa.CUSTOMER_DEFAULT set c_mktsegment = 'retail' where NOT c_privilege_level < 0 OR customer_id > 10 AND (c_mktsegment = 'building' OR salary > 1000);

-- DB-379:<factor 4> ::= <column reference>
update sa.CUSTOMER set c_mktsegment = 'retail' where test01.sa.CUSTOMER.customer_id in (select customer_id from test01.sa.CUSTOMER_COPY);

-- DB-380:<factor 4> ::= <expression const>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_mktsegment = N'retail' OR c_privilege_level = -1 AND c_custkey is not null;

-- DB-381:<factor 4> ::= <scalar function expression>
update sa.CUSTOMER set c_mktsegment = 'retail' where dbo.return0() in (select c_privilege_level from sa.CUSTOMER) AND ABS(c_privilege_level) = 1;

-- DB-382:<factor 4> ::= CAST <left paren> <row value ctor> AS <data type> <right paren>
update sa.CUSTOMER_DEFAULT set c_mktsegment = 'retail' where CAST(salary AS int) > 1000;

-- DB-383:<factor 4> ::= COALESCE <left paren> <row value ctor> <right paren>
update sa.CUSTOMER set c_mktsegment = 'retail' where customer_id = coalesce(null,null,1 ,2);

-- DB-384:<factor 4> ::= CURRENT_TIMESTAMP
update sa.CUSTOMER_DEFAULT set c_mktsegment = 'retail' where c_create_date < CURRENT_TIMESTAMP;

-- DB-385:<factor 4> ::= NULLIF <left paren> <row value ctor> <comma> <row value ctor> <right paren>
update sa.CUSTOMER set c_mktsegment = 'retail' where NULLIF(c_privilege_level,-1) is null;

-- DB-386:<factor 4> ::= <subquery>
update sa.CUSTOMER set c_mktsegment = 'retail' where (select sum(c_privilege_level) from sa.CUSTOMER where c_mktsegment = 'building') < 0 ;

-- DB-387:<factor 4> ::= <left paren> <row value ctor list> <right paren>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = ((select c_privilege_level from sa.CUSTOMER where customer_id = 4) + 1) * 2;

-- DB-388:<factor 3> ::= <plus or minus op> <factor 4>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = +(select c_privilege_level from sa.CUSTOMER where customer_id = 1) OR c_privilege_level = -1;

-- DB-389:<factor 2> ::= <factor 2> <circumflex> <factor 3>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level > (select c_privilege_level from sa.CUSTOMER where customer_id = 1) ^ 1;

-- DB-390:<factor 1> ::= <factor 1> <mul op> <factor 2>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = 1*-(select c_privilege_level from sa.CUSTOMER where customer_id = 2);

-- DB-391:<factor 1> ::= <factor 1> <div op> <factor 2>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)/2;

-- DB-392:<factor 1> ::= <factor 1> <per op> <factor 2>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)%2;

-- DB-393:<factor 0> ::= <factor 0> <plus op> <factor 1>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)+1;

-- DB-394:<factor 0> ::= <factor 0> <minus op> <factor 1>
update sa.CUSTOMER set c_mktsegment = 'retail' where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)-1;

-- DB-395:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
INSERT INTO TEST01.SA.CUSTOMER select * from sa.CUSTOMER_COPY where customer_id between 1005 and 1006;

-- DB-396:CASE WHEN <search condition> THEN <row value ctor> END
update sa.CUSTOMER set c_mktsegment = 'retail' where Case when 'building' in(select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level < 0) then c_privilege_level END < 0;

-- DB-397:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> END
update sa.CUSTOMER set c_mktsegment = 'retail' where CASE c_mktsegment when 'retail' then c_privilege_level end = -1;

-- DB-398:CASE WHEN <search condition> THEN <row value ctor> ELSE <row value ctor> END
update sa.CUSTOMER set c_mktsegment = 'retail' where CASE when 'retail' not in (select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level >= 0) then c_privilege_level Else customer_id END > 1;

-- DB-399:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
update sa.CUSTOMER set c_mktsegment = 'retail' where CASE c_mktsegment when 'Catering' then c_privilege_level ELSE customer_id END = 1;

-- DB-400:<when clause list> ::= <when clause> <comma> <when clause>...
update sa.CUSTOMER_DEFAULT set c_mktsegment = 'retail' where CASE when exists(select * from sa.CUSTOMER where c_mktsegment is null) then c_privilege_level when exists(select * from sa.CUSTOMER where c_mktsegment is not null) then customer_id ELSE salary END > 1;

-- DB-402:SELECT <select list> <table primary>
with a(a_id, a_mktsegment) as
(select customer_id,c_mktsegment from sa.CUSTOMER)
select * from a where a_id<10;

-- DB-403:<query primary> INTERSECT <query primary>
with a(a_id, a_custkey) as
(select customer_id, c_custkey from sa.CUSTOMER
intersect
select customer_id, c_custkey from dbo.CUSTOMER_VIEW)
select * from a;

-- DB-404:<query expression body> UNION ALL <query term>
with a(a_custkey, a_id) as
(select c_custkey,customer_id from sa.CUSTOMER
union all
select c_custkey,customer_id from dbo.CUSTOMER_VIEW)
select * from a;

-- DB-405:<query expression body> EXCEPT <query term>
with a(a_id, a_custkey) as
(select c_custkey,customer_id from sa.CUSTOMER
except
select c_custkey,customer_id from dbo.CUSTOMER_VIEW)
select * from a;

-- DB-406:SELECT <select list> <joined table>
 with a(a_id, a_custkey) as
(select customer_id,c_custkey from sa.CUSTOMER inner join
sa.ORDERS on c_custkey=o_custkey)
select * from a;

-- DB-407:SELECT<select list> <from clause><where clause>
with a(a_id, a_mktsegment) as
(select customer_id,c_mktsegment from sa.CUSTOMER where customer_id<10)
select * from a;

-- DB-408:SELECT<select list> <from clause><group clause>
with a(a_custkey,total) as
(select o_custkey,count(o_custkey) from sa.ORDERS group by o_custkey)
select * from a;

-- DB-409:customized temporary table
with temptable as
(select order_id,o_custkey from sa.ORDERS)
select * from temptable;

-- DB-410:query name is a exist table
with Sales as
(select * from sa.ORDERS where order_id<10)
SELECT * FROM Sales;

-- DB-411:<row value ctor> <comp op> <row value ctor>
delete from sa.CUSTOMER where c_privilege_level = 1;

-- DB-412:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
delete from sa.CUSTOMER where customer_id between 2 and 3;

-- DB-413:<row value ctor> NOT BETWEEN <row value ctor> AND <row value ctor>
delete from sa.CUSTOMER where customer_id not between 2 and 10;

-- DB-414:<row value ctor> LIKE <row value ctor>
delete from sa.CUSTOMER where c_mktsegment like 'Ca%';

-- DB-415:<row value ctor> NOT LIKE <row value ctor>
delete from sa.CUSTOMER where c_mktsegment not like 'Ca%' and c_privilege_level = 1;

-- DB-416:<row value ctor> IN <subquery>
delete from sa.CUSTOMER where c_mktsegment in (select distinct c_mktsegment from sa.CUSTOMER_COPY) and c_privilege_level = 1;

-- DB-417:<row value ctor> NOT IN <subquery>
delete from sa.CUSTOMER where c_privilege_level not in (select distinct c_privilege_level from sa.CUSTOMER_COPY) and c_mktsegment = 'retail';

-- DB-418:<row value ctor> IS NULL
delete from sa.CUSTOMER where (select c_custkey from sa.CUSTOMER_COPY where c_custkey is null) is null and c_privilege_level = 1;

-- DB-419:<row value ctor> IS NOT NULL
delete from sa.CUSTOMER where (select c_custkey from sa.CUSTOMER_COPY where c_custkey is null) is not null and c_privilege_level = 0;

-- DB-420:EXISTS <subquery>
delete from sa.CUSTOMER where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail') and c_privilege_level = 2;

-- DB-421:<row value ctor> IN ( <row value ctor list> )
delete from sa.CUSTOMER where(select c_mktsegment from sa.CUSTOMER_COPY where customer_id = 1) in ('building','Catering');

-- DB-422:<row value ctor> NOT IN ( <row value ctor list> ）
delete from sa.CUSTOMER where c_mktsegment not in ('building','Catering');

-- DB-423:Not <boolean factor>
delete from sa.CUSTOMER where not exists(select * from sa.CUSTOMER where c_privilege_level = 2);

-- DB-424:<boolean term> AND <boolean factor>
delete from sa.CUSTOMER where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail') and c_privilege_level = 2;

-- DB-425:<search condition> OR <boolean term>
delete from sa.CUSTOMER where exists(select * from sa.CUSTOMER where c_mktsegment = 'retail') OR c_privilege_level = 2;

-- DB-426:The priority for NOT, AND, OR
delete from sa.CUSTOMER where NOT c_privilege_level < 0 OR c_privilege_level = -2 AND (c_mktsegment = 'building' OR (select c_mktsegment from sa.CUSTOMER_COPY where customer_id = 1005) = 'retail');

-- DB-427:<factor 4> ::= <column reference>
delete from test01.sa.CUSTOMER where exists(select * from test01.sa.CUSTOMER where test01.sa.CUSTOMER.c_mktsegment = 'retail') OR test01.sa.CUSTOMER.c_privilege_level = 2;

-- DB-428:<factor 4> ::= <expression const>
delete from sa.CUSTOMER where c_mktsegment = N'retail' OR c_privilege_level = -1 AND c_custkey is not null;

-- DB-429:<factor 4> ::= <scalar function expression>
delete from sa.CUSTOMER where dbo.return0() in (select c_privilege_level from sa.CUSTOMER) AND ABS(c_privilege_level) = 1;

-- DB-430:<factor 4> ::= CAST <left paren> <row value ctor> AS <data type> <right paren>
delete from sa.CUSTOMER_DEFAULT  where CAST(salary AS int) > 1000;

-- DB-431:<factor 4> ::= COALESCE <left paren> <row value ctor> <right paren>
delete from sa.CUSTOMER where customer_id = coalesce(null,null,1 ,2);

-- DB-432:<factor 4> ::= CURRENT_TIMESTAMP
delete from sa.CUSTOMER where CURRENT_TIMESTAMP = getdate() and c_privilege_level = 1;

-- DB-433:<factor 4> ::= NULLIF <left paren> <row value ctor> <comma> <row value ctor> <right paren>  <marked error>
delete from sa.CUSTOMER where NULLIF(c_privilege_level,1) is null;

-- DB-434:<factor 4> ::= <subquery>
delete from sa.CUSTOMER where (select sum(c_privilege_level) from sa.CUSTOMER where c_mktsegment = 'building') < 0 and customer_id = 3;

-- DB-435:<factor 4> ::= <left paren> <row value ctor list> <right paren>  <marked error>
delete from sa.CUSTOMER where c_privilege_level = ((select c_privilege_level from sa.CUSTOMER where customer_id = 4) + 1) * 2;

-- DB-436:<factor 3> ::= <plus or minus op> <factor 4>
delete from sa.CUSTOMER where c_privilege_level = +(select c_privilege_level from sa.CUSTOMER where customer_id = 1) OR c_privilege_level = -1;

-- DB-437:<factor 2> ::= <factor 2> <circumflex> <factor 3>
delete from sa.CUSTOMER where c_privilege_level > (select c_privilege_level from sa.CUSTOMER where customer_id = 1) ^ 1;

-- DB-438:<factor 1> ::= <factor 1> <mul op> <factor 2>
delete from sa.CUSTOMER where c_privilege_level = 1*-(select c_privilege_level from sa.CUSTOMER where customer_id = 2);

-- DB-439:<factor 1> ::= <factor 1> <div op> <factor 2>
delete from sa.CUSTOMER where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)/2;

-- DB-440:<factor 1> ::= <factor 1> <per op> <factor 2>
delete from sa.CUSTOMER where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)%3;

-- DB-441:<factor 0> ::= <factor 0> <plus op> <factor 1>
delete from sa.CUSTOMER where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 2)+1;

-- DB-442:<factor 0> ::= <factor 0> <minus op> <factor 1>
delete from sa.CUSTOMER where c_privilege_level = (select c_privilege_level from sa.CUSTOMER where customer_id = 4)-1;

-- DB-443:<query expression body> UNION ALL <query term> EXCEPT<query term>INTERSECT<query term>
INSERT INTO TEST01.SA.CUSTOMER VALUES ('breakingbad',((select c_mktsegment from sa.CUSTOMER union all select c_mktsegment from sa.CUSTOMER where c_privilege_level = 1 EXCEPT select c_mktsegment from sa.CUSTOMER_COPY) INTERSECT select c_mktsegment from sa.CUSTOMER2 where c_privilege_level = 1), 34);

-- DB-444:<row value ctor> <comp op> <any> <subquery>
delete from sa.CUSTOMER_COPY where customer_id = any (select customer_id from sa.CUSTOMER_COPY) and customer_id = 1;

-- DB-445:CASE WHEN <search condition> THEN <row value ctor> END
delete from sa.CUSTOMER where CASE when 'retail' in(select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level < 0) then c_privilege_level END < 0;

-- DB-446:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> END
delete from sa.CUSTOMER where CASE c_mktsegment when 'retail' then c_privilege_level end = -1;

-- DB-447:CASE WHEN <search condition> THEN <row value ctor> ELSE <row value ctor> END
delete from sa.CUSTOMER_DEFAULT where CASE when 'retail' not in (select c_mktsegment from sa.CUSTOMER_COPY where c_privilege_level >= 0) then c_privilege_level Else salary END > 1000;

-- DB-448:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
delete from sa.CUSTOMER_DEFAULT where CASE c_mktsegment when 'Catering' then c_privilege_level ELSE salary END = 1;

-- DB-449:<when clause list> ::= <when clause> <comma> <when clause>...
delete from sa.CUSTOMER_DEFAULT where CASE when exists(select * from sa.CUSTOMER where c_mktsegment is null) then c_privilege_level when exists(select * from sa.CUSTOMER where c_mktsegment is not null) then customer_id ELSE salary END = 1006;

-- DB-450:<set clause list> ::= <set clause> <comma> <set clause> ...
update sa.CUSTOMER set c_mktsegment = (select test01.sa.CUSTOMER.c_mktsegment from test01.sa.CUSTOMER_COPY  where test01.sa.CUSTOMER_COPY.customer_id=1), c_privilege_level = 1 where exists(select * from sa.CUSTOMER where c_mktsegment is null);

-- DB-451:<query name> AS (CTE_query_definition1) union all(CTE_query_definition2 )
with cte as(
       select * from sa.Sales where Qty=3
       union all
       select a.* from sa.Sales a,cte b
       where a.OrderID=b.Qty
   )
SELECT * FROM cte;

-- DB-452:<query name> AS (CTE_query_definition1) union all(CTE_query_definition2 ) inner join
with cte(Product,Qty,Tlevel) as(
       select Product,Qty,0 as Tlevel from sa.Sales where Qty=5
       union all
       select e.Product,e.Qty,cte.Tlevel+1 as Tlevel from cte
       inner join sa.Sales e on e.Qty=cte.Qty
where cte.Tlevel<10)
SELECT * FROM cte;

-- DB-453:plus/minus
select a.customer_id, a.c_privilege_level, a.c_custkey, b.customer_id, b.c_custkey, b.c_privilege_level, a.c_privilege_level+b.c_privilege_level from test01.sa.CUSTOMER a inner join test01.sa.CUSTOMER_COPY b on a.c_custkey=b.c_custkey;

-- DB-459:<object column> <equals operator>SELECT <select list> <table primary>
update test01.sa.CUSTOMER_DEFAULT
set test01.sa.CUSTOMER_DEFAULT.c_mktsegment=(select test01.sa.CUSTOMER.c_mktsegment from test01.sa.CUSTOMER  where test01.sa.CUSTOMER.customer_id=1)
where customer_id=0;

-- DB-460:<object column> <equals operator>SELECT <select list> <joined table>
update test01.sa.CUSTOMER_DEFAULT
set test01.sa.CUSTOMER_DEFAULT.c_mktsegment=(select c_mktsegment from (SELECT customer_id,c_mktsegment
FROM test01.sa.CUSTOMER as a cross join test01.sa.ORDERS as b
WHERE a.c_custkey=b.o_custkey)c where c.customer_id =5)
where customer_id=0;

-- DB-461:<row value ctor> <comp op> <all> <subquery>
INSERT INTO TEST01.SA.CUSTOMER select c_custkey, c_mktsegment, c_privilege_level from sa.CUSTOMER_COPY where customer_id > all (select customer_id from sa.CUSTOMER);

-- DB-462:<object column> <equals operator><query primary> INTERSECT <query primary>
update test01.sa.CUSTOMER_DEFAULT
set test01.sa.CUSTOMER_DEFAULT.c_mktsegment=(select c_mktsegment from (SELECT c_mktsegment,customer_id from test01.sa.CUSTOMER
INTERSECT
select c_mktsegment,customer_id from test01.sa.CUSTOMER_COPY)
as c where c.customer_id =1005)
where customer_id=0;

-- DB-463:<object column> <equals operator>plus/minus
update test01.sa.CUSTOMER_DEFAULT
set c_privilege_level=(select c_privilege_level from sa.CUSTOMER where customer_id = 1)-2
where customer_id=0;

-- DB-464:<object column> <equals operator> <contextually typed value specification>
update sa.CUSTOMER
set c_mktsegment=null;

-- DB-465:<set clause list> ::= <set clause> <comma> <set clause> ...
update sa.CUSTOMER set c_mktsegment = 'retail', c_privilege_level = 1 where exists(select * from sa.CUSTOMER where c_mktsegment is null);

-- DB-466:<object column> <equals operator><column reference>  <marked error>
/*update test01.sa.ORDERS
set o_custkey=SalesRep
from test01.sa.ORDERS,sales
where test01.sa.ORDERS.o_shippriority=Sales.Qty;*/

-- DB-467:<object column> <equals operator><expression const>
update sa.CUSTOMER
set c_mktsegment='Los Angeles';

-- DB-468:<object column> <equals operator><scalar function expression>
update test01.sa.CUSTOMER
set c_mktsegment =dbo.return0() where customer_id=9;

-- DB-469:<object column> <equals operator><cast as>
update test01.sa.CUSTOMER_DEFAULT
set c_privilege_level=cast((CAST(c_privilege_level as int)+20) as int);

-- DB-470:<object column> <equals operator><COALESCE>
update test01.sa.CUSTOMER_DEFAULT
set c_privilege_level=coalesce(null,5)
where customer_id=0;

-- DB-471:<object column> <equals operator><case when..then..else..end>
update test01.sa.CUSTOMER_DEFAULT
set c_privilege_level=case when c_privilege_level=1 then 1 else c_privilege_level+1 end
where customer_id=0;

-- DB-472:<object column> <equals operator>SELECT <select list> <table primary>
update test01.sa.CUSTOMER_DEFAULT
set test01.sa.CUSTOMER_DEFAULT.c_mktsegment=(select test01.sa.CUSTOMER.c_mktsegment from test01.sa.CUSTOMER  where test01.sa.CUSTOMER.customer_id=1)
where customer_id=0;

-- DB-473:<object column> <equals operator>SELECT <select list> <joined table>
update test01.sa.CUSTOMER_DEFAULT
set test01.sa.CUSTOMER_DEFAULT.c_mktsegment=(select c_mktsegment from (SELECT customer_id,c_mktsegment
FROM test01.sa.CUSTOMER as a cross join test01.sa.ORDERS as b
WHERE a.c_custkey=b.o_custkey)c where c.customer_id =5);

-- DB-474:<object column> <equals operator><query primary> INTERSECT <query primary>
update test01.sa.CUSTOMER_DEFAULT
set test01.sa.CUSTOMER_DEFAULT.c_mktsegment=(select c_mktsegment from (SELECT c_mktsegment,customer_id from test01.sa.CUSTOMER
INTERSECT
select c_mktsegment,customer_id from test01.sa.CUSTOMER_COPY)
as c where c.customer_id =1005)
where customer_id=0;

-- DB-475:<object column> <equals operator>plus/minus
update test01.sa.CUSTOMER_DEFAULT
set c_privilege_level=c_privilege_level-2
where customer_id=0;

-- DB-476:<object column> <equals operator><with clause>  <marked error>
/*with a(a_id, a_mktsegment) as
(select customer_id,c_mktsegment from test01.sa.CUSTOMER)
update test01.sa.CUSTOMER_DEFAULT
set test01.sa.CUSTOMER_DEFAULT.c_mktsegment=(select a_mktsegment from a where a_id=1)
where customer_id=0*/

-- DB-477:sum()
update test01.sa.CUSTOMER_DEFAULT
set c_privilege_level = (select sum(c_privilege_level) from sa.CUSTOMER)
where customer_id=0;

-- DB-478:<table primary><left join><table primary>ON <search condition>
INSERT INTO TEST01.SA.CUSTOMER select distinct a.c_custkey, a.c_mktsegment, a.c_privilege_level from sa.CUSTOMER_COPY a left join sa.CUSTOMER b on a.c_mktsegment is not null;

-- DB-479:<table primary><right join><table primary>ON <search condition>
INSERT INTO TEST01.SA.CUSTOMER select distinct a.c_custkey, a.c_mktsegment, a.c_privilege_level from sa.CUSTOMER a right join sa.CUSTOMER_COPY b on a.c_mktsegment is not null;

-- DB-480:<table primary><full join><table primary>ON <search condition>
INSERT INTO TEST01.SA.CUSTOMER select distinct a.c_custkey, a.c_mktsegment, a.c_privilege_level from sa.CUSTOMER a full join sa.CUSTOMER_COPY b on a.c_mktsegment is not null;

-- DB-481:GROUP BY
INSERT INTO TEST01.SA.CUSTOMER select c_mktsegment, c_privilege_level, c_privilege_level from sa.CUSTOMER group by c_custkey, c_mktsegment, c_privilege_level having c_privilege_level = 2/2;

-- DB-482:HAVING
INSERT INTO TEST01.SA.CUSTOMER VALUES ('pljgbjggbbgbb76yhh', 'retail', (select sum(c_privilege_level) from sa.CUSTOMER having sum(c_privilege_level)>1));

-- DB-483:<table expression> ::= <from clause> <having clause>
select sum(c_privilege_level) from sa.CUSTOMER having sum(c_privilege_level)>1;

-- DB-484:GROUP BY...HAVING
INSERT INTO TEST01.SA.CUSTOMER select c_mktsegment, c_privilege_level, c_privilege_level from sa.CUSTOMER_COPY group by c_mktsegment, c_privilege_level having (select c_privilege_level from sa.CUSTOMER_COPY where customer_id = 1006) < 1-2 and c_mktsegment is not null;

-- DB-485:<row value ctor> <comp op> <row value ctor>
insert into sa.CUSTOMER select * from sa.CUSTOMER_COPY where c_custkey = 'breakingbad'and c_privilege_level = 1;
--Test View, change one policy condition, resource.sql.table = "CUSTOMER_VIEW"
insert into sa.CUSTOMER_VIEW select * from sa.CUSTOMER_COPY where c_custkey = 'breakingbad'and c_privilege_level = 1;

-- DB-486:<left paren> <insert column list> <right paren> <query expression>
insert into sa.CUSTOMER (c_custkey, c_mktsegment, c_privilege_level) select c_custkey, c_mktsegment, c_privilege_level from sa.CUSTOMER_COPY where c_custkey = 'breakingbad'and c_privilege_level = 1;
insert into sa.CUSTOMER_VIEW (c_custkey, c_mktsegment, c_privilege_level) select c_custkey, c_mktsegment, c_privilege_level from sa.CUSTOMER_COPY where c_custkey = 'breakingbad'and c_privilege_level = 1;

-- DB-487:<query expression body> UNION ALL <query term> EXCEPT<query term>INTERSECT<query term>  <marked error>
INSERT INTO TEST01.SA.CUSTOMER VALUES ('breakingbad',((select c_mktsegment from sa.CUSTOMER union all select c_mktsegment from sa.CUSTOMER where c_privilege_level = 1 EXCEPT select c_mktsegment from sa.CUSTOMER_COPY) INTERSECT select c_mktsegment from sa.CUSTOMER2 where c_privilege_level = 1), 34);

-- DB-488:<row value ctor> BETWEEN <row value ctor> AND <row value ctor>
INSERT INTO TEST01.SA.CUSTOMER select * from sa.CUSTOMER_COPY where customer_id between 1005 and 1006;

-- DB-489:CASE WHEN <search condition> THEN <row value ctor> END
INSERT INTO TEST01.SA.CUSTOMER VALUES ('breakingbad', (select CASE when customer_id = 1 then c_mktsegment end from test01.sa.CUSTOMER_COPY where customer_id = 1005), 0);

-- DB-490:<subquery>
INSERT INTO TEST01.SA.CUSTOMER (c_custkey, c_mktsegment, c_privilege_level) select * from (select c_custkey, c_mktsegment, c_privilege_level from sa.CUSTOMER_COPY) as temptable;

-- DB-491:<row value ctor> <comp op> <all> <subquery>
INSERT INTO TEST01.SA.CUSTOMER select c_custkey, c_mktsegment, c_privilege_level from sa.CUSTOMER where customer_id > all (select customer_id from sa.CUSTOMER_COPY);

-- DB-492:CROSS JOIN
INSERT INTO TEST01.SA.CUSTOMER SELECT a.c_custkey, a.c_mktsegment, a.c_privilege_level FROM sa.CUSTOMER as a cross join sa.CUSTOMER_COPY as b WHERE a.c_privilege_level=b.c_privilege_level;

-- DB-493:<joined table><inner join><table primary>ON <search condition>
INSERT INTO TEST01.SA.CUSTOMER select a.c_custkey, a.c_mktsegment, a.c_privilege_level from (select * from sa.CUSTOMER) a inner join sa.CUSTOMER_COPY b on a.c_mktsegment = 'building' and a.customer_id = 4;

-- DB-494:<table primary><left join><table primary>ON <search condition>
INSERT INTO TEST01.SA.CUSTOMER select distinct a.c_custkey, a.c_mktsegment, a.c_privilege_level from sa.CUSTOMER_COPY a left join sa.CUSTOMER b on a.c_mktsegment is not null;

-- DB-495:<table primary><right join><table primary>ON <search condition>
INSERT INTO TEST01.SA.CUSTOMER select distinct a.c_custkey, a.c_mktsegment, a.c_privilege_level from sa.CUSTOMER a right join sa.CUSTOMER_COPY b on a.c_mktsegment is not null;

-- DB-496:<table primary><full join><table primary>ON <search condition>
INSERT INTO TEST01.SA.CUSTOMER select distinct a.c_custkey, a.c_mktsegment, a.c_privilege_level from sa.CUSTOMER a full join sa.CUSTOMER_COPY b on a.c_mktsegment is not null;

-- DB-497:GROUP BY
INSERT INTO TEST01.SA.CUSTOMER select c_mktsegment, c_privilege_level, c_privilege_level from sa.CUSTOMER_COPY group by c_custkey, c_mktsegment, c_privilege_level having c_privilege_level = 2/2;

-- DB-498:HAVING
INSERT INTO TEST01.SA.CUSTOMER VALUES ('pljgbjggbbgbb76yhh', 'retail', (select sum(c_privilege_level) from sa.CUSTOMER_COPY having sum(c_privilege_level)>1));

-- DB-499:GROUP BY...HAVING
INSERT INTO TEST01.SA.CUSTOMER select c_mktsegment, c_privilege_level, c_privilege_level from sa.CUSTOMER_COPY group by c_mktsegment, c_privilege_level having (select c_privilege_level from sa.CUSTOMER_COPY where customer_id = 1006) < 1-2 and c_mktsegment is not null;

-- DB-500:<object column> <equals operator>plus/minus<column reference>  <marked error>
/*update test01.sa.ORDERS
set o_shippriority=o_shippriority+c_privilege_level
from test01.sa.ORDERS as a join test01.sa.CUSTOMER_COPY as b
on a.o_custkey=b.c_custkey*/

-- DB-501:<subquery> ::= <left paren> <query expression> <right paren>
select * from
(select * from test01.sa.CUSTOMER where c_privilege_level=1) a
cross join
(select * from test01.sa.CUSTOMER_COPY where c_privilege_level<0) b
where a.c_mktsegment =b.c_mktsegment;

-- DB-502:<left paren> <joined table> <right paren>
select * from
(test01.sa.CUSTOMER a inner join test01.sa.ORDERS b on a.c_privilege_level=32)
cross join
(test01.sa.CUSTOMER_COPY c inner join test01.sa.ORDERS d on c.c_privilege_level=d.o_orderpriority);

-- DB-503:<left paren> <joined table> <right paren>
 select * from
(test01.sa.CUSTOMER a inner join test01.sa.ORDERS b on a.c_privilege_level=32)
cross join
(test01.sa.CUSTOMER_COPY c inner join test01.sa.ORDERS d on c.c_privilege_level=d.o_orderpriority);

-- DB-504:<subquery> ::= <left paren> <query expression> <right paren>
select * from
(test01.sa.CUSTOMER_COPY a inner join test01.sa.ORDERS b on a.c_privilege_level=b.o_orderpriority )
cross join
(select * from test01.sa.CUSTOMER_COPY where c_privilege_level<0) c
where a.c_mktsegment=c.c_mktsegment;

-- DB-505:<left paren> <joined table> <right paren>
SELECT a.customer_id, a.c_mktsegment FROM sa.CUSTOMER as a inner join (sa.CUSTOMER_DEFAULT as b inner join sa.CUSTOMER_COPY as c on b.customer_id = c.customer_id ) on a.customer_id = b.customer_id WHERE a.c_privilege_level = -2;

-- DB-506:<object column> <equals operator><having>
update test01.sa.CUSTOMER_DEFAULT
set test01.sa.CUSTOMER_DEFAULT.c_privilege_level=
(select sum(c_privilege_level) from test01.sa.CUSTOMER having sum(c_privilege_level)>1 )
where customer_id=0;

-- DB-507:RANK <left paren> <right paren><over clause>
select *, rank() over (order by c_mktsegment) rank1 from sa.CUSTOMER;

-- DB-508:DENSE_RANK <left paren> <right paren><over clause>
select *, DENSE_RANK() over (order by c_mktsegment) rank1 from sa.CUSTOMER;

-- DB-509:ROW_NUMBER <left paren> <right paren> <over clause>
select *, ROW_NUMBER() over (order by c_mktsegment) rank1 from sa.CUSTOMER;

-- DB-510:PERCENT_RANK <left paren> <right paren> <over clause>
select *, PERCENT_RANK() over (order by c_privilege_level) rank1 from sa.CUSTOMER;

-- DB-511:CUME_DIST <left paren> <right paren> <over clause>
select *, CUME_DIST() over (order by c_privilege_level) rank1 from sa.CUSTOMER;

-- DB-512:<object column> <equals operator><group by>
update test01.sa.ORDERS
set o_shippriority=(select o_shippriority
from test01.sa.ORDERS as a join test01.sa.CUSTOMER_COPY as b
on a.o_custkey=b.c_custkey
group by o_shippriority)
where order_id=13;

-- DB-513:OVER <left paren> <partition by clause> <order by clause><right paren>
select *, rank() over (partition by c_mktsegment order by c_privilege_level) rank1 from sa.CUSTOMER;

-- DB-514:AVG()
select avg(c_privilege_level) AVG from sa.CUSTOMER;

-- DB-515:MAX()
select MAX(c_privilege_level) MAX from sa.CUSTOMER;

-- DB-516:MIN()
select MIN(c_privilege_level) from sa.CUSTOMER;

-- DB-517:SUM()
select SUM(c_privilege_level) SUM from sa.CUSTOMER;

-- DB-518:COUNT()
select COUNT(c_privilege_level) STDDEV_POP from sa.CUSTOMER;

-- DB-519:<aggregate function name> <left paren> ALL <row value ctor> <right paren>
select SUM( ALL c_privilege_level) SUM from sa.CUSTOMER;

-- DB-520:<aggregate function name> <left paren> DISTINCT <row value ctor> <right paren>
select SUM(DISTINCT c_privilege_level) SUM from sa.CUSTOMER;

-- DB-521:COUNT <left paren> <asterisk> <right paren>
select COUNT(*) STDDEV_POP from sa.CUSTOMER;

-- DB-522:GROUPING <left paren> <row value ctor> <right paren>
select customer_id, c_mktsegment, GROUPING(c_mktsegment) from sa.CUSTOMER group by customer_id, c_mktsegment;

-- DB-523:AVG()
select avg(c_privilege_level) AVG from sa.CUSTOMER;

-- DB-524:MAX()
select MAX(c_privilege_level) MAX from sa.CUSTOMER;

-- DB-525:MIN()
select MIN(c_privilege_level) from sa.CUSTOMER;

-- DB-526:SUM()
select SUM(c_privilege_level) SUM from sa.CUSTOMER;

-- DB-527:COUNT()
select COUNT(c_privilege_level) STDDEV_POP from sa.CUSTOMER;

-- DB-528:<aggregate function name> <left paren> ALL <row value ctor> <right paren>
select SUM( ALL c_privilege_level) SUM from sa.CUSTOMER;

-- DB-529:<aggregate function name> <left paren> DISTINCT <row value ctor> <right paren>
select SUM(DISTINCT c_privilege_level) SUM from sa.CUSTOMER;

-- DB-530:COUNT <left paren> <asterisk> <right paren>
select COUNT(*) STDDEV_POP from sa.CUSTOMER;

-- DB-531:GROUPING <left paren> <row value ctor> <right paren>
/* EMPTY */

-- DB-547:CASE WHEN <search condition> THEN <row value ctor> END
Select * from test01.sa.Customer order by (case when c_privilege_level<0
then c_privilege_level
end);

-- DB-548:CASE WHEN <search condition> THEN <row value ctor> ELSE <row value ctor> END
Select * from test01.sa.Customer order by
(case when c_privilege_level<0
then c_privilege_level
else customer_id
end);

-- DB-549:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> END
Select * from test01.sa.Customer order by (case c_mktsegment when 'breakingbad'
then c_privilege_level
end);

-- DB-550:CASE <case arg> WHEN <row value ctor> THEN <row value ctor> ELSE <row value ctor> END
Select * from test01.sa.Customer order by
(case c_privilege_level when '0'
then c_privilege_level
else customer_id
end);

-- DB-551:<when clause list> ::= <when clause> <comma> <when clause>
Select * from test01.sa.Customer order by
(case c_privilege_level
when '0'
then c_privilege_level
when '1'
then customer_id
end);

-- DB-554:COUNT <left paren> <asterisk> <right paren>
select c_custkey,c_privilege_level, count(*) from
test01.sa.CUSTOMER
group by c_custkey,c_privilege_level order by count(*);

-- DB-556:VALUES <row value ctor list><row value ctor list>
insert into test01.sa.CUSTOMER_DEFAULT (c_custkey, c_mktsegment, c_privilege_level) values ('breakingbad', 'Cateing', 2), ('FAC_aac', 'fac', -1);

-- DB-557:VALUES <expression const>
insert into test01.sa.CUSTOMER_DEFAULT (c_custkey, c_mktsegment, c_privilege_level) values (DEFAULT, 'Cateing', 2);

-- DB-558:VALUES <plus or minus op>
insert into test01.sa.CUSTOMER_DEFAULT (c_custkey, c_mktsegment, c_privilege_level) values (default, 'Cateing', 5-4);

-- DB-559:<column reference>+<column reference>
Select * from test01.sa.CUSTOMER_DEFAULT order by c_custkey+N'#'+c_mktsegment;

-- DB-560:select-from one table-where-group by-order by
select c_custkey, c_mktsegment, sum(c_privilege_level) AS sum, avg((c_privilege_level-customer_id) * 2) avg, COUNT(*) from sa.CUSTOMER_DEFAULT where c_create_date > Dateadd(dd, -90, Cast('1998-12-01' AS datetime)) group by c_custkey, c_mktsegment order by c_custkey, c_mktsegment;

-- DB-561:<row value ctor> ::= <row value ctor> <cnn op> <factor 0>
/* EMPTY */

-- DB-562:<row value ctor> ::= <row value ctor> <cnn op> <factor 0>
/* EMPTY */

-- DB-564:<row value ctor> ::= <row value ctor> <cnn op> <factor 0>
/* EMPTY */

-- DB-566:<row value ctor> ::= <row value ctor> <cnn op> <factor 0>
/* EMPTY */

-- DB-567:<row value ctor> ::= <row value ctor> <cnn op> <factor 0>
/* EMPTY */

-- DB-568:select-from multi tables-where-group by-order by
select a.customer_id A_cus_id, a.c_mktsegment A_c_mkts, b.c_privilege_level B_c_pri, c.salary C_salary from sa.CUSTOMER a, sa.CUSTOMER_COPY b, sa.CUSTOMER_DEFAULT c where a.c_mktsegment = 'building' and b.c_privilege_level < 2 and c.salary < 1300 group by a.customer_id, a.c_mktsegment, b.c_privilege_level, c.salary order by  a.customer_id, b.c_privilege_level;

-- DB-569:select-from(select-from multi tables-where)-group by-order by
Select A_cus_id, A_c_mkts, B_c_pri, C_salary from (select a.customer_id A_cus_id, a.c_mktsegment A_c_mkts, b.c_privilege_level B_c_pri, c.salary C_salary from sa.CUSTOMER a, sa.CUSTOMER_COPY b, sa.CUSTOMER_DEFAULT c where a.c_mktsegment = 'building' and (b.c_privilege_level < 2 OR c.salary < 1300) and a.customer_id = b.customer_id and b.customer_id = c.customer_id) AS ABC group by A_cus_id, A_c_mkts, B_c_pri, C_salary order by A_cus_id DESC, A_c_mkts, B_c_pri, C_salary;

-- DB-570:sum(CASE-when-then-else-end )
select c_mktsegment, sum(case when c_mktsegment = 'building' then c_privilege_level Else 0 end)/sum(c_privilege_level) from sa.CUSTOMER_COPY GROUP BY c_mktsegment;

-- DB-571:NULLIF <left paren> <row value ctor> <comma> <row value ctor> <right paren>
Select nullif(customer_id,c_privilege_level) from test01.sa.CUSTOMER_DEFAULT;

-- DB-572:SUM()
update test01.sa.CUSTOMER_DEFAULT
set c_privilege_level = (select sum(c_privilege_level) from sa.CUSTOMER)
where customer_id=0;

-- DB-573:OVER <left paren> <partition by clause><right paren>
select count(*) over (partition by product),* from Sales;

-- DB-574:OVER <left paren> <order by clause><right paren>
select count(*) over (order by orderID),* from Sales;

-- DB-575:UNBOUNDED PRECEDING
select count(*) over (partition by product order by orderID rows UNBOUNDED PRECEDING ),* from Sales;

-- DB-576:CURRENT ROW
select count(*) over (partition by product order by orderID rows CURRENT ROW ),* from Sales;

-- DB-577:<unsigned value specification> PRECEDING
select count(*) over (partition by product order by orderID rows 2 PRECEDING ),* from Sales;

-- DB-578:BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING
select count(*) over (partition by product order by orderID rows between UNBOUNDED PRECEDING and UNBOUNDED following ),* from Sales;

-- DB-579:BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
select count(*) over (partition by product order by orderID rows between UNBOUNDED PRECEDING and CURRENT ROW ),* from Sales;

-- DB-580:TOP-select  <marked error-not support>
/*select top 10 a.customer_id A_cus_id, a.c_mktsegment A_c_mkts, b.c_privilege_level B_c_pri, c.salary C_salary
from sa.CUSTOMER a, sa.CUSTOMER_COPY b, sa.CUSTOMER_DEFAULT c
where a.c_mktsegment = 'building'
and b.c_privilege_level < 2
and c.salary < 1300
group by a.customer_id, a.c_mktsegment, b.c_privilege_level, c.salary
order by  a.customer_id, b.c_privilege_level;*/

-- DB-581:BETWEEN UNBOUNDED PRECEDING AND <unsigned value specification> PRECEDING
select count(*) over (partition by product order by orderID rows between UNBOUNDED PRECEDING and 1 PRECEDING ),* from Sales;

-- DB-582:/* comment */
/** testig comments **/
select c_custkey, c_mktsegment, sum(c_privilege_level) AS sum, avg((c_privilege_level-customer_id) * 2) avg, COUNT(*)
from sa.CUSTOMER_DEFAULT
where c_create_date > Dateadd(dd, -90, Cast('1998-12-01' AS datetime))
group by c_custkey, c_mktsegment
order by c_custkey, c_mktsegment;

-- DB-583:BETWEEN UNBOUNDED PRECEDING AND<int number> FOLLOWING
select count(*) over (partition by product order by orderID rows between UNBOUNDED PRECEDING and 1 following ),* from Sales;

-- DB-584:-- comments
-- testing comments
select c_custkey, c_mktsegment, sum(c_privilege_level) AS sum, avg((c_privilege_level-customer_id) * 2) avg, COUNT(*)
from sa.CUSTOMER_DEFAULT
where c_create_date > Dateadd(dd, -90, Cast('1998-12-01' AS datetime))
group by c_custkey, c_mktsegment
order by c_custkey, c_mktsegment;

-- DB-585:use  <marked error-not support>
/*  use test01
Select A_cus_id, A_c_mkts, B_c_pri, C_salary
from (
select a.customer_id A_cus_id, a.c_mktsegment A_c_mkts, b.c_privilege_level B_c_pri, c.salary C_salary
from sa.CUSTOMER a, sa.CUSTOMER_COPY b, sa.CUSTOMER_DEFAULT c
where a.c_mktsegment = 'building'
and (b.c_privilege_level < 2
OR c.salary < 1300)
and a.customer_id = b.customer_id
and b.customer_id = c.customer_id) AS ABC
group by A_cus_id, A_c_mkts, B_c_pri, C_salary
order by A_cus_id DESC, A_c_mkts, B_c_pri, C_salary */

-- DB-586:BETWEEN CURRENT ROW AND UNBOUNDED FOLLOWING????
select count(*) over (partition by product order by orderID rows between CURRENT ROW and UNBOUNDED following),* from Sales;

-- DB-587:BETWEEN CURRENT ROW AND <int number> FOLLOWING
select count(*) over (partition by product order by orderID rows between CURRENT ROW and 1 following ),* from Sales;

-- DB-588:BETWEEN CURRENT ROW AND CURRENT ROW
select count(*) over (partition by product order by orderID rows between CURRENT ROW and CURRENT ROW),* from Sales;

-- DB-589:BETWEEN <unsigned value specification> PRECEDING AND CURRENT ROW
select count(*) over (partition by product order by orderID rows between 2 PRECEDING and CURRENT ROW),* from Sales;

-- DB-590:select-from multi tables-where-group by-having-order by
select a.c_mktsegment, sum(a.c_privilege_level * a.customer_id) AS sum
from sa.CUSTOMER a, sa.CUSTOMER_COPY b,sa.CUSTOMER_DEFAULT c
where a.customer_id = b.customer_id
and b.customer_id = c.customer_id
and a.c_mktsegment = 'Catering'
group by a.c_mktsegment
having  sum(a.c_privilege_level * a.customer_id) > (select sum(a.c_privilege_level * a.customer_id) * 0.001000
from sa.CUSTOMER a, sa.CUSTOMER_COPY b,sa.CUSTOMER_DEFAULT c
where a.customer_id = b.customer_id
  and b.customer_id = c.customer_id
  and a.c_mktsegment = 'Catering')
order by sum desc;

-- DB-591:BETWEEN <unsigned value specification> PRECEDING AND UNBOUNDED FOLLOWING
select count(*) over (partition by product order by orderID rows between 2 PRECEDING and CURRENT ROW),* from Sales;

-- DB-592:BETWEEN <unsigned value specification> PRECEDING AND <unsigned value specification> PRECEDING
select count(*) over (partition by product order by orderID rows between 2 PRECEDING and 1 PRECEDING),* from Sales;

-- DB-593:BETWEEN <unsigned value specification> PRECEDING AND <int number> FOLLOWING
select count(*) over (partition by product order by orderID rows between 2 PRECEDING and 1 following),* from Sales;

-- DB-594:BETWEEN <int number> FOLLOWING AND <int number> FOLLOWING
select count(*) over (partition by product order by orderID rows between 1 following and 2 following),* from Sales;

-- DB-595:BETWEEN <int number> FOLLOWING AND UNBOUNDED FOLLOWING
select count(*) over (partition by product order by orderID rows between 1 following and UNBOUNDED following),* from Sales;

-- DB-596:select-from(select-from-join on-group by)-group by-order by
SELECT c_count,
   Count(*) AS CUSTDIST
FROM   (SELECT c_custkey,
   Count(o_orderkey)
FROM   sa.customer
   LEFT OUTER JOIN sa.orders
ON c_custkey = o_custkey
GROUP  BY c_custkey) AS C_ORDERS (c_custkey, c_count)
GROUP  BY c_count
ORDER  BY custdist DESC,
  c_count DESC;

-- DB-597:GROUP BY <grouping element list><grouping element list>
select OrderID,SalesRep,Qty from Sales where OrderID<4 group by OrderID,SalesRep,Qty;

-- DB-598:<subquery>
select b.*
from sa.ORDERS a, sa.CUSTOMER b
where b.customer_id in (select customer_id
from sa.CUSTOMER_COPY c
where customer_id in(select customer_id
from sa.CUSTOMER_DEFAULT d
where c_privilege_level = 1)
and c.c_privilege_level > (select 0.5 * sum(c_privilege_level)
   from sa.CUSTOMER2 e
   where e.customer_id = c.customer_id
and e.c_mktsegment = 'building')
)
and a.o_custkey = b.c_custkey
and b.c_mktsegment = 'building'
order by b.c_privilege_level;

-- DB-599:with(tablock)-update  <marked error-not support>
/* EMPTY */

-- DB-600:OUTPUT-update  <marked error-not support>
/* EMPTY */

-- DB-601:UNBOUNDED PRECEDING
select count(*) over (partition by product order by orderID range UNBOUNDED PRECEDING),* from Sales;
select count(*) over (partition by c_mktsegment order by customer_id range UNBOUNDED PRECEDING),* from test01.sa.CUSTOMER;

-- DB-602:CURRENT ROW
select count(*) over (partition by c_mktsegment order by customer_id range current row),* from test01.sa.CUSTOMER;

-- DB-603:statement<semicolon>statement
select * from sa.CUSTOMER where c_privilege_level = 1;
select * from sa.CUSTOMER where customer_id < all (select customer_id from sa.CUSTOMER_COPY);

-- DB-604:multi statements without <semicolon>  <marked error-not support>
/* EMPTY */

-- DB-605:select-into-from  <marked error-not support>
--Select * into sa.CUSTOMER_COPY from sa.CUSTOMER;

-- DB-606:Select "  <marked error-not support>
--Select " from sa.customer

-- DB-607:BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING
select count(*) over (partition by c_mktsegment order by customer_id range between UNBOUNDED PRECEDING and UNBOUNDED following),* from test01.sa.CUSTOMER;

-- DB-608:BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
select count(*) over (partition by c_mktsegment order by customer_id range between UNBOUNDED PRECEDING and CURRENT ROW),* from test01.sa.CUSTOMER;

-- DB-616:BETWEEN CURRENT ROW AND UNBOUNDED FOLLOWING????
select count(*) over (partition by c_mktsegment order by customer_id range between CURRENT ROW and UNBOUNDED following),* from test01.sa.CUSTOMER;

-- DB-618:BETWEEN CURRENT ROW AND CURRENT ROW
select count(*) over (partition by c_mktsegment order by customer_id range BETWEEN CURRENT ROW AND CURRENT ROW),* from test01.sa.CUSTOMER;

-- DB-631:OVER <left paren><partition by clause><order by clause><right paren>
select count(*) over (partition by c_mktsegment order by customer_id),* from test01.sa.CUSTOMER;

-- DB-638:sum() OVER <left paren><partition by clause><order by clause><right paren>
select sum(o_orderpriority) over (partition by o_custkey order by order_id),* from test01.sa.ORDERS;

-- DB-639:sum() OVER<partition by clause><order by clause>ROWS <window frame extent>
select sum(o_orderpriority) over (partition by o_custkey order by order_id rows between current row and 2 following),* from test01.sa.ORDERS;

-- DB-640:sum() OVER<partition by clause><order by clause>range <window frame extent>
select sum(o_orderpriority) over (partition by o_custkey order by order_id range between UNBOUNDED preceding and current row),* from test01.sa.ORDERS;

SELECT * FROM A UNION SELECT * FROM B ORDER BY mmm;