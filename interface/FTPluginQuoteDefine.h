#pragma once

#ifndef interface
#define interface struct
#endif

/*************************************************
Copyright: FUTU
Author: ysq
Date: 2015-03-18
Description: ����API�ͻص��ӿڶ���
**************************************************/

/**
*��Ʊ���г�����
*/
enum StockMktType
{
	StockMkt_None = 0,
	StockMkt_HK = 1,  //�۹� 
	StockMkt_US = 2,  //����
	StockMkt_SH = 3,  //����
	StockMkt_SZ = 4,  //���
	StockMkt_Feature_Old = 5,  //�ɵ��ڻ� code: 999000, 999001 �����ڻ���ʱ������һ��������
	StockMkt_Feature_New = 6,  //���ڻ� code: 999010, 999011 �����ڻ���ʱ���ݻ���죬�봫ͳ��������һ�£�
};

enum StockSubErrCode
{
	StockSub_Suc = 0,	//���ĳɹ�
	StockSub_FailUnknown = 1,	//δ֪��ʧ��
	StockSub_FailMaxSubNum = 2,	//�����������
	StockSub_FailCodeNoFind = 3,	//����û�ҵ�(Ҳ�п������г����ʹ���)
	StockSub_FailGuidNoFind = 4,	//���GUID����
	StockSub_FailNoImplInf = 5,		//����ӿ�δ���
	StockSub_UnSubTimeError = 6,	//δ���㷴����Ҫ��ʱ��-1����
};

enum QueryDataErrCode
{
	QueryData_Suc = 0,	//��ѯ�ɹ�
	QueryData_FailUnknown = 1,	//δ֪��ʧ��
	QueryData_FailMaxSubNum = 2,	//��������ѯ��
	QueryData_FailCodeNoFind = 3,	//����û�ҵ�(Ҳ�п������г����ʹ���)
	QueryData_FailGuidNoFind = 4,	//���GUID����
	QueryData_FailNoImplInf = 5,		//����ӿ�δ���
	QueryData_IsExisted = 6,
};

enum StockSubType
{
	StockSubType_Simple = 1,
	StockSubType_Gear = 2,
	StockSubType_Ticker = 4,
	StockSubType_RT = 5,
	StockSubType_KL_DAY = 6,
	StockSubType_KL_MIN5 = 7,
	StockSubType_KL_MIN15 = 8,
	StockSubType_KL_MIN30 = 9,
	StockSubType_KL_MIN60 = 10,
	StockSubType_KL_MIN1 = 11,
	StockSubType_KL_WEEK = 12,
	StockSubType_KL_MONTH = 13,
};

enum PluginSecurityType
{
	PluginSecurity_All = 0,
	PluginSecurity_Bond = 1, //ծȯ	
	PluginSecurity_Stock = 3, //����	
	PluginSecurity_ETF = 4,
	PluginSecurity_Warrant = 5, //����ţ��		
	PluginSecurity_Index = 6,
};

/**
* ��Ʊ����������Ϣ��
* �۸񾫶���3λС���� �籨��8.888�洢ֵ 88888
*/
typedef struct tagQuotePriceBase
{
	DWORD dwOpen;		//���̼�
	DWORD dwLastClose;  //���ռ�
	DWORD dwCur;		//��ǰ��
	DWORD dwHigh;		//��߼�
	DWORD dwLow;		//��ͼ�
	INT64 ddwVolume;	//�ɽ���
	INT64 ddwTrunover;	//�ɽ���
	DWORD dwTime;		//����ʱ��
	DWORD ddwLotSize;	//ÿ������
}Quote_PriceBase, *LPQuote_PriceBase;


/**
* ��Ʊʮ������
* IFTQuoteData::FillOrderQueue �Ľӿڲ���
*/
typedef struct tagQuoteOrderItem
{
	DWORD	dwBuyPrice, dwSellPrice;  //��� ����
	INT64	ddwBuyVol, ddwSellVol;    //���� ����
	int		nBuyOrders, nSellOrders;  //��λ 
}Quote_OrderItem, *LPQuote_OrderItem;

typedef struct tagPluginTickItem
{
	DWORD dwPrice;
	DWORD dwTime;
	int nDealType;
	INT64 nSequence;
	INT64 nVolume;
	INT64 nTurnover; //�ɽ���
}PluginTickItem, *LPPluginTickItem;

/**
* ��ʱ����
*/
typedef struct tagQuoteStockRTData
{
	int   nDataStatus;
	DWORD dwTime;
	DWORD dwOpenedMins;  //���̵ڶ��ٷ���  

	int   nCurPrice;
	DWORD nLastClosePrice; //��������̼� 

	int   nAvgPrice;

	INT64 ddwTDVolume;
	INT64 ddwTDValue;
}Quote_StockRTData, *LPQuote_StockRTData;

/**
* K������
*/
typedef struct tagQueryStockKLData
{
	int   nDataStatus;
	DWORD dwTime;

	int   nOpenPrice;
	int   nClosePrice;

	int   nHighestPrice;
	int   nLowestPrice;

	int   nPERatio; //��ӯ��(��λС��)
	int   nTurnoverRate;//������(���ɼ�ָ������/��/��K��)

	INT64 ddwTDVol;
	INT64 ddwTDVal;
}Quote_StockKLData, *LPQuote_StockKLData;

typedef struct tagSubInfo
{
	INT64 ddwStockHash;
	int   nStockSubType;
}Quote_SubInfo, *LPQuote_SubInfo;

//nKLType:
//1 = 1��K;  
//2 = ��K; 
//3 = ��K;   
//4 = ��K;
//6 = 5��K; 
//7 = 15��K;  
//8 = 30��K;  
//9 = 60��K;
//
//nRehabType:
//0 = ����Ȩ��
//1 = ǰ��Ȩ��
//2 = ��Ȩ��

//nStockSubType:
//1 = ����
//2 = ����
//4 = ���
//5 = ��ʱ//δ��
//6 = ��K
//7 =  5��K
//8 =  15��K
//9 =  30��K
//10 =  60��K
//11 =  1��K
//12 = ��K
//13 = ��K

typedef struct tagPluginStockInfo
{
	INT64 nStockID;
	int  nLotSize;
	PluginSecurityType nSecType;
	WCHAR chSimpName[64];
	WCHAR chCodeSig[16];
}PluginStockInfo, *LPPluginStockInfo;

typedef struct tagBatchBasic
{
	DWORD dwOpen;		//���̼�
	DWORD dwLastClose;  //���ռ�
	DWORD dwCur;		//��ǰ��
	DWORD dwHigh;		//��߼�
	DWORD dwLow;		//��ͼ�
	DWORD dwAmpli;
	INT64 ddwVolume;	//�ɽ���
	INT64 ddwTurnover;	//�ɽ���
	int   nSuspension;
	int   nTurnoverRate;
	DWORD dwTime;		//����ʱ��
	DWORD dwListTime;	//����ʱ��
}Quote_BatchBasic, *LPQuote_BatchBasic;

enum PlugErtFlag
{
	Ert_NONE = 0x00,
	Ert_SPLIT = 0x01,    //���
	Ert_JOIN = 0x02,	 //�Ϲ�
	Ert_BONUS_STK = 0x04,//�͹�
	Ert_INTOSHARES = 0x08,//ת����
	Ert_ALLOT = 0x10,    //���
	Ert_ADD = 0x20,		//������
	Ert_DIVIDEND = 0x40,//���ֽ�ֺ�
	Ert_SPECIALDIVIDEND = 0x80, //���ֽ�ֺ�
};

//��Ȩ��¼��
struct PluginExRightItem
{
	INT64 stock_id;
	UINT ex_date;    // ��Ȩ��Ϣ����, ����20160615
	UINT ert_flag;    // ��˾�ж�������ϣ�ErtFlag

	//���(eg. 1��5��BaseΪ1��ERTΪ5)
	UINT split_base;
	UINT split_ert;

	//�Ϲ�(eg. 50��1��BaseΪ50��ERTΪ1)
	UINT join_base;
	UINT join_ert;

	//�͹�(eg. 10��3, BaseΪ10,ERTΪ3)
	UINT bonus_stk_base;
	UINT bonus_stk_ert;

	//���(eg. 10��2, ��ɼ�Ϊ6.3Ԫ, BaseΪ10, ERTΪ2, PriceΪ6300)
	UINT allot_base;
	UINT allot_ert;
	INT64 allot_price;

	//ת����(���͹�����)
	UINT into_shr_base;
	UINT into_ert;

	//����(���������)
	UINT stk_add_base;
	UINT stk_add_ert;
	INT64 stk_add_price;

	// �ֽ�ֺ�(eg. ÿ10������0.5Ԫ��BaseΪ10, AmountΪ500)
	UINT dividend_base;
	INT64 dividend_amount;

	// �ر��Ϣ
	UINT dividend_special_base;
	UINT dividend_special_amount;

	// result_self
	double fwd_factor_a;
	double fwd_factor_b;
	double bwd_factor_a;
	double bwd_factor_b;

	// ���������ı�����
	wchar_t *sc_txt;

	// ���������ı�����
	wchar_t *tc_txt;
};

// ��Ʊ�������������
struct PluginStockSnapshot
{
	INT64 stock_id;    // ��Ʊid
	int  ret;    // �Ƿ��ҵ����ռ�¼��0Ϊ�ɹ��ҵ���snapshot�����ݡ�����ֵ��snapshot�����ݣ��������Ҳ�����Ʊ��
	char   stock_code[16];
	UINT instrument_type;
	UINT market_code;

	// �۸����
	double nominal_price;
	double last_close_price;
	double open_price;
	INT64 update_time;

	INT64 suspend_flag;
	INT64 listing_status;
	INT64 listing_date;

	// �ɽ�ͳ����Ϣ
	INT64 shares_traded;
	double turnover;
	double highest_price;
	double lowest_price;
	float  turnover_ratio;
};