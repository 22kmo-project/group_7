const db = require('../database');

const account = {
  getById: function(id, callback) {
    return db.query('select * from account where id_account=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  add: function(account, callback) {
    return db.query(
      'insert into account (id_client,balance) values(?,?)',
      [account.id_client, account.balance],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(
      'update account set id_client=?,balance=? where id_account=?',
      [account.id_client, account.balance, id],
      callback
    );
  }
};
module.exports = account;