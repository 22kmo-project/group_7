var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var cardRouter = require('./routes/card');
var loginRouter = require('./routes/login');
var clientRouter = require('./routes/client');
var accountRouter = require('./routes/account');
var transactionRouter = require('./routes/transaction');
var accountclientRouter = require('./routes/accountclient');
var clienttransactionRouter = require('./routes/clienttransaction');
var clientfivetransactionRouter = require('./routes/clientfivetransaction');
var accounttransferRouter = require('./routes/accounttransfer');
var cardlockedRouter = require('./routes/cardlocked');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

function authenticateToken(req, res, next) {
  const authHeader = req.headers['authorization']
  const token = authHeader && authHeader.split(' ')[1]

  console.log("token = "+token);
  if (token == null) return res.sendStatus(401)

  jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
    console.log(err)

    if (err) return res.sendStatus(403)

    req.user = user

    next()
  })
}

//SUOJAAMATTOMAT ENDPOINTIT
app.use('/login', loginRouter);
app.use('/cardlocked', cardlockedRouter);
app.use(authenticateToken); // kaikki tämän rivin jälkeen on suojattu

//SUOJATUT ENDPOINTIT
app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/card', cardRouter);
app.use('/client', clientRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);
app.use('/accountclient', accountclientRouter);
app.use('/clienttransaction', clienttransactionRouter);
app.use('/clientfivetransaction', clientfivetransactionRouter);
app.use('/accounttransfer', accounttransferRouter);

module.exports = app;
