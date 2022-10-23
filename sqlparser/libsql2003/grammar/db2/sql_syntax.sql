for_update:
	FOR UPDATE  opt_of_clos
opt_of_clos:
	OF column_list
column_list:
    column_name [,...]

skip_locked:
	SKIP LOCKED DATA

with_isolation:
	WITH  { CS | UR | RS | RR }

queryno_clause:
	QUERYNO integer
fetch_first:
	FETCH FIRST   integer   { ROWS | ROW } [ONLY]
optimize_clause:
	OPTIMIZE FOR  integer   { ROWS | ROW } [ONLY]

read_only_clause:
	FOR READ ONLY