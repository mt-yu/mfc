#pragma once
class CRectlx :
	public RECT
{


public:
	operator RECT* ()
	{
		return this;
	}
//构造函数
	CRectlx();
	CRectlx(int l, int t, int r, int b);
	CRectlx(const RECT& srCRectlx);
	CRectlx(LPCRECT lpSrcRect);
	CRectlx(POINT point, SIZE size);
	CRectlx(POINT topLeft, POINT bottomRight);
//析构函数
	~CRectlx();

	int Width() const;	//后面加const 相当于声明该函数为只读函数，相当于c#中的访问器 get;
	int Height() const;
	CSize Size() const;

	CPoint& TopLeft();
	CPoint& BottomRight();

	const CPoint& TopLeft() const;
	const CPoint& BottomRight() const;

	CPoint CenterPoint() const;


	BOOL IsRectEmpty() const;
	BOOL IsRectNull() const;
	BOOL PtInRect(POINT point) const;
	
	void SetRect(int, int, int, int);
	void SetRect(POINT, POINT);

	

	void InflateRect(int, int);
	void DeflateRect(int, int);
	void OffsetRect(int, int);
	void NormalizeRect();

	void operator=(const RECT& srcRect);
	BOOL operator==(const RECT& rect) const;
	BOOL operator!=(const RECT& rect) const;


};

