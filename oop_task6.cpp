#include <iostream>
#include <bits/stdc++.h>

class Staff
{
	private:


	protected:
		std::string fullName;
		int baseSalary;
		int expYear;

		Staff(std::string fname, int bs, int exp)
			: fullName(fname), baseSalary(bs), expYear(exp)
		{}

	public:
		
		std::vector<Staff *> staffList;
		Staff() 
		{
			std::cout << "Create an empty Staff to manage all staff in stafflist \n";
		}

		~Staff() {
			std::cout << " Staff named : " << fullName << " has been deleted \n";
		}

		void showAllStaff()
		{
				std::cout << std::setw(30) << std::left << "Full Name" << std::setw(15)
				<< std::right << "NET Salary" << std::setw(25) << std::right << "Years of experience \n";
				std::cout << "----------------------------------------------------------------------- \n";
			for (auto &iter : staffList)
			{
				std::cout << std::setw(30) << std::left << iter->fullName << std::setw(15)
				<< std::right << iter->salaryStatistic() << std::setw(25) << std::right << iter->expYear << "\n";
			}
		}

		void addStaff(Staff *stf)
		{
			staffList.push_back(stf);
		}

		void removeStaff(Staff *stf)
		{
			staffList.erase(std::remove(staffList.begin(), staffList.end(), stf), staffList.end());
		}

		/* "unnecessary"
		void removeStaff(std::string name)
		{
			staffList.erase(std::remove_if(staffList.begin(), staffList.end(), [&name](auto const &iter)
						{return iter->fullName == name;}), staffList.end());
		}*/

		void modifyStaff(std::string name, std::string newName, int salary, int expy)
		{
			for (auto &iter : staffList)
			{
				if (iter->fullName == name)
				{
					iter->fullName = newName;
					iter->baseSalary = salary;
					iter->expYear = expy;
				}
			}
		}
		
		virtual void introduce()
		{
			std::cout << "My name is : " << fullName << " - " << " My salary is : " << baseSalary << "\n"; 
		}


		virtual int salaryStatistic()
		{
			return baseSalary;
		}

};

class HR : public Staff
{
	public:
		HR(std::string fname, int bs, int exp)
			: Staff(fname, bs, exp) {}
		~HR() {}
};

class Coder : public Staff
{
	public:
		Coder(std::string fname, int bs, int exp)
			: Staff(fname, bs, exp) {}

		~Coder() {}

		int salaryStatistic()
		{
			int coderSalary = baseSalary + 0.15*baseSalary;
			return coderSalary;
		}
};

class BusinessStaff : public Staff
{
	public:
		int contract;
		BusinessStaff(std::string fname, int bs, int exp, int ctr)
			: Staff(fname, bs, exp)
		{
			contract = ctr;
		}

		~BusinessStaff() {}


		int salaryStatistic()
		{
			int busnSalary = baseSalary + 0.01*contract*baseSalary; 
			return busnSalary;
		}
};

int main()
{
	Staff *nhung = new HR("Hong Nhung", 7000000, 2);
	Staff *anquang = new Coder("An Quang", 12000000, 2);
	Staff *marina = new BusinessStaff("Marina Shiraishi", 11500000, 4, 6);

	Staff *staff = new Staff();    		//tao staff de su dung vector stafflist
	std::vector<Staff *> stflist;
	staff->staffList = stflist;
	staff->addStaff(nhung);
	staff->addStaff(marina);
	staff->addStaff(anquang);
	staff->modifyStaff("An Quang", "VOZer wibu fan MU", 15325000, 6);
	staff->showAllStaff();

	//delete staff;
	staff->removeStaff(marina);
	delete marina;
	staff->showAllStaff();
	return 0;
}
