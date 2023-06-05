#include <iostream>
#include <string>

using namespace std;

class DataBase
{
public:
    virtual void insert_data() = 0;
};

class Sqlite3 : public DataBase
{
public:
    virtual void insert_data() override
    {
    }
};

class Mysql : public DataBase
{
public:
    virtual void insert_data() override
    {
    }
};

class PQLsql : public DataBase
{
public:
    virtual void insert_data() override
    {
    }
};

//

class DBFactory
{
public:
    static DataBase *createDB(string name)
    {
        DataBase *pb;
        if (name == "sqlite3")
        {
            pb = new Sqlite3();
        }
        else if (name == "mysql")
        {
            pb = new Mysql();
        }
    }
};

class Insert
{
    void insert()
    {

    }
    DataBase *db;
};

class AddressBook
{
public:
    AddressBook(DataBase *db)
    {
        this->db = db;
    }
    //Sqlite3 *db;
    DataBase *db;
};



int main()
{
    string name;
    std::cin >> name;
    DataBase *pb = DBFactory::createDB(name);
    // DataBase *pb = new Mysql();
    pb->insert_data();

    AddressBook manger(pb);

    return 0;
}