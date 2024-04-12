var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/index', function(req, res, next) {
  console.log('index get');
  res.render('index', { title: 'Express' });
});

module.exports = router;
