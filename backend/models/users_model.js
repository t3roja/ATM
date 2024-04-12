
//const { response } = require('../app.js');
const db=require('../database.js');
const bcrypt=require('bcryptjs');

const clients = {
    
    getAllClients(callback){
        return db.query('select * from client',callback);
    },
    getOneClient(id,callback){
        return db.query('select * from client WHERE id_client=?',[id],callback);
    },

    login(idCard,callback){

        return db.query('SELECT pin FROM card WHERE id_card=?',[idCard],callback);
    },
    
    //Kutsuttaessa muuttaa PIN-numeron salatuksi
    updateCard(id,updateData,callback){
        bcrypt.hash(updateData.pin,10,function(err,hashedPassword){
                return db.query('UPDATE card SET pin=? WHERE id_account=?',[hashedPassword,id],callback);
            })
    },

}

module.exports=clients;