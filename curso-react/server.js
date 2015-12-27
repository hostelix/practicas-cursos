
var express = require('express');
var app = express();
var http = require('http').createServer(app);
var swig = require('swig');

app.engine('html', swig.renderFile);
app.set('view engine', 'html');
app.set('view cache', false);
swig.setDefaults({ cache: false });

var PORT = process.env.PORT || 3001;

app.set('views', __dirname);
app.use('/js', express.static(__dirname + '/js'));


app.get("/", function(request, response){
	response.render("index.html", {url: __dirname})
})

http.listen(PORT, function(){
	console.log("Servidor corriendo en el puerto: "+PORT);
});




