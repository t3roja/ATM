const mysql = require('mysql2');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: 'netuser',
  password: 'netpass',
  database: 'bank_automat'
});
module.exports = connection;
/*
const mysql = require('mysql2');
const connection = mysql.createPool({
  host: 'my-sql-atm-test.a.aivencloud.com',
  user: 'avnadmin',
  password: 'AVNS_HVZe7dIzEagkrFXRugn',
  database: 'bank_automat',
  port: '15120',
});
module.exports = connection;*/