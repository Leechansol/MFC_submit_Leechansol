
// MFCSubmit_LeeChansolDlg.h: 헤더 파일
//

#pragma once
#include "DlgImage.h"

#define MAX_POINT 10

// CMFCSubmitLeeChansolDlg 대화 상자
class CMFCSubmitLeeChansolDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCSubmitLeeChansolDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CImage m_image;
	CDlgImage* m_pDlgImage;
	CPoint m_pos[MAX_POINT];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSUBMIT_LEECHANSOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDraw();
	afx_msg void OnDestroy();
	void drawCircle(unsigned char* fm, int x, int y, int nRadius);
	bool isCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	afx_msg void OnBnClickedBtnCenter();
	CPoint findCenter();
};
