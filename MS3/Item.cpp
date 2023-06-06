// Final Project Milestone 3
//
// Version 1.0
// Date    2023-03-26
// Author    Suna Kim
// File name    Item.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Item.h"

namespace sdds{
    Item::Item()
    {
        m_SKU[0] = '\0';
        m_name = nullptr;
        m_price = 0.0;
        m_isTaxed = false;
        m_qty = 0;
        m_displayType = 0;
        m_error = Error();
    }
    Item::Item(const Item& another)
    {//Rule of three
        operator=(another);
    }
    Item& Item::operator=(const Item& right)
    {
        if (this != &right)
        { // prevents self copying
            //clear(); // set empty in case right is empty;
            setEmpty();
            if (right)
            {  // the same as bool operator and !isEmpty
                strcpy(m_SKU, right.m_SKU);
                m_name = new char[strlen(right.m_name)+1];
                strcpy(m_name, right.m_name);
                m_isTaxed = right.m_isTaxed;
                m_price = right.m_price;
                m_qty = right.m_qty;
            }
        }
        return *this;
    }
    Item::~Item()
    {
        delete [] m_name;
    }
    bool Item::operator==(const char* right) const
    {
        return !strcmp(m_SKU, right);
    }

    bool Item::operator>(const Item& right) const
    {
        return strcmp(m_name, right.m_name) > 0;
    }
    int Item::operator+=(int right)
    {
        m_qty += right;
        if (m_qty > MAX_STOCK_NUMBER) {
            m_qty = MAX_STOCK_NUMBER;
            m_error = ERROR_POS_QTY;
        }
        return m_qty;
    }
    int Item::operator-=(int right)
    {
        m_qty -= right;
        if (right > m_qty) {
            m_qty = 0;
            m_error = ERROR_POS_STOCK;
        }
        return m_qty;
    }
    Item::operator bool() const
    {
        return !m_error;
    }
    ostream& Item::write(ostream& os) const
    {
        char tempName[21] = { 0 };
        
        if (*this)
        {
            if(POS_LIST == m_displayType)
            {
                os.width(7);    os.setf(ios::left); os << m_SKU; os.unsetf(ios::left);
                os << "|";
            
                if (strlen(m_name) > 20)
                {
                    strncpy(tempName, m_name, 20);
                    os.width(20); os.setf(ios::left); os << tempName; os.unsetf(ios::left);
                    os << "|";
                }
                else{
                    os.width(20);    os.setf(ios::left); os << m_name; os.unsetf(ios::left);
                    os << "|";
                }
                os.width(7);    os.setf(ios::right); os.setf(ios::fixed); os.precision(2); os << m_price; os.unsetf(ios::right);
                if(m_isTaxed)
                {
                    os << "| X |";
                }
                else
                {
                    os << "|   |";
                }
                os.width(4);    os.setf(ios::right); os << quantity(); os.unsetf(ios::right);
                os << "|";
                os.width(9);    os.setf(ios::right); os << cost() * quantity(); os.unsetf(ios::right);
                os << "|";
            }
            else if(POS_FORM == m_displayType)
            {
                os << "=============v" << endl << "Name:        " << m_name << endl;
                os << "Sku:         " << m_SKU << endl;
                os << "Price:       " << m_price << endl;
                os << "Price + tax: ";
                if (m_isTaxed)
                {
                    os << m_price * (1 + TAX) << endl;

                }
                else if(!m_isTaxed)
                {
                    os << "N/A" << endl;
                }
                os << "Stock Qty:   " << quantity() << endl;
            }
        }
        else
        {
            os << m_error;
        }
        return os;
    }
    ofstream& Item::save(ofstream& os) const//파일에 아웃풋저장
    {
        if (m_error)
        {
            os << m_error;
        }
        else
        {
            os << itemType() << "," << m_SKU << "," << m_name << ",";
            os.setf(ios::fixed); os.precision(2); os << m_price << "," << m_isTaxed << "," << m_qty;
        }
        return os;
    }
    istream& Item::read(istream& is)
    {
        char tempSKU[100+1] = { 0 };
        char tempName[100+1] = { 0 };
        char tempTaxed = '\0';
        double tempPrice = 0.0;
        int tempQty = 0;
        bool done = true;
        
        cout << "Sku" << endl << "> ";
        do
        {
            done = true;
            is.getline(tempSKU, MAX_SKU_LEN, '\n');//getline. ignore
            if (is.fail() || strlen(tempSKU) > MAX_SKU_LEN)
            {
                if (is.fail())
                {
                    is.clear(); //인풋스트림이 페일하면 클리어해줘야함
                    is.ignore(MAX_SKU_LEN, '\n');
                }
                cout << ERROR_POS_SKU << endl << "> ";
                done = false;
            }
            else
            {
                strcpy(m_SKU, tempSKU);
                done = true;
            }
        } while (!done);

        cout << "Name" << endl << "> ";
        do
        {
            done = true;
            is.getline(tempName, MAX_NAME_LEN, '\n');
            if (is.fail() || strlen(tempName) > MAX_NAME_LEN)
            {
                if (is.fail())
                {
                    is.clear(); //인풋스트림이 페일하면 클리어해줘야함
                    is.ignore(MAX_NAME_LEN, '\n');
                }
                cout << ERROR_POS_NAME << endl << "> ";
                done = false;
            }
            else
            {
                if (m_name)
                {
                    delete[] m_name;
                }
                m_name = nullptr;
                m_name = new char[strlen(tempName) + 1];
                strcpy(m_name, tempName);
                done = true;
            }
        } while (!done);

        cout << "Price" << endl << "> ";
        do
        {
            done = true;
            is >> tempPrice;
            if (is.fail() || tempPrice <= 0.0)
            {
                if (is.fail())
                {
                    is.clear(); //인풋스트림이 페일하면 클리어해줘야함
                    is.ignore(10, '\n');
                }
                cout << ERROR_POS_PRICE << endl << "> ";
                done = false;
            }
            else
            {
                m_price = tempPrice;
                done = true;
            }
        } while (!done);

        cout << "Taxed?" << endl << "(Y)es/(N)o: ";
            is.ignore(10, '\n');
        do
        {
            done = true;
            is >> tempTaxed;
            if (is.fail() || (tempTaxed != 'y' && tempTaxed != 'n'))
            {
                is.clear(); //인풋스트림이 페일하면 클리어해줘야함
                is.ignore(10, '\n');
                cout << "Only 'y' and 'n' are acceptable: ";
                done = false;
            }
            else
            {
                if (tempTaxed == 'y')
                {
                    //m_isTaxed = true;
                    m_isTaxed = true;
                    done = true;
                }
                else if (tempTaxed == 'n')
                {
                    m_isTaxed = false;
                    done = true;
                }
            }
        } while (!done);

        cout << "Quantity" << endl << "> ";
        do
        {
            done = true;
            is >> tempQty;
            if (is.fail() || tempQty < 1 || tempQty > MAX_STOCK_NUMBER)
            {
                if (is.fail())
                {
                    is.clear(); //인풋스트림이 페일하면 클리어해줘야함
                    is.ignore(10, '\n');
                }
                cout << ERROR_POS_QTY << endl << "> ";
                done = false;
            }
            else
            {
                m_qty = tempQty;
                done = true;
            }
        } while (!done);

        return is;
    }
    ifstream& Item::load(ifstream& is)//파일에서 읽어옴(한번에 다받고 마지막에 벨리데이션, 인풋스트림이 페일인지 확인하고 벨리데이션)
    {
        char tempSKU[101] = { 0 };
        char tempName[101] = { 0 };
        double tempPrice = 0.0;
        bool tempTaxed;
        int tempQty = 0;
        bool isFail = false;
        
        m_error = Error(); //clear error

        is.getline(tempSKU, 100, ',');
        if (is.fail()) //SKU
        {
            isFail = true;
            is.clear();
            is.ignore(1000, ',');
            m_error = ERROR_POS_SKU;
        }
        
        if (!isFail)
        {
            is.getline(tempName, 100, ','); //겟라인은 구분자의 이그노어포함
            if (is.fail()) //Name
            {
                isFail = true;
                is.clear();
                is.ignore(1000, ',');
                m_error = ERROR_POS_NAME;
            }
        }

        if (!isFail)
        {
            is >> tempPrice;
            if (is.fail()) //price
            {
                isFail = true;
                is.clear();
                is.ignore(1000, ',');
                m_error = ERROR_POS_PRICE;
            }
        }

        if (!isFail) //taxed
        {
            is.ignore();//얘는 캐릭터 하나 무시하는것
            is >> tempTaxed;
            if (is.fail())
            {
                isFail = true;
                is.clear();
                is.ignore(1000, ',');
                m_error = ERROR_POS_TAX;
            }
        }

        if (!isFail) //Qty
        {
            is.ignore();//얘는 캐릭터 하나 무시하는것
            is >> tempQty;
            if (is.fail())
            {
                isFail = true;
                is.clear();
                is.ignore(1000, ',');
                m_error = ERROR_POS_QTY;
            }
        }


        if (!isFail)
        {
            if (strlen(tempSKU) > MAX_SKU_LEN)
            {
                m_error = ERROR_POS_SKU;
                isFail = true;               
            }

            if (!isFail)
            {
                if (strlen(tempName) > MAX_NAME_LEN)
                {
                    m_error = ERROR_POS_NAME;
                    isFail = true;
                }
            }

            if (!isFail)
            {
                if (tempPrice < 1)
                {
                    m_error = ERROR_POS_PRICE;
                    isFail = true;
                }
            }

            if (!isFail)
            {
                if (tempTaxed != 0 && tempTaxed != 1)
                {
                    m_error = ERROR_POS_TAX;
                    isFail = true;
                }
            }

            if (!isFail)
            {
                if (tempQty < 1 || tempQty > MAX_STOCK_NUMBER)
                {
                    m_error = ERROR_POS_QTY;
                    isFail = true;
                }
            }
        }
        
        if(!isFail)
        {
            for (int i = 0; i < MAX_SKU_LEN; i++)
            {
                m_SKU[i] = tempSKU[i];
            }
            if (m_name)
            {
                delete [] m_name;
            }
            m_name = nullptr;
            m_name = new char[strlen(tempName) + 1];
            strcpy(m_name, tempName);

            m_price = tempPrice;
            if(tempTaxed == 1)
            {
                m_isTaxed = true;
            }
            else if (tempTaxed == 0)
            {
                m_isTaxed = false;
            }
            m_qty = tempQty;
        }
        return is;
    }
    ostream& Item::bprint(ostream& os) const
    {
        char tempName[21] = { 0 };
        
        //os.setf(ios::left); cout << m_SKU; os.unsetf(ios::left);
        os << "| ";
        if (strlen(m_name) > 20)
        {
            strncpy(tempName, m_name, 20);
            tempName[20] = '\0';
            os.width(20); os.setf(ios::left); os << tempName; os.unsetf(ios::left);
            /*for (int i = 0; i < 20; i++)
            {
                //os << tempName[i];
            }*/
            //os.unsetf(ios::left);
            os << "|";
        }
        else{
            os.width(20); os.setf(ios::left); os << m_name;
            os.unsetf(ios::left);
            os << "|";
        }
        os.width(10);
        os.setf(ios::right);
        if (m_isTaxed)
        {
            os << m_price * (1+TAX); os.unsetf(ios::right);
        }
        else
        {
            os << m_price; os.unsetf(ios::right);
        }
        
        if(m_isTaxed)
        {
            os << " |  " << itemType() << "  |" << endl;
        }
        else
        {
            os << " |     |" << endl;
        }
        return os;
    }
    void Item::setEmpty()
    {
        m_SKU[0] = 0;
        if (m_name)
        {
            delete[] m_name;
        }
        m_name = nullptr;
        m_price = 0;
        m_isTaxed = false;
        m_qty = 0;
        m_displayType = 0;
        m_error.clear();
    }
    char Item::itemType() const
    {
        return m_isTaxed? 'T' : ' ';
    }
    Item& Item::displayType(int pos)
    {
        if (pos == POS_LIST)
        {
            m_displayType = pos;
        }
        else if(pos == POS_FORM)
        {
            m_displayType = pos;
        }
        return *this;
    }
    double Item::cost() const
    {
        return m_isTaxed ? m_price * (1 + TAX) : m_price;
    }
    int Item::quantity() const
    {
        return m_qty;
    }
    Item& Item::clear()
    {
        m_error.clear();
        return *this;
    }
    double operator+=(double& left, const Item& right)
    {
        left += right.cost() * right.quantity();
        return left;
    }
}
