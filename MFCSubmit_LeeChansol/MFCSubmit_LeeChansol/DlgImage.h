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
	CPoint m_center[MAX_POINT];
	int flg = 0;
	int circle_size = 0;

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
	void drawOutCircle(CDC* pDC, COLORREF color, int thick);
private:
	void InitImage();
};
