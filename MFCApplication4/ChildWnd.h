#pragma once


// CChildWnd

class CChildWnd : public CWnd
{
	DECLARE_DYNAMIC(CChildWnd)

public:
	CChildWnd();
	virtual ~CChildWnd();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


