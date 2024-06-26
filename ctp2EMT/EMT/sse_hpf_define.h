/*!****************************************************************************
	@file   	sse_hpf_define.h

	@brief		ʢ����������ṹ��
******************************************************************************/
#pragma once
#include <cstring>

#define		SSE_EXCHANGE_ID				(100)

#define        SSE_SYMBOL_LEN                   (9)                     // �Ͻ�����Լ����
#define        SSE_LEV2_DEPTH                   (10)                    // �Ͻ���lev2��λ���
#define        SSE_OPTION_DEPTH                 (5)                     // �Ͻ�����Ȩ��λ���

#define        SSE_SECURITY_NAME_LEN            (9)
#define        SSE_PRODUCT_STATUS_LEN           (21)
#define        DATE_LEN                         (9)

#define		SSE_ORDER_MSG_TYPE			(32)
#define		SSE_INDEX_MSG_TYPE			(33)
#define		SSE_EXECUTION_MSG_TYPE		(34)
#define		SSE_OPTION_MSG_TYPE			(35)
#define		SSE_TREE_MSG_TYPE			(38)
#define		SSE_LEV2_MSG_TYPE			(39)
#define		SSE_BOND_SNAP_MSG_TYPE		(60)
#define		SSE_BOND_TICK_MSG_TYPE		(61)
#define		SSE_LEV2_STATIC_INFO_MSG_TYPE    (255)                   // �Ͻ���lev2��̬��Ϣ����


#define		SSE_HB_TICK_MSG_TYPE		(132)
#define		SSE_HB_INDEX_MSG_TYPE		(133)
#define		SSE_HB_OPTION_MSG_TYPE		(135)
#define		SSE_HB_TREE_MSG_TYPE		(138)
#define		SSE_HB_FULL_MSG_TYPE		(139)
#define		SSE_HB_BOND_MSG_TYPE		(160)		// ծȯlev2��������
#define		SSE_HB_BOND_TICK_MSG_TYPE	(161)		// ծȯ�������

#pragma pack(push, 1)
struct sse_hpf_heartbt_pkt
{
	sse_hpf_heartbt_pkt()
	{
		memset(this, 0, sizeof(sse_hpf_heartbt_pkt));
	}

	unsigned int						m_sequence;						// ȡ��ǰ���ͨ����������Ϣ��SeqNum
	unsigned char						m_reserved_0[4];				// 4���ֽڵı����ֶ�
	unsigned char						m_message_type;					// ���ڸ�ͨ��msgtype+100
	unsigned char						m_reserved_1[7];				// �����ֶ�
};

struct sse_hpf_head
{
	unsigned int						m_sequence;
	unsigned short						m_tick1;
	unsigned short						m_tick2;
	unsigned char						m_message_type;
	unsigned short						m_message_len;		/// ��������Ϣͷ�ĳ���
	unsigned char						m_exchange_id;
	unsigned short						m_quote_date_year;
	unsigned char						m_quote_date_month;
	unsigned char						m_quote_date_day;
	unsigned int						m_send_time;
	unsigned char						m_category_id;
	unsigned int						m_msg_seq_id;
	unsigned char						m_seq_lost_flag;	/// 1=�ж�����0=û�ж���
};

struct px_level
{
	px_level()
	{
		memset(this, 0, sizeof(px_level));
	}
	char								m_lev_operator;
	char								m_resv[3];
	unsigned int						m_px;
	unsigned long long					m_qty;
};
//���ί��
struct sse_hpf_order_pkt
{
	sse_hpf_order_pkt()
	{
		memset(this, 0, sizeof(sse_hpf_order_pkt));
	}
	sse_hpf_head						m_head;

	unsigned int						m_order_index;
	unsigned int						m_channel;
	char								m_symbol[9];
	unsigned int						m_order_time;
	unsigned char						m_order_type;
	unsigned long long					m_order_no;
	unsigned int						m_order_price;
	unsigned long long					m_balance;
	unsigned char						m_reserved_0[15];
	unsigned char						m_order_bs_flag;
	unsigned long long					m_biz_index;
	unsigned char						m_reserved_1[4];
};
//ָ��
struct sse_hpf_index_pkt
{
	sse_hpf_index_pkt()
	{
		memset(this, 0, sizeof(sse_hpf_index_pkt));
	}
	sse_hpf_head						m_head;

	unsigned int						m_quote_update_time;
	char								m_symbol[9];
	unsigned char						m_security_type;			/// 0=ָ���� 10=����
	unsigned int						m_previous_close_price;
	unsigned int 						m_open_price;
	unsigned long long					m_total_value;
	unsigned int						m_day_high;
	unsigned int						m_day_low;
	unsigned int						m_last_price;
	unsigned long long					m_total_quantity;
	unsigned int						m_today_close_price;
};
//��ʳɽ�
struct sse_hpf_exe_pkt
{
	sse_hpf_exe_pkt()
	{
		memset(this, 0, sizeof(sse_hpf_exe_pkt));
	}
	sse_hpf_head						m_head;

	unsigned int						m_trade_index;
	unsigned int						m_channel;
	char								m_symbol[9];
	unsigned int						m_trade_time;
	unsigned int						m_trade_price;
	unsigned long long					m_trade_qty;
	unsigned long long					m_trade_money;
	unsigned long long					m_trade_buy_no;
	unsigned long long					m_trade_sell_no;
	char								m_trade_bs_flag;
	unsigned long long					m_biz_index;
	unsigned int						m_reserved;
};
//��Ȩ
struct stock_option_px_level
{
	stock_option_px_level()
	{
		memset(this, 0, sizeof(stock_option_px_level));
	}
	unsigned int							m_px;
	unsigned long long						m_qty;
};
struct sse_hpf_stock_option
{
	sse_hpf_stock_option()
	{
		memset(this, 0, sizeof(sse_hpf_stock_option));
	}
	sse_hpf_head							m_head;

	unsigned int							m_quote_update_time;
	unsigned char							m_security_type;
	char									m_symbol[9];
	unsigned char							m_image_status;
	unsigned char							m_reserved1;
	unsigned int							m_previous_close_price;
	unsigned int							m_previous_settle_price;
	unsigned int 							m_open_price;
	unsigned int							m_day_high;
	unsigned int							m_day_low;
	unsigned int 							m_last_price;
	unsigned int 							m_today_close_price;
	unsigned int 							m_settle_price;
	unsigned int 							m_dynamic_price;
	unsigned char 							m_reserved2[3];
	unsigned char							m_trading_status;
	unsigned long long						m_open_interest;
	unsigned int							m_num_trades;
	unsigned long long						m_volume;
	unsigned long long						m_turnover;
	unsigned char							m_no_bid_level;
	unsigned char							m_no_offer_level;
	stock_option_px_level					m_bid_px[5];
	stock_option_px_level					m_ask_px[5];
};
//����
struct sse_hpf_lev2_header
{
	sse_hpf_head						m_head;

	unsigned int						m_quote_update_time;
	char								m_symbol[9];
	unsigned char						m_security_type;
	unsigned char						m_data_type;
	unsigned char						m_reserved1;
	unsigned int						m_previous_close_price;
	unsigned int 						m_open_price;
	unsigned int						m_day_high;
	unsigned int						m_day_low;
	unsigned int						m_last_price;
	unsigned int						m_today_close_price;
	unsigned char						m_instrument_status;
	unsigned char						m_trading_status;
	unsigned short						m_reserved2;
	unsigned int						m_total_trade_number;
	unsigned long long					m_total_quantity;
	unsigned long long					m_total_value;

	unsigned long long					m_total_bid_qty;
	unsigned int						m_total_bid_weighted_avg_px;
	unsigned long long					m_total_ask_qty;
	unsigned int						m_total_ask_weighted_avg_px;
	unsigned int						m_yield_to_maturity;
	unsigned char						m_bid_depth;
	unsigned char						m_ask_depth;
};
struct sse_hpf_lev2
{
	sse_hpf_lev2()
	{
		memset(this, 0, sizeof(sse_hpf_lev2));
	}
	sse_hpf_lev2_header					m_lev2_header;
	px_level							m_bid_px[10];
	px_level							m_ask_px[10];
};
//����
struct tree_px_level
{
	tree_px_level()
	{
		memset(this, 0, sizeof(tree_px_level));
	}
	unsigned int							m_px;
	unsigned long long						m_qty;
};
struct sse_hpf_tree_pkt
{
	sse_hpf_head						m_head;
	unsigned int						m_channel_id;
	unsigned int						m_quote_update_time;
	char								m_symbol[9];
	unsigned char						m_security_type;
	unsigned long long					m_biz_index;
	unsigned int						m_previous_close_price;
	unsigned int 						m_open_price;
	unsigned int						m_day_high;
	unsigned int						m_day_low;
	unsigned int						m_last_price;
	unsigned int						m_today_close_price;
	unsigned char						m_instrument_status;
	unsigned char						m_trading_status;
	unsigned char						m_reserved1[6];
	unsigned int						m_total_trade_number;
	unsigned long long					m_total_quantity;
	unsigned long long					m_total_value;
	unsigned long long					m_total_bid_qty;
	unsigned int						m_total_bid_weighted_avg_px;
	unsigned long long					m_total_ask_qty;
	unsigned int						m_total_ask_weighted_avg_px;
	unsigned int						m_yield_to_maturity;
	unsigned char						m_bid_depth;
	unsigned char						m_ask_depth;
	unsigned char						m_reserved2[2];
	tree_px_level						m_bid_px[10];
	tree_px_level						m_ask_px[10];
};

// ծȯ��λ��Ϣ
struct sse_msg_bond_level_unit
{
	unsigned int					m_price;
	unsigned long long 				m_volumn;
};

// ծȯ��������
struct sse_msg_bond_snap_pkt
{
	sse_hpf_head					m_head;
	unsigned int					m_update_time;					// ����ʱ��
	char							m_reserved_0[4];				// �����ֶ�
	char							m_security_id[9];					// ծȯ����
	char							m_secu_type;					// ֤ȯ����
	char							m_sub_secu_type;				// ֤ȯ������
	char							m_reserved_1[3];				// �����ֶ�
	unsigned int					m_pre_close_px;					// ���ռ�
	unsigned int					m_open_px;						// ���̼�
	unsigned int					m_day_high;						// ��߼�
	unsigned int					m_day_low;						// ��ͼ�
	unsigned int					m_last_px;						// �ּ�
	unsigned int					m_close_px;						// �������̼�
	char							m_instrument_status;			// ��ǰƷ�ֽ���״̬
	char							m_reserved_2[3];				// �����ֶ�
	unsigned int					m_trade_num;					// �ɽ�����
	unsigned long long 				m_trade_volumn;					// �ɽ�����
	unsigned long long 				m_trade_value;					// �ɽ��ܽ��
	unsigned long long 				m_total_qty_bid;				// ί�������������֣�
	unsigned int					m_weighted_avg_px_bid;			// ծȯ��Ȩƽ��ί��۸�
	unsigned long long 				m_total_qty_ask;				// ί����������
	unsigned int					m_weighted_avg_px_ask;			// ծȯ��Ȩƽ��ί���۸�
	unsigned int					m_withdraw_buy_number;			// ���볷������
	unsigned long long 				m_withdraw_buy_amount;			// ���볷������
	unsigned long long 				m_withdraw_buy_money;			// ���볷�����
	unsigned int					m_withdraw_sell_number;			// ������������
	unsigned long long 				m_withdraw_sell_amount;			// ������������
	unsigned long long 				m_withdraw_sell_money;			// �����������
	unsigned int					m_total_bid_number;				// �����ܱ���
	unsigned int					m_total_offer_number;			// �����ܱ���
	int								m_bid_trade_max_duration;		// ����ί�гɽ����ȴ�ʱ��
	int								m_offer_trade_max_duration;		// ����ί�гɽ����ȴ�ʱ��
	char							m_bid_depth;					// ����λ��
	char							m_ask_depth;					// ������λ��
	char							m_reserved_3[6];
	sse_msg_bond_level_unit			m_bid_levels[10];				// ������Ϣ
	sse_msg_bond_level_unit			m_offer_levels[10];				// ������Ϣ
};

// ծȯ���
struct sse_msg_bond_tick_pkt
{
	sse_hpf_head					m_head;
	unsigned int					m_tick_index;					// ��ţ���1��ʼ����ͨ������
	unsigned int					m_channel_id;					// ͨ����
	char							m_security_id[9];					// �������
	char							m_secu_type;					// ֤ȯ����
	char							m_sub_secu_type;				// ֤ȯ������
	unsigned int					m_tick_time;					// ������ɽ�ʱ��
	char							m_tick_type;					// ���ͣ� A���������� Dɾ�������� ɾ�������� S��Ʒ״̬������ T�ɽ�
	unsigned long long 				m_buy_order_no;					// �򷽶����ţ��Բ�Ʒ״̬����������
	unsigned long long 				m_sell_order_no;				// ���������ţ��Բ�Ʒ״̬����������
	unsigned int					m_price;						// �۸񣬶Բ�Ʒ״̬����������
	unsigned long long 				m_qty;							// �������֣����Բ�Ʒ״̬����������
	unsigned long long 				m_trade_money;					// �ɽ���Ԫ�����������ڳɽ���Ϣ
	char							m_side_flag;					// ������־����Ϊ������ ������־����Ϊ������ ������־����Ϊ������ ������־����Ϊ������ ������־����Ϊ������ ������־����Ϊ������ ������־����Ϊ������ ������־����Ϊ������ B - �򵥣� S - ��������Ϊ�ɽ��� ��������Ϊ�ɽ��� ��������Ϊ�ɽ��� ��������Ϊ�ɽ��� ��������Ϊ�ɽ��� ��������Ϊ�ɽ��� B - ���̣� ���̣� ������ S - ���̣� ������N - δ֪ ��
	char							m_instrument_status;			// ��Ʊ / ���״̬���������ڲ�Ʒ״̬����
	char							m_reserved[8];					// �����ֶ�
};

struct sse_static_msg_header
{
    unsigned int                    m_seq_num;                          // ��������Ϣ��� ��1��ʼ
    unsigned char                   m_reserved[4];                      // 4���ֽڱ����ֶ�
    unsigned char                   m_msg_type;                         // ��Ϣ����
    unsigned short                  m_msg_body_len;                     // ��Ϣ�峤��
    bool                            m_batch_finish_flag;                // ��ǰ��̬�ļ�������ɱ�־
};

struct sse_static_msg_body
{
    unsigned char                   m_exchange_id;                             // ������id
    char                            m_symbol[SSE_SYMBOL_LEN];                  // ֤ȯ����
    unsigned int                    m_send_time;                               // ���鷢��ʱ�䣬ʱ�������
    char                            m_static_file_date[DATE_LEN];              // ��̬�ļ����ڣ�YYYYMMDD, ��'\0'����
    //�ǵ����������ͣ�******************************************************************************************
    // �� �� (ʮ��������Ϊ32)��ʾ�޶���
    // ��N����ʾ���׹���2013�޶��棩3.4.13�涨�����ǵ����������ͻ���Ȩ֤����취��22���涨
    // ��R����ʾ���׹���2013�޶��棩3.4.15��3.4.16�涨�����ǵ�����������
    // ��S����ʾ�ع��ǵ�����������
    // ��F����ʾ���ڲο��۸���ǵ�������
    // ��P����ʾIPO�������յ��ǵ�����������
    // ��U����ʾ���κμ۸��ǵ�����������
    //******************************************************************************************
    char                            m_price_limit_type;                        // ����ͣ��������
    double                          m_up_limit_price;                          // ��ͣ��
    double                          m_down_limit_price;                        // ��ͣ��
    unsigned long long int          m_bid_qty_unit;                            // ��������λ
    unsigned long long int          m_ask_qty_unit;                            // ��������λ
    unsigned long long int          m_limit_upper_qty;                         // �޼��걨��������
    unsigned long long int          m_limit_lower_qty;                         // �޼��걨��������
    double                          m_price_changge_unit;                      // �걨��С��۵�λ
    unsigned long long int          m_market_upper_qty;                        // �м��걨��������
    unsigned long long int          m_market_lower_qty;                        // �м��걨��������
    char                            m_security_name[SSE_SECURITY_NAME_LEN];    // ֤ȯ���ƣ���'\0'����
    // *******************************************************************************************
    //     ֤ȯ����            ֤ȯ������
    //     0            ָ��   0              ָ��
    //                         255            δ����
    //     1            ��Ʊ   0              ����
    //                         1
    //                         2              ��ҵ��
    //                         3              B��
    //                         4              H��
    //                         5              �ƴ���
    //                         255            δ����
    //     2            ����   248            LOF����
    //                         249            ETF����
    //                         255            δ����
    //     3            ծȯ   248            ��ծ
    //                         249            ��תծ
    //                         255            δ����
    //     4            �ع�   248            ��ծ�ع�
    //                         255            δ����
    //     9            ��Ȩ   248            ��Ʊ��Ȩ
    //                         249            ETF��Ȩ
    //                         255            δ����
    //     10           ����
    // *******************************************************************************************
    unsigned char                   m_ssecurity_type;                          // ֤ȯ����
    unsigned char                   m_sub_ssecurity_type;                      // ֤ȯ������
    char                            m_finance_target_mark;                     // ���ʱ�ı�־ �� �� (ʮ��������Ϊ32)��ʾ�޶���,��T����ʾ�����ʱ��֤ȯ,��F����ʾ�������ʱ��֤ȯ��
    char                            m_ssecurity_target_mark;                   // ��ȯ��ı�־ �� �� (ʮ��������Ϊ32)��ʾ�޶���,��T����ʾ�����ʱ��֤ȯ,��F����ʾ�������ʱ��֤ȯ��
    char                            m_product_status[SSE_PRODUCT_STATUS_LEN];  // ��Ʒ״̬, ��'\0'����
    char                            m_listing_date[DATE_LEN];                  // �������ڣ���ʽΪYYYYMMDD, ��'\0'����
};

struct sse_static_msg
{
    sse_static_msg_header           m_header;
    sse_static_msg_body             m_body;
};

#pragma pack(pop)
