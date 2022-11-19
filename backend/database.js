const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'group_7',
  password: 'netpass',
  database: 'group_7'
});
module.exports = connection;


