/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Customer.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);//유저스트링인풋함수
    }

    
    // complete

    //Sets Customer data members to an empty state
    void EmptyRecord(struct Customers& customers){
        struct Customers remove = {{0}};//{{스트럭쳐 초기화}}
        customers = remove;
    }
    //Sets Customer data members to an empty state
    void EmptyRecord(struct CustomersRecord& customersRecord){
    
        //포인터 어드레스 안전하게 초기화 주는방법은 nullptr.
        struct CustomersRecord remove = {nullptr, 0}; //{스트럭쳐 포인터 초기화, 인트 초기화}
        customersRecord = remove;
    }
    bool read(Customers& rec){
        //char 스트링 초기화는 첫번째 인덱스만 '\0'
        bool check = false;//bool 초기값은 false로 주는게 좋다.
        
        cout << " Enter User name: ";
        read(rec.user_name, 21);
        
        if (rec.user_name[0]) {
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
            check = true;
        }        
        return check;
    }
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec){
        Customers* newRecord = {0};//다이나믹은 포인터로 선언. 제발 외워!!!
        int i = 0;
        
        t_rec.noOfRecords++;//new (old = new-1), 레코드 갯수가 이미 더해진거임 그래서 뒤에서 더할필요가 없다.
        
        if (t_rec.noOfRecords == 1) {
            t_rec.ptr_rec = nullptr;
            t_rec.ptr_rec = new Customers[t_rec.noOfRecords];
            t_rec.ptr_rec[0] = c_rec; //1건의 경우이기 때문에 인덱스도 하나.
        }
        else{
            newRecord = nullptr;
            newRecord = new Customers[t_rec.noOfRecords];
            
           for (i = 0; i < t_rec.noOfRecords - 1; i++) { //old
               newRecord[i] = t_rec.ptr_rec[i];
                }
            newRecord[t_rec.noOfRecords-1] = c_rec;
            delete [] t_rec.ptr_rec;
            t_rec.ptr_rec = nullptr;
            t_rec.ptr_rec = newRecord;
           }
    }
    void display(const Customers& c_rec){ //단건. T를 받는거에서 반복문 돌면서 t.ptr[i]를 c받는 펑션한테 보내주기 == t에서 c로 값을 보내줌. 얘가 출력
        
        cout << ". " << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", " << c_rec.replies_count << ", " << c_rec.share_videos << endl <<endl;
    }
    void display(const CustomersRecord& t_rec){ //다건. T를 받는거에서 반복문 돌면서 t.ptr[i]를 c받는 펑션한테 보내주기. 얘는 나눠서 c로 보내주는 역할.
        int i = 0;
        for (i = 0; i < t_rec.noOfRecords; i++) {
            cout << i + 1;
            display(t_rec.ptr_rec[i]); //레퍼런스는 변수 그 자체이기 때문에 어드레스오브 노노. 필요없다.
            }
    }
}
