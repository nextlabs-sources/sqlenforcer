--prepareStatement
INSERT INTO jeffc VALUES (?,?,?,?,?);

SELECT*FROM jeffc WHERE id > ? AND age = ? AND address IN('zhejiang',?) ORDER BY id;
SELECT name FROM jeffc where id > ? UNION SELECT name FROM jeffd where id > ? ORDER BY id;
SELECT * FROM jeffc WHERE ? > id  AND 100 > ?;
SELECT jeffc.name AS cname, jeffd.name AS dname FROM jeffc JOIN jeffd ON jeffc.age = ?;
SELECT * FROM jeffc WHERE name LIKE ? ;
SELECT * FROM jeffc WHERE id BETWEEN ? AND ?;
SELECT * FROM jeffc WHERE ? <> ? 

DELETE FROM jeffc WHERE id = ?;
UPDATE jeffc SET id = 1,name = ? WHERE id = ?;
UPDATE jeffc SET age = ? WHERE id > ? AND id < ?;

--param must be number 
SELECT id, age FROM jeffc WHERE age > (SELECT AVG(?) FROM jeffd);
SELECT SUM(?) AS sumage FROM jeffc  

--didn't support
SELECT TOP ? * FROM jeffc 