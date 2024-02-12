#pragma once

#include "Employee.hpp"

#include <list>
#include <string>
#include <iostream>

class Department
{
public:
    Department(const std::string& name)
        : _name { name }
    {}

    Employee& add_employee(const std::string& name, unsigned int salary, Employee* manager)
    {
        auto& employee = _employees.emplace_back(name, salary);

        if (manager != nullptr)
        {
            manager->add_subordinate(employee);
        }

        return employee;
    }

    void print_employees(){
        for (auto employee:_employees){
            std::cout << employee << std::endl;
        }
    }

    void print_dep(){
        std::cout << _name << std::endl;
    }

    void remove_subodinate_for_all_employee(Employee& e){
        for (auto& employee:_employees){
            employee.remove_subodinate(e);
        }
        _employees.remove(e);
    }

private:
    std::string _name;
    std::list<Employee> _employees;
};
