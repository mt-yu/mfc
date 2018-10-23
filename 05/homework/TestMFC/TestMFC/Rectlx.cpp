#include "stdafx.h"
#include "Rectlx.h"


CRectlx::CRectlx()
{
}

CRectlx::CRectlx(int l, int t, int r, int b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}
CRectlx::CRectlx(const RECT& srCRectlx)
{
	
	memcpy(this, &srCRectlx, sizeof(RECT));
	// *this = srCRectlx;
}

CRectlx::CRectlx(LPCRECT lpSrcRect)
{
	memcpy(this, lpSrcRect, sizeof(RECT));
	//	*this = lpSrcRect;
}

CRectlx::CRectlx(POINT point, SIZE size)
{
	left = point.x;
	top = point.y;
	right = point.x + size.cx;
	bottom = point.y + size.cy;
}

CRectlx::CRectlx(POINT topLeft, POINT bottomRight)
{
	left = topLeft.x;
	top = topLeft.y;
	right = bottomRight.x;
	bottom = bottomRight.y;
}

int CRectlx::Width() const
{
	return right - left;
}

int CRectlx::Height() const
{
	return bottom - top;
}

CSize CRectlx::Size() const
{
	return CSize(right - left, bottom - top);
}

CPoint& CRectlx::TopLeft()
{
	return *((CPoint*)this);
}
CPoint& CRectlx::BottomRight()
{
	return *((CPoint*)this + 1);
}

CPoint CRectlx::CenterPoint() const
{
	return CPoint((left + right) / 2, (top + bottom) / 2);
}

const CPoint& CRectlx::TopLeft() const
{
	return *((CPoint*)this);
}
const CPoint& CRectlx::BottomRight() const
{
	return *((CPoint*)this + 1);
}

BOOL CRectlx::IsRectEmpty() const
{
	return !Width() || !Height();
}

BOOL CRectlx::IsRectNull() const
{
	return bottom == top == left == right == 0;
}

BOOL CRectlx::PtInRect(POINT point) const
{
	return point.x > left && point.x < right && point.y > top && point.y < bottom;
}

void CRectlx::SetRect(int x1, int y1, int x2, int y2)
{
	left = x1;
	top = y1;
	right = x2;
	bottom = y2;
}

void CRectlx::SetRect(POINT TopLeft, POINT BottomRight)
{
	left = TopLeft.x;
	top = TopLeft.y;
	right = BottomRight.x;
	bottom = BottomRight.y;
}

void CRectlx::InflateRect(int x, int y)
{
	left -= x;
	top -= y;
	right += x;
	bottom += y;
}

void CRectlx::DeflateRect(int x, int y)
{
	left += x; 
	top += y;
	right -= x;
	bottom -= y;
}

void CRectlx::OffsetRect(int x, int y)
{
	left += x;
	right += x;
	bottom += y;
	top += y;
}

void CRectlx::NormalizeRect()
{
	int nTemp;
	if (left > right)
	{
		nTemp = left;
		left = right;
		right = nTemp;
	}
	if (top > bottom)
	{
		nTemp = top;
		top = bottom;
		bottom = nTemp;
	}
}

void CRectlx::operator=(const RECT& src)
{
	memcpy(this, &src, sizeof(RECT));
}

BOOL CRectlx::operator==(const RECT& rect) const
{
	return !memcmp(this, &rect, sizeof(RECT));
}


BOOL CRectlx::operator!=(const RECT& rect) const
{
	return memcmp(this, &rect, sizeof(RECT)) != 0;
}











CRectlx::~CRectlx()
{
}
