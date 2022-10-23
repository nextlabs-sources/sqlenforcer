SELECT * FROM
sa.CUSTOMER
inner join sa.ORDERS
cross join sa.Sales
on order_id=OrderID and c_custkey=o_custkey;

SELECT * FROM A INNER JOIN B INNER JOIN C ON 1=0 ON 1=0;

SELECT * FROM A INNER JOIN B ON 1=0 INNER JOIN C ON 1=0;


SELECT NAME, LABEL, MAPPING from dict_type_fields where  PARENT_TYPE_ID = (SELECT ID FROM DICT_ELEMENT_TYPES WHERE NAME = ? ) AND DELETED = 'N';

SELECT e FROM PolicyDeploymentEntity e WHERE e.developmentId = ? AND e.overrideCount = ? ORDER BY e.activeTo DESC;

SELECT r FROM PolicyDeploymentRecord r WHERE r.id = ?;

SELECT e.ID FROM DEPLOYMENT_ENTITIES e INNER JOIN DEPLOYMENT_RECORDS r ON (e.DEP_RECORD_ID = r.ID) WHERE e.DEVELOPMENT_ID = ? AND e.OVERRIDE_CNT = ? AND e.ACTIVE_TO > ? AND r.ACTION_TYPE = ?;

SELECT e FROM PolicyDeploymentEntity e WHERE e.developmentId = ? AND e.overrideCount = ? AND e.activeTo > ?;

SELECT l.DEPLOYEMENT_ID, l.DEVELOPMENT_ID, l.ACTIVE_FROM, l.ACTIVE_TO, l.ACTION_TYPE, l.DEPLOY_ENT_COUNT FROM ( SELECT j.DEVELOPMENT_ID DEVELOPMENT_ID, ab.ID DEPLOYEMENT_ID, ab.ACTIVE_FROM ACTIVE_FROM , ab.ACTIVE_TO ACTIVE_TO, cd.ACTION_TYPE ACTION_TYPE, j.DEPLOY_ENT_COUNT DEPLOY_ENT_COUNT FROM DEPLOYMENT_ENTITIES ab INNER JOIN DEPLOYMENT_RECORDS cd ON (cd.ID = ab.DEP_RECORD_ID) INNER JOIN (SELECT k.DEVELOPMENT_ID, COUNT(k.DEVELOPMENT_ID) DEPLOY_ENT_COUNT FROM (SELECT de.DEVELOPMENT_ID, dr.ACTION_TYPE ACTION_TYPE, dr.DEPLOYMENT_TYPE DEPLOYMENT_TYPE FROM DEPLOYMENT_ENTITIES de INNER JOIN DEPLOYMENT_RECORDS dr ON(dr.ID = de.DEP_RECORD_ID) WHERE de.OVERRIDE_CNT = ? ) k GROUP BY k.DEVELOPMENT_ID ) j ON (j.DEVELOPMENT_ID = ab.DEVELOPMENT_ID AND ab.OVERRIDE_CNT = ?) ) l WHERE l.ACTIVE_TO > ? AND l.DEVELOPMENT_ID = ?;

SELECT NAME, SHORT_CODE, SHORT_NAME FROM PM_ACTION_CONFIG WHERE LOWER(SHORT_CODE) = ?;

SELECT short_code FROM PM_ACTION_CONFIG act LEFT JOIN POLICY_MODEL p on (act.plcy_model_id = p.id) WHERE p.discriminator != ? AND p.short_name = ? AND act.short_name = ? AND p.id = ?;

SELECT ID, NAME FROM APPLICATION_USER_DOMAIN d WHERE LOWER(d.NAME) = ?;

SELECT USERNAME FROM APPLICATION_USER a WHERE a.USER_TYPE = ? AND a.AUTH_HANDLER_ID = ?;

SELECT a.USERNAME, a.EMAIL FROM APPLICATION_USER a WHERE LOWER(a.email) = ? UNION SELECT s.USERNAME, s.EMAIL FROM SUPER_APPLICATION_USER s WHERE LOWER(s.email) = ?;

SELECT ID, USERNAME, FIRST_NAME, LAST_NAME, DOMAIN_ID, PRIMARY_GROUP_ID, LAST_LOGGED_TIME, HIDE_SPLASH, LAST_UPDATED, USER_TYPE, AUTH_HANDLER_ID    FROM APPLICATION_USER a WHERE a.status = ? OR a.AUTH_HANDLER_ID != ? UNION ALL SELECT ID, USERNAME, FIRST_NAME, LAST_NAME, DOMAIN_ID, PRIMARY_GROUP_ID, LAST_LOGGED_TIME, HIDE_SPLASH, LAST_UPDATED, 'internal', -1 from SUPER_APPLICATION_USER;

SELECT COUNT(ID) FROM APPLICATION_USER WHERE STATUS = ? AND AUTH_HANDLER_ID = ?;

SELECT o FROM OperatorConfig o WHERE o.dataType = ? ORDER BY o.label;

SELECT c FROM SavedSearch c WHERE lower(c.name) like ? AND c.status != 'DELETED' AND c.type = ? ORDER BY c.name;

SELECT p FROM AppUserProperties p WHERE p.userId = ? ORDER BY p.key;

SELECT p FROM AppUserProperties p WHERE p.superUserId = ? ORDER BY p.key;

SELECT a FROM AuditLog a WHERE a.ownerId = ? ORDER BY a.createdDate DESC;

SELECT a FROM AuditLog a ORDER BY a.createdDate DESC;

SELECT a FROM AuditLog a WHERE a.component = ? ORDER BY a.createdDate DESC;

SELECT a1.from_resource_name, a1.allow_count, d1.deny_count, (a1.allow_count + d1.deny_count) total_count
FROM ((SELECT rp1.from_resource_name from_resource_name, ra1.allow_decision decision, ISNULL(ra1.allow_count, 0) allow_count
       FROM ((SELECT ra.from_resource_name from_resource_name, ra.policy_decision allow_decision, count(ra.from_resource_name) allow_count
              from RPA_LOG ra
              WHERE policy_decision = 'A' AND day_nb >= ? AND day_nb <= ? GROUP BY ra.from_resource_name, ra.policy_decision) ra1

              RIGHT JOIN (SELECT rp.from_resource_name from_resource_name, 'A' deny_decision
                          from RPA_LOG rp
                          WHERE day_nb >= ? AND day_nb <= ?
                          GROUP BY rp.from_resource_name) rp1
                  ON (rp1.from_resource_name = ra1.from_resource_name))) a1
              INNER JOIN   (SELECT rp1.from_resource_name from_resource_name, rp1.deny_decision decision, ISNULL(rd1.deny_count, 0) deny_count
                            FROM ((SELECT rd.from_resource_name from_resource_name, rd.policy_decision deny_decision, count(rd.from_resource_name) deny_count
                                   from RPA_LOG rd
                                   WHERE policy_decision = 'D' AND day_nb >= ? AND day_nb <= ?
                                   GROUP BY rd.from_resource_name, rd.policy_decision) rd1

                                   RIGHT JOIN (SELECT rp.from_resource_name from_resource_name, 'D' deny_decision
                                               from RPA_LOG rp
                                               WHERE day_nb >= ? AND day_nb <= ?
                                               GROUP BY rp.from_resource_name) rp1
                                        ON (rp1.from_resource_name = rd1.from_resource_name))) d1
                  ON  (a1.from_resource_name = d1.from_resource_name)) ORDER BY total_count DESC;

SELECT a1.from_resource_name, a1.allow_count, d1.deny_count, (a1.allow_count + d1.deny_count) total_count FROM (   (SELECT rp1.from_resource_name from_resource_name, ra1.allow_decision decision, NVL(ra1.allow_count, 0) allow_count FROM (       (SELECT ra.from_resource_name from_resource_name, ra.policy_decision allow_decision, count(ra.from_resource_name) allow_count from RPA_LOG ra               WHERE policy_decision = 'A' AND day_nb >= ? AND day_nb <= ? GROUP BY ra.from_resource_name, ra.policy_decision) ra1 RIGHT JOIN       (SELECT rp.from_resource_name from_resource_name, 'A' deny_decision from RPA_LOG rp               WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1       ON (rp1.from_resource_name = ra1.from_resource_name))) a1    INNER JOIN   (SELECT rp1.from_resource_name from_resource_name, rp1.deny_decision decision, NVL(rd1.deny_count, 0) deny_count FROM (      (SELECT rd.from_resource_name from_resource_name, rd.policy_decision deny_decision, count(rd.from_resource_name) deny_count from RPA_LOG rd              WHERE policy_decision = 'D' AND day_nb >= ? AND day_nb <= ? GROUP BY rd.from_resource_name, rd.policy_decision) rd1 RIGHT JOIN      (SELECT rp.from_resource_name from_resource_name, 'D' deny_decision from RPA_LOG rp              WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1      ON (rp1.from_resource_name = rd1.from_resource_name))) d1  ON (a1.from_resource_name = d1.from_resource_name)) ORDER BY total_count DESC;

SELECT a1.from_resource_name, a1.allow_count, d1.deny_count, (a1.allow_count + d1.deny_count) total_count FROM (   (SELECT rp1.from_resource_name from_resource_name, ra1.allow_decision decision, COALESCE(ra1.allow_count, 0) allow_count FROM (       (SELECT ra.from_resource_name from_resource_name, ra.policy_decision allow_decision, count(ra.from_resource_name) allow_count from RPA_LOG ra               WHERE policy_decision = 'A' AND day_nb >= ? AND day_nb <= ? GROUP BY ra.from_resource_name, ra.policy_decision) ra1 RIGHT JOIN       (SELECT rp.from_resource_name from_resource_name, 'A' deny_decision from RPA_LOG rp               WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1       ON (rp1.from_resource_name = ra1.from_resource_name))) a1    INNER JOIN   (SELECT rp1.from_resource_name from_resource_name, rp1.deny_decision decision, COALESCE(rd1.deny_count, 0) deny_count FROM (      (SELECT rd.from_resource_name from_resource_name, rd.policy_decision deny_decision, count(rd.from_resource_name) deny_count from RPA_LOG rd              WHERE policy_decision = 'D' AND day_nb >= ? AND day_nb <= ? GROUP BY rd.from_resource_name, rd.policy_decision) rd1 RIGHT JOIN      (SELECT rp.from_resource_name from_resource_name, 'D' deny_decision from RPA_LOG rp              WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1      ON (rp1.from_resource_name = rd1.from_resource_name))) d1  ON (a1.from_resource_name = d1.from_resource_name)) ORDER BY total_count DESC;

SELECT k.name, COUNT(k.name) FROM  (SELECT t.name, e.element_id  from DICT_LEAF_ELEMENTS e LEFT JOIN  DICT_ELEMENT_TYPES t ON (t.id = e.type_id)) k GROUP BY k.name;

SELECT e.id, e.domain_name, e.enrollment_type, e.isActive, u.start_time, u.end_time, u.is_successful, u.err_msg FROM DICT_ENROLLMENTS e  LEFT JOIN DICT_UPDATES u  ON (e.id = u.enrollment_id AND u.active_to > ?) ORDER BY u.end_time desc;

SELECT e.id, e.domain_name, e.enrollment_type, e.isActive, u.start_time, u.end_time, u.is_successful, u.err_msg FROM DICT_ENROLLMENTS e  LEFT JOIN DICT_UPDATES u  ON (e.id = u.enrollment_id AND u.active_to > ?) ORDER BY u.end_time desc;

SELECT id, name, type, typeDisplayName, lastHeartbeat, heartbeatRate FROM COMPONENT where type = ?;

SELECT id, name, type, typeDisplayName, lastHeartbeat, heartbeatRate FROM COMPONENT where type = ?;

SELECT a.id, a.host, a.type, a.registered, a.version, a.lastHeartbeat,  a.deployment_bundle_ts, c.heart_beat_freq_time, c.heart_beat_freq_time_unit, c.dabs_location  FROM AGENT a INNER JOIN COMM_PROFILE c ON (a.comm_profile_id = c.id) where a.registered = ?;

SELECT a.id, a.host, a.type, a.registered, a.version, a.lastHeartbeat,  a.deployment_bundle_ts, c.heart_beat_freq_time, c.heart_beat_freq_time_unit, c.dabs_location  FROM AGENT a INNER JOIN COMM_PROFILE c ON (a.comm_profile_id = c.id) where a.registered = ?;

SELECT MAX(as_of) last_deployment_record FROM DEPLOYMENT_RECORDS;

SELECT r.test time_unit, count(r.test) total_request FROM RPA_LOG r INNER JOIN (SELECT l.decision_request_id decision_request_id FROM RPA_LOG l WHERE l.request_date_time >= ? AND l.request_date_time <= ? GROUP BY l.decision_request_id) g ON ( g.decision_request_id = r.decision_request_id) GROUP BY r.test ORDER BY r.test;

SELECT DAY_NB, MONITOR_ID, MONITOR_NAME, count(MONITOR_NAME)  FROM ALERT WHERE DAY_NB >= ? AND DAY_NB <= ? GROUP BY DAY_NB, MONITOR_ID, MONITOR_NAME ORDER BY DAY_NB;

SELECT r.user_id user_id, r.user_name, count(r.user_id) total_count from RPA_LOG r      WHERE r.policy_decision = ? AND r.day_nb >= ? AND r.day_nb <= ?       GROUP BY r.user_id, r.user_name ORDER BY total_count desc;

SELECT r.user_id user_id, r.user_name, count(r.user_id) total_count from RPA_LOG r      WHERE r.policy_decision = ? AND r.day_nb >= ? AND r.day_nb <= ?       GROUP BY r.user_id, r.user_name ORDER BY total_count desc;

SELECT a1.from_resource_name, a1.allow_count, d1.deny_count, (a1.allow_count + d1.deny_count) total_count FROM (   (SELECT rp1.from_resource_name from_resource_name, ra1.allow_decision decision, ISNULL(ra1.allow_count, 0) allow_count FROM (       (SELECT ra.from_resource_name from_resource_name, ra.policy_decision allow_decision, count(ra.from_resource_name) allow_count from RPA_LOG ra               WHERE policy_decision = 'A' AND day_nb >= ? AND day_nb <= ? GROUP BY ra.from_resource_name, ra.policy_decision) ra1 RIGHT JOIN       (SELECT rp.from_resource_name from_resource_name, 'A' deny_decision from RPA_LOG rp               WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1       ON (rp1.from_resource_name = ra1.from_resource_name))) a1    INNER JOIN   (SELECT rp1.from_resource_name from_resource_name, rp1.deny_decision decision, ISNULL(rd1.deny_count, 0) deny_count FROM (      (SELECT rd.from_resource_name from_resource_name, rd.policy_decision deny_decision, count(rd.from_resource_name) deny_count from RPA_LOG rd              WHERE policy_decision = 'D' AND day_nb >= ? AND day_nb <= ? GROUP BY rd.from_resource_name, rd.policy_decision) rd1 RIGHT JOIN      (SELECT rp.from_resource_name from_resource_name, 'D' deny_decision from RPA_LOG rp              WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1      ON (rp1.from_resource_name = rd1.from_resource_name))) d1  ON  (a1.from_resource_name = d1.from_resource_name)) ORDER BY total_count DESC;

SELECT a1.from_resource_name, a1.allow_count, d1.deny_count, (a1.allow_count + d1.deny_count) total_count FROM (   (SELECT rp1.from_resource_name from_resource_name, ra1.allow_decision decision, NVL(ra1.allow_count, 0) allow_count FROM (       (SELECT ra.from_resource_name from_resource_name, ra.policy_decision allow_decision, count(ra.from_resource_name) allow_count from RPA_LOG ra               WHERE policy_decision = 'A' AND day_nb >= ? AND day_nb <= ? GROUP BY ra.from_resource_name, ra.policy_decision) ra1 RIGHT JOIN       (SELECT rp.from_resource_name from_resource_name, 'A' deny_decision from RPA_LOG rp               WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1       ON (rp1.from_resource_name = ra1.from_resource_name))) a1    INNER JOIN   (SELECT rp1.from_resource_name from_resource_name, rp1.deny_decision decision, NVL(rd1.deny_count, 0) deny_count FROM (      (SELECT rd.from_resource_name from_resource_name, rd.policy_decision deny_decision, count(rd.from_resource_name) deny_count from RPA_LOG rd              WHERE policy_decision = 'D' AND day_nb >= ? AND day_nb <= ? GROUP BY rd.from_resource_name, rd.policy_decision) rd1 RIGHT JOIN      (SELECT rp.from_resource_name from_resource_name, 'D' deny_decision from RPA_LOG rp              WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1      ON (rp1.from_resource_name = rd1.from_resource_name))) d1  ON (a1.from_resource_name = d1.from_resource_name)) ORDER BY total_count DESC;

SELECT a1.from_resource_name, a1.allow_count, d1.deny_count, (a1.allow_count + d1.deny_count) total_count FROM (   (SELECT rp1.from_resource_name from_resource_name, ra1.allow_decision decision, COALESCE(ra1.allow_count, 0) allow_count FROM (       (SELECT ra.from_resource_name from_resource_name, ra.policy_decision allow_decision, count(ra.from_resource_name) allow_count from RPA_LOG ra               WHERE policy_decision = 'A' AND day_nb >= ? AND day_nb <= ? GROUP BY ra.from_resource_name, ra.policy_decision) ra1 RIGHT JOIN       (SELECT rp.from_resource_name from_resource_name, 'A' deny_decision from RPA_LOG rp               WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1       ON (rp1.from_resource_name = ra1.from_resource_name))) a1    INNER JOIN   (SELECT rp1.from_resource_name from_resource_name, rp1.deny_decision decision, COALESCE(rd1.deny_count, 0) deny_count FROM (      (SELECT rd.from_resource_name from_resource_name, rd.policy_decision deny_decision, count(rd.from_resource_name) deny_count from RPA_LOG rd              WHERE policy_decision = 'D' AND day_nb >= ? AND day_nb <= ? GROUP BY rd.from_resource_name, rd.policy_decision) rd1 RIGHT JOIN      (SELECT rp.from_resource_name from_resource_name, 'D' deny_decision from RPA_LOG rp              WHERE day_nb >= ? AND day_nb <= ?  GROUP BY rp.from_resource_name) rp1      ON (rp1.from_resource_name = rd1.from_resource_name))) d1  ON (a1.from_resource_name = d1.from_resource_name)) ORDER BY total_count DESC;

SELECT policy_fullname, policy_name, policy_decision, COUNT(policy_fullname) total_count FROM RPA_LOG r  WHERE day_nb >= ? AND day_nb <= ?  GROUP BY policy_fullname, policy_name, policy_decision ORDER BY total_count DESC;

SELECT l.fullname, l.deployer FROM   (SELECT d.name fullname, d.submitter deployer, k.policy_fullname policy_fullname FROM DEVELOPMENT_ENTITIES d LEFT JOIN     (SELECT r.policy_fullname policy_fullname FROM RPA_LOG r       WHERE r.day_nb >= ? AND r.day_nb <= ? GROUP BY r.policy_fullname) k   ON (k.policy_fullname = CONCAT('/', d.name)) WHERE d.type = 'PO' AND d.status = 'AP' AND d.hidden = 'N') l WHERE l.policy_fullname is null;

SELECT DAY_NB, POLICY_DECISION, count(ID) FROM RPA_LOG  WHERE DAY_NB >= ? AND DAY_NB <= ? AND POLICY_DECISION = ? GROUP BY DAY_NB, POLICY_DECISION ORDER BY DAY_NB;

SELECT a.ID, a.HOST, a.TYPE, a.REGISTERED, a.LASTHEARTBEAT, a.DEPLOYMENT_BUNDLE_TS,  c.HEART_BEAT_FREQ_TIME, c.HEART_BEAT_FREQ_TIME_UNIT FROM AGENT a INNER JOIN  COMM_PROFILE c  on (a.COMM_PROFILE_ID = c.ID) WHERE a.REGISTERED = ?;

SELECT e.id, e.DOMAIN_NAME , e.ENROLLMENT_TYPE , u.IS_SUCCESSFUL, u.ERR_MSG, u.ACTIVE_FROM FROM DICT_ENROLLMENTS e LEFT JOIN DICT_UPDATES u  ON ( e.ID = u.ENROLLMENT_ID) WHERE ACTIVE_TO >= ?;

SELECT ID, NAME FROM MONITOR WHERE IS_ACTIVE = ?;

SELECT COUNT(*) FROM ARCHIVE_POLICY_ACTIVITY_LOG;

SELECT COUNT(*) FROM POLICY_ACTIVITY_LOG;

SELECT COUNT(*) FROM POLICY_ACTIVITY_LOG WHERE DAY_NB >=  ? AND DAY_NB <= ?;

SELECT t FROM TagLabel t WHERE t.type = ? ORDER BY t.label;

SELECT t FROM TagLabel t WHERE lower(t.key) = ? AND t.type = ? ORDER BY t.label;

SELECT e FROM PolicyDevelopmentEntity e WHERE e.type = ?;

SELECT e FROM PolicyDevelopmentEntity e WHERE e.hidden = ? AND e.status != ? AND e.type = ?;

SELECT t FROM AuthHandlerTypeDetail t WHERE t.type = ? ORDER BY t.type;


SELECT ID, USERNAME, FIRST_NAME, LAST_NAME, DOMAIN_ID, PRIMARY_GROUP_ID, LAST_LOGGED_TIME, HIDE_SPLASH, LAST_UPDATED, EMAIL FROM SUPER_APPLICATION_USER a WHERE LOWER(a.username) = ?;

INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'GET', '/api/v1/sysconfig/getUIConfigs', 'authenticated');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'GET', '/api/v1/sysconfig/reset', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'POST', '/api/v1/sysconfig/search', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'POST', '/api/v1/sysconfig/update', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'GET', '/api/v1/sysconfig/get', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');

INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'POST', '/api/v1/loggerConfiguration/save', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'GET', '/api/v1/loggerConfiguration/findAll', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'POST', '/api/v1/loggerConfiguration/delete', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'GET', '/api/v1/loggerConfiguration/refresh', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'POST', '/api/v1/loggerHandler/save', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'GET', '/api/v1/loggerHandler/findAll', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');
INSERT INTO ACCESS_CONTROL (ID, REQUEST_METHOD, URL_PATTERN, EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL, 'POST', '/api/v1/loggerHandler/delete', 'hasAnyAuthority(''VIEW_ADMINISTRATOR'')');

INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'console','policy-evaluation','INFO',0,0,'Control Center Console Policy Evaluation Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'console','org.springframework','WARN',0,0,'Control Center Console Spring Framework Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'console','com.mchange','ERROR',0,0,'Control Center Console Database Connection Pool Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'console','com.nextlabs.destiny.console','INFO',0,0,'Control Center Console Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'console','com.bluejungle.pf.engine.destiny','INFO',0,0,'Control Center Console Base Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'console','com.bluejungle.destiny.agent.controlmanager','INFO',0,0,'Control Center Console Agent Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'console','com.nextlabs.destiny.console.AuditLogger','INFO',0,0,'Control Center Console Audit Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'config-service','com.nextlabs.destiny.configservice','INFO',0,0,'Control Center Configuration Service Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'config-service','org.springframework','INFO',0,0,'Control Center Configuration Service Spring Framework Logger');
INSERT INTO LOGGER_CONFIGURATION (ID,APPLICATION,NAME,LOG_LEVEL,PARENT,CUSTOM,DISPLAY_NAME) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'config-service','com.mchange','INFO',0,0,'Control Center Configuration Service Database Connection Pool Logger');

INSERT INTO LOGGER_HANDLER (ID,NAME,LOG_LEVEL,TYPE,APPEND,FILE_NAME,FILE_LIMIT,FILE_COUNT,CUSTOM) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'Server Console','WARN','CONSOLE',NULL,NULL,NULL,NULL,0);
INSERT INTO LOGGER_HANDLER (ID,NAME,LOG_LEVEL,TYPE,APPEND,FILE_NAME,FILE_LIMIT,FILE_COUNT,CUSTOM) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'Control Center Console File Handler','ALL','FILE',1,'console',500000,10,0);
INSERT INTO LOGGER_HANDLER (ID,NAME,LOG_LEVEL,TYPE,APPEND,FILE_NAME,FILE_LIMIT,FILE_COUNT,CUSTOM) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'Control Center Configuration Service File Handler','ALL','FILE',1,'configservice',500000,10,0);

INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'console' AND NAME = 'org.springframework'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Console File Handler'));
INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'console' AND NAME = 'com.mchange'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Console File Handler'));
INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'console' AND NAME = 'com.nextlabs.destiny.console'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Console File Handler'));
INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'console' AND NAME = 'com.bluejungle.destiny.agent.controlmanager'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Console File Handler'));
INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'console' AND NAME = 'policy-evaluation'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Console File Handler'));
INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'console' AND NAME = 'com.bluejungle.pf.engine.destiny'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Console File Handler'));
INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'config-service' AND NAME = 'com.nextlabs.destiny.configservice'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Configuration Service File Handler'));
INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'config-service' AND NAME = 'org.springframework'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Configuration Service File Handler'));
INSERT INTO LOGGER_HANDLER_CONFIGURATION(LOGGER_ID, HANDLER_ID)  VALUES((SELECT MAX(ID) FROM LOGGER_CONFIGURATION WHERE APPLICATION = 'config-service' AND NAME = 'com.mchange'), (SELECT MAX(ID) FROM LOGGER_HANDLER WHERE NAME = 'Control Center Configuration Service File Handler'));

INSERT INTO
OPERATOR_CONFIG(id, created_date, last_updated_by, last_updated, created_by, version, data_type, operator_key, label)
VALUES
(HIBERNATE_SEQUENCE.NEXTVAL, sysdate, 0, sysdate, 0, 0, 'DATE', '<', 'before');

INSERT INTO
OPERATOR_CONFIG(id, created_date, last_updated_by, last_updated, created_by, version, data_type, operator_key, label)
VALUES
(HIBERNATE_SEQUENCE.NEXTVAL,sysdate, 0, sysdate, 0, 0, 'DATE', '>=', 'on or after');

UPDATE ACCESS_CONTROL SET URL_PATTERN = '/api/v1/policyModel/mgmt/extraSubjectAttribs/{type:[A-Za-z]+}' WHERE REQUEST_METHOD = 'GET' AND URL_PATTERN = '/api/v1/policyModel/mgmt/extraSubjectAttribs/{type:[A-Z]+}';

INSERT INTO ACCESS_CONTROL (ID,REQUEST_METHOD,URL_PATTERN,EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'GET','/swagger-ui.html','authenticated');
INSERT INTO ACCESS_CONTROL (ID,REQUEST_METHOD,URL_PATTERN,EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'GET','/webjars/springfox-swagger-ui/**','authenticated');
INSERT INTO ACCESS_CONTROL (ID,REQUEST_METHOD,URL_PATTERN,EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'GET','/swagger-resources','authenticated');
INSERT INTO ACCESS_CONTROL (ID,REQUEST_METHOD,URL_PATTERN,EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'GET','/swagger-resources/**','authenticated');
INSERT INTO ACCESS_CONTROL (ID,REQUEST_METHOD,URL_PATTERN,EXPRESSION) VALUES (HIBERNATE_SEQUENCE.NEXTVAL,'GET','/api-docs','authenticated');

-- DDAC component has been removed
DELETE FROM COMPONENT WHERE type LIKE 'DDAC';

UPDATE APPLICATION_USER
SET USERNAME = USERNAME || '_' || TO_CHAR(LAST_UPDATED, 'YYMMDDHHMISS'),
LAST_NAME = LAST_NAME || ' (deactivated ' || TO_CHAR(LAST_UPDATED, 'DD Mon YYYY') || ')',
DISPLAYNAME = DISPLAYNAME || ' (deactivated ' || TO_CHAR(LAST_UPDATED, 'DD Mon YYYY') || ')'
WHERE STATUS = 'DELETED';

-- Remove references to ACTIVE_DIRECTORY agent type
DELETE FROM COMM_PROFILE WHERE agent_type LIKE 'ACTIVE_DIRECTORY';

DELETE FROM COMM_PROFILE_SEED_ITEMS WHERE SEED_NAME LIKE 'DefaultCommProfile_ACTIVE_DIRECTORY';

SELECT USERNAME, FIRST_NAME, LAST_NAME, DOMAIN_ID, PRIMARY_GROUP_ID, PASSWORD, INITLOGIN_DONE, LOCKED, FAILED_LOGIN_ATTEMPTS FROM SUPER_APPLICATION_USER
UNION ALL
SELECT USERNAME, FIRST_NAME, LAST_NAME, DOMAIN_ID, PRIMARY_GROUP_ID, password, INITLOGIN_DONE, LOCKED, FAILED_LOGIN_ATTEMPTS FROM APPLICATION_USER
  WHERE STATUS != 'DELETED' AND NOT EXISTS (
  	SELECT USERNAME FROM SUPER_APPLICATION_USER WHERE APPLICATION_USER.USERNAME = SUPER_APPLICATION_USER.USERNAME
  );


SELECT 0 AS id, policy_log_id, attribute_type, attribute_name, attribute_value  FROM
(SELECT
temp.id AS policy_log_id,
temp.attr_type AS attribute_type,
map.name AS attribute_name,
temp.attribute_value
FROM
(SELECT
   Y.id,
   X.attr_type,
   X.mapped_column,
    CASE X.mapped_column
	WHEN 'attr1' THEN Y.attr1
	WHEN 'attr2' THEN Y.attr2
	WHEN 'attr3' THEN Y.attr3
	WHEN 'attr4' THEN Y.attr4
	WHEN 'attr5' THEN Y.attr5
	WHEN 'attr6' THEN Y.attr6
	WHEN 'attr7' THEN Y.attr7
	WHEN 'attr8' THEN Y.attr8
	WHEN 'attr9' THEN Y.attr9
	WHEN 'attr10' THEN Y.attr10
	WHEN 'attr11' THEN Y.attr11
	WHEN 'attr12' THEN Y.attr12
	WHEN 'attr13' THEN Y.attr13
	WHEN 'attr14' THEN Y.attr14
	WHEN 'attr15' THEN Y.attr15
	WHEN 'attr16' THEN Y.attr16
	WHEN 'attr17' THEN Y.attr17
	WHEN 'attr18' THEN Y.attr18
	WHEN 'attr19' THEN Y.attr19
	WHEN 'attr20' THEN Y.attr20
	WHEN 'attr21' THEN Y.attr21
	WHEN 'attr22' THEN Y.attr22
	WHEN 'attr23' THEN Y.attr23
	WHEN 'attr24' THEN Y.attr24
	WHEN 'attr25' THEN Y.attr25
	WHEN 'attr26' THEN Y.attr26
	WHEN 'attr27' THEN Y.attr27
	WHEN 'attr28' THEN Y.attr28
	WHEN 'attr29' THEN Y.attr29
	WHEN 'attr30' THEN Y.attr30
	WHEN 'attr31' THEN Y.attr31
	WHEN 'attr32' THEN Y.attr32
	WHEN 'attr33' THEN Y.attr33
	WHEN 'attr34' THEN Y.attr34
	WHEN 'attr35' THEN Y.attr35
	WHEN 'attr36' THEN Y.attr36
	WHEN 'attr37' THEN Y.attr37
	WHEN 'attr38' THEN Y.attr38
	WHEN 'attr39' THEN Y.attr39
	WHEN 'attr40' THEN Y.attr40
	WHEN 'attr41' THEN Y.attr41
	WHEN 'attr42' THEN Y.attr42
	WHEN 'attr43' THEN Y.attr43
	WHEN 'attr44' THEN Y.attr44
	WHEN 'attr45' THEN Y.attr45
	WHEN 'attr46' THEN Y.attr46
	WHEN 'attr47' THEN Y.attr47
	WHEN 'attr48' THEN Y.attr48
	WHEN 'attr49' THEN Y.attr49
	WHEN 'attr50' THEN Y.attr50
	WHEN 'attr51' THEN Y.attr51
	WHEN 'attr52' THEN Y.attr52
	WHEN 'attr53' THEN Y.attr53
	WHEN 'attr54' THEN Y.attr54
	WHEN 'attr55' THEN Y.attr55
	WHEN 'attr56' THEN Y.attr56
	WHEN 'attr57' THEN Y.attr57
	WHEN 'attr58' THEN Y.attr58
	WHEN 'attr59' THEN Y.attr59
	WHEN 'attr60' THEN Y.attr60
	WHEN 'attr61' THEN Y.attr61
	WHEN 'attr62' THEN Y.attr62
	WHEN 'attr63' THEN Y.attr63
	WHEN 'attr64' THEN Y.attr64
	WHEN 'attr65' THEN Y.attr65
	WHEN 'attr66' THEN Y.attr66
	WHEN 'attr67' THEN Y.attr67
	WHEN 'attr68' THEN Y.attr68
	WHEN 'attr69' THEN Y.attr69
	WHEN 'attr70' THEN Y.attr70
	WHEN 'attr71' THEN Y.attr71
	WHEN 'attr72' THEN Y.attr72
	WHEN 'attr73' THEN Y.attr73
	WHEN 'attr74' THEN Y.attr74
	WHEN 'attr75' THEN Y.attr75
	WHEN 'attr76' THEN Y.attr76
	WHEN 'attr77' THEN Y.attr77
	WHEN 'attr78' THEN Y.attr78
	WHEN 'attr79' THEN Y.attr79
	WHEN 'attr80' THEN Y.attr80
	WHEN 'attr81' THEN Y.attr81
	WHEN 'attr82' THEN Y.attr82
	WHEN 'attr83' THEN Y.attr83
	WHEN 'attr84' THEN Y.attr84
	WHEN 'attr85' THEN Y.attr85
	WHEN 'attr86' THEN Y.attr86
	WHEN 'attr87' THEN Y.attr87
	WHEN 'attr88' THEN Y.attr88
	WHEN 'attr89' THEN Y.attr89
	WHEN 'attr90' THEN Y.attr90
	WHEN 'attr91' THEN Y.attr91
	WHEN 'attr92' THEN Y.attr92
	WHEN 'attr93' THEN Y.attr93
	WHEN 'attr94' THEN Y.attr94
	WHEN 'attr95' THEN Y.attr95
	WHEN 'attr96' THEN Y.attr96
	WHEN 'attr97' THEN Y.attr97
	WHEN 'attr98' THEN Y.attr98
	WHEN 'attr99' THEN Y.attr99
	END AS attribute_value
FROM
   rpa_log  Y CROSS JOIN  (select mapped_column, attr_type FROM rpa_log_mapping where mapped_column is NOT NULL) X) temp
JOIN rpa_log_mapping  map on temp.mapped_column = map.mapped_column
WHERE temp.attribute_value IS NOT NULL

UNION ALL

SELECT policy_log_id, map.name AS attribute_name, attr_value AS attribute_value, attr_type as attribute_type from rpa_log_attr rla
JOIN rpa_log_mapping map on rla.attr_id = map.id) results;

SELECT
    id as id,
    ref_log_id as policy_log_id,
    name as name,
    attr_one as attribute_one,
    attr_two as attribute_two,
    attr_three as attribute_three
FROM report_obligation_log;

SELECT
    id as id,
    tracking_log_id as tracking_log_id,
    attribute_name as attribute_name,
    attribute_value as attribute_value
FROM report_tracking_custom_attr;

SELECT
    id as id,
	host_id as host_id,
	host_ip as host_ip,
    host_name as host_name,
	user_id as user_id,
    user_name as user_name,
    user_sid as user_sid,
	application_id as application_id,
    application_name as application_name,
    action as action,
	policy_id as policy_id,
    policy_fullname as policy_full_name,
	policy_name as policy_name,
    policy_decision as policy_decision,
	decision_request_id as decision_request_id,
    log_level as log_level,
    from_resource_name as source_resource_name,
	from_resource_size as source_resource_size,
    from_resource_prefix as source_resource_prefix,
    from_resource_path as source_resource_path,
    from_resource_short_name as source_resource_short_name,
    from_resource_owner_id as source_resource_owner_id,
    from_resource_created_date as source_resource_create_date,
	from_resource_modified_date as source_resource_modified_date,
    to_resource_name as target_resource_name,
	attr1 as attr1,
	attr2 as attr2,
	attr3 as attr3,
	attr4 as attr4,
	attr5 as attr5,
	attr6 as attr6,
	attr7 as attr7,
	attr8 as attr8,
	attr9 as attr9,
	attr10 as attr10,
	attr11 as attr11,
	attr12 as attr12,
	attr13 as attr13,
	attr14 as attr14,
	attr15 as attr15,
	attr16 as attr16,
	attr17 as attr17,
	attr18 as attr18,
	attr19 as attr19,
	attr20 as attr20,
	attr21 as attr21,
	attr22 as attr22,
	attr23 as attr23,
	attr24 as attr24,
	attr25 as attr25,
	attr26 as attr26,
	attr27 as attr27,
	attr28 as attr28,
	attr29 as attr29,
	attr30 as attr30,
	attr31 as attr31,
	attr32 as attr32,
	attr33 as attr33,
	attr34 as attr34,
	attr35 as attr35,
	attr36 as attr36,
	attr37 as attr37,
	attr38 as attr38,
	attr39 as attr39,
	attr40 as attr40,
	attr41 as attr41,
	attr42 as attr42,
	attr43 as attr43,
	attr44 as attr44,
	attr45 as attr45,
	attr46 as attr46,
	attr47 as attr47,
	attr48 as attr48,
	attr49 as attr49,
	attr50 as attr50,
	attr51 as attr51,
	attr52 as attr52,
	attr53 as attr53,
	attr54 as attr54,
	attr55 as attr55,
	attr56 as attr56,
	attr57 as attr57,
	attr58 as attr58,
	attr59 as attr59,
	attr60 as attr60,
	attr61 as attr61,
	attr62 as attr62,
	attr63 as attr63,
	attr64 as attr64,
	attr65 as attr65,
	attr66 as attr66,
	attr67 as attr67,
	attr68 as attr68,
	attr69 as attr69,
	attr70 as attr70,
	attr71 as attr71,
	attr72 as attr72,
	attr73 as attr73,
	attr74 as attr74,
	attr75 as attr75,
	attr76 as attr76,
	attr77 as attr77,
	attr78 as attr78,
	attr79 as attr79,
	attr80 as attr80,
	attr81 as attr81,
	attr82 as attr82,
	attr83 as attr83,
	attr84 as attr84,
	attr85 as attr85,
	attr86 as attr86,
	attr87 as attr87,
	attr88 as attr88,
	attr89 as attr89,
	attr90 as attr90,
	attr91 as attr91,
	attr92 as attr92,
	attr93 as attr93,
	attr94 as attr94,
	attr95 as attr95,
	attr96 as attr96,
	attr97 as attr97,
	attr98 as attr98,
	attr99 as attr99
FROM rpa_log;

SELECT
    policy_log_id as policy_log_id,
    attr_id as attr_id,
    attr_value as attr_value
FROM rpa_log_attr;

SELECT
    mapped_column as mapped_column,
    name as name,
    data_type as data_type,
    attr_type as attr_type
FROM rpa_log_mapping;

/* FROM com.nextlabs.destiny.console.model.SavedSearch */ select savedsearc0_.id as id1_21_, savedsearc0_.created_date as created_2_21_, savedsearc0_.last_updated_by as last_upd3_21_, savedsearc0_.last_updated as last_upd4_21_, savedsearc0_.created_by as created_5_21_, savedsearc0_.version as version6_21_, savedsearc0_.criteria_json as criteria7_21_, savedsearc0_.description as descript8_21_, savedsearc0_.lowercase_name as lowercas9_21_, savedsearc0_.name as name10_21_, savedsearc0_.shared_mode as shared_11_21_, savedsearc0_.status as status12_21_, savedsearc0_.type as type13_21_ from SAVED_SEARCH savedsearc0_;
/* FROM com.nextlabs.destiny.console.model.SuperApplicationUser */ select superappli0_.id as id1_22_, superappli0_.created_date as created_2_22_, superappli0_.displayName as displayN3_22_, superappli0_.email as email4_22_, superappli0_.failed_login_attempts as failed_l5_22_, superappli0_.first_name as first_na6_22_, superappli0_.hide_splash as hide_spl7_22_, superappli0_.initlogin_done as initlogi8_22_, superappli0_.last_name as last_nam9_22_, superappli0_.last_updated_by as last_up10_22_, superappli0_.last_updated as last_up11_22_, superappli0_.locked as locked12_22_, superappli0_.last_logged_time as last_lo13_22_, superappli0_.created_by as created14_22_, superappli0_.password as passwor15_22_, superappli0_.username as usernam16_22_ from SUPER_APPLICATION_USER superappli0_;
/* FROM com.nextlabs.destiny.console.model.TagLabel */ select taglabel0_.id as id1_23_, taglabel0_.created_date as created_2_23_, taglabel0_.last_updated_by as last_upd3_23_, taglabel0_.last_updated as last_upd4_23_, taglabel0_.created_by as created_5_23_, taglabel0_.version as version6_23_, taglabel0_.hidden as hidden7_23_, taglabel0_.tag_key as tag_key8_23_, taglabel0_.label as label9_23_, taglabel0_.status as status10_23_, taglabel0_.type as type11_23_ from TAG_LABELS taglabel0_;
/* FROM com.nextlabs.destiny.console.model.authorization.AccessControl */ select accesscont0_.id as id1_0_, accesscont0_.expression as expressi2_0_, accesscont0_.request_method as request_3_0_, accesscont0_.url_pattern as url_patt4_0_ from ACCESS_CONTROL accesscont0_;
/* dynamic native SQL query */ SELECT ID, USERNAME, FIRST_NAME, LAST_NAME, DOMAIN_ID, PRIMARY_GROUP_ID, LAST_LOGGED_TIME, HIDE_SPLASH, LAST_UPDATED, USER_TYPE, AUTH_HANDLER_ID    FROM APPLICATION_USER a WHERE a.status = ?;
/* named HQL query appUserProperties.findByUserId */ select appuserpro0_.id as id1_3_, appuserpro0_.created_date as created_2_3_, appuserpro0_.last_updated_by as last_upd3_3_, appuserpro0_.last_updated as last_upd4_3_, appuserpro0_.created_by as created_5_3_, appuserpro0_.version as version6_3_, appuserpro0_.data_type as data_typ7_3_, appuserpro0_.prop_key as prop_key8_3_, appuserpro0_.super_user_id as super_us9_3_, appuserpro0_.user_id as user_id10_3_, appuserpro0_.prop_value as prop_va11_3_ from APP_USER_PROPERTIES appuserpro0_ where appuserpro0_.user_id=? order by appuserpro0_.prop_key;
/* named HQL query policy.findActiveByType */ select policydeve0_.id as id1_9_, policydeve0_.appql as appql2_9_, policydeve0_.created as created3_9_, policydeve0_.description as descript4_9_, policydeve0_.extended_desc as extended5_9_, policydeve0_.has_dependencies as has_depe6_9_, policydeve0_.hidden as hidden7_9_, policydeve0_.is_sub_policy as is_sub_p8_9_, policydeve0_.last_modified as last_mod9_9_, policydeve0_.last_updated as last_up10_9_, policydeve0_.modifier as modifie11_9_, policydeve0_.owner as owner12_9_, policydeve0_.pql as pql13_9_, policydeve0_.status as status14_9_, policydeve0_.submitted_time as submitt15_9_, policydeve0_.submitter as submitt16_9_, policydeve0_.name as name17_9_, policydeve0_.type as type18_9_, policydeve0_.version as version19_9_ from DEVELOPMENT_ENTITIES policydeve0_ where policydeve0_.hidden=? and policydeve0_.status<>? and policydeve0_.type=?;
/* named HQL query tag.findByKey */ select taglabel0_.id as id1_23_, taglabel0_.created_date as created_2_23_, taglabel0_.last_updated_by as last_upd3_23_, taglabel0_.last_updated as last_upd4_23_, taglabel0_.created_by as created_5_23_, taglabel0_.version as version6_23_, taglabel0_.hidden as hidden7_23_, taglabel0_.tag_key as tag_key8_23_, taglabel0_.label as label9_23_, taglabel0_.status as status10_23_, taglabel0_.type as type11_23_ from TAG_LABELS taglabel0_ where lower(taglabel0_.tag_key)=? and taglabel0_.type=? order by taglabel0_.label;
/* select count(generatedAlias0) from OperatorConfig as generatedAlias0 where 1=1 */ select count(operatorco0_.id) as col_0_0_ from OPERATOR_CONFIG operatorco0_ where 1=1;
/* select generatedAlias0 from DelegateModel as generatedAlias0 where ( generatedAlias0.shortName=:param0 ) and ( generatedAlias0.status<>:param1 ) */ select delegatemo0_.id as id2_19_, delegatemo0_.created_date as created_3_19_, delegatemo0_.last_updated_by as last_upd4_19_, delegatemo0_.last_updated as last_upd5_19_, delegatemo0_.created_by as created_6_19_, delegatemo0_.version as version7_19_, delegatemo0_.description as descript8_19_, delegatemo0_.name as name9_19_, delegatemo0_.short_name as short_n10_19_, delegatemo0_.status as status11_19_, delegatemo0_.type as type12_19_ from POLICY_MODEL delegatemo0_ where delegatemo0_.discriminator='DELEGATION' and delegatemo0_.short_name=? and delegatemo0_.status<>?;
/* select generatedAlias0 from DelegateModel as generatedAlias0 where ( generatedAlias0.type=:param0 ) or ( generatedAlias0.type=:param1 ) */ select delegatemo0_.id as id2_19_, delegatemo0_.created_date as created_3_19_, delegatemo0_.last_updated_by as last_upd4_19_, delegatemo0_.last_updated as last_upd5_19_, delegatemo0_.created_by as created_6_19_, delegatemo0_.version as version7_19_, delegatemo0_.description as descript8_19_, delegatemo0_.name as name9_19_, delegatemo0_.short_name as short_n10_19_, delegatemo0_.status as status11_19_, delegatemo0_.type as type12_19_ from POLICY_MODEL delegatemo0_ where delegatemo0_.discriminator='DELEGATION' and (delegatemo0_.type=? or delegatemo0_.type=?);
/* select generatedAlias0 from PolicyDevelopmentEntity as generatedAlias0 where ( generatedAlias0.title=:param0 ) and ( generatedAlias0.status<>:param1 ) */ select policydeve0_.id as id1_9_, policydeve0_.appql as appql2_9_, policydeve0_.created as created3_9_, policydeve0_.description as descript4_9_, policydeve0_.extended_desc as extended5_9_, policydeve0_.has_dependencies as has_depe6_9_, policydeve0_.hidden as hidden7_9_, policydeve0_.is_sub_policy as is_sub_p8_9_, policydeve0_.last_modified as last_mod9_9_, policydeve0_.last_updated as last_up10_9_, policydeve0_.modifier as modifie11_9_, policydeve0_.owner as owner12_9_, policydeve0_.pql as pql13_9_, policydeve0_.status as status14_9_, policydeve0_.submitted_time as submitt15_9_, policydeve0_.submitter as submitt16_9_, policydeve0_.name as name17_9_, policydeve0_.type as type18_9_, policydeve0_.version as version19_9_ from DEVELOPMENT_ENTITIES policydeve0_ where policydeve0_.name=? and policydeve0_.status<>?;
/* select generatedAlias0 from PolicyModel as generatedAlias0 where ( generatedAlias0.type=:param0 ) or ( generatedAlias0.type=:param1 ) */ select policymode0_.id as id2_19_, policymode0_.created_date as created_3_19_, policymode0_.last_updated_by as last_upd4_19_, policymode0_.last_updated as last_upd5_19_, policymode0_.created_by as created_6_19_, policymode0_.version as version7_19_, policymode0_.description as descript8_19_, policymode0_.name as name9_19_, policymode0_.short_name as short_n10_19_, policymode0_.status as status11_19_, policymode0_.type as type12_19_, policymode0_.discriminator as discrimi1_19_ from POLICY_MODEL policymode0_ where policymode0_.type=? or policymode0_.type=?;
SELECT * FROM "connection_test_table_sa3662";
SELECT ID, TYPE, CONFIG_DATA_JSON FROM AUTH_HANDLER_REGISTRY;
delete from REPORT_INTERNAL where property=?;
insert into REPORT_INTERNAL (value, property) values (?, ?);
select actions0_.plcy_model_id as plcy_mo11_19_0_, actions0_.id as id1_14_0_, actions0_.id as id1_14_1_, actions0_.created_date as created_2_14_1_, actions0_.last_updated_by as last_upd3_14_1_, actions0_.last_updated as last_upd4_14_1_, actions0_.created_by as created_5_14_1_, actions0_.version as version6_14_1_, actions0_.name as name7_14_1_, actions0_.short_code as short_co8_14_1_, actions0_.short_name as short_na9_14_1_, actions0_.sort_order as sort_or10_14_1_ from PM_ACTION_CONFIG actions0_ where actions0_.plcy_model_id=?;
select attributes0_.plcy_model_id as plcy_mo13_19_0_, attributes0_.id as id1_15_0_, attributes0_.id as id1_15_1_, attributes0_.created_date as created_2_15_1_, attributes0_.last_updated_by as last_upd3_15_1_, attributes0_.last_updated as last_upd4_15_1_, attributes0_.created_by as created_5_15_1_, attributes0_.version as version6_15_1_, attributes0_.data_type as data_typ7_15_1_, attributes0_.name as name8_15_1_, attributes0_.policy_model_id as policy_12_15_1_, attributes0_.reg_ex_pattern as reg_ex_p9_15_1_, attributes0_.short_name as short_n10_15_1_, attributes0_.sort_order as sort_or11_15_1_, policymode1_.id as id2_19_2_, policymode1_.created_date as created_3_19_2_, policymode1_.last_updated_by as last_upd4_19_2_, policymode1_.last_updated as last_upd5_19_2_, policymode1_.created_by as created_6_19_2_, policymode1_.version as version7_19_2_, policymode1_.description as descript8_19_2_, policymode1_.name as name9_19_2_, policymode1_.short_name as short_n10_19_2_, policymode1_.status as status11_19_2_, policymode1_.type as type12_19_2_, policymode1_.discriminator as discrimi1_19_2_ from PM_ATTRIBUTE_CONFIG attributes0_ left outer join POLICY_MODEL policymode1_ on attributes0_.policy_model_id=policymode1_.id where attributes0_.plcy_model_id=?;
select componentd0_.id as id, componentd0_.name as name, componentd0_.type as type, componentd0_.typeDisplayName as typeDisp4_, componentd0_.callbackURL as callback5_, componentd0_.componentURL as componen6_, componentd0_.lastHeartbeat as lastHear7_, componentd0_.heartbeatRate as heartbea8_, componentd0_.version as version from COMPONENT componentd0_ where (componentd0_.name=? );
select componentd0_.id as id, componentd0_.name as name, componentd0_.type as type, componentd0_.typeDisplayName as typeDisp4_, componentd0_.callbackURL as callback5_, componentd0_.componentURL as componen6_, componentd0_.lastHeartbeat as lastHear7_, componentd0_.heartbeatRate as heartbea8_, componentd0_.version as version from COMPONENT componentd0_ where (componentd0_.type=? )and(componentd0_.callbackURL=? );
select count(*) from OBLIGATION_LOG where sync_done is null;
select count(*) from POLICY_ACTIVITY_LOG where sync_done is null;
select customappd0_.id as id, customappd0_.name as name, customappd0_.version as version, customappd0_.description as descript4_ from CUSTOM_APP customappd0_;
select customrepo0_.id as id, customrepo0_.app_ref_id as app_ref_id, customrepo0_.file_content as file_con3_ from REPORT_CUSTOM_APP_UI customrepo0_;
select customrepo0_.id as id, customrepo0_.app_ref_id as app_ref_id, customrepo0_.title as title, customrepo0_.description as descript4_ from REPORT_CUSTOM_APP customrepo0_;
select customrepo0_.id as id, customrepo0_.position as position, customrepo0_.custom_report_id as custom_r3_, customrepo0_.name as name, customrepo0_.content as content from REPORT_CUSTOM_APP_FILES customrepo0_;
select deployment0_.id as id, deployment0_.version as version, deployment0_.development_id as developm3_, deployment0_.dep_record_id as dep_reco4_, deployment0_.name as name, deployment0_.description as descript6_, deployment0_.pql as pql, deployment0_.processedpql as processe8_, deployment0_.override_cnt as override9_, deployment0_.active_from as active_10_, deployment0_.active_to as active_to, deployment0_.hidden as hidden, deployment0_.original_version as origina13_, deployment0_.last_modified as last_mo14_, deployment0_.modifier as modifier, deployment0_.submitted_time as submitt16_, deployment0_.submitter as submitter from deployment_entities deployment0_, deployment_records deployment1_, development_entities developmen2_ where deployment0_.development_id=developmen2_.id and ((deployment0_.override_cnt=0 )and(deployment0_.pql is not null )and(deployment0_.active_to>? )and(deployment0_.active_from<=? )and(deployment0_.active_from>? )and(deployment1_.deployment_type=?  and deployment0_.dep_record_id=deployment1_.id)and(developmen2_.type in(?) and deployment0_.development_id=developmen2_.id)) order by  developmen2_.id asc;
select deployment0_.id as id0_, deployment0_.action_type as action_t2_0_, deployment0_.deployment_type as deployme3_0_, deployment0_.as_of as as_of0_, deployment0_.when_requested as when_req5_0_, deployment0_.when_cancelled as when_can6_0_, deployment0_.hidden as hidden0_, deployment0_.deployer as deployer0_ from deployment_records deployment0_ where deployment0_.id=?;
select developmen0_.id as id0_, developmen0_.version as version0_, developmen0_.owner as owner0_, developmen0_.appql as appql0_, developmen0_.name as name0_, developmen0_.description as descript6_0_, developmen0_.pql as pql0_, developmen0_.status as status0_, developmen0_.type as type0_, developmen0_.last_updated as last_up10_0_, developmen0_.created as created0_, developmen0_.last_modified as last_mo12_0_, developmen0_.modifier as modifier0_, developmen0_.submitted_time as submitt14_0_, developmen0_.submitter as submitter0_, developmen0_.hidden as hidden0_, developmen0_.has_dependencies as has_dep17_0_, developmen0_.is_sub_policy as is_sub_18_0_ from development_entities developmen0_ where developmen0_.id=?;
select eventdo0_.id as id, eventdo0_.name as name from EVENT eventdo0_ where (eventdo0_.name=? );
select fields0_.PARENT_TYPE_ID as PARENT_T9___, fields0_.ID as ID__, fields0_.ID as ID0_, fields0_.VERSION as VERSION0_, fields0_.name as name0_, fields0_.name_upper as name_upper0_, fields0_.type as type0_, fields0_.label as label0_, fields0_.deleted as deleted0_, fields0_.mapping as mapping0_, fields0_.PARENT_TYPE_ID as PARENT_T9_0_ from DICT_TYPE_FIELDS fields0_ where fields0_.PARENT_TYPE_ID=?;
--select heartbeatr0_.id as id, heartbeatr0_.timestamp as timestamp from HEART_BEAT_RECORD heartbeatr0_ where (timestamp<? );
select loggedacti0_.settings_id as settings1___, loggedacti0_.action as action__ from ACT_JOURN_SETTINGS_LOGGED_ACTS loggedacti0_ where loggedacti0_.settings_id=?;
select max(updatereco0_.end_time) as x0_0_ from DICT_UPDATES updatereco0_ where ((not exists(select updatereco1_.ID from DICT_UPDATES updatereco1_ where (updatereco1_.ACTIVE_FROM<=updatereco0_.ACTIVE_FROM )and(updatereco1_.ACTIVE_TO>updatereco0_.ACTIVE_FROM )and(updatereco1_.is_successful='N' ))))and(updatereco0_.is_successful='Y' );
select min(updatereco0_.end_time) as x0_0_ from DICT_UPDATES updatereco0_ where ((not exists(select updatereco1_.ID from DICT_UPDATES updatereco1_ where (updatereco1_.ACTIVE_FROM<=updatereco0_.ACTIVE_FROM )and(updatereco1_.ACTIVE_TO>updatereco0_.ACTIVE_FROM )and(updatereco1_.is_successful='N' ))))and(updatereco0_.is_successful='Y' )and(updatereco0_.ACTIVE_FROM>? );
select obligation0_.plcy_model_id as plcy_mo11_19_0_, obligation0_.id as id1_17_0_, obligation0_.id as id1_17_1_, obligation0_.created_date as created_2_17_1_, obligation0_.last_updated_by as last_upd3_17_1_, obligation0_.last_updated as last_upd4_17_1_, obligation0_.created_by as created_5_17_1_, obligation0_.version as version6_17_1_, obligation0_.name as name7_17_1_, obligation0_.run_at as run_at8_17_1_, obligation0_.short_name as short_na9_17_1_, obligation0_.sort_order as sort_or10_17_1_ from PM_OBLIGATION_CONFIG obligation0_ where obligation0_.plcy_model_id=?;
select operatorco0_.attribute_id as attribut1_15_0_, operatorco0_.operator_id as operator2_16_0_, operatorco1_.id as id1_12_1_, operatorco1_.created_date as created_2_12_1_, operatorco1_.last_updated_by as last_upd3_12_1_, operatorco1_.last_updated as last_upd4_12_1_, operatorco1_.created_by as created_5_12_1_, operatorco1_.version as version6_12_1_, operatorco1_.data_type as data_typ7_12_1_, operatorco1_.operator_key as operator8_12_1_, operatorco1_.label as label9_12_1_ from PM_ATTRIB_CONFIG_OPER_CONFIG operatorco0_ inner join OPERATOR_CONFIG operatorco1_ on operatorco0_.operator_id=operatorco1_.id where operatorco0_.attribute_id=?;
select parameters0_.obligation_id as obligat16_17_0_, parameters0_.id as id1_18_0_, parameters0_.id as id1_18_1_, parameters0_.created_date as created_2_18_1_, parameters0_.last_updated_by as last_upd3_18_1_, parameters0_.last_updated as last_upd4_18_1_, parameters0_.created_by as created_5_18_1_, parameters0_.version as version6_18_1_, parameters0_.default_value as default_7_18_1_, parameters0_.is_editable as is_edita8_18_1_, parameters0_.is_hidden as is_hidde9_18_1_, parameters0_.list_values as list_va10_18_1_, parameters0_.is_mandatory as is_mand11_18_1_, parameters0_.name as name12_18_1_, parameters0_.short_name as short_n13_18_1_, parameters0_.sort_order as sort_or14_18_1_, parameters0_.data_type as data_ty15_18_1_ from PM_PARAMETER_CONFIG parameters0_ where parameters0_.obligation_id=?;
select registrati0_.EVENT_ID as EVENT_ID__, registrati0_.id as id__, registrati0_.COMPONENT_ID as COMPONEN4___, registrati0_.id as id1_, registrati0_.lastModified as lastModi2_1_, registrati0_.isActive as isActive1_, registrati0_.COMPONENT_ID as COMPONEN4_1_, registrati0_.EVENT_ID as EVENT_ID1_, componentd1_.id as id0_, componentd1_.name as name0_, componentd1_.type as type0_, componentd1_.typeDisplayName as typeDisp4_0_, componentd1_.callbackURL as callback5_0_, componentd1_.componentURL as componen6_0_, componentd1_.lastHeartbeat as lastHear7_0_, componentd1_.heartbeatRate as heartbea8_0_, componentd1_.version as version0_ from EVENT_REGISTRATION registrati0_ left outer join COMPONENT componentd1_ on registrati0_.COMPONENT_ID=componentd1_.id where registrati0_.EVENT_ID=?;
select reporterda0_.property as property0_, reporterda0_.value as value0_ from REPORT_INTERNAL reporterda0_ where reporterda0_.property=?;
select seeditems0_.SEED_COMM_PROFILE_ID as SEED_COM1___, seeditems0_.COMM_PROFILE_ID as COMM_PRO2___, seeditems0_.SEED_NAME as SEED_NAME__ from COMM_PROFILE_SEED_ITEMS seeditems0_ where seeditems0_.SEED_COMM_PROFILE_ID=?;
select tags0_.dev_entity_id as dev_enti1_9_0_, tags0_.tag_id as tag_id2_10_0_, taglabel1_.id as id1_23_1_, taglabel1_.created_date as created_2_23_1_, taglabel1_.last_updated_by as last_upd3_23_1_, taglabel1_.last_updated as last_upd4_23_1_, taglabel1_.created_by as created_5_23_1_, taglabel1_.version as version6_23_1_, taglabel1_.hidden as hidden7_23_1_, taglabel1_.tag_key as tag_key8_23_1_, taglabel1_.label as label9_23_1_, taglabel1_.status as status10_23_1_, taglabel1_.type as type11_23_1_ from DEVELOPMENT_ENTITIES_TAGS tags0_ inner join TAG_LABELS taglabel1_ on tags0_.tag_id=taglabel1_.id where tags0_.dev_entity_id=?;
select tags0_.plcy_model_id as plcy_mod1_19_0_, tags0_.tag_id as tag_id2_20_0_, taglabel1_.id as id1_23_1_, taglabel1_.created_date as created_2_23_1_, taglabel1_.last_updated_by as last_upd3_23_1_, taglabel1_.last_updated as last_upd4_23_1_, taglabel1_.created_by as created_5_23_1_, taglabel1_.version as version6_23_1_, taglabel1_.hidden as hidden7_23_1_, taglabel1_.tag_key as tag_key8_23_1_, taglabel1_.label as label9_23_1_, taglabel1_.status as status10_23_1_, taglabel1_.type as type11_23_1_ from POLICY_MODEL_TAGS tags0_ inner join TAG_LABELS taglabel1_ on tags0_.tag_id=taglabel1_.id where tags0_.plcy_model_id=?;
select this.ID as ID0_, this.VERSION as VERSION0_, this.domain_name as domain_n3_0_, this.enrollment_type as enrollme4_0_, this.isRecurring as isRecurr5_0_, this.isActive as isActive0_ from DICT_ENROLLMENTS this where this.isActive=?;
select this.ID as ID0_, this.VERSION as VERSION0_, this.name as name0_ from DICT_ELEMENT_TYPES this where this.name=?;
select this.id as id0_, this.lastUpdated as lastUpda2_0_, this.type as type0_ from RESOURCE_CACHE_STATE this where this.type=?;
select this.id as id0_, this.last_updated as last_upd2_0_ from COMM_PROFILE_SEED this where 1=1;
select this.id as id0_, this.name as name0_, this.customizable as customiz3_0_ from ACTIVITY_JOURNALING_SETTINGS this where this.name=?;
select this.id as id0_, this.name as name0_, this.description as descript3_0_, this.criteria_json as criteria4_0_, this.alert_message as alert_me5_0_, this.email_address as email_ad6_0_, this.auto_dismiss as auto_dis7_0_, this.email_admin as email_ad8_0_, this.is_active as is_active0_, this.created_datetime as created10_0_, this.updated_datetime as updated11_0_, this.is_deleted as is_deleted0_, this.uuid as uuid0_, this.is_archived as is_arch14_0_, this.shared_mode as shared_15_0_, this.owner_id as owner_id0_, this.pql_data as pql_data0_ from MONITOR this where (this.is_active=? and (this.is_deleted=? and this.is_archived=?));
select this.id as id0_, this.name as name0_, this.mapped_column as mapped_c3_0_, this.data_type as data_type0_, this.attr_type as attr_type0_, this.is_dynamic_attr as is_dynam6_0_ from RPA_LOG_MAPPING this where 1=1;
select this.id as id2_, this.lastModified as lastModi2_2_, this.isActive as isActive2_, this.COMPONENT_ID as COMPONEN4_2_, this.EVENT_ID as EVENT_ID2_, componentd1_.id as id0_, componentd1_.name as name0_, componentd1_.type as type0_, componentd1_.typeDisplayName as typeDisp4_0_, componentd1_.callbackURL as callback5_0_, componentd1_.componentURL as componen6_0_, componentd1_.lastHeartbeat as lastHear7_0_, componentd1_.heartbeatRate as heartbea8_0_, componentd1_.version as version0_, eventdo2_.id as id1_, eventdo2_.name as name1_ from EVENT_REGISTRATION this left outer join COMPONENT componentd1_ on this.COMPONENT_ID=componentd1_.id left outer join EVENT eventdo2_ on this.EVENT_ID=eventdo2_.id where this.lastModified>=? and not this.COMPONENT_ID=?;
--select top 1 this.id as id1_, this.default_profile as default_2_1_, this.created_date as created_3_1_, this.modified_date as modified4_1_, this.name as name1_, this.DABS_location as DABS_loc6_1_, this.agent_type as agent_type1_, this.heart_beat_freq_time as heart_be8_1_, this.heart_beat_freq_time_unit as heart_be9_1_, this.log_limit as log_limit1_, this.log_freq_time as log_fre11_1_, this.log_freq_time_unit as log_fre12_1_, this.default_port as default13_1_, this.push_enabled as push_en14_1_, this.password_hash as passwor15_1_, this.curr_act_journ_settings_name as curr_ac16_1_, this.cust_act_journ_settings_id as cust_ac17_1_, activityjo1_.id as id0_, activityjo1_.name as name0_, activityjo1_.customizable as customiz3_0_ from COMM_PROFILE this left outer join ACTIVITY_JOURNALING_SETTINGS activityjo1_ on this.cust_act_journ_settings_id=activityjo1_.id where (this.id=?) order by this.id asc;
--select top 1000 id,ref_log_id,name,attr_one,attr_two,attr_three from OBLIGATION_LOG where sync_done is null;
--select top 1000 id,time,host_id,host_ip,host_name,user_id,user_name,application_id,application_name,action,policy_id,policy_decision,decision_request_id,log_level,fromresourcename,fromresourcesize,fromresourceownerid,fromresourcecreateddate,fromresourcemodifieddate,toresourcename from POLICY_ACTIVITY_LOG where sync_done is null ORDER BY user_id ASC, time ASC;
--select top 30 this.id as id0_, this.creationTime as creation2_0_, this.dataObjectName as dataObje3_0_, this.resultObjectName as resultOb4_0_, this.availableRowCount as availabl5_0_, this.minValue as minValue0_, this.maxValue as maxValue0_, this.sumValue as sumValue0_, this.totalRowCount as totalRow9_0_ from STORED_QUERY this where this.creationTime<?;
update COMPONENT set name=?, type=?, typeDisplayName=?, callbackURL=?, componentURL=?, lastHeartbeat=?, heartbeatRate=?, version=? where id=?;
update EVENT_REGISTRATION set lastModified=?, isActive=?, COMPONENT_ID=?, EVENT_ID=? where id=?;
update REPORT_INTERNAL set value=? where property=?;
update RESOURCE_CACHE_STATE set lastUpdated=?, type=? where id=?;

select elementtyp1_.ID as ID, elementtyp1_.VERSION as VERSION, elementtyp1_.name as name, leafelemen0_.String01 as x0_0_, leafelemen0__1_.ORIGINAL_ID as x1_0_, elementtyp1_.ID as x2_0_, leafelemen0__1_.UNIQUE_NAME as x3_0_ from DICT_LEAF_ELEMENTS leafelemen0_ inner join DICT_ELEMENTS leafelemen0__1_ on leafelemen0_.ELEMENT_ID=leafelemen0__1_.ID, DICT_ELEMENT_TYPES elementtyp1_ where leafelemen0_.TYPE_ID=elementtyp1_.ID and (((leafelemen0_.TYPE_ID=? )AND(((leafelemen0_.String01 LIKE ? ESCAPE '\' )OR(leafelemen0_.String01 LIKE ? ESCAPE '\' )OR(leafelemen0_.String01 LIKE ? ESCAPE '\' )OR(leafelemen0_.String01 LIKE ? ESCAPE '\' ))AND(lower(leafelemen0_.String01)=? )AND(leafelemen0_.String01 is not null ))and(String01 is not null ))and(leafelemen0__1_.ACTIVE_TO>? )and(leafelemen0__1_.ACTIVE_FROM<=? ));

insert into HEART_BEAT_RECORD (timestamp) values (?);

insert into policy_activity_log (id, time, month_nb, day_nb, host_id, user_id, application_id, application_name, action, fromresourcename, fromresourcesize, fromresourceownerid, fromresourcecreateddate, fromresourcemodifieddate, toresourcename, policy_id, policy_decision, decision_request_id, host_name, host_ip, user_name, log_level) values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);

insert into RPA_LOG (id,time, request_date_time, month_nb, week_nb, day_nb, hour_nb, minute_nb ,host_id,host_ip,host_name,user_id,user_name,user_sid,application_id,application_name,action,policy_id,policy_name,policy_fullname,policy_decision,decision_request_id,log_level,from_resource_name,from_resource_prefix,from_resource_path,from_resource_short_name,from_resource_size,from_resource_owner_id,from_resource_created_date,from_resource_modified_date,to_resource_name, attr1, attr2, attr3, attr4, attr5, attr6, attr7, attr8, attr9, attr10, attr11, attr12, attr13, attr14, attr15, attr16, attr17, attr18, attr19, attr20, attr21, attr22, attr23, attr24, attr25, attr26, attr27, attr28, attr29, attr30, attr31, attr32, attr33, attr34, attr35, attr36, attr37, attr38, attr39, attr40, attr41, attr42, attr43, attr44, attr45, attr46, attr47, attr48, attr49, attr50, attr51, attr52, attr53, attr54, attr55, attr56, attr57, attr58, attr59, attr60, attr61, attr62, attr63, attr64, attr65, attr66, attr67, attr68, attr69, attr70, attr71, attr72, attr73, attr74, attr75, attr76, attr77, attr78, attr79, attr80, attr81, attr82, attr83, attr84, attr85, attr86, attr87, attr88, attr89, attr90, attr91, attr92, attr93, attr94, attr95, attr96, attr97, attr98, attr99) values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);

/* insert com.nextlabs.destiny.console.model.EntityAuditLog */ insert into ENTITY_AUDIT_LOG (ACTION, ACTOR, ACTOR_ID, ENTITY_ID, ENTITY_TYPE, NEW_VALUE, OLD_VALUE, TIMESTAMP) values (?, ?, ?, ?, ?, ?, ?, ?);

insert into DEPLOYMENT_REQUEST (executed, time, scheduleTime) values (?, ?, ?);

update DEPLOYMENT_REQUEST set executed=?, time=?, scheduleTime=? where id=?;

select this.id as id0_, this.executed as executed0_, this.time as time0_, this.scheduleTime as schedule4_0_ from DEPLOYMENT_REQUEST this where this.id=?;

select deployment0_.id as id0_, deployment0_.executed as executed0_, deployment0_.time as time0_, deployment0_.scheduleTime as schedule4_0_ from DEPLOYMENT_REQUEST deployment0_ where deployment0_.id=?;

select leafelemen0__1_.ORIGINAL_ID as x0_0_ from DICT_LEAF_ELEMENTS leafelemen0_ inner join DICT_ELEMENTS leafelemen0__1_ on leafelemen0_.ELEMENT_ID=leafelemen0__1_.ID where (((leafelemen0_.TYPE_ID=? )OR(leafelemen0_.TYPE_ID=? ))AND(((leafelemen0_.TYPE_ID=? )AND(((leafelemen0_.String09 LIKE ? ESCAPE '\' )OR(leafelemen0_.String09 LIKE ? ESCAPE '\' )OR(leafelemen0_.String09 LIKE ? ESCAPE '\' )OR(leafelemen0_.String09 LIKE ? ESCAPE '\' ))AND(lower(leafelemen0_.String09)=? )AND(leafelemen0_.String09 is not null ))and(String09 is not null ))AND((leafelemen0_.TYPE_ID=? )AND(((leafelemen0_.String07 LIKE ? ESCAPE '\' )OR(leafelemen0_.String07 LIKE ? ESCAPE '\' )OR(leafelemen0_.String07 LIKE ? ESCAPE '\' )OR(leafelemen0_.String07 LIKE ? ESCAPE '\' ))AND(lower(leafelemen0_.String07)=? )AND(leafelemen0_.String07 is not null ))and(String07 is not null ))AND((leafelemen0_.TYPE_ID=? )AND(((leafelemen0_.String08 LIKE ? ESCAPE '\' )OR(leafelemen0_.String08 LIKE ? ESCAPE '\' )OR(leafelemen0_.String08 LIKE ? ESCAPE '\' )OR(leafelemen0_.String08 LIKE ? ESCAPE '\' ))AND(lower(leafelemen0_.String08)=? )AND(leafelemen0_.String08 is not null ))and(String08 is not null ))))and(leafelemen0__1_.ACTIVE_TO>? )and(leafelemen0__1_.ACTIVE_FROM<=? ) order by leafelemen0__1_.ORIGINAL_ID asc;

insert into tracking_activity_log (id, time, month_nb, day_nb, host_id, user_id, application_id, application_name, action, fromresourcename, fromresourcesize, fromresourceownerid, fromresourcecreateddate, fromresourcemodifieddate, toresourcename, host_name, host_ip, user_name, log_level) values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);


select count(*) from RPA_LOG where time < ?;
select min(time) from REPORT_POLICY_ACTIVITY_LOG	;
SELECT from_resource_name AS Dimension, count(*) AS ResultCount FROM RPA_LOG RPA WHERE time >= ? AND time <= ? AND log_level >= ? AND policy_decision LIKE ? GROUP BY from_resource_name ORDER BY ResultCount desc 	;
SELECT policy_fullname AS Dimension, count(*) AS ResultCount FROM RPA_LOG RPA WHERE time >= ? AND time <= ? AND log_level >= ? AND policy_decision LIKE ? GROUP BY policy_fullname ORDER BY ResultCount desc 	;
SELECT user_name AS Dimension, count(*) AS ResultCount FROM RPA_LOG RPA WHERE time >= ? AND time <= ? AND log_level >= ? AND policy_decision LIKE ? GROUP BY user_name ORDER BY ResultCount desc 	;
SELECT c.first_name,c.last_name,c.display_name FROM CACHED_USER c WHERE c.original_id ! = ? AND c.active_from <= ? AND c.active_to > ?	;
SELECT attr39, attr38, attr37, attr36, attr35, attr34, attr33, attr32, attr31, attr30, TO_RESOURCE_NAME, LOG_LEVEL, APPLICATION_NAME, FROM_RESOURCE_PATH, attr49, attr48, attr47, attr46, attr45, attr44, attr43, attr42, attr41, attr40, FROM_RESOURCE_NAME, attr19, attr18, attr17, attr16, attr15, attr14, attr13, attr57, attr12, attr56, attr11, attr55, attr10, attr54, POLICY_NAME, attr53, attr52, attr51, attr50, HOST_NAME, HOST_IP, attr9, POLICY_FULLNAME, attr29, attr6, attr28, attr5, attr27, TIME, attr8, attr26, USER_NAME, attr7, attr25, attr2, attr24, attr1, attr23, attr4, attr22, attr3, attr21, attr20, ACTION, POLICY_DECISION FROM RPA_LOG WHERE id = ?	;
SELECT ID, TIME, MONTH_NB, DAY_NB, HOST_ID, HOST_IP, HOST_NAME, USER_ID, USER_NAME, APPLICATION_ID, APPLICATION_NAME, ACTION, POLICY_ID, POLICY_FULLNAME, POLICY_NAME, POLICY_DECISION, LOG_LEVEL, FROM_RESOURCE_NAME, FROM_RESOURCE_PREFIX, FROM_RESOURCE_PATH, FROM_RESOURCE_SHORT_NAME, TO_RESOURCE_NAME FROM RPA_LOG WHERE id= ? ;





SELECT c.first_name,c.last_name,c.display_name FROM CACHED_USER c WHERE c.original_id ! = ? AND c.active_from <= ? AND c.active_to > ?;

select elementtyp1_.ID as ID, elementtyp1_.VERSION as VERSION, elementtyp1_.name as name, leafelemen0_.String01 as x0_0_, leafelemen0__1_.ORIGINAL_ID as x1_0_, elementtyp1_.ID as x2_0_, leafelemen0__1_.UNIQUE_NAME as x3_0_ from DICT_LEAF_ELEMENTS leafelemen0_ inner join DICT_ELEMENTS leafelemen0__1_ on leafelemen0_.ELEMENT_ID=leafelemen0__1_.ID, DICT_ELEMENT_TYPES elementtyp1_ where leafelemen0_.TYPE_ID=elementtyp1_.ID and (((leafelemen0_.TYPE_ID=? )AND(((leafelemen0_.String01 LIKE ? ESCAPE '\' )OR(leafelemen0_.String01 LIKE ? ESCAPE '\' )OR(leafelemen0_.String01 LIKE ? ESCAPE '\' )OR(leafelemen0_.String01 LIKE ? ESCAPE '\' ))AND(lower(leafelemen0_.String01)=? )AND(leafelemen0_.String01 is not null ))and(String01 is not null ))and(leafelemen0__1_.ACTIVE_TO>? )and(leafelemen0__1_.ACTIVE_FROM<=? ));

select  this.id as id1_, this.default_profile as default_2_1_, this.created_date as created_3_1_, this.modified_date as modified4_1_, this.name as name1_, this.DABS_location as DABS_loc6_1_, this.agent_type as agent_type1_, this.heart_beat_freq_time as heart_be8_1_, this.heart_beat_freq_time_unit as heart_be9_1_, this.log_limit as log_limit1_, this.log_freq_time as log_fre11_1_, this.log_freq_time_unit as log_fre12_1_, this.default_port as default13_1_, this.push_enabled as push_en14_1_, this.password_hash as passwor15_1_, this.curr_act_journ_settings_name as curr_ac16_1_, this.cust_act_journ_settings_id as cust_ac17_1_, activityjo1_.id as id0_, activityjo1_.name as name0_, activityjo1_.customizable as customiz3_0_ from COMM_PROFILE this left outer join ACTIVITY_JOURNALING_SETTINGS activityjo1_ on this.cust_act_journ_settings_id=activityjo1_.id where (this.id=?) order by this.id asc;

insert into HEART_BEAT_RECORD (timestamp) values (?);

select elementtyp1_.ID as ID, elementtyp1_.VERSION as VERSION, elementtyp1_.name as name, leafelemen0_.String01 as x0_0_, leafelemen0__1_.ORIGINAL_ID as x1_0_, elementtyp1_.ID as x2_0_, leafelemen0__1_.UNIQUE_NAME as x3_0_ from DICT_LEAF_ELEMENTS leafelemen0_ inner join DICT_ELEMENTS leafelemen0__1_ on leafelemen0_.ELEMENT_ID=leafelemen0__1_.ID, DICT_ELEMENT_TYPES elementtyp1_ where leafelemen0_.TYPE_ID=elementtyp1_.ID and (((leafelemen0_.TYPE_ID=? )AND(((leafelemen0_.String01 LIKE ?  )OR(leafelemen0_.String01 LIKE ?  )OR(leafelemen0_.String01 LIKE ?  )OR(leafelemen0_.String01 LIKE ?  ))AND(lower(leafelemen0_.String01)=? )AND(leafelemen0_.String01 is not null ))and(String01 is not null ))and(leafelemen0__1_.ACTIVE_TO>? )and(leafelemen0__1_.ACTIVE_FROM<=? ));

select this.id as id1_, this.default_profile as default_2_1_, this.created_date as created_3_1_, this.modified_date as modified4_1_, this.name as name1_, this.DABS_location as DABS_loc6_1_, this.agent_type as agent_type1_, this.heart_beat_freq_time as heart_be8_1_, this.heart_beat_freq_time_unit as heart_be9_1_, this.log_limit as log_limit1_, this.log_freq_time as log_fre11_1_, this.log_freq_time_unit as log_fre12_1_, this.default_port as default13_1_, this.push_enabled as push_en14_1_, this.password_hash as passwor15_1_, this.curr_act_journ_settings_name as curr_ac16_1_, this.cust_act_journ_settings_id as cust_ac17_1_, activityjo1_.id as id0_, activityjo1_.name as name0_, activityjo1_.customizable as customiz3_0_ from COMM_PROFILE this left outer join ACTIVITY_JOURNALING_SETTINGS activityjo1_ on this.cust_act_journ_settings_id=activityjo1_.id where (this.id=?) order by this.id asc;

select elementtyp1_.ID as ID, elementtyp1_.VERSION as VERSION, elementtyp1_.name as name, leafelemen0_.String01 as x0_0_, leafelemen0__1_.ORIGINAL_ID as x1_0_, elementtyp1_.ID as x2_0_, leafelemen0__1_.UNIQUE_NAME as x3_0_ from DICT_LEAF_ELEMENTS leafelemen0_ inner join DICT_ELEMENTS leafelemen0__1_ on leafelemen0_.ELEMENT_ID=leafelemen0__1_.ID, DICT_ELEMENT_TYPES elementtyp1_ where leafelemen0_.TYPE_ID=elementtyp1_.ID and (((leafelemen0_.TYPE_ID=? )AND(((leafelemen0_.String01 LIKE ? )OR(leafelemen0_.String01 LIKE ? )OR(leafelemen0_.String01 LIKE ? )OR(leafelemen0_.String01 LIKE ? ))AND(lower(leafelemen0_.String01)=? )AND(leafelemen0_.String01 is not null ))and(String01 is not null ))and(leafelemen0__1_.ACTIVE_TO>? )and(leafelemen0__1_.ACTIVE_FROM<=? ));

select id,TIME_,host_id,host_ip,host_name,user_id,user_name,application_id,application_name,action,policy_id,policy_decision,decision_request_id,log_level,fromresourcename,fromresourcesize,fromresourceownerid,fromresourcecreateddate,fromresourcemodifieddate,toresourcename from POLICY_ACTIVITY_LOG where sync_done is null ORDER BY user_id ASC, TIME_ ASC;

/* dynamic native SQL query */ SELECT r.user_id user_id, r.user_name, count(r.user_id) total_count from RPA_LOG r WHERE r.policy_decision = ? AND r.day_nb >= ? AND r.day_nb <= ? GROUP BY r.user_id, r.user_name ORDER BY total_count desc;

/* dynamic native SQL query */ SELECT a1.from_resource_name, a1.allow_count, d1.deny_count, (a1.allow_count + d1.deny_count) total_count FROM ( (SELECT rp1.from_resource_name from_resource_name, ra1.allow_decision decision, ISNULL(ra1.allow_count, 0) allow_count FROM ( (SELECT ra.from_resource_name from_resource_name, ra.policy_decision allow_decision, count(ra.from_resource_name) allow_count from RPA_LOG ra WHERE policy_decision = 'A' AND day_nb >= ? AND day_nb <= ? GROUP BY ra.from_resource_name, ra.policy_decision) ra1 RIGHT JOIN (SELECT rp.from_resource_name from_resource_name, 'A' deny_decision from RPA_LOG rp WHERE day_nb >= ? AND day_nb <= ? GROUP BY rp.from_resource_name) rp1 ON (rp1.from_resource_name = ra1.from_resource_name))) a1 INNER JOIN (SELECT rp1.from_resource_name from_resource_name, rp1.deny_decision decision, ISNULL(rd1.deny_count, 0) deny_count FROM ( (SELECT rd.from_resource_name from_resource_name, rd.policy_decision deny_decision, count(rd.from_resource_name) deny_count from RPA_LOG rd WHERE policy_decision = 'D' AND day_nb >= ? AND day_nb <= ? GROUP BY rd.from_resource_name, rd.policy_decision) rd1 RIGHT JOIN (SELECT rp.from_resource_name from_resource_name, 'D' deny_decision from RPA_LOG rp WHERE day_nb >= ? AND day_nb <= ? GROUP BY rp.from_resource_name) rp1 ON (rp1.from_resource_name = rd1.from_resource_name))) d1 ON (a1.from_resource_name = d1.from_resource_name)) ORDER BY total_count DESC;

/* dynamic native SQL query */ SELECT policy_fullname, policy_name, policy_decision, COUNT(policy_fullname) total_count FROM RPA_LOG r WHERE day_nb >= ? AND day_nb <= ? GROUP BY policy_fullname, policy_name, policy_decision ORDER BY total_count DESC;

/* dynamic native SQL query */ SELECT l.fullname, l.deployer FROM (SELECT d.name fullname, d.submitter deployer, k.policy_fullname policy_fullname FROM DEVELOPMENT_ENTITIES d LEFT JOIN (SELECT r.policy_fullname policy_fullname FROM RPA_LOG r WHERE r.day_nb >= ? AND r.day_nb <= ? GROUP BY r.policy_fullname) k ON (k.policy_fullname = CONCAT('/', d.name)) WHERE d.type = 'PO' AND d.status = 'AP' AND d.hidden = 'N') l WHERE l.policy_fullname is null;

/* named HQL query auditLog.lastXRecords */ select auditlog0_.id as id1_4_, auditlog0_.created_date as created_2_4_, auditlog0_.last_updated_by as last_upd3_4_, auditlog0_.last_updated as last_upd4_4_, auditlog0_.created_by as created_5_4_, auditlog0_.version as version6_4_, auditlog0_.component as componen7_4_, auditlog0_.hidden as hidden8_4_, auditlog0_.msgCode as msgCode9_4_, auditlog0_.msgParams as msgPara10_4_ from AUDIT_LOGS auditlog0_ order by auditlog0_.created_date DESC;

insert into policy_activity_log (id, TIME_, month_nb, day_nb, host_id, user_id, application_id, application_name, action, fromresourcename, fromresourcesize, fromresourceownerid, fromresourcecreateddate, fromresourcemodifieddate, toresourcename, policy_id, policy_decision, decision_request_id, host_name, host_ip, user_name, log_level) values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?) ;

/* FROM com.nextlabs.destiny.console.model.SavedSearch */ select savedsearc0_.id as id1_21_, savedsearc0_.created_date as created_2_21_, savedsearc0_.last_updated_by as last_upd3_21_, savedsearc0_.last_updated as last_upd4_21_, savedsearc0_.created_by as created_5_21_, savedsearc0_.version as version6_21_, savedsearc0_.criteria_json as criteria7_21_, savedsearc0_.description as descript8_21_, savedsearc0_.lowercase_name as lowercas9_21_, savedsearc0_.name as name10_21_, savedsearc0_.shared_mode as shared_11_21_, savedsearc0_.status as status12_21_, savedsearc0_.type as type13_21_ from SAVED_SEARCH savedsearc0_;
/* FROM com.nextlabs.destiny.console.model.SuperApplicationUser */ select superappli0_.id as id1_22_, superappli0_.created_date as created_2_22_, superappli0_.displayName as displayN3_22_, superappli0_.email as email4_22_, superappli0_.failed_login_attempts as failed_l5_22_, superappli0_.first_name as first_na6_22_, superappli0_.hide_splash as hide_spl7_22_, superappli0_.initlogin_done as initlogi8_22_, superappli0_.last_name as last_nam9_22_, superappli0_.last_updated_by as last_up10_22_, superappli0_.last_updated as last_up11_22_, superappli0_.locked as locked12_22_, superappli0_.last_logged_time as last_lo13_22_, superappli0_.created_by as created14_22_, superappli0_.password as passwor15_22_, superappli0_.username as usernam16_22_ from SUPER_APPLICATION_USER superappli0_;
/* FROM com.nextlabs.destiny.console.model.TagLabel */ select taglabel0_.id as id1_23_, taglabel0_.created_date as created_2_23_, taglabel0_.last_updated_by as last_upd3_23_, taglabel0_.last_updated as last_upd4_23_, taglabel0_.created_by as created_5_23_, taglabel0_.version as version6_23_, taglabel0_.hidden as hidden7_23_, taglabel0_.tag_key as tag_key8_23_, taglabel0_.label as label9_23_, taglabel0_.status as status10_23_, taglabel0_.type as type11_23_ from TAG_LABELS taglabel0_;
/* FROM com.nextlabs.destiny.console.model.authorization.AccessControl */ select accesscont0_.id as id1_0_, accesscont0_.expression as expressi2_0_, accesscont0_.request_method as request_3_0_, accesscont0_.url_pattern as url_patt4_0_ from ACCESS_CONTROL accesscont0_;
/* dynamic native SQL query */ SELECT ID, USERNAME, FIRST_NAME, LAST_NAME, DOMAIN_ID, PRIMARY_GROUP_ID, LAST_LOGGED_TIME, HIDE_SPLASH, LAST_UPDATED, USER_TYPE, AUTH_HANDLER_ID    FROM APPLICATION_USER a WHERE a.status = ?;
/* named HQL query appUserProperties.findByUserId */ select appuserpro0_.id as id1_3_, appuserpro0_.created_date as created_2_3_, appuserpro0_.last_updated_by as last_upd3_3_, appuserpro0_.last_updated as last_upd4_3_, appuserpro0_.created_by as created_5_3_, appuserpro0_.version as version6_3_, appuserpro0_.data_type as data_typ7_3_, appuserpro0_.prop_key as prop_key8_3_, appuserpro0_.super_user_id as super_us9_3_, appuserpro0_.user_id as user_id10_3_, appuserpro0_.prop_value as prop_va11_3_ from APP_USER_PROPERTIES appuserpro0_ where appuserpro0_.user_id=? order by appuserpro0_.prop_key;
/* named HQL query policy.findActiveByType */ select policydeve0_.id as id1_9_, policydeve0_.appql as appql2_9_, policydeve0_.created as created3_9_, policydeve0_.description as descript4_9_, policydeve0_.extended_desc as extended5_9_, policydeve0_.has_dependencies as has_depe6_9_, policydeve0_.hidden as hidden7_9_, policydeve0_.is_sub_policy as is_sub_p8_9_, policydeve0_.last_modified as last_mod9_9_, policydeve0_.last_updated as last_up10_9_, policydeve0_.modifier as modifie11_9_, policydeve0_.owner as owner12_9_, policydeve0_.pql as pql13_9_, policydeve0_.status as status14_9_, policydeve0_.submitted_time as submitt15_9_, policydeve0_.submitter as submitt16_9_, policydeve0_.name as name17_9_, policydeve0_.type as type18_9_, policydeve0_.version as version19_9_ from DEVELOPMENT_ENTITIES policydeve0_ where policydeve0_.hidden=? and policydeve0_.status<>? and policydeve0_.type=?;
/* named HQL query tag.findByKey */ select taglabel0_.id as id1_23_, taglabel0_.created_date as created_2_23_, taglabel0_.last_updated_by as last_upd3_23_, taglabel0_.last_updated as last_upd4_23_, taglabel0_.created_by as created_5_23_, taglabel0_.version as version6_23_, taglabel0_.hidden as hidden7_23_, taglabel0_.tag_key as tag_key8_23_, taglabel0_.label as label9_23_, taglabel0_.status as status10_23_, taglabel0_.type as type11_23_ from TAG_LABELS taglabel0_ where lower(taglabel0_.tag_key)=? and taglabel0_.type=? order by taglabel0_.label;
/* select count(generatedAlias0) from OperatorConfig as generatedAlias0 where 1=1 */ select count(operatorco0_.id) as col_0_0_ from OPERATOR_CONFIG operatorco0_ where 1=1;
/* select generatedAlias0 from DelegateModel as generatedAlias0 where ( generatedAlias0.shortName=:param0 ) and ( generatedAlias0.status<>:param1 ) */ select delegatemo0_.id as id2_19_, delegatemo0_.created_date as created_3_19_, delegatemo0_.last_updated_by as last_upd4_19_, delegatemo0_.last_updated as last_upd5_19_, delegatemo0_.created_by as created_6_19_, delegatemo0_.version as version7_19_, delegatemo0_.description as descript8_19_, delegatemo0_.name as name9_19_, delegatemo0_.short_name as short_n10_19_, delegatemo0_.status as status11_19_, delegatemo0_.type as type12_19_ from POLICY_MODEL delegatemo0_ where delegatemo0_.discriminator='DELEGATION' and delegatemo0_.short_name=? and delegatemo0_.status<>?;
/* select generatedAlias0 from DelegateModel as generatedAlias0 where ( generatedAlias0.type=:param0 ) or ( generatedAlias0.type=:param1 ) */ select delegatemo0_.id as id2_19_, delegatemo0_.created_date as created_3_19_, delegatemo0_.last_updated_by as last_upd4_19_, delegatemo0_.last_updated as last_upd5_19_, delegatemo0_.created_by as created_6_19_, delegatemo0_.version as version7_19_, delegatemo0_.description as descript8_19_, delegatemo0_.name as name9_19_, delegatemo0_.short_name as short_n10_19_, delegatemo0_.status as status11_19_, delegatemo0_.type as type12_19_ from POLICY_MODEL delegatemo0_ where delegatemo0_.discriminator='DELEGATION' and (delegatemo0_.type=? or delegatemo0_.type=?);
/* select generatedAlias0 from PolicyDevelopmentEntity as generatedAlias0 where ( generatedAlias0.title=:param0 ) and ( generatedAlias0.status<>:param1 ) */ select policydeve0_.id as id1_9_, policydeve0_.appql as appql2_9_, policydeve0_.created as created3_9_, policydeve0_.description as descript4_9_, policydeve0_.extended_desc as extended5_9_, policydeve0_.has_dependencies as has_depe6_9_, policydeve0_.hidden as hidden7_9_, policydeve0_.is_sub_policy as is_sub_p8_9_, policydeve0_.last_modified as last_mod9_9_, policydeve0_.last_updated as last_up10_9_, policydeve0_.modifier as modifie11_9_, policydeve0_.owner as owner12_9_, policydeve0_.pql as pql13_9_, policydeve0_.status as status14_9_, policydeve0_.submitted_time as submitt15_9_, policydeve0_.submitter as submitt16_9_, policydeve0_.name as name17_9_, policydeve0_.type as type18_9_, policydeve0_.version as version19_9_ from DEVELOPMENT_ENTITIES policydeve0_ where policydeve0_.name=? and policydeve0_.status<>?;
/* select generatedAlias0 from PolicyModel as generatedAlias0 where ( generatedAlias0.type=:param0 ) or ( generatedAlias0.type=:param1 ) */ select policymode0_.id as id2_19_, policymode0_.created_date as created_3_19_, policymode0_.last_updated_by as last_upd4_19_, policymode0_.last_updated as last_upd5_19_, policymode0_.created_by as created_6_19_, policymode0_.version as version7_19_, policymode0_.description as descript8_19_, policymode0_.name as name9_19_, policymode0_.short_name as short_n10_19_, policymode0_.status as status11_19_, policymode0_.type as type12_19_, policymode0_.discriminator as discrimi1_19_ from POLICY_MODEL policymode0_ where policymode0_.type=? or policymode0_.type=?;
SELECT * FROM "connection_test_table_sa3662";
SELECT ID, TYPE, CONFIG_DATA_JSON FROM AUTH_HANDLER_REGISTRY;
select actions0_.plcy_model_id as plcy_mo11_19_0_, actions0_.id as id1_14_0_, actions0_.id as id1_14_1_, actions0_.created_date as created_2_14_1_, actions0_.last_updated_by as last_upd3_14_1_, actions0_.last_updated as last_upd4_14_1_, actions0_.created_by as created_5_14_1_, actions0_.version as version6_14_1_, actions0_.name as name7_14_1_, actions0_.short_code as short_co8_14_1_, actions0_.short_name as short_na9_14_1_, actions0_.sort_order as sort_or10_14_1_ from PM_ACTION_CONFIG actions0_ where actions0_.plcy_model_id=?;
select attributes0_.plcy_model_id as plcy_mo13_19_0_, attributes0_.id as id1_15_0_, attributes0_.id as id1_15_1_, attributes0_.created_date as created_2_15_1_, attributes0_.last_updated_by as last_upd3_15_1_, attributes0_.last_updated as last_upd4_15_1_, attributes0_.created_by as created_5_15_1_, attributes0_.version as version6_15_1_, attributes0_.data_type as data_typ7_15_1_, attributes0_.name as name8_15_1_, attributes0_.policy_model_id as policy_12_15_1_, attributes0_.reg_ex_pattern as reg_ex_p9_15_1_, attributes0_.short_name as short_n10_15_1_, attributes0_.sort_order as sort_or11_15_1_, policymode1_.id as id2_19_2_, policymode1_.created_date as created_3_19_2_, policymode1_.last_updated_by as last_upd4_19_2_, policymode1_.last_updated as last_upd5_19_2_, policymode1_.created_by as created_6_19_2_, policymode1_.version as version7_19_2_, policymode1_.description as descript8_19_2_, policymode1_.name as name9_19_2_, policymode1_.short_name as short_n10_19_2_, policymode1_.status as status11_19_2_, policymode1_.type as type12_19_2_, policymode1_.discriminator as discrimi1_19_2_ from PM_ATTRIBUTE_CONFIG attributes0_ left outer join POLICY_MODEL policymode1_ on attributes0_.policy_model_id=policymode1_.id where attributes0_.plcy_model_id=?;
select componentd0_.id as id, componentd0_.name as name, componentd0_.type as type, componentd0_.typeDisplayName as typeDisp4_, componentd0_.callbackURL as callback5_, componentd0_.componentURL as componen6_, componentd0_.lastHeartbeat as lastHear7_, componentd0_.heartbeatRate as heartbea8_, componentd0_.version as version from COMPONENT componentd0_ where (componentd0_.name=? );
select componentd0_.id as id, componentd0_.name as name, componentd0_.type as type, componentd0_.typeDisplayName as typeDisp4_, componentd0_.callbackURL as callback5_, componentd0_.componentURL as componen6_, componentd0_.lastHeartbeat as lastHear7_, componentd0_.heartbeatRate as heartbea8_, componentd0_.version as version from COMPONENT componentd0_ where (componentd0_.type=? )and(componentd0_.callbackURL=? );
select customappd0_.id as id, customappd0_.name as name, customappd0_.version as version, customappd0_.description as descript4_ from CUSTOM_APP customappd0_;
select customrepo0_.id as id, customrepo0_.app_ref_id as app_ref_id, customrepo0_.file_content as file_con3_ from REPORT_CUSTOM_APP_UI customrepo0_;
select customrepo0_.id as id, customrepo0_.app_ref_id as app_ref_id, customrepo0_.title as title, customrepo0_.description as descript4_ from REPORT_CUSTOM_APP customrepo0_;
select customrepo0_.id as id, customrepo0_.position as position, customrepo0_.custom_report_id as custom_r3_, customrepo0_.name as name, customrepo0_.content as content from REPORT_CUSTOM_APP_FILES customrepo0_;
select deployment0_.id as id, deployment0_.version as version, deployment0_.development_id as developm3_, deployment0_.dep_record_id as dep_reco4_, deployment0_.name as name, deployment0_.description as descript6_, deployment0_.pql as pql, deployment0_.processedpql as processe8_, deployment0_.override_cnt as override9_, deployment0_.active_from as active_10_, deployment0_.active_to as active_to, deployment0_.hidden as hidden, deployment0_.original_version as origina13_, deployment0_.last_modified as last_mo14_, deployment0_.modifier as modifier, deployment0_.submitted_time as submitt16_, deployment0_.submitter as submitter from deployment_entities deployment0_, deployment_records deployment1_, development_entities developmen2_ where deployment0_.development_id=developmen2_.id and ((deployment0_.override_cnt=0 )and(deployment0_.pql is not null )and(deployment0_.active_to>? )and(deployment0_.active_from<=? )and(deployment0_.active_from>? )and(deployment1_.deployment_type=?  and deployment0_.dep_record_id=deployment1_.id)and(developmen2_.type in(?) and deployment0_.development_id=developmen2_.id)) order by  developmen2_.id asc;
select deployment0_.id as id0_, deployment0_.action_type as action_t2_0_, deployment0_.deployment_type as deployme3_0_, deployment0_.as_of as as_of0_, deployment0_.when_requested as when_req5_0_, deployment0_.when_cancelled as when_can6_0_, deployment0_.hidden as hidden0_, deployment0_.deployer as deployer0_ from deployment_records deployment0_ where deployment0_.id=?;
select developmen0_.id as id0_, developmen0_.version as version0_, developmen0_.owner as owner0_, developmen0_.appql as appql0_, developmen0_.name as name0_, developmen0_.description as descript6_0_, developmen0_.pql as pql0_, developmen0_.status as status0_, developmen0_.type as type0_, developmen0_.last_updated as last_up10_0_, developmen0_.created as created0_, developmen0_.last_modified as last_mo12_0_, developmen0_.modifier as modifier0_, developmen0_.submitted_time as submitt14_0_, developmen0_.submitter as submitter0_, developmen0_.hidden as hidden0_, developmen0_.has_dependencies as has_dep17_0_, developmen0_.is_sub_policy as is_sub_18_0_ from development_entities developmen0_ where developmen0_.id=?;
select eventdo0_.id as id, eventdo0_.name as name from EVENT eventdo0_ where (eventdo0_.name=? );
select fields0_.PARENT_TYPE_ID as PARENT_T9___, fields0_.ID as ID__, fields0_.ID as ID0_, fields0_.VERSION as VERSION0_, fields0_.name as name0_, fields0_.name_upper as name_upper0_, fields0_.type as type0_, fields0_.label as label0_, fields0_.deleted as deleted0_, fields0_.mapping as mapping0_, fields0_.PARENT_TYPE_ID as PARENT_T9_0_ from DICT_TYPE_FIELDS fields0_ where fields0_.PARENT_TYPE_ID=?;
select heartbeatr0_.id as id, heartbeatr0_.timestamp as timestamp from HEART_BEAT_RECORD heartbeatr0_ where (timestamp<? );
select loggedacti0_.settings_id as settings1___, loggedacti0_.action as action__ from ACT_JOURN_SETTINGS_LOGGED_ACTS loggedacti0_ where loggedacti0_.settings_id=?;
select min(updatereco0_.end_time) as x0_0_ from DICT_UPDATES updatereco0_ where ((not exists(select updatereco1_.ID from DICT_UPDATES updatereco1_ where (updatereco1_.ACTIVE_FROM<=updatereco0_.ACTIVE_FROM )and(updatereco1_.ACTIVE_TO>updatereco0_.ACTIVE_FROM )and(updatereco1_.is_successful='N' ))))and(updatereco0_.is_successful='Y' )and(updatereco0_.ACTIVE_FROM>? );
select obligation0_.plcy_model_id as plcy_mo11_19_0_, obligation0_.id as id1_17_0_, obligation0_.id as id1_17_1_, obligation0_.created_date as created_2_17_1_, obligation0_.last_updated_by as last_upd3_17_1_, obligation0_.last_updated as last_upd4_17_1_, obligation0_.created_by as created_5_17_1_, obligation0_.version as version6_17_1_, obligation0_.name as name7_17_1_, obligation0_.run_at as run_at8_17_1_, obligation0_.short_name as short_na9_17_1_, obligation0_.sort_order as sort_or10_17_1_ from PM_OBLIGATION_CONFIG obligation0_ where obligation0_.plcy_model_id=?;
select operatorco0_.attribute_id as attribut1_15_0_, operatorco0_.operator_id as operator2_16_0_, operatorco1_.id as id1_12_1_, operatorco1_.created_date as created_2_12_1_, operatorco1_.last_updated_by as last_upd3_12_1_, operatorco1_.last_updated as last_upd4_12_1_, operatorco1_.created_by as created_5_12_1_, operatorco1_.version as version6_12_1_, operatorco1_.data_type as data_typ7_12_1_, operatorco1_.operator_key as operator8_12_1_, operatorco1_.label as label9_12_1_ from PM_ATTRIB_CONFIG_OPER_CONFIG operatorco0_ inner join OPERATOR_CONFIG operatorco1_ on operatorco0_.operator_id=operatorco1_.id where operatorco0_.attribute_id=?;
select parameters0_.obligation_id as obligat16_17_0_, parameters0_.id as id1_18_0_, parameters0_.id as id1_18_1_, parameters0_.created_date as created_2_18_1_, parameters0_.last_updated_by as last_upd3_18_1_, parameters0_.last_updated as last_upd4_18_1_, parameters0_.created_by as created_5_18_1_, parameters0_.version as version6_18_1_, parameters0_.default_value as default_7_18_1_, parameters0_.is_editable as is_edita8_18_1_, parameters0_.is_hidden as is_hidde9_18_1_, parameters0_.list_values as list_va10_18_1_, parameters0_.is_mandatory as is_mand11_18_1_, parameters0_.name as name12_18_1_, parameters0_.short_name as short_n13_18_1_, parameters0_.sort_order as sort_or14_18_1_, parameters0_.data_type as data_ty15_18_1_ from PM_PARAMETER_CONFIG parameters0_ where parameters0_.obligation_id=?;
select registrati0_.EVENT_ID as EVENT_ID__, registrati0_.id as id__, registrati0_.COMPONENT_ID as COMPONEN4___, registrati0_.id as id1_, registrati0_.lastModified as lastModi2_1_, registrati0_.isActive as isActive1_, registrati0_.COMPONENT_ID as COMPONEN4_1_, registrati0_.EVENT_ID as EVENT_ID1_, componentd1_.id as id0_, componentd1_.name as name0_, componentd1_.type as type0_, componentd1_.typeDisplayName as typeDisp4_0_, componentd1_.callbackURL as callback5_0_, componentd1_.componentURL as componen6_0_, componentd1_.lastHeartbeat as lastHear7_0_, componentd1_.heartbeatRate as heartbea8_0_, componentd1_.version as version0_ from EVENT_REGISTRATION registrati0_ left outer join COMPONENT componentd1_ on registrati0_.COMPONENT_ID=componentd1_.id where registrati0_.EVENT_ID=?;
select seeditems0_.SEED_COMM_PROFILE_ID as SEED_COM1___, seeditems0_.COMM_PROFILE_ID as COMM_PRO2___, seeditems0_.SEED_NAME as SEED_NAME__ from COMM_PROFILE_SEED_ITEMS seeditems0_ where seeditems0_.SEED_COMM_PROFILE_ID=?;
select tags0_.dev_entity_id as dev_enti1_9_0_, tags0_.tag_id as tag_id2_10_0_, taglabel1_.id as id1_23_1_, taglabel1_.created_date as created_2_23_1_, taglabel1_.last_updated_by as last_upd3_23_1_, taglabel1_.last_updated as last_upd4_23_1_, taglabel1_.created_by as created_5_23_1_, taglabel1_.version as version6_23_1_, taglabel1_.hidden as hidden7_23_1_, taglabel1_.tag_key as tag_key8_23_1_, taglabel1_.label as label9_23_1_, taglabel1_.status as status10_23_1_, taglabel1_.type as type11_23_1_ from DEVELOPMENT_ENTITIES_TAGS tags0_ inner join TAG_LABELS taglabel1_ on tags0_.tag_id=taglabel1_.id where tags0_.dev_entity_id=?;
select tags0_.plcy_model_id as plcy_mod1_19_0_, tags0_.tag_id as tag_id2_20_0_, taglabel1_.id as id1_23_1_, taglabel1_.created_date as created_2_23_1_, taglabel1_.last_updated_by as last_upd3_23_1_, taglabel1_.last_updated as last_upd4_23_1_, taglabel1_.created_by as created_5_23_1_, taglabel1_.version as version6_23_1_, taglabel1_.hidden as hidden7_23_1_, taglabel1_.tag_key as tag_key8_23_1_, taglabel1_.label as label9_23_1_, taglabel1_.status as status10_23_1_, taglabel1_.type as type11_23_1_ from POLICY_MODEL_TAGS tags0_ inner join TAG_LABELS taglabel1_ on tags0_.tag_id=taglabel1_.id where tags0_.plcy_model_id=?;
select this.ID as ID0_, this.VERSION as VERSION0_, this.domain_name as domain_n3_0_, this.enrollment_type as enrollme4_0_, this.isRecurring as isRecurr5_0_, this.isActive as isActive0_ from DICT_ENROLLMENTS this where this.isActive=?;
select this.ID as ID0_, this.VERSION as VERSION0_, this.name as name0_ from DICT_ELEMENT_TYPES this where this.name=?;
select this.id as id0_, this.lastUpdated as lastUpda2_0_, this.type as type0_ from RESOURCE_CACHE_STATE this where this.type=?;
select this.id as id0_, this.last_updated as last_upd2_0_ from COMM_PROFILE_SEED this where 1=1;
select this.id as id0_, this.name as name0_, this.customizable as customiz3_0_ from ACTIVITY_JOURNALING_SETTINGS this where this.name=?;
select this.id as id0_, this.name as name0_, this.description as descript3_0_, this.criteria_json as criteria4_0_, this.alert_message as alert_me5_0_, this.email_address as email_ad6_0_, this.auto_dismiss as auto_dis7_0_, this.email_admin as email_ad8_0_, this.is_active as is_active0_, this.created_datetime as created10_0_, this.updated_datetime as updated11_0_, this.is_deleted as is_deleted0_, this.uuid as uuid0_, this.is_archived as is_arch14_0_, this.shared_mode as shared_15_0_, this.owner_id as owner_id0_, this.pql_data as pql_data0_ from MONITOR this where (this.is_active=? and (this.is_deleted=? and this.is_archived=?));
select this.id as id2_, this.lastModified as lastModi2_2_, this.isActive as isActive2_, this.COMPONENT_ID as COMPONEN4_2_, this.EVENT_ID as EVENT_ID2_, componentd1_.id as id0_, componentd1_.name as name0_, componentd1_.type as type0_, componentd1_.typeDisplayName as typeDisp4_0_, componentd1_.callbackURL as callback5_0_, componentd1_.componentURL as componen6_0_, componentd1_.lastHeartbeat as lastHear7_0_, componentd1_.heartbeatRate as heartbea8_0_, componentd1_.version as version0_, eventdo2_.id as id1_, eventdo2_.name as name1_ from EVENT_REGISTRATION this left outer join COMPONENT componentd1_ on this.COMPONENT_ID=componentd1_.id left outer join EVENT eventdo2_ on this.EVENT_ID=eventdo2_.id where this.lastModified>=? and not this.COMPONENT_ID=?;
--select top 1 this.id as id1_, this.default_profile as default_2_1_, this.created_date as created_3_1_, this.modified_date as modified4_1_, this.name as name1_, this.DABS_location as DABS_loc6_1_, this.agent_type as agent_type1_, this.heart_beat_freq_time as heart_be8_1_, this.heart_beat_freq_time_unit as heart_be9_1_, this.log_limit as log_limit1_, this.log_freq_time as log_fre11_1_, this.log_freq_time_unit as log_fre12_1_, this.default_port as default13_1_, this.push_enabled as push_en14_1_, this.password_hash as passwor15_1_, this.curr_act_journ_settings_name as curr_ac16_1_, this.cust_act_journ_settings_id as cust_ac17_1_, activityjo1_.id as id0_, activityjo1_.name as name0_, activityjo1_.customizable as customiz3_0_ from COMM_PROFILE this left outer join ACTIVITY_JOURNALING_SETTINGS activityjo1_ on this.cust_act_journ_settings_id=activityjo1_.id where (this.id=?) order by this.id asc;
--select top 30 this.id as id0_, this.creationTime as creation2_0_, this.dataObjectName as dataObje3_0_, this.resultObjectName as resultOb4_0_, this.availableRowCount as availabl5_0_, this.minValue as minValue0_, this.maxValue as maxValue0_, this.sumValue as sumValue0_, this.totalRowCount as totalRow9_0_ from STORED_QUERY this where this.creationTime<?;
update COMPONENT set name=?, type=?, typeDisplayName=?, callbackURL=?, componentURL=?, lastHeartbeat=?, heartbeatRate=?, version=? where id=?;
update EVENT_REGISTRATION set lastModified=?, isActive=?, COMPONENT_ID=?, EVENT_ID=? where id=?;
update RESOURCE_CACHE_STATE set lastUpdated=?, type=? where id=?;
















