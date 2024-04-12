const db=require('../database');

const transactions = {

    depositBalance(updateData,callback){
        return db.query('CALL depositBalance(?,?)',[updateData.id,updateData.amount],callback);
    },
    withdrawBalance(updateData,callback){
        return db.query('CALL withdrawBalance(?,?)',[updateData.id,updateData.amount],callback)
    },
    withdrawCredit(updateData,callback){
        return db.query('CALL withdrawCredit(?,?)',[updateData.id,updateData.amount],callback)
    },

}

module.exports=transactions;