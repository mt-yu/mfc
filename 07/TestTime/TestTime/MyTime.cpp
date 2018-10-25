#include "stdafx.h"
#include "MyTime.h"


CMyTime::CMyTime()
{
	m_time = 0;
}

CMyTime::CMyTime(time_t time)
{
	m_time = time;
}

CMyTime::CMyTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec, int nDST)
{
	tm tms = { nSec, nMin, nHour, nDay, nMonth - 1, nYear - 1900 };
	m_time = mktime(&tms);
}

time_t CMyTime::GetTime() const
{
	return m_time;
}

CMyTime CMyTime::GetCurrentTime()
{
	
	return time(NULL);
}

int CMyTime::GetYear() const
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_year + 1900;
}

int CMyTime::GetMonth() const
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_mon + 1;
}

int CMyTime::GetDay() const
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_mday;
}

int CMyTime::GetHour() const
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_hour;
}

int CMyTime::GetMinute() const
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_min;
}

int CMyTime::GetSecond() const
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_sec;
}

int CMyTime::GetDayOfWeek() const
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_wday + 1;
}



CMyTime::~CMyTime()
{
}
