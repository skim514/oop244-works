/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Customer.h
// Version 1.1
// Date   Winter 2023
// Author Yosef Ashibani and Suna Kim
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Yosef Ashibani   23-01-24       reordered user's tweets report
/////////////////////////////////////////////////////////////////
***********************************************************************/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };
    
    void read(char* str, int len); //Reads a CString into the str pointer up to len characters.
   
    // to be completed
    void EmptyRecord(struct Customers& customers);

    //void 함수에 리턴값이 없을때 아규먼트를 직접적으로 수정하고 싶으면 포인터나 레퍼런스사용.
    //일반변수면 레퍼런스, 포인터는 포인터

    void EmptyRecord(struct CustomersRecord& customersRecord);

    bool read(Customers& rec);

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);

    void display(const Customers& c_rec);

    void display(const CustomersRecord& t_rec);
}

#endif 
