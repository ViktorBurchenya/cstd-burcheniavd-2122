#include <string>
#include <iostream>
#include <unistd.h>
#include <list>
#include <vector>
#include <algorithm>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/resultset_metadata.h>

using namespace sql;
using namespace std;

int main(int argc, char* argv[]) {
    int opt;
    vector<string> column_name_list;

    // Shut GetOpt error messages down (return '?'): 
    opterr = 0;

    // Retrieve the options:
    while ((opt = getopt(argc, argv, "F:")) != -1) {  // for each option...
        if (opt == 'F') {
            column_name_list.insert(column_name_list.end(), string(optarg));
        }
    }
    string queries;
    for (unsigned i = 1; i < argc; i++) {
        if (string(argv[i]) != "-F" && find(column_name_list.begin(), column_name_list.end(), argv[i]) == column_name_list.end()) {
            queries += "'" + string(argv[i]) + "',";
        }
    }

    string columns;
    for (unsigned i = 0; i < column_name_list.size(); i++) {
        columns += column_name_list[i] + ",";
    }
    columns.erase(columns.size() - 1);
    queries.erase(queries.size() - 1);

    try {
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        driver = get_driver_instance();

        con = driver->connect("sql_adress", "user", "nope"); // Join a server
        con->setSchema("database_name"); // Use a database

        stmt = con->createStatement();
        res = stmt->executeQuery(string("select " + columns + " from table_name where accession in (" + queries + ")"));

        sql::ResultSetMetaData* res_meta = res->getMetaData();
        int cols = res_meta->getColumnCount();
        if (res->rowsCount() == 0) {
            cout << "Query not found!" << endl;
            return 0;
        }
        while (res->next()) {
            for (unsigned i = 1; i <= cols; i++) {
                cout << res->getString(i) << endl;
            }
        }
        delete res;
        delete stmt;
        delete con;
    }
    // No idea about this part yet, copied it from a tutorial
    catch (sql::SQLException& e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return 0;
}