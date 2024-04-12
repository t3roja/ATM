var express = require('express');
var router = express.Router();
//const { response } = require('../app');
const clients = require('../models/users_model');
const bcrypt=require('bcryptjs');
const jwt = require('jsonwebtoken');
const dotenv=require('dotenv');
dotenv.config();

router.post('/',function(request,response){
    clients.login(request.body.idCard,function(err,result){
    if(request.body.idCard && request.body.pin){//tarkistetaan onko ID ja PIN syötetty
            if(err){
                response.json(err);
            }
            else{                            
                if(result.length > 0){ //onko vastauksessa jotain
                const hashedPin=result[0].pin;
                bcrypt.compare(request.body.pin,hashedPin,function(err,compareResult){ //verrataan syötettyä salasanaa oikeaan
                    if(compareResult){

                        console.log("Login successful");


                        const token=generateAccessToken({idCard: request.body.idCard})

                        response.send(token);
                    }
                    else{
                        console.log("Login failed");
                        response.send("Login failed");
                    }
                })
                }
                else{
                    console.log("ID not found");
                    response.send(false);
                }

            }
        
    }
    else{
        console.log("No ID or PIN provided");
        response.send(false);
    }
    });
});


function generateAccessToken(username) { //WEB-tokenin luonti
    dotenv.config();
    return jwt.sign(username, process.env.MY_TOKEN, { expiresIn: '600s'/*kauanko säilyy voimassa*/});
  }

module.exports=router;