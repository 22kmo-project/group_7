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
            'insert into card (id_client,id_account,pin, card_status) values(?,?,?,?)',
            [add_data.id_client,add_data.id_account,hashedPin, add_data.card_status],
            callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    bcrypt.hash(update_data.pin, saltRounds, function(err, hashedPin) {
        return db.query(
            'update card set id_client=?,id_account=?,pin=?, card_status=? where id_card=?',
            [update_data.id_client,update_data.id_account,hashedPin, update_data.card_status, id],
            callback);
        });
  },

  lockpin: function(id, callback) {    
    return db.query(
            'update card set card_status=1 where id_card=?', 
            [id], callback);
  },

  getAllLockedCards: function(callback) {    
    return db.query(
            'select id_card from card where card_status=1',
            callback);
  },
  
  checkPin: function(id,callback){
    return db.query('select pin from card where id_card=? and card_status=0',[id],callback);
  },

  deleteAllLockedCards: function(callback) {
    return db.query('delete from card where card_status=1', callback);
  },

  unlockpin: function(id, callback) {    
    return db.query(
            'update card set card_status=0 where id_card=?', 
            [id], callback);
  }

};

module.exports = card;