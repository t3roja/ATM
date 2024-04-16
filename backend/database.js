/*const mysql = require('mysql2');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: 'netuser',
  password: 'netpass',
  database: 'bank_automat'
});
module.exports = connection;*/

const mysql = require('mysql2');
const dotenv = require('dotenv');
dotenv.config();

const conn="mysql://avnadmin:AVNS_LboqcJSqlpoD97kgefH@my-sql-atm-test.a.aivencloud.com:15120/bank_automat";

const connection=mysql.createPool(conn);

module.exports = connection;