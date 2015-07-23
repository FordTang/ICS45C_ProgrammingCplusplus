//Created by Ford Tang, 46564602
//ICS45C

#include <iostream>
#include <string>

int main()
{
    std::string first_name, last_name, email;
    std::cout << "Please enter your first name:  ";
    std::getline(std::cin, first_name);
    std::cout << "Please enter your last name:  ";
    std::getline(std::cin,last_name);
    std::cout << "Please enter your email address:  ";
    std::getline(std::cin, email);
    std::cout << std::endl << "From: Customer Service <customer_service@ics45c.com>" << std::endl << "To: " << first_name << " " << last_name << " <" << email << ">" << std::endl << "Subject: ICS45C appreciates your business!" << std::endl << std::endl << "Dear " << first_name << " " << last_name << ":" << std::endl << std::endl << "We are writing today to thank you for your business, and to invite you" << std::endl <<"to contact us if you have any comments and concerns about your recent" << std::endl <<"order.  If so, please email us at customer_service@ics45c.com and we" << std::endl << "would be delighted to discuss them with you." << std::endl << std::endl << std::endl << "Many Thanks," << std::endl <<std::endl << "ICS45C Customer Service Team" << std::endl <<std::endl;

    return 0;
}

