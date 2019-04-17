
// graphingView.h : CgraphingView 类的接口
//

#pragma once

#include "graphingDoc.h"

class CgraphingView : public CView
{
protected: // 仅从序列化创建
	CgraphingView();
	DECLARE_DYNCREATE(CgraphingView);

// 特性
public:
	CgraphingDoc* GetDocument() const;

// 操作
public:
	int graphtype;
	void bar_graph(CDC* pDC);
	void line_graph(CDC* pDC);
	void pie_graph(CDC* pDC);
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CgraphingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // graphingView.cpp 中的调试版本
inline CgraphingDoc* CgraphingView::GetDocument() const
   { return reinterpret_cast<CgraphingDoc*>(m_pDocument); }
#endif

