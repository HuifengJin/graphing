#pragma once


// Cgraphdia 对话框

class Cgraphdia : public CDialogEx
{
	DECLARE_DYNAMIC(Cgraphdia)

public:
	Cgraphdia(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cgraphdia();

// 对话框数据
	enum { IDD = IDD_DIAGRAPH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
