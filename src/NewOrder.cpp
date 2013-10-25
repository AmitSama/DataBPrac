//#include"loader.cpp"
//#include"neworderrandom.cpp"
#include<ctime>
//#include<stdint.h>

using namespace std;

void newOrder(int32_t w_id, int32_t d_id, int32_t c_id, int32_t items, int32_t supware[], int32_t itemid[], int32_t qty[], int64_t datetime){
//        select w_tax from warehouse w where w.w_id=w_id;
//        select c_discount from customer c where c_w_id=w_id and c_d_id=d_id and c.c_id=c_id;
//        select d_next_o_id as o_id,d_tax from district d where d_w_id=w_id and d.d_id=d_id;
//        update district set d_next_o_id=o_id+1 where d_w_id=w_id and district.d_id=d_id;

        Numeric<4,4> w_tax = warehouse[pkey_warehouse[(Integer)w_id]].w_tax;
        Numeric<4,4> c_discount = customer[pkey_customer[std::make_tuple((Integer)w_id,(Integer)d_id,(Integer)c_id)]].c_discount;
        t_district dis = district[pkey_district[std::make_tuple((Integer)w_id,(Integer)d_id)]];
        Integer o_id = dis.d_next_o_id;
        Numeric<4,4> d_tax = dis.d_tax;
        dis.d_next_o_id = o_id+1;

//        var integer all_local = 1;
//        forsequence (index between 0 and items-1) {
//           if (w_id<>supware[index])
//              all_local=0;
//        }
        Integer all_local = 1;
        for(int32_t index =0; index< items;index++) {
            if(w_id != supware[index]) {
                all_local = 0;
            }
        }

//        insert into "order" values (o_id,d_id,w_id,c_id,datetime,0,items,all_local);
//        insert into neworder values (o_id,d_id,w_id);

        t_order s;
        s.o_id = o_id;
        s.o_d_id = d_id;
        s.o_w_id = w_id;
        s.o_c_id = c_id;
        s.o_entry_d = (Timestamp)datetime;
        s.o_carrier_id = 0;
        s.o_ol_cnt = Numeric<2,0>(items);
        s.o_all_local = all_local;

        uint64_t size = order.size();
        order.push_back(s);
        pkey_order[std::make_tuple(s.o_w_id,s.o_d_id,s.o_c_id)] = size;
        order_wdc[hashKey(s.o_w_id,s.o_d_id,s.o_c_id,s.o_id)] = size;

        t_neworder s1;
        s1.no_o_id = o_id;
        s1.no_d_id = d_id;
        s1.no_w_id = w_id;
        uint64_t size1 = neworder.size();
        pkey_neworder[std::make_tuple(s1.no_w_id,s1.no_d_id,s1.no_o_id)]= size1;

        /*
         *forsequence (index between 0 and items-1) {
        select i_price from item where i_id=itemid[index];
        select s_quantity,s_remote_cnt,s_order_cnt,case d_id when 1 then s_dist_01 when 2 then s_dist_02 when 3 then s_dist_03
        when 4 then s_dist_04 when 5 then s_dist_05 when 6 then s_dist_06 when 7 then s_dist_07
        when 8 then s_dist_08 when 9 then s_dist_09 when 10 then s_dist_10 end as s_dist from stock
        where s_w_id=supware[index] and s_i_id=itemid[index];

      if (s_quantity>qty[index]) {
         update stock set s_quantity=s_quantity-qty[index] where s_w_id=supware[index] and s_i_id=itemid[index];
      } else {
         update stock set s_quantity=s_quantity+91-qty[index] where s_w_id=supware[index] and s_i_id=itemid[index];
      }

      if (supware[index]<>w_id) {
         update stock set s_remote_cnt=s_remote_cnt+1 where s_w_id=w_id and s_i_id=itemid[index];
      } else {
         update stock set s_order_cnt=s_order_cnt+1 where s_w_id=w_id and s_i_id=itemid[index];
      }

      var numeric(6,2) ol_amount=qty[index]*i_price*(1.0+w_tax+d_tax)*(1.0-c_discount);
      insert into orderline values (o_id,d_id,w_id,index+1,itemid[index],supware[index],0,qty[index],ol_amount,s_dist);
   }
         */
        t_stock s2;
        Integer s_w_id, s_i_id;


        t_item s3;
        Numeric<5,2> i_price;

        Numeric<4,0> s_quantity;
        Numeric<4,0> s_remote_cnt;
        Numeric<4,0> s_order_cnt;
        Numeric<6,2> ol_amount;
        Char<24> s_dist;

        for(uint32_t index=0; index < items; index++) {

            i_price = item[pkey_item[(Integer)itemid[index]]].i_price;
            s_w_id = supware[index];
            s_i_id = itemid[index];
            s2 = stock[pkey_stock[std::make_tuple((Integer)s_w_id,(Integer)s_i_id)]];
            s_quantity = s2.s_quantity;
            s_remote_cnt = s2.s_remote_cnt;
            s_order_cnt = s2.s_order_cnt;
            switch (d_id) {
                case 1: s_dist = s2.s_dist_01;
                    break;
                case 2: s_dist = s2.s_dist_02;
                    break;
                case 3: s_dist = s2.s_dist_03;
                    break;
                case 4: s_dist = s2.s_dist_04;
                    break;
                case 5: s_dist = s2.s_dist_05;
                    break;
                case 6: s_dist = s2.s_dist_06;
                    break;
                case 7: s_dist = s2.s_dist_07;
                    break;
                case 8: s_dist = s2.s_dist_08;
                    break;
                case 9: s_dist = s2.s_dist_09;
                    break;
                case 10: s_dist = s2.s_dist_10;
                    break;
                default:
                    break;
            }
//        if (s_quantity>qty[index]) {
//           update stock set s_quantity=s_quantity-qty[index] where s_w_id=supware[index] and s_i_id=itemid[index];
//        } else {
//           update stock set s_quantity=s_quantity+91-qty[index] where s_w_id=supware[index] and s_i_id=itemid[index];
//        }
            if(s_quantity>qty[index]) {
                s2.s_quantity = s_quantity-qty[index];
            }
            else {
                s2.s_quantity = s_quantity+91-qty[index];
            }
//            if (supware[index]<>w_id) {
//               update stock set s_remote_cnt=s_remote_cnt+1 where s_w_id=w_id and s_i_id=itemid[index];
//            } else {
//               update stock set s_order_cnt=s_order_cnt+1 where s_w_id=w_id and s_i_id=itemid[index];
//            }
            if(supware[index]!= w_id) {
                s2.s_remote_cnt = s_remote_cnt+1;
            }
            else {
                s2.s_remote_cnt = s_order_cnt+1;
            }

//            var numeric(6,2) ol_amount=qty[index]*i_price*(1.0+w_tax+d_tax)*(1.0-c_discount);
//            insert into orderline values (o_id,d_id,w_id,index+1,itemid[index],supware[index],0,qty[index],ol_amount,s_dist);

            ol_amount = Numeric<6,2>(qty[index]*i_price.value*(1.0+w_tax.value+d_tax.value)*(1.0-c_discount.value));
            t_orderline s4;
            s4.ol_o_id = o_id;
            s4.ol_d_id = d_id;
            s4.ol_w_id = w_id;
            s4.ol_number = index+1;
            s4.ol_i_id = itemid[index];
            s4.ol_supply_w_id = supware[index];
            s4.ol_delivery_d = 0;
            s4.ol_quantity = qty[index];
            s4.ol_amount = ol_amount;
            s4.ol_dist_info = s_dist;

            orderline.push_back(s4);
            pkey_orderline[std::make_tuple(s4.ol_w_id,s4.ol_d_id,s4.ol_o_id,s4.ol_number)] = (uint64_t)orderline.size()-1;
        }
}

