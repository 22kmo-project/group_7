const express = require('express');
const router = express.Router();
const transaction = require('../models/transaction_model');

router.post('/',function(request,response){
    transaction.transferAmount(request.body, function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    })
});

module.exports = router;