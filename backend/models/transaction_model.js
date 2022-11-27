const db = require('../database');

const transaction = {
  //Tämä tulee sovelluksen näytä saldo -kohtaan, hakee 10 viimeisintä tilitapahtumaa
  //getTenTransactions: function(id, callback) {
    //return db.query('select * from transaction where id_account=? limit 10;', [id], callback);
  //},

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
  }
};

module.exports = transaction;