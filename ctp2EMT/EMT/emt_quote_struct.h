#pragma once
/////////////////////////////////////////////////////////////////////////
///@author �����Ƹ�֤ȯ�ɷ����޹�˾
///@file emt_quote_struct.h
///@brief ��������ҵ�����ݽṹ
/////////////////////////////////////////////////////////////////////////

#ifndef __EMT_MARKETDATA_H__
#define __EMT_MARKETDATA_H__ extern "C" _declspec(dllimport)
#include <cstdint>
#include <cinttypes>

#include "emt_quote_data_type.h"
#include "sse_hpf_define.h"
#include "sze_hpf_define.h"

#pragma pack(1)  // �ڴ���1�ֽ�Ϊ��λ����

#define MAX_LEVEL_NUM 10         /// �������������
#define MAX_LEVEL_ORDERS_NUM 50  /// ����λ��ʾί�б���
#define EMQ_ERR_MSG_LEN 124      /// ������Ϣ���ַ�������

/// ָ���ĺ�Լ
struct _EMTSpecificTickerStruct {
  /// ����������
  EMQ_EXCHANGE_TYPE exchange_id;
  /// ��Լ���루��������������Ϣ������"600000"�������ո���'\0'��β
  char ticker[EMQ_TICKER_LEN];
};
using EMTSpecificTickerStruct = struct _EMTSpecificTickerStruct;

/// ָ������ṹ��
struct _EMTIndexDataStruct {
  /// ����������
  EMQ_EXCHANGE_TYPE exchange_id;
  /// ��Լ����(��������������Ϣ)�������ո���"\0"��β
  char ticker[EMQ_TICKER_LEN];
  /// ����ʱ�䣬��ʽΪYYYYMMDDHHMMSSssss
  int64_t data_time;
  /// �������̼�
  double pre_close_price;
  /// ���տ��̼�
  double open_price;
  /// ���¼�
  double last_price;
  /// ��߼�
  double high_price;
  /// ��ͼ�
  double low_price;
  /// ������Ϊ�ܳɽ���(��λ�ɣ��뽻����һ��)
  int64_t qty;
  /// �ɽ���Ϊ�ܳɽ����(��λԪ���뽻����һ��)
  double turnover;
};
using EMTIndexDataStruct = struct _EMTIndexDataStruct;

/// ����������ݽṹ��
struct _EMTMarketDataFundExData {
  /// ����ʵʱ�ο���ֵ(SH,SZ)
  double iopv;
  /// ETF�깺����(SH)
  int32_t etf_buy_count;
  /// ETF��ر���(SH)
  int32_t etf_sell_count;
  /// ETF�깺����(SH)
  double etf_buy_qty;
  /// ETF�깺���(SH)
  double etf_buy_money;
  /// ETF�������(SH)
  double etf_sell_qty;
  /// ETF��ؽ��(SH)
  double etf_sell_money;
  /// ����T-1�վ�ֵ(SZ)
  double pre_iopv;
};
using EMTMarketDataFundExData = struct _EMTMarketDataFundExData;

/// ծȯ�������ݽṹ��
struct _EMTMarketDataBondExData {
  /// ծȯ��Ȩƽ��ί��۸�(SH)
  double ma_bond_bid_price;
  /// ծȯ��Ȩƽ��ί���۸�(SH)
  double ma_bond_ask_price;
  /// ծȯ����������(SH)
  double yield_to_maturity;
};
using EMTMarketDataBondExData = struct _EMTMarketDataBondExData;

/// Ȩ֤��������
struct _EMTMarketDataWarrantExData {
  /// Ȩִ֤�е�������(SH)
  double total_warrant_exec_qty;
  /// Ȩ֤��ͣ�۸�Ԫ��(SH)
  double warrant_lower_price;
  /// Ȩ֤��ͣ�۸�Ԫ��(SH)
  double warrant_upper_price;
};

using EMTMarketDataWarrantExData = struct _EMTMarketDataWarrantExData;

/// ��Ȩ��������
struct _EMTMarketDataOptionExData {
  /// �������жϲο���(SH)
  double auction_price;
  /// �������жϼ��Ͼ�������ƥ����(SH)
  int64_t auction_qty;
  /// ���ѯ��ʱ��(SH)
  int64_t last_enquiry_time;

  // ��Ȩ����
  /// ���ճֲ���(��)(Ŀǰδ��д)
  int64_t pre_total_long_positon;
  /// �ֲ���(��)(Ŀǰδ��д)
  int64_t total_long_positon;
  /// ���ս����(Ŀǰδ��д)
  double pre_settl_price;
  /// ���ս����(Ŀǰδ��д)
  double settl_price;
};

using EMTMarketDataOptionExData = struct _EMTMarketDataOptionExData;

/// �۹�ͨ������չ����
struct _EMTMarketDataHkExData {
  /// �ο���
  double refer_price;
  /// ���̼�
  double nominal_price;
  /// �������޼�
  double buyside_up_limit_price;
  /// �������޼�
  double buyside_low_limit_price;
  /// �������޼�
  double sellside_up_limit_price;
  /// �������޼�
  double sellside_low_limit_price;
  /// �侲�ڿ�ʼʱ��  HHmmssSSS
  int32_t complex_event_start_time;
  /// �侲�ڽ���ʱ�� HHmmssSSS
  int32_t complex_event_end_time;
};

using EMTMarketDataHkExData = struct _EMTMarketDataHkExData;

/// ��������ת������չ����
struct _EMTMarketDataBJGZExData {
  /// ��̬��ӯ��
  double LYR;
  /// ��̬��ӯ��
  double TTM;
  /// �۸�����һ ���������̼��ǵ�
  double price_change1;
  /// �۸��ǵ��� ����һ�ʳɽ��ǵ�
  double price_change2;
  /// ��Լ�ֲ���
  int64_t open_interest;
  /// ��һλ char ����״̬��N����ʾ����״̬����Y��
  /// ��ʾ���չ���/���У���D����ʾ������Ʊ���ף���I����ʾѯ�ۣ���F����ʾ�깺 �ڶ�λ
  /// char ֤ȯ����
  /// ��T����ʾ��Ӧ֤ȯ�ǹ���/���й�˾��Ʊ����B����ʾ��Ӧ֤ȯ��������˾�����й�˾��Ʊ����O����ʾ��Ӧ֤ȯ�ǽ��ṩ��Ȩ���ܵ���Ȩ����P����ʾ��Ӧ֤ȯ�ǳ�����������
  /// 200 �����Ƶ�֤ȯ;(���ȹ�)��R����ʾ��Ӧ֤ȯ���������͵�ҵ��
  ///    ��F����ʾ�Ƿ���ҵ��;��C����ʾ��Ӧ֤ȯ���ṩЭ��ת�õĿ�ת����˾ծȯ��
  /// ����λ char ��������  ��T����ʾЭ�齻�׷�ʽ�� *
  /// ��M����ʾ���н��׷�ʽ����B����ʾ���Ͼ���+�������۽��׷�ʽ�� *
  /// ��C����ʾ���Ͼ��۽��׷�ʽ����P����ʾ���з�ʽ����O����ʾ�������͡� ����λ char  *
  /// ͣ�Ʊ�־  *
  /// ��F����ʾ�������ף���T����ʾͣ�ƣ��������걨����H����ʾͣ�ƣ������걨�� ����λ
  /// char
  /// ��0��-�����㣬��1��-���²㣬��2��-���������������ȹɡ���תծ��ָ�������г��㼶�ģ����ֶ���ո�(Ԥ��)
  char ticker_relevant_info[8];
};
using EMTMarketDataBJGZExData = struct _EMTMarketDataBJGZExData;

/// ��������ṹ��

struct _EMTMarketDataStruct {
  /// ����������
  EMQ_EXCHANGE_TYPE exchange_id;
  /// ��Լ����(��������������Ϣ)�������ո���"\0"��β
  char ticker[EMQ_TICKER_LEN];

  // �۸�
  /// ���¼�
  double last_price;
  /// �������̼�
  double pre_close_price;
  /// ���̼�
  double open_price;
  /// ��߼�
  double high_price;
  /// ��ͼ�
  double low_price;
  /// �����̼�(SH)
  double close_price;

  // �ǵ�ͣ
  /// ��ͣ��(SZ)
  double upper_limit_price;
  /// ��ͣ��(SZ)
  double lower_limit_price;
  /// ����ʱ�䣬��ʽΪYYYYMMDDHHMMSSssss
  int64_t data_time;

  // ��������
  /// ������Ϊ�ܳɽ���(��λ�ɣ��뽻����һ��)
  int64_t qty;
  /// �ɽ���Ϊ�ܳɽ����(��λԪ���뽻����һ��)
  double turnover;
  /// ���վ���=(turnover/qty)
  double avg_price;

  // ������
  /// ʮ�������
  double bid[10];
  /// ʮ��������
  double ask[10];
  /// ʮ��������
  int64_t bid_qty[10];
  /// ʮ��������
  int64_t ask_qty[10];

  /// �ɽ�����
  int64_t trades_count;
  /// ��ǰ����״̬˵��(SH)
  char ticker_status[8];

  /// ί����������(SH,SZ)
  int64_t total_bid_qty;
  /// ί����������(SH,SZ)
  int64_t total_ask_qty;
  /// ��Ȩƽ��ί��۸�(SH,SZ)
  double ma_bid_price;
  /// ��Ȩƽ��ί���۸�(SH,SZ)
  double ma_ask_price;

  /// ���볷������(SH)
  int32_t cancel_buy_count;
  /// ������������(SH)
  int32_t cancel_sell_count;
  /// ���볷������(SH)
  double cancel_buy_qty;
  /// ������������(SH)
  double cancel_sell_qty;
  /// ���볷�����(SH)
  double cancel_buy_money;
  /// �����������(SH)
  double cancel_sell_money;
  /// �����ܱ���(SH)
  int64_t total_buy_count;
  /// �����ܱ���(SH)
  int64_t total_sell_count;
  /// ����ί�гɽ����ȴ�ʱ��(SH)
  int32_t duration_after_buy;
  /// ����ί�гɽ����ȴ�ʱ��(SH)
  int32_t duration_after_sell;
  /// ��ί�м�λ��(SH)
  int32_t num_bid_orders;
  /// ����ί�м�λ��(SH)
  int32_t num_ask_orders;
  ///  ��������������
  union {
    /// ծȯ��������
    EMTMarketDataBondExData bond;
    /// �����������
    EMTMarketDataFundExData fund;
    /// Ȩ֤��������
    EMTMarketDataWarrantExData warrant;
    /// ��Ȩ��������
    EMTMarketDataOptionExData opt;
    /// �۹ɶ�������
    EMTMarketDataHkExData hk;
    /// ��������ת��������
    EMTMarketDataBJGZExData bjgz;
  };
  /// ֤ȯ���1����Ʊ,����,ծȯ,Ȩ֤,��Ѻʽ�ع���2����Ȩ��������union��������������
  EMQ_TICKER_TYPE data_type;
};
using EMTMarketDataStruct = struct _EMTMarketDataStruct;

/// ��Ʊ���龲̬��Ϣ
struct _EMTQuoteStaticInfo {
  /// ����������
  EMQ_EXCHANGE_TYPE exchange_id;
  /// ��Լ���루��������������Ϣ���������ո���'\0'��β
  char ticker[EMQ_TICKER_LEN];
  /// ��Լ����
  char ticker_name[EMQ_TICKER_NAME_LEN];
  /// ��Լ����
  EMQ_TICKER_TYPE ticker_type;
  /// ������
  double pre_close_price;
  /// ��ͣ���
  double upper_limit_price;
  /// ��ͣ���
  double lower_limit_price;
  /// ��С�䶯��λ
  double price_tick;
  /// ��Լ��С������(��)
  int32_t buy_qty_unit;
  /// ��Լ��С������(��)
  int32_t sell_qty_unit;
};
using EMTQuoteStaticInfo = struct _EMTQuoteStaticInfo;

/// ��Ʊ����ȫ����̬��Ϣ
using EMTQuoteFullInfo = struct _EMTQuoteFullInfo {
  /// ����������
  EMQ_EXCHANGE_TYPE exchange_id;
  /// ֤ȯ����
  char ticker[EMQ_TICKER_LEN];
  /// ֤ȯ����
  char ticker_name[EMQ_TICKER_NAME_LEN];
  /// ��Լ��ϸ����
  EMQ_SECURITY_TYPE security_type;
  /// ��Լ�ʵ������
  EMQ_QUALIFICATION_TYPE ticker_qualification_class;
  /// �Ƿ�ע����(�����ô�ҵ���Ʊ��������ҵ��Ʊ������ƾ֤)
  bool is_registration;
  /// �Ƿ����Э����Ƽܹ�(�����ô�ҵ���Ʊ��������ҵ��Ʊ������ƾ֤)
  bool is_VIE;
  /// �Ƿ���δӯ��(�����ô�ҵ���Ʊ��������ҵ��Ʊ������ƾ֤)
  bool is_noprofit;
  /// �Ƿ����ͶƱȨ����(�����ô�ҵ���Ʊ��������ҵ��Ʊ������ƾ֤)
  bool is_weighted_voting_rights;
  /// �Ƿ����ǵ�������(ע�����ṩ������ȣ���ͨ���ǵ�ͣ�ۺ����ռ����������)
  bool is_have_price_limit;
  /// ��ͣ�ۣ��������ǵ�������ʱ��Ч��
  double upper_limit_price;
  /// ��ͣ�ۣ��������ǵ�������ʱ��Ч��
  double lower_limit_price;
  /// ���ռ�
  double pre_close_price;
  /// �۸���С�䶯��λ
  double price_tick;
  /// �޼���ί����������
  int32_t bid_qty_upper_limit;
  /// �޼���ί����������
  int32_t bid_qty_lower_limit;
  /// �޼���������λ
  int32_t bid_qty_unit;
  /// �޼���ί����������
  int32_t ask_qty_upper_limit;
  /// �޼���ί����������
  int32_t ask_qty_lower_limit;
  /// �޼���������λ
  int32_t ask_qty_unit;
  /// �м���ί����������
  int32_t market_bid_qty_upper_limit;
  /// �м���ί����������
  int32_t market_bid_qty_lower_limit;
  /// �м���������λ
  int32_t market_bid_qty_unit;
  /// �м���ί����������
  int32_t market_ask_qty_upper_limit;
  /// �м���ί����������
  int32_t market_ask_qty_lower_limit;
  /// �м���������λ
  int32_t market_ask_qty_unit;
  /// �����ֶ�
  uint64_t unknown[4];
};

/// ���¼�
struct _EMTTickerPriceInfo {
  /// ����������
  EMQ_EXCHANGE_TYPE exchange_type;
  /// ��Լ���루��������������Ϣ���������ո���'\0'��β
  char ticker[EMQ_TICKER_LEN];
  /// ���¼�
  double last_price;
};
using EMTTickerPriceInfo = struct _EMTTickerPriceInfo;

/// �۹ɾ�̬��Ϣ����
struct _EMTHKStaticInfo {
  /// ����������
  EMQ_EXCHANGE_TYPE exchange_type;

  /// ֤ȯ����
  EMQ_TICKER_TYPE ticker_type;

  /// ��Լ���루��������������Ϣ���������ո���'\0'��β
  char ticker[EMQ_HK_TICKER_LEN];

  /// ISIN ����
  char isin_ticker[EMQ_TICKER_LEN];

  /// Ӣ��֤ȯ�����
  char short_form_ticke_en[EMQ_TICKER_LEN];

  /// �г�����
  // MAIN- ���� GEM-��ҵ��
  // ETS-���佻��֤ȯ NASD-Nasdaq AMX �г�
  char market_type[4];

  /// ֤ȯ���
  /// BOND	Bond ծȯ
  /// BWRT	Basket Warrant һ����Ȩ֤
  /// EQTY	Equity  �ɱ�
  /// TRST	Trust  ����
  /// WRNT	Warrant  Ȩ֤
  char symbol_type[4];

  /// ����֤ȯ����  Ȩ֤�����ɴ���
  char assist_symbol[5];

  /// ��������
  /// �۱ң�HKD�� ��Ԫ��USD������ң�CNY���ıң�AUD���ӱң�CAD ;
  /// ��Բ��JPY;�¼��±ң�SGD ; Ӣ�� : GBP ; ŷԪ��EUR
  char currency_type[3];

  /// ���ҵ�λ
  /// ���ҵ�λ��ʾǰ���̼۸��ֶεĵ�λ�������ҵ�λȡֵΪ 0
  /// ʱ��ǰ���̼۸�=ǰ���̼۸��ֶ�ȡֵ��10 �� 0 ���ݣ������ҵ�λȡֵΪ 1
  /// ʱ��ǰ���̼۸�=ǰ���̼۸��ֶ�ȡֵ��10 �� 1 ���ݣ��������ơ�
  char currency_unit;

  /// ��ֵ�������� �۱ң�HKD�� ��Ԫ��USD������ң�CNY
  char currency_denomination_type[3];

  /// �����ֶ�
  char reserved1[4];

  /// �������� YYYYMMDD
  char issueDate[8];

  /// ������λ
  /// ������
  /// �����걨���������Ǹ��ֶε���������
  int32_t round_lot;

  /// �����ֶ�
  char reserved2[4];

  /// ��ֵ ��Ʊ��ֵ ��λ��Ԫ
  double denomination;

  /// ��Ϣ  ����ծȯ��д��������Ϣ �������Ϣͨ�� CCASS ϵͳ�������ծȯ
  double interest;

  /// ǰ���̼� ���ճ�Ȩ��Ϣ�������̼۸�
  double pre_close_price;

  ///  �����ֶ�
  char reserverd3[16];

  /// ��һλ��ЧY��ʾͣ�� N��ʾ��ͣ��
  /// �ڶ�λ��Ч Y��ʾ�����г��������ڻ��� N��ʾ������
  /// ����λ��Ч Y��ʾ�������о��۽���ʱ�� N��ʾ������
  /// ����λ��Ч Y��ʾ���뿪��ǰʱ���Ż� N��ʾ������
  /// ��������λ��Ч �۲����,������λ���㡣
  /// ��������λ��Ч �г��������ڻ������
  char text[64];

  /// ����֤ȯ��� GBK����
  char ticker_name_zh[64];

  /// Ӣ��֤ȯȫ��
  char ticker_name_en[64];
};
using EMTHKStaticInfo = struct _EMTHKStaticInfo;

/// ��ת��̬��Ϣ����
struct _EMTBJGZStaticInfo {
  /// ����������
  EMQ_EXCHANGE_TYPE exchange_type;
  /// ֤ȯ����
  EMQ_TICKER_TYPE ticker_type;
  /// ��Լ���루��������������Ϣ���������ո���'\0'��β
  char ticker[8];
  /// char[8] ֤ȯ��� GBK
  char ticker_name[8];
  /// char[6]  ��ҵ����
  /// ���ڹ�Ʊ����ߵ�һλΪ��ĸ����ʾ���ࣻ��ߵڶ�����λΪ���֣���ʾ���ࣻ����λΪ�ա�
  /// ���嶨����μ��й�֤���䲼�ġ����й�˾��ҵ����ָ����
  char industry_type[6];
  /// char[2]
  /// �������࡮00������ң���02����Ԫ
  char currency_type[2];
  /// double ��ֵ
  /// ���ڹ�Ʊ��ÿ����ֵΪ 1Ԫ�����ڿ�תծ��ÿ����ֵΪ 100 Ԫ
  double denomination;
  /// int64 �ܹɱ�
  int64_t total_share_capital;
  /// int64 �����۹ɱ�
  int64_t nonrestricted_share_capital;
  /// double ����ÿ������
  /// ���ڹ�Ʊ���������ÿ������
  double last_year_eps;
  ///  double ����ÿ������  Ԥ��
  double this_year_eps;
  /// double ���ַ���
  /// Ϊȫ����ת��˾��������������ȡ����Ͷ���ߴ��յĽ��׷��÷��ʣ��÷��ʽ�Ϊ�ο���ʵ�ʷ���������շѹ���涨Ϊ׼
  double transaction_rate;
  /// double ӡ��˰��
  double stamp_duty_rate;
  /// double ��������
  double transfer_rate;
  /// int32 �������� CCYYMMDD
  int32_t list_date;
  /// int32  ��Ϣ�� CCYYMMDD
  /// �������ȹɺͿ�תծ�����ֶδ������Ϣ�գ�����ҪԼҵ�񣬸��ֶδ����ҪԼ��ʼ���ڣ����ڷ���ҵ�񣬸��ֶδ����ѯ�ۿ�ʼ����
  int32_t start_date;
  /// int32 ������ CCYYMMDD
  /// ����ҪԼҵ�񣬸��ֶδ����ҪԼ�������ڣ����ڷ���ҵ�񣬸��ֶδ����ѯ�۽�������
  int32_t end_date;
  /// int32  ÿ������ �걨��������
  int32_t declare_upper_limit;
  /// int32 ��������λ
  int32_t buy_quantity_unit;
  /// int32 ��������λ
  int32_t sell_quantity_unit;
  /// int32 ��С�걨����
  /// ��ų�������������Ͷ��������������ʱ�ε�ÿ����С�걨����
  int32_t min_declare_count;
  /// int32 �޼۲�������
  /// 0 ��ʾ �޼۲�����ֵΪ�۸�1 Ϊ������
  int32_t param_type;
  /// double �۸�λ
  /// �걨�۸����С�䶯��λ������ 0.01 Ԫ RMB��
  double tick_size;
  /// double �ױʽ����޼۲���
  /// ����ο��������ӿ��ĵ�
  double first_trade_limit_price_param;
  /// double ���������޼۲���
  /// ����ο��������ӿ��ĵ�
  double sub_trade_limit_price_param;
  /// double ��ͣ�۸�
  /// Ϊ�걨��Ч�۸�Χ�ļ۸����ޣ���� =99999.99������Ϊ����ң���
  /// 99999.999������Ϊ��Ԫ��������Ӧ��֤ȯû���Ƿ����ơ�����ҪԼҵ�񣬴�����չ�/�ع��۸�
  double upper_limit_price;
  /// double ��ͣ�۸�
  /// Ϊ�걨��Ч�۸�Χ�ļ۸�����
  /// ���=0.000������Ӧ��֤ȯû�е������ơ�����ҪԼҵ�񣬴�����չ�/�ع��۸�
  double lower_limit_price;
  /// double �ۺϱ���
  /// �������ȹɣ����ֶδ����Ʊ���Ϣ�ʣ�%�������ڿ�תծ�����ֶδ��Ʊ�����ʣ�%����
  double conv_ratio;
  /// char �ɷֹɱ�־ Ԥ��
  char constituent_stock_flag;
  /// char ����״̬
  /// ��N����ʾ����״̬����Y����ʾ���չ���/���У���D����ʾ������Ʊ���ף���I����ʾѯ�ۣ���F����ʾ�깺
  char trade_status;
  /// char ֤ȯ����
  /// ��T����ʾ��Ӧ֤ȯ�ǹ���/���й�˾��Ʊ����B����ʾ��Ӧ֤ȯ��������˾�����й�˾��Ʊ��
  /// ��O����ʾ��Ӧ֤ȯ�ǽ��ṩ��Ȩ���ܵ���Ȩ����P����ʾ��Ӧ֤ȯ�ǳ����������� 200
  /// �����Ƶ�֤ȯ;(���ȹ�) ��R����ʾ��Ӧ֤ȯ���������͵�ҵ��
  /// ��F����ʾ�Ƿ���ҵ��;��C����ʾ��Ӧ֤ȯ���ṩЭ��ת�õĿ�ת����˾ծȯ��
  char symbol_type;
  ///  char ��������
  /// ��T����ʾЭ�齻�׷�ʽ��
  /// ��M����ʾ���н��׷�ʽ����B����ʾ���Ͼ���+�������۽��׷�ʽ��
  /// ��C����ʾ���Ͼ��۽��׷�ʽ����P����ʾ���з�ʽ����O����ʾ�������͡�
  char trade_type;
  /// char ͣ�Ʊ�־
  /// ��F����ʾ�������ף���T����ʾͣ�ƣ��������걨����H����ʾͣ�ƣ������걨��
  char suspend_flag;
  ///  char ��Ȩ��Ϣ��־
  /// ��N����ʾ����״̬����E����ʾ��Ȩ����D����ʾ��Ϣ����A����ʾ��Ȩ��Ϣ��
  char ex_divide_flag;
  /// char ����ͶƱ��־ Ԥ��
  char network_note_flag;
  /// char �г��㼶
  /// ��0��-�����㣬��1��-���²㣬��2��-���������������ȹɡ���תծ��ָ�������г��㼶�ģ����ֶ���ո�(Ԥ���ֶ�)
  char market_level;
  ///  char[2] ���׳��� Ԥ��
  char trading_ring[2];
  /// char �Ƿ�Ϊ���ʱ�� (Ԥ���ֶ�)
  /// ��Y��-�ǣ���N��-��
  char is_financing;
  /// char �Ƿ�Ϊ��ȯ��� (Ԥ���ֶ�)
  /// ��Y��-�ǣ���N��-��
  char is_securities_loan;
  /// char �Ƿ��տ����� (Ԥ���ֶ�)
  /// ��Y��-�ǣ���N��-��
  char is_financing_today;
  /// char �Ƿ��տ���ȯ (Ԥ���ֶ�)
  /// ��Y��-�ǣ���N��-��
  char is_securities_loan_today;
  /// Ԥ���ֶ�
  char reserved[2];
  /// int32���׵�λ �걨�����ĵ�λ
  int32_t trade_unit;
  /// char[4] ����ҵ��״̬
  /// ���������NQXX�ӿ��ĵ�
  char other_status[4];

  /// int32 ����������
  /// �������������ṩ���з����֤ȯ��ʾ������������������û���������ṩ���з����֤ȯ���ֶε�ֵĬ��Ϊ
  /// 0
  int32_t market_maker_count;
  /// int32
  /// ��¼����ʱ�� HHMMSS
  int32_t update_time;
  /// double ���ڽ��׼۸����� Ԥ��
  double block_trade_upper_limit_price;
  /// double ���ڽ��׼۸����� Ԥ��
  double block_trade_lower_limit_price;
};
using EMTBJGZStaticInfo = struct _EMTBJGZStaticInfo;

/// ����ؽ�����
struct _EMTRebuildData {
  union {
    sze_hpf_order_pkt sz_order;            /// /**< �������ί��*/
    sze_hpf_exe_pkt sz_exe;                /// /**< ������ʳɽ�*/
    sze_hpf_bond_order_pkt sz_bond_order;  /// /**< ����ծȯ���ί��*/
    sze_hpf_bond_exe_pkt sz_bond_exe;      /// /**< ����ծȯ��ʳɽ�*/

    sse_hpf_order_pkt sh_order;          /// /**< �������ί��*/
    sse_hpf_exe_pkt sh_exe;              /// /**< ������ʳɽ�*/
    sse_msg_bond_tick_pkt sh_bond_tick;  /// /**< ����ծȯ���*/
  };
};
using EMTRebuildData = struct _EMTRebuildData;

struct _EMTRebuildRespData {
  int8_t data_type;
  uint16_t channel;
  uint64_t sequence;
  uint64_t request_id;
  EMTRebuildData* data;
};
using EMTRebuildRespData = struct _EMTRebuildRespData;

/// ��Ӧ����ṹ��
struct _EMTRspInfoStruct {
  /// �������
  int32_t error_id;
  /// ������Ϣ
  char error_msg[EMQ_ERR_MSG_LEN];
};
using EMTRspInfoStruct = struct _EMTRspInfoStruct;

#pragma pack()  // �ָ�Ĭ���ڴ���뷽ʽ

#endif  // !__EMT_MARKETDATA_H__