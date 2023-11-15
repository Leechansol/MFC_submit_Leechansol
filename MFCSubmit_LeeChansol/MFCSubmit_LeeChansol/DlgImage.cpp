﻿// DlgImage.cpp: 구현 파일
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
	findCenter();
	drawData(&dc);
}

void CDlgImage::drawData(CDC* pDC)
{
	//drawCircle(pDC, COLOR_BLUE); // original circle
	//drawCenter(pDC);
	drawOutCircle(pDC, COLOR_YELLOW, 2); // out circle
	
}

void CDlgImage::findCenter()
{
	int x = m_pos[0].x;
	int y = m_pos[0].y;
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();

	int sumX = 0;
	int sumY = 0;
	int cnt = 0;
	CRect rect(0, 0, nWidth, nHeight);
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] == 0) {
				sumX += i;
				sumY += j;
				cnt++;
			}
		}
	}
	double centerX = (double)sumX / cnt;
	double centerY = (double)sumY / cnt;

}

// 원그리기
void CDlgImage::drawOutCircle(CDC* pDC, COLORREF color, int thick)
{
	int x = m_pos[0].x;
	int y = m_pos[0].y;
	
	CPen pen;
	CBrush brush;
	
	pen.CreatePen(PS_SOLID, thick, color); //펜모양, 굵기, 색깔
	CPen* pOldPen = pDC->SelectObject(&pen);
	brush.CreateStockObject(NULL_BRUSH);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	CRect rect(x-thick/2, y-thick/2, x + radius * 2 + thick/2, y + radius * 2 + thick/2);
	pDC->Ellipse(rect); // 원그리기
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

	pen.DeleteObject();
	brush.DeleteObject();
	
}

// 십자그리기
void CDlgImage::drawCenter(CDC* pDC)
{
	/*
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, COLOR_BLUE);
	CPen* pOldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(m_pos[0].x - 3, m_pos[0].y); // 시작 좌표
	pDC->LineTo(m_pos[0].x + 3, m_pos[0].y); // 끝 좌표

	pDC->MoveTo(m_pos[0].x, m_pos[0].y - 3); // 시작 좌표
	pDC->LineTo(m_pos[0].x, m_pos[0].y + 3); // 끝 좌표

	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
	*/
}