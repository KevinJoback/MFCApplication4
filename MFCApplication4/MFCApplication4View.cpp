
// MFCApplication4View.cpp : implementation of the CMFCApplication4View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4View

IMPLEMENT_DYNCREATE(CMFCApplication4View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication4View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMFCApplication4View construction/destruction

CMFCApplication4View::CMFCApplication4View() noexcept
{
	// TODO: add construction code here

}

CMFCApplication4View::~CMFCApplication4View()
{
	for( int i = 0; i < m_ChildWnds.GetSize(); i++ )
	{
		ASSERT_KINDOF(CWnd, m_ChildWnds.GetAt(i));
		CWnd* pWnd = (CWnd*)m_ChildWnds.GetAt(i);
		delete pWnd;
	}
}

BOOL CMFCApplication4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View drawing

void CMFCApplication4View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCApplication4View printing

BOOL CMFCApplication4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCApplication4View diagnostics

#ifdef _DEBUG
void CMFCApplication4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication4Doc* CMFCApplication4View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication4Doc)));
	return (CMFCApplication4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication4View message handlers

#include "ChildWnd.h"

int CMFCApplication4View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CString wndClass = theApp.m_WndClassName;
	DWORD style = WS_CHILD | WS_VISIBLE;
	long height = 50;
	long width = 50;
	for( int i = 0; i < 10; i++ )
	{
		for( int j = 0; j < 20; j++ )
		{
			long left = j * width;
			long top = i * height;
			long right = left + width;
			long bottom = top + height;
			CRect rect(left, top, right, bottom);
			CChildWnd* pWnd = new CChildWnd();
			pWnd->Create(wndClass, _T("child"),
				style, rect, this, i*10+j);
			m_ChildWnds.Add(pWnd);
		}

	}

	return 0;
}
