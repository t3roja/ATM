//const multer  = require('multer')
//const upload = multer({ dest: 'imagen tiedostokansio tähän' })
// npm install --save multer <--tämän teet komentokehotteessa omalla koneella

//joko ylempi tai alempi pitää testata
//const express = require('express')
//const app = express()
//const multer  = require('multer')
//const upload = multer()

const app = express()

app.post('/image', upload.single('kuva'), function (req, res, next) {
 
})



const cpUpload = upload.fields([{ name: 'kuva', maxCount: 1 }, { name: 'kuvat', maxCount: 8 }])
app.post('/image', cpUpload, function (req, res, next) {

})

//const multer  = require('multer')
//const upload = multer({ dest: './public/data/uploads/' })
//app.post('/stats', upload.single('uploaded_file'), function (req, res) {
   // req.file is the name of your file in the form above, here 'uploaded_file'
   // req.body will hold the text fields, if there were any 
//   console.log(req.file, req.body)
//});
