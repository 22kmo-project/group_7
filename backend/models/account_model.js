const db = require('../database');

const account = {
  getById: function(id, callback) {
    return db.query('select * from account where id_account=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account', callback);

  },
  delete: function(id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);

  }
};
module.exports = account;