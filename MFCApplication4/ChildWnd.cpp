// ChildWnd.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication4.h"
#include "ChildWnd.h"


// CChildWnd

IMPLEMENT_DYNAMIC(CChildWnd, CWnd)

CChildWnd::CChildWnd()
{

}

CChildWnd::~CChildWnd()
{
}


BEGIN_MESSAGE_MAP(CChildWnd, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildWnd message handlers




void CChildWnd::OnPaint()
{
	CPaintDC dc(this);
	CRect	rect;
	CPen pen(PS_SOLID, 2, RGB(100, 100, 100));
	GetClientRect(&rect);
	dc.MoveTo(0, 0);
	dc.LineTo(rect.right, rect.bottom);
	dc.MoveTo(rect.right, 0);
	dc.LineTo(rect.left, rect.bottom);
}


BOOL CChildWnd::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
}
