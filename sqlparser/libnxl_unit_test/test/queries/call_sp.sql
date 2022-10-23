-- sql2003
CALL sp();
CALL sp(1,2);
CALL sp('1' AS BIGINT);
CALL sp(12 + 3);
CALL sp(1>0);
CALL sp((SELECT max(y) FROM p), 'qwerty');

-- sqlserver
{CALL sp()};
{CALL sp(1,2)};
{CALL sp('asd')};
-- not support list in sqlserver
{CALL sp('1' AS BIGINT)};
{CALL sp(12 + 3)};
{CALL sp(1>0)};
{CALL sp((SELECT max(y) FROM p), 'qwerty')};