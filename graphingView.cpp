
// graphingView.cpp : CgraphingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "graphing.h"
#endif

#include "graphingDoc.h"
#include "graphingView.h"
#include <cstring>
#include "Cgraphdia.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CgraphingView

IMPLEMENT_DYNCREATE(CgraphingView, CView)

BEGIN_MESSAGE_MAP(CgraphingView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CgraphingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_NEW, &CgraphingView::OnNew)
	ON_COMMAND(ID_EXIT, &CgraphingView::OnExit)
	ON_COMMAND(ID_BARGRAPH, &CgraphingView::OnBargraph)
	ON_COMMAND(ID_LINEGRAPH, &CgraphingView::OnLinegraph)
	ON_COMMAND(ID_PIEGRAPH, &CgraphingView::OnPiegraph)
	ON_COMMAND(ID_BARGRAPHINDIALOG, &CgraphingView::OnBargraphindialog)
END_MESSAGE_MAP()

// CgraphingView 构造/析构

CgraphingView::CgraphingView()
{
	// TODO: 在此处添加构造代码

	graphtype = 0;
}

CgraphingView::~CgraphingView()
{
}

BOOL CgraphingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CgraphingView 绘制

void CgraphingView::OnDraw(CDC* pDC)
{
	CgraphingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码


	switch(graphtype)
	{
		case 1:
			bar_graph(pDC);
			break;
		case 2:
			line_graph(pDC);
			break;
		case 3:
			pie_graph(pDC);
			break;
		case 4:
			Invalidate();
			break;
		default:
			break;
	}
}


// CgraphingView 打印


void CgraphingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CgraphingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CgraphingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CgraphingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CgraphingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CgraphingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CgraphingView 诊断

#ifdef _DEBUG
void CgraphingView::AssertValid() const
{
	CView::AssertValid();
}

void CgraphingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CgraphingDoc* CgraphingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CgraphingDoc)));
	return (CgraphingDoc*)m_pDocument;
}
#endif //_DEBUG


// CgraphingView 消息处理程序


void CgraphingView::OnNew()
{
	// TODO: 在此添加命令处理程序代码

	graphtype = 4;
	Invalidate();
}


void CgraphingView::OnExit()
{
	// TODO: 在此添加命令处理程序代码

	PostQuitMessage(0);
}


void CgraphingView::OnBargraph()
{
	// TODO: 在此添加命令处理程序代码

	graphtype = 1;
	Invalidate();
}

void CgraphingView::bar_graph(CDC* pDC)
{
//画线
	CPen *pPen,*pOldPen;  
	pPen=new CPen(PS_SOLID,3,RGB(0,0,0));  
	pOldPen=(CPen *)pDC->SelectObject(pPen);
	CPoint p(100,100);
	pDC->MoveTo(p);
	pDC->LineTo(100,700);
	pDC->MoveTo(100,700);
	pDC->LineTo(1400,700);
	pDC->MoveTo(90,400);
	pDC->LineTo(110,400);
	pDC->MoveTo(90,500);
	pDC->LineTo(110,500);
	pDC->MoveTo(90,600);
	pDC->LineTo(110,600);
	pDC->MoveTo(400,690);
	pDC->LineTo(400,710);
	pDC->MoveTo(700,690);
	pDC->LineTo(700,710);
	pDC->MoveTo(1000,690);
	pDC->LineTo(1000,710);
	pDC->MoveTo(1200,100);
	pDC->LineTo(1500,100);
	pDC->MoveTo(1500,100);
	pDC->LineTo(1500,400);
	pDC->MoveTo(1500,400);
	pDC->LineTo(1200,400);
	pDC->MoveTo(1200,400);
	pDC->LineTo(1200,100);
	
	pDC->SelectObject(pOldPen);
	delete pPen; 

//写字
	
	CString s1("Bar Chart");
	CString s2("day1");
	CString s3("day2");
	CString s4("day3");
	CString s5("Games");
	CString s6("300");
	CString s7("200");
	CString s8("100");
	CString s9("Scores");
	CString s10("Legend");
	CString s11("game1");
	CString s12("game2");
	CString s13("game3");
	CString s14("game4");
	CString s15("game5");
	CString s16("game6");
	CString s17("game7");
	CString s18("game8");
	CString s19("game9");
	CString s20("game10");

	TEXTMETRIC tm;
	pDC->SetTextColor(RGB(0,0,0));  
	pDC->SelectStockObject(DEVICE_DEFAULT_FONT);
	pDC->TextOutW(700,50,s1);
	pDC->TextOutW(380,720,s2);
	pDC->TextOutW(680,720,s3);
	pDC->TextOutW(980,720,s4);
	pDC->TextOutW(680,750,s5);
	pDC->TextOutW(50,390,s6);
	pDC->TextOutW(50,490,s7);
	pDC->TextOutW(50,590,s8);
	pDC->TextOutW(1325,110,s10);
	pDC->TextOutW(1210,135,s11);
	pDC->TextOutW(1210,160,s12);
	pDC->TextOutW(1210,185,s13);
	pDC->TextOutW(1210,210,s14);
	pDC->TextOutW(1210,235,s15);
	pDC->TextOutW(1210,260,s16);
	pDC->TextOutW(1210,285,s17);
	pDC->TextOutW(1210,310,s18);
	pDC->TextOutW(1210,335,s19);
	pDC->TextOutW(1210,360,s20);
	pDC->GetTextMetrics(&tm);  
	
	CFont nowFont;
	LOGFONT logfont;
	memset(&logfont, 0, sizeof(logfont));
	logfont.lfWeight = 25;
	logfont.lfHeight = 25;
	logfont.lfEscapement = 90*10;
	nowFont.CreateFontIndirect(&logfont);
	pDC->SelectObject(nowFont);
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(10,490,s9);

//画条子
	
	pDC->FillSolidRect(1300,135,190,15,RGB(0,255,0));
	pDC->FillSolidRect(1300,160,190,15,RGB(0,0,255));
	pDC->FillSolidRect(1300,185,190,15,RGB(255,0,0));
	pDC->FillSolidRect(1300,210,190,15,RGB(60,54,75));
	pDC->FillSolidRect(1300,235,190,15,RGB(123,34,0));
	pDC->FillSolidRect(1300,260,190,15,RGB(256,24,34));
	pDC->FillSolidRect(1300,285,190,15,RGB(98,45,0));
	pDC->FillSolidRect(1300,310,190,15,RGB(21,43,87));
	pDC->FillSolidRect(1300,335,190,15,RGB(45,60,34));
	pDC->FillSolidRect(1300,360,190,15,RGB(0,90,235));

	pDC->FillSolidRect(150,550,20,150,RGB(0,0,255));
	pDC->FillSolidRect(170,450,20,250,RGB(256,24,34));
	pDC->FillSolidRect(190,400,20,300,RGB(123,34,0));
	pDC->FillSolidRect(210,500,20,200,RGB(0,255,0));
	pDC->FillSolidRect(230,470,20,230,RGB(98,45,0));
	pDC->FillSolidRect(250,400,20,300,RGB(45,60,34));
	pDC->FillSolidRect(270,520,20,180,RGB(60,54,75));
	pDC->FillSolidRect(290,480,20,220,RGB(0,90,235));
	pDC->FillSolidRect(310,450,20,250,RGB(255,0,0));
	pDC->FillSolidRect(330,420,20,280,RGB(60,54,75));
	pDC->FillSolidRect(680,500,20,200,RGB(0,255,0));
	pDC->FillSolidRect(700,560,20,140,RGB(0,90,235));
	pDC->FillSolidRect(720,440,20,260,RGB(45,60,34));
	pDC->FillSolidRect(960,500,20,200,RGB(256,24,34));
	pDC->FillSolidRect(980,530,20,170,RGB(45,60,34));
	pDC->FillSolidRect(1000,510,20,190,RGB(21,43,87));

}



void CgraphingView::OnLinegraph()
{
	// TODO: 在此添加命令处理程序代码

	graphtype = 2;
	Invalidate();
}

void CgraphingView::line_graph(CDC* pDC)
{
//画线
	CPen *pPen1,*pOldPen1;  
	pPen1=new CPen(PS_SOLID,3,RGB(0,0,0));  
	pOldPen1=(CPen *)pDC->SelectObject(pPen1);
	CPoint p1(100,100);
	pDC->MoveTo(p1);
	pDC->LineTo(100,700);
	pDC->MoveTo(100,700);
	pDC->LineTo(1400,700);
	pDC->MoveTo(90,400);
	pDC->LineTo(110,400);
	pDC->MoveTo(90,500);
	pDC->LineTo(110,500);
	pDC->MoveTo(90,600);
	pDC->LineTo(110,600);
	pDC->MoveTo(400,690);
	pDC->LineTo(400,710);
	pDC->MoveTo(700,690);
	pDC->LineTo(700,710);
	pDC->MoveTo(1000,690);
	pDC->LineTo(1000,710);
	pDC->MoveTo(1200,100);
	pDC->LineTo(1400,100);
	pDC->MoveTo(1400,100);
	pDC->LineTo(1400,300);
	pDC->MoveTo(1400,300);
	pDC->LineTo(1200,300);
	pDC->MoveTo(1200,300);
	pDC->LineTo(1200,100);
	
	pDC->SelectObject(pOldPen1);
	delete pPen1;

//写字
	CString s1("Line Chart");
	CString s2("Games");
	CString s3("300");
	CString s4("200");
	CString s5("100");
	CString s6("Scores");
	CString s7("day1");
	CString s8("day2");
	CString s9("day3");
	CString s10("Legend");
	CString s11("game1");
	CString s12("game2");
	CString s13("game3");

	TEXTMETRIC tm;
	pDC->SetTextColor(RGB(0,0,0));  
	pDC->SelectStockObject(DEVICE_DEFAULT_FONT);
	pDC->TextOutW(700,50,s1);
	pDC->TextOutW(680,780,s2);
	pDC->TextOutW(50,390,s3);
	pDC->TextOutW(50,490,s4);
	pDC->TextOutW(50,590,s5);
	pDC->TextOutW(1275,110,s10);
	pDC->TextOutW(1210,160,s11);
	pDC->TextOutW(1210,210,s12);
	pDC->TextOutW(1210,260,s13);
	pDC->GetTextMetrics(&tm);

	CFont nowFont1;
	LOGFONT logfont1;
	memset(&logfont1, 0, sizeof(logfont1));
	logfont1.lfWeight = 25;
	logfont1.lfHeight = 25;
	logfont1.lfEscapement = 90*10;
	nowFont1.CreateFontIndirect(&logfont1);
	pDC->SelectObject(nowFont1);
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(10,490,s6);

	CFont nowFont2;
	LOGFONT logfont2;
	memset(&logfont2, 0, sizeof(logfont2));
	logfont2.lfWeight = 20;
	logfont2.lfHeight = 20;
	logfont2.lfEscapement = 45*10;
	nowFont2.CreateFontIndirect(&logfont2);
	pDC->SelectObject(nowFont2);
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(380,740,s7);
	pDC->TextOut(680,740,s8);
	pDC->TextOut(980,740,s9);

//画条子
	pDC->FillSolidRect(1275,160,110,20,RGB(0,255,0));
	pDC->FillSolidRect(1275,210,110,20,RGB(0,0,255));
	pDC->FillSolidRect(1275,260,110,20,RGB(255,0,0));

//画折线
	CPen *pPen2,*pOldPen2;  
	pPen2=new CPen(PS_SOLID,3,RGB(0,255,0));  
	pOldPen2=(CPen *)pDC->SelectObject(pPen2);

	CPoint p2(400,500);
	pDC->MoveTo(p2);
	pDC->LineTo(700,400);
	pDC->MoveTo(700,400);
	pDC->LineTo(1000,520);

	pDC->SelectObject(pOldPen2);
	delete pPen2;


	CPen *pPen3,*pOldPen3;  
	pPen3=new CPen(PS_SOLID,3,RGB(255,0,0));  
	pOldPen3=(CPen *)pDC->SelectObject(pPen3);

	CPoint p3(400,530);
	pDC->MoveTo(p3);
	pDC->LineTo(700,620);
	pDC->MoveTo(700,620);
	pDC->LineTo(1000,570);

	pDC->SelectObject(pOldPen3);
	delete pPen3;


	CPen *pPen4,*pOldPen4;  
	pPen4=new CPen(PS_SOLID,3,RGB(0,0,255));  
	pOldPen4=(CPen *)pDC->SelectObject(pPen4);

	CPoint p4(400,600);
	pDC->MoveTo(p4);
	pDC->LineTo(700,540);
	pDC->MoveTo(700,540);
	pDC->LineTo(1000,530);

	pDC->SelectObject(pOldPen4);
	delete pPen4;

}


void CgraphingView::OnPiegraph()
{
	// TODO: 在此添加命令处理程序代码

	graphtype = 3;
	Invalidate();
}

void CgraphingView::pie_graph(CDC* pDC)
{

//画线
	CPen *pPen,*pOldPen;  
	pPen=new CPen(PS_SOLID,3,RGB(0,0,0));  
	pOldPen=(CPen *)pDC->SelectObject(pPen);

	CPoint p(1200,100);
	pDC->MoveTo(p);
	pDC->LineTo(1500,100);
	pDC->MoveTo(1500,100);
	pDC->LineTo(1500,400);
	pDC->MoveTo(1500,400);
	pDC->LineTo(1200,400);
	pDC->MoveTo(1200,400);
	pDC->LineTo(1200,100);
	
	

//写字
	CString s1("Pie Chart");
	CString s2("Legend");
	CString s3("game1");
	CString s4("game2");
	CString s5("game3");
	CString s6("game4");
	CString s7("game5");
	CString s8("game6");
	CString s9("game7");
	CString s10("game8");
	CString s11("game9");
	CString s12("game10");
	CString s13("day1");
	CString s14("day2");
	CString s15("day3");

	TEXTMETRIC tm;
	pDC->SetTextColor(RGB(0,0,0));  
	pDC->SelectStockObject(DEVICE_DEFAULT_FONT);
	pDC->TextOutW(700,50,s1);
	pDC->TextOutW(1325,110,s2);
	pDC->TextOutW(1210,135,s3);
	pDC->TextOutW(1210,160,s4);
	pDC->TextOutW(1210,185,s5);
	pDC->TextOutW(1210,210,s6);
	pDC->TextOutW(1210,235,s7);
	pDC->TextOutW(1210,260,s8);
	pDC->TextOutW(1210,285,s9);
	pDC->TextOutW(1210,310,s10);
	pDC->TextOutW(1210,335,s11);
	pDC->TextOutW(1210,360,s12);
	pDC->TextOutW(240,630,s13);
	pDC->TextOutW(580,630,s14);
	pDC->TextOutW(920,630,s15);
	pDC->GetTextMetrics(&tm);

//画条子
	pDC->FillSolidRect(1300,135,190,15,RGB(0,255,0));
	pDC->FillSolidRect(1300,160,190,15,RGB(0,0,255));
	pDC->FillSolidRect(1300,185,190,15,RGB(255,0,0));
	pDC->FillSolidRect(1300,210,190,15,RGB(255,255,0));
	pDC->FillSolidRect(1300,235,190,15,RGB(255,0,255));
	pDC->FillSolidRect(1300,260,190,15,RGB(0,255,255));
	pDC->FillSolidRect(1300,285,190,15,RGB(0,0,0));
	pDC->FillSolidRect(1300,310,190,15,RGB(255,255,255));
	pDC->FillSolidRect(1300,335,190,15,RGB(30,60,90));
	pDC->FillSolidRect(1300,360,190,15,RGB(128,128,128));

//画饼
	CBrush *pBrush,*pOldBrush;
	pDC->SetBkColor(RGB(255,255,255));

//饼1
	pBrush=new CBrush(RGB(0,0,255));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,240,300,220,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(0,255,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,220,300,200,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(255,0,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,200,300,150,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(255,255,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,150,300,120,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(128,128,128));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,120,300,100,450);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(0,255,255));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,100,450,130,600);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(0,0,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,130,600,270,600);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(255,0,255));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,270,600,370,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(30,60,90));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(100,300,400,600,370,300,240,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

//饼2
	pBrush=new CBrush(RGB(0,0,255));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(440,300,740,600,600,300,470,600);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(0,255,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(440,300,740,600,470,600,710,600);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(255,0,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(440,300,740,600,710,600,600,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

//饼3
	pBrush=new CBrush(RGB(0,0,255));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(780,300,1080,600,980,300,800,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(0,255,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(780,300,1080,600,800,300,800,600);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(255,0,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(780,300,1080,600,800,600,930,600);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(255,255,0));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(780,300,1080,600,930,600,950,600);
	pDC->SelectObject(pOldBrush);
	delete pBrush;

	pBrush=new CBrush(RGB(0,255,255));
	pOldBrush=(CBrush *)pDC->SelectObject(pBrush); 
	pDC->Pie(780,300,1080,600,950,600,980,300);
	pDC->SelectObject(pOldBrush);
	delete pBrush;


	pDC->SelectObject(pOldPen);
	delete pPen; 
}

void CgraphingView::OnBargraphindialog()
{
	// TODO: 在此添加命令处理程序代码
	
	Cgraphdia m_d;
	m_d.DoModal();
}
