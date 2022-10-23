package com.nextlabs.jdbc.mssqlproxy;

public class nxlEnforcedSqlResult {
    public String enforcedSql;
    public boolean isBlocked;
    nxlEnforcedSqlResult()
    {
        this.enforcedSql = "";
        this.isBlocked = false;
    }
    nxlEnforcedSqlResult(String enforcedSql, boolean isBlocked) {
        this.enforcedSql = enforcedSql;
        this.isBlocked = isBlocked;
    }
}
