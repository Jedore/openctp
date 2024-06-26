/*!
* @file   	sze_hpf_define.h
* @brief	ʢ��������������ṹ��
**/
#pragma once
#include <cstring>

#define		SZE_EXCHANGE_ID				(101)

#define		SZE_REPLACE_MSG_TYPE		(21)
#define		SZE_IDX_MSG_TYPE			(22)
#define		SZE_ORDER_MSG_TYPE			(23)
#define		SZE_EXECUTION_MSG_TYPE		(24)
#define		SZE_AFTER_MSG_TYPE			(25)					/// �̺󶨼ۿ���	sze_2_3_2
#define		SZE_TREE_MSG_TYPE			(29)
#define		SZE_IBR_TREE_MSG_TYPE       (28)                    // ���IBR��������
#define		SZE_TURNOVER_MSG_TYPE       (26)                    // ����ɽ���ͳ�ƿ���
#define		SZE_BOND_SNAP_MSG_TYPE      (80)                    // ���ծȯ������Ϣ����
#define		SZE_BOND_ORDER_MSG_TYPE     (81)                    // ���ծȯ���ί����Ϣ����
#define		SZE_BOND_EXE_MSG_TYPE       (82)                    // ���ծȯ��ʳɽ���Ϣ����


#define		SZE_LEV2_DEPTH              (10)                    // ����������
#define		IBR_DEPTH					(5)

#define		SZE_HB_LEV2_SNAPSHOT_MSG_TYPE	(121)
#define		SZE_HB_IDX_MSG_TYPE				(122)
#define		SZE_HB_ORDER_MSG_TYPE			(123)
#define		SZE_HB_AFTER_MSG_TYPE			(125)
#define		SZE_HB_TURNOVER_MSG_TYPE		(126)
#define		SZE_HB_IBR_MSG_TYPE				(128)
#define		SZE_HB_LEV2_TREE_MSG_TYPE		(129)
#define		SZE_HB_BOND_SNAP_MSG_TYPE   	(180)				// ���ծȯ����������Ϣ����,api�ڲ�����
#define		SZE_HB_BOND_TICK_MSG_TYPE   	(181)				// ���ծȯ���������Ϣ����,api�ڲ�����


#pragma pack(push, 1)
struct sze_hpf_heartbeat_pkt
{
	sze_hpf_heartbeat_pkt()
	{
		memset(this, 0, sizeof(*this));
	}

	unsigned int						m_sequence;
	unsigned short						m_tick1;
	unsigned short						m_tick2;
	unsigned char						m_msg_type;
	unsigned char						m_reserved[7];
};

struct px_qty_unit
{
	unsigned int						m_price;
	long long							m_qty;
};

struct sze_hpf_pkt_head
{
	int									m_sequence;
	short								m_tick1;
	short								m_tick2;
	unsigned char						m_msg_type;
	unsigned char						m_security_type;
	unsigned char						m_sub_security_type;
	char								m_symbol[9];
	unsigned char						m_exchange_id;
	long long							m_quote_update_time;
	unsigned short						m_channel_no;
	long long							m_sequence_num;
	unsigned int 						m_md_stream_id;
};

struct sze_hpf_lev2_pkt
{
	sze_hpf_pkt_head					m_header;
	unsigned char 						m_trade_phase_code;
	long long							m_trade_num;
	long long							m_total_qty;
	long long							m_total_value;
	unsigned int						m_pre_close_price;
	unsigned int						m_last_price;
	unsigned int						m_open_price;
	unsigned int						m_day_high;
	unsigned int						m_day_low;
	unsigned int						m_today_close_price;
	unsigned int						m_total_bid_wvp;
	long long							m_total_bid_qty;
	unsigned int						m_total_ask_wvp;
	long long							m_total_ask_qty;
	unsigned int 						m_lpv;
	unsigned int 						m_iopv;
	unsigned int						m_upper_limit_price;
	unsigned int						m_low_limit_price;
	unsigned int 						m_open_interest;
	px_qty_unit							m_bid_unit[10];
	px_qty_unit							m_ask_unit[10];
};

struct sze_hpf_idx_pkt
{
	sze_hpf_pkt_head					m_header;
	long long							m_trade_num;
	long long							m_total_qty;
	long long							m_total_value;
	unsigned int						m_last_price;
	unsigned int						m_pre_close_price;
	unsigned int						m_open_price;
	unsigned int						m_day_high;
	unsigned int						m_day_low;
	unsigned int 						m_close_price;
	char								m_resv[5];
};

struct sze_hpf_order_pkt
{
	sze_hpf_pkt_head					m_header;
	unsigned int						m_px;
	long long							m_qty;
	char								m_side;
	char								m_order_type;
	char								m_resv[15];
};

struct sze_hpf_exe_pkt
{
	sze_hpf_pkt_head					m_header;
	long long							m_bid_app_seq_num;
	long long							m_ask_app_seq_num;
	unsigned int						m_exe_px;
	long long							m_exe_qty;
	char								m_exe_type;
};

struct sze_hpf_tree_pkt
{
	sze_hpf_pkt_head					m_header;
	long long							m_trade_num;
	unsigned long long					m_total_qty;
	long long							m_total_value;
	unsigned int						m_pre_close_price;
	unsigned int						m_last_price;
	unsigned int						m_open_price;
	unsigned int						m_day_high;
	unsigned int						m_day_low;
	unsigned int						m_today_close_price;
	unsigned int						m_total_bid_wvp;
	unsigned long long					m_total_bid_qty;
	unsigned int						m_total_ask_wvp;
	unsigned long long					m_total_ask_qty;
	unsigned int						m_upper_limit_price;
	unsigned int						m_low_limit_price;
	unsigned long long					m_market_open_total_bid;
	unsigned long long					m_market_open_total_ask;
	unsigned int						m_total_lev2_bid;
	unsigned int						m_total_lev2_ask;
	px_qty_unit							m_bid_unit[10];
	px_qty_unit							m_ask_unit[10];
	char								m_ch_gap_flag;
	char								m_resv[4];
};

//�̺󶨼ۣ�2.3.2
struct sze_hpf_after_pkt
{
	sze_hpf_pkt_head					m_header;
	unsigned char						m_trading_phase_code;
	long long							m_trade_num;
	unsigned long long int				m_total_qty;
	unsigned long long int				m_total_value;
	unsigned int						m_pre_close_price;
	unsigned int						m_exe_price;
	unsigned long long int				m_bid_qty;
	unsigned long long int				m_ask_qty;
	char								m_resv[4];
};

//�ɽ���ͳ��sze3.0
struct sze_hpf_turnover_pkt
{
	sze_hpf_pkt_head					m_header;
	unsigned char						m_trading_phase_code;
	long long							m_prev_close_px;
	long long							m_num_trade;
	unsigned long long					m_total_volumn_trade;
	unsigned long long					m_total_value_trade;
	unsigned int						m_stock_num;
};

// ibr_tree
struct sze_hpf_ibr_tree_pkt
{
	sze_hpf_pkt_head					m_header;
	unsigned int						m_total_bid_weighted_avgPx;
	unsigned long long					m_total_bid_qty;
	unsigned int						m_total_ask_weighted_avgPx;
	unsigned long long					m_total_ask_qty;
	unsigned int						m_total_level_bid;
	unsigned int						m_total_level_ask;
	px_qty_unit							m_bid_unit[IBR_DEPTH];
	px_qty_unit							m_ask_unit[IBR_DEPTH];
	char								m_reserved[5];
};



// ���ȫ�¿�����Ϣ
struct sze_hpf_bond_snap_pkt
{
	sze_hpf_pkt_head                      m_head;                            // ��ͷ
	unsigned char                     m_trading_status;                  // ����״̬��
	//******************************************************************************************
	// Bit7-Bit4(m_trading_status&0xF0):
	// 0x00:��ʾ����������ǰ)
	// 0x10:��ʾ���̼��Ͼ���
	// 0x20:��ʾ��������
	// 0x30:��ʾ����
	// 0x40:��ʾ��Լͣ��
	// 0x50:��ʾ�ɻָ����׵��۶�ʱ�Σ����м��Ͼ��ۣ�
	// 0x60:��ʾ���ɻָ����׵��۶�ʱ�Σ���ͣ���������У�
	// 0x70:��ʾ���̼��Ͼ���ʱ��
	// 0x80:��ʾ�������жϣ������ڹ�Ʊ��Ȩ)
	// 0x15:��ʾ������
	// Bit3(m_trading_status&0x08):
	// 0x08:?��ʾ�˺�Լ���������� 0x00:��ʾ�˺�Լ������������
	// Bit2(m_trading_status&0x04):
	// 0x04:��ʾ������ 0x00:��ʾδ����
	// Bit1(m_trading_status&0x02):
	// 0x02:��ʾ�˺�Լ�ڵ�ǰʱ�ν��ܶ����걨 0x00:��ʾ�˺�Լ�ڵ�ǰʱ�β����ܶ����걨
	// Bit0:Ԥ��
	//******************************************************************************************
	unsigned long long                m_total_trade_num;                 // �ɽ�����
	unsigned long long                m_total_quantity;                  // �ܳɽ�����          ʵ��ֵ��Ҫ���� 100
	unsigned long long                m_total_value;                     // �ܳɽ��          ʵ��ֵ��Ҫ���� 1000000
	unsigned int                      m_pre_close_price;                 // ���ռۣ�            ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_last_price;                      // ���¼ۣ�            ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_open_price;                      // ���̼ۣ�            ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_day_high_price;                  // ��߼ۣ�            ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_day_low_price;                   // ��ͼۣ�            ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_today_close_price;               // ���̼ۣ�            ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_total_trade_weighted_avg_price;  // ��Ȩƽ���ۣ�        ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_fluctuation_1;                   // ���� 1,             ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_fluctuation_2;                   // ���� 2,             ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_total_bid_weighted_avg_price;    // �򷽹ҵ����ۣ�      ʵ��ֵ��Ҫ���� 10000
	unsigned long long                m_total_bid_quantity;              // ��������            ʵ��ֵ��Ҫ���� 100
	unsigned int                      m_total_ask_weighted_avg_price;    // �����ҵ����ۣ�      ʵ��ֵ��Ҫ���� 10000
	unsigned long long                m_total_ask_quantity;              // ��������            ʵ��ֵ��Ҫ���� 100

	unsigned int                      m_weighted_avg_price_BP;           // ��Ȩƽ���ǵ� BP     ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_weighted_avg_pre_close_price;    // �����̼�Ȩƽ����    ʵ��ֵ��Ҫ���� 10000
	unsigned int                      m_auction_trade_last_price;        // ƥ��ɽ����¼�      ʵ��ֵ��Ҫ���� 10000
	unsigned char                     m_reserved[4];                     // �����ֶ�
	unsigned long long                m_auction_volume_trade;            // ƥ��ɽ��ɽ���      ʵ��ֵ��Ҫ���� 100
	unsigned long long                m_auction_value_trade;             // ƥ��ɽ��ɽ����    ʵ��ֵ��Ҫ���� 1000000

	px_qty_unit	                      m_bid_unit[SZE_LEV2_DEPTH];        // ��ʮ��
	px_qty_unit	                      m_ask_unit[SZE_LEV2_DEPTH];        // ����ʮ��
};

// ���ծȯ���ί��
struct sze_hpf_bond_order_pkt
{
	sze_hpf_pkt_head                  m_head;                            // ��ͷ
	/// �����ί�м۸�ת��˵�����£�
	//  ****************************************************************************************************************
	//  |�������� \ �������� |                    ��1��            |                           ����2��                    |
	//  |     �мۣ�1��      |                    ֱ��͸��           |                           ֱ��͸��                   |
	//  |    ��������(U��    |                    ֱ��͸��           |                           ֱ��͸��                   |
	//  |     �޼ۣ�2��      |   ���С�� 3 ��ȡΪ 3������ȡԭֵ     |   ������� 999999997��ȡΪ 999999997������ȡԭֵ     |
	//  *****************************************************************************************************************
	unsigned int                      m_price;                           // �۸�  ʵ��ֵ��Ҫ���� 10000
	unsigned long long                m_quantity;                        // ������  ʵ��ֵ��Ҫ���� 100
	char                              m_side;                            // ���򣬡�1��=�� ��2��=��
	char                              m_order_type;                      // ��������
	//******************************************************************************************
	// '1'=�м�  '2'=�޼�  'U'=��������
	//******************************************************************************************
	char                              m_reserved[15];                     // �����ֶ�
};

// ���ծȯ��ʳɽ�
struct sze_hpf_bond_exe_pkt
{
	sze_hpf_pkt_head                  m_head;                           // ��ͷ
	long long                         m_buy_num;                        // �򷽰����
	long long                         m_sell_num;                       // ���������
	unsigned int                      m_price;                          // �۸�   ʵ��ֵ��Ҫ���� 10000
	long long                         m_quantity;                       // ������   ʵ��ֵ��Ҫ���� 100
	char                              m_type;                           // �ɽ�����
	//******************************************************************************************
	// '4'=����  'F'=�ɽ�
	//******************************************************************************************
};

#pragma pack(pop)
