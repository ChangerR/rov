var fs = require('fs')
var path = require('path');
var tconfig = function() {
	
	var tconf = require('./thrust.json')
	
	this.print = function() {
		console.log(tconf);
	};
	
	this.change = function(data) {
		for (l in data) {
			for( m in tconf) {
				if(l == m) 
					tconf[m] = data[l];
			}
		}
	}
	
	this.update = function() {
		fs.writeFileSync(path.join(__dirname, 'thrust.json'),JSON.stringify(tconf));
	}
	
	this.getjson = function() {
	    return tconf;
	}
};

module.exports = tconfig;