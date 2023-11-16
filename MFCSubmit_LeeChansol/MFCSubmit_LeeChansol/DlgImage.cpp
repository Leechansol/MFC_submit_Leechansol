// DlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "MFCSubmit_LeeChansol.h"
#include "afxdialogex.h"
#include "DlgImage.h"

#define COLOR_YELLOW RGB(0xff, 0xff, 0)
#define COLOR_BLUE RGB(0, 0, 0xff)

#include <iostream>
using namespace std;
// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MoveWindow(0, 0, 640, 480); //윈도우 사이즈 조절
	InitImage();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 220, nWidth * nHeight);
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}

	if (flg == true) // OutCircle 버튼 클릭 시
		drawOutCircle(&dc, COLOR_YELLOW, 1);
}

void CDlgImage::drawData(CDC* pDC)
{
	drawOutCircle(pDC, COLOR_YELLOW, 1); // out circle
}

// pen으로 원그리기
void CDlgImage::drawOutCircle(CDC* pDC, COLORREF color, int thick)
{
	CPen pen;
	CBrush brush;
	
	pen.CreatePen(PS_SOLID, thick, color); //펜모양, 굵기, 색깔
	CPen* pOldPen = pDC->SelectObject(&pen);
	brush.CreateStockObject(NULL_BRUSH);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	CRect rect(m_pos[0].x, m_pos[0].y, m_pos[0].x+circle_size*2+1, m_pos[0].y + circle_size*2+1);
	pDC->Ellipse(rect); // 원그리기
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

	pen.DeleteObject();
	brush.DeleteObject();
	
	flg = false;
}