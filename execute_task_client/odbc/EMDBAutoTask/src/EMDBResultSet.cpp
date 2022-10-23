#include "../include/Utility.h"
#include "../include/EMDBResultSet.h"

#include <json/json.h>

CEMDBResultSet::CEMDBResultSet():m_bReturn(false)
{
}


CEMDBResultSet::~CEMDBResultSet()
{
	for (auto cvec: m_vecRecord)
	{
		if (cvec)
		{
			for (auto c : (*cvec))
			{
				if (c)
				{
					delete c;
				}
			}
			cvec->clear();
			delete cvec;
		}
	}
	m_vecRecord.clear();
}

bool CEMDBResultSet::compare_with(IResultSet *other)
{
	std::string strErr;
	return IsEqual((CEMDBResultSet*)other, strErr);
}

const char* CEMDBResultSet::json_serialize()
{
	Json::Value jsValue;
	jsValue["RETURN"] = m_bReturn ? 1 : 0;
	for (int i = 0; i < m_vecHearder.size(); ++i)
	{
		jsValue["RESULT_SET"]["PROPERTIES"].append(m_vecHearder[i]);
	}

	for (int i = 0; i < m_vecRecord.size(); ++i)
	{
		Act_recordVec * pVec = m_vecRecord[i];
		Json::Value  jsSub;
		for (int j = 0; j < pVec->size(); ++j)
		{
			Act_record * pRet = (*pVec)[j];
			if (pRet->GetType() == RET_TYPE::RINT)
			{
				jsSub.append(((Act_record_I*)pRet)->GetValue());
			}
			else if (pRet->GetType() == RET_TYPE::RDBL)
			{
				jsSub.append(((Act_record_D*)pRet)->GetValue());
			}
			else if (pRet->GetType() == RET_TYPE::RSTR)
			{
				jsSub.append(((Act_record_S*)pRet)->GetValue());
			}
			else if(pRet->GetType() == RET_TYPE::RNUL)
			{
				Json::Value  value;
				jsSub.append(value);
			}
		}
		jsValue["RESULT_SET"]["records"].append(jsSub);

	}
	m_serialize = jsValue.toStyledString();
 
	return m_serialize.c_str();
}

void CEMDBResultSet::Push_Header(std::string str)
{
	m_vecHearder.push_back(str);
}



void CEMDBResultSet::Push_Record(Act_recordVec * vec)
{
	m_vecRecord.push_back(vec);
}

void CEMDBResultSet::Push_Ret(int ivalue)
{
	if (ivalue == 0)
	{
		m_bReturn = false;
	}
	else {
		m_bReturn = true;
	}
}

bool CEMDBResultSet::IsEqual(CEMDBResultSet*pCom, std::string & strErr) const
{
	if (m_bReturn != pCom->m_bReturn)
	{
		strErr = "sql executed failed";
		return false;
	}
	if (m_vecHearder.size() != pCom->m_vecHearder.size() )
	{
		strErr = "PROPERTIES number is not same";
		return false;
	}

	for (int i = 0 ; i < m_vecHearder.size();++i)
	{
		if (Utility::compare_str(m_vecHearder[i], pCom->m_vecHearder[i]) != 0)
		{
			strErr = "PROPERTIES value is not same";
			
			return false;
		}
	}

	if (m_vecRecord.size() != pCom->m_vecRecord.size()) {
		strErr = "RECORD row size is not same";
		return false;
	}
	for (int i = 0; i < m_vecRecord.size(); ++i)
	{
		if (m_vecRecord[i]->size() != pCom->m_vecRecord[i]->size())
		{
			strErr = "RECORD column size is not same";
			return false;
		}
		for (int j = 0 ; j < m_vecRecord[i]->size();++j)
		{
			if (!(*m_vecRecord[i])[j]->IsEqual((*pCom->m_vecRecord[i])[j])) 
			{
				strErr = "RECORD value is not same";
				return false;
			}
		}
		
	}
	return true;
}






//-------------------------------------------------------------------------------

Act_record_I::Act_record_I(int v):value(v),type(RET_TYPE::RINT)
{
	
}

Act_record_I::~Act_record_I()
{

}



RET_TYPE Act_record_I::GetType( ) const
{
	return type;
}

bool Act_record_I::IsEqual(Act_record*pClass) const
{
	if (RET_TYPE::RINT == pClass->GetType()&&
		value == ((Act_record_I*)pClass)->value)
	{
		return true;
	}
	return false;
}

//----------------------------------------------------------------------------
Act_record_S::Act_record_S(std::string v):value(v),type(RET_TYPE::RSTR)
{
	
}

Act_record_S::~Act_record_S()
{

}



RET_TYPE Act_record_S::GetType() const
{
	return type;
}

bool Act_record_S::IsEqual(Act_record*pClass) const
{
	if (RET_TYPE::RSTR == pClass->GetType() &&
		value.compare(((Act_record_S*)pClass)->value)==0)
	{
		return true;
	}
	return false;
}




Act_record_D::Act_record_D(double v):value(v),type(RET_TYPE::RDBL)
{
	
	
}

Act_record_D::~Act_record_D()
{

}


RET_TYPE Act_record_D::GetType() const
{
	return type;
}

bool Act_record_D::IsEqual(Act_record*pClass) const
{
    if (RET_TYPE::RSTR == pClass->GetType())
    {
        double r_value = std::stod(((Act_record_S*)pClass)->GetValue());
        double diff = value - r_value;
        if (diff > -0.001 &&
            diff <  0.001)
        {
            return true;
        }
    }
    else if (RET_TYPE::RDBL == pClass->GetType())
	{
		double d = value - ((Act_record_D*)pClass)->value;
		if (d > -0.00001 &&
			d <  0.00001)
		{
			return true;
		}
	}
	return false;
}

Act_record_Null::Act_record_Null():type(RNUL)
{

}

bool Act_record_Null::IsEqual(Act_record*pClass) const
{
	return type == pClass->GetType();
}
