// PluginServer.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "PluginServer.h"
#include "PluginModule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE �����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//


// CPluginServerApp

BEGIN_MESSAGE_MAP(CPluginServerApp, CWinApp)
END_MESSAGE_MAP()


// CPluginServerApp ����

CPluginServerApp::CPluginServerApp()
{
	// TODO: �ڴ˴����ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CPluginServerApp ����

CPluginServerApp theApp;


// CPluginServerApp ��ʼ��

BOOL CPluginServerApp::InitInstance()
{
	CWinApp::InitInstance();	

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	return TRUE;
}

int CPluginServerApp::ExitInstance()
{
	ReleasePluginMoudle();
	return __super::ExitInstance();
}