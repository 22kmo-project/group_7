const db = require('../database');

const transaction = {
  getById: function(id, callback) {
    return db.query('select * from transaction where id_transaction=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from transaction', callback);
  },
  add: function(transaction, callback) {
    return db.query(
      'insert into transaction (DATE,transaction,balance) values(?,?,?)',
      [transaction.DATE, transaction.transaction, transaction.balance],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transaction where id_transaction=?', [id], callback);
  },
  update: function(id, transaction, callback) {
    return db.query(
      'update transaction set DATE=?,transaction=?, balance=? where id_transaction=?',
      [transaction.DATE, transaction.transaction, transaction.balance, id],
      callback
    );
  }
};
module.exports = transaction;