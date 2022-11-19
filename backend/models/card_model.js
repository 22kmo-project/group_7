const db = require('../database');
const bcrypt = require('bcryptjs');
const saltRounds=10;

const card = {
  getById: function(id, callback) {
    return db.query('select * from card where id_card=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(add_data, callback) {
    bcrypt.hash(add_data.pin, saltRounds, function(err, hashedPin) {
        return db.query(
            'insert into card (pin) values(?)',
            [hashedPin],
            callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    bcrypt.hash(update_data.pin, saltRounds, function(err, hashedPin) {
        return db.query(
            'update card set pin=? where id_card=?',
            [hashedPin, id],
            callback);
        });
  },
  checkPin: function(id,callback){
    return db.query('select pin from card where id_card=?',[id],callback);
  }
};

module.exports = card;