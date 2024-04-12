var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
//const multer  = require('multer')
//const upload = multer({ dest: 'imagen tiedostokansio tähän' })
// npm install --save multer <--tämän teet komentokehotteessa omalla koneella


var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var loginRouter = require('./routes/login');
var transactionsRouter = require('./routes/transactions');
const mysql = require('./database');
const connection = require('./database');
const jwt=require('jsonwebtoken');
const dotenv=require('dotenv')
dotenv.config();

var app = express();

const port = 3000;
//const port = 15120

app.listen(port, function(){
    console.log('Kuunnellaan porttia '+ port);
});


app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

//Suojaamattomat reitit
app.use('/login',loginRouter)
app.use('/index', indexRouter);

//Suojatut reitit
app.use(authenticateToken);
app.use('/users', usersRouter);
app.use('/transactions', transactionsRouter);



function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, function(err, user) {
  
      if (err) return res.sendStatus(403)

      req.user = user
  
      next()
    })
  }

module.exports = app;
