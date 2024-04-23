const db=require('../database');

const transactions = {

    depositBalance(updateData,callback){
        return db.query('CALL depositBalance((select id_account from card where id_card =?),?)',[updateData.id,updateData.amount],callback);
    },
    withdrawBalance(updateData,callback){
        return db.query('CALL withdrawBalance((select id_account from card where id_card =?),?)',[updateData.id,updateData.amount],callback);
    },
    withdrawCredit(updateData,callback){
        return db.query('CALL withdrawCredit((select id_account from card where id_card =?),?)',[updateData.id,updateData.amount],callback);
    },
    showAccount(updateData,callback){
        return db.query('SELECT * from account where id_account=?',[updateData.id],callback);
    },
    showTransactions(updateData,callback){
        return db.query('SELECT * from transaction where id_account =(select id_account from account_type WHERE id_card=?)' ,[updateData.id],callback)
    },
    showBalance(updateData,callback){
        return db.query('SELECT balance,credit_limit from account where id_account =(select id_account from account_type WHERE id_card=?)',[updateData.id],callback)
    },
    showCreditLimit(updateData,callback){
        db.query('SELECT credit_limit from account where id_account =(select id_account from account_type WHERE id_card=?)',[updateData.id],callback)
        
    },


}

module.exports=transactions;