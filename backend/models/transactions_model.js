const db=require('../database');

const transactions = {

    depositBalance(updateData,callback){
        return db.query('CALL depositBalance(?,?)',[updateData.id,updateData.amount],callback);
    },
    withdrawBalance(updateData,callback){
        return db.query('CALL withdrawBalance(?,?)',[updateData.id,updateData.amount],callback);
    },
    withdrawCredit(updateData,callback){
        return db.query('CALL withdrawCredit(?,?)',[updateData.id,updateData.amount],callback);
    },
    showAccount(updateData,callback){
        return db.query('SELECT * from account where id_account=?',[updateData.id],callback);
    },
    showTransactions(updateData,callback){
        return db.query('SELECT * from transaction WHERE id_account=?',[updateData.id],callback)
    },

}

module.exports=transactions;