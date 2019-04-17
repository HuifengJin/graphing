// Cgraphdia.cpp : 实现文件
//

#include "stdafx.h"
#include "graphing.h"
#include "Cgraphdia.h"
#include "afxdialogex.h"


// Cgraphdia 对话框

IMPLEMENT_DYNAMIC(Cgraphdia, CDialogEx)

Cgraphdia::Cgraphdia(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cgraphdia::IDD, pParent)
{

}

Cgraphdia::~Cgraphdia()
{
}

void Cgraphdia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cgraphdia, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Cgraphdia 消息处理程序


void Cgraphdia::OnPaint()
{
	CPaintDC *pDC = new CPaintDC(GetDlgItem(IDC_PICTURE)); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

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

	delete pDC;
}
