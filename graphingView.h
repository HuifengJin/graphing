
// graphingView.h : CgraphingView ��Ľӿ�
//

#pragma once

#include "graphingDoc.h"

class CgraphingView : public CView
{
protected: // �������л�����
	CgraphingView();
	DECLARE_DYNCREATE(CgraphingView);

// ����
public:
	CgraphingDoc* GetDocument() const;

// ����
public:
	int graphtype;
	void bar_graph(CDC* pDC);
	void line_graph(CDC* pDC);
	void pie_graph(CDC* pDC);
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CgraphingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNew();
	afx_msg void OnExit();
	afx_msg void OnBargraph();
	afx_msg void OnLinegraph();
	afx_msg void OnPiegraph();
	afx_msg void OnBargraphindialog();
};

#ifndef _DEBUG  // graphingView.cpp �еĵ��԰汾
inline CgraphingDoc* CgraphingView::GetDocument() const
   { return reinterpret_cast<CgraphingDoc*>(m_pDocument); }
#endif

