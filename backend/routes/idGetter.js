var express = require('express');
var router = express.Router();
const idGetter=require('../models/idGetter_model.js');

/* GET home page. 
router.get('/index', function(req, res, next) {
  console.log('index get');
  res.render('index', { title: 'Express' });
});*/

//id_account id_cardista
router.get('/getID/:id', function(request,response){
  idGetter.getAccountId(request.params.id,function(err,result){
    if(err){
      console.log(err);
      response.json(err.errno);
    }
    else{
      response.json(result[0]);
    }
  });
})


router.get('/getCardType/:id', function(request,response){
  idGetter.getCardType(request.params.id,function(err,result){
    if(err){
      console.log(err);
      response.json(err.errno);
    }
    else{
      response.json(result[0]);
    }
  });
})

module.exports = router;
