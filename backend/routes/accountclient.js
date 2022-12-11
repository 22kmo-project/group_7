const express = require('express');
const router = express.Router();
const account = require('../models/account_model');

router.get('/',function(request,response){
    account.getAllBalances(function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    });
});

router.get('/:id',function(request,response){
    const id=request.params.id;
    account.getOneBalance(id,function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult[0]);
        }
    });
});

router.post('/', 
function(request, response) {
  account.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body); 
    }
  });
});

router.delete('/:id', 
function(request, response) {
  account.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put('/:id', 
function(request, response) {
  account.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});



module.exports = router;