
create schema new_schema;

create table jeff.TEST_C
(
    C_CHAR char(255),
    C_VARC   varchar(255),
    C_TEXT  text,

    C_NCHAR  nchar(255),
    C_NVARC nvarchar(255),
    C_NTEXT ntext,

    C_BIN binary(255),
    C_VARBIN varbinary(255),
    C_IMAGE image
)
go;

create table jeff.TEST_DT
(
    C_DATE        date,
    C_DATETIMEOFF datetimeoffset,
    C_DATETIME2   datetime2,
    C_SMDATETIME  smalldatetime,
    C_DATETIME    datetime,
    C_TIME        time,
    C_TIMESTAMP   timestamp null
)
go;

alter table jeff.TEST_DT
	add C_TIMESTAMP timestamp null
go;

SELECT
    CAST('2007-05-08 12:35:29. 1234567 +12:15' AS time(7)) AS 'time'
    ,CAST('2007-05-08 12:35:29. 1234567 +12:15' AS date) AS 'date'
    ,CAST('2007-05-08 12:35:29.123' AS smalldatetime) AS 'smalldatetime'
    ,CAST('2007-05-08 12:35:29.123' AS datetime) AS 'datetime'
    ,CAST('2007-05-08 12:35:29. 1234567 +12:15' AS datetime2(7)) AS  'datetime2'
    ,CAST('2007-05-08 12:35:29.1234567 +12:15' AS datetimeoffset(7)) AS    'datetimeoffset';

