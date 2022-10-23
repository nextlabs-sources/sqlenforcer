-- DB-77:<select sublist> ==> <row value ctor> <as clause>
select customer_id, CASE when c_privilege_level=-2
then customer_id else c_privilege_level end as `case`
from test01.sa.CUSTOMER;

-- DB-78:<select sublist> ==> <regular identifier> <period> <asterisk>
select sa.CUSTOMER.* from sa.CUSTOMER;

-- DB-79:<select sublist> ==> " <delimited identifier body> " <period> <asterisk>
select  `select sa customer`.* from sa.CUSTOMER `select sa customer`;

-- DB-80:<select sublist> ==> <regular identifier>."<delimited identifier body>".<asterisk>
select  test01.sa.`select sa customer`.* from sa.`select sa customer`;


-- DB-234:<row value ctor> IN <subquery>
select customer_id, c_mktsegment AS `Select c_mktsegment` from sa.CUSTOMER where c_mktsegment in (select distinct c_mktsegment from sa.CUSTOMER_COPY);

-- DB-235:<row value ctor> NOT IN <subquery>
select customer_id, c_mktsegment `(Select c_mktsegment)`,c_privilege_level from sa.CUSTOMER where c_privilege_level not in (select distinct c_privilege_level from sa.CUSTOMER_COPY);

--
SELECT * FROM `tes``t`."hello""".`qwe"65`;