#include"schema.cpp"
//#include <stdio.h>

void warehouse_loader() { // very important

    char m_w_id[1024];
    char m_w_name[1024];
    char m_w_street_1[1024];
    char m_w_street_2[1024];
    char m_w_city[1024];
    char m_w_state[1024];
    char m_w_zip[1024];
    char m_w_tax[1024];
    char m_w_ytd[1024];

    char buff[1024];
    uint64_t n=0;
    FILE* pFile = fopen("tpcc_warehouse.tbl","R");

    while(fgets(buff, 1024, pFile) != NULL) {

        sscanf(buff, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s",m_w_id, m_w_name, m_w_street_1, m_w_street_2, m_w_city, m_w_state, m_w_zip, m_w_tax, m_w_ytd);
        struct t_warehouse s;
        s.w_id = Integer::castString(m_w_id,strlen(m_w_id));
        s.w_name = Varchar<10>::castString(m_w_name,strlen(m_w_name));
        s.w_street_1 = Varchar<20>::castString(m_w_street_1,strlen(m_w_street_1));
        s.w_street_2 = Varchar<20>::castString(m_w_street_2,strlen(m_w_street_2));
        s.w_city = Varchar<20>::castString(m_w_city,strlen(m_w_city));
        s.w_state = Char<2>::castString(m_w_state,strlen(m_w_state));
        s.w_zip = Char<9>::castString(m_w_zip,strlen(m_w_zip));
        s.w_tax = Numeric<4,4>::castString(m_w_tax,strlen(m_w_tax));
        s.w_ytd = Numeric<12,2>::castString(m_w_ytd,strlen(m_w_ytd));

        pkey_warehouse[s.w_id]=n++;
        warehouse.push_back(s);
    }
    fclose (pFile);
}

void district_loader() {

    char m_d_id[1024];
    char m_d_w_id[1024];
    char m_d_name[1024];
    char m_d_street_1[1024];
    char m_d_street_2[1024];
    char m_d_city[1024];
    char m_d_state[1024];
    char m_d_zip[1024];
    char m_d_tax[1024];
    char m_d_ytd[1024];
    char m_d_next_o_id[1024];

    char buff[1024];
    uint64_t n=0;
    FILE* pFile = fopen("tpcc_district.tbl","R");

    while(fgets(buff, 1024, pFile) != NULL) {

        sscanf(buff, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s",m_d_id, m_d_w_id, m_d_name, m_d_street_1, m_d_street_2, m_d_city, m_d_state, m_d_zip, m_d_tax, m_d_ytd, m_d_next_o_id);
        struct t_district s;
        s.d_id = Integer::castString(m_d_id,strlen(m_d_id));
        s.d_w_id = Integer::castString(m_d_w_id,strlen(m_d_w_id));
        s.d_name = Varchar<10>::castString(m_d_name,strlen(m_d_name));
        s.d_street_1 = Varchar<20>::castString(m_d_street_1,strlen(m_d_street_1));
        s.d_street_2 = Varchar<20>::castString(m_d_street_2,strlen(m_d_street_2));
        s.d_city = Varchar<20>::castString(m_d_city,strlen(m_d_city));
        s.d_state = Char<2>::castString(m_d_state,strlen(m_d_state));
        s.d_zip = Char<9>::castString(m_d_zip,strlen(m_d_zip));
        s.d_tax = Numeric<4,4>::castString(m_d_tax,strlen(m_d_tax));
        s.d_ytd = Numeric<12,2>::castString(m_d_ytd,strlen(m_d_ytd));
        s.d_next_o_id = Integer::castString(m_d_next_o_id,strlen(m_d_next_o_id));
        pkey_district[std::make_tuple(s.d_id,s.d_w_id)] = n++;
        district.push_back(s);
    }
    fclose (pFile);
}


void customer_loader() {

    char m_c_id[1024];
    char m_c_d_id[1024];
    char m_c_w_id[1024];
    char m_c_first[1024];
    char m_c_middle[1024];
    char m_c_last[1024];
    char m_c_street_1[1024];
    char m_c_street_2[1024];
    char m_c_city[1024];
    char m_c_state[1024];
    char m_c_zip[1024];
    char m_c_phone[1024];
    char m_c_since[1024];
    char m_c_credit[1024];
    char m_c_credit_lim[1024];
    char m_c_discount[1024];
    char m_c_balance[1024];
    char m_c_ytd_payment[1024];
    char m_c_payment_cnt[1024];
    char m_c_delivery_cnt[1024];
    char m_c_data[1024];


    char buff[1024];
    uint64_t n=0;
    FILE* pFile = fopen("tpcc_customer.tbl","R");

    while(fgets(buff, 1024, pFile) != NULL) {

        sscanf(buff, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s",m_c_id, m_c_d_id, m_c_w_id,m_c_first, m_c_middle, m_c_last, m_c_street_1,m_c_street_2, m_c_city, m_c_state, m_c_zip, m_c_phone, m_c_since, m_c_credit, m_c_credit_lim, m_c_discount, m_c_balance, m_c_ytd_payment, m_c_payment_cnt, m_c_delivery_cnt, m_c_data);
        struct t_customer s;
        s.c_id = Integer::castString(m_c_id,strlen(m_c_id));
        s.c_d_id = Integer::castString(m_c_d_id,strlen(m_c_d_id));
        s.c_w_id = Integer::castString(m_c_w_id,strlen(m_c_w_id));
        s.c_first = Varchar<16>::castString(m_c_first,strlen(m_c_first));
        s.c_middle = Varchar<2>::castString(m_c_middle,strlen(m_c_middle));
        s.c_last = Varchar<16>::castString(m_c_last,strlen(m_c_last));
        s.c_street_1 =Varchar<20>::castString(m_c_street_1,strlen(m_c_street_1));
        s.c_street_2 = Varchar<20>::castString(m_c_street_2,strlen(m_c_street_2));
        s.c_city = Varchar<20>::castString(m_c_city,strlen(m_c_city));
        s.c_state = Char<2>::castString(m_c_state,strlen(m_c_state));
        s.c_zip = Char<9>::castString(m_c_zip,strlen(m_c_zip));
        s.c_phone= Char<16>::castString(m_c_phone,strlen(m_c_phone));
        s.c_since = Timestamp::castString(m_c_since,strlen(m_c_since));
        s.c_credit = Char<2>::castString(m_c_credit,strlen(m_c_credit));
        s.c_credit_lim = Numeric<12,2>::castString(m_c_credit_lim,strlen(m_c_credit_lim));
        s.c_discount = Numeric<4,4>::castString(m_c_discount,strlen(m_c_discount));
        s.c_balance = Numeric<12,2>::castString(m_c_balance,strlen(m_c_balance));
        s.c_ytd_payment = Numeric<12,2>::castString(m_c_ytd_payment,strlen(m_c_ytd_payment));
        s.c_payment_cnt = Numeric<4,0>::castString(m_c_payment_cnt,strlen(m_c_payment_cnt));
        s.c_delivery_cnt = Numeric<4,0>::castString(m_c_delivery_cnt,strlen(m_c_delivery_cnt));
        s.c_data = Varchar<500>::castString(m_c_data,strlen(m_c_data));

        pkey_customer[std::make_tuple(s.c_w_id,s.c_id,s.c_d_id)] = n;
        customer_wdl[hashKey(s.c_w_id,s.c_d_id,s.c_id,s.c_last,s.c_first)] = n;
        n++;
        customer.push_back(s);
    }
    fclose (pFile);
}

void history_loader(){

    char m_h_c_id[1024];
    char m_h_c_d_id[1024];
    char m_h_c_w_id[1024];
    char m_h_d_id[1024];
    char m_h_w_id[1024];
    char m_h_date[1024];
    char m_h_amount[1024];
    char m_h_data[1024];

    char buff[1024];
    FILE* pFile = fopen("tpcc_history.tbl","R");

    while(fgets(buff, 1024, pFile) != NULL) {

        sscanf(buff, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s", m_h_c_id,m_h_c_d_id,m_h_c_w_id,m_h_d_id,m_h_w_id,m_h_date,m_h_amount,m_h_data);
        struct t_history s;
        s.h_c_id = Integer::castString(m_h_c_id,strlen(m_h_c_id));
        s.h_c_d_id = Integer::castString(m_h_c_d_id,strlen(m_h_c_d_id));
        s.h_c_w_id = Integer::castString(m_h_c_w_id,strlen(m_h_c_w_id));
        s.h_d_id = Integer::castString(m_h_d_id,strlen(m_h_d_id));
        s.h_w_id= Integer::castString(m_h_w_id,strlen(m_h_w_id));
        s.h_date = Timestamp::castString(m_h_date,strlen(m_h_date));
        s.h_amount = Numeric<6,2>::castString(m_h_amount,strlen(m_h_amount));
        s.h_data = Varchar<24>::castString(m_h_data,strlen(m_h_data));

        history.push_back(s);
    }
    fclose (pFile);
}

void neworder_loader() {
    char m_no_o_id[512];
    char m_no_d_id[512];
    char m_no_w_id[512];

    char buff[1024];
    struct t_neworder s;
    FILE *pFile = fopen("tpcc_neworder.tbl", "R");
    uint64_t n = 0;

    while(fgets(buff, 1024, pFile) != NULL) {
        sscanf(buff, "%[^|]|%[^|]|%s", m_no_o_id, m_no_d_id, m_no_w_id);
        s.no_o_id = Integer::castString(m_no_o_id, strlen(m_no_o_id));
        s.no_d_id = Integer::castString(m_no_d_id, strlen(m_no_d_id));
        s.no_w_id = Integer::castString(m_no_w_id, strlen(m_no_w_id));
        neworder.push_back(s);

        pkey_neworder[std::make_tuple(s.no_w_id, s.no_d_id, s.no_o_id)]= n;
        n++;
    }
    fclose (pFile);
}

void order_loader() {
    char m_o_id[512];
    char m_o_d_id[512];
    char m_o_w_id[512];
    char m_o_c_id[512];
    char m_o_entry_d[512];
    char m_o_carrier_id[512];
    char m_o_ol_cnt[4];
    char m_o_all_local[3];

    char buff[1024];
    struct t_order s;
    FILE *pFile = fopen("tpcc_order.tbl", "r");
    uint64_t n = 0;

    while(fgets(buff, 1024, pFile) != NULL) {
        sscanf(buff, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s", m_o_id, m_o_d_id, m_o_w_id, m_o_c_id, m_o_entry_d, m_o_carrier_id, m_o_ol_cnt, m_o_all_local);

        s.o_id = Integer::castString(m_o_id, strlen(m_o_id));
        s.o_d_id = Integer::castString(m_o_d_id, strlen(m_o_d_id));
        s.o_w_id = Integer::castString(m_o_w_id, strlen(m_o_w_id));
        s.o_c_id = Integer::castString(m_o_c_id, strlen(m_o_c_id));
        s.o_entry_d = Timestamp::castString(m_o_entry_d, strlen(m_o_entry_d));
        s.o_carrier_id = Integer::castString(m_o_carrier_id, strlen(m_o_carrier_id));
        s.o_ol_cnt = Numeric<2,0>::castString(m_o_ol_cnt, strlen(m_o_ol_cnt));
        s.o_all_local = Numeric<1,0>::castString(m_o_all_local, strlen(m_o_all_local));
        order.push_back(s);

        pkey_order[std::make_tuple(s.o_w_id, s.o_d_id,s.o_id)] = n;
        order_wdc[hashKey(s.o_w_id, s.o_d_id,s.o_c_id,s.o_id)] = n;
        n++;
    }
    fclose (pFile);
}


void orderline_loader() {
    char m_ol_o_id[512];
    char m_ol_d_id[512];
    char m_ol_w_id[512];
    char m_ol_number[512];
    char m_ol_i_id[512];
    char m_ol_supply_w_id[512];
    char m_ol_delivery_d[512];
    char m_ol_quantity[4];
    char m_ol_amount[10];
    char m_ol_dist_info[25];

    char buff[1024];
    struct t_orderline s;
    FILE *pFile = fopen("tpcc_orderline.tbl", "r");
    uint64_t n = 0;

    while(fgets(buff, 1024, pFile) != NULL) {

        sscanf(buff, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s", m_ol_o_id, m_ol_d_id, m_ol_w_id, m_ol_number, m_ol_i_id, m_ol_supply_w_id, m_ol_delivery_d, m_ol_quantity, m_ol_amount, m_ol_dist_info);
        s.ol_o_id = Integer::castString(m_ol_o_id, strlen(m_ol_o_id));
        s.ol_d_id = Integer::castString(m_ol_d_id, strlen(m_ol_d_id));
        s.ol_w_id = Integer::castString(m_ol_w_id, strlen(m_ol_w_id));
        s.ol_number = Integer::castString(m_ol_number, strlen(m_ol_number));
        s.ol_i_id = Integer::castString(m_ol_i_id, strlen(m_ol_i_id));
        s.ol_supply_w_id = Integer::castString(m_ol_supply_w_id, strlen(m_ol_supply_w_id));
        s.ol_delivery_d = Timestamp::castString(m_ol_delivery_d, strlen(m_ol_delivery_d));
        s.ol_quantity = Numeric<2,0>::castString(m_ol_quantity, strlen(m_ol_quantity));
        s.ol_amount = Numeric<6,2>::castString(m_ol_amount, strlen(m_ol_amount));
        s.ol_dist_info = Char<24>::castString(m_ol_dist_info, strlen(m_ol_dist_info));
        orderline.push_back(s);

        pkey_orderline[std::make_tuple(s.ol_o_id,s.ol_d_id,s.ol_w_id,s.ol_number)] = n;
        n++;
    }
    fclose (pFile);
}

void item_loader() {
    char m_i_id[512];
    char m_i_im_id[512];
    char m_i_name[25];
    char m_i_price[9];
    char m_i_data[51];

    char buff[1024];
    struct t_item s;
    FILE *pFile = fopen("tpcc_item.tbl","r");
    uint64_t n = 0;

    while(fgets(buff, 1024, pFile) != NULL) {

        sscanf(buff, "%[^|]|%[^|]|%[^|]|%[^|]|%s", m_i_id, m_i_im_id, m_i_name, m_i_price, m_i_data);
        s.i_id = Integer::castString(m_i_id, strlen(m_i_id));
        s.i_im_id = Integer::castString(m_i_im_id, strlen(m_i_im_id));
        s.i_name = Varchar<24>::castString(m_i_name, strlen(m_i_name));
        s.i_price = Numeric<5,2>::castString(m_i_price, strlen(m_i_price));
        s.i_data = Varchar<50>::castString(m_i_data, strlen(m_i_data));

        item.push_back(s);
        pkey_item[s.i_id]= n;
        n++;
    }
    fclose (pFile);
}

void stock_loader() {
    char m_s_i_id[512];
    char m_s_w_id[512];
    char m_s_quantity[6];
    char m_s_dist_01[25];
    char m_s_dist_02[25];
    char m_s_dist_03[25];
    char m_s_dist_04[25];
    char m_s_dist_05[25];
    char m_s_dist_06[25];
    char m_s_dist_07[25];
    char m_s_dist_08[25];
    char m_s_dist_09[25];
    char m_s_dist_10[25];
    char m_s_ytd[10];
    char m_s_order_cnt[6];
    char m_s_remote_cnt[6];
    char m_s_data[51];

    char buff[1024];
    struct t_stock s;
    FILE *pFile = fopen("tpcc_stock.tbl", "r");
    uint64_t n = 0;

    while(fgets(buff, 1024, pFile) != NULL) {

        sscanf(buff, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s", m_s_i_id, m_s_w_id, m_s_quantity, m_s_dist_01, m_s_dist_02, m_s_dist_03, m_s_dist_04, m_s_dist_05, m_s_dist_06, m_s_dist_07, m_s_dist_08, m_s_dist_09, m_s_dist_10, m_s_ytd, m_s_order_cnt, m_s_remote_cnt, m_s_data);

        s.s_i_id = Integer::castString(m_s_i_id, strlen(m_s_i_id));
        s.s_w_id = Integer::castString(m_s_w_id, strlen(m_s_w_id));

        s.s_quantity = Numeric<4,0>::castString(m_s_quantity, strlen(m_s_quantity));
        s.s_dist_01 = Char<24>::castString(m_s_dist_01, strlen(m_s_dist_01));
        s.s_dist_02 = Char<24>::castString(m_s_dist_02, strlen(m_s_dist_02));
        s.s_dist_03 = Char<24>::castString(m_s_dist_03, strlen(m_s_dist_03));
        s.s_dist_04 = Char<24>::castString(m_s_dist_04, strlen(m_s_dist_04));
        s.s_dist_05 = Char<24>::castString(m_s_dist_05, strlen(m_s_dist_05));
        s.s_dist_06 = Char<24>::castString(m_s_dist_06, strlen(m_s_dist_06));
        s.s_dist_07 = Char<24>::castString(m_s_dist_07, strlen(m_s_dist_07));
        s.s_dist_08 = Char<24>::castString(m_s_dist_08, strlen(m_s_dist_08));
        s.s_dist_09 = Char<24>::castString(m_s_dist_09, strlen(m_s_dist_09));
        s.s_dist_10 = Char<24>::castString(m_s_dist_10, strlen(m_s_dist_10));
        s.s_ytd = Numeric<8,0>::castString(m_s_ytd, strlen(m_s_ytd));
        s.s_order_cnt = Numeric<4,0>::castString(m_s_order_cnt, strlen(m_s_order_cnt));
        s.s_remote_cnt = Numeric<4,0>::castString(m_s_remote_cnt, strlen(m_s_remote_cnt));
        s.s_data = Varchar<50>::castString(m_s_data, strlen(m_s_data));
        stock.push_back(s);

        pkey_stock[std::make_tuple(s.s_w_id, s.s_i_id)] = n;
        n++;
    }
    fclose (pFile);
}
