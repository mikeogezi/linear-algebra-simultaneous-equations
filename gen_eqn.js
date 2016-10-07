var fs = require('fs');
var n = Number(process.argv[2] || 10);

var outerArr = [];

for (var i = 0; i < n; i++) {
    for (var j = 0, innerArr = []; j < n + 1; j++) {
        innerArr.push(Math.random() * 15);
    }
    
    outerArr.push(innerArr);
}

outerArr.forEach(function (_innerArr, _index) {
    outerArr[_index] = _innerArr.join(',');
});

outerArr = outerArr.join('\n');

fs.writeFile('./random_eqn_matrix.dat', outerArr, function (err) {
    if (err) {
        console.error(err);
    }
});
