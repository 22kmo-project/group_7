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
      'insert into account (id_client,balance) values(?,?)',
      [add_data.id_client, add_data.balance],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },

  update: function(id, update_data, callback) {
    return db.query(
      'update account set id_client=?,balance=? where id_account=?',
      [update_data.id_client, update_data.balance, id],
      callback
    );
  },

  getAllBalances: function(callback){
    return db.query('select client.id_client, account.id_account, concat(fname," ",lname) as "client_name", balance from client inner join account on client.id_client=account.id_client inner join card on card.id_account=account.id_account',
    callback);
  },
  
  getOneBalance: function(id,callback){
    return db.query('select client.id_client, account.id_account, concat(fname," ",lname) as "client_name", balance from client inner join account on client.id_client=account.id_client inner join card on card.id_account=account.id_account where card.id_card=?',[id],
    callback);
  }
};
module.exports = account;