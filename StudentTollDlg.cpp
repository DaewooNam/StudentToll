
// StudentTollDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "StudentToll.h"
#include "StudentTollDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//People Information


 class  People// linkied list 값
{
	
protected: 
	CString name;
	CString sex;
	CString hobby;


 };



 /*
struct People
{
	CString *name;
	CString *sex;
	CString *hobby;

};
*/





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


// CStudentTollDlg 대화 상자



CStudentTollDlg::CStudentTollDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENTTOLL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentTollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStudentTollDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_MDF, &CStudentTollDlg::OnBnClickedBtnMdf)
	ON_BN_CLICKED(IDC_BTN_RESIST, &CStudentTollDlg::OnBnClickedBtnResist)
	ON_BN_CLICKED(IDC_BTN_DEL, &CStudentTollDlg::OnBnClickedBtnDel)
	ON_LBN_SELCHANGE(IDC_LIST_STUDENT, &CStudentTollDlg::OnLbnSelchangeListStudent)
END_MESSAGE_MAP()


// CStudentTollDlg 메시지 처리기

BOOL CStudentTollDlg::OnInitDialog()
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
	CListBox *pList = (CListBox*)GetDlgItem(IDC_LIST_STUDENT);


	
	
	People info[10];

	info[0].name = "키트리";




	
	
	
	pList->AddString("키트리/남/없음/없음/없음/없음");
	pList->AddString("안녕하/남/운동/코딩/없음/없음");
	pList->AddString("코이타/여/운동/코딩/없음/없음");




	



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CStudentTollDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CStudentTollDlg::OnPaint()
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
HCURSOR CStudentTollDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStudentTollDlg::OnBnClickedBtnMdf()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_STUDENT);



	int nSelIdx = pList->GetCurSel();

	pList->DeleteString(nSelIdx);

	ListAdd(nSelIdx);


}


void CStudentTollDlg::OnBnClickedBtnResist()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ListAdd();


}


void CStudentTollDlg::OnBnClickedBtnDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_STUDENT);
	int nSelIdx = pList->GetCurSel();
	pList->DeleteString(nSelIdx);
}


void CStudentTollDlg::OnLbnSelchangeListStudent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//TRACE("CStudentTollDlg::OnLbnSelchangeListStudent()\n");


	CListBox *pList = (CListBox*)GetDlgItem(IDC_LIST_STUDENT);


	int nSelIdx = pList->GetCurSel();

	CString strTotal;

	pList->GetText(nSelIdx, strTotal);
	strTotal += "\n";
	TRACE(strTotal);


	CString temp;
	//이름
	static int nIdx = 0;

	temp = strTotal.Tokenize("/",nIdx);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_NAME);

	pEdit->SetWindowText(temp);


	//성별 radio 방식은 이전 연결해주는 방법이 더 좋음
	temp = strTotal.Tokenize("/", nIdx);

	if(temp =="남")
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_RA_MAN);
		pBtn->SetCheck(TRUE);


		pBtn = (CButton*)GetDlgItem(IDC_RA_WOMAN);
		pBtn->SetCheck(FALSE);
	}
	else
	{	
		CButton* pBtn = (CButton*)GetDlgItem(IDC_RA_WOMAN);
		pBtn->SetCheck(TRUE);

		pBtn = (CButton*)GetDlgItem(IDC_RA_MAN);
		pBtn->SetCheck(FALSE);

	}

	//취미 (운동)
	temp = strTotal.Tokenize("/", nIdx);

	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK_SPORT);

	if (temp == "운동")
		pBtn->SetCheck(TRUE);
	else
		pBtn->SetCheck(FALSE);


	//취미 (코딩)

	temp = strTotal.Tokenize("/", nIdx);

	pBtn = (CButton*)GetDlgItem(IDC_CHECK_CODING);

	if (temp == "코딩")
		pBtn->SetCheck(TRUE);
	else
		pBtn->SetCheck(FALSE);



	//취미 (게임)
	temp = strTotal.Tokenize("/", nIdx);

	pBtn = (CButton*)GetDlgItem(IDC_CHECK_GAME);

	if (temp == "게임")
		pBtn->SetCheck(TRUE);
	else
		pBtn->SetCheck(FALSE);





	//취미 (등산)
	temp = strTotal.Tokenize("/", nIdx);

	pBtn = (CButton*)GetDlgItem(IDC_CHECK_MOUNT);

	if (temp == "등산")
		pBtn->SetCheck(TRUE);
	else
		pBtn->SetCheck(FALSE);

	nIdx = 0;


}

void CStudentTollDlg::ListAdd(int idx)
{
	//이름
	CString strTotal;

	CString temp;
	GetDlgItemText(IDC_EDIT_NAME, temp);

	strTotal += temp;
	strTotal += "/";

	// 성별
	CButton*p = (CButton*)GetDlgItem(IDC_RA_MAN);
	int n = p->GetCheck();

	
	if (n == 1) //남
		strTotal += "남/";
	else
		strTotal += "여/";


	// 취미
	p = (CButton*)GetDlgItem(IDC_CHECK_SPORT);
	if (p->GetCheck())
		strTotal += "운동/";
	else
		strTotal += "없음/";

	p = (CButton*)GetDlgItem(IDC_CHECK_CODING);
	if (p->GetCheck())
		strTotal += "코딩/";
	else
		strTotal += "없음/";

	p = (CButton*)GetDlgItem(IDC_CHECK_GAME);
	if (p->GetCheck())
		strTotal += "게임/";
	else
		strTotal += "없음/";



	p = (CButton*)GetDlgItem(IDC_CHECK_MOUNT);
	if (p->GetCheck())
		strTotal += "등산/";
	else
		strTotal += "없음/";


	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_STUDENT);
	pList->InsertString(idx, strTotal);
}
