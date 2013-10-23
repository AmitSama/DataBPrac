#include"schema.cpp"
#include <stdio.h>
/*Initially will be loading only those files
 *which are required by the neworder function
 */
void warehouse_loader( const char* filename) { // very important

    const char* m_w_id;
    const char* m_w_name;
    const char* m_w_street_1;
    const char* m_w_street_2;
    const char* m_w_city;
    const char* m_w_state;
    const char* m_w_zip;
    const char* m_w_tax;
    const char* m_w_ytd;

    char buff[1024];
    uint64_t n=0;
    FILE* pFile = fopen(filename,"R");

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
}
void district_loader( const char* filename) {

    const char* m_d_id;
    const char* m_d_w_id;
    const char* m_d_name;
    const char* m_d_street_1;
    const char* m_d_street_2;
    const char* m_d_city;
    const char* m_d_state;
    const char* m_d_zip;
    const char* m_d_tax;
    const char* m_d_ytd;
    const char* m_d_next_o_id;

    char buff[1024];
    uint64_t n=0;
    FILE* pFile = fopen(filename,"R");

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
}


void customer_loader( const char* filename) {

    const char* m_c_id;
    const char* m_c_d_id;
    const char* m_c_w_id;
    const char* m_c_first;
    const char* m_c_middle;
    const char* m_c_last;
    const char* m_c_street_1;
    const char* m_c_street_2;
    const char* m_c_city;
    const char* m_c_state;
    const char* m_c_zip;
    const char* m_c_phone;
    char m_c_since[1024];
    const char* m_c_credit;
    const char* m_c_credit_lim;
    const char* m_c_discount;
    const char* m_c_balance;
    const char* m_c_ytd_payment;
    const char* m_c_payment_cnt;
    const char* m_c_delivery_cnt;
    const char* m_c_data;


    char buff[1024];
    uint64_t n=0;
    FILE* pFile = fopen(filename,"R");

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
        //customer_wdl[std::make_tuple(s.c_w_id,s.c_d_id,s.c_id,s.c_last,s.c_first)] = n;
        n++;
        customer.push_back(s);
    }
}

void history_loader(const char* filename){

        char m_h_c_id[1024];
        char m_h_c_d_id[1024];
        char m_h_c_w_id[1024];
        char m_h_d_id[1024];
        char m_h_w_id[1024];
        char m_h_date[1024];
        char m_h_amount[1024];
        char m_h_data[1024];

        char buff[1024];
        FILE* pFile = fopen(filename,"R");

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

}
