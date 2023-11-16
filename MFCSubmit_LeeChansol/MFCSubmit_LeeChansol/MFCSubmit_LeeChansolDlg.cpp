
// MFCSubmit_LeeChansolDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCSubmit_LeeChansol.h"
#include "MFCSubmit_LeeChansolDlg.h"
#include "afxdialogex.h"
#define COLOR_YELLOW RGB(0xff, 0xff, 0)
#define COLOR_BLACK RGB(0, 0, 0)

#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCSubmitLeeChansolDlg 대화 상자



CMFCSubmitLeeChansolDlg::CMFCSubmitLeeChansolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSUBMIT_LEECHANSOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSubmitLeeChansolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSubmitLeeChansolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DRAW, &CMFCSubmitLeeChansolDlg::OnBnClickedBtnDraw)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_CENTER, &CMFCSubmitLeeChansolDlg::OnBnClickedBtnCenter)
	ON_BN_CLICKED(IDC_BTN_OUTCIRCLE, &CMFCSubmitLeeChansolDlg::OnBnClickedBtnOutcircle)
END_MESSAGE_MAP()


// CMFCSubmitLeeChansolDlg 메시지 처리기

BOOL CMFCSubmitLeeChansolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	MoveWindow(0, 0, 960, 600);
	// 새 다이얼로그 연결
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);

	m_pDlgImage->flg = false;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCSubmitLeeChansolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCSubmitLeeChansolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCSubmitLeeChansolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 기본 원 그리기
void CMFCSubmitLeeChansolDlg::OnBnClickedBtnDraw()
{
	// 반지름 길이 받아오기
	int radius = GetDlgItemInt(IDC_RADIUS);
	//m_pDlgImage->radius = radius;
	nRadius = radius;

	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	memset(fm, 220, nWidth * nHeight);

	// 랜덤 좌표, 밖으로 벗어나지 않게
	int x = rand() % (nWidth - radius*2);
	int y = rand() % (nHeight - radius*2);

	m_pDlgImage->m_pos[0].x = x;
	m_pDlgImage->m_pos[0].y = y;

	m_pos[0].x = x;
	m_pos[0].y = y;

	//원 그리기
	drawCircle(fm, x, y, radius, COLOR_YELLOW);

	m_pDlgImage->Invalidate();
}


void CMFCSubmitLeeChansolDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pDlgImage)	delete m_pDlgImage;
}

//좌표 받아서 기본 원 그리기
void CMFCSubmitLeeChansolDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, COLORREF color)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_pDlgImage->m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2 + 1 ; j++) {
		for (int i = x; i < x + nRadius * 2 + 1 ; i++) {
			if (isCircle(i, j, nCenterX, nCenterY, nRadius))
				fm[j * nPitch + i] = COLOR_BLACK;
		}
	}
}

//원 내부 판별
bool CMFCSubmitLeeChansolDlg::isCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool flg = false;
	double dx = i - nCenterX;
	double dy = j - nCenterY;
	double dDist = dx * dx + dy * dy;

	//원 내부 판별
	if (dDist <= nRadius * nRadius)
		flg = true;

	return flg;
}

//중심에 십자 그리기
void CMFCSubmitLeeChansolDlg::OnBnClickedBtnCenter()
{
	int len = nRadius/5; // 십자 길이
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	CPoint pt = findCenter();

	cout << pt.x << "," << pt.y << endl;
	for (int j = pt.y - len; j < pt.y + len+1; j++) {
		fm[j * nPitch + pt.x] = 0xff;
	}
	for (int i = pt.x - len; i < pt.x + len+1; i++) {
		fm[pt.y * nPitch + i] = 0xff;
	}
	m_pDlgImage->Invalidate();
}

// 중심좌표 찾기
CPoint CMFCSubmitLeeChansolDlg::findCenter()
{
	CPoint pt;
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	// 중심좌표를 위한 변수
	int sumX = 0;
	int sumY = 0;
	int cnt = 0;

	//반지름 계산을 위한 변수
	int x_min = INT_MAX;
	int x_max = INT_MIN;
	int y_min = INT_MAX;
	int y_max = INT_MIN;

	CRect rect(0, 0, nWidth, nHeight);
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] == 0) {
				sumX += i;
				sumY += j;
				cnt++;

				x_min = min(x_min, i);
				x_max = max(x_max, i);
				y_min = min(y_min, j);
				y_max = max(y_max, j);
			}
		}
	}

	double centerX = (double)sumX / cnt;
	double centerY = (double)sumY / cnt;

	m_pDlgImage->circle_size = (((x_max - x_min) / 2) + ((y_max - y_min) / 2)) / 2; // 반지름 계산

	pt.x = centerX;
	pt.y = centerY;
	m_pDlgImage->m_center[0].x = centerX;
	m_pDlgImage->m_center[0].y = centerY;
	return pt;
}
void CMFCSubmitLeeChansolDlg::OnBnClickedBtnOutcircle()
{
	m_pDlgImage->flg = true;
	m_pDlgImage->Invalidate();
}

