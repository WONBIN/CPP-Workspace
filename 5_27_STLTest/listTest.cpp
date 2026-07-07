// struct ContactItem (string ContactName, strPhoneNumber, strDisplayPresentation)
// use STL list to stroe the contact items
#include <iostream>
#include <list>
#include <string>

using namespace std;

struct ContactItem
{
    string strContactName;
    string strPhoneNumber;
    string strDisplayPresentation;

    ContactItem(const string& name, const string& phoneNumber)
    {
        strContactName = name;
        strPhoneNumber = phoneNumber;
        strDisplayPresentation = name + " (" + phoneNumber + ")";
    }
    // overload the < operator for sorting by the name 
    bool operator<(const ContactItem& other) const
    {
        return strContactName > other.strContactName; // Sort by contact name
    }
};

void DisplayContacts(const list<ContactItem>& contacts)
{
    for (const auto& contact : contacts)
    {
        cout << "Name: " << contact.strContactName << endl;
        cout << "Phone Number: " << contact.strPhoneNumber << endl;
        cout << "Display Presentation: " << contact.strDisplayPresentation << endl;
    }
}

bool SortonPhoneNumber(const ContactItem& a, const ContactItem& b)
{
    return a.strPhoneNumber < b.strPhoneNumber;
}
// used by list::remove() given  
bool operator==(const ContactItem& other) const{
    return strContactName == other.strContactName;
}
int main()
{
    list<ContactItem> contacts;

    contacts.push_back(ContactItem("Jane Rolling", "123-456-7890"));
    contacts.push_back(ContactItem("Sam Altman", "987-654-3210"));
    contacts.emplace_back("John Doe", "123-456-7890");
    contacts.emplace_back("Jane Smith", "987-654-3210");

    cout << "Contact List" << endl;
    DisplayContacts(contacts);
    contacts.sort();    
    cout << "\nSorted Contact List" << endl;
    DisplayContacts(contacts);
    contacts.sort(SortonPhoneNumber);
    contacts.remove(ContactItem("Zob",""));
    contacts.remove_if([](const ContactItem& contact)
    
        {return contact.strContactName == "Charlie";});

        //Find a contact by name
        auto it = std::find_if(contacts.begin(), contacts.end(), [](const ContactItem& contact)
        {
            return contact.strContactName == "Alice";
        });

    return 0;
}