const db = require('../database');

const account = {
  getById: function(id, callback) {
    return db.query('select * from account where id_account=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into account (balance) values(?)',
      [add_data.balance],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update account set balance=? where id_account=?',
      [update_data.balance, id],
      callback
    );
  }
};
module.exports = account;