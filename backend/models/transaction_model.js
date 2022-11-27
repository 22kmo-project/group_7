const db = require('../database');

const transaction = {
  getById: function(id, callback) {
    return db.query('select * from transaction where id_transaction=?', [id], callback);
  },
  
  getAll: function(callback) {
    return db.query('select * from transaction', callback);
  },
  
  add: function(add_data, callback) {
    return db.query(
      'insert into transaction (id_account,id_card,transaction_date,transaction,amount) values(?,?,?,?,?)',
      [add_data.id_account, add_data.id_card, add_data.transaction_date, add_data.transaction, add_data.amount],
      callback
    );
  },
  
  delete: function(id, callback) {
    return db.query('delete from transaction where id_transaction=?', [id], callback);
  },
  
  update: function(id, update_data, callback) {
    return db.query(
      'update transaction set id_account=?,id_card=?,transaction_date=?,transaction=?,amount=? where id_transaction=?',
      [update_data.id_account, update_data.id_card, update_data.transaction_date, update_data.transaction, update_data.amount, id],
      callback
    );
  },
  getTenTransactions: function(id,callback){
    return db.query('select transaction.transaction as "tapahtuman laji", transaction_date as "päivämäärä", transaction.balance as "summa" from transaction inner join account on transaction.id_account=account.id_account inner join card on card.id_client=account.id_client where card.id_card=? limit 10;',[id],callback);
  }
};

module.exports = transaction;