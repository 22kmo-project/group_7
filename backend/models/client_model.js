const db = require('../database');

const client = {
  getById: function(id, callback) {
    return db.query('select * from client where id_client=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from client', callback);
  },
  add: function(client, callback) {
    return db.query(
      'insert into client (fname,lname,addr_street,addr_municipality,phone_num) values(?,?,?,?,?)',
      [client.fname, client.lname, client.addr_street, client.addr_municipality, client.phone_num],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from client where id_client=?', [id], callback);
  },
  update: function(id, client, callback) {
    return db.query(
      'update client set fname=?,lname=?,addr_street=?,addr_municipality=?,phone_num=? where id_client=?',
      [client.fname, client.lname, client.addr_street, client.addr_municipality, client.phone_num, id],
      callback
    );
  }
};
module.exports = client;