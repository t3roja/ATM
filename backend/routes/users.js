var express = require('express');
var router = express.Router();
//const { response } = require('../app');
const clients = require('../models/users_model');

/* GET users listing
router.get('/', function(requ, res, next) {
  res.send('respond with a resource');
});*/

router.get('/clients', function(request,response){
  clients.getAllClients(function(err,result){
    if(err){
      console.log(err);
      response.json(err.errno);
    }
    else{
      response.json(result);
    }
  });
})

router.get('/clients/:id', function(request,response){
  clients.getOneClient(request.params.id, function(err,result){
    if(err){
      console.log(err);
      response.json(err.errno);
    }
    else{
      response.json(result[0])
    }
  });
});

router.put('/update/:id',function(request,response){
  clients.updateCard(request.params.id,request.body,function(err, result){
    if(err){
      console.log(err);
      response.json(err);
    }
    else{
      response.json(result);
    }
  });
});

module.exports = router;
