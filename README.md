# MFC_submit_Leechansol

### MFCSubmit_LeeChansolDlg.cpp  
void OnBnClickedBtnDraw() : Circle 버튼, 반지름 길이 받아오기, 좌표 구하기  
void drawCircle(unsigned char* fm, int x, int y, int nRadius) : 받은 좌표로 원 그리기  
bool isCircle(int i, int j, int nCenterX, int nCenterY, int nRadius) : 원 내부인지 판별하기  
void OnBnClickedBtnCenter() : 중심에 십자 그리기  
CPoint findCenter() : Center 버튼, 중심 좌표 찾기  
void OnBnClickedBtnOutcircle() : OutCircle 버튼  

### DlgImage.cpp  
void OnPaint() : OutCircle 버튼 클릭시 drawOutCircle 호출  
void drawOutCircle(CDC* pDC, COLORREF color, int thick) : pen으로 원 그리기  

