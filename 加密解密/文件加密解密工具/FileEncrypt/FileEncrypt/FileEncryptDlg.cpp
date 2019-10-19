
// FileEncryptDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "FileEncrypt.h"
#include "FileEncryptDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CFileEncryptDlg 对话框



CFileEncryptDlg::CFileEncryptDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILEENCRYPT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileEncryptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DECRYPT, m_editFileDecrypt);
	DDX_Control(pDX, IDC_EDIT_ENCRYPT, m_editFileEncrypt);
}

BEGIN_MESSAGE_MAP(CFileEncryptDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_ENCRYPT, &CFileEncryptDlg::OnEnChangeEditEncrypt)
	ON_EN_CHANGE(IDC_EDIT_DECRYPT, &CFileEncryptDlg::OnEnChangeEditDecrypt)
	ON_BN_CLICKED(IDC_BUTTON_ENCRYPT, &CFileEncryptDlg::OnBnClickedButtonEncrypt)
	ON_BN_CLICKED(IDC_BUTTON_DECRYPT, &CFileEncryptDlg::OnBnClickedButtonDecrypt)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CFileEncryptDlg 消息处理程序

BOOL CFileEncryptDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFileEncryptDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFileEncryptDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFileEncryptDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileEncryptDlg::OnEnChangeEditEncrypt()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CFileEncryptDlg::OnEnChangeEditDecrypt()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CFileEncryptDlg::OnBnClickedButtonEncrypt()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString cstr;
	m_editFileEncrypt.GetWindowTextW(cstr);
	//AfxMessageBox(cstr);
	UpdateData(FALSE);

	DoEncrypt(cstr);
	AfxMessageBox(TEXT("文件成功加密"));
}


void CFileEncryptDlg::OnBnClickedButtonDecrypt()
{
	// TODO: 在此添加控件通知处理程序代码
	//控件变量方式获取Edit控件文件
	UpdateData(TRUE);
	CString cstr;
	m_editFileDecrypt.GetWindowTextW(cstr);
	//AfxMessageBox(cstr);
	UpdateData(FALSE);

	DoDecrypt(cstr);
	AfxMessageBox(TEXT("文件成功解密"));
}


void CFileEncryptDlg::OnDropFiles(HDROP hDropInfo)
{

}

void CFileEncryptDlg::DoEncrypt(CString filepath)
{
	FILE* infp;
	USES_CONVERSION;
	char file_path[MAX_PATH] = { '\0' };
	strcpy(file_path, T2A(filepath));
	infp = fopen(file_path, "rb");
	if (infp == NULL) {
		AfxMessageBox(TEXT("文件打开失败，Error %d"));
	}

	fseek(infp, 0, SEEK_END);
	unsigned int nLength = ftell(infp);
	fseek(infp, 0, SEEK_SET);

	char* pbuffer = new char[nLength+1];

	if (!fread(pbuffer, 1, nLength, infp)) {
		AfxMessageBox(TEXT("fread 文件读取失败"));
	}

	char* key = ">6G/QJ25@hlyX:?a";
	unsigned int uKeyLen = strlen(key);
	unsigned int j = 0;
	unsigned int i = 0;
	for (; i < nLength; i++) {
		pbuffer[i] ^= key[j];
		j++;
		if (j >= uKeyLen)
			j -= uKeyLen;
	}

	//写加密后的文件
	FILE* outfp;
	char encrypt_filepath[MAX_PATH] = { '\0' };
	char path[MAX_PATH] = { '\0' };
	char filename[MAX_PATH] = { '\0' };
	char* pfilepath = file_path + strlen(file_path) -1;
	unsigned int k = 0;
	while (*pfilepath) {
		k++;
		if (*pfilepath == '\\') {
			//path
			strncpy(path, file_path, strlen(file_path) - k + 1);
			//finename
			strncpy(filename, pfilepath+1, k);
			break;
		}
		pfilepath--;
	}
	strcat(encrypt_filepath, path);
	strcat(encrypt_filepath, "encrypt_");
	strcat(encrypt_filepath, filename);
	outfp = fopen(encrypt_filepath, "wb");
	if (outfp == NULL) {
		AfxMessageBox(TEXT("加密文件打开失败"));
	}
	if (!fwrite(pbuffer, 1, nLength, outfp)) {
		AfxMessageBox(TEXT("加密文件写入失败"));
	}

	if (outfp != NULL)
		fclose(outfp);
	outfp = NULL;

	if (infp != NULL)
		fclose(infp);
	infp = NULL;

	delete [] pbuffer;
	pbuffer = NULL;
}

void CFileEncryptDlg::DoDecrypt(CString filepath)
{
	FILE* infp;
	USES_CONVERSION;
	char file_path[MAX_PATH] = { '\0' };
	strcpy(file_path, T2A(filepath));
	infp = fopen(file_path, "rb");
	if (infp == NULL) {
		AfxMessageBox(TEXT("文件打开失败，Error %d"));
	}

	fseek(infp, 0, SEEK_END);
	unsigned int nLength = ftell(infp);
	fseek(infp, 0, SEEK_SET);

	char* pbuffer = new char[nLength + 1];

	if (!fread(pbuffer, 1, nLength, infp)) {
		AfxMessageBox(TEXT("fread 文件读取失败"));
	}

	char* key = ">6G/QJ25@hlyX:?a";
	unsigned int uKeyLen = strlen(key);
	unsigned int j = 0;
	unsigned int i = 0;
	for (; i < nLength; i++) {
		pbuffer[i] ^= key[j];
		j++;
		if (j >= uKeyLen)
			j -= uKeyLen;
	}

	//写解密后的文件
	FILE* outfp;
	char decrypt_filepath[MAX_PATH] = { '\0' };
	char path[MAX_PATH] = { '\0' };
	char filename[MAX_PATH] = { '\0' };
	char* pfilepath = file_path + strlen(file_path) - 1;
	unsigned int k = 0;
	while (*pfilepath) {
		k++;
		if (*pfilepath == '\\') {
			//path
			strncpy(path, file_path, strlen(file_path) - k + 1);
			//finename
			strncpy(filename, pfilepath + 1, k);
			break;
		}
		pfilepath--;
	}
	strcat(decrypt_filepath, path);
	strcat(decrypt_filepath, "decrypt_");
	strcat(decrypt_filepath, filename);
	outfp = fopen(decrypt_filepath, "wb");
	if (outfp == NULL) {
		AfxMessageBox(TEXT("解密文件打开失败"));
	}
	if (!fwrite(pbuffer, 1, nLength, outfp)) {
		AfxMessageBox(TEXT("解密文件写入失败"));
	}

	if (outfp != NULL)
		fclose(outfp);
	outfp = NULL;

	if (infp != NULL)
		fclose(infp);
	infp = NULL;

	delete[] pbuffer;
	pbuffer = NULL;
}
