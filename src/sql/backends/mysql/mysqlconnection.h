/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef _FNORDMETRIC_MYSQLBACKEND_MYSQLCONNECTION_H
#define _FNORDMETRIC_MYSQLBACKEND_MYSQLCONNECTION_H
#include <memory>
#include <fnordmetric/sql/backend.h>
#include <fnordmetric/util/runtimeexception.h>
#include <mysql.h>

namespace fnordmetric {
namespace query {
namespace mysql_backend {

class MySQLConnection {
public:

  /**
   * Creates a new mysql connection and tries to connect to the provided URI
   * May throw an exception
   *
   * Example URIs:
   *    mysql://localhost/test_database?user=root
   *    mysql://somehost:3306/my_database?user=my_user&password=my_secret
   *
   * @param URI the mysql:// URI
   * @returns a new MySQLConnection
   */
  static std::unique_ptr<MySQLConnection> openConnection(const util::URI& uri);

  /**
   * Create a new mysql connection
   */
  MySQLConnection();

  /**
   * Destroy a mysql connection. Closes the connection
   */
  ~MySQLConnection();

  /**
   * Connect to a mysql server on the specified URI. May throw an exception
   *
   * Example URIs:
   *    mysql://localhost/test_database?user=root
   *    mysql://somehost:3306/my_database?user=my_user&password=my_secret
   *
   * @param URI the mysql:// URI
   * @returns a new MySQLConnection
   */
  void connect(const util::URI& uri);

  /**
   * Connect to a mysql server. May throw an exception
   *
   * @param host the mysql server hostname
   * @param port the mysql server port
   * @param database the mysql database to open or empty string
   * @param username the mysql user username or empty string
   * @param password the mysq user password or empty string
   * @returns a new MySQLConnection
   */
  void connect(
      const std::string& host,
      unsigned int port,
      const std::string& database,
      const std::string& username,
      const std::string& password);

protected:
   MYSQL* mysql_;
};

}
}
}
#endif
