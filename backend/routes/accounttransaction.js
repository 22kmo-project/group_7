const express = require('express');
const router = express.Router();
const account = require('../models/transaction_model');

router.get('/:id',function(request,response){
    const id=request.params.id;
    account.getTenTransactions(id,function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult[0]);
        }
    })
})
module.exports = router;