#ifndef EX2_42_H_
#define EX2_42_H_

#include <string>
#include <iostream>

struct Sales_data { 
    std::string bookNo; 
    unsigned units_sold = 0; 
    double revenue = 0.0;
    
    void calRevenue(double price);
    double calAvgPrice();
    void setData(Sales_data data);
    void addData(Sales_data data);
    void printData();
    };

    void Sales_data::calRevenue(double price) {
        revenue = units_sold * price;
    }

    double Sales_data::calAvgPrice() {
        if (units_sold != 0) {
            return revenue / units_sold;
        } else {
            return 0.0;
        }
    }

    void Sales_data::setData(Sales_data data) {
        bookNo = data.bookNo;
        units_sold = data.units_sold;
        revenue = data.revenue;
    }

    void Sales_data::addData(Sales_data data) {
        if (bookNo != data.bookNo) return;
        units_sold += data.units_sold;
        revenue += data.revenue;
    }

    void Sales_data::printData() {
        std::cout << bookNo << " " << units_sold << " " << revenue
                  << " ";
        double avgPrice = calAvgPrice();
        if (avgPrice != 0.0) {
            std::cout << avgPrice << std::endl;
        } else {
            std::cout << "(no sales)" << std::endl; 
        }
    }

#endif // EX2_42_H_