#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include "sqlite3.h"

class Contact {
public:
    Contact(const std::string& name, const std::string& gender, const std::string& phone,
        const std::string& email, const std::string& address)
        : name_(name), gender_(gender), phone_(phone), email_(email), address_(address) {}

    std::string getName() const {
        return name_;
    }

    std::string getGender() const {
        return gender_;
    }

    std::string getPhone() const {
        return phone_;
    }

    std::string getEmail() const {
        return email_;
    }

    std::string getAddress() const {
        return address_;
    }

private:
    std::string name_;
    std::string gender_;
    std::string phone_;
    std::string email_;
    std::string address_;
};

class AddressBook {
public:
    AddressBook() {
        int result = sqlite3_open(":memory:", &db_);
        if (result != SQLITE_OK) {
            std::cout << "Failed to open database." << std::endl;
            return;
        }

        std::string sql = "CREATE TABLE contacts ("
                          "name TEXT, gender TEXT, phone TEXT, email TEXT, address TEXT);";
        result = sqlite3_exec(db_, sql.c_str(), nullptr, nullptr, nullptr);
        if (result != SQLITE_OK) {
            std::cout << "Failed to create table." << std::endl;
            return;
        }
    }

    ~AddressBook() {
        sqlite3_close(db_);
    }

    void addContact(const Contact& contact) {
        std::string sql = "INSERT INTO contacts VALUES (?, ?, ?, ?, ?);";
        sqlite3_stmt* stmt;
        int result = sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr);
        if (result != SQLITE_OK) {
            std::cout << "Failed to prepare statement." << std::endl;
            return;
        }

        sqlite3_bind_text(stmt, 1, contact.getName().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, contact.getGender().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, contact.getPhone().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, contact.getEmail().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 5, contact.getAddress().c_str(), -1, SQLITE_STATIC);

        result = sqlite3_step(stmt);
        if (result != SQLITE_DONE) {
            std::cout << "Failed to execute statement." << std::endl;
        }

        sqlite3_finalize(stmt);
    }

    void updateContact(const Contact& contact) {
        std::string sql = "UPDATE contacts SET gender = ?, phone = ?, email = ?, address = ? WHERE name = ?;";
        sqlite3_stmt* stmt;
        int result = sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr);
        if (result != SQLITE_OK) {
            std::cout << "Failed to prepare statement." << std::endl;
            return;
        }

        sqlite3_bind_text(stmt, 1, contact.getGender().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, contact.getPhone().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, contact.getEmail().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, contact.getAddress().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 5, contact.getName().c_str(), -1, SQLITE_STATIC);

        result = sqlite3_step(stmt);
        if (result != SQLITE_DONE) {
            std::cout << "Failed to execute statement." << std::endl;
        }

        sqlite3_finalize(stmt);
    }

    void deleteContact(const std::string& name) {
        std::string sql = "DELETE FROM contacts WHERE name = ?;";
        sqlite3_stmt* stmt;
        int result = sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr);
        if (result != SQLITE_OK) {
            std::cout << "Failed to prepare statement." << std::endl;
            return;
        }

        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

        result = sqlite3_step(stmt);
        if (result != SQLITE_DONE) {
            std::cout << "Failed to execute statement." << std::endl;
        }

        sqlite3_finalize(stmt);
    }

    std::vector<Contact> getAllContacts() {
        std::vector<Contact> contacts;

        std::string sql = "SELECT * FROM contacts;";
        sqlite3_stmt* stmt;
        int result = sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr);
        if (result != SQLITE_OK) {
            std::cout << "Failed to prepare statement." << std::endl;
            return contacts;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            std::string gender = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            std::string phone = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            std::string address = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

            contacts.emplace_back(name, gender, phone, email, address);
        }

        sqlite3_finalize(stmt);

        return contacts;
    }

private:
    sqlite3* db_;
};

class AddressBookFactory {
public:
    static std::shared_ptr<AddressBook> createAddressBook() {
        return std::make_shared<AddressBook>();
    }
};

class CommandLineInterface {
public:
    CommandLineInterface(std::shared_ptr<AddressBook> addressBook)
        : addressBook_(addressBook) {}

    void run() {
        while (true) {
            std::cout << "======== Address Book ========" << std::endl;
            std::cout << "1. Add Contact" << std::endl;
            std::cout << "2. Update Contact" << std::endl;
            std::cout << "3. Delete Contact" << std::endl;
            std::cout << "4. View All Contacts" << std::endl;
            std::cout << "5. Exit" << std::endl;
            std::cout << "==============================" << std::endl;
            std::cout << "Enter your choice: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addContact();
                    break;
                case 2:
                    updateContact();
                    break;
                case 3:
                    deleteContact();
                    break;
                case 4:
                    printAllContacts();
                    break;
                case 5:
                    return;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
        }
    }

private:
    void addContact() {
        std::string name, gender, phone, email, address;
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Gender: ";
        std::getline(std::cin, gender);
        std::cout << "Enter Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Enter Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter Address: ";
        std::getline(std::cin, address);

        Contact contact(name, gender, phone, email, address);
        addressBook_->addContact(contact);

        std::cout << "Contact added successfully." << std::endl;
    }

    void updateContact() {
        std::string name, gender, phone, email, address;
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Gender: ";
        std::getline(std::cin, gender);
        std::cout << "Enter Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Enter Email: ";
        std::getline(std::cin, email);
        std::cout << "Enter Address: ";
        std::getline(std::cin, address);

        Contact contact(name, gender, phone, email, address);
        addressBook_->updateContact(contact);

        std::cout << "Contact updated successfully." << std::endl;
    }

    void deleteContact() {
        std::string name;
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);

        addressBook_->deleteContact(name);

        std::cout << "Contact deleted successfully." << std::endl;
    }

    void printAllContacts() {
        std::vector<Contact> contacts = addressBook_->getAllContacts();

        std::cout << "======= All Contacts =======" << std::endl;
        for (const Contact& contact : contacts) {
            std::cout << "Name: " << contact.getName() << std::endl;
            std::cout << "Gender: " << contact.getGender() << std::endl;
            std::cout << "Phone: " << contact.getPhone() << std::endl;
            std::cout << "Email: " << contact.getEmail() << std::endl;
            std::cout << "Address: " << contact.getAddress() << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
        std::cout << "=============================" << std::endl;
    }

    std::shared_ptr<AddressBook> addressBook_;
};

int main() {
    std::shared_ptr<AddressBook> addressBook = AddressBookFactory::createAddressBook();
    CommandLineInterface cli(addressBook);
    cli.run();

    return 0;
}
