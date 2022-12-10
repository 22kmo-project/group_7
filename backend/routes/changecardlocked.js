const express = require('express');
const router = express.Router();
const card = require('../models/card_model');


router.get('/',function(request,response){
  card.getAllLockedCards(function(err,dbResult){
      if(err){
          response.json(err);
      }
      else{
          response.json(dbResult);
      }
  })
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

module.exports = router;