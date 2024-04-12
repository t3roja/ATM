const express=require('express');
const transactions = require('../models/transactions_model');
var router = express.Router();

router.post('/depositBalance',function(request,response){
    transactions.depositBalance(request.body,function(err,result){
      if(err){
        console.log(err);
        response.json(err.errno);
      }
      else{response.json(result);
      }
    })
  })
  
  router.post('/withdrawBalance/', function(request,response){
    transactions.withdrawBalance(request.body, function(err,result){
      if(err){
        console.log(err);
        response.json(err.errno);
      }
      else{
        response.json(result)
      }
    })
  });
  
  router.post('/withdrawCredit/', function(request,response){
    transactions.withdrawCredit(request.body, function(err,result){
      if(err){
        console.log(err);
        response.json(err.errno);
      }
      else{
        response.json(result)
      }
    })
  });

  router.post('/showAccount/', function(request,response){
    transactions.showAccount(request.body, function(err,result){
      if(err){
        console.log(err);
        response.json(err.errno);
      }
      else{
        response.json(result[0])
      }
    })
  })

  router.post('/showTransactions/', function(request,response){
    transactions.showTransactions(request.body, function(err,result){
      if(err){
        console.log(err);
        response.json(err.errno);
      }
      else{
        response.json(result)
      }
    })
  })
  
module.exports=router;