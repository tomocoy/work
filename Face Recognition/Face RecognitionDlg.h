
// Face RecognitionDlg.h : ͷ�ļ�
//
#include <cv.h>

#pragma once
 
#define IMG_HEIGHT 200  
#define IMG_WIDTH 180 

// CFaceRecognitionDlg �Ի���
class CFaceRecognitionDlg : public CDialogEx
{
// ����
public:
	CFaceRecognitionDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FACERECOGNITION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtnBrowse();
	afx_msg void OnBnClickedBtnCheck();

private:
	int m_num;
	void DrawPicToHDC(IplImage* image, UINT ID);
	void load_data(double *T, IplImage *src, int k);
	void calc_mean(double *T, double *m);
	void calc_covariance_matrix(double *T, double *L, double *m);
	void cstrq(double a[], int n, double q[], double b[], double c[]);
	int csstq(int n, double b[], double c[], double q[], double eps, int l);
	void matrix_reverse(double *src, double *dest, int row, int col);
	void matrix_mutil(double *c, double *a, double *b, int x, int y, int z);
	void pick_eignevalue(double *b, double *q, double *p_q, int num_q);
	void get_eigenface(double *p_q, double *T, int num_q, double *projected_train, double *eigenvector);
	
public:
	afx_msg void OnBnClickedBtnBrowse2();
};
