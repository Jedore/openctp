/////////////////////////////////////////////////////////////////////////
///@author �����Ƹ�֤ȯ�ɷ����޹�˾
///@file quote_api.h
///@brief ����ͻ�������ӿ�
/////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

#include "emt_quote_data_type.h"
#include "sse_hpf_define.h"
#include "sze_hpf_define.h"
#include "emt_quote_struct.h"

#ifdef _WIN32
#ifdef LIB_QUOTE_API_EXPORT
#define QUOTE_API_ _declspec(dllexport)
#else
#define QUOTE_API_ _declspec(dllimport)
#endif
#else
#define QUOTE_API_
#endif // _WIN32

namespace EMQ {
namespace API {

class QuoteSpi {
  public:

    /**
     *   ����Ӧ��
     *   @attention                     �˺���ֻ���ڷ�������������ʱ�Ż���ã�һ�������û�����
     *   @param error_info              ����������Ӧ��������ʱ�ľ����������
     *   @return                        �ú�������Ϊvoid
     */
    virtual void OnError(const EMTRspInfoStruct* error_info) {};

    /**
     *   ָ������֪ͨ
     *   @attention                     ��Ҫ���ٷ��أ���������������Ϣ��������ʱ������������ʱ���ᴥ������
     *   @param index_data              ָ���������ݣ�ֻ��ָ��������������ֶ�
     */
    virtual void OnIndexData(EMTIndexDataStruct* index_data) {};

    /**
     *   �������֪ͨ��������һ��һ����
     *   @attention                     ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
     *   @param market_data             ��������
     *   @param bid1_qty                ��һ��������
     *   @param bid1_count              ��һ���е���Чί�б���
     *   @param max_bid1_count          ��һ������ί�б���
     *   @param ask1_qty                ��һ��������
     *   @param ask1_count              ��һ���е���Чί�б���
     *   @param max_ask1_count          ��һ������ί�б���
     */
    virtual void OnDepthMarketData(EMTMarketDataStruct* market_data, int64_t bid1_qty[], int32_t bid1_count, int32_t max_bid1_count, int64_t ask1_qty[], int32_t ask1_count, int32_t max_ask1_count) {};

    /**
     *   ����ȫ�г���ָ������Ӧ��
     *   @attention                     ��Ҫ���ٷ���
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г�
     *   @param error_info              ���ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     */
    virtual void OnSubscribeAllIndexData(EMQ_EXCHANGE_TYPE exchange_id, EMTRspInfoStruct* error_info) {};

    /**
     *   �˶�ȫ�г���ָ������Ӧ��
     *   @attention                     ��Ҫ���ٷ���
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г�
     *   @param error_info              ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     */
    virtual void OnUnSubscribeAllIndexData(EMQ_EXCHANGE_TYPE exchange_id, EMTRspInfoStruct* error_info) {};

    /**
     *   ����ָ������Ӧ��
     *   @attention                     ÿ�����ĵĺ�Լ��Ӧһ������Ӧ����Ҫ���ٷ��أ����������������Ϣ������������ʱ���ᴥ������
     *   @param ticker                  ���ĵĺ�Լ��Ŵ���
     *   @param error_info              ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     *   @param is_last                 �Ƿ�˴ζ��ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnSubIndexData(EMTSpecificTickerStruct* ticker, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     *   �˶�ָ������Ӧ��
     *   @attention                     ÿ�����ĵĺ�Լ��Ӧһ���˶�Ӧ����Ҫ���ٷ��أ����������������Ϣ������������ʱ���ᴥ������
     *   @param ticker                  ���ĵĺ�Լ��Ŵ���
     *   @param error_info              ȡ�����ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     *   @param is_last                 �Ƿ�˴�ȡ�����ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnUnSubIndexData(EMTSpecificTickerStruct* ticker, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     *   ����ȫ�г���Ʊ��������Ӧ��
     *   @attention                     ��Ҫ���ٷ���
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г�
     *   @param error_info              ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     */
    virtual void OnSubscribeAllMarketData(EMQ_EXCHANGE_TYPE exchange_id, EMTRspInfoStruct* error_info) {};

    /**
     *   �˶�ȫ�г��Ĺ�Ʊ��������Ӧ��
     *   @attention                     ��Ҫ���ٷ���
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г�
     *   @param error_info              ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     */
    virtual void OnUnSubscribeAllMarketData(EMQ_EXCHANGE_TYPE exchange_id, EMTRspInfoStruct* error_info) {};

    /**
     *   ���Ŀ�������Ӧ�𣬰�����Ʊ������ծȯ��Ȩ֤����Ѻʽ�ع�
     *   @attention                     ÿ�����ĵĺ�Լ��Ӧһ������Ӧ����Ҫ���ٷ��أ����������������Ϣ������������ʱ���ᴥ������
     *   @param ticker                  ���ĵĺ�Լ��Ŵ���
     *   @param error_info              ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     *   @param is_last                 �Ƿ�˴ζ��ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnSubMarketData(EMTSpecificTickerStruct* ticker, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     *   �˶���������Ӧ�𣬰�����Ʊ������ծȯ��Ȩ֤����Ѻʽ�ع�
     *   @attention                     ÿ�����ĵĺ�Լ��Ӧһ������Ӧ����Ҫ���ٷ��أ����������������Ϣ������������ʱ���ᴥ������
     *   @param ticker                  ���ĵĺ�Լ��Ŵ���
     *   @param error_info              ȡ�����ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     *   @param is_last                 �Ƿ�˴�ȡ�����ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnUnSubMarketData(EMTSpecificTickerStruct* ticker, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     *   ��ѯȫ�г���Լ���־�̬��Ϣ��Ӧ��
     *   @attention                     ��Ҫʹ�ú�Լ���־�̬��Ϣ�ṹ��EMTQuoteStaticInfo
     *   @param qsi                     ��Լ���־�̬��Ϣ�ṹ��
     *   @param error_info              ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     *   @param is_last                 �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnQueryAllTickers(EMTQuoteStaticInfo* qsi, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     *   ��ѯȫ�г���Լ������̬��Ϣ��Ӧ��
     *   @attention                     ��Ҫʹ�ú�Լ������̬��Ϣ�ṹ��EMTQutoFullInfo(�������г���̬��Ϣ)
     *   @param qfi                     ��Լ������̬��Ϣ�ṹ��
     *   @param error_info              ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     *   @param is_last                 �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnQueryAllTickersFullInfo(EMTQuoteFullInfo* qfi, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     *   ��ѯ��Լ����ָ����Ӧ��
     *   @attention                     ��Ҫʹ���������ݽṹ��EMTIndexDataStruct
     *   @param index_data              ����ָ������
     *   @param error_info              ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     *   @param is_last                 �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnQueryLatestIndexData(EMTIndexDataStruct* index_data, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     *   ��ѯ��Լ�����ֻ����յ�Ӧ��
     *   @attention                     ��Ҫʹ���������ݽṹ��EMTMarketDataStruct
     *   @param market_data             �����ֻ���������
     *   @param error_info              ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     *   @param is_last                 �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnQueryLatestMarketData(EMTMarketDataStruct* market_data, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     * ��ѯ���¼�
     * @attention                       ��Ҫʹ�����¼۽ṹ��EMTTickerPriceInfo
     * @param price_info                ���¼۸�����
     * @param error_info                ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     * @param is_last                   �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnQueryTickersPriceInfo(EMTTickerPriceInfo* price_info, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     * @brief  ��ѯ�۹ɾ�̬��Ϣ
     * @attention                       ��Ҫʹ�ø۹ɾ�̬��Ϣ�ṹ��EMTHKStaticInfo
     * @param  static_info              �۹ɾ�̬��Ϣ����
     * @param  error_info               ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     * @param  is_last                  �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnQueryHKStaticInfo(EMTHKStaticInfo* static_info, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     * @brief  ��ѯ��ת��̬��Ϣ
     * @attention                       ��Ҫʹ�ù�ת��̬��Ϣ�ṹ��EMTBJGZStaticInfo
     * @param  static_info              ��ת��̬��Ϣ����
     * @param  error_info               ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
     * @param  is_last                  �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnQueryBJGZStaticInfo(EMTBJGZStaticInfo* static_info, EMTRspInfoStruct* error_info, bool is_last) {};

    /**
     * ��ѯ�ؽ��ز������������Ӧ��
     * @param  rebuild_data             �ؽ�������Ӧ��Ϣ
     * @param  error_info               ������Ϣ����������Ӧ��������ľ����������
     * @param  is_last                  �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
     */
    virtual void OnRebuildSzData(const EMTRebuildRespData* rebuild_data, const EMTRspInfoStruct* error_info, const bool is_last) {};
};

class QUOTE_API_ QuoteApi {
  public:

    /**
     * @brief  ����QuoteApi
     * @attention                       ϵͳ��֧�ֹ�ҹ����ȷ��ÿ�쿪��ǰ��������
     * @param  log_path                 ��־���Ŀ¼�����趨һ����ʵ���ڵ��п�дȨ�޵�·��
     * @param  log_file_level           �ļ���־����־����
     * @param  log_console_level        ����̨��־����־����
     * @return ��������QuoteApiʵ��
     */
    static QuoteApi* CreateQuoteApi(const char* log_path, EMQ_LOG_LEVEL log_file_level, EMQ_LOG_LEVEL log_console_level);

    /**
     * @brief  ע��ص��ӿ�
     * @param  quote_spi                �����Իص��ӿ����ʵ�������ڵ�¼֮ǰ�趨
     */
    virtual void RegisterSpi(QuoteSpi* quote_spi) = 0;

    /**
     * @brief  �û���¼����
     * @attention                       �˺���Ϊͬ������ʽ������Ҫ�첽�ȴ���¼�ɹ������������ؼ��ɽ��к�������
     * @param  ip                       ��������ַ�����ơ�127.0.0.1��
     * @param  port                     �������˿ں�
     * @param  user                     ��¼�û���
     * @param  pwd                      ��¼����
     * @return ��������QuoteApiʵ��
     */
    virtual int32_t Login(const char* ip, const uint16_t port, const char* user, const char* pwd) = 0;

    /**
     * @brief  �ǳ�����
     */
    virtual void Logout() = 0;

    /**
     * @brief  ��ѯ�ز������������
     * 
     * @attention                       �˽ӿڶ�L1�û����ṩ����
     * @param  chno                     �ز�����ͨ����
     * @param  beg_seq                  �ز�������ʼ���
     * @param  end_seq                  �ز����ݽ������
     * @param  request_id               �����ֶΣ���д���ڵ���0�����ֵ
     * @return                          �����Ƿ�ɹ� "0"��ʾ����ɹ���"-2"��ʾ�������ӱ����ʧ��,���ͻز���Ϣʧ�ܣ����Գ����������� "-3"��ʾȨ��У��ʧ��
     */
    virtual int32_t RebuildSzData(const uint32_t chno, const uint64_t beg_seq, const uint64_t end_seq, const uint64_t request_id) = 0;

    /**
     * @brief  ����ϵͳ�̰߳󶨵�cpu id
     * 
     * @attention                       �˺����ɲ�����,������Ҫ�ڵ�¼ǰ���á�id��д -1 �����ϵͳ���ɷ��䣬�����а�ˡ�
     * @param  recv_cpu_no              �����̰߳�cpu id�� �����cpu 0����������0����cpu 2����������2������󶨺����cpu
     * @param  process_cpu_no           �����̰߳�cpu id��
     * @return
     */
    virtual void SetThreadAffinity(int32_t recv_cpu_no = -1,int32_t process_cpu_no = -1) = 0;

    /**
     *   @brief ���û�������С
     *   @attention                     ����api�ڲ���Ϣ��������С,��¼ǰ������Ч
     *   @param buffer_size             ��������С����λMB��Ĭ��512MB����С����Ϊ64MB
     *   @return                        "0"��ʾ���óɹ�����"0"��ʾ������Ч����Ĭ��ֵ
     */
    virtual int32_t SetBuffer(size_t buffer_size) = 0;

    /**
     *   @brief ����ȫ�г�ָ����������
     *   @attention                     ��Ҫ��ȡ������ȫ�г�ָ������ӿ�����ʹ��
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г���EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ����ȫ�г�ָ����������ӿڵ����Ƿ�ɹ���"0"��ʾ�ӿڵ��óɹ�����"0"��ʾ�ӿڵ��ó���
     */
    virtual int SubscribeAllIndexData(EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ȡ������ȫ�г�ָ����������
     *   @attention                     ��Ҫ�붩��ȫ�г�ָ������ӿ�����ʹ��
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г���EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ȡ������ȫ�г�ָ����������ӿڵ����Ƿ�ɹ���"0"��ʾ�ӿڵ��óɹ�����"0"��ʾ�ӿڵ��ó���
     */
    virtual int UnSubscribeAllIndexData(EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ����ָ����������
     *   @attention                     ��һ���Զ���ͬһ֤ȯ�������Ķ��ָ���������û���Ϊ����������Ҫ���µ�¼���������������Ҫ���¶���
     *   @param tickers                 ָ���������飬ע��ָ�����������"\0"��β���������ո�
     *   @param count                   ��Ҫ���������ָ������
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г���EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ���Ľӿڵ����Ƿ�ɹ���"0"��ʾ�ӿڵ��óɹ�����"0"��ʾ�ӿڵ��ó���
     */
    virtual int SubscribeIndexData(char* tickers[], int count, EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ȡ������ָ����������
     *   @attention                     ��һ����ȡ������ͬһ֤ȯ�������Ķ��ָ���������û���Ϊ����������Ҫ���µ�¼���������������Ҫ���¶���
     *   @param tickers                 ָ���������飬ע��ָ�����������"\0"��β���������ո�
     *   @param count                   ��Ҫ���������ָ������
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г���EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ȡ�����Ľӿڵ����Ƿ�ɹ���"0"��ʾ�ӿڵ��óɹ�����"0"��ʾ�ӿڵ��ó���
     */
    virtual int UnSubscribeIndexData(char* tickers[], int count, EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ����ȫ�г���Լ��������
     *   @attention                     ��Ҫ��ȫ�г��˶�����ӿ�����ʹ��
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г�
     *   @return                        ����ȫ�г�����ӿڵ����Ƿ�ɹ���"0"��ʾ�ӿڵ��óɹ�����"0"��ʾ�ӿڵ��ó���
     */
    virtual int SubscribeAllMarketData(EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief �˶�ȫ�г���Լ��������
     *   @attention                     ��Ҫ��ȫ�г���������ӿ�����ʹ��
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г���EMQ_EXCHANGE_SHHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_SZHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        �˶�ȫ�г�����ӿڵ����Ƿ�ɹ���"0"��ʾ�ӿڵ��óɹ�����"0"��ʾ�ӿڵ��ó���
     */
    virtual int UnSubscribeAllMarketData(EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ���Ŀ������飬������Ʊ������ծȯ��Ȩ֤����Ѻʽ�ع�
     *   @attention                     ��һ���Զ���ͬһ֤ȯ�������Ķ����Լ�������û���Ϊ����������Ҫ���µ�¼���������������Ҫ���¶���
     *   @param tickers                 ��Լ�������飬ע���Լ���������"\0"��β���������ո�
     *   @param count                   ��Ҫ��������ĺ�Լ����
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г���EMQ_EXCHANGE_SHHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_SZHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ���Ľӿڵ����Ƿ�ɹ���"0"��ʾ�ӿڵ��óɹ�����"0"��ʾ�ӿڵ��ó���
     */
    virtual int SubscribeMarketData(char* tickers[], int count, EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ȡ�����Ŀ������飬������Ʊ������ծȯ��Ȩ֤����Ѻʽ�ع�
     *   @attention                     ��һ����ȡ������ͬһ֤ȯ�������Ķ����Լ�������û���Ϊ����������Ҫ���µ�¼���������������Ҫ���¶���
     *   @param tickers                 ��Լ�������飬ע���Լ���������"\0"��β���������ո�
     *   @param count                   ��Ҫ��������ĺ�Լ����
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г���EMQ_EXCHANGE_SHHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_SZHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ȡ�����Ľӿڵ����Ƿ�ɹ���"0"��ʾ�ӿڵ��óɹ�����"0"��ʾ�ӿڵ��ó���
     */
    virtual int UnSubscribeMarketData(char* tickers[], int count, EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ��ȡ���к�Լ�Ĳ��־�̬��Ϣ������ȫ�г����к�Լ�Ĳ��־�̬��Ϣ
     *   @param exchange_id             ���������룬֧�ֻ����г���EMQ_EXCHANGE_SH��ʾ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾ��֤ȫ�г�
     *   @return                        ���Ͳ�ѯ�����Ƿ�ɹ���"0"��ʾ���Ͳ�ѯ����ɹ�����"0"��ʾ���Ͳ�ѯ���󲻳ɹ�
     */
    virtual int QueryAllTickers(EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ��ȡ���к�Լ��������̬��Ϣ������ȫ�г����к�Լ��������̬��Ϣ
     *   @param exchange_id             ���������룬֧�ֻ����г���EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г���EMQ_EXCHANGE_SHHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_SZHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ���Ͳ�ѯ�����Ƿ�ɹ���"0"��ʾ���Ͳ�ѯ����ɹ�����"0"��ʾ���Ͳ�ѯ���󲻳ɹ�
     */
    virtual int QueryAllTickersFullInfo(EMQ_EXCHANGE_TYPE exchange_id = EMQ_EXCHANGE_TYPE::EMQ_EXCHANGE_UNKNOWN) = 0;

    /**
     *   @brief ��ȡ���¿�����Ϣ
     *   @param tickers                 ��ԼID���飬ע���Լ���������'\0'��β���������ո�
     *   @param count                   ��Լ������Ϊ0��ʾ��ѯ���������к�Լ
     *   @param ticker_type             ��Լ����
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г�,EMQ_EXCHANGE_SHHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_SZHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ���Ͳ�ѯ�����Ƿ�ɹ���"0"��ʾ���Ͳ�ѯ����ɹ�����"0"��ʾ���Ͳ�ѯ���󲻳ɹ�
     */
    virtual int QueryLatestInfo(char* tickers[], int count, EMQ_TICKER_TYPE ticker_type, EMQ_EXCHANGE_TYPE exchange_id) = 0;

    /**
     *   @brief ��ȡ���¼�
     *   @param tickers                 ��ԼID���飬ע���Լ���������'\0'��β���������ո�
     *   @param count                   ��Լ������Ϊ0��ʾ��ѯ���������к�Լ
     *   @param exchange_id             ���������룬EMQ_EXCHANGE_SH��ʾΪ�Ϻ�ȫ�г���EMQ_EXCHANGE_SZ��ʾΪ����ȫ�г�,EMQ_EXCHANGE_SHHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_SZHK��ʾΪ���и۹�ͨ��EMQ_EXCHANGE_BJGZK��ʾ��������ת�г�
     *   @return                        ���Ͳ�ѯ�����Ƿ�ɹ���"0"��ʾ���Ͳ�ѯ����ɹ�����"0"��ʾ���Ͳ�ѯ���󲻳ɹ�
     */
    virtual int QueryTickersPriceInfo(char* tickers[], int count, EMQ_EXCHANGE_TYPE exchange_id) = 0;

};

} // namespace API
} // namespace EMQ