#pragma once

#include "Department.hpp"

#include <list>
#include <string>
#include <iostream>

class HRSoftSystem
{
public:
    Department& add_department(const std::string& name)
    {
        return _departments.emplace_back(name);
    }

    void print_all_employees(){
        for (auto dep:_departments){
            dep.print_employees();
        }
    }

    void print_all_departments(){
        for (auto dep:_departments){
            dep.print_dep();
        }
    }

    void remove_employee(Employee& employee){
        for (auto& dep:_departments){
            dep.remove_subodinate_for_all_employee(employee);
        }
    }
    
private:
    std::list<Department> _departments;
};
