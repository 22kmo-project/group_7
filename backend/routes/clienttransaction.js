const express = require('express');
const router = express.Router();
const transaction = require('../models/transaction_model');

//Tämä hakee 10 ensimmäistä tilitapahtumaa
router.get('/:id', function(request,response){
    const id=request.params.id;
    transaction.getTransactions(id,function(err,dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    })

});

module.exports=router;