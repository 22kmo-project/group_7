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
      'insert into transaction (id_account,id_card,event_date,event,balance) values(?,?,?,?,?)',
      [transaction.id_account, transaction.id_card, transaction.event_date, transaction.event, transaction.balance],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transaction where id_transaction=?', [id], callback);
  },
  update: function(id, transaction, callback) {
    return db.query(
      'update transaction set id_account=?,id_card=?,event_date=?,event=?,balance=? where id_transaction=?',
      [transaction.id_account, transaction.id_card, transaction.event_date, transaction.event, transaction.balance, id],
      callback
    );
  }
};
module.exports = transaction;