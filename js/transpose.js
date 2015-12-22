var fs = require('fs');

var fileName = '';
var output = '';

if(process.argv[2]) {
	fileName = process.argv[2];
	// console.log(fileName);
}
else {
	throw new Error('Please enter a file name.');
}

fs.readFile(fileName, function(e, data) {
	if(e) {
		throw new Error('Error opening file: '+ e);
	}
	values = data.toString().split("\n");

	values.forEach(function(val, index, array) {
		var temp = array[index].replace(/(\r\n|\n|\r)/gm,"").trim();
		// console.log(array[index]);
		output = output.concat(temp + ',');
	});
	console.log(output); 
	// console.log(output.length);
});