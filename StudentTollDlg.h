
// StudentTollDlg.h: 헤더 파일
//

#pragma once


// CStudentTollDlg 대화 상자
class CStudentTollDlg : public CDialogEx
{
// 생성입니다.
public:
	CStudentTollDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENTTOLL_DIALOG };
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
	afx_msg void OnBnClickedBtnMdf();
	afx_msg void OnBnClickedBtnResist();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnLbnSelchangeListStudent();
	
	void ListAdd(int idx = 0); // 아무것도 매개면서 없을시 디폴트 매개변수

};
