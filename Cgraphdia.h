#pragma once


// Cgraphdia �Ի���

class Cgraphdia : public CDialogEx
{
	DECLARE_DYNAMIC(Cgraphdia)

public:
	Cgraphdia(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cgraphdia();

// �Ի�������
	enum { IDD = IDD_DIAGRAPH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
