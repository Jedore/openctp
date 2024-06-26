/////////////////////////////////////////////////////////////////////////
///@author �����Ƹ�֤ȯ�ɷ����޹�˾
///@file EMQ_quote_data_type.h
///@brief ����������ݻ�������
/////////////////////////////////////////////////////////////////////////
#ifndef _EMQ_QUOTE_DATA_TYPE_H_
#define _EMQ_QUOTE_DATA_TYPE_H_
#include <cinttypes>

#pragma pack(1)
/// API�汾��
#define API_VERSION	"2.19.0"
///�ڲ�Э��ͨ�Ű汾
#define EMT_VERSION 1

/// ���֤ȯ������ַ�������
#define EMQ_TICKER_LEN 16
/// ���֤ȯ���Ƶ��ַ�������
#define EMQ_TICKER_NAME_LEN 64

#define EMQ_HK_TICKER_LEN 8
#define EMQ_BJGZ_TICKER_LEN 8

/////////////////////////////////////////////////////////////////////////
///@brief EMQ_LOG_LEVEL����־�����������
/////////////////////////////////////////////////////////////////////////
typedef enum EMQ_LOG_LEVEL {
	EMQ_LOG_LEVEL_TRACE,
	EMQ_LOG_LEVEL_DEBUG,
	EMQ_LOG_LEVEL_INFO,
	EMQ_LOG_LEVEL_WARNING,
	EMQ_LOG_LEVEL_ERROR,
	EMQ_LOG_LEVEL_FATAL,
	EMQ_LOG_LEVEL_OFF
}EMQ_LOG_LEVEL;

/////////////////////////////////////////////////////////////////////////
///@brief EMQ_PROTOCOL_TYPE��ͨѶ����Э�鷽ʽ
/////////////////////////////////////////////////////////////////////////
typedef enum EMQ_PROTOCOL_TYPE
{
	EMQ_PROTOCOL_TCP = 1,	///<����TCP��ʽ����
	EMQ_PROTOCOL_UDP		///<����UDP��ʽ����(������ӿ�֧��)
}EMQ_PROTOCOL_TYPE;

/////////////////////////////////////////////////////////////////////////
///@brief EMQ_EXCHANGE_TYPE�ǽ��������ͣ�������ʹ��
/////////////////////////////////////////////////////////////////////////
typedef enum EMQ_EXCHANGE_TYPE
{
	EMQ_EXCHANGE_SH = 1,	    ///<��֤
	EMQ_EXCHANGE_SZ,		    ///<��֤
	EMQ_EXCHANGE_SHHK,			///<��֤�۹�ͨ
	EMQ_EXCHANGE_SZHK,		    ///<��֤�۹�ͨ
	EMQ_EXCHANGE_BJGZ,		    ///<��������ת����
	EMQ_EXCHANGE_UNKNOWN = 100  ///<�����ڵĽ���������
}EMQ_EXCHANGE_TYPE;


//////////////////////////////////////////////////////////////////////////
///@brief EMQ_TICKER_TYPE֤ȯ����
//////////////////////////////////////////////////////////////////////////
typedef enum EMQ_TICKER_TYPE
{
	EMQ_TICKER_TYPE_STOCK = 0,            ///<��ͨ��Ʊ
	EMQ_TICKER_TYPE_INDEX,                ///<ָ��
	EMQ_TICKER_TYPE_FUND,                 ///<����
	EMQ_TICKER_TYPE_BOND,                 ///<ծȯ
	EMQ_TICKER_TYPE_OPTION,               ///<��Ȩ
	EMQ_TICKER_TYPE_TECH_STOCK,           ///<�ƴ����Ʊ���Ϻ���
	EMQ_TICKER_TYPE_REPURCHASE,           ///<��Ѻʽ�ع�
	EMQ_TICKER_TYPE_WARRANT,              ///<Ȩ֤
	EMQ_TICKER_TYPE_HKSTOCK,			  ///<�۹�ͨ
	EMQ_TICKER_TYPE_BJGZ,				  ///<��������ת
	EMQ_TICKER_TYPE_UNKNOWN = 100         ///<δ֪����

}EMQ_TICKER_TYPE;

/////////////////////////////////////////////////////////////////////////
///@brief EMQ_QUALIFICATION_TYPE��һ��֤ȯ�ʵ���ö������
/////////////////////////////////////////////////////////////////////////
typedef enum EMQ_QUALIFICATION_TYPE
{
	EMQ_QUALIFICATION_PUBLIC = 0,			///<����Ͷ���ߣ��ϸ�Ͷ���������Ͷ���߾���
	EMQ_QUALIFICATION_COMMON = 1,			///<���ϸ�Ͷ�����빫��Ͷ����
	EMQ_QUALIFICATION_ORGANIZATION = 2,		///<���޻���Ͷ����
	EMQ_QUALIFICATION_UNKNOWN = 3			///<δ֪����Ȩ�ȿ���Ϊ��������
}EMQ_QUALIFICATION_TYPE;


/////////////////////////////////////////////////////////////////////////
///@brief EMQ_SECURITY_TYPE��һ��֤ȯ��ϸ����ö������
/////////////////////////////////////////////////////////////////////////
typedef enum EMQ_SECURITY_TYPE {
	/// �����Ʊ
	EMQ_SECURITY_MAIN_BOARD = 0,
	/// ��С���Ʊ
	EMQ_SECURITY_SECOND_BOARD,
	/// ��ҵ���Ʊ
	EMQ_SECURITY_STARTUP_BOARD,
	/// ָ��
	EMQ_SECURITY_INDEX,
	/// �ƴ����Ʊ(�Ϻ�)
	EMQ_SECURITY_TECH_BOARD = 4,
	/// ��ծ
	EMQ_SECURITY_STATE_BOND = 5,
	/// ��ҵծ
	EMQ_SECURITY_ENTERPRICE_BOND = 6,
	/// ��˾ծ
	EMQ_SECURITY_COMPANEY_BOND = 7,
	/// ת��ծȯ
	EMQ_SECURITY_CONVERTABLE_BOND = 8,
	/// ��ծ��ع�
	EMQ_SECURITY_NATIONAL_BOND_REVERSE_REPO = 12,
	/// ���г���Ʊ ETF
	EMQ_SECURITY_ETF_SINGLE_MARKET_STOCK = 14,
	/// ���г���Ʊ ETF
	EMQ_SECURITY_ETF_INTER_MARKET_STOCK,
	/// ���г�ʵ��ծȯ ETF
	EMQ_SECURITY_ETF_SINGLE_MARKET_BOND = 17,
	/// �ƽ� ETF
	EMQ_SECURITY_ETF_GOLD = 19,
	/// �ּ������ӻ���
	EMQ_SECURITY_STRUCTURED_FUND_CHILD = 24,
	/// ������������
	EMQ_SECURITY_SZSE_RECREATION_FUND = 26,
	/// ������Ȩ
	EMQ_SECURITY_STOCK_OPTION = 29,
	/// ETF��Ȩ
	EMQ_SECURITY_ETF_OPTION = 30,
	/// ���
	EMQ_SECURITY_ALLOTMENT = 100,

	/// �Ͻ��������ͻ��һ���
	EMQ_SECURITY_MONETARY_FUND_SHCR = 110,
	/// �Ͻ��������ͻ��һ���
	EMQ_SECURITY_MONETARY_FUND_SHTR = 111,
	/// ������һ���
	EMQ_SECURITY_MONETARY_FUND_SZ = 112,

	/// ����
	EMQ_SECURITY_OTHERS = 255
}EMQ_SECURITY_TYPE;

/////////////////////////////////////////////////////////////////////////
///@brief RebuildDataType �ؽ���������
/////////////////////////////////////////////////////////////////////////
typedef enum EMQ_REBUILD_DATA_TYPE {
	SZE_ORDER_DATA = 11,								///< ����ί��
	SZE_EXE_DATA = 12,									///< ���гɽ�
	SZE_BOND_ORDER_DATA = 13,							///< ����ծȯί��
	SZE_BOND_EXE_DATA = 14,								///< ����ծȯ�ɽ�
	SSE_ORDER_DATA = 15,								///< ����ί��
	SSE_EXE_DATA = 16,									///< ���гɽ�
	SZE_BOND_TBT_DATA = 17								///< ����ծȯ���
}EMQ_REBUILD_DATA_TYPE;


#pragma pack()

#endif
