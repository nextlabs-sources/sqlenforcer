#pragma once
#include "Task.h"
#include <iostream> 
#include <vector>
enum RET_TYPE { RNUL, RSTR, RINT,RDBL };
class Act_record;
class Act_record_I;
class Act_record_S;

typedef std::vector<std::string> StringVec;
typedef std::vector<Act_record*> Act_recordVec;
typedef std::vector<Act_recordVec*> Act_recordVec_Vec;

class CEMDBResultSet :public IResultSet
{
public:
	CEMDBResultSet();
	~CEMDBResultSet();

	virtual bool compare_with(IResultSet *other);
	virtual const char* json_serialize();

	void Push_Header(std::string str);
	void Push_Record(Act_recordVec * vec);
	void Push_Ret(int ivalue);

	bool IsEqual(CEMDBResultSet*pCom, std::string & strErr)const;
private:
	bool m_bReturn;//executed return value
	StringVec m_vecHearder;
	Act_recordVec_Vec m_vecRecord;

	std::string m_serialize;
};


class Act_record
{
public:
	virtual ~Act_record(){};

	virtual RET_TYPE GetType() const = 0;
	virtual bool IsEqual(Act_record*pClass) const = 0;

};


class Act_record_I :public Act_record
{
public:
	Act_record_I(int v);	
	~Act_record_I();

	virtual RET_TYPE GetType() const;
	virtual bool IsEqual(Act_record*pClass) const;
	int GetValue() { return value; };
private:
	RET_TYPE type;
	int value;
};



class Act_record_S :public Act_record
{
public:
	Act_record_S(std::string v);
	~Act_record_S();

	virtual RET_TYPE GetType() const;
	virtual bool IsEqual(Act_record*pClass) const;
	std::string GetValue() { return value; };
private:
	RET_TYPE type;
	std::string value;
};


class Act_record_D :public Act_record
{
public:
	Act_record_D(double v);
	~Act_record_D();

	virtual RET_TYPE GetType() const;
	virtual bool IsEqual(Act_record*pClass) const;
	double GetValue() { return value; };
private:
	RET_TYPE type;
	double value;
};

class Act_record_Null :public Act_record {
public:
	Act_record_Null();

	virtual RET_TYPE GetType() const { return type; };
	virtual bool IsEqual(Act_record*pClass) const ;
	//double GetValue() { return value; };
private:
	RET_TYPE type;
};