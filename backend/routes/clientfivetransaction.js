const express = require('express');
const router = express.Router();
const transaction = require('../models/transaction_model');


router.get('/:id', function(request,response){
    const id=request.params.id;
    transaction.getFiveTransactions(id,function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    })

});

module.exports=router;