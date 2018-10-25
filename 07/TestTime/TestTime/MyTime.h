#pragma once
class CMyTime
{

public:
	CMyTime();
	CMyTime(time_t time);

	CMyTime(
		int nYear,
		int nMonth,
		int nDay,
		int nHour,
		int nMin,
		int nSec,
		int nDST = -1);

	time_t GetTime() const;

	static CMyTime GetCurrentTime();
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	int GetHour() const;
	int GetMinute() const;
	int GetSecond() const;
	int GetDayOfWeek() const;
	
	bool operator==( CMyTime time) const
	{
		return this->m_time == time.m_time;
	}
	bool operator!=(CMyTime time) const
	{
		return this->m_time != time.m_time;
	}
	bool operator<(CMyTime time) const
	{
		return this->m_time < time.m_time;
	}
	bool operator>(CMyTime time) const
	{
		return this->m_time > time.m_time;
	}
	bool operator<=(CMyTime time) const
	{
		return this->m_time <= time.m_time;
	}
	bool operator>=(CMyTime time) const
	{
		return this->m_time >= time.m_time;
	}
	
	
	
	
	
	~CMyTime();
private:
	time_t m_time;


};

