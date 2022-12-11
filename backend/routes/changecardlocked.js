const express = require('express');
const router = express.Router();
const card = require('../models/card_model');


router.get('/',
function(request,response){
  card.getAllLockedCards(function(err,dbResult){
      if(err){
          response.json(err);
      }
      else{
          response.json(dbResult);
      }
  });
});

router.put('/:id', 
function(request, response) {
  card.unlockpin(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.delete('/:id', 
function(request, response) {
  card.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.post('/', 
function(request, response) {
  card.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body); 
    }
  });
});

module.exports = router;