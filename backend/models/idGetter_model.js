const db=require('../database.js');


const idGetter = {

    getAccountId(id,callback){
        return db.query('select id_account from card where id_card =?',[id],callback);
    },
    getCardType(id,callback){
        return db.query('select card_type from card where id_card=?',[id],callback)
    }
}

module.exports=idGetter;