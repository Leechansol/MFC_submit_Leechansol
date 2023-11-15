#pragma once
#include "afxdialogex.h"
#include "MFCSubmit_LeeChansol.h"

#define MAX_POINT 100

// CDlgImage 대화 상자

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CImage m_image;
	CWnd* m_pParent; // 부모 변수 저장
	CPoint m_pos[MAX_POINT];
	double m_widthlength;
	double m_heightlength;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	void drawData(CDC* pDC);
	void drawCircle(CDC* pDC, COLORREF color, int n);
	void drawCenter(CDC* pDC);
	void InitImage();
};
