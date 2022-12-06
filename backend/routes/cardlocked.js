const express = require('express');
const router = express.Router();
const card = require('../models/card_model');


router.put('/:id', 
function(request, response) {
  card.lockpin(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;