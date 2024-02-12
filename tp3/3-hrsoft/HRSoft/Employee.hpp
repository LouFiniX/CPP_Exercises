#pragma once

#include <list>
#include <iostream>
#include <string>

class Employee
{
public:
    Employee(const std::string& name, unsigned int salary)
        : _name { name }, _salary { salary }
    {}

    void add_subordinate(Employee& subordinate)
    {
        _subordinates.emplace_back(&subordinate);
    }

    void print_subordinates(){
        for (auto e:_subordinates){
            std::cout << *e << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream&, const Employee&);

    void remove_subodinate(Employee& employee){
        _subordinates.remove(&employee);
    }

    int operator==(Employee other){
        return other._name == _name && other._salary == _salary;
    }

private:
    std::string _name;
    unsigned int _salary = 0;
    std::list<Employee*> _subordinates;
};

inline std::ostream& operator<<(std::ostream& stream, const Employee& employee)
{
    const auto is_manager = !employee._subordinates.empty();
    return stream << employee._name
                  << " (salary: " << employee._salary
                  << "| manager: " << (is_manager ? "yes" : "no")
                  << ")";
}
