package emdb;

import java.util.ArrayList;
import java.util.List;


class Record{
    Record(){
        type = -1;
    }
    int type;
}
class RecordI extends Record{
    RecordI(int value){
        this.value = value;
        type = 1;
    }
    Integer value;
}
class RecordS extends Record{
    RecordS(String value){
        this.value = value;

        type = 2;
    }
    String value;
}
class RecordD extends Record{
    RecordD(double value){
        this.value = value;
        type = 3;
    }
    Double value;
}


class RecordNull extends  Record{
    RecordNull(){
        type = 4;
    }
}

public class EMDBResultSet {
    EMDBResultSet(){
        m_bReturn = false;
        m_vecHearder = new ArrayList<>();
        m_vecRecords = new ArrayList<>();
    }

    static int strcmp(String l, String r) {
        int len1 = l.length(), len2 = r.length(), i = 0;
        for(i = 0; i < len1 && i < len2 && l.charAt(i) != 0 && r.charAt(i) != 0; ++i) {
            if(l.charAt(i) != r.charAt(i))
                return l.charAt(i) - r.charAt(i);
        }
        if(i < len1 && l.charAt(i) == 0)
            len1 = i;
        if (i < len2 && r.charAt(i) ==0)
            len2 = i;
        return len1 - len2;
    }

    boolean CompareWith(EMDBResultSet other){
        if (this.m_bReturn != other.m_bReturn) {
            return  false;
        }

        if (this.m_vecHearder.size() != other.m_vecHearder.size()) {
            return  false;
        }
        for (int i = 0 ; i < this.m_vecHearder.size();++i){
            if (this.m_vecHearder.get(i).compareTo(other.m_vecHearder.get(i)) != 0) {
            	return  false;
            }
        }
        if (this.m_vecRecords.size() != other.m_vecRecords.size()) {
        	return  false;
        }
            
        for (int i = 0 ; i < this.m_vecRecords.size();++i){
            List<Record> list1 = this.m_vecRecords.get(i);
            List<Record> list2 = other.m_vecRecords.get(i);
            if (list1.size() != list2.size()) {
                return  false;
            }

            for (int j = 0 ; j < list1.size();++j){
                if (list1.get(j).type != list2.get(j).type) {
                    return  false;
                }
                    

                if (list1.get(j).type == 1){
                    if (((RecordI) list1.get(j)).value.compareTo (((RecordI) list2.get(j)).value)!= 0) {
                        return  false;
                    }

                }
                else if (list1.get(j).type == 2){
                    String s1 = ((RecordS) list1.get(j)).value;
                    String s2 = ((RecordS) list2.get(j)).value;
                    if (strcmp(s1, s2) != 0) {
                        return  false;
                    }


                }
                else if (list1.get(j).type == 3){
                    double d = ((RecordD) list1.get(j)).value - ((RecordD) list2.get(j)).value;
                    if (d > 0.00001 || d < -0.00001) {
                        return  false;
                    }

                }else{
                    // TODO: What?
                }
            }

        }
        return true;
    }

    /**
     * Joy
     * @param emdbrs
     * @return
     */
    public static List<Object> resultList(EMDBResultSet emdbrs){
    	List<Object> list = new ArrayList();
    	
    	if(emdbrs != null) {
    		
        	
    		list.add(emdbrs.m_bReturn);
    		
    		list.add(emdbrs.m_vecHearder);
    		
    		List<List<Object>> columnValue = new ArrayList(); 
    		
    		for(int i = 0; i < emdbrs.m_vecRecords.size(); i++) {
    			List<Object> obj = new ArrayList();
    			List<Record> recordList = emdbrs.m_vecRecords.get(i);
    			for(int j = 0; j < recordList.size(); j++) {
    				
    				int iType = recordList.get(j).type;

    				switch(iType)
                    {
                        case 1: 
                        {
                        	obj.add(((RecordI) recordList.get(j)).value);
                            break;
                        }
                        case 3: 
                        {
                        	obj.add(((RecordD) recordList.get(j)).value);
                            break;
                        }
                     
                        case 4:{
                        	obj.add(null);
                            break;
                        }
                        
                        default: {
                        	obj.add(((RecordS) recordList.get(j)).value);
                        }
    					
    				}
    				
    			}
    			columnValue.add(obj);
    		}
    		list.add(columnValue);
    	}
    	return list;
    }
    
    void Push_Header(String col){
        m_vecHearder.add(col);
    }
    void Push_Record(List<Record>  vec){
        m_vecRecords.add(vec);
    }
    void Push_Ret(boolean bvalue){
        m_bReturn = bvalue;
    }

    private boolean m_bReturn;//executed return value
    private List<String> m_vecHearder;
    private List<List<Record>> m_vecRecords;
}
